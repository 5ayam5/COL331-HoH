#pragma once

#include "util/config.h"
#include "util/debug.h"

namespace io {

  static inline uint8_t read8(io_t p, uint16_t i){
    io_t pp=p+i;
    uint8_t value;
    asm volatile ("inb %1, %0" : "=a"(value) : "d"(pp) );
    return value;
  }
  static inline void write8(io_t p, uint16_t i, uint8_t value){
    io_t pp=p+i;
    asm volatile ("outb %0, %1" :: "a"(value) , "d"(pp));
  }



  static inline uint16_t read16(io_t p, uint16_t i){
    io_t pp=p+i;
    uint16_t value;
    asm volatile ("inw %1, %0" : "=a"(value) : "d"(pp) );
    return value;
  }
  static inline void write16(io_t p, uint16_t i, uint16_t value){
    io_t pp=p+i;
    asm volatile ("outw %0, %1" :: "a"(value) , "d"(pp));
  }


  static inline uint32_t read32(io_t p, uint16_t i){
    io_t pp=p+i;
    uint32_t value;
    asm volatile ("inl %1, %0" : "=a"(value) : "d"(pp) );
    return value;
  }
  static inline void write32(io_t p, uint16_t i, uint32_t value){
    io_t pp=p+i;
    asm volatile ("outl %0, %1" :: "a"(value) , "d"(pp));
  }


} //namespace io

namespace mmio{

  static inline uint8_t read8(addr_t p, uint32_t index){
    volatile uint8_t* pp=(uint8_t*)(p+index);
    uint8_t value=*pp;
    asm volatile ("mfence":::"memory");
    return value;
  }
  static inline void write8(addr_t p, uint32_t index, uint8_t value){
    volatile uint8_t* pp=(uint8_t*)(p+index);
    *pp=value;
    asm volatile ("mfence":::"memory");
  }



  static inline uint16_t read16(addr_t p, uint32_t index){
    volatile uint16_t* pp=(uint16_t*)(p+index);
    uint16_t value=*pp;
    asm volatile ("mfence":::"memory");
    return value;
  }
  static inline void write16(addr_t p, uint32_t index, uint16_t value){
    volatile uint16_t* pp=(uint16_t*)(p+index);
    *pp=value;
    asm volatile ("mfence":::"memory");
  }



  static inline uint32_t read32(addr_t p, uint32_t index){
    volatile uint32_t* pp=(uint32_t*)(p+index);
    uint32_t value=*pp;
    asm volatile ("mfence":::"memory");
    return value;
  }
  static inline void write32(addr_t p, uint32_t index, uint32_t value){
    volatile uint32_t* pp=(uint32_t*)(p+index);
    *pp=value;
    asm volatile ("mfence":::"memory");
  }


} //namespace mmio


namespace pci{
  typedef uint16_t index_t;
  enum { pci_base=0xcf8, pci_conf=0, pci_data=4};

  static inline uint32_t address(pci_t p, index_t index){
    return (uint32_t(1)<<31)| (uint32_t(p.bus)<<16) |  (uint32_t(p.slot)<<11) | (uint32_t(p.func)<<8) | uint32_t(index);
  }





  static inline uint32_t read32(pci_t p, index_t index){
    hoh_assert(index%4==0,"XXX");
    uint32_t value;
    io::write32(pci_base,pci_conf, address(p,index));
    value=io::read32(pci_base, pci_data);
    return value;
  }
  static inline void write32(pci_t p, index_t index, uint32_t value){
    hoh_assert(index%4==0,"XXX");
    io::write32(pci_base,pci_conf, address(p,index));
    io::write32(pci_base, pci_data, value);
  }






  static inline uint8_t read8(pci_t p, index_t index){
    uint32_t word=read32(p,index&~0x3);
    uint8_t value;
    switch(index%4){
      case 0:
        value=get_bits<7,0>(word);
        break;
      case 1:
        value=get_bits<15,8>(word);
        break;
      case 2:
        value=get_bits<23,16>(word);
        break;
      case 3:
        value=get_bits<31,24>(word);
        break;
    }
    return value;
  }
  static inline void write8(pci_t p, index_t index, uint8_t value){
    uint32_t word=read32(p,index&~0x3);
    switch(index%4){
      case 0:
        word=set_bits<7,0>(word,value);
        break;
      case 1:
        word=set_bits<15,8>(word,value);
        break;
      case 2:
        word=set_bits<23,16>(word,value);
        break;
      case 3:
        word=set_bits<31,24>(word,value);
        break;
    }
    write32(p,index&~0x3,word);
  }



  static inline uint16_t read16(pci_t p, index_t index){
    uint32_t word=read32(p,index&~0x3);
    uint16_t value;
    switch(index%4){
      case 0:
        value=get_bits<15,0>(word);
        break;
      case 2:
        value=get_bits<31,16>(word);
        break;
      default:
        hoh_assert(false,"XXX");
        break;
    }
    return value;
  }
  static inline void write16(pci_t p, index_t index, uint16_t value){
    uint32_t word=read32(p,index&~0x3);
    switch(index%4){
      case 0:
        word=set_bits<15,0>(word,value);
        break;
      case 2:
        word=set_bits<31,24>(word,value);
        break;
      default:
        hoh_assert(false,"XXX");
        break;
    }
    write32(p,index&~0x3,word);
  }



} //namespace pci

