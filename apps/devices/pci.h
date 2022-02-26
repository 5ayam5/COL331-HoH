#pragma once

#include "apps/generated/pci_hdr0.dev.h"

class dev_pci_t{
  private:
    pci_hdr0_t m_dev;
  public:
    dev_pci_t(uint8_t bus, uint8_t slot, uint8_t func){
      pci_t addr(bus,slot,func);
      pci_hdr0_initialize(&m_dev,addr);
    }

    uint16_t vendor_id(){
      return pci_hdr0_vendor_id_rd(&m_dev);
    }
    uint16_t device_id(){
      return pci_hdr0_device_id_rd(&m_dev);
    }

    pci_hdr0_hdr_type_t hdr_type(){
      return pci_hdr0_hdr_type_rd(&m_dev);
    }

    bool is_multi(pci_hdr0_hdr_type_t x){
      return pci_hdr0_hdr_type_multi_extract(x);
    }

    bool is_multi(){
      return pci_hdr0_hdr_type_multi_rdf(&m_dev);
    }


    bool isbar32(int id){
      auto x=pci_hdr0_bars_rd(&m_dev,id);
      pci_hdr0_bars_wr(&m_dev,id,0xffffffff);
      auto y=pci_hdr0_bars_rd(&m_dev,id);
      pci_hdr0_bars_wr(&m_dev,id,x);
      pci_hdr0_bar32_t t{y};
      return !pci_hdr0_bar32_space_extract(t) && pci_hdr0_bar32_tpe_extract(t)==pci_hdr0_bar_32bit;
    }

    addr_t base32(int id){
      auto x=pci_hdr0_bars_rd(&m_dev,id);
      pci_hdr0_bar32_t xx{x};
      return addr_t(pci_hdr0_bar32_base_extract(xx)<<7); //why hardcoded 7 (base is 25 bits)
    }

    void command_master(bool x){
      pci_hdr0_command_master_wrf(&m_dev,x);
    }

    void dump(){
      hoh_debug("pci: "<<&m_dev);
    }
};

