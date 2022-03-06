#pragma once

#include "util/bitpool.h"
#include "util/util.h"
#include "util/io.h"

class shm_t{
  public:
    size_t   m_rank;
    addr_t   shared_data;   //NCPUs
    addr_t   spsc_data[64]; //NCPUs

    shm_t(int rank, addr_t tshared):
      m_rank(rank),
      shared_data(tshared)
    {
      for(int i=0;i<64;i++){
        spsc_data[i]=0;
      }
    }

    addr_t get_shared() { return shared_data;}

    void set(int i, addr_t m){
      hoh_assert(i!=m_rank, "XXX");
      hoh_assert(spsc_data[i]==0,"XXX");
      hoh_assert(m,"XXX");
      spsc_data[i]=m;
    }
    bool has(int i){
      return spsc_data[i];
    }
    addr_t get(int i){
      hoh_assert(i!=m_rank, "XXX");
      hoh_assert(has(i),"XXX");
      return spsc_data[i];
    }

    void send(int torank){
      hoh_assert(spsc_data[torank],"XXX");
      mmio::write32(spsc_data[torank],0,1);
    }
    void recv(){
      hoh_assert(spsc_data[m_rank],"XXX");
      mmio::write32(spsc_data[m_rank],0,0);
    }
    bool has(){
      return spsc_data[m_rank] && mmio::read32(spsc_data[m_rank],0)!=0;
    }
};


