#pragma once
#include "generated/lpc_cmos.dev.h"

class dev_lpc_cmos_t{
  private:
    lpc_cmos_t m_dev;
  public:
    dev_lpc_cmos_t(io_t base){
      lpc_cmos_initialize(&m_dev, base);
    }
  public:
    void shutdown_wr(){
      lpc_cmos_standard_wr(&m_dev, 0xf, 0xa);
    }
    void warmreset_wr(addr_t addr){
      uint32_t x=get_bits<19,4>(uintptr_t(addr));
      x=(x<<16)|(0); // msb 16 bits is for CS, lsb 16 bits must be zero
      mmio::write32((addr_t)0, 0x467, x);
    }
};
