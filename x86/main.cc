#include "labs/vgatext.h"
#include "util/debug.h"
#include "labs/keyboard.h"

struct core_t{
  addr_t        vgatext_base;   //=addr_t(0xb8000);
  int           vgatext_width;  //=80;
  int           vgatext_height; //=25;

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

  lpc_kbd_initialize(&core.lpc_kbd,0x60);
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
  for(;;){
    core_loop_step(core);
  }
}



//
// step
//
static void core_loop_step(core_t& core){
  uint8_t       input;

  if(!lpc_kbd::has_key(core.lpc_kbd)){
    return;
  }

  input=lpc_kbd::get_key(core.lpc_kbd);

  hoh_debug("Got key: " << input);
}

