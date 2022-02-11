#pragma once
/*
 * Device Definition: LPC Real-Time Clock
 * 
 * Automatically Generated from Spec.
 * Using a modified mackerel.
 * 
 * DO NOT EDIT!
 */
#include "util/debug.h"
#include "util/io.h"
#undef __DN
#define __DN(x) lpc_cmos ## _ ## x
/*
 * Constants defn: lpc_cmos.dcs (Division chain select)
 *  - no width specified
 */
HOH_STRONG_TYPEDEF( uint8_t , lpc_cmos_dcs_t);
#define lpc_cmos_normal ((lpc_cmos_dcs_t)0x2)
#define lpc_cmos_divreset ((lpc_cmos_dcs_t)0x6)
#define lpc_cmos_divreset2 ((lpc_cmos_dcs_t)0x7)
#define lpc_cmos_bypass15 ((lpc_cmos_dcs_t)0x5)
#define lpc_cmos_bypass10 ((lpc_cmos_dcs_t)0x4)
#define lpc_cmos_bypass5 ((lpc_cmos_dcs_t)0x3)

static inline const char* lpc_cmos_dcs_describe(lpc_cmos_dcs_t _e) __attribute__ ((always_inline));
static inline const char* lpc_cmos_dcs_describe(lpc_cmos_dcs_t _e)
{
    switch ((uint8_t )(_e)) {
    case (uint8_t )(0x2):
        return("normal: Normal operation");
    case (uint8_t )(0x6):
        return("divreset: Divider reset");
    case (uint8_t )(0x7):
        return("divreset2: Divider reset");
    case (uint8_t )(0x5):
        return("bypass15: Bypass 15 stages");
    case (uint8_t )(0x4):
        return("bypass10: Bypass 10 stages");
    case (uint8_t )(0x3):
        return("bypass5: Bypass 5 stages");
    default:
        return(NULL);
    }
}

static inline dout_t& operator<<(dout_t& _os, lpc_cmos_dcs_t _e) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, lpc_cmos_dcs_t _e)
{
    const char* d = lpc_cmos_dcs_describe(_e);
    if (d) {
        return(_os << d);
    } else {
        return((((_os << ("Unknown constant:")) << ("lpc_cmos_dcs_t")) << ("value:")) << ((uint64_t )(_e)));
    }
}

/*
 * Constants defn: lpc_cmos.rate (Rate select)
 *  - no width specified
 */
HOH_STRONG_TYPEDEF( uint8_t , lpc_cmos_rate_t);
#define lpc_cmos_never ((lpc_cmos_rate_t)0x0)
#define lpc_cmos_ms3_90625_ ((lpc_cmos_rate_t)0x1)
#define lpc_cmos_ms7_8125_ ((lpc_cmos_rate_t)0x2)
#define lpc_cmos_us122_070 ((lpc_cmos_rate_t)0x3)
#define lpc_cmos_us244_141 ((lpc_cmos_rate_t)0x4)
#define lpc_cmos_us488_281 ((lpc_cmos_rate_t)0x5)
#define lpc_cmos_us976_5625 ((lpc_cmos_rate_t)0x6)
#define lpc_cmos_ms1_953125 ((lpc_cmos_rate_t)0x7)
#define lpc_cmos_ms3_906251 ((lpc_cmos_rate_t)0x8)
#define lpc_cmos_ms7_8125 ((lpc_cmos_rate_t)0x9)
#define lpc_cmos_ms15_625 ((lpc_cmos_rate_t)0xa)
#define lpc_cmos_ms31_25 ((lpc_cmos_rate_t)0xb)
#define lpc_cmos_ms62_5 ((lpc_cmos_rate_t)0xc)
#define lpc_cmos_ms125 ((lpc_cmos_rate_t)0xd)
#define lpc_cmos_ms250 ((lpc_cmos_rate_t)0xe)
#define lpc_cmos_ms500 ((lpc_cmos_rate_t)0xf)

static inline const char* lpc_cmos_rate_describe(lpc_cmos_rate_t _e) __attribute__ ((always_inline));
static inline const char* lpc_cmos_rate_describe(lpc_cmos_rate_t _e)
{
    switch ((uint8_t )(_e)) {
    case (uint8_t )(0x0):
        return("never: Interrupt never toggles");
    case (uint8_t )(0x1):
        return("ms3_90625_: 3.90625 ms (duplicate)");
    case (uint8_t )(0x2):
        return("ms7_8125_: 7.8125 ms (duplicate)");
    case (uint8_t )(0x3):
        return("us122_070: 122.070 us");
    case (uint8_t )(0x4):
        return("us244_141: 244.141 us");
    case (uint8_t )(0x5):
        return("us488_281: 488.281 us");
    case (uint8_t )(0x6):
        return("us976_5625: 976.5625 us");
    case (uint8_t )(0x7):
        return("ms1_953125: 1.953125 ms");
    case (uint8_t )(0x8):
        return("ms3_906251: 3.906251 ms");
    case (uint8_t )(0x9):
        return("ms7_8125: 7.8125 ms");
    case (uint8_t )(0xa):
        return("ms15_625: 15.625 ms");
    case (uint8_t )(0xb):
        return("ms31_25: 31.25 ms");
    case (uint8_t )(0xc):
        return("ms62_5: 62.5 ms");
    case (uint8_t )(0xd):
        return("ms125: 125 ms");
    case (uint8_t )(0xe):
        return("ms250: 250 ms");
    case (uint8_t )(0xf):
        return("ms500: 500 ms");
    default:
        return(NULL);
    }
}

static inline dout_t& operator<<(dout_t& _os, lpc_cmos_rate_t _e) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, lpc_cmos_rate_t _e)
{
    const char* d = lpc_cmos_rate_describe(_e);
    if (d) {
        return(_os << d);
    } else {
        return((((_os << ("Unknown constant:")) << ("lpc_cmos_rate_t")) << ("value:")) << ((uint64_t )(_e)));
    }
}

/*
 * Register type: lpc_cmos_rega_t
 * Description: Implicit type of Register A register
 * Fields:
 *   rs	(size 4, offset 0, init 0):	RW	Rate select
 *   dv	(size 3, offset 4, init 0):	RW	Divisioin chain select
 *   uip	(size 1, offset 7, init 0):	RW	Update in progress
 */
HOH_STRONG_TYPEDEF( uint8_t , lpc_cmos_rega_t);
#define lpc_cmos_rega_default (lpc_cmos_rega_t )(0x0)
static inline lpc_cmos_rate_t lpc_cmos_rega_rs_extract(lpc_cmos_rega_t _regval) __attribute__ ((always_inline));
static inline lpc_cmos_rate_t lpc_cmos_rega_rs_extract(lpc_cmos_rega_t _regval)
{
    return((lpc_cmos_rate_t )((_regval & 0xf) >> 0));
}

static inline lpc_cmos_rega_t lpc_cmos_rega_rs_insert(lpc_cmos_rega_t _regval, lpc_cmos_rate_t _fieldval) __attribute__ ((always_inline));
static inline lpc_cmos_rega_t lpc_cmos_rega_rs_insert(lpc_cmos_rega_t _regval, lpc_cmos_rate_t _fieldval)
{
    return((lpc_cmos_rega_t )((_regval & 0xf0) | (0xf & (((lpc_cmos_rega_t )(_fieldval)) << 0))));
}

static inline lpc_cmos_dcs_t lpc_cmos_rega_dv_extract(lpc_cmos_rega_t _regval) __attribute__ ((always_inline));
static inline lpc_cmos_dcs_t lpc_cmos_rega_dv_extract(lpc_cmos_rega_t _regval)
{
    return((lpc_cmos_dcs_t )((_regval & 0x70) >> 4));
}

static inline lpc_cmos_rega_t lpc_cmos_rega_dv_insert(lpc_cmos_rega_t _regval, lpc_cmos_dcs_t _fieldval) __attribute__ ((always_inline));
static inline lpc_cmos_rega_t lpc_cmos_rega_dv_insert(lpc_cmos_rega_t _regval, lpc_cmos_dcs_t _fieldval)
{
    return((lpc_cmos_rega_t )((_regval & 0x8f) | (0x70 & (((lpc_cmos_rega_t )(_fieldval)) << 4))));
}

static inline uint8_t lpc_cmos_rega_uip_extract(lpc_cmos_rega_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_rega_uip_extract(lpc_cmos_rega_t _regval)
{
    return((uint8_t )((_regval & 0x80) >> 7));
}

static inline lpc_cmos_rega_t lpc_cmos_rega_uip_insert(lpc_cmos_rega_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_cmos_rega_t lpc_cmos_rega_uip_insert(lpc_cmos_rega_t _regval, uint8_t _fieldval)
{
    return((lpc_cmos_rega_t )((_regval & 0x7f) | (0x80 & (((lpc_cmos_rega_t )(_fieldval)) << 7))));
}

static inline dout_t& operator<<(dout_t& _os, lpc_cmos_rega_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, lpc_cmos_rega_t _regval)
{
    ((_os << (" rs =\t")) << lpc_cmos_rega_rs_extract(_regval)) << ("\t(Rate select)\n");
    ((_os << (" dv =\t")) << lpc_cmos_rega_dv_extract(_regval)) << ("\t(Divisioin chain select)\n");
    ((_os << (" uip =\t")) << lpc_cmos_rega_uip_extract(_regval)) << ("\t(Update in progress)\n");
    return(_os);
}

/*
 * Register type: lpc_cmos_regb_t
 * Description: Implicit type of General configuration register
 * Fields:
 *   dse	(size 1, offset 0, init 0):	RW	Daylight savings enable
 *   hourform	(size 1, offset 1, init 0):	RW	Hour format
 *   dm	(size 1, offset 2, init 0):	RW	Data mode (BCD/binary)
 *   sqwe	(size 1, offset 3, init 0):	RW	Square wave enable
 *   uie	(size 1, offset 4, init 0):	RW	Update-ended interrupt enable
 *   aie	(size 1, offset 5, init 0):	RW	Alarm interrupt enable
 *   pie	(size 1, offset 6, init 0):	RW	Periodic interrupt enable
 *   set	(size 1, offset 7, init 0):	RW	Update cycle inhibit
 */
HOH_STRONG_TYPEDEF( uint8_t , lpc_cmos_regb_t);
#define lpc_cmos_regb_default (lpc_cmos_regb_t )(0x0)
static inline uint8_t lpc_cmos_regb_dse_extract(lpc_cmos_regb_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_regb_dse_extract(lpc_cmos_regb_t _regval)
{
    return((uint8_t )((_regval & 0x1) >> 0));
}

static inline lpc_cmos_regb_t lpc_cmos_regb_dse_insert(lpc_cmos_regb_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_cmos_regb_t lpc_cmos_regb_dse_insert(lpc_cmos_regb_t _regval, uint8_t _fieldval)
{
    return((lpc_cmos_regb_t )((_regval & 0xfe) | (0x1 & (((lpc_cmos_regb_t )(_fieldval)) << 0))));
}

static inline uint8_t lpc_cmos_regb_hourform_extract(lpc_cmos_regb_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_regb_hourform_extract(lpc_cmos_regb_t _regval)
{
    return((uint8_t )((_regval & 0x2) >> 1));
}

static inline lpc_cmos_regb_t lpc_cmos_regb_hourform_insert(lpc_cmos_regb_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_cmos_regb_t lpc_cmos_regb_hourform_insert(lpc_cmos_regb_t _regval, uint8_t _fieldval)
{
    return((lpc_cmos_regb_t )((_regval & 0xfd) | (0x2 & (((lpc_cmos_regb_t )(_fieldval)) << 1))));
}

static inline uint8_t lpc_cmos_regb_dm_extract(lpc_cmos_regb_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_regb_dm_extract(lpc_cmos_regb_t _regval)
{
    return((uint8_t )((_regval & 0x4) >> 2));
}

static inline lpc_cmos_regb_t lpc_cmos_regb_dm_insert(lpc_cmos_regb_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_cmos_regb_t lpc_cmos_regb_dm_insert(lpc_cmos_regb_t _regval, uint8_t _fieldval)
{
    return((lpc_cmos_regb_t )((_regval & 0xfb) | (0x4 & (((lpc_cmos_regb_t )(_fieldval)) << 2))));
}

static inline uint8_t lpc_cmos_regb_sqwe_extract(lpc_cmos_regb_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_regb_sqwe_extract(lpc_cmos_regb_t _regval)
{
    return((uint8_t )((_regval & 0x8) >> 3));
}

static inline lpc_cmos_regb_t lpc_cmos_regb_sqwe_insert(lpc_cmos_regb_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_cmos_regb_t lpc_cmos_regb_sqwe_insert(lpc_cmos_regb_t _regval, uint8_t _fieldval)
{
    return((lpc_cmos_regb_t )((_regval & 0xf7) | (0x8 & (((lpc_cmos_regb_t )(_fieldval)) << 3))));
}

static inline uint8_t lpc_cmos_regb_uie_extract(lpc_cmos_regb_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_regb_uie_extract(lpc_cmos_regb_t _regval)
{
    return((uint8_t )((_regval & 0x10) >> 4));
}

static inline lpc_cmos_regb_t lpc_cmos_regb_uie_insert(lpc_cmos_regb_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_cmos_regb_t lpc_cmos_regb_uie_insert(lpc_cmos_regb_t _regval, uint8_t _fieldval)
{
    return((lpc_cmos_regb_t )((_regval & 0xef) | (0x10 & (((lpc_cmos_regb_t )(_fieldval)) << 4))));
}

static inline uint8_t lpc_cmos_regb_aie_extract(lpc_cmos_regb_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_regb_aie_extract(lpc_cmos_regb_t _regval)
{
    return((uint8_t )((_regval & 0x20) >> 5));
}

static inline lpc_cmos_regb_t lpc_cmos_regb_aie_insert(lpc_cmos_regb_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_cmos_regb_t lpc_cmos_regb_aie_insert(lpc_cmos_regb_t _regval, uint8_t _fieldval)
{
    return((lpc_cmos_regb_t )((_regval & 0xdf) | (0x20 & (((lpc_cmos_regb_t )(_fieldval)) << 5))));
}

static inline uint8_t lpc_cmos_regb_pie_extract(lpc_cmos_regb_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_regb_pie_extract(lpc_cmos_regb_t _regval)
{
    return((uint8_t )((_regval & 0x40) >> 6));
}

static inline lpc_cmos_regb_t lpc_cmos_regb_pie_insert(lpc_cmos_regb_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_cmos_regb_t lpc_cmos_regb_pie_insert(lpc_cmos_regb_t _regval, uint8_t _fieldval)
{
    return((lpc_cmos_regb_t )((_regval & 0xbf) | (0x40 & (((lpc_cmos_regb_t )(_fieldval)) << 6))));
}

static inline uint8_t lpc_cmos_regb_set_extract(lpc_cmos_regb_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_regb_set_extract(lpc_cmos_regb_t _regval)
{
    return((uint8_t )((_regval & 0x80) >> 7));
}

static inline lpc_cmos_regb_t lpc_cmos_regb_set_insert(lpc_cmos_regb_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_cmos_regb_t lpc_cmos_regb_set_insert(lpc_cmos_regb_t _regval, uint8_t _fieldval)
{
    return((lpc_cmos_regb_t )((_regval & 0x7f) | (0x80 & (((lpc_cmos_regb_t )(_fieldval)) << 7))));
}

static inline dout_t& operator<<(dout_t& _os, lpc_cmos_regb_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, lpc_cmos_regb_t _regval)
{
    ((_os << (" dse =\t")) << lpc_cmos_regb_dse_extract(_regval)) << ("\t(Daylight savings enable)\n");
    ((_os << (" hourform =\t")) << lpc_cmos_regb_hourform_extract(_regval)) << ("\t(Hour format)\n");
    ((_os << (" dm =\t")) << lpc_cmos_regb_dm_extract(_regval)) << ("\t(Data mode (BCD/binary))\n");
    ((_os << (" sqwe =\t")) << lpc_cmos_regb_sqwe_extract(_regval)) << ("\t(Square wave enable)\n");
    ((_os << (" uie =\t")) << lpc_cmos_regb_uie_extract(_regval)) << ("\t(Update-ended interrupt enable)\n");
    ((_os << (" aie =\t")) << lpc_cmos_regb_aie_extract(_regval)) << ("\t(Alarm interrupt enable)\n");
    ((_os << (" pie =\t")) << lpc_cmos_regb_pie_extract(_regval)) << ("\t(Periodic interrupt enable)\n");
    ((_os << (" set =\t")) << lpc_cmos_regb_set_extract(_regval)) << ("\t(Update cycle inhibit)\n");
    return(_os);
}

/*
 * Register type: lpc_cmos_regc_t
 * Description: Implicit type of Flag register C register
 * Fields:
 *   _anon0	(size 4, offset 0, init 0):	RSVD	_
 *   uf	(size 1, offset 4, init 0):	RO	Update-ended
 *   af	(size 1, offset 5, init 0):	RO	Alarm
 *   pf	(size 1, offset 6, init 0):	RO	Periodic interrupt
 *   irqf	(size 1, offset 7, init 0):	RO	Interrupt request flag
 */
HOH_STRONG_TYPEDEF( uint8_t , lpc_cmos_regc_t);
#define lpc_cmos_regc_default (lpc_cmos_regc_t )(0x0)
static inline uint8_t lpc_cmos_regc_uf_extract(lpc_cmos_regc_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_regc_uf_extract(lpc_cmos_regc_t _regval)
{
    return((uint8_t )((_regval & 0x10) >> 4));
}

static inline lpc_cmos_regc_t lpc_cmos_regc_uf_insert(lpc_cmos_regc_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_cmos_regc_t lpc_cmos_regc_uf_insert(lpc_cmos_regc_t _regval, uint8_t _fieldval)
{
    return((lpc_cmos_regc_t )((_regval & 0xef) | (0x10 & (((lpc_cmos_regc_t )(_fieldval)) << 4))));
}

static inline uint8_t lpc_cmos_regc_af_extract(lpc_cmos_regc_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_regc_af_extract(lpc_cmos_regc_t _regval)
{
    return((uint8_t )((_regval & 0x20) >> 5));
}

static inline lpc_cmos_regc_t lpc_cmos_regc_af_insert(lpc_cmos_regc_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_cmos_regc_t lpc_cmos_regc_af_insert(lpc_cmos_regc_t _regval, uint8_t _fieldval)
{
    return((lpc_cmos_regc_t )((_regval & 0xdf) | (0x20 & (((lpc_cmos_regc_t )(_fieldval)) << 5))));
}

static inline uint8_t lpc_cmos_regc_pf_extract(lpc_cmos_regc_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_regc_pf_extract(lpc_cmos_regc_t _regval)
{
    return((uint8_t )((_regval & 0x40) >> 6));
}

static inline lpc_cmos_regc_t lpc_cmos_regc_pf_insert(lpc_cmos_regc_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_cmos_regc_t lpc_cmos_regc_pf_insert(lpc_cmos_regc_t _regval, uint8_t _fieldval)
{
    return((lpc_cmos_regc_t )((_regval & 0xbf) | (0x40 & (((lpc_cmos_regc_t )(_fieldval)) << 6))));
}

static inline uint8_t lpc_cmos_regc_irqf_extract(lpc_cmos_regc_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_regc_irqf_extract(lpc_cmos_regc_t _regval)
{
    return((uint8_t )((_regval & 0x80) >> 7));
}

static inline lpc_cmos_regc_t lpc_cmos_regc_irqf_insert(lpc_cmos_regc_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_cmos_regc_t lpc_cmos_regc_irqf_insert(lpc_cmos_regc_t _regval, uint8_t _fieldval)
{
    return((lpc_cmos_regc_t )((_regval & 0x7f) | (0x80 & (((lpc_cmos_regc_t )(_fieldval)) << 7))));
}

static inline dout_t& operator<<(dout_t& _os, lpc_cmos_regc_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, lpc_cmos_regc_t _regval)
{
    ((_os << (" uf =\t")) << lpc_cmos_regc_uf_extract(_regval)) << ("\t(Update-ended)\n");
    ((_os << (" af =\t")) << lpc_cmos_regc_af_extract(_regval)) << ("\t(Alarm)\n");
    ((_os << (" pf =\t")) << lpc_cmos_regc_pf_extract(_regval)) << ("\t(Periodic interrupt)\n");
    ((_os << (" irqf =\t")) << lpc_cmos_regc_irqf_extract(_regval)) << ("\t(Interrupt request flag)\n");
    return(_os);
}

/*
 * Register type: lpc_cmos_regd_t
 * Description: Implicit type of Flag register D register
 * Fields:
 *   al_date	(size 6, offset 0, init 0):	RW	Date alarm
 *   _anon6	(size 1, offset 6, init 0):	RSVD	_
 *   vrt	(size 1, offset 7, init 0):	MBZ	Valid RAM and time
 */
HOH_STRONG_TYPEDEF( uint8_t , lpc_cmos_regd_t);
#define lpc_cmos_regd_default (lpc_cmos_regd_t )(0x0)
static inline uint8_t lpc_cmos_regd_al_date_extract(lpc_cmos_regd_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_regd_al_date_extract(lpc_cmos_regd_t _regval)
{
    return((uint8_t )((_regval & 0x3f) >> 0));
}

static inline lpc_cmos_regd_t lpc_cmos_regd_al_date_insert(lpc_cmos_regd_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_cmos_regd_t lpc_cmos_regd_al_date_insert(lpc_cmos_regd_t _regval, uint8_t _fieldval)
{
    return((lpc_cmos_regd_t )((_regval & 0xc0) | (0x3f & (((lpc_cmos_regd_t )(_fieldval)) << 0))));
}

static inline uint8_t lpc_cmos_regd_vrt_extract(lpc_cmos_regd_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_regd_vrt_extract(lpc_cmos_regd_t _regval)
{
    return((uint8_t )((_regval & 0x80) >> 7));
}

static inline lpc_cmos_regd_t lpc_cmos_regd_vrt_insert(lpc_cmos_regd_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_cmos_regd_t lpc_cmos_regd_vrt_insert(lpc_cmos_regd_t _regval, uint8_t _fieldval)
{
    return((lpc_cmos_regd_t )((_regval & 0x7f) | (0x80 & (((lpc_cmos_regd_t )(_fieldval)) << 7))));
}

static inline dout_t& operator<<(dout_t& _os, lpc_cmos_regd_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, lpc_cmos_regd_t _regval)
{
    ((_os << (" al_date =\t")) << lpc_cmos_regd_al_date_extract(_regval)) << ("\t(Date alarm)\n");
    ((_os << (" vrt =\t")) << lpc_cmos_regd_vrt_extract(_regval)) << ("\t(Valid RAM and time)\n");
    return(_os);
}

/*
 * Device representation structure
 */
struct __DN(t) {
    io_t base;
};

/*
 * Initial register values (currently 0)
 */
enum lpc_cmos_initials {
    lpc_cmos_ndx_initial = 0x0,
    lpc_cmos_target_initial = 0x0,
    lpc_cmos_standard_initial = 0x0,
    lpc_cmos_endx_initial = 0x0,
    lpc_cmos_etarget_initial = 0x0,
    lpc_cmos_extended_initial = 0x0,
    lpc_cmos_seconds_initial = 0x0,
    lpc_cmos_al_seconds_initial = 0x0,
    lpc_cmos_minutes_initial = 0x0,
    lpc_cmos_al_minutes_initial = 0x0,
    lpc_cmos_hours_initial = 0x0,
    lpc_cmos_al_hours_initial = 0x0,
    lpc_cmos_weekday_initial = 0x0,
    lpc_cmos_date_initial = 0x0,
    lpc_cmos_month_initial = 0x0,
    lpc_cmos_year_initial = 0x0,
    lpc_cmos_rega_initial = 0x0,
    lpc_cmos_regb_initial = 0x0,
    lpc_cmos_regc_initial = 0x0,
    lpc_cmos_regd_initial = 0x0
};

/*
 * Device Initialization function
 */
static inline void lpc_cmos_initialize(__DN(t) *_dev, io_t base) __attribute__ ((always_inline));
static inline void lpc_cmos_initialize(__DN(t) *_dev, io_t base)
{
    _dev->base = base;
}

/*
 * Include access functions for user-defined spaces
 */
#include "generated/lpc_cmos.spaces.h"
/*
 * Register ndx: Standard index
 * Type: lpc_cmos.uint8 (primitive type)
 */
static inline uint8_t lpc_cmos_ndx_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_ndx_rawrd(__DN(t) *_dev)
{
    return((uint8_t )(io::read8(_dev->base, 0x70)));
}

static inline uint8_t lpc_cmos_ndx_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_ndx_rd(__DN(t) *_dev)
{
    return((uint8_t )(io::read8(_dev->base, 0x70)));
}

static inline void lpc_cmos_ndx_rawwr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_cmos_ndx_rawwr(__DN(t) *_dev, uint8_t _regval)
{
    io::write8(_dev->base, 0x70, _regval);
}

static inline void lpc_cmos_ndx_wr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_cmos_ndx_wr(__DN(t) *_dev, uint8_t _regval)
{
    // No MB0 or RSVD fields present
    // No MB1 fields present
    // No pre-read of register required
    io::write8(_dev->base, 0x70, _regval);
}

static inline dout_t& lpc_cmos_ndx_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_cmos_ndx_pr(dout_t& _os, __DN(t) *_dev)
{
    uint8_t _regval = (uint8_t )(io::read8(_dev->base, 0x70));
    _os << ("Register ndx (Standard index): ");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

/*
 * Register target: Standard target
 * Type: lpc_cmos.uint8 (primitive type)
 */
static inline uint8_t lpc_cmos_target_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_target_rawrd(__DN(t) *_dev)
{
    return((uint8_t )(io::read8(_dev->base, 0x71)));
}

static inline uint8_t lpc_cmos_target_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_target_rd(__DN(t) *_dev)
{
    return((uint8_t )(io::read8(_dev->base, 0x71)));
}

static inline void lpc_cmos_target_rawwr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_cmos_target_rawwr(__DN(t) *_dev, uint8_t _regval)
{
    io::write8(_dev->base, 0x71, _regval);
}

static inline void lpc_cmos_target_wr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_cmos_target_wr(__DN(t) *_dev, uint8_t _regval)
{
    // No MB0 or RSVD fields present
    // No MB1 fields present
    // No pre-read of register required
    io::write8(_dev->base, 0x71, _regval);
}

static inline dout_t& lpc_cmos_target_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_cmos_target_pr(dout_t& _os, __DN(t) *_dev)
{
    uint8_t _regval = (uint8_t )(io::read8(_dev->base, 0x71));
    _os << ("Register target (Standard target): ");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

/*
 * Register array standard: standard
 * Type: lpc_cmos.uint8 (primitive type)
 */
static const size_t lpc_cmos_standard_length = 256;
static inline uint8_t lpc_cmos_standard_rawrd(__DN(t) *_dev, int _i) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_standard_rawrd(__DN(t) *_dev, int _i)
{
    return((uint8_t )(__DN(std)::read8(_dev, 0x0 + _i)));
}

static inline uint8_t lpc_cmos_standard_rd(__DN(t) *_dev, int _i) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_standard_rd(__DN(t) *_dev, int _i)
{
    return((uint8_t )(__DN(std)::read8(_dev, 0x0 + _i)));
}

static inline void lpc_cmos_standard_rawwr(__DN(t) *_dev, int _i, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_cmos_standard_rawwr(__DN(t) *_dev, int _i, uint8_t _regval)
{
    __DN(std)::write8(_dev, 0x0 + _i, _regval);
}

static inline void lpc_cmos_standard_wr(__DN(t) *_dev, int _i, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_cmos_standard_wr(__DN(t) *_dev, int _i, uint8_t _regval)
{
    // No MB0 or RSVD fields present
    // No MB1 fields present
    // No pre-read of register required
    __DN(std)::write8(_dev, 0x0 + _i, _regval);
}

static inline dout_t& lpc_cmos_standard_pri(dout_t& _os, __DN(t) *_dev, int _i) __attribute__ ((always_inline));
static inline dout_t& lpc_cmos_standard_pri(dout_t& _os, __DN(t) *_dev, int _i)
{
    uint8_t _regval = (uint8_t )(__DN(std)::read8(_dev, 0x0 + _i));
    ((((_os << ("Register ")) << ("standard")) << _i) << ("standard")) << (":");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

static inline dout_t& lpc_cmos_standard_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_cmos_standard_pr(dout_t& _os, __DN(t) *_dev)
{
    int _i;
    for( _i = 0; _i < 256; _i++) {
        lpc_cmos_standard_pri(_os, _dev, _i);
    }
    return(_os);
}

/*
 * Register endx: Extended index
 * Type: lpc_cmos.uint8 (primitive type)
 */
static inline uint8_t lpc_cmos_endx_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_endx_rawrd(__DN(t) *_dev)
{
    return((uint8_t )(io::read8(_dev->base, 0x72)));
}

static inline uint8_t lpc_cmos_endx_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_endx_rd(__DN(t) *_dev)
{
    return((uint8_t )(io::read8(_dev->base, 0x72)));
}

static inline void lpc_cmos_endx_rawwr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_cmos_endx_rawwr(__DN(t) *_dev, uint8_t _regval)
{
    io::write8(_dev->base, 0x72, _regval);
}

static inline void lpc_cmos_endx_wr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_cmos_endx_wr(__DN(t) *_dev, uint8_t _regval)
{
    // No MB0 or RSVD fields present
    // No MB1 fields present
    // No pre-read of register required
    io::write8(_dev->base, 0x72, _regval);
}

static inline dout_t& lpc_cmos_endx_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_cmos_endx_pr(dout_t& _os, __DN(t) *_dev)
{
    uint8_t _regval = (uint8_t )(io::read8(_dev->base, 0x72));
    _os << ("Register endx (Extended index): ");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

/*
 * Register etarget: Extended target
 * Type: lpc_cmos.uint8 (primitive type)
 */
static inline uint8_t lpc_cmos_etarget_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_etarget_rawrd(__DN(t) *_dev)
{
    return((uint8_t )(io::read8(_dev->base, 0x73)));
}

static inline uint8_t lpc_cmos_etarget_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_etarget_rd(__DN(t) *_dev)
{
    return((uint8_t )(io::read8(_dev->base, 0x73)));
}

static inline void lpc_cmos_etarget_rawwr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_cmos_etarget_rawwr(__DN(t) *_dev, uint8_t _regval)
{
    io::write8(_dev->base, 0x73, _regval);
}

static inline void lpc_cmos_etarget_wr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_cmos_etarget_wr(__DN(t) *_dev, uint8_t _regval)
{
    // No MB0 or RSVD fields present
    // No MB1 fields present
    // No pre-read of register required
    io::write8(_dev->base, 0x73, _regval);
}

static inline dout_t& lpc_cmos_etarget_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_cmos_etarget_pr(dout_t& _os, __DN(t) *_dev)
{
    uint8_t _regval = (uint8_t )(io::read8(_dev->base, 0x73));
    _os << ("Register etarget (Extended target): ");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

/*
 * Register array extended: extended
 * Type: lpc_cmos.uint8 (primitive type)
 */
static const size_t lpc_cmos_extended_length = 256;
static inline uint8_t lpc_cmos_extended_rawrd(__DN(t) *_dev, int _i) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_extended_rawrd(__DN(t) *_dev, int _i)
{
    return((uint8_t )(__DN(ext)::read8(_dev, 0x0 + _i)));
}

static inline uint8_t lpc_cmos_extended_rd(__DN(t) *_dev, int _i) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_extended_rd(__DN(t) *_dev, int _i)
{
    return((uint8_t )(__DN(ext)::read8(_dev, 0x0 + _i)));
}

static inline void lpc_cmos_extended_rawwr(__DN(t) *_dev, int _i, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_cmos_extended_rawwr(__DN(t) *_dev, int _i, uint8_t _regval)
{
    __DN(ext)::write8(_dev, 0x0 + _i, _regval);
}

static inline void lpc_cmos_extended_wr(__DN(t) *_dev, int _i, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_cmos_extended_wr(__DN(t) *_dev, int _i, uint8_t _regval)
{
    // No MB0 or RSVD fields present
    // No MB1 fields present
    // No pre-read of register required
    __DN(ext)::write8(_dev, 0x0 + _i, _regval);
}

static inline dout_t& lpc_cmos_extended_pri(dout_t& _os, __DN(t) *_dev, int _i) __attribute__ ((always_inline));
static inline dout_t& lpc_cmos_extended_pri(dout_t& _os, __DN(t) *_dev, int _i)
{
    uint8_t _regval = (uint8_t )(__DN(ext)::read8(_dev, 0x0 + _i));
    ((((_os << ("Register ")) << ("extended")) << _i) << ("extended")) << (":");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

static inline dout_t& lpc_cmos_extended_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_cmos_extended_pr(dout_t& _os, __DN(t) *_dev)
{
    int _i;
    for( _i = 0; _i < 256; _i++) {
        lpc_cmos_extended_pri(_os, _dev, _i);
    }
    return(_os);
}

/*
 * Register seconds: Seconds
 * Type: lpc_cmos.uint8 (primitive type)
 */
static inline uint8_t lpc_cmos_seconds_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_seconds_rawrd(__DN(t) *_dev)
{
    return((uint8_t )(__DN(std)::read8(_dev, 0x0)));
}

static inline uint8_t lpc_cmos_seconds_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_seconds_rd(__DN(t) *_dev)
{
    return((uint8_t )(__DN(std)::read8(_dev, 0x0)));
}

static inline void lpc_cmos_seconds_rawwr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_cmos_seconds_rawwr(__DN(t) *_dev, uint8_t _regval)
{
    __DN(std)::write8(_dev, 0x0, _regval);
}

static inline void lpc_cmos_seconds_wr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_cmos_seconds_wr(__DN(t) *_dev, uint8_t _regval)
{
    // No MB0 or RSVD fields present
    // No MB1 fields present
    // No pre-read of register required
    __DN(std)::write8(_dev, 0x0, _regval);
}

static inline dout_t& lpc_cmos_seconds_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_cmos_seconds_pr(dout_t& _os, __DN(t) *_dev)
{
    uint8_t _regval = (uint8_t )(__DN(std)::read8(_dev, 0x0));
    _os << ("Register seconds (Seconds): ");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

/*
 * Register al_seconds: Seconds alarm
 * Type: lpc_cmos.uint8 (primitive type)
 */
static inline uint8_t lpc_cmos_al_seconds_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_al_seconds_rawrd(__DN(t) *_dev)
{
    return((uint8_t )(__DN(std)::read8(_dev, 0x1)));
}

static inline uint8_t lpc_cmos_al_seconds_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_al_seconds_rd(__DN(t) *_dev)
{
    return((uint8_t )(__DN(std)::read8(_dev, 0x1)));
}

static inline void lpc_cmos_al_seconds_rawwr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_cmos_al_seconds_rawwr(__DN(t) *_dev, uint8_t _regval)
{
    __DN(std)::write8(_dev, 0x1, _regval);
}

static inline void lpc_cmos_al_seconds_wr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_cmos_al_seconds_wr(__DN(t) *_dev, uint8_t _regval)
{
    // No MB0 or RSVD fields present
    // No MB1 fields present
    // No pre-read of register required
    __DN(std)::write8(_dev, 0x1, _regval);
}

static inline dout_t& lpc_cmos_al_seconds_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_cmos_al_seconds_pr(dout_t& _os, __DN(t) *_dev)
{
    uint8_t _regval = (uint8_t )(__DN(std)::read8(_dev, 0x1));
    _os << ("Register al_seconds (Seconds alarm): ");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

/*
 * Register minutes: Minutes
 * Type: lpc_cmos.uint8 (primitive type)
 */
static inline uint8_t lpc_cmos_minutes_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_minutes_rawrd(__DN(t) *_dev)
{
    return((uint8_t )(__DN(std)::read8(_dev, 0x2)));
}

static inline uint8_t lpc_cmos_minutes_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_minutes_rd(__DN(t) *_dev)
{
    return((uint8_t )(__DN(std)::read8(_dev, 0x2)));
}

static inline void lpc_cmos_minutes_rawwr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_cmos_minutes_rawwr(__DN(t) *_dev, uint8_t _regval)
{
    __DN(std)::write8(_dev, 0x2, _regval);
}

static inline void lpc_cmos_minutes_wr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_cmos_minutes_wr(__DN(t) *_dev, uint8_t _regval)
{
    // No MB0 or RSVD fields present
    // No MB1 fields present
    // No pre-read of register required
    __DN(std)::write8(_dev, 0x2, _regval);
}

static inline dout_t& lpc_cmos_minutes_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_cmos_minutes_pr(dout_t& _os, __DN(t) *_dev)
{
    uint8_t _regval = (uint8_t )(__DN(std)::read8(_dev, 0x2));
    _os << ("Register minutes (Minutes): ");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

/*
 * Register al_minutes: Minutes Alarm
 * Type: lpc_cmos.uint8 (primitive type)
 */
static inline uint8_t lpc_cmos_al_minutes_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_al_minutes_rawrd(__DN(t) *_dev)
{
    return((uint8_t )(__DN(std)::read8(_dev, 0x3)));
}

static inline uint8_t lpc_cmos_al_minutes_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_al_minutes_rd(__DN(t) *_dev)
{
    return((uint8_t )(__DN(std)::read8(_dev, 0x3)));
}

static inline void lpc_cmos_al_minutes_rawwr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_cmos_al_minutes_rawwr(__DN(t) *_dev, uint8_t _regval)
{
    __DN(std)::write8(_dev, 0x3, _regval);
}

static inline void lpc_cmos_al_minutes_wr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_cmos_al_minutes_wr(__DN(t) *_dev, uint8_t _regval)
{
    // No MB0 or RSVD fields present
    // No MB1 fields present
    // No pre-read of register required
    __DN(std)::write8(_dev, 0x3, _regval);
}

static inline dout_t& lpc_cmos_al_minutes_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_cmos_al_minutes_pr(dout_t& _os, __DN(t) *_dev)
{
    uint8_t _regval = (uint8_t )(__DN(std)::read8(_dev, 0x3));
    _os << ("Register al_minutes (Minutes Alarm): ");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

/*
 * Register hours: Hours
 * Type: lpc_cmos.uint8 (primitive type)
 */
static inline uint8_t lpc_cmos_hours_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_hours_rawrd(__DN(t) *_dev)
{
    return((uint8_t )(__DN(std)::read8(_dev, 0x4)));
}

static inline uint8_t lpc_cmos_hours_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_hours_rd(__DN(t) *_dev)
{
    return((uint8_t )(__DN(std)::read8(_dev, 0x4)));
}

static inline void lpc_cmos_hours_rawwr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_cmos_hours_rawwr(__DN(t) *_dev, uint8_t _regval)
{
    __DN(std)::write8(_dev, 0x4, _regval);
}

static inline void lpc_cmos_hours_wr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_cmos_hours_wr(__DN(t) *_dev, uint8_t _regval)
{
    // No MB0 or RSVD fields present
    // No MB1 fields present
    // No pre-read of register required
    __DN(std)::write8(_dev, 0x4, _regval);
}

static inline dout_t& lpc_cmos_hours_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_cmos_hours_pr(dout_t& _os, __DN(t) *_dev)
{
    uint8_t _regval = (uint8_t )(__DN(std)::read8(_dev, 0x4));
    _os << ("Register hours (Hours): ");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

/*
 * Register al_hours: Hours Alarm
 * Type: lpc_cmos.uint8 (primitive type)
 */
static inline uint8_t lpc_cmos_al_hours_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_al_hours_rawrd(__DN(t) *_dev)
{
    return((uint8_t )(__DN(std)::read8(_dev, 0x5)));
}

static inline uint8_t lpc_cmos_al_hours_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_al_hours_rd(__DN(t) *_dev)
{
    return((uint8_t )(__DN(std)::read8(_dev, 0x5)));
}

static inline void lpc_cmos_al_hours_rawwr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_cmos_al_hours_rawwr(__DN(t) *_dev, uint8_t _regval)
{
    __DN(std)::write8(_dev, 0x5, _regval);
}

static inline void lpc_cmos_al_hours_wr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_cmos_al_hours_wr(__DN(t) *_dev, uint8_t _regval)
{
    // No MB0 or RSVD fields present
    // No MB1 fields present
    // No pre-read of register required
    __DN(std)::write8(_dev, 0x5, _regval);
}

static inline dout_t& lpc_cmos_al_hours_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_cmos_al_hours_pr(dout_t& _os, __DN(t) *_dev)
{
    uint8_t _regval = (uint8_t )(__DN(std)::read8(_dev, 0x5));
    _os << ("Register al_hours (Hours Alarm): ");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

/*
 * Register weekday: Day of Week
 * Type: lpc_cmos.uint8 (primitive type)
 */
static inline uint8_t lpc_cmos_weekday_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_weekday_rawrd(__DN(t) *_dev)
{
    return((uint8_t )(__DN(std)::read8(_dev, 0x6)));
}

static inline uint8_t lpc_cmos_weekday_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_weekday_rd(__DN(t) *_dev)
{
    return((uint8_t )(__DN(std)::read8(_dev, 0x6)));
}

static inline void lpc_cmos_weekday_rawwr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_cmos_weekday_rawwr(__DN(t) *_dev, uint8_t _regval)
{
    __DN(std)::write8(_dev, 0x6, _regval);
}

static inline void lpc_cmos_weekday_wr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_cmos_weekday_wr(__DN(t) *_dev, uint8_t _regval)
{
    // No MB0 or RSVD fields present
    // No MB1 fields present
    // No pre-read of register required
    __DN(std)::write8(_dev, 0x6, _regval);
}

static inline dout_t& lpc_cmos_weekday_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_cmos_weekday_pr(dout_t& _os, __DN(t) *_dev)
{
    uint8_t _regval = (uint8_t )(__DN(std)::read8(_dev, 0x6));
    _os << ("Register weekday (Day of Week): ");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

/*
 * Register date: Day of Month
 * Type: lpc_cmos.uint8 (primitive type)
 */
static inline uint8_t lpc_cmos_date_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_date_rawrd(__DN(t) *_dev)
{
    return((uint8_t )(__DN(std)::read8(_dev, 0x7)));
}

static inline uint8_t lpc_cmos_date_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_date_rd(__DN(t) *_dev)
{
    return((uint8_t )(__DN(std)::read8(_dev, 0x7)));
}

static inline void lpc_cmos_date_rawwr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_cmos_date_rawwr(__DN(t) *_dev, uint8_t _regval)
{
    __DN(std)::write8(_dev, 0x7, _regval);
}

static inline void lpc_cmos_date_wr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_cmos_date_wr(__DN(t) *_dev, uint8_t _regval)
{
    // No MB0 or RSVD fields present
    // No MB1 fields present
    // No pre-read of register required
    __DN(std)::write8(_dev, 0x7, _regval);
}

static inline dout_t& lpc_cmos_date_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_cmos_date_pr(dout_t& _os, __DN(t) *_dev)
{
    uint8_t _regval = (uint8_t )(__DN(std)::read8(_dev, 0x7));
    _os << ("Register date (Day of Month): ");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

/*
 * Register month: Month
 * Type: lpc_cmos.uint8 (primitive type)
 */
static inline uint8_t lpc_cmos_month_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_month_rawrd(__DN(t) *_dev)
{
    return((uint8_t )(__DN(std)::read8(_dev, 0x8)));
}

static inline uint8_t lpc_cmos_month_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_month_rd(__DN(t) *_dev)
{
    return((uint8_t )(__DN(std)::read8(_dev, 0x8)));
}

static inline void lpc_cmos_month_rawwr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_cmos_month_rawwr(__DN(t) *_dev, uint8_t _regval)
{
    __DN(std)::write8(_dev, 0x8, _regval);
}

static inline void lpc_cmos_month_wr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_cmos_month_wr(__DN(t) *_dev, uint8_t _regval)
{
    // No MB0 or RSVD fields present
    // No MB1 fields present
    // No pre-read of register required
    __DN(std)::write8(_dev, 0x8, _regval);
}

static inline dout_t& lpc_cmos_month_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_cmos_month_pr(dout_t& _os, __DN(t) *_dev)
{
    uint8_t _regval = (uint8_t )(__DN(std)::read8(_dev, 0x8));
    _os << ("Register month (Month): ");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

/*
 * Register year: Year
 * Type: lpc_cmos.uint8 (primitive type)
 */
static inline uint8_t lpc_cmos_year_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_year_rawrd(__DN(t) *_dev)
{
    return((uint8_t )(__DN(std)::read8(_dev, 0x9)));
}

static inline uint8_t lpc_cmos_year_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_year_rd(__DN(t) *_dev)
{
    return((uint8_t )(__DN(std)::read8(_dev, 0x9)));
}

static inline void lpc_cmos_year_rawwr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_cmos_year_rawwr(__DN(t) *_dev, uint8_t _regval)
{
    __DN(std)::write8(_dev, 0x9, _regval);
}

static inline void lpc_cmos_year_wr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_cmos_year_wr(__DN(t) *_dev, uint8_t _regval)
{
    // No MB0 or RSVD fields present
    // No MB1 fields present
    // No pre-read of register required
    __DN(std)::write8(_dev, 0x9, _regval);
}

static inline dout_t& lpc_cmos_year_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_cmos_year_pr(dout_t& _os, __DN(t) *_dev)
{
    uint8_t _regval = (uint8_t )(__DN(std)::read8(_dev, 0x9));
    _os << ("Register year (Year): ");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

/*
 * Register rega: Register A
 * Type: lpc_cmos.rega (Implicit type of Register A register)
 *   rs	(size 4, offset 0, init 0):	RW	Rate select
 *   dv	(size 3, offset 4, init 0):	RW	Divisioin chain select
 *   uip	(size 1, offset 7, init 0):	RW	Update in progress
 */
static inline lpc_cmos_rega_t lpc_cmos_rega_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_cmos_rega_t lpc_cmos_rega_rawrd(__DN(t) *_dev)
{
    return((lpc_cmos_rega_t )(__DN(std)::read8(_dev, 0xa)));
}

static inline lpc_cmos_rega_t lpc_cmos_rega_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_cmos_rega_t lpc_cmos_rega_rd(__DN(t) *_dev)
{
    return((lpc_cmos_rega_t )(__DN(std)::read8(_dev, 0xa)));
}

static inline void lpc_cmos_rega_rawwr(__DN(t) *_dev, lpc_cmos_rega_t _regval) __attribute__ ((always_inline));
static inline void lpc_cmos_rega_rawwr(__DN(t) *_dev, lpc_cmos_rega_t _regval)
{
    __DN(std)::write8(_dev, 0xa, _regval);
}

static inline void lpc_cmos_rega_wr(__DN(t) *_dev, lpc_cmos_rega_t _regval) __attribute__ ((always_inline));
static inline void lpc_cmos_rega_wr(__DN(t) *_dev, lpc_cmos_rega_t _regval)
{
    // No MB0 or RSVD fields present
    // No MB1 fields present
    // No pre-read of register required
    __DN(std)::write8(_dev, 0xa, _regval);
}

static inline dout_t& lpc_cmos_rega_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_cmos_rega_pr(dout_t& _os, __DN(t) *_dev)
{
    lpc_cmos_rega_t _regval = (lpc_cmos_rega_t )(__DN(std)::read8(_dev, 0xa));
    _os << ("Register rega (Register A): ");
    _os << ("\n");
    ((_os << (" rs =\t")) << lpc_cmos_rega_rs_extract(_regval)) << ("\t(Rate select)\n");
    ((_os << (" dv =\t")) << lpc_cmos_rega_dv_extract(_regval)) << ("\t(Divisioin chain select)\n");
    ((_os << (" uip =\t")) << lpc_cmos_rega_uip_extract(_regval)) << ("\t(Update in progress)\n");
    return(_os);
}

static inline lpc_cmos_rate_t lpc_cmos_rega_rs_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_cmos_rate_t lpc_cmos_rega_rs_rdf(__DN(t) *_dev)
{
    lpc_cmos_rega_t _regval = (lpc_cmos_rega_t )(__DN(std)::read8(_dev, 0xa));
    return(lpc_cmos_rega_rs_extract(_regval));
}

static inline lpc_cmos_dcs_t lpc_cmos_rega_dv_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_cmos_dcs_t lpc_cmos_rega_dv_rdf(__DN(t) *_dev)
{
    lpc_cmos_rega_t _regval = (lpc_cmos_rega_t )(__DN(std)::read8(_dev, 0xa));
    return(lpc_cmos_rega_dv_extract(_regval));
}

static inline uint8_t lpc_cmos_rega_uip_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_rega_uip_rdf(__DN(t) *_dev)
{
    lpc_cmos_rega_t _regval = (lpc_cmos_rega_t )(__DN(std)::read8(_dev, 0xa));
    return(lpc_cmos_rega_uip_extract(_regval));
}

static inline void lpc_cmos_rega_rs_wrf(__DN(t) *_dev, lpc_cmos_rate_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_cmos_rega_rs_wrf(__DN(t) *_dev, lpc_cmos_rate_t _fieldval)
{
    lpc_cmos_rega_t _regval = (lpc_cmos_rega_t )(0xf & (((lpc_cmos_rega_t )(_fieldval)) << 0));
    _regval = (_regval | (0xf0 & ((lpc_cmos_rega_t )(__DN(std)::read8(_dev, 0xa)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    __DN(std)::write8(_dev, 0xa, _regval);
    // No shadow register to write to
}

static inline void lpc_cmos_rega_dv_wrf(__DN(t) *_dev, lpc_cmos_dcs_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_cmos_rega_dv_wrf(__DN(t) *_dev, lpc_cmos_dcs_t _fieldval)
{
    lpc_cmos_rega_t _regval = (lpc_cmos_rega_t )(0x70 & (((lpc_cmos_rega_t )(_fieldval)) << 4));
    _regval = (_regval | (0x8f & ((lpc_cmos_rega_t )(__DN(std)::read8(_dev, 0xa)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    __DN(std)::write8(_dev, 0xa, _regval);
    // No shadow register to write to
}

static inline void lpc_cmos_rega_uip_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_cmos_rega_uip_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_cmos_rega_t _regval = (lpc_cmos_rega_t )(0x80 & (((lpc_cmos_rega_t )(_fieldval)) << 7));
    _regval = (_regval | (0x7f & ((lpc_cmos_rega_t )(__DN(std)::read8(_dev, 0xa)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    __DN(std)::write8(_dev, 0xa, _regval);
    // No shadow register to write to
}

/*
 * Register regb: General configuration
 * Type: lpc_cmos.regb (Implicit type of General configuration register)
 *   dse	(size 1, offset 0, init 0):	RW	Daylight savings enable
 *   hourform	(size 1, offset 1, init 0):	RW	Hour format
 *   dm	(size 1, offset 2, init 0):	RW	Data mode (BCD/binary)
 *   sqwe	(size 1, offset 3, init 0):	RW	Square wave enable
 *   uie	(size 1, offset 4, init 0):	RW	Update-ended interrupt enable
 *   aie	(size 1, offset 5, init 0):	RW	Alarm interrupt enable
 *   pie	(size 1, offset 6, init 0):	RW	Periodic interrupt enable
 *   set	(size 1, offset 7, init 0):	RW	Update cycle inhibit
 */
static inline lpc_cmos_regb_t lpc_cmos_regb_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_cmos_regb_t lpc_cmos_regb_rawrd(__DN(t) *_dev)
{
    return((lpc_cmos_regb_t )(__DN(std)::read8(_dev, 0xb)));
}

static inline lpc_cmos_regb_t lpc_cmos_regb_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_cmos_regb_t lpc_cmos_regb_rd(__DN(t) *_dev)
{
    return((lpc_cmos_regb_t )(__DN(std)::read8(_dev, 0xb)));
}

static inline void lpc_cmos_regb_rawwr(__DN(t) *_dev, lpc_cmos_regb_t _regval) __attribute__ ((always_inline));
static inline void lpc_cmos_regb_rawwr(__DN(t) *_dev, lpc_cmos_regb_t _regval)
{
    __DN(std)::write8(_dev, 0xb, _regval);
}

static inline void lpc_cmos_regb_wr(__DN(t) *_dev, lpc_cmos_regb_t _regval) __attribute__ ((always_inline));
static inline void lpc_cmos_regb_wr(__DN(t) *_dev, lpc_cmos_regb_t _regval)
{
    // No MB0 or RSVD fields present
    // No MB1 fields present
    // No pre-read of register required
    __DN(std)::write8(_dev, 0xb, _regval);
}

static inline dout_t& lpc_cmos_regb_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_cmos_regb_pr(dout_t& _os, __DN(t) *_dev)
{
    lpc_cmos_regb_t _regval = (lpc_cmos_regb_t )(__DN(std)::read8(_dev, 0xb));
    _os << ("Register regb (General configuration): ");
    _os << ("\n");
    ((_os << (" dse =\t")) << lpc_cmos_regb_dse_extract(_regval)) << ("\t(Daylight savings enable)\n");
    ((_os << (" hourform =\t")) << lpc_cmos_regb_hourform_extract(_regval)) << ("\t(Hour format)\n");
    ((_os << (" dm =\t")) << lpc_cmos_regb_dm_extract(_regval)) << ("\t(Data mode (BCD/binary))\n");
    ((_os << (" sqwe =\t")) << lpc_cmos_regb_sqwe_extract(_regval)) << ("\t(Square wave enable)\n");
    ((_os << (" uie =\t")) << lpc_cmos_regb_uie_extract(_regval)) << ("\t(Update-ended interrupt enable)\n");
    ((_os << (" aie =\t")) << lpc_cmos_regb_aie_extract(_regval)) << ("\t(Alarm interrupt enable)\n");
    ((_os << (" pie =\t")) << lpc_cmos_regb_pie_extract(_regval)) << ("\t(Periodic interrupt enable)\n");
    ((_os << (" set =\t")) << lpc_cmos_regb_set_extract(_regval)) << ("\t(Update cycle inhibit)\n");
    return(_os);
}

static inline uint8_t lpc_cmos_regb_dse_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_regb_dse_rdf(__DN(t) *_dev)
{
    lpc_cmos_regb_t _regval = (lpc_cmos_regb_t )(__DN(std)::read8(_dev, 0xb));
    return(lpc_cmos_regb_dse_extract(_regval));
}

static inline uint8_t lpc_cmos_regb_hourform_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_regb_hourform_rdf(__DN(t) *_dev)
{
    lpc_cmos_regb_t _regval = (lpc_cmos_regb_t )(__DN(std)::read8(_dev, 0xb));
    return(lpc_cmos_regb_hourform_extract(_regval));
}

static inline uint8_t lpc_cmos_regb_dm_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_regb_dm_rdf(__DN(t) *_dev)
{
    lpc_cmos_regb_t _regval = (lpc_cmos_regb_t )(__DN(std)::read8(_dev, 0xb));
    return(lpc_cmos_regb_dm_extract(_regval));
}

static inline uint8_t lpc_cmos_regb_sqwe_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_regb_sqwe_rdf(__DN(t) *_dev)
{
    lpc_cmos_regb_t _regval = (lpc_cmos_regb_t )(__DN(std)::read8(_dev, 0xb));
    return(lpc_cmos_regb_sqwe_extract(_regval));
}

static inline uint8_t lpc_cmos_regb_uie_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_regb_uie_rdf(__DN(t) *_dev)
{
    lpc_cmos_regb_t _regval = (lpc_cmos_regb_t )(__DN(std)::read8(_dev, 0xb));
    return(lpc_cmos_regb_uie_extract(_regval));
}

static inline uint8_t lpc_cmos_regb_aie_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_regb_aie_rdf(__DN(t) *_dev)
{
    lpc_cmos_regb_t _regval = (lpc_cmos_regb_t )(__DN(std)::read8(_dev, 0xb));
    return(lpc_cmos_regb_aie_extract(_regval));
}

static inline uint8_t lpc_cmos_regb_pie_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_regb_pie_rdf(__DN(t) *_dev)
{
    lpc_cmos_regb_t _regval = (lpc_cmos_regb_t )(__DN(std)::read8(_dev, 0xb));
    return(lpc_cmos_regb_pie_extract(_regval));
}

static inline uint8_t lpc_cmos_regb_set_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_regb_set_rdf(__DN(t) *_dev)
{
    lpc_cmos_regb_t _regval = (lpc_cmos_regb_t )(__DN(std)::read8(_dev, 0xb));
    return(lpc_cmos_regb_set_extract(_regval));
}

static inline void lpc_cmos_regb_dse_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_cmos_regb_dse_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_cmos_regb_t _regval = (lpc_cmos_regb_t )(0x1 & (((lpc_cmos_regb_t )(_fieldval)) << 0));
    _regval = (_regval | (0xfe & ((lpc_cmos_regb_t )(__DN(std)::read8(_dev, 0xb)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    __DN(std)::write8(_dev, 0xb, _regval);
    // No shadow register to write to
}

static inline void lpc_cmos_regb_hourform_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_cmos_regb_hourform_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_cmos_regb_t _regval = (lpc_cmos_regb_t )(0x2 & (((lpc_cmos_regb_t )(_fieldval)) << 1));
    _regval = (_regval | (0xfd & ((lpc_cmos_regb_t )(__DN(std)::read8(_dev, 0xb)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    __DN(std)::write8(_dev, 0xb, _regval);
    // No shadow register to write to
}

static inline void lpc_cmos_regb_dm_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_cmos_regb_dm_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_cmos_regb_t _regval = (lpc_cmos_regb_t )(0x4 & (((lpc_cmos_regb_t )(_fieldval)) << 2));
    _regval = (_regval | (0xfb & ((lpc_cmos_regb_t )(__DN(std)::read8(_dev, 0xb)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    __DN(std)::write8(_dev, 0xb, _regval);
    // No shadow register to write to
}

static inline void lpc_cmos_regb_sqwe_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_cmos_regb_sqwe_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_cmos_regb_t _regval = (lpc_cmos_regb_t )(0x8 & (((lpc_cmos_regb_t )(_fieldval)) << 3));
    _regval = (_regval | (0xf7 & ((lpc_cmos_regb_t )(__DN(std)::read8(_dev, 0xb)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    __DN(std)::write8(_dev, 0xb, _regval);
    // No shadow register to write to
}

static inline void lpc_cmos_regb_uie_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_cmos_regb_uie_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_cmos_regb_t _regval = (lpc_cmos_regb_t )(0x10 & (((lpc_cmos_regb_t )(_fieldval)) << 4));
    _regval = (_regval | (0xef & ((lpc_cmos_regb_t )(__DN(std)::read8(_dev, 0xb)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    __DN(std)::write8(_dev, 0xb, _regval);
    // No shadow register to write to
}

static inline void lpc_cmos_regb_aie_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_cmos_regb_aie_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_cmos_regb_t _regval = (lpc_cmos_regb_t )(0x20 & (((lpc_cmos_regb_t )(_fieldval)) << 5));
    _regval = (_regval | (0xdf & ((lpc_cmos_regb_t )(__DN(std)::read8(_dev, 0xb)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    __DN(std)::write8(_dev, 0xb, _regval);
    // No shadow register to write to
}

static inline void lpc_cmos_regb_pie_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_cmos_regb_pie_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_cmos_regb_t _regval = (lpc_cmos_regb_t )(0x40 & (((lpc_cmos_regb_t )(_fieldval)) << 6));
    _regval = (_regval | (0xbf & ((lpc_cmos_regb_t )(__DN(std)::read8(_dev, 0xb)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    __DN(std)::write8(_dev, 0xb, _regval);
    // No shadow register to write to
}

static inline void lpc_cmos_regb_set_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_cmos_regb_set_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_cmos_regb_t _regval = (lpc_cmos_regb_t )(0x80 & (((lpc_cmos_regb_t )(_fieldval)) << 7));
    _regval = (_regval | (0x7f & ((lpc_cmos_regb_t )(__DN(std)::read8(_dev, 0xb)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    __DN(std)::write8(_dev, 0xb, _regval);
    // No shadow register to write to
}

/*
 * Register regc: Flag register C
 * Type: lpc_cmos.regc (Implicit type of Flag register C register)
 *   _anon0	(size 4, offset 0, init 0):	RSVD	_
 *   uf	(size 1, offset 4, init 0):	RO	Update-ended
 *   af	(size 1, offset 5, init 0):	RO	Alarm
 *   pf	(size 1, offset 6, init 0):	RO	Periodic interrupt
 *   irqf	(size 1, offset 7, init 0):	RO	Interrupt request flag
 */
static inline lpc_cmos_regc_t lpc_cmos_regc_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_cmos_regc_t lpc_cmos_regc_rawrd(__DN(t) *_dev)
{
    return((lpc_cmos_regc_t )(__DN(std)::read8(_dev, 0xc)));
}

static inline lpc_cmos_regc_t lpc_cmos_regc_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_cmos_regc_t lpc_cmos_regc_rd(__DN(t) *_dev)
{
    return((lpc_cmos_regc_t )(__DN(std)::read8(_dev, 0xc)));
}

static inline void lpc_cmos_regc_rawwr(__DN(t) *_dev, lpc_cmos_regc_t _regval) __attribute__ ((always_inline));
static inline void lpc_cmos_regc_rawwr(__DN(t) *_dev, lpc_cmos_regc_t _regval)
{
    __DN(std)::write8(_dev, 0xc, _regval);
}

// Register regc is not writeable
static inline dout_t& lpc_cmos_regc_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_cmos_regc_pr(dout_t& _os, __DN(t) *_dev)
{
    lpc_cmos_regc_t _regval = (lpc_cmos_regc_t )(__DN(std)::read8(_dev, 0xc));
    _os << ("Register regc (Flag register C): ");
    _os << ("\n");
    // _anon0 is anonymous
    ((_os << (" uf =\t")) << lpc_cmos_regc_uf_extract(_regval)) << ("\t(Update-ended)\n");
    ((_os << (" af =\t")) << lpc_cmos_regc_af_extract(_regval)) << ("\t(Alarm)\n");
    ((_os << (" pf =\t")) << lpc_cmos_regc_pf_extract(_regval)) << ("\t(Periodic interrupt)\n");
    ((_os << (" irqf =\t")) << lpc_cmos_regc_irqf_extract(_regval)) << ("\t(Interrupt request flag)\n");
    return(_os);
}

static inline uint8_t lpc_cmos_regc_uf_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_regc_uf_rdf(__DN(t) *_dev)
{
    lpc_cmos_regc_t _regval = (lpc_cmos_regc_t )(__DN(std)::read8(_dev, 0xc));
    return(lpc_cmos_regc_uf_extract(_regval));
}

static inline uint8_t lpc_cmos_regc_af_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_regc_af_rdf(__DN(t) *_dev)
{
    lpc_cmos_regc_t _regval = (lpc_cmos_regc_t )(__DN(std)::read8(_dev, 0xc));
    return(lpc_cmos_regc_af_extract(_regval));
}

static inline uint8_t lpc_cmos_regc_pf_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_regc_pf_rdf(__DN(t) *_dev)
{
    lpc_cmos_regc_t _regval = (lpc_cmos_regc_t )(__DN(std)::read8(_dev, 0xc));
    return(lpc_cmos_regc_pf_extract(_regval));
}

static inline uint8_t lpc_cmos_regc_irqf_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_regc_irqf_rdf(__DN(t) *_dev)
{
    lpc_cmos_regc_t _regval = (lpc_cmos_regc_t )(__DN(std)::read8(_dev, 0xc));
    return(lpc_cmos_regc_irqf_extract(_regval));
}

/*
 * Register regd: Flag register D
 * Type: lpc_cmos.regd (Implicit type of Flag register D register)
 *   al_date	(size 6, offset 0, init 0):	RW	Date alarm
 *   _anon6	(size 1, offset 6, init 0):	RSVD	_
 *   vrt	(size 1, offset 7, init 0):	MBZ	Valid RAM and time
 */
static inline lpc_cmos_regd_t lpc_cmos_regd_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_cmos_regd_t lpc_cmos_regd_rawrd(__DN(t) *_dev)
{
    return((lpc_cmos_regd_t )(__DN(std)::read8(_dev, 0xd)));
}

static inline lpc_cmos_regd_t lpc_cmos_regd_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_cmos_regd_t lpc_cmos_regd_rd(__DN(t) *_dev)
{
    return((lpc_cmos_regd_t )(__DN(std)::read8(_dev, 0xd)));
}

static inline void lpc_cmos_regd_rawwr(__DN(t) *_dev, lpc_cmos_regd_t _regval) __attribute__ ((always_inline));
static inline void lpc_cmos_regd_rawwr(__DN(t) *_dev, lpc_cmos_regd_t _regval)
{
    __DN(std)::write8(_dev, 0xd, _regval);
}

static inline void lpc_cmos_regd_wr(__DN(t) *_dev, lpc_cmos_regd_t _regval) __attribute__ ((always_inline));
static inline void lpc_cmos_regd_wr(__DN(t) *_dev, lpc_cmos_regd_t _regval)
{
    _regval = (_regval & 0x3f);
    // No MB1 fields present
    _regval = (_regval | (0x40 & ((lpc_cmos_regd_t )(__DN(std)::read8(_dev, 0xd)))));
    __DN(std)::write8(_dev, 0xd, _regval);
}

static inline dout_t& lpc_cmos_regd_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_cmos_regd_pr(dout_t& _os, __DN(t) *_dev)
{
    lpc_cmos_regd_t _regval = (lpc_cmos_regd_t )(__DN(std)::read8(_dev, 0xd));
    _os << ("Register regd (Flag register D): ");
    _os << ("\n");
    ((_os << (" al_date =\t")) << lpc_cmos_regd_al_date_extract(_regval)) << ("\t(Date alarm)\n");
    // _anon6 is anonymous
    ((_os << (" vrt =\t")) << lpc_cmos_regd_vrt_extract(_regval)) << ("\t(Valid RAM and time)\n");
    return(_os);
}

static inline uint8_t lpc_cmos_regd_al_date_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_cmos_regd_al_date_rdf(__DN(t) *_dev)
{
    lpc_cmos_regd_t _regval = (lpc_cmos_regd_t )(__DN(std)::read8(_dev, 0xd));
    return(lpc_cmos_regd_al_date_extract(_regval));
}

static inline void lpc_cmos_regd_al_date_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_cmos_regd_al_date_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_cmos_regd_t _regval = (lpc_cmos_regd_t )(0x3f & (((lpc_cmos_regd_t )(_fieldval)) << 0));
    _regval = (_regval | (0x40 & ((lpc_cmos_regd_t )(__DN(std)::read8(_dev, 0xd)))));
    // No read of register shadow required
    _regval = (_regval & 0x7f);
    // No MB1 fields present
    __DN(std)::write8(_dev, 0xd, _regval);
    // No shadow register to write to
}

static inline dout_t& operator<<(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, __DN(t) *_dev)
{
    _os << ("-------------------------\n");
    _os << ("Dump of device lpc_cmos (LPC Real-Time Clock):\n");
    lpc_cmos_ndx_pr(_os, _dev);
    lpc_cmos_target_pr(_os, _dev);
    lpc_cmos_standard_pr(_os, _dev);
    lpc_cmos_endx_pr(_os, _dev);
    lpc_cmos_etarget_pr(_os, _dev);
    lpc_cmos_extended_pr(_os, _dev);
    lpc_cmos_seconds_pr(_os, _dev);
    lpc_cmos_al_seconds_pr(_os, _dev);
    lpc_cmos_minutes_pr(_os, _dev);
    lpc_cmos_al_minutes_pr(_os, _dev);
    lpc_cmos_hours_pr(_os, _dev);
    lpc_cmos_al_hours_pr(_os, _dev);
    lpc_cmos_weekday_pr(_os, _dev);
    lpc_cmos_date_pr(_os, _dev);
    lpc_cmos_month_pr(_os, _dev);
    lpc_cmos_year_pr(_os, _dev);
    lpc_cmos_rega_pr(_os, _dev);
    lpc_cmos_regb_pr(_os, _dev);
    lpc_cmos_regc_pr(_os, _dev);
    lpc_cmos_regd_pr(_os, _dev);
    _os << ("End of dump of device lpc_cmos\n");
    _os << ("-------------------------\n");
    return(_os);
}

#undef __DN
