#pragma once
#include "util/io.h"

namespace lpc_ioapic_ioapic{
  static inline uint32_t read32(lpc_ioapic_t* _dev, size_t i){
    mmio::write32(_dev->base,0,i);
    return mmio::read32(_dev->base,0x10);
  }
  static inline void write32(lpc_ioapic_t* _dev, size_t i,uint32_t v){
    mmio::write32(_dev->base,0,i);
    return mmio::write32(_dev->base,0x10,v);
  }
  static inline uint64_t read64(lpc_ioapic_t* _dev, size_t subreg){
    uint32_t lo=read32(_dev, subreg+0);        
    uint32_t hi=read32(_dev, subreg+1);        
    uint64_t ret=(uint64_t(hi)<<32)|lo;
    return ret;
  }
  static inline void write64(lpc_ioapic_t* _dev, size_t subreg,uint64_t value){
    uint32_t lo=get_bits<31,0>(value);                       
    uint32_t hi=get_bits<63,32>(value);                      
    write32(_dev, subreg+0,lo);        
    write32(_dev, subreg+1,hi);        
  }
}

