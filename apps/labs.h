#pragma once

#include "labs/vgatext.h"
#include "util/debug.h"
#include "labs/keyboard.h"
#include "labs/shell.h"
#include "labs/coroutine.h"
#include "labs/fiber.h"
#include "labs/fiber_scheduler.h"
#include "labs/preempt.h"

#include "devices/lapic.h"

struct apps_t{
  addr_t        vgatext_base;   //=addr_t(0xb8000);
  int           vgatext_width;  //=80;
  int           vgatext_height; //=25;

  shellstate_t  shell_state;

  //for one coroutine
  coroutine_t   f_coro;
  f_t           f_locals;

  //for one fiber
  enum { ARRAY_SIZE=4096};
  addr_t        f_stack;
  size_t        f_arraysize;
  uint32_t      f_debug1;
  uint8_t       f_array[ARRAY_SIZE] ALIGN(64);
  uint32_t      f_debug2;

  //for fiber_scheduler
  enum { STACKPTRS_SIZE=10};
  size_t        stackptrs_size;
  addr_t        stackptrs[STACKPTRS_SIZE];
  size_t        arrays_size;
  uint8_t       arrays[STACKPTRS_SIZE*ARRAY_SIZE] ALIGN(64);

  renderstate_t render_state; //separate renderstate from shellstate

  lpc_kbd_t     lpc_kbd;


  uint8_t       input;
  renderstate_t rendertmp;


public:
  apps_t()
  {
    //support ancient gcc-4.6
    vgatext_base   = (addr_t)0xb8000;
    vgatext_width  = 80;
    vgatext_height = 25;
    f_stack        = addr_t(0xfacebaad);
    f_arraysize    = sizeof(f_array);
    f_debug1       = 0xface600d; // for debug
    f_debug2       = 0xface600d;
    stackptrs_size = STACKPTRS_SIZE;
    arrays_size    = sizeof(arrays);

    hoh_assert(arrays_size==STACKPTRS_SIZE*ARRAY_SIZE,"Bug: apps.arrays_size="<<arrays_size);
  }

};


extern "C" void apps_reset(int rank, apps_t& apps);
extern "C" void apps_loop(int rank, addr_t* main_stack, preempt_t* pprempt, apps_t* p_apps, dev_lapic_t* lapic);

