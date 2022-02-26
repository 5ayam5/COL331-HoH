#pragma once
#include "generated/lpc_pic.dev.h"

class dev_lpc_pic_t{
  private:
    lpc_pic_t m_dev;
  public:
    dev_lpc_pic_t(io_t base){
      lpc_pic_initialize(&m_dev,base);
    }
  public:
    void reset(int irq){
      maskall();
      lpc_pic_master_icw1_wr(&m_dev,lpc_pic_icw1_default);
      lpc_pic_slave_icw1_wr(&m_dev,lpc_pic_icw1_default);

      lpc_pic_master_icw2_base_wrf(&m_dev,irq);
      lpc_pic_slave_icw2_base_wrf(&m_dev,irq+8);

      lpc_pic_master_icw3_cascade_wrf(&m_dev,1); //enable cascade
      lpc_pic_slave_icw3_slave_id_wrf(&m_dev,2); //cascaded at 2

      lpc_pic_master_icw4_wr(&m_dev,lpc_pic_icw4_default);
      lpc_pic_slave_icw4_wr(&m_dev,lpc_pic_icw4_default);

      maskall();
    }

  public:

    void eoi_master(){
      lpc_pic_master_ocw2_rsleoi_wrf(&m_dev,lpc_pic_eoi);
    }
    void eoi_slave(){
      lpc_pic_slave_ocw2_rsleoi_wrf(&m_dev,lpc_pic_eoi);
      lpc_pic_master_ocw2_rsleoi_wrf(&m_dev,lpc_pic_eoi);
    }
    void maskall(){
      lpc_pic_master_ocw1_wr(&m_dev,0xff);
      lpc_pic_slave_ocw1_wr(&m_dev,0xff);
    }
    void unmaskall(){
      lpc_pic_master_ocw1_wr(&m_dev,0x0);
      lpc_pic_slave_ocw1_wr(&m_dev,0x0);
    }

    uint16_t get_irq(){
      lpc_pic_master_ocw3_rrc_wrf(&m_dev, lpc_pic_read_irq);
      uint8_t m=lpc_pic_master_ocw3rd_rd(&m_dev);
      lpc_pic_slave_ocw3_rrc_wrf(&m_dev, lpc_pic_read_irq);
      uint8_t s=lpc_pic_slave_ocw3rd_rd(&m_dev);
      return (s<<8)|m;
    }

    uint16_t get_is(){
      lpc_pic_master_ocw3_rrc_wrf(&m_dev, lpc_pic_read_is);
      uint8_t m=lpc_pic_master_ocw3rd_rd(&m_dev);
      lpc_pic_slave_ocw3_rrc_wrf(&m_dev, lpc_pic_read_is);
      uint8_t s=lpc_pic_slave_ocw3rd_rd(&m_dev);
      return (s<<8)|m;
    }

    void dump(){
      hoh_debug("PIC: "<<&m_dev);
    }

};



