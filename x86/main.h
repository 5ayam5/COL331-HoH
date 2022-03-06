#pragma once

//apps
#include "apps/labs.h"

//for hal
#include "devices/idt32.h"
#include "devices/gdt32.h"
#include "devices/pic.h"
#include "devices/lapic.h"
#include "devices/ioapic.h"
#include "devices/oldtimer.h"
#include "devices/cmos.h"
#include "devices/ia32.h"
#include "devices/mmu32.h"

//pool
#include "util/bitpool.h"

#include "util/multiboot.h" //multiboot: for bsp

#include "util/shm.h"

struct config_t{
  io_t   pic_base;//=0;
  addr_t lapic_base; //=addr_t(0xfee00000);
  addr_t ioapic_base;//=addr_t(0xfec00000);
  io_t   oldtimer_base; //=0x40;
  io_t   cmos_base; //=0;

  config_t(){
    //to support ancient gcc-4.6
    pic_base=0;
    lapic_base=((addr_t)0xfee00000);
    ioapic_base=((addr_t)0xfec00000);
    oldtimer_base=0x40;
    cmos_base=0;
  }
};

struct hal_t{
  dev_idt32_t      idt;
  dev_gdt32_tss_t  gdt;
  dev_lpc_pic_t    pic;
  dev_lapic_t      lapic;
  dev_lpc_ioapic_t ioapic;
  dev_lpc_timer_t  oldtimer;
  dev_lpc_cmos_t   cmos;
  dev_ia32_t       ia32;
  dev_pde32_t*     pde32;

public:
  hal_t(addr_t tstack,size_t tstacksize,addr_t gsbegin,size_t gssize,dev_pde32_t* tpde,const config_t& config):
    gdt(tstack,tstacksize,gsbegin,gssize),
    pic(config.pic_base),
    lapic(config.lapic_base),
    ioapic(config.ioapic_base),
    oldtimer(config.oldtimer_base),
    cmos(config.cmos_base),
    ia32(),
    pde32(tpde)
  {

  }
};

struct core_t{
#define core_offset_self       0
#define core_offset_rank       4
#define core_offset_mainstack  8
#define core_offset_stackbegin 12
#define core_offset_stacksize  16
#define core_offset_stackend   20
#define core_offset_preempt    24

  const core_t* self;
  size_t        rank;
  addr_t        main_stack; //=0;
  addr_t        main_stackbegin;
  size_t        main_stacksize;
  addr_t        main_stackend_cached;
  preempt_t     preempt;

  bitpool_t     pool4M;
  bitpool_t     pool4K;
  size_t        magic;  //=0xface600d;

  config_t      config;
  hal_t         hal;
  shm_t         shm;
  apps_t        apps;

public:
  // Note: called on a tiny stack
  core_t(int trank, addr_t tmastermsg, const bitpool_t& p4M, const bitpool_t& p4K, addr_t tstack, size_t tstacksize, const config_t& tconfig):
    self(this),
    rank(trank),
    main_stackbegin(tstack), // XXX: reset the pool too
    main_stacksize(tstacksize),
    main_stackend_cached(tstack+tstacksize),
    preempt(),
    pool4M(p4M),
    pool4K(p4K),
    config(tconfig),
    hal(tstack,tstacksize,addr_t(this),sizeof(core_t),allocT<dev_pde32_t>(pool4K),tconfig),
    shm(trank,tmastermsg)
  {
    main_stack = addr_t(0xfacebaad); //to tell you that their value is random
    magic=0xface600d;
  }
};


extern "C" void core_reset(int rank, core_t& core)  STACK_FORCE_ALIGN;
extern "C" void core_loop(int rank, core_t* p_core) STACK_FORCE_ALIGN;




extern "C" void core_master_init(uint32_t magic, multiboot_info_t* pinfo, addr_t& mymem, bitpool_t& pool_tmp) STACK_FORCE_ALIGN;
extern "C" void core_mem_init(int rank, addr_t mastermsg, addr_t mymsg, bitpool_t& pool_tmp, bitpool_t& pool_tmp2, addr_t& ret_stack, addr_t& ret_core) STACK_FORCE_ALIGN;

