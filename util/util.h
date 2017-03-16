#pragma once

#include "util/config.h"
#include "util/debug.h"
#include <new>


#define XSTR(x) #x
#define STR(x) XSTR(x)
#define QUOTE STR

#define XCAT(_x,_y) _x##_y
#define CAT(_x,_y) XCAT(_x,_y)


extern "C" void* memset(void* s, int c, size_t n);
extern "C" void* memcpy(void* __restrict dest, const void* __restrict src, size_t n);
extern "C" int memcmp(const void *s1, const void *s2, size_t n);
extern "C" void* memmove(void* dest, const void* src, size_t n);


typedef uint32_t Index;


template<typename T,typename... Args>
static inline void construct(T* p, Args&&... args){
  new (reinterpret_cast<void*>(p)) T(std::forward<Args>(args)...);
}

template<typename T>
static inline void destroy(T* p){
  p->~T();
}

#if 0
template<int A, int B>
uint32_t set_bits32(uint32_t x){
  typedef uint32_t T;
  T(1)<<B;
  return x<<B;
}
#endif

static inline unsigned int bitfind1(uint64_t x){
    if(sizeof(long)*8==64){
        return __builtin_ctzl(x);
    }else{
        uint32_t y=get_bits<31,0>(x);
        if(y) return __builtin_ctzl(y);
        y=get_bits<63,32>(x);
        if(y) return 32+__builtin_ctzl(y);
    }
}
static inline unsigned int bitcount(uint64_t x){
    if(sizeof(long)*8==64){
        return __builtin_popcountl(x);
    }else{
        uint32_t y1=get_bits<31,0>(x);
        uint32_t y2=get_bits<63,32>(x);
        return __builtin_popcountl(y1)+__builtin_popcountl(y2);
    }
}

static inline void bitclear(uint64_t& x, uint8_t i){
  x= x & ~(uint64_t(1)<<i);
}
static inline void bitset(uint64_t& x, uint8_t i){
  x= x | (uint64_t(1)<<i);
}
static inline bool bittest(uint64_t x, uint8_t i){
  return (x & (uint64_t(1)<<i))!=0;
}


static inline addr_t prevalign(addr_t x, uint32_t align){
  return addr_t((uintptr_t(x)/align) * align);
}

static inline addr_t nextalign(addr_t x, uint32_t align){
  return prevalign(x+align-1,align);
}


template<typename T>
static inline T max(const T& a, const T& b){
  return (!(a<b))? a : b;
}




static inline uint64_t rdtsc() {
	uint32_t lo, hi;
	asm volatile ("rdtsc" : "=a" (lo), "=d" (hi)::"memory");
	return (uint64_t)hi << 32 | lo;
}

static inline uint64_t diff_in_usec(const uint64_t& a,const uint64_t& b){
  return (a-b)/1000.00;
}



struct ScopedTimer{
  ScopedTimer(const char* n):name(n){
    hoh_debug("ScopedTimer: "<<name<<": begin");
    r_start=rdtsc();
  }
  ~ScopedTimer(){
    r_end=rdtsc();
    auto dt=diff_in_usec(r_end,r_start);
    hoh_debug("ScopedTimer: "<<name<<": "<<dt);
  }
  private:
  const char* name;
  uint64_t r_start,r_end;
};




