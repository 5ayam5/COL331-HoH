#pragma once

#include "generated/ia32.dev.h"

class dev_ia32_t{
  private:
    ia32_t m_dev;
  public:
    dev_ia32_t(){
      ia32_initialize(&m_dev);
    }
  public:
    void enable_paging(){
      hoh_debug("enabling paging");
      {
        uint32_t tmp=0;
        asm volatile("movl %%cr4,%0":"=r"(tmp)::"memory");
        tmp|=(1<<4); //PSE: Page Size Extension for 4M page
        asm volatile("movl %0,%%cr4"::"r"(tmp):"memory");
      }
      {
        uint32_t tmp=0;
        asm volatile("movl %%cr0,%0":"=r"(tmp)::"memory");
        tmp|=(1<<31);
        asm volatile("movl %0,%%cr0"::"r"(tmp):"memory");
      }
      hoh_debug("enabled paging");
      //*((volatile int*)0x00adbeef)=0;
    }

    void fpu_simd_reset(){
      {
        uint32_t tmp=0;
        asm volatile("movl %%cr0,%0":"=r"(tmp)::);

        tmp |= (1u<<1);  // set MP
        tmp &= ~(1u<<2); // clear EM
        tmp &= ~(1u<<3); // clear TS
        tmp |= (1u<<4);  // set ET
        tmp |= (1u<<5);  // set NE

        asm volatile("movl %0,%%cr0"::"r"(tmp):"memory");
      }
      {
        uint32_t tmp=0;
        asm volatile("movl %%cr4,%0":"=r"(tmp)::"memory");

        tmp |= (1u<<9);  // set OSFXSR
        tmp |= (1u<<10); // set OSXMMEXCPT

        asm volatile("movl %0,%%cr4"::"r"(tmp):"memory");
      }
    }

    addr_t apic_base(){
      return (addr_t)(ia32_apic_base_base_rdf(&m_dev)<<12);
    }

    bool is_bsp(){
      return ia32_apic_base_bsp_rdf(&m_dev);
    }

};
