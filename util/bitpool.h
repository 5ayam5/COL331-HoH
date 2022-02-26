#pragma once

#include "util/util.h"

//
// Pool data: we'll have eventually have alignment issues
// and combining metadata with data won't be space efficient.
// Ex: 4k Page alignment, 2MB alignment.
// Intrusive would've been better though.
//
// There'll be multiple types of pools..
//  - so we have to decide now, on how to handle these
//


struct bitpool_t{
  public:
    enum {N=61};//make it 512 bytes
    typedef uint16_t index_t;
  private:
    addr_t   m_data;
    uint32_t m_datasize;
    uint64_t m_level0; //=0;
    uint64_t m_level1[N]; // ={0};
  public:
    bitpool_t(uint32_t ds0, addr_t d0):m_data(d0), m_datasize(ds0){
      //for ancient gcc-4.6
      m_level0 = 0;
      for(int i=0;i<N;i++){
        m_level1[i]=0;
      }
    }

    index_t to_index(addr_t x){
      index_t index=(x-m_data)/datasize();
      return index;
    }
    void add_mem(addr_t from, addr_t to){
      hoh_assert((to-from)%datasize()==0, "XXX");
      hoh_assert(uintptr_t(from-m_data)%datasize()==0,"XXX");
      for(;from!=to;from+=datasize()){
        index_t index=to_index(from);
        hoh_assert(index<N*64,"XXX:"<<index<<" "<<uintptr_t(from)<<" "<<uintptr_t(to)<<" sz="<<uintptr_t(to-from)<<" del="<<uintptr_t(from-m_data)<<" ds="<<datasize()<<" ");
        //hoh_debug(uintptr_t(this)<<": Added: "<<uintptr_t(from)<<" index="<<index);
        free(index);
      }
    }
    bool     canalloc(){
      return !empty();
    }
    bool empty(){
      return m_level0==0;
    }
    index_t alloc(){
      //hoh_debug(uintptr_t(this)<<": Allocating. Size= "<<remaining());
      hoh_assert(canalloc(), "XXX");

      index_t i0=bitfind1(m_level0);
      index_t i1=bitfind1(m_level1[i0]);
      //hoh_debug("before: L0="<<m_level0<<" i0="<<i0<<" L1="<<m_level1[i0]<<" i1="<<i1);
      bitclear(m_level1[i0],i1);
      if(m_level1[i0]==0){
        bitclear(m_level0,i0);
      }
      //hoh_debug("after: L0="<<m_level0<<" i0="<<i0<<" L1="<<m_level1[i0]<<" i1="<<i1);
      index_t i=i0*64 + i1;
      //hoh_debug("alloced: "<<i);
      return i;
    }
    void free(index_t i){
      hoh_assert(0<=i && i<N*64, "XXX: "<<i);
      index_t i0=i/64;
      index_t i1=i%64;
      hoh_assert(bittest(m_level1[i0],i1)==false,"XXX:"<<i0<<" "<<i1<<" "<<m_level1[i0]);
      bitset(m_level1[i0],i1);
      bitset(m_level0,i0);
      //hoh_debug(uintptr_t(this)<<": freed: "<<i<<"..."<<i0<<" "<<i1<<" "<<m_level1[i0]<<" Remaining: "<<remaining());
    }
    addr_t get(index_t i){
      return m_data + i*m_datasize;
    }
    uint32_t datasize()const{ return m_datasize;}
    index_t remaining()const{
      index_t ret=0;
      for(index_t i=0;i<N;i++){
        for(index_t j=0;j<64;j++){
          if(bittest(m_level1[i],j)){
            ret++;
          }
        }
        //ret+=bitcount(m_level1[i]);
      }
      return ret;
    }
  public:
};



static inline void add_mem(bitpool_t& p, addr_t from, addr_t to){
  p.add_mem(from,to);
}


static inline bool canalloc(bitpool_t& pool){
  return pool.canalloc();
}

static inline addr_t alloc(bitpool_t& pool){
  return pool.get(pool.alloc());
}

static inline void free(bitpool_t& pool, addr_t x){
  return pool.free(pool.to_index((addr_t)x));
}

template<typename T, typename... Args>
static inline T* allocT(bitpool_t& pool, Args&&... args){
  addr_t p=alloc(pool);
  construct((T*)p,std::forward<Args>(args)...);
  return (T*)p;
}


