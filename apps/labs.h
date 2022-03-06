#pragma once

#include "labs/vgatext.h"
#include "util/debug.h"
#include "labs/keyboard.h"
#include "labs/shell.h"
#include "labs/coroutine.h"
#include "labs/fiber.h"
#include  "labs/fiber_scheduler.h"
#include "labs/preempt.h"
#include "labs/multicore.h"

#include "devices/lapic.h"
#include "util/shm.h"

enum {
  channel0_size       = 2  // must be a power of two
};

struct channel0_data_t{
  renderstate_t data;
} ALIGN(64);

struct channels_t{
  channel_t                channel0_meta       ALIGN(64);
  channel0_data_t          channel0_data[channel0_size];
};


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
  bool          render_flag;  // = true

  lpc_kbd_t     lpc_kbd;


  uint8_t       input;
  renderstate_t rendertmp;

  // multicore
  readport_t    channel0_readport;
  size_t        channel0_readport_read_index_tmp;

  writeport_t   channel0_writeport;
  size_t        channel0_writeport_write_index_tmp;
  size_t        channel0_writeport_delete_index_tmp;


public:
  apps_t():
    channel0_readport(channel0_size),
    channel0_writeport(channel0_size)
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

    render_flag    = false;

    hoh_assert(arrays_size==STACKPTRS_SIZE*ARRAY_SIZE,"Bug: apps.arrays_size="<<arrays_size);
  }

};


extern "C" void apps_reset(int rank, apps_t& apps, shm_t& shm);
extern "C" void apps_loop(int rank, addr_t* main_stack, preempt_t* pprempt, apps_t* p_apps, dev_lapic_t* lapic, shm_t* pshm);

