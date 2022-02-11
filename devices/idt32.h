#pragma once

#include "generated/ia32.dev.h"
#include "util/util.h"
#include "devices/config.h"

class dev_idt32_t{
  private:
    enum {N=256};
    ia32_idt_array_t m_data[N];

  public:
    dev_idt32_t(){
      static_assert(sizeof(m_data[0])==8,"XXX");
      for(int i=0;i<N;i++){
        set(i,0,0,0);
      }
    }
  public:
    void reset(){
      descriptor_register idtr={uint16_t(N*ia32_idt_size-1),(uintptr_t)m_data};
      asm volatile ( "lidt %0\nnop\n" : :"m"(idtr):"memory");
    }

  public:
    void set(int index, uint32_t base,uint16_t sel,uint8_t flags){
      for(int i=0;i<ia32_idt_size;i++){
        m_data[index][i]=0;
      }
      ia32_idt_base_lo_insert(get_data(index),get_bits<15,0>(base));
      ia32_idt_sel_insert(get_data(index),sel);
      ia32_idt_flags_insert(get_data(index),flags);
      ia32_idt_base_hi_insert(get_data(index),get_bits<31,16>(base));
    }
  private:
    ia32_idt_t get_data(int i){ return (ia32_idt_t)&m_data[i][0];}
};


