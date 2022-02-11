#include "apps/labs.h"


//
// app step
//
static void apps_loop_step(int rank, addr_t& main_stack, preempt_t& preempt, apps_t& apps, dev_lapic_t& lapic){

  if(!lpc_kbd::has_key(apps.lpc_kbd)){
    goto nokey;
  }

  apps.input=lpc_kbd::get_key(apps.lpc_kbd);

  if(apps.input & 0x80){
    goto nokey;
  }

  // on key: pass the key to shell
  shell_update(apps.input, apps.shell_state);

nokey:
  // execute shell for one time slot to do the computation, if required.
  shell_step(apps.shell_state);

  // execute shell for one time slot to do the some computation based on coroutine, if required.
  shell_step_coroutine(apps.shell_state, apps.f_coro, apps.f_locals);

  // execute shell for one time slot to do the some computation based on fiber, if required.
  shell_step_fiber(apps.shell_state, main_stack, preempt, apps.f_stack, apps.f_array, apps.f_arraysize, lapic);

  // execute shell for one time slot to do the additional long computations based on fiber, if required.
  shell_step_fiber_scheduler(apps.shell_state, main_stack, preempt, apps.stackptrs, apps.stackptrs_size, apps.arrays, apps.arrays_size, lapic);

  // shellstate -> renderstate: compute render state from shell state
  shell_render(apps.shell_state, apps.rendertmp);

  //
  // optimization: render() is pure/referentially transparent.
  // ie. r1 == r2 ==> render(r1) == render(r2).
  // ie. For the same render state, render() will always generate the same UI.
  // So, If the render state is same as last render state, let's optimize it away.
  //
  if(render_eq(apps.render_state, apps.rendertmp)){
    goto done;
  }

  // renderstate -> vgatext: given renderstate, render to vgatext buffer.
  apps.render_state=apps.rendertmp;
  render(apps.render_state, apps.vgatext_width, apps.vgatext_height, apps.vgatext_base);

done:
  return;
}

namespace lpc_kbd{
  static inline void reset(lpc_kbd_t& dev){
    lpc_kbd_initialize(&dev,0x60);
    //disable: kbd_int and aux_int 
    //disable auxilary device
  }
}





//
// reset
//
extern "C" void apps_reset(int rank, apps_t& apps){

  hoh_debug("Hello, serial!");
  
  {
    // Hello, world!
    const char* p="Hello, world!";
    for(int loc=0;*p;loc++,p++){
      vgatext::writechar(loc,*p,1,7,apps.vgatext_base);
    }
  }

  lpc_kbd::reset(apps.lpc_kbd);

  shell_init(apps.shell_state);

  shell_render(apps.shell_state, apps.render_state);
}

//
// main loop
//
extern "C" void apps_loop(int rank, addr_t* pmain_stack, preempt_t* ppreempt, apps_t* p_apps, dev_lapic_t* plapic){
  addr_t& main_stack = *pmain_stack;
  preempt_t& preempt = *ppreempt;
  apps_t& apps       = *p_apps;
  dev_lapic_t& lapic = *plapic;
  uint32_t esp;
  asm volatile ("mov %%esp,%0":"=r"(esp)::);
  hoh_debug("apps_loop: esp="<<esp);
  render(apps.render_state, apps.vgatext_width, apps.vgatext_height, apps.vgatext_base);
  for(;;){
    apps_loop_step(rank, main_stack, preempt, apps,lapic);
  }
}


