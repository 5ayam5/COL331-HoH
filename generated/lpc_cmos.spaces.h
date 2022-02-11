#pragma once

static inline void lpc_cmos_ndx_wr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_target_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline void lpc_cmos_target_wr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_cmos_endx_wr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_etarget_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline void lpc_cmos_etarget_wr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
namespace lpc_cmos_std{
  static inline uint8_t read8(lpc_cmos_t* dev, int i){
    lpc_cmos_ndx_wr(dev, i);
    return lpc_cmos_target_rd(dev);
  }
  static inline void write8(lpc_cmos_t* dev, int i, uint8_t val){
    lpc_cmos_ndx_wr(dev, i);
    return lpc_cmos_target_wr(dev,val);
  }
}
namespace lpc_cmos_ext{
  static inline uint8_t read8(lpc_cmos_t* dev, int i){
    lpc_cmos_endx_wr(dev, i);
    return lpc_cmos_etarget_rd(dev);
  }
  static inline void write8(lpc_cmos_t* dev, int i, uint8_t val){
    lpc_cmos_endx_wr(dev, i);
    return lpc_cmos_etarget_wr(dev,val);
  }
}

