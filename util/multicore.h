#include "devices/lapic.h"
#include "devices/cmos.h"
#include "util/bitpool.h"
#include "util/shm.h"

template<typename Channels>
static inline void remotecore_reset(int remotecoreid, addr_t remotebootfile, size_t remotebootfilesize, size_t remotebootfileoffset,
                                    int myrank, dev_lpc_cmos_t& cmos, dev_lapic_t& lapic, bitpool_t& pool4M, shm_t& shm){

  hoh_debug("remotecore_reset: from: "<<myrank<<" remotecoreid: "<<remotecoreid);
  enum { PHYS_BOOTADDR=0x7000};
  addr_t bootaddr= addr_t(PHYS_BOOTADDR);


  //copy to boot location
  memcpy(bootaddr, remotebootfile, remotebootfilesize);

  //pointer to boot code/data to be modified
  addr_t p= bootaddr + remotebootfileoffset;

  // 0th offset: bitpool
  bitpool_t* pool_tmp=(bitpool_t*)(p+0);
  hoh_debug(myrank<<"Pool remaining: "<<pool4M.remaining());
  construct(pool_tmp,pool4M.datasize(),addr_t(0));

  for(int i=0;i<10;i++){
    hoh_assert(canalloc(pool4M),"XXX");
    addr_t r=alloc(pool4M);
    pool_tmp->add_mem(r,r+pool4M.datasize());
  }

  if(!shm.has(remotecoreid)){
    Channels* c=allocT<Channels>(pool4M);
    shm.set(remotecoreid,addr_t(c));
  }
  // 512th offset: rank
  mmio::write32(p,512,remotecoreid);                      //remote's myrank
  mmio::write32(p,516,(uint32_t)shm.get(remotecoreid));   //1:1 message
  mmio::write32(p,520,(uint32_t)shm.get_shared());        //shared message

  //reset the remote core
  cmos.shutdown_wr();
  cmos.warmreset_wr(bootaddr);
  lapic.icr_init(true,remotecoreid);
  for(;;){
    if(lapic.poll_wait()){
      break;
    }
  }
  cmos.shutdown_wr();
  cmos.warmreset_wr(bootaddr);
  lapic.icr_init(false,remotecoreid);
  for(;;){
    if(lapic.poll_wait()){
      break;
    }
  }
  lapic.icr_startup(bootaddr,remotecoreid);
  lapic.icr_startup(bootaddr,remotecoreid);
  hoh_debug("remotecore_reset done: from: "<<myrank<<" remotecoreid: "<<remotecoreid);
}



extern unsigned char g_ia32_start16[];
extern unsigned char g_ia32_end16[];
extern unsigned char g_ia32_data16[];

template<typename Channels>
static inline void remotecore_reset_helper(int remotecoreid, int myrank, dev_lpc_cmos_t& cmos, dev_lapic_t& lapic, bitpool_t& pool4M, shm_t& shm){

  addr_t remotebootfile       = &g_ia32_start16[0];
  size_t remotebootfilesize   = uintptr_t(&g_ia32_end16[0])-uintptr_t(&g_ia32_start16[0]);
  size_t remotebootfileoffset = uintptr_t(&g_ia32_data16[0])-uintptr_t(&g_ia32_start16[0]);

  remotecore_reset<Channels>(remotecoreid, remotebootfile, remotebootfilesize, remotebootfileoffset, myrank, cmos, lapic, pool4M, shm);

}
