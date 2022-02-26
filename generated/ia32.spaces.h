#pragma once

namespace ia32_msr{
  static inline uint64_t read64(ia32_t* _dev, size_t i){
    uint32_t lo,hi;
    asm volatile("rdmsr" 
        : "=a"(lo)
        , "=d"(hi) 
        : "c"(i)
        );
    uint64_t ret=hi;
    ret = ret<<32 | lo;
    return ret;

  }
  static inline void write64(ia32_t* _dev, size_t i,uint64_t value){
    asm volatile("wrmsr" 
        :
        : "a"(get_bits<31,0>(value))
        , "d"(get_bits<63,32>(value))
        , "c"(i)
        );
  }
  void write32(ia32_t* _dev, size_t,uint32_t );
  uint32_t read32(ia32_t* _dev, size_t);
}

