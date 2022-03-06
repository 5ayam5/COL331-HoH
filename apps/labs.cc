#include "apps/labs.h"


static inline channels_t& channels_get(int othercore, shm_t& shm){
  addr_t p= shm.get(othercore);
  return *(channels_t*)p;
}


static inline channel_t& channel0_get(int othercore, shm_t& shm){
  return channels_get(othercore,shm).channel0_meta;
}

static inline renderstate_t& channel0_get_data(int othercore, shm_t& shm, size_t offset){
  return channels_get(othercore,shm).channel0_data[offset%channel0_size].data;
}


//
// app step
//
static void apps_loop_step(int rank, addr_t& main_stack, preempt_t& preempt, apps_t& apps, dev_lapic_t& lapic, shm_t& shm){
  if(rank==0){
    goto rank0;
  }else if(rank==1){
    goto rank1;
  }

  goto done;
rank0:

  if(!lpc_kbd::has_key(apps.lpc_kbd)){
    goto nokey;
  }

  apps.input=lpc_kbd::get_key(apps.lpc_kbd);

  if(apps.input & 0x80){
    goto nokey;
  }

  // on key: pass the key to shell
  shell_update(apps.input, apps.shell_state);

  if(lpc_kbd::has_key(apps.lpc_kbd)){
    goto done;
  }

nokey:

  // shellstate -> renderstate: compute render state from shell state
  shell_render(apps.shell_state, apps.rendertmp);

  //
  // optimization: render() is pure/referentially transparent.
  // ie. r1 == r2 ==> render(r1) == render(r2).
  // ie. For the same render state, render() will always generate the same UI.
  // So, If the render state is same as last render state, let's optimize it away.
  //
  if(apps.render_flag && render_eq(apps.render_state, apps.rendertmp)){
    apps.render_state=apps.rendertmp;
    goto norender;
  }
  apps.render_flag = true;

  //can reserve space to write data
  if(!apps.channel0_writeport.write_canreserve(1)){
    //hoh_debug(" cannot reserve: size="<<apps.channel0_writeport.write_reservesize());
    goto norender;
  }


  //reserve space to write data
  apps.channel0_writeport_write_index_tmp = apps.channel0_writeport.write_reserve(1);

  //write data
  construct(&channel0_get_data(rank+1,shm,apps.channel0_writeport_write_index_tmp),
            apps.rendertmp);

  //sync: save/update write pointer
  apps.channel0_writeport.write_release(channel0_get(rank+1,shm)); // save write count. sync with core(rank+1)

  //save state
  apps.render_state=apps.rendertmp;

  //hoh_debug("rank0");

norender:
  //hoh_debug("norender");

  //sync: load read pointer
  apps.channel0_writeport.read_acquire(channel0_get(rank+1,shm)); //read read count. sync with core rank+1


  //can reserve space to delete data
  if(!apps.channel0_writeport.delete_canreserve(1)){
    goto docompute;
  }

  //reserve space which we want to delete data
  apps.channel0_writeport_delete_index_tmp = apps.channel0_writeport.delete_reserve(1);

  destroy(&channel0_get_data(rank+1,shm,apps.channel0_writeport_delete_index_tmp));

  //sync: save/update delete pointer
  apps.channel0_writeport.delete_release(); // save delete count

  if(lpc_kbd::has_key(apps.lpc_kbd)){
    goto done;
  }

docompute:

  // execute shell for one time slot to do the computation, if required.
  shell_step(apps.shell_state);

  // execute shell for one time slot to do the some computation based on coroutine, if required.
  shell_step_coroutine(apps.shell_state, apps.f_coro, apps.f_locals);

  // execute shell for one time slot to do the some computation based on fiber, if required.
  shell_step_fiber(apps.shell_state, main_stack, preempt, apps.f_stack, apps.f_array, apps.f_arraysize, lapic);

  // execute shell for one time slot to do the additional long computations based on fiber, if required.
  shell_step_fiber_scheduler(apps.shell_state, main_stack, preempt, apps.stackptrs, apps.stackptrs_size, apps.arrays, apps.arrays_size,lapic);



  goto done;
rank1:

  //read from shm

  //sync: load write pointer
  apps.channel0_readport.write_acquire(channel0_get(rank-1,shm)); // load write count. sync with core(rank-1)

  // can reserve space to read
  if(!apps.channel0_readport.read_canreserve(1)){
    //hoh_debug("rank1: cant reserve space: "<<apps.channel0_readport.read_reservesize());
    goto done;
  }

  //reserve read
  apps.channel0_readport_read_index_tmp = apps.channel0_readport.read_reserve(1);

  // process the data
  // renderstate -> vgatext: given renderstate, render to vgatext buffer.
  render(channel0_get_data(rank-1,shm, apps.channel0_readport_read_index_tmp),
         apps.vgatext_width, apps.vgatext_height, apps.vgatext_base);

  //when we are done processing the data
  //sync: save/update read pointer
  apps.channel0_readport.read_release(channel0_get(rank-1,shm));  // save read count. sync with core(rank-1)

  goto done;
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
extern "C" void apps_reset(int rank, apps_t& apps, shm_t& shm){

  hoh_debug(rank<<": Hello, serial!");

  if(rank==0){
    // Hello, world!
    const char* p="Hello, world!";
    for(int loc=0;*p;loc++,p++){
      vgatext::writechar(loc,*p,1,7,apps.vgatext_base);
    }
  }

  if(rank==0){
    lpc_kbd::reset(apps.lpc_kbd);
  }

  shell_init(apps.shell_state);

}

//
// main loop
//
extern "C" void apps_loop(int rank, addr_t* pmain_stack, preempt_t* ppreempt, apps_t* p_apps, dev_lapic_t* plapic, shm_t* pshm){
  addr_t& main_stack = *pmain_stack;
  preempt_t& preempt = *ppreempt;
  apps_t& apps       = *p_apps;
  dev_lapic_t& lapic = *plapic;
  shm_t& shm         = *pshm;
  uint32_t esp;
  asm volatile ("mov %%esp,%0":"=r"(esp)::);
  hoh_debug("apps_loop: esp="<<esp);

  for(;;){
    apps_loop_step(rank, main_stack, preempt, apps,lapic,shm);
  }
}


