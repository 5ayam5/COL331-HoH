#include "util/config.h"

//
//
//DESCRIPTION
//       The memset() function fills the first n bytes of the memory area pointed to by s with the constant byte c.
//RETURN VALUE
//       The memset() function returns a pointer to the memory area s.
extern "C" void* memset(void* s, int c, size_t n){
  addr_t p=addr_t(s);
  for(size_t i = 0; i < n; i++){
    p[i] = uint8_t(c);
  }
  return s;
}


//
//DESCRIPTION
//       The memcpy() function copies n bytes from memory area src to memory area dest.  The memory areas must not overlap.  Use memmove(3) if the memory areas do overlap.
//
//RETURN VALUE
//       The memcpy() function returns a pointer to dest.
//
extern "C" void* memcpy(void* __restrict dest, const void* __restrict src, size_t n){
  addr_t      d = addr_t(dest);
  constaddr_t s = constaddr_t(src);

  for (size_t i = 0; i < n; i++){
    d[i] = s[i];
  }

  return dest;
}



//
//DESCRIPTION
//       The memcmp() function compares the first n bytes (each interpreted as unsigned char) of the memory areas s1 and s2.
//
//RETURN VALUE
//       The memcmp() function returns an integer less than, equal to, or greater than zero if the first n bytes of s1 is found, respectively, to be less than, to match, or be greater than the first n bytes of s2.
//
//       For a nonzero return value, the sign is determined by the sign of the difference between the first pair of bytes (interpreted as unsigned char) that differ in s1 and s2.
//
extern "C" int memcmp(const void *s1, const void *s2, size_t n){
  constaddr_t p=constaddr_t(s1);
  constaddr_t q=constaddr_t(s2);

  for(size_t i = 0; i < n; i++){
    if (p[i] < q[i]) {
      return -1;
    } else if ( p[i] > q[i] ){
      return 1;
    }
  }

  return 0;
}


//
//DESCRIPTION
//       The memmove() function copies n bytes from memory area src to memory area dest.  The memory areas may overlap: copying takes place as though the bytes in src are first copied into a temporary array that does not overlap src or
//       dest, and the bytes are then copied from the temporary array to dest.
//
//RETURN VALUE
//       The memmove() function returns a pointer to dest.
//
extern "C" void* memmove(void* dest, const void* src, size_t n){
  addr_t      d = addr_t(dest);
  constaddr_t s = constaddr_t(src);

//
//   s S d D  : ANY
//   s d S D  : BW
//   s d D S  : BW
//
//   d D s S  : ANY
//   d s D S  : FW
//   d s S D  : FW
//

  if (s<d){ // BW
    for(size_t i = n; i > 0; i--){
      d[i-1] = s[i-1];
    }
  }else if(d<s){ //FW
    for(size_t i = 0; i < n; i++){
      d[i] = s[i];
    }
  }

  return dest;
}


