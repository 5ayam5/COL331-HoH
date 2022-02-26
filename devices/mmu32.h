#pragma once
#include "util/util.h"

class dev_pde32_t{
  public:
    enum { N=1024};
    uint32_t m_page[N] ALIGN(0x1000);
  public:
    dev_pde32_t(){
      hoh_assert(uintptr_t(m_page)%0x1000==0,"Alignment issue");
      for(int i=0;i<N;i++){
        unset(i);
      }
    }
  public:
    void reset(){
      asm volatile("movl %0,%%cr3\n"::"r"(m_page):"memory");
    }
  public:
    void set(char* x, char* p){
      hoh_assert((get_bits<21,0>(uintptr_t(x))==0),"XXX");
      set(get_bits<31,22>((uintptr_t)x), (uintptr_t)p, 0x87);
    }
    void map(char* begin, char* end, char* to){
      hoh_assert(begin<end,"XXX");
      int _i=0;
      hoh_assert((get_bits<21,0>(uintptr_t(begin))==0),"XXX");
      hoh_assert((get_bits<21,0>(uintptr_t(end))==0),"XXX");
      for(char* p=begin; p<end; (p+=(4<<20)), (to+=(4<<20)), _i++){
        set(p, to);
      }
    }
  private:
    void set(int i, uint32_t addr,uint16_t flags){
      hoh_assert((get_bits<11,0>(addr)==0),"XXX");
      m_page[i]=(get_bits<31,12>(addr)<<12) | flags;
    }
    void unset(int i){
      hoh_assert(i>=0 && i<N,"XXX");
      set(i,0,2);
    }
};

