#pragma once

#include "generated/ia32.dev.h"
#include "util/util.h"
#include "devices/config.h"

class dev_gdt32_tss_t{
  public:
    enum type{null,code,data,usercode,userdata,tss,per_core,N};
  private:
    ia32_gdt_array_t m_gdt[N];
    ia32_tss_array_t m_tss;

  public:
    dev_gdt32_tss_t(addr_t stack_begin, size_t stack_size, addr_t pcore_begin,size_t pcore_size){
      static_assert(sizeof(m_gdt[0])==8,"XXX");
      set_gdt(null,0,0,0,0xc);
      set_gdt(code,0,0xffffffff,0x9b,0xc);
      set_gdt(data,0,0xffffffff,0x93,0xc);
      set_gdt(usercode,0,0xffffffff,0xfa,0xc);
      set_gdt(userdata,0,0xffffffff,0xf2,0xc);
      set_gdt(tss,uintptr_t(&m_tss),uintptr_t(&m_tss+1),0x89,0xc);
      set_gdt(per_core,uintptr_t(pcore_begin),pcore_size,0x93,0xc);
      set_tss(stack_begin+stack_size-8);
    }

  public:

    void reset(){
      descriptor_register gdtr={uint16_t(N*ia32_gdt_size-1),(uintptr_t)m_gdt};
      asm volatile (
          "lgdt %0\n"
          "mov %2, %%ds\n"
          "mov %2, %%es\n"
          "mov %2, %%ss\n"
          "mov %3, %%fs\n"
          "mov %3, %%gs\n"
          "ljmp %1, $1f\n"
          "1:\n"
          "nop\n"
          :
          :"m"(gdtr),
          "i"(code*ia32_gdt_size),
          "r"(data*ia32_gdt_size),
          "r"(per_core*ia32_gdt_size)
          :"memory"
          );


      asm volatile("ltr %%ax" ::"a"(tss*ia32_gdt_size):"memory");
    }

  public:
    void set_tss(addr_t stackTop){
      for(int i=0;i<ia32_tss_size;i++){
        m_tss[i]=0;
      }
      ia32_tss_ss0_insert(get_tss(),data*ia32_gdt_size);
      ia32_tss_iopb_offset_insert(get_tss(), ia32_tss_size);
      ia32_tss_esp0_insert(get_tss(), uintptr_t(stackTop));
    }


  private:
    ia32_gdt_t get_gdt(int i){ return (ia32_gdt_t)&m_gdt[i][0];}
    ia32_tss_t get_tss(){ return (ia32_tss_t)&m_tss[0];}

    void set_gdt(int index,uint32_t base, uint32_t limit, uint8_t access, uint8_t gran) {
      static_assert(sizeof(m_gdt[0][0])==1,"XXX");
      for(int i=0;i<ia32_gdt_size;i++){
        get_gdt(index)[i]=0;
      }
      ia32_gdt_limit_lo_insert(get_gdt(index),get_bits<15,0>(limit));
      ia32_gdt_base_lo_insert(get_gdt(index),get_bits<15,0>(base));
      ia32_gdt_base_mi_insert(get_gdt(index),get_bits<23,16>(base));
      ia32_gdt_access_insert(get_gdt(index),access);
      ia32_gdt_limit_hi_insert(get_gdt(index),get_bits<19,16>(limit));
      ia32_gdt_gran_insert(get_gdt(index),gran);
      ia32_gdt_base_hi_insert(get_gdt(index),get_bits<31,24>(base));
    }

};

