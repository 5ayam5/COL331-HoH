//
// main.cc
//

#include "x86/main.h"
#include "x86/except.h"     //exceptions and asm interface

#include "util/multicore.h"

//
// initialize config
//
static void config_init(int rank, config_t& config){
  dev_ia32_t ia32;
  hoh_debug("is_bsp:" << ia32.is_bsp());
  hoh_debug("apic_base:" << ia32.apic_base());

  // TODO: initialize config from acpi tables etc.
  // config.lapic_base = ia32.apic_base();
}



//
// hal reset
//
static void hal_reset(int rank,hal_t& hal){
  asm volatile ("cli" ::: "memory");

  idt_reset(hal.idt);
  hal.pde32->map(0, (char*)~0x3fffffUL, 0);
  hal.gdt.reset();

  if(rank==0){
    hal.pic.reset(pic_master_base);
    hal.pic.maskall();
    hal.ioapic.reset();
  }

  hal.lapic.reset();
  hal.idt.reset();

  if(rank==0){
    hal.oldtimer.set_hz(0);
  }

  hal.pde32->reset();
  hal.ia32.enable_paging();

  asm volatile ("sti" ::: "memory");
}


//
// reset core to a known state
//
// called from boot.S
//
extern "C" void core_reset(int rank, core_t& core){
  //serial::reset();
  hoh_debug(rank<<": core_reset begin");
  hoh_assert(rank == core.rank, "XXX");
  hal_reset(core.rank,core.hal);

  if(rank==0){
    remotecore_reset_helper<channels_t>(rank+1,rank,core.hal.cmos,core.hal.lapic,core.pool4M,core.shm);
  }
  apps_reset(core.rank,core.apps,core.shm);
}

//
// loop
//
// called from boot.S
//
extern "C" void core_loop(int rank, core_t* p_core){
  core_t& core=*p_core;
  hoh_assert(rank == core.rank, "XXX");
  hoh_debug(rank<<": core_loop begin");

  apps_loop(core.rank, &core.main_stack, &core.preempt, &core.apps, &core.hal.lapic, &core.shm);
}


//
// initialize BSP/master core
//
// called from boot.S
//
extern char g_end[];
extern "C" void core_master_init(uint32_t magic, multiboot_info_t* pinfo, addr_t& sharedmem, bitpool_t& pool_tmp){
  hoh_assert(magic == MULTIBOOT_BOOTLOADER_MAGIC,"magic="<<magic);
  hoh_assert(pinfo,"XXX");
  multiboot_info_t& info = *pinfo;

  //
  //print multiboot info
  //
  hoh_debug_if(test_bit(info.flags,0), "mem_lower = "<<info.mem_lower<<", "<<"mem_upper = "<<info.mem_upper);
  hoh_debug_if(test_bit(info.flags,2), "cmdline   = "<<info.cmdline);
  if(test_bit(info.flags,3)){
    for(size_t i=0;i<info.mods_count;i++){
      hoh_debug("mod_start="<<info.mods_addr[i].mod_start<<", mod_end="<<info.mods_addr[i].mod_end<<", mod_cmdline="<<info.mods_addr[i].cmdline<<",FB="<<*(const char*)info.mods_addr[i].mod_start);
    }
  }

  //
  // Initialize Pool from Memory map
  //
  enum { PAGE_SIZE=4<<20 };
  construct(&pool_tmp,uint32_t(PAGE_SIZE),addr_t(0));

  if(test_bit(info.flags, 6)){
    multiboot_memory_map_t* from = (multiboot_memory_map_t*)info.mmap_addr;
    multiboot_memory_map_t* to   = (multiboot_memory_map_t*)(info.mmap_addr+info.mmap_length);

    for(multiboot_memory_map_t* p=from; p!=to; ++p){
      multiboot_memory_map_t& r = *p;
      hoh_debug(" size = "<<r.size << ", base_addr = "<< r.addr << ", length = "<<r.len << ", type = "<<  r.type);
      if(r.type != 1){
        continue;
      }
      addr_t from = addr_t(r.addr);
      addr_t to   = from + r.len;

      //consider only memory after g_end as free
      addr_t end  = addr_t(&g_end[0]);
      if(to < end){
        continue;
      }
      if(from < end && end <= to){
        from = end;
      }

      //align them to page boundary
      from = nextalign(from, PAGE_SIZE);
      to   = prevalign(to,   PAGE_SIZE);
      hoh_debug("Adding from= "<< from << " to= "<<to);

      //add to pool
      for(addr_t p=from; p<to; p+=pool_tmp.datasize()){
        pool_tmp.add_mem(p,p+pool_tmp.datasize());
      }
    }
  }

  hoh_debug("Pool Size: "<<pool_tmp.remaining()<<" Pool="<<uint32_t(&pool_tmp));
  hoh_assert(pool_tmp.remaining() > 10, "Not enough memory");
  sharedmem=alloc(pool_tmp);

}


//
// initialize memory
//
// called from boot.S
//
extern "C" void core_mem_init(int rank, addr_t mastermsg, addr_t sharedmsg, bitpool_t& pool_tmp, bitpool_t& pool_tmp2, addr_t& ret_stack, addr_t& ret_core){
  hoh_debug("core "<<rank<<" initializing mem: "<<pool_tmp.remaining()<<" Pool="<<uint32_t(&pool_tmp));
  hoh_assert(canalloc(pool_tmp),"XXX");

  auto p4k = alloc(pool_tmp);
  enum { PAGE_SIZE4K=4<<10 };
  construct(&pool_tmp2,uint32_t(PAGE_SIZE4K),p4k);
  for(addr_t p = p4k; p < p4k+pool_tmp.datasize(); p += pool_tmp2.datasize()){
    pool_tmp2.add_mem(p, p+pool_tmp2.datasize());
  }

  //stack
  hoh_assert(canalloc(pool_tmp2),"XXX");
  auto stack = alloc(pool_tmp2);
  auto stacksize=pool_tmp2.datasize();

  //core
  hoh_debug("size of core="<<sizeof(core_t));
  hoh_assert(sizeof(core_t)<pool_tmp.datasize(),"XXX");
  hoh_assert(canalloc(pool_tmp),"XXX");

  config_t config;
  config_init(rank, config);
  auto pcore = allocT<core_t>(pool_tmp, rank, sharedmsg, pool_tmp,pool_tmp2,stack,stacksize,config);
  if(mastermsg){
    int master=0; //master boots all the remote core. TODO: Should've passed as an arg
    pcore->shm.set(master,mastermsg);
  }

  ret_core   = addr_t(pcore);
  ret_stack  = pcore->main_stackbegin+pcore->main_stacksize-8;

}



