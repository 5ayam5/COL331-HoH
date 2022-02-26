#pragma once
#include "generated/lpc_ioapic.dev.h"

// dont call from interrupt handlers
class dev_lpc_ioapic_t{
  private:
    lpc_ioapic_t m_dev;
  public:
    dev_lpc_ioapic_t(addr_t base){
      lpc_ioapic_initialize(&m_dev,base);
    }

  public:
    void reset(){
      int mre=lpc_ioapic_ver_mre_rdf(&m_dev);
      int nirq=mre+1;
      hoh_debug("nirq="<<nirq);
      for(int i=0;i<nirq;i++){
        lpc_ioapic_redir_tbl_t x=lpc_ioapic_redirtbl_rd(&m_dev,i);
        x=lpc_ioapic_redir_tbl_vector_insert(x,48+i);
        x=lpc_ioapic_redir_tbl_mask_insert(x,0); //masked
        lpc_ioapic_redirtbl_wr(&m_dev,i,x);
      }
      //setmode(true);
    }
  public:
    void eoi(int rec){
      lpc_ioapic_eoir_rec_wrf(&m_dev,rec);
    }
  private:
    void setmode(bool lapic){
      io::write8(0x0, 0x22, 0x70);
      io::write8(0x0, 0x23, lapic);
    }
  private:
};

