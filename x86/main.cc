#include "labs/vgatext.h"
#include "util/debug.h"


//
// main
//
extern "C" void core_boot(){
  addr_t vgatext_base=(addr_t)0xb8000;

  const char* p="Hello, world!";
  for(int loc=0;*p;loc++,p++){
    vgatext::writechar(loc,*p,0,7,vgatext_base);
  }
  hoh_debug("Hello, serial!");
}

