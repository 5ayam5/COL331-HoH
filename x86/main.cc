#include "labs/vgatext.h"
#include "util/debug.h"
#include "labs/keyboard.h"
#include "labs/shell.h"
#include "labs/coroutine.h"
#include "labs/fiber.h"

struct core_t{
  addr_t        vgatext_base;   //=addr_t(0xb8000);
  int           vgatext_width;  //=80;
  int           vgatext_height; //=25;

  shellstate_t  shell_state;

  //for one coroutine
  coroutine_t   f_coro;
  f_t           f_locals;

  //for one fiber
  enum { ARRAY_SIZE=4096};
  addr_t        main_stack;
  addr_t        f_stack;
  size_t        f_arraysize;
  uint32_t      f_debug1;
  uint8_t       f_array[ARRAY_SIZE] ALIGN(64);
  uint32_t      f_debug2;

  renderstate_t render_state; //separate renderstate from shellstate

  lpc_kbd_t     lpc_kbd;
};

static core_t   s_core;

extern "C" void core_boot();
extern "C" void core_init(core_t& core);
extern "C" void core_reset(core_t& core);
extern "C" void core_loop(core_t* p_core);
static     void core_loop_step(core_t& core);


//
// main
//
extern "C" void core_boot(){
  core_init(s_core);
  core_reset(s_core);

  { // Hello, world!
    const char* p="Hello, world!";
    for(int loc=0;*p;loc++,p++){
      vgatext::writechar(loc,*p,0,7,s_core.vgatext_base);
    }
  }

  hoh_debug("Hello, serial!");

  core_loop(&s_core);
}




//
// initialize core
//
extern "C" void core_init(core_t& core){
  core.vgatext_base   = (addr_t)0xb8000;
  core.vgatext_width  = 80;
  core.vgatext_height = 25;

  core.main_stack     = addr_t(0xfacebaad); //to tell you that their value is random
  core.f_stack        = addr_t(0xfacebaad);
  core.f_arraysize    = sizeof(core.f_array);
  core.f_debug1       = 0xface600d; // for debug
  core.f_debug2       = 0xface600d;

  lpc_kbd_initialize(&core.lpc_kbd,0x60);

  shell_init(core.shell_state);

  shell_render(core.shell_state, core.render_state);
}


//
// reset core to a known state
//
extern "C" void core_reset(core_t& core){
  //serial::reset();
  //lpc_kbd::reset();
}


//
// main loop
//
extern "C" void core_loop(core_t* p_core){
  core_t& core=*p_core;
  hoh_debug("core_loop: esp=");
  render(core.render_state, core.vgatext_width, core.vgatext_height, core.vgatext_base);
  for(;;){
    core_loop_step(core);
  }
}



//
// step
//
static void core_loop_step(core_t& core){
  uint8_t       input;
  renderstate_t rendertmp;


  if(!lpc_kbd::has_key(core.lpc_kbd)){
    goto nokey;
  }

  input=lpc_kbd::get_key(core.lpc_kbd);

  if(input & 0x80){
    goto nokey;
  }

  // on key: pass the key to shell
  shell_update(input, core.shell_state);

nokey:
  // execute shell for one time slot to do the computation, if required.
  shell_step(core.shell_state);

  // execute shell for one time slot to do the some computation based on coroutine, if required.
  shell_step_coroutine(core.shell_state, core.f_coro, core.f_locals);

  // execute shell for one time slot to do the some computation based on fiber, if required.
  shell_step_fiber(core.shell_state, core.main_stack, core.f_stack, core.f_array, core.f_arraysize);

  // shellstate -> renderstate: compute render state from shell state
  shell_render(core.shell_state, rendertmp);

  //
  // optimization: render() is pure/referentially transparent.
  // ie. r1 == r2 ==> render(r1) == render(r2).
  // ie. For the same render state, render() will always generate the same UI.
  // So, If the render state is same as last render state, let's optimize it away.
  //
  if(render_eq(core.render_state, rendertmp)){
    goto done;
  }

  // renderstate -> vgatext: given renderstate, render to vgatext buffer.
  core.render_state=rendertmp;
  render(core.render_state, core.vgatext_width, core.vgatext_height, core.vgatext_base);

done:
  return;
}
