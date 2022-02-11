#pragma once
#include "generated/lpc_timer.dev.h"

class dev_lpc_timer_t{
  private:
    lpc_timer_t m_dev;
  public:
    dev_lpc_timer_t(io_t base){
      lpc_timer_initialize(&m_dev,base);
    }
  public:
    void set_hz(int32_t hz){
      uint16_t divisor = (hz == 0 ? 0 : (1193180 / hz));

      {
        lpc_timer_tcw_t x=(lpc_timer_tcw_t)lpc_timer_tcw_default;
        x=lpc_timer_tcw_bcd_insert(x,0);
        x=lpc_timer_tcw_mode_insert(x,lpc_timer_rtgen); //if not periodic use oseoc
        x=lpc_timer_tcw_rwsel_insert(x,lpc_timer_lmsb); //lsb then msb
        x=lpc_timer_tcw_select_insert(x,lpc_timer_c0);
        lpc_timer_tcw_wr(&m_dev,x);
      }

      lpc_timer_cntacc0_wr(&m_dev, get_bits<7,0>(divisor));    //lsb
      lpc_timer_cntacc0_wr(&m_dev, get_bits<15,8>(divisor));   //msb
    }

};

