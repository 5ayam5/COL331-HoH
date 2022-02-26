#pragma once
/*
 * Device Definition: LPC Timer
 * 
 * Automatically Generated from Spec.
 * Using a modified mackerel.
 * 
 * DO NOT EDIT!
 */
#include "util/debug.h"
#include "util/io.h"
#undef __DN
#define __DN(x) lpc_timer ## _ ## x
/*
 * Constants defn: lpc_timer.cnt_mode (Counter mode)
 *  - no width specified
 */
HOH_STRONG_TYPEDEF( uint8_t , lpc_timer_cnt_mode_t);
#define lpc_timer_oseoc ((lpc_timer_cnt_mode_t)0x0)
#define lpc_timer_hr1s ((lpc_timer_cnt_mode_t)0x1)
#define lpc_timer_rtgen ((lpc_timer_cnt_mode_t)0x2)
#define lpc_timer_rtgen_ ((lpc_timer_cnt_mode_t)0x6)
#define lpc_timer_sqwav ((lpc_timer_cnt_mode_t)0x3)
#define lpc_timer_sqwav_ ((lpc_timer_cnt_mode_t)0x7)
#define lpc_timer_swstr ((lpc_timer_cnt_mode_t)0x4)
#define lpc_timer_hwstr ((lpc_timer_cnt_mode_t)0x5)

static inline const char* lpc_timer_cnt_mode_describe(lpc_timer_cnt_mode_t _e) __attribute__ ((always_inline));
static inline const char* lpc_timer_cnt_mode_describe(lpc_timer_cnt_mode_t _e)
{
    switch ((uint8_t )(_e)) {
    case (uint8_t )(0x0):
        return("oseoc: Out signal on end of count (mode 0)");
    case (uint8_t )(0x1):
        return("hr1s: Hardware retriggerable one-shot (mode 1)");
    case (uint8_t )(0x2):
        return("rtgen: Rate generator (mode 2)");
    case (uint8_t )(0x6):
        return("rtgen_: Rate generator (mode 2)");
    case (uint8_t )(0x3):
        return("sqwav: Square wave output (mode 3)");
    case (uint8_t )(0x7):
        return("sqwav_: Square wave output (mode 3)");
    case (uint8_t )(0x4):
        return("swstr: Software triggered strobe (mode 4)");
    case (uint8_t )(0x5):
        return("hwstr: Hardware triggered strobe (mode 5)");
    default:
        return(NULL);
    }
}

static inline dout_t& operator<<(dout_t& _os, lpc_timer_cnt_mode_t _e) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, lpc_timer_cnt_mode_t _e)
{
    const char* d = lpc_timer_cnt_mode_describe(_e);
    if (d) {
        return(_os << d);
    } else {
        return((((_os << ("Unknown constant:")) << ("lpc_timer_cnt_mode_t")) << ("value:")) << ((uint64_t )(_e)));
    }
}

/*
 * Constants defn: lpc_timer.timer_rwsel (Read/write select)
 *  - no width specified
 */
HOH_STRONG_TYPEDEF( uint8_t , lpc_timer_timer_rwsel_t);
#define lpc_timer_clc ((lpc_timer_timer_rwsel_t)0x0)
#define lpc_timer_lsb ((lpc_timer_timer_rwsel_t)0x1)
#define lpc_timer_msb ((lpc_timer_timer_rwsel_t)0x2)
#define lpc_timer_lmsb ((lpc_timer_timer_rwsel_t)0x3)

static inline const char* lpc_timer_timer_rwsel_describe(lpc_timer_timer_rwsel_t _e) __attribute__ ((always_inline));
static inline const char* lpc_timer_timer_rwsel_describe(lpc_timer_timer_rwsel_t _e)
{
    switch ((uint8_t )(_e)) {
    case (uint8_t )(0x0):
        return("clc: Counter latch cmd");
    case (uint8_t )(0x1):
        return("lsb: R/w least sig. byte");
    case (uint8_t )(0x2):
        return("msb: R/w most sig. byte");
    case (uint8_t )(0x3):
        return("lmsb: R/w lsb then msb");
    default:
        return(NULL);
    }
}

static inline dout_t& operator<<(dout_t& _os, lpc_timer_timer_rwsel_t _e) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, lpc_timer_timer_rwsel_t _e)
{
    const char* d = lpc_timer_timer_rwsel_describe(_e);
    if (d) {
        return(_os << d);
    } else {
        return((((_os << ("Unknown constant:")) << ("lpc_timer_timer_rwsel_t")) << ("value:")) << ((uint64_t )(_e)));
    }
}

/*
 * Constants defn: lpc_timer.timer_cntsel (Counter select)
 *  - no width specified
 */
HOH_STRONG_TYPEDEF( uint8_t , lpc_timer_timer_cntsel_t);
#define lpc_timer_c0 ((lpc_timer_timer_cntsel_t)0x0)
#define lpc_timer_c1 ((lpc_timer_timer_cntsel_t)0x1)
#define lpc_timer_c2 ((lpc_timer_timer_cntsel_t)0x2)
#define lpc_timer_rb ((lpc_timer_timer_cntsel_t)0x3)

static inline const char* lpc_timer_timer_cntsel_describe(lpc_timer_timer_cntsel_t _e) __attribute__ ((always_inline));
static inline const char* lpc_timer_timer_cntsel_describe(lpc_timer_timer_cntsel_t _e)
{
    switch ((uint8_t )(_e)) {
    case (uint8_t )(0x0):
        return("c0: Counter 0");
    case (uint8_t )(0x1):
        return("c1: Counter 1");
    case (uint8_t )(0x2):
        return("c2: Counter 2");
    case (uint8_t )(0x3):
        return("rb: Read back cmd");
    default:
        return(NULL);
    }
}

static inline dout_t& operator<<(dout_t& _os, lpc_timer_timer_cntsel_t _e) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, lpc_timer_timer_cntsel_t _e)
{
    const char* d = lpc_timer_timer_cntsel_describe(_e);
    if (d) {
        return(_os << d);
    } else {
        return((((_os << ("Unknown constant:")) << ("lpc_timer_timer_cntsel_t")) << ("value:")) << ((uint64_t )(_e)));
    }
}

/*
 * Register type: lpc_timer_tcw_t
 * Description: Implicit type of Timer Control Word register
 * Fields:
 *   bcd	(size 1, offset 0, init 0):	WO	Binary coded decimal select
 *   mode	(size 3, offset 1, init 0):	WO	Counter mode
 *   rwsel	(size 2, offset 4, init 0):	WO	Read/write select
 *   select	(size 2, offset 6, init 0):	WO	Counter select
 */
HOH_STRONG_TYPEDEF( uint8_t , lpc_timer_tcw_t);
#define lpc_timer_tcw_default (lpc_timer_tcw_t )(0x0)
static inline uint8_t lpc_timer_tcw_bcd_extract(lpc_timer_tcw_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_timer_tcw_bcd_extract(lpc_timer_tcw_t _regval)
{
    return((uint8_t )((_regval & 0x1) >> 0));
}

static inline lpc_timer_tcw_t lpc_timer_tcw_bcd_insert(lpc_timer_tcw_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_timer_tcw_t lpc_timer_tcw_bcd_insert(lpc_timer_tcw_t _regval, uint8_t _fieldval)
{
    return((lpc_timer_tcw_t )((_regval & 0xfe) | (0x1 & (((lpc_timer_tcw_t )(_fieldval)) << 0))));
}

static inline lpc_timer_cnt_mode_t lpc_timer_tcw_mode_extract(lpc_timer_tcw_t _regval) __attribute__ ((always_inline));
static inline lpc_timer_cnt_mode_t lpc_timer_tcw_mode_extract(lpc_timer_tcw_t _regval)
{
    return((lpc_timer_cnt_mode_t )((_regval & 0xe) >> 1));
}

static inline lpc_timer_tcw_t lpc_timer_tcw_mode_insert(lpc_timer_tcw_t _regval, lpc_timer_cnt_mode_t _fieldval) __attribute__ ((always_inline));
static inline lpc_timer_tcw_t lpc_timer_tcw_mode_insert(lpc_timer_tcw_t _regval, lpc_timer_cnt_mode_t _fieldval)
{
    return((lpc_timer_tcw_t )((_regval & 0xf1) | (0xe & (((lpc_timer_tcw_t )(_fieldval)) << 1))));
}

static inline lpc_timer_timer_rwsel_t lpc_timer_tcw_rwsel_extract(lpc_timer_tcw_t _regval) __attribute__ ((always_inline));
static inline lpc_timer_timer_rwsel_t lpc_timer_tcw_rwsel_extract(lpc_timer_tcw_t _regval)
{
    return((lpc_timer_timer_rwsel_t )((_regval & 0x30) >> 4));
}

static inline lpc_timer_tcw_t lpc_timer_tcw_rwsel_insert(lpc_timer_tcw_t _regval, lpc_timer_timer_rwsel_t _fieldval) __attribute__ ((always_inline));
static inline lpc_timer_tcw_t lpc_timer_tcw_rwsel_insert(lpc_timer_tcw_t _regval, lpc_timer_timer_rwsel_t _fieldval)
{
    return((lpc_timer_tcw_t )((_regval & 0xcf) | (0x30 & (((lpc_timer_tcw_t )(_fieldval)) << 4))));
}

static inline lpc_timer_timer_cntsel_t lpc_timer_tcw_select_extract(lpc_timer_tcw_t _regval) __attribute__ ((always_inline));
static inline lpc_timer_timer_cntsel_t lpc_timer_tcw_select_extract(lpc_timer_tcw_t _regval)
{
    return((lpc_timer_timer_cntsel_t )((_regval & 0xc0) >> 6));
}

static inline lpc_timer_tcw_t lpc_timer_tcw_select_insert(lpc_timer_tcw_t _regval, lpc_timer_timer_cntsel_t _fieldval) __attribute__ ((always_inline));
static inline lpc_timer_tcw_t lpc_timer_tcw_select_insert(lpc_timer_tcw_t _regval, lpc_timer_timer_cntsel_t _fieldval)
{
    return((lpc_timer_tcw_t )((_regval & 0x3f) | (0xc0 & (((lpc_timer_tcw_t )(_fieldval)) << 6))));
}

static inline dout_t& operator<<(dout_t& _os, lpc_timer_tcw_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, lpc_timer_tcw_t _regval)
{
    ((_os << (" bcd =\t")) << lpc_timer_tcw_bcd_extract(_regval)) << ("\t(Binary coded decimal select)\n");
    ((_os << (" mode =\t")) << lpc_timer_tcw_mode_extract(_regval)) << ("\t(Counter mode)\n");
    ((_os << (" rwsel =\t")) << lpc_timer_tcw_rwsel_extract(_regval)) << ("\t(Read/write select)\n");
    ((_os << (" select =\t")) << lpc_timer_tcw_select_extract(_regval)) << ("\t(Counter select)\n");
    return(_os);
}

/*
 * Register type: lpc_timer_rdbk_cmd_t
 * Description: Implicit type of Read back command register
 * Fields:
 *   _anon0	(size 1, offset 0, init 0):	MBZ	_
 *   c0	(size 1, offset 1, init 0):	WO	Counter 0 select
 *   c1	(size 1, offset 2, init 0):	WO	Counter 1 select
 *   c2	(size 1, offset 3, init 0):	WO	Counter 2 select
 *   stat	(size 1, offset 4, init 0):	WO	Latch status of selected counters
 *   count	(size 1, offset 5, init 0):	WO	Latch count of selected counters
 *   _anon6	(size 2, offset 6, init 3):	MB1	_
 */
HOH_STRONG_TYPEDEF( uint8_t , lpc_timer_rdbk_cmd_t);
#define lpc_timer_rdbk_cmd_default (lpc_timer_rdbk_cmd_t )(0xc0)
static inline uint8_t lpc_timer_rdbk_cmd_c0_extract(lpc_timer_rdbk_cmd_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_timer_rdbk_cmd_c0_extract(lpc_timer_rdbk_cmd_t _regval)
{
    return((uint8_t )((_regval & 0x2) >> 1));
}

static inline lpc_timer_rdbk_cmd_t lpc_timer_rdbk_cmd_c0_insert(lpc_timer_rdbk_cmd_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_timer_rdbk_cmd_t lpc_timer_rdbk_cmd_c0_insert(lpc_timer_rdbk_cmd_t _regval, uint8_t _fieldval)
{
    return((lpc_timer_rdbk_cmd_t )((_regval & 0xfd) | (0x2 & (((lpc_timer_rdbk_cmd_t )(_fieldval)) << 1))));
}

static inline uint8_t lpc_timer_rdbk_cmd_c1_extract(lpc_timer_rdbk_cmd_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_timer_rdbk_cmd_c1_extract(lpc_timer_rdbk_cmd_t _regval)
{
    return((uint8_t )((_regval & 0x4) >> 2));
}

static inline lpc_timer_rdbk_cmd_t lpc_timer_rdbk_cmd_c1_insert(lpc_timer_rdbk_cmd_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_timer_rdbk_cmd_t lpc_timer_rdbk_cmd_c1_insert(lpc_timer_rdbk_cmd_t _regval, uint8_t _fieldval)
{
    return((lpc_timer_rdbk_cmd_t )((_regval & 0xfb) | (0x4 & (((lpc_timer_rdbk_cmd_t )(_fieldval)) << 2))));
}

static inline uint8_t lpc_timer_rdbk_cmd_c2_extract(lpc_timer_rdbk_cmd_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_timer_rdbk_cmd_c2_extract(lpc_timer_rdbk_cmd_t _regval)
{
    return((uint8_t )((_regval & 0x8) >> 3));
}

static inline lpc_timer_rdbk_cmd_t lpc_timer_rdbk_cmd_c2_insert(lpc_timer_rdbk_cmd_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_timer_rdbk_cmd_t lpc_timer_rdbk_cmd_c2_insert(lpc_timer_rdbk_cmd_t _regval, uint8_t _fieldval)
{
    return((lpc_timer_rdbk_cmd_t )((_regval & 0xf7) | (0x8 & (((lpc_timer_rdbk_cmd_t )(_fieldval)) << 3))));
}

static inline uint8_t lpc_timer_rdbk_cmd_stat_extract(lpc_timer_rdbk_cmd_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_timer_rdbk_cmd_stat_extract(lpc_timer_rdbk_cmd_t _regval)
{
    return((uint8_t )((_regval & 0x10) >> 4));
}

static inline lpc_timer_rdbk_cmd_t lpc_timer_rdbk_cmd_stat_insert(lpc_timer_rdbk_cmd_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_timer_rdbk_cmd_t lpc_timer_rdbk_cmd_stat_insert(lpc_timer_rdbk_cmd_t _regval, uint8_t _fieldval)
{
    return((lpc_timer_rdbk_cmd_t )((_regval & 0xef) | (0x10 & (((lpc_timer_rdbk_cmd_t )(_fieldval)) << 4))));
}

static inline uint8_t lpc_timer_rdbk_cmd_count_extract(lpc_timer_rdbk_cmd_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_timer_rdbk_cmd_count_extract(lpc_timer_rdbk_cmd_t _regval)
{
    return((uint8_t )((_regval & 0x20) >> 5));
}

static inline lpc_timer_rdbk_cmd_t lpc_timer_rdbk_cmd_count_insert(lpc_timer_rdbk_cmd_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_timer_rdbk_cmd_t lpc_timer_rdbk_cmd_count_insert(lpc_timer_rdbk_cmd_t _regval, uint8_t _fieldval)
{
    return((lpc_timer_rdbk_cmd_t )((_regval & 0xdf) | (0x20 & (((lpc_timer_rdbk_cmd_t )(_fieldval)) << 5))));
}

static inline dout_t& operator<<(dout_t& _os, lpc_timer_rdbk_cmd_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, lpc_timer_rdbk_cmd_t _regval)
{
    ((_os << (" c0 =\t")) << lpc_timer_rdbk_cmd_c0_extract(_regval)) << ("\t(Counter 0 select)\n");
    ((_os << (" c1 =\t")) << lpc_timer_rdbk_cmd_c1_extract(_regval)) << ("\t(Counter 1 select)\n");
    ((_os << (" c2 =\t")) << lpc_timer_rdbk_cmd_c2_extract(_regval)) << ("\t(Counter 2 select)\n");
    ((_os << (" stat =\t")) << lpc_timer_rdbk_cmd_stat_extract(_regval)) << ("\t(Latch status of selected counters)\n");
    ((_os << (" count =\t")) << lpc_timer_rdbk_cmd_count_extract(_regval)) << ("\t(Latch count of selected counters)\n");
    return(_os);
}

/*
 * Register type: lpc_timer_ltch_cmd_t
 * Description: Implicit type of Counter latch command register
 * Fields:
 *   _anon0	(size 6, offset 0, init 0):	MBZ	_
 *   select	(size 2, offset 6, init 0):	WO	Counter select
 */
HOH_STRONG_TYPEDEF( uint8_t , lpc_timer_ltch_cmd_t);
#define lpc_timer_ltch_cmd_default (lpc_timer_ltch_cmd_t )(0x0)
static inline lpc_timer_timer_cntsel_t lpc_timer_ltch_cmd_select_extract(lpc_timer_ltch_cmd_t _regval) __attribute__ ((always_inline));
static inline lpc_timer_timer_cntsel_t lpc_timer_ltch_cmd_select_extract(lpc_timer_ltch_cmd_t _regval)
{
    return((lpc_timer_timer_cntsel_t )((_regval & 0xc0) >> 6));
}

static inline lpc_timer_ltch_cmd_t lpc_timer_ltch_cmd_select_insert(lpc_timer_ltch_cmd_t _regval, lpc_timer_timer_cntsel_t _fieldval) __attribute__ ((always_inline));
static inline lpc_timer_ltch_cmd_t lpc_timer_ltch_cmd_select_insert(lpc_timer_ltch_cmd_t _regval, lpc_timer_timer_cntsel_t _fieldval)
{
    return((lpc_timer_ltch_cmd_t )((_regval & 0x3f) | (0xc0 & (((lpc_timer_ltch_cmd_t )(_fieldval)) << 6))));
}

static inline dout_t& operator<<(dout_t& _os, lpc_timer_ltch_cmd_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, lpc_timer_ltch_cmd_t _regval)
{
    ((_os << (" select =\t")) << lpc_timer_ltch_cmd_select_extract(_regval)) << ("\t(Counter select)\n");
    return(_os);
}

/*
 * Register type: lpc_timer_sbyte_fmt_t
 * Description: Interval timer status byte format
 * Fields:
 *   bcd	(size 1, offset 0, init 0):	NOATTR	Binary coded decimal select
 *   mode	(size 3, offset 1, init 0):	NOATTR	Counter mode
 *   rwsel	(size 2, offset 4, init 0):	NOATTR	Read/write select
 *   cnt_stat	(size 1, offset 6, init 0):	NOATTR	Count register status
 *   cnt_out	(size 1, offset 7, init 0):	NOATTR	Counter OUT pin status
 */
HOH_STRONG_TYPEDEF( uint8_t , lpc_timer_sbyte_fmt_t);
#define lpc_timer_sbyte_fmt_default (lpc_timer_sbyte_fmt_t )(0x0)
static inline uint8_t lpc_timer_sbyte_fmt_bcd_extract(lpc_timer_sbyte_fmt_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_timer_sbyte_fmt_bcd_extract(lpc_timer_sbyte_fmt_t _regval)
{
    return((uint8_t )((_regval & 0x1) >> 0));
}

static inline lpc_timer_sbyte_fmt_t lpc_timer_sbyte_fmt_bcd_insert(lpc_timer_sbyte_fmt_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_timer_sbyte_fmt_t lpc_timer_sbyte_fmt_bcd_insert(lpc_timer_sbyte_fmt_t _regval, uint8_t _fieldval)
{
    return((lpc_timer_sbyte_fmt_t )((_regval & 0xfe) | (0x1 & (((lpc_timer_sbyte_fmt_t )(_fieldval)) << 0))));
}

static inline lpc_timer_cnt_mode_t lpc_timer_sbyte_fmt_mode_extract(lpc_timer_sbyte_fmt_t _regval) __attribute__ ((always_inline));
static inline lpc_timer_cnt_mode_t lpc_timer_sbyte_fmt_mode_extract(lpc_timer_sbyte_fmt_t _regval)
{
    return((lpc_timer_cnt_mode_t )((_regval & 0xe) >> 1));
}

static inline lpc_timer_sbyte_fmt_t lpc_timer_sbyte_fmt_mode_insert(lpc_timer_sbyte_fmt_t _regval, lpc_timer_cnt_mode_t _fieldval) __attribute__ ((always_inline));
static inline lpc_timer_sbyte_fmt_t lpc_timer_sbyte_fmt_mode_insert(lpc_timer_sbyte_fmt_t _regval, lpc_timer_cnt_mode_t _fieldval)
{
    return((lpc_timer_sbyte_fmt_t )((_regval & 0xf1) | (0xe & (((lpc_timer_sbyte_fmt_t )(_fieldval)) << 1))));
}

static inline lpc_timer_timer_rwsel_t lpc_timer_sbyte_fmt_rwsel_extract(lpc_timer_sbyte_fmt_t _regval) __attribute__ ((always_inline));
static inline lpc_timer_timer_rwsel_t lpc_timer_sbyte_fmt_rwsel_extract(lpc_timer_sbyte_fmt_t _regval)
{
    return((lpc_timer_timer_rwsel_t )((_regval & 0x30) >> 4));
}

static inline lpc_timer_sbyte_fmt_t lpc_timer_sbyte_fmt_rwsel_insert(lpc_timer_sbyte_fmt_t _regval, lpc_timer_timer_rwsel_t _fieldval) __attribute__ ((always_inline));
static inline lpc_timer_sbyte_fmt_t lpc_timer_sbyte_fmt_rwsel_insert(lpc_timer_sbyte_fmt_t _regval, lpc_timer_timer_rwsel_t _fieldval)
{
    return((lpc_timer_sbyte_fmt_t )((_regval & 0xcf) | (0x30 & (((lpc_timer_sbyte_fmt_t )(_fieldval)) << 4))));
}

static inline uint8_t lpc_timer_sbyte_fmt_cnt_stat_extract(lpc_timer_sbyte_fmt_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_timer_sbyte_fmt_cnt_stat_extract(lpc_timer_sbyte_fmt_t _regval)
{
    return((uint8_t )((_regval & 0x40) >> 6));
}

static inline lpc_timer_sbyte_fmt_t lpc_timer_sbyte_fmt_cnt_stat_insert(lpc_timer_sbyte_fmt_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_timer_sbyte_fmt_t lpc_timer_sbyte_fmt_cnt_stat_insert(lpc_timer_sbyte_fmt_t _regval, uint8_t _fieldval)
{
    return((lpc_timer_sbyte_fmt_t )((_regval & 0xbf) | (0x40 & (((lpc_timer_sbyte_fmt_t )(_fieldval)) << 6))));
}

static inline uint8_t lpc_timer_sbyte_fmt_cnt_out_extract(lpc_timer_sbyte_fmt_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_timer_sbyte_fmt_cnt_out_extract(lpc_timer_sbyte_fmt_t _regval)
{
    return((uint8_t )((_regval & 0x80) >> 7));
}

static inline lpc_timer_sbyte_fmt_t lpc_timer_sbyte_fmt_cnt_out_insert(lpc_timer_sbyte_fmt_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_timer_sbyte_fmt_t lpc_timer_sbyte_fmt_cnt_out_insert(lpc_timer_sbyte_fmt_t _regval, uint8_t _fieldval)
{
    return((lpc_timer_sbyte_fmt_t )((_regval & 0x7f) | (0x80 & (((lpc_timer_sbyte_fmt_t )(_fieldval)) << 7))));
}

static inline dout_t& operator<<(dout_t& _os, lpc_timer_sbyte_fmt_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, lpc_timer_sbyte_fmt_t _regval)
{
    ((_os << (" bcd =\t")) << lpc_timer_sbyte_fmt_bcd_extract(_regval)) << ("\t(Binary coded decimal select)\n");
    ((_os << (" mode =\t")) << lpc_timer_sbyte_fmt_mode_extract(_regval)) << ("\t(Counter mode)\n");
    ((_os << (" rwsel =\t")) << lpc_timer_sbyte_fmt_rwsel_extract(_regval)) << ("\t(Read/write select)\n");
    ((_os << (" cnt_stat =\t")) << lpc_timer_sbyte_fmt_cnt_stat_extract(_regval)) << ("\t(Count register status)\n");
    ((_os << (" cnt_out =\t")) << lpc_timer_sbyte_fmt_cnt_out_extract(_regval)) << ("\t(Counter OUT pin status)\n");
    return(_os);
}

/*
 * Device representation structure
 */
struct __DN(t) {
    io_t base;
    lpc_timer_tcw_t tcw_shadow;
    lpc_timer_rdbk_cmd_t rdbk_cmd_shadow;
    lpc_timer_ltch_cmd_t ltch_cmd_shadow;
};

/*
 * Initial register values (currently 0)
 */
enum lpc_timer_initials {
    lpc_timer_tcw_initial = 0x0,
    lpc_timer_rdbk_cmd_initial = 0x0,
    lpc_timer_ltch_cmd_initial = 0x0,
    lpc_timer_sbyte_fmt0_initial = 0x0,
    lpc_timer_sbyte_fmt1_initial = 0x0,
    lpc_timer_sbyte_fmt2_initial = 0x0,
    lpc_timer_cntacc0_initial = 0x0,
    lpc_timer_cntacc1_initial = 0x0,
    lpc_timer_cntacc2_initial = 0x0
};

/*
 * Device Initialization function
 */
static inline void lpc_timer_initialize(__DN(t) *_dev, io_t base) __attribute__ ((always_inline));
static inline void lpc_timer_initialize(__DN(t) *_dev, io_t base)
{
    _dev->base = base;
}

/*
 * No user-defined spaces
 */
/*
 * Register tcw: Timer Control Word
 * Type: lpc_timer.tcw (Implicit type of Timer Control Word register)
 *   bcd	(size 1, offset 0, init 0):	WO	Binary coded decimal select
 *   mode	(size 3, offset 1, init 0):	WO	Counter mode
 *   rwsel	(size 2, offset 4, init 0):	WO	Read/write select
 *   select	(size 2, offset 6, init 0):	WO	Counter select
 */
static inline lpc_timer_tcw_t lpc_timer_tcw_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_timer_tcw_t lpc_timer_tcw_rawrd(__DN(t) *_dev)
{
    return((lpc_timer_tcw_t )(io::read8(_dev->base, 0x3)));
}

static inline lpc_timer_tcw_t lpc_timer_tcw_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_timer_tcw_t lpc_timer_tcw_rd(__DN(t) *_dev)
{
    return(_dev->tcw_shadow);
}

static inline void lpc_timer_tcw_rawwr(__DN(t) *_dev, lpc_timer_tcw_t _regval) __attribute__ ((always_inline));
static inline void lpc_timer_tcw_rawwr(__DN(t) *_dev, lpc_timer_tcw_t _regval)
{
    io::write8(_dev->base, 0x3, _regval);
}

static inline void lpc_timer_tcw_wr(__DN(t) *_dev, lpc_timer_tcw_t _regval) __attribute__ ((always_inline));
static inline void lpc_timer_tcw_wr(__DN(t) *_dev, lpc_timer_tcw_t _regval)
{
    // No MB0 or RSVD fields present
    // No MB1 fields present
    // No pre-read of register required
    io::write8(_dev->base, 0x3, _regval);
}

static inline dout_t& lpc_timer_tcw_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_timer_tcw_pr(dout_t& _os, __DN(t) *_dev)
{
    lpc_timer_tcw_t _regval = _dev->tcw_shadow;
    _os << ("Register tcw (Timer Control Word): ");
    _os << ("\n");
    ((_os << (" bcd =\t")) << lpc_timer_tcw_bcd_extract(_regval)) << ("\t(Binary coded decimal select)\n");
    ((_os << (" mode =\t")) << lpc_timer_tcw_mode_extract(_regval)) << ("\t(Counter mode)\n");
    ((_os << (" rwsel =\t")) << lpc_timer_tcw_rwsel_extract(_regval)) << ("\t(Read/write select)\n");
    ((_os << (" select =\t")) << lpc_timer_tcw_select_extract(_regval)) << ("\t(Counter select)\n");
    return(_os);
}

static inline uint8_t lpc_timer_tcw_bcd_rd_shadow(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_timer_tcw_bcd_rd_shadow(__DN(t) *_dev)
{
    return(lpc_timer_tcw_bcd_extract(_dev->tcw_shadow));
}

static inline lpc_timer_cnt_mode_t lpc_timer_tcw_mode_rd_shadow(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_timer_cnt_mode_t lpc_timer_tcw_mode_rd_shadow(__DN(t) *_dev)
{
    return(lpc_timer_tcw_mode_extract(_dev->tcw_shadow));
}

static inline lpc_timer_timer_rwsel_t lpc_timer_tcw_rwsel_rd_shadow(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_timer_timer_rwsel_t lpc_timer_tcw_rwsel_rd_shadow(__DN(t) *_dev)
{
    return(lpc_timer_tcw_rwsel_extract(_dev->tcw_shadow));
}

static inline lpc_timer_timer_cntsel_t lpc_timer_tcw_select_rd_shadow(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_timer_timer_cntsel_t lpc_timer_tcw_select_rd_shadow(__DN(t) *_dev)
{
    return(lpc_timer_tcw_select_extract(_dev->tcw_shadow));
}

static inline void lpc_timer_tcw_bcd_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_timer_tcw_bcd_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_timer_tcw_t _regval = (lpc_timer_tcw_t )(0x1 & (((lpc_timer_tcw_t )(_fieldval)) << 0));
    // No pre-read of register required
    _regval = (_regval | (0xfe & (_dev->tcw_shadow)));
    // No MB0 fields present
    // No MB1 fields present
    io::write8(_dev->base, 0x3, _regval);
    _dev->tcw_shadow = _regval;
}

static inline void lpc_timer_tcw_mode_wrf(__DN(t) *_dev, lpc_timer_cnt_mode_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_timer_tcw_mode_wrf(__DN(t) *_dev, lpc_timer_cnt_mode_t _fieldval)
{
    lpc_timer_tcw_t _regval = (lpc_timer_tcw_t )(0xe & (((lpc_timer_tcw_t )(_fieldval)) << 1));
    // No pre-read of register required
    _regval = (_regval | (0xf1 & (_dev->tcw_shadow)));
    // No MB0 fields present
    // No MB1 fields present
    io::write8(_dev->base, 0x3, _regval);
    _dev->tcw_shadow = _regval;
}

static inline void lpc_timer_tcw_rwsel_wrf(__DN(t) *_dev, lpc_timer_timer_rwsel_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_timer_tcw_rwsel_wrf(__DN(t) *_dev, lpc_timer_timer_rwsel_t _fieldval)
{
    lpc_timer_tcw_t _regval = (lpc_timer_tcw_t )(0x30 & (((lpc_timer_tcw_t )(_fieldval)) << 4));
    // No pre-read of register required
    _regval = (_regval | (0xcf & (_dev->tcw_shadow)));
    // No MB0 fields present
    // No MB1 fields present
    io::write8(_dev->base, 0x3, _regval);
    _dev->tcw_shadow = _regval;
}

static inline void lpc_timer_tcw_select_wrf(__DN(t) *_dev, lpc_timer_timer_cntsel_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_timer_tcw_select_wrf(__DN(t) *_dev, lpc_timer_timer_cntsel_t _fieldval)
{
    lpc_timer_tcw_t _regval = (lpc_timer_tcw_t )(0xc0 & (((lpc_timer_tcw_t )(_fieldval)) << 6));
    // No pre-read of register required
    _regval = (_regval | (0x3f & (_dev->tcw_shadow)));
    // No MB0 fields present
    // No MB1 fields present
    io::write8(_dev->base, 0x3, _regval);
    _dev->tcw_shadow = _regval;
}

/*
 * Register rdbk_cmd: Read back command
 * Type: lpc_timer.rdbk_cmd (Implicit type of Read back command register)
 *   _anon0	(size 1, offset 0, init 0):	MBZ	_
 *   c0	(size 1, offset 1, init 0):	WO	Counter 0 select
 *   c1	(size 1, offset 2, init 0):	WO	Counter 1 select
 *   c2	(size 1, offset 3, init 0):	WO	Counter 2 select
 *   stat	(size 1, offset 4, init 0):	WO	Latch status of selected counters
 *   count	(size 1, offset 5, init 0):	WO	Latch count of selected counters
 *   _anon6	(size 2, offset 6, init 3):	MB1	_
 */
static inline lpc_timer_rdbk_cmd_t lpc_timer_rdbk_cmd_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_timer_rdbk_cmd_t lpc_timer_rdbk_cmd_rawrd(__DN(t) *_dev)
{
    return((lpc_timer_rdbk_cmd_t )(io::read8(_dev->base, 0x3)));
}

static inline lpc_timer_rdbk_cmd_t lpc_timer_rdbk_cmd_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_timer_rdbk_cmd_t lpc_timer_rdbk_cmd_rd(__DN(t) *_dev)
{
    return(_dev->rdbk_cmd_shadow);
}

static inline void lpc_timer_rdbk_cmd_rawwr(__DN(t) *_dev, lpc_timer_rdbk_cmd_t _regval) __attribute__ ((always_inline));
static inline void lpc_timer_rdbk_cmd_rawwr(__DN(t) *_dev, lpc_timer_rdbk_cmd_t _regval)
{
    io::write8(_dev->base, 0x3, _regval);
}

static inline void lpc_timer_rdbk_cmd_wr(__DN(t) *_dev, lpc_timer_rdbk_cmd_t _regval) __attribute__ ((always_inline));
static inline void lpc_timer_rdbk_cmd_wr(__DN(t) *_dev, lpc_timer_rdbk_cmd_t _regval)
{
    _regval = (_regval & 0xfe);
    _regval = (_regval | 0xc0);
    // No pre-read of register required
    io::write8(_dev->base, 0x3, _regval);
}

static inline dout_t& lpc_timer_rdbk_cmd_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_timer_rdbk_cmd_pr(dout_t& _os, __DN(t) *_dev)
{
    lpc_timer_rdbk_cmd_t _regval = _dev->rdbk_cmd_shadow;
    _os << ("Register rdbk_cmd (Read back command): ");
    _os << ("\n");
    // _anon0 is anonymous
    ((_os << (" c0 =\t")) << lpc_timer_rdbk_cmd_c0_extract(_regval)) << ("\t(Counter 0 select)\n");
    ((_os << (" c1 =\t")) << lpc_timer_rdbk_cmd_c1_extract(_regval)) << ("\t(Counter 1 select)\n");
    ((_os << (" c2 =\t")) << lpc_timer_rdbk_cmd_c2_extract(_regval)) << ("\t(Counter 2 select)\n");
    ((_os << (" stat =\t")) << lpc_timer_rdbk_cmd_stat_extract(_regval)) << ("\t(Latch status of selected counters)\n");
    ((_os << (" count =\t")) << lpc_timer_rdbk_cmd_count_extract(_regval)) << ("\t(Latch count of selected counters)\n");
    // _anon6 is anonymous
    return(_os);
}

static inline uint8_t lpc_timer_rdbk_cmd_c0_rd_shadow(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_timer_rdbk_cmd_c0_rd_shadow(__DN(t) *_dev)
{
    return(lpc_timer_rdbk_cmd_c0_extract(_dev->rdbk_cmd_shadow));
}

static inline uint8_t lpc_timer_rdbk_cmd_c1_rd_shadow(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_timer_rdbk_cmd_c1_rd_shadow(__DN(t) *_dev)
{
    return(lpc_timer_rdbk_cmd_c1_extract(_dev->rdbk_cmd_shadow));
}

static inline uint8_t lpc_timer_rdbk_cmd_c2_rd_shadow(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_timer_rdbk_cmd_c2_rd_shadow(__DN(t) *_dev)
{
    return(lpc_timer_rdbk_cmd_c2_extract(_dev->rdbk_cmd_shadow));
}

static inline uint8_t lpc_timer_rdbk_cmd_stat_rd_shadow(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_timer_rdbk_cmd_stat_rd_shadow(__DN(t) *_dev)
{
    return(lpc_timer_rdbk_cmd_stat_extract(_dev->rdbk_cmd_shadow));
}

static inline uint8_t lpc_timer_rdbk_cmd_count_rd_shadow(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_timer_rdbk_cmd_count_rd_shadow(__DN(t) *_dev)
{
    return(lpc_timer_rdbk_cmd_count_extract(_dev->rdbk_cmd_shadow));
}

static inline void lpc_timer_rdbk_cmd_c0_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_timer_rdbk_cmd_c0_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_timer_rdbk_cmd_t _regval = (lpc_timer_rdbk_cmd_t )(0x2 & (((lpc_timer_rdbk_cmd_t )(_fieldval)) << 1));
    // No pre-read of register required
    _regval = (_regval | (0x3c & (_dev->rdbk_cmd_shadow)));
    _regval = (_regval & 0xfe);
    _regval = (_regval | 0xc0);
    io::write8(_dev->base, 0x3, _regval);
    _dev->rdbk_cmd_shadow = _regval;
}

static inline void lpc_timer_rdbk_cmd_c1_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_timer_rdbk_cmd_c1_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_timer_rdbk_cmd_t _regval = (lpc_timer_rdbk_cmd_t )(0x4 & (((lpc_timer_rdbk_cmd_t )(_fieldval)) << 2));
    // No pre-read of register required
    _regval = (_regval | (0x3a & (_dev->rdbk_cmd_shadow)));
    _regval = (_regval & 0xfe);
    _regval = (_regval | 0xc0);
    io::write8(_dev->base, 0x3, _regval);
    _dev->rdbk_cmd_shadow = _regval;
}

static inline void lpc_timer_rdbk_cmd_c2_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_timer_rdbk_cmd_c2_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_timer_rdbk_cmd_t _regval = (lpc_timer_rdbk_cmd_t )(0x8 & (((lpc_timer_rdbk_cmd_t )(_fieldval)) << 3));
    // No pre-read of register required
    _regval = (_regval | (0x36 & (_dev->rdbk_cmd_shadow)));
    _regval = (_regval & 0xfe);
    _regval = (_regval | 0xc0);
    io::write8(_dev->base, 0x3, _regval);
    _dev->rdbk_cmd_shadow = _regval;
}

static inline void lpc_timer_rdbk_cmd_stat_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_timer_rdbk_cmd_stat_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_timer_rdbk_cmd_t _regval = (lpc_timer_rdbk_cmd_t )(0x10 & (((lpc_timer_rdbk_cmd_t )(_fieldval)) << 4));
    // No pre-read of register required
    _regval = (_regval | (0x2e & (_dev->rdbk_cmd_shadow)));
    _regval = (_regval & 0xfe);
    _regval = (_regval | 0xc0);
    io::write8(_dev->base, 0x3, _regval);
    _dev->rdbk_cmd_shadow = _regval;
}

static inline void lpc_timer_rdbk_cmd_count_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_timer_rdbk_cmd_count_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_timer_rdbk_cmd_t _regval = (lpc_timer_rdbk_cmd_t )(0x20 & (((lpc_timer_rdbk_cmd_t )(_fieldval)) << 5));
    // No pre-read of register required
    _regval = (_regval | (0x1e & (_dev->rdbk_cmd_shadow)));
    _regval = (_regval & 0xfe);
    _regval = (_regval | 0xc0);
    io::write8(_dev->base, 0x3, _regval);
    _dev->rdbk_cmd_shadow = _regval;
}

/*
 * Register ltch_cmd: Counter latch command
 * Type: lpc_timer.ltch_cmd (Implicit type of Counter latch command register)
 *   _anon0	(size 6, offset 0, init 0):	MBZ	_
 *   select	(size 2, offset 6, init 0):	WO	Counter select
 */
static inline lpc_timer_ltch_cmd_t lpc_timer_ltch_cmd_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_timer_ltch_cmd_t lpc_timer_ltch_cmd_rawrd(__DN(t) *_dev)
{
    return((lpc_timer_ltch_cmd_t )(io::read8(_dev->base, 0x3)));
}

static inline lpc_timer_ltch_cmd_t lpc_timer_ltch_cmd_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_timer_ltch_cmd_t lpc_timer_ltch_cmd_rd(__DN(t) *_dev)
{
    return(_dev->ltch_cmd_shadow);
}

static inline void lpc_timer_ltch_cmd_rawwr(__DN(t) *_dev, lpc_timer_ltch_cmd_t _regval) __attribute__ ((always_inline));
static inline void lpc_timer_ltch_cmd_rawwr(__DN(t) *_dev, lpc_timer_ltch_cmd_t _regval)
{
    io::write8(_dev->base, 0x3, _regval);
}

static inline void lpc_timer_ltch_cmd_wr(__DN(t) *_dev, lpc_timer_ltch_cmd_t _regval) __attribute__ ((always_inline));
static inline void lpc_timer_ltch_cmd_wr(__DN(t) *_dev, lpc_timer_ltch_cmd_t _regval)
{
    _regval = (_regval & 0xc0);
    // No MB1 fields present
    // No pre-read of register required
    io::write8(_dev->base, 0x3, _regval);
}

static inline dout_t& lpc_timer_ltch_cmd_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_timer_ltch_cmd_pr(dout_t& _os, __DN(t) *_dev)
{
    lpc_timer_ltch_cmd_t _regval = _dev->ltch_cmd_shadow;
    _os << ("Register ltch_cmd (Counter latch command): ");
    _os << ("\n");
    // _anon0 is anonymous
    ((_os << (" select =\t")) << lpc_timer_ltch_cmd_select_extract(_regval)) << ("\t(Counter select)\n");
    return(_os);
}

static inline lpc_timer_timer_cntsel_t lpc_timer_ltch_cmd_select_rd_shadow(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_timer_timer_cntsel_t lpc_timer_ltch_cmd_select_rd_shadow(__DN(t) *_dev)
{
    return(lpc_timer_ltch_cmd_select_extract(_dev->ltch_cmd_shadow));
}

static inline void lpc_timer_ltch_cmd_select_wrf(__DN(t) *_dev, lpc_timer_timer_cntsel_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_timer_ltch_cmd_select_wrf(__DN(t) *_dev, lpc_timer_timer_cntsel_t _fieldval)
{
    lpc_timer_ltch_cmd_t _regval = (lpc_timer_ltch_cmd_t )(0xc0 & (((lpc_timer_ltch_cmd_t )(_fieldval)) << 6));
    // No pre-read of register required
    // No read of register shadow required
    _regval = (_regval & 0xc0);
    // No MB1 fields present
    io::write8(_dev->base, 0x3, _regval);
    _dev->ltch_cmd_shadow = _regval;
}

/*
 * Register sbyte_fmt0: Int. timer 0 status format
 * Type: lpc_timer.sbyte_fmt (Interval timer status byte format)
 *   bcd	(size 1, offset 0, init 0):	RO	Binary coded decimal select
 *   mode	(size 3, offset 1, init 0):	RO	Counter mode
 *   rwsel	(size 2, offset 4, init 0):	RO	Read/write select
 *   cnt_stat	(size 1, offset 6, init 0):	RO	Count register status
 *   cnt_out	(size 1, offset 7, init 0):	RO	Counter OUT pin status
 */
static inline lpc_timer_sbyte_fmt_t lpc_timer_sbyte_fmt0_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_timer_sbyte_fmt_t lpc_timer_sbyte_fmt0_rawrd(__DN(t) *_dev)
{
    return((lpc_timer_sbyte_fmt_t )(io::read8(_dev->base, 0x0)));
}

static inline lpc_timer_sbyte_fmt_t lpc_timer_sbyte_fmt0_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_timer_sbyte_fmt_t lpc_timer_sbyte_fmt0_rd(__DN(t) *_dev)
{
    return((lpc_timer_sbyte_fmt_t )(io::read8(_dev->base, 0x0)));
}

static inline void lpc_timer_sbyte_fmt0_rawwr(__DN(t) *_dev, lpc_timer_sbyte_fmt_t _regval) __attribute__ ((always_inline));
static inline void lpc_timer_sbyte_fmt0_rawwr(__DN(t) *_dev, lpc_timer_sbyte_fmt_t _regval)
{
    io::write8(_dev->base, 0x0, _regval);
}

// Register sbyte_fmt0 is not writeable
static inline dout_t& lpc_timer_sbyte_fmt0_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_timer_sbyte_fmt0_pr(dout_t& _os, __DN(t) *_dev)
{
    lpc_timer_sbyte_fmt_t _regval = (lpc_timer_sbyte_fmt_t )(io::read8(_dev->base, 0x0));
    _os << ("Register sbyte_fmt0 (Int. timer 0 status format): ");
    _os << ("\n");
    ((_os << (" bcd =\t")) << lpc_timer_sbyte_fmt_bcd_extract(_regval)) << ("\t(Binary coded decimal select)\n");
    ((_os << (" mode =\t")) << lpc_timer_sbyte_fmt_mode_extract(_regval)) << ("\t(Counter mode)\n");
    ((_os << (" rwsel =\t")) << lpc_timer_sbyte_fmt_rwsel_extract(_regval)) << ("\t(Read/write select)\n");
    ((_os << (" cnt_stat =\t")) << lpc_timer_sbyte_fmt_cnt_stat_extract(_regval)) << ("\t(Count register status)\n");
    ((_os << (" cnt_out =\t")) << lpc_timer_sbyte_fmt_cnt_out_extract(_regval)) << ("\t(Counter OUT pin status)\n");
    return(_os);
}

static inline uint8_t lpc_timer_sbyte_fmt0_bcd_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_timer_sbyte_fmt0_bcd_rdf(__DN(t) *_dev)
{
    lpc_timer_sbyte_fmt_t _regval = (lpc_timer_sbyte_fmt_t )(io::read8(_dev->base, 0x0));
    return(lpc_timer_sbyte_fmt_bcd_extract(_regval));
}

static inline lpc_timer_cnt_mode_t lpc_timer_sbyte_fmt0_mode_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_timer_cnt_mode_t lpc_timer_sbyte_fmt0_mode_rdf(__DN(t) *_dev)
{
    lpc_timer_sbyte_fmt_t _regval = (lpc_timer_sbyte_fmt_t )(io::read8(_dev->base, 0x0));
    return(lpc_timer_sbyte_fmt_mode_extract(_regval));
}

static inline lpc_timer_timer_rwsel_t lpc_timer_sbyte_fmt0_rwsel_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_timer_timer_rwsel_t lpc_timer_sbyte_fmt0_rwsel_rdf(__DN(t) *_dev)
{
    lpc_timer_sbyte_fmt_t _regval = (lpc_timer_sbyte_fmt_t )(io::read8(_dev->base, 0x0));
    return(lpc_timer_sbyte_fmt_rwsel_extract(_regval));
}

static inline uint8_t lpc_timer_sbyte_fmt0_cnt_stat_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_timer_sbyte_fmt0_cnt_stat_rdf(__DN(t) *_dev)
{
    lpc_timer_sbyte_fmt_t _regval = (lpc_timer_sbyte_fmt_t )(io::read8(_dev->base, 0x0));
    return(lpc_timer_sbyte_fmt_cnt_stat_extract(_regval));
}

static inline uint8_t lpc_timer_sbyte_fmt0_cnt_out_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_timer_sbyte_fmt0_cnt_out_rdf(__DN(t) *_dev)
{
    lpc_timer_sbyte_fmt_t _regval = (lpc_timer_sbyte_fmt_t )(io::read8(_dev->base, 0x0));
    return(lpc_timer_sbyte_fmt_cnt_out_extract(_regval));
}

/*
 * Register sbyte_fmt1: Int. timer 1 status format
 * Type: lpc_timer.sbyte_fmt (Interval timer status byte format)
 *   bcd	(size 1, offset 0, init 0):	RO	Binary coded decimal select
 *   mode	(size 3, offset 1, init 0):	RO	Counter mode
 *   rwsel	(size 2, offset 4, init 0):	RO	Read/write select
 *   cnt_stat	(size 1, offset 6, init 0):	RO	Count register status
 *   cnt_out	(size 1, offset 7, init 0):	RO	Counter OUT pin status
 */
static inline lpc_timer_sbyte_fmt_t lpc_timer_sbyte_fmt1_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_timer_sbyte_fmt_t lpc_timer_sbyte_fmt1_rawrd(__DN(t) *_dev)
{
    return((lpc_timer_sbyte_fmt_t )(io::read8(_dev->base, 0x1)));
}

static inline lpc_timer_sbyte_fmt_t lpc_timer_sbyte_fmt1_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_timer_sbyte_fmt_t lpc_timer_sbyte_fmt1_rd(__DN(t) *_dev)
{
    return((lpc_timer_sbyte_fmt_t )(io::read8(_dev->base, 0x1)));
}

static inline void lpc_timer_sbyte_fmt1_rawwr(__DN(t) *_dev, lpc_timer_sbyte_fmt_t _regval) __attribute__ ((always_inline));
static inline void lpc_timer_sbyte_fmt1_rawwr(__DN(t) *_dev, lpc_timer_sbyte_fmt_t _regval)
{
    io::write8(_dev->base, 0x1, _regval);
}

// Register sbyte_fmt1 is not writeable
static inline dout_t& lpc_timer_sbyte_fmt1_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_timer_sbyte_fmt1_pr(dout_t& _os, __DN(t) *_dev)
{
    lpc_timer_sbyte_fmt_t _regval = (lpc_timer_sbyte_fmt_t )(io::read8(_dev->base, 0x1));
    _os << ("Register sbyte_fmt1 (Int. timer 1 status format): ");
    _os << ("\n");
    ((_os << (" bcd =\t")) << lpc_timer_sbyte_fmt_bcd_extract(_regval)) << ("\t(Binary coded decimal select)\n");
    ((_os << (" mode =\t")) << lpc_timer_sbyte_fmt_mode_extract(_regval)) << ("\t(Counter mode)\n");
    ((_os << (" rwsel =\t")) << lpc_timer_sbyte_fmt_rwsel_extract(_regval)) << ("\t(Read/write select)\n");
    ((_os << (" cnt_stat =\t")) << lpc_timer_sbyte_fmt_cnt_stat_extract(_regval)) << ("\t(Count register status)\n");
    ((_os << (" cnt_out =\t")) << lpc_timer_sbyte_fmt_cnt_out_extract(_regval)) << ("\t(Counter OUT pin status)\n");
    return(_os);
}

static inline uint8_t lpc_timer_sbyte_fmt1_bcd_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_timer_sbyte_fmt1_bcd_rdf(__DN(t) *_dev)
{
    lpc_timer_sbyte_fmt_t _regval = (lpc_timer_sbyte_fmt_t )(io::read8(_dev->base, 0x1));
    return(lpc_timer_sbyte_fmt_bcd_extract(_regval));
}

static inline lpc_timer_cnt_mode_t lpc_timer_sbyte_fmt1_mode_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_timer_cnt_mode_t lpc_timer_sbyte_fmt1_mode_rdf(__DN(t) *_dev)
{
    lpc_timer_sbyte_fmt_t _regval = (lpc_timer_sbyte_fmt_t )(io::read8(_dev->base, 0x1));
    return(lpc_timer_sbyte_fmt_mode_extract(_regval));
}

static inline lpc_timer_timer_rwsel_t lpc_timer_sbyte_fmt1_rwsel_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_timer_timer_rwsel_t lpc_timer_sbyte_fmt1_rwsel_rdf(__DN(t) *_dev)
{
    lpc_timer_sbyte_fmt_t _regval = (lpc_timer_sbyte_fmt_t )(io::read8(_dev->base, 0x1));
    return(lpc_timer_sbyte_fmt_rwsel_extract(_regval));
}

static inline uint8_t lpc_timer_sbyte_fmt1_cnt_stat_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_timer_sbyte_fmt1_cnt_stat_rdf(__DN(t) *_dev)
{
    lpc_timer_sbyte_fmt_t _regval = (lpc_timer_sbyte_fmt_t )(io::read8(_dev->base, 0x1));
    return(lpc_timer_sbyte_fmt_cnt_stat_extract(_regval));
}

static inline uint8_t lpc_timer_sbyte_fmt1_cnt_out_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_timer_sbyte_fmt1_cnt_out_rdf(__DN(t) *_dev)
{
    lpc_timer_sbyte_fmt_t _regval = (lpc_timer_sbyte_fmt_t )(io::read8(_dev->base, 0x1));
    return(lpc_timer_sbyte_fmt_cnt_out_extract(_regval));
}

/*
 * Register sbyte_fmt2: Int. timer 2 status format
 * Type: lpc_timer.sbyte_fmt (Interval timer status byte format)
 *   bcd	(size 1, offset 0, init 0):	RO	Binary coded decimal select
 *   mode	(size 3, offset 1, init 0):	RO	Counter mode
 *   rwsel	(size 2, offset 4, init 0):	RO	Read/write select
 *   cnt_stat	(size 1, offset 6, init 0):	RO	Count register status
 *   cnt_out	(size 1, offset 7, init 0):	RO	Counter OUT pin status
 */
static inline lpc_timer_sbyte_fmt_t lpc_timer_sbyte_fmt2_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_timer_sbyte_fmt_t lpc_timer_sbyte_fmt2_rawrd(__DN(t) *_dev)
{
    return((lpc_timer_sbyte_fmt_t )(io::read8(_dev->base, 0x2)));
}

static inline lpc_timer_sbyte_fmt_t lpc_timer_sbyte_fmt2_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_timer_sbyte_fmt_t lpc_timer_sbyte_fmt2_rd(__DN(t) *_dev)
{
    return((lpc_timer_sbyte_fmt_t )(io::read8(_dev->base, 0x2)));
}

static inline void lpc_timer_sbyte_fmt2_rawwr(__DN(t) *_dev, lpc_timer_sbyte_fmt_t _regval) __attribute__ ((always_inline));
static inline void lpc_timer_sbyte_fmt2_rawwr(__DN(t) *_dev, lpc_timer_sbyte_fmt_t _regval)
{
    io::write8(_dev->base, 0x2, _regval);
}

// Register sbyte_fmt2 is not writeable
static inline dout_t& lpc_timer_sbyte_fmt2_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_timer_sbyte_fmt2_pr(dout_t& _os, __DN(t) *_dev)
{
    lpc_timer_sbyte_fmt_t _regval = (lpc_timer_sbyte_fmt_t )(io::read8(_dev->base, 0x2));
    _os << ("Register sbyte_fmt2 (Int. timer 2 status format): ");
    _os << ("\n");
    ((_os << (" bcd =\t")) << lpc_timer_sbyte_fmt_bcd_extract(_regval)) << ("\t(Binary coded decimal select)\n");
    ((_os << (" mode =\t")) << lpc_timer_sbyte_fmt_mode_extract(_regval)) << ("\t(Counter mode)\n");
    ((_os << (" rwsel =\t")) << lpc_timer_sbyte_fmt_rwsel_extract(_regval)) << ("\t(Read/write select)\n");
    ((_os << (" cnt_stat =\t")) << lpc_timer_sbyte_fmt_cnt_stat_extract(_regval)) << ("\t(Count register status)\n");
    ((_os << (" cnt_out =\t")) << lpc_timer_sbyte_fmt_cnt_out_extract(_regval)) << ("\t(Counter OUT pin status)\n");
    return(_os);
}

static inline uint8_t lpc_timer_sbyte_fmt2_bcd_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_timer_sbyte_fmt2_bcd_rdf(__DN(t) *_dev)
{
    lpc_timer_sbyte_fmt_t _regval = (lpc_timer_sbyte_fmt_t )(io::read8(_dev->base, 0x2));
    return(lpc_timer_sbyte_fmt_bcd_extract(_regval));
}

static inline lpc_timer_cnt_mode_t lpc_timer_sbyte_fmt2_mode_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_timer_cnt_mode_t lpc_timer_sbyte_fmt2_mode_rdf(__DN(t) *_dev)
{
    lpc_timer_sbyte_fmt_t _regval = (lpc_timer_sbyte_fmt_t )(io::read8(_dev->base, 0x2));
    return(lpc_timer_sbyte_fmt_mode_extract(_regval));
}

static inline lpc_timer_timer_rwsel_t lpc_timer_sbyte_fmt2_rwsel_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_timer_timer_rwsel_t lpc_timer_sbyte_fmt2_rwsel_rdf(__DN(t) *_dev)
{
    lpc_timer_sbyte_fmt_t _regval = (lpc_timer_sbyte_fmt_t )(io::read8(_dev->base, 0x2));
    return(lpc_timer_sbyte_fmt_rwsel_extract(_regval));
}

static inline uint8_t lpc_timer_sbyte_fmt2_cnt_stat_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_timer_sbyte_fmt2_cnt_stat_rdf(__DN(t) *_dev)
{
    lpc_timer_sbyte_fmt_t _regval = (lpc_timer_sbyte_fmt_t )(io::read8(_dev->base, 0x2));
    return(lpc_timer_sbyte_fmt_cnt_stat_extract(_regval));
}

static inline uint8_t lpc_timer_sbyte_fmt2_cnt_out_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_timer_sbyte_fmt2_cnt_out_rdf(__DN(t) *_dev)
{
    lpc_timer_sbyte_fmt_t _regval = (lpc_timer_sbyte_fmt_t )(io::read8(_dev->base, 0x2));
    return(lpc_timer_sbyte_fmt_cnt_out_extract(_regval));
}

/*
 * Register cntacc0: Counter 0 access
 * Type: lpc_timer.uint8 (primitive type)
 */
static inline uint8_t lpc_timer_cntacc0_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_timer_cntacc0_rawrd(__DN(t) *_dev)
{
    return((uint8_t )(io::read8(_dev->base, 0x0)));
}

static inline uint8_t lpc_timer_cntacc0_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_timer_cntacc0_rd(__DN(t) *_dev)
{
    return((uint8_t )(io::read8(_dev->base, 0x0)));
}

static inline void lpc_timer_cntacc0_rawwr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_timer_cntacc0_rawwr(__DN(t) *_dev, uint8_t _regval)
{
    io::write8(_dev->base, 0x0, _regval);
}

static inline void lpc_timer_cntacc0_wr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_timer_cntacc0_wr(__DN(t) *_dev, uint8_t _regval)
{
    // No MB0 or RSVD fields present
    // No MB1 fields present
    // No pre-read of register required
    io::write8(_dev->base, 0x0, _regval);
}

static inline dout_t& lpc_timer_cntacc0_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_timer_cntacc0_pr(dout_t& _os, __DN(t) *_dev)
{
    uint8_t _regval = (uint8_t )(io::read8(_dev->base, 0x0));
    _os << ("Register cntacc0 (Counter 0 access): ");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

/*
 * Register cntacc1: Counter 1 access
 * Type: lpc_timer.uint8 (primitive type)
 */
static inline uint8_t lpc_timer_cntacc1_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_timer_cntacc1_rawrd(__DN(t) *_dev)
{
    return((uint8_t )(io::read8(_dev->base, 0x1)));
}

static inline uint8_t lpc_timer_cntacc1_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_timer_cntacc1_rd(__DN(t) *_dev)
{
    return((uint8_t )(io::read8(_dev->base, 0x1)));
}

static inline void lpc_timer_cntacc1_rawwr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_timer_cntacc1_rawwr(__DN(t) *_dev, uint8_t _regval)
{
    io::write8(_dev->base, 0x1, _regval);
}

static inline void lpc_timer_cntacc1_wr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_timer_cntacc1_wr(__DN(t) *_dev, uint8_t _regval)
{
    // No MB0 or RSVD fields present
    // No MB1 fields present
    // No pre-read of register required
    io::write8(_dev->base, 0x1, _regval);
}

static inline dout_t& lpc_timer_cntacc1_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_timer_cntacc1_pr(dout_t& _os, __DN(t) *_dev)
{
    uint8_t _regval = (uint8_t )(io::read8(_dev->base, 0x1));
    _os << ("Register cntacc1 (Counter 1 access): ");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

/*
 * Register cntacc2: Counter 2 access
 * Type: lpc_timer.uint8 (primitive type)
 */
static inline uint8_t lpc_timer_cntacc2_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_timer_cntacc2_rawrd(__DN(t) *_dev)
{
    return((uint8_t )(io::read8(_dev->base, 0x2)));
}

static inline uint8_t lpc_timer_cntacc2_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_timer_cntacc2_rd(__DN(t) *_dev)
{
    return((uint8_t )(io::read8(_dev->base, 0x2)));
}

static inline void lpc_timer_cntacc2_rawwr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_timer_cntacc2_rawwr(__DN(t) *_dev, uint8_t _regval)
{
    io::write8(_dev->base, 0x2, _regval);
}

static inline void lpc_timer_cntacc2_wr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_timer_cntacc2_wr(__DN(t) *_dev, uint8_t _regval)
{
    // No MB0 or RSVD fields present
    // No MB1 fields present
    // No pre-read of register required
    io::write8(_dev->base, 0x2, _regval);
}

static inline dout_t& lpc_timer_cntacc2_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_timer_cntacc2_pr(dout_t& _os, __DN(t) *_dev)
{
    uint8_t _regval = (uint8_t )(io::read8(_dev->base, 0x2));
    _os << ("Register cntacc2 (Counter 2 access): ");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

static inline dout_t& operator<<(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, __DN(t) *_dev)
{
    _os << ("-------------------------\n");
    _os << ("Dump of device lpc_timer (LPC Timer):\n");
    lpc_timer_tcw_pr(_os, _dev);
    lpc_timer_rdbk_cmd_pr(_os, _dev);
    lpc_timer_ltch_cmd_pr(_os, _dev);
    lpc_timer_sbyte_fmt0_pr(_os, _dev);
    lpc_timer_sbyte_fmt1_pr(_os, _dev);
    lpc_timer_sbyte_fmt2_pr(_os, _dev);
    lpc_timer_cntacc0_pr(_os, _dev);
    lpc_timer_cntacc1_pr(_os, _dev);
    lpc_timer_cntacc2_pr(_os, _dev);
    _os << ("End of dump of device lpc_timer\n");
    _os << ("-------------------------\n");
    return(_os);
}

#undef __DN
