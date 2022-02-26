#pragma once
/*
 * Device Definition: LPC IHC PIC function
 * 
 * Automatically Generated from Spec.
 * Using a modified mackerel.
 * 
 * DO NOT EDIT!
 */
#include "util/debug.h"
#include "util/io.h"
#undef __DN
#define __DN(x) lpc_pic ## _ ## x
/*
 * Constants defn: lpc_pic.rrc (Register read command)
 *  - no width specified
 */
HOH_STRONG_TYPEDEF( uint8_t , lpc_pic_rrc_t);
#define lpc_pic_read_irq ((lpc_pic_rrc_t)0x2)
#define lpc_pic_read_is ((lpc_pic_rrc_t)0x3)

static inline const char* lpc_pic_rrc_describe(lpc_pic_rrc_t _e) __attribute__ ((always_inline));
static inline const char* lpc_pic_rrc_describe(lpc_pic_rrc_t _e)
{
    switch ((uint8_t )(_e)) {
    case (uint8_t )(0x2):
        return("read_irq: Read IRQ register");
    case (uint8_t )(0x3):
        return("read_is: Read IS register");
    default:
        return(NULL);
    }
}

static inline dout_t& operator<<(dout_t& _os, lpc_pic_rrc_t _e) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, lpc_pic_rrc_t _e)
{
    const char* d = lpc_pic_rrc_describe(_e);
    if (d) {
        return(_os << d);
    } else {
        return((((_os << ("Unknown constant:")) << ("lpc_pic_rrc_t")) << ("value:")) << ((uint64_t )(_e)));
    }
}

/*
 * Constants defn: lpc_pic.rsleoi (Rotate and EOI codes)
 *  - no width specified
 */
HOH_STRONG_TYPEDEF( uint8_t , lpc_pic_rsleoi_t);
#define lpc_pic_raeoic ((lpc_pic_rsleoi_t)0x0)
#define lpc_pic_eoi ((lpc_pic_rsleoi_t)0x1)
#define lpc_pic_seoi ((lpc_pic_rsleoi_t)0x3)
#define lpc_pic_raeois ((lpc_pic_rsleoi_t)0x4)
#define lpc_pic_reoi ((lpc_pic_rsleoi_t)0x5)
#define lpc_pic_sp ((lpc_pic_rsleoi_t)0x6)
#define lpc_pic_rseoi ((lpc_pic_rsleoi_t)0x7)

static inline const char* lpc_pic_rsleoi_describe(lpc_pic_rsleoi_t _e) __attribute__ ((always_inline));
static inline const char* lpc_pic_rsleoi_describe(lpc_pic_rsleoi_t _e)
{
    switch ((uint8_t )(_e)) {
    case (uint8_t )(0x0):
        return("raeoic: Rotate in auto EOI mode (clear)");
    case (uint8_t )(0x1):
        return("eoi: Non-specific EOI command");
    case (uint8_t )(0x3):
        return("seoi: Specific EOI command");
    case (uint8_t )(0x4):
        return("raeois: Rotate in auto EOI mode (set)");
    case (uint8_t )(0x5):
        return("reoi: Rotate on non-specific EOI command");
    case (uint8_t )(0x6):
        return("sp: Set priority command");
    case (uint8_t )(0x7):
        return("rseoi: Rotate on specific EOI command");
    default:
        return(NULL);
    }
}

static inline dout_t& operator<<(dout_t& _os, lpc_pic_rsleoi_t _e) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, lpc_pic_rsleoi_t _e)
{
    const char* d = lpc_pic_rsleoi_describe(_e);
    if (d) {
        return(_os << d);
    } else {
        return((((_os << ("Unknown constant:")) << ("lpc_pic_rsleoi_t")) << ("value:")) << ((uint64_t )(_e)));
    }
}

/*
 * Register type: lpc_pic_icw1_t
 * Description: Initialization Command Word 1
 * Fields:
 *   _anon0	(size 1, offset 0, init 1):	MB1	_
 *   _anon1	(size 1, offset 1, init 0):	MBZ	_
 *   _anon2	(size 1, offset 2, init 0):	MBZ	_
 *   ltim	(size 1, offset 3, init 0):	NOATTR	Edge / Level bank select (ignored)
 *   _anon4	(size 1, offset 4, init 1):	MB1	_
 *   _anon5	(size 3, offset 5, init 0):	MBZ	_
 */
HOH_STRONG_TYPEDEF( uint8_t , lpc_pic_icw1_t);
#define lpc_pic_icw1_default (lpc_pic_icw1_t )(0x11)
static inline uint8_t lpc_pic_icw1_ltim_extract(lpc_pic_icw1_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_icw1_ltim_extract(lpc_pic_icw1_t _regval)
{
    return((uint8_t )((_regval & 0x8) >> 3));
}

static inline lpc_pic_icw1_t lpc_pic_icw1_ltim_insert(lpc_pic_icw1_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_pic_icw1_t lpc_pic_icw1_ltim_insert(lpc_pic_icw1_t _regval, uint8_t _fieldval)
{
    return((lpc_pic_icw1_t )((_regval & 0xf7) | (0x8 & (((lpc_pic_icw1_t )(_fieldval)) << 3))));
}

static inline dout_t& operator<<(dout_t& _os, lpc_pic_icw1_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, lpc_pic_icw1_t _regval)
{
    ((_os << (" ltim =\t")) << lpc_pic_icw1_ltim_extract(_regval)) << ("\t(Edge / Level bank select (ignored))\n");
    return(_os);
}

/*
 * Register type: lpc_pic_icw2_t
 * Description: Initialization Command Word 2
 * Fields:
 *   req_level	(size 3, offset 0, init 0):	NOATTR	Interrupt request level
 *   base	(size 5, offset 3, init 0):	NOATTR	Interrupt vector base address
 */
HOH_STRONG_TYPEDEF( uint8_t , lpc_pic_icw2_t);
#define lpc_pic_icw2_default (lpc_pic_icw2_t )(0x0)
static inline uint8_t lpc_pic_icw2_req_level_extract(lpc_pic_icw2_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_icw2_req_level_extract(lpc_pic_icw2_t _regval)
{
    return((uint8_t )((_regval & 0x7) >> 0));
}

static inline lpc_pic_icw2_t lpc_pic_icw2_req_level_insert(lpc_pic_icw2_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_pic_icw2_t lpc_pic_icw2_req_level_insert(lpc_pic_icw2_t _regval, uint8_t _fieldval)
{
    return((lpc_pic_icw2_t )((_regval & 0xf8) | (0x7 & (((lpc_pic_icw2_t )(_fieldval)) << 0))));
}

static inline uint8_t lpc_pic_icw2_base_extract(lpc_pic_icw2_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_icw2_base_extract(lpc_pic_icw2_t _regval)
{
    return((uint8_t )((_regval & 0xf8) >> 3));
}

static inline lpc_pic_icw2_t lpc_pic_icw2_base_insert(lpc_pic_icw2_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_pic_icw2_t lpc_pic_icw2_base_insert(lpc_pic_icw2_t _regval, uint8_t _fieldval)
{
    return((lpc_pic_icw2_t )((_regval & 0x7) | (0xf8 & (((lpc_pic_icw2_t )(_fieldval)) << 3))));
}

static inline dout_t& operator<<(dout_t& _os, lpc_pic_icw2_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, lpc_pic_icw2_t _regval)
{
    ((_os << (" req_level =\t")) << lpc_pic_icw2_req_level_extract(_regval)) << ("\t(Interrupt request level)\n");
    ((_os << (" base =\t")) << lpc_pic_icw2_base_extract(_regval)) << ("\t(Interrupt vector base address)\n");
    return(_os);
}

/*
 * Register type: lpc_pic_pic_master_icw3_t
 * Description: Master Controller Initialization Command Word 3
 * Fields:
 *   _anon0	(size 2, offset 0, init 0):	MBZ	_
 *   cascade	(size 1, offset 2, init 0):	NOATTR	Cascaded PIC IRQ connection
 *   _anon3	(size 5, offset 3, init 0):	MBZ	_
 */
HOH_STRONG_TYPEDEF( uint8_t , lpc_pic_pic_master_icw3_t);
#define lpc_pic_pic_master_icw3_default (lpc_pic_pic_master_icw3_t )(0x0)
static inline uint8_t lpc_pic_pic_master_icw3_cascade_extract(lpc_pic_pic_master_icw3_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_pic_master_icw3_cascade_extract(lpc_pic_pic_master_icw3_t _regval)
{
    return((uint8_t )((_regval & 0x4) >> 2));
}

static inline lpc_pic_pic_master_icw3_t lpc_pic_pic_master_icw3_cascade_insert(lpc_pic_pic_master_icw3_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_pic_pic_master_icw3_t lpc_pic_pic_master_icw3_cascade_insert(lpc_pic_pic_master_icw3_t _regval, uint8_t _fieldval)
{
    return((lpc_pic_pic_master_icw3_t )((_regval & 0xfb) | (0x4 & (((lpc_pic_pic_master_icw3_t )(_fieldval)) << 2))));
}

static inline dout_t& operator<<(dout_t& _os, lpc_pic_pic_master_icw3_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, lpc_pic_pic_master_icw3_t _regval)
{
    ((_os << (" cascade =\t")) << lpc_pic_pic_master_icw3_cascade_extract(_regval)) << ("\t(Cascaded PIC IRQ connection)\n");
    return(_os);
}

/*
 * Register type: lpc_pic_pic_slave_icw3_t
 * Description: Slave Controller Initialization Command Word 3
 * Fields:
 *   slave_id	(size 3, offset 0, init 0):	NOATTR	Slave Identification Code
 *   _anon3	(size 5, offset 3, init 0):	MBZ	_
 */
HOH_STRONG_TYPEDEF( uint8_t , lpc_pic_pic_slave_icw3_t);
#define lpc_pic_pic_slave_icw3_default (lpc_pic_pic_slave_icw3_t )(0x0)
static inline uint8_t lpc_pic_pic_slave_icw3_slave_id_extract(lpc_pic_pic_slave_icw3_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_pic_slave_icw3_slave_id_extract(lpc_pic_pic_slave_icw3_t _regval)
{
    return((uint8_t )((_regval & 0x7) >> 0));
}

static inline lpc_pic_pic_slave_icw3_t lpc_pic_pic_slave_icw3_slave_id_insert(lpc_pic_pic_slave_icw3_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_pic_pic_slave_icw3_t lpc_pic_pic_slave_icw3_slave_id_insert(lpc_pic_pic_slave_icw3_t _regval, uint8_t _fieldval)
{
    return((lpc_pic_pic_slave_icw3_t )((_regval & 0xf8) | (0x7 & (((lpc_pic_pic_slave_icw3_t )(_fieldval)) << 0))));
}

static inline dout_t& operator<<(dout_t& _os, lpc_pic_pic_slave_icw3_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, lpc_pic_pic_slave_icw3_t _regval)
{
    ((_os << (" slave_id =\t")) << lpc_pic_pic_slave_icw3_slave_id_extract(_regval)) << ("\t(Slave Identification Code)\n");
    return(_os);
}

/*
 * Register type: lpc_pic_icw4_t
 * Description: Initialization Command Word 4
 * Fields:
 *   _anon0	(size 1, offset 0, init 1):	MB1	_
 *   aeoi	(size 1, offset 1, init 0):	NOATTR	Automatic End of Interrupt
 *   _anon2	(size 1, offset 2, init 0):	MBZ	_
 *   _anon3	(size 1, offset 3, init 0):	MBZ	_
 *   sfnm	(size 1, offset 4, init 0):	NOATTR	Special fully nested mode
 *   _anon5	(size 3, offset 5, init 0):	MBZ	_
 */
HOH_STRONG_TYPEDEF( uint8_t , lpc_pic_icw4_t);
#define lpc_pic_icw4_default (lpc_pic_icw4_t )(0x1)
static inline uint8_t lpc_pic_icw4_aeoi_extract(lpc_pic_icw4_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_icw4_aeoi_extract(lpc_pic_icw4_t _regval)
{
    return((uint8_t )((_regval & 0x2) >> 1));
}

static inline lpc_pic_icw4_t lpc_pic_icw4_aeoi_insert(lpc_pic_icw4_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_pic_icw4_t lpc_pic_icw4_aeoi_insert(lpc_pic_icw4_t _regval, uint8_t _fieldval)
{
    return((lpc_pic_icw4_t )((_regval & 0xfd) | (0x2 & (((lpc_pic_icw4_t )(_fieldval)) << 1))));
}

static inline uint8_t lpc_pic_icw4_sfnm_extract(lpc_pic_icw4_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_icw4_sfnm_extract(lpc_pic_icw4_t _regval)
{
    return((uint8_t )((_regval & 0x10) >> 4));
}

static inline lpc_pic_icw4_t lpc_pic_icw4_sfnm_insert(lpc_pic_icw4_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_pic_icw4_t lpc_pic_icw4_sfnm_insert(lpc_pic_icw4_t _regval, uint8_t _fieldval)
{
    return((lpc_pic_icw4_t )((_regval & 0xef) | (0x10 & (((lpc_pic_icw4_t )(_fieldval)) << 4))));
}

static inline dout_t& operator<<(dout_t& _os, lpc_pic_icw4_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, lpc_pic_icw4_t _regval)
{
    ((_os << (" aeoi =\t")) << lpc_pic_icw4_aeoi_extract(_regval)) << ("\t(Automatic End of Interrupt)\n");
    ((_os << (" sfnm =\t")) << lpc_pic_icw4_sfnm_extract(_regval)) << ("\t(Special fully nested mode)\n");
    return(_os);
}

/*
 * Register type: lpc_pic_ocw2_t
 * Description: Operational Control Word 2
 * Fields:
 *   level	(size 3, offset 0, init 0):	NOATTR	Interrupt level select
 *   _anon3	(size 2, offset 3, init 0):	MBZ	_
 *   rsleoi	(size 3, offset 5, init 0):	NOATTR	Rotate and EOI Codes
 */
HOH_STRONG_TYPEDEF( uint8_t , lpc_pic_ocw2_t);
#define lpc_pic_ocw2_default (lpc_pic_ocw2_t )(0x0)
static inline uint8_t lpc_pic_ocw2_level_extract(lpc_pic_ocw2_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_ocw2_level_extract(lpc_pic_ocw2_t _regval)
{
    return((uint8_t )((_regval & 0x7) >> 0));
}

static inline lpc_pic_ocw2_t lpc_pic_ocw2_level_insert(lpc_pic_ocw2_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_pic_ocw2_t lpc_pic_ocw2_level_insert(lpc_pic_ocw2_t _regval, uint8_t _fieldval)
{
    return((lpc_pic_ocw2_t )((_regval & 0xf8) | (0x7 & (((lpc_pic_ocw2_t )(_fieldval)) << 0))));
}

static inline lpc_pic_rsleoi_t lpc_pic_ocw2_rsleoi_extract(lpc_pic_ocw2_t _regval) __attribute__ ((always_inline));
static inline lpc_pic_rsleoi_t lpc_pic_ocw2_rsleoi_extract(lpc_pic_ocw2_t _regval)
{
    return((lpc_pic_rsleoi_t )((_regval & 0xe0) >> 5));
}

static inline lpc_pic_ocw2_t lpc_pic_ocw2_rsleoi_insert(lpc_pic_ocw2_t _regval, lpc_pic_rsleoi_t _fieldval) __attribute__ ((always_inline));
static inline lpc_pic_ocw2_t lpc_pic_ocw2_rsleoi_insert(lpc_pic_ocw2_t _regval, lpc_pic_rsleoi_t _fieldval)
{
    return((lpc_pic_ocw2_t )((_regval & 0x1f) | (0xe0 & (((lpc_pic_ocw2_t )(_fieldval)) << 5))));
}

static inline dout_t& operator<<(dout_t& _os, lpc_pic_ocw2_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, lpc_pic_ocw2_t _regval)
{
    ((_os << (" level =\t")) << lpc_pic_ocw2_level_extract(_regval)) << ("\t(Interrupt level select)\n");
    ((_os << (" rsleoi =\t")) << lpc_pic_ocw2_rsleoi_extract(_regval)) << ("\t(Rotate and EOI Codes)\n");
    return(_os);
}

/*
 * Register type: lpc_pic_ocw3_t
 * Description: Operational Control Word 3
 * Fields:
 *   rrc	(size 2, offset 0, init 0):	NOATTR	Register read command
 *   pmc	(size 1, offset 2, init 0):	NOATTR	Poll mode command
 *   _anon3	(size 1, offset 3, init 1):	MB1	_
 *   _anon4	(size 1, offset 4, init 0):	MBZ	_
 *   esmm	(size 1, offset 5, init 0):	NOATTR	Enable special mask mode
 *   smm	(size 1, offset 6, init 0):	NOATTR	Special mask mode
 *   _anon7	(size 1, offset 7, init 0):	MBZ	_
 */
HOH_STRONG_TYPEDEF( uint8_t , lpc_pic_ocw3_t);
#define lpc_pic_ocw3_default (lpc_pic_ocw3_t )(0x8)
static inline lpc_pic_rrc_t lpc_pic_ocw3_rrc_extract(lpc_pic_ocw3_t _regval) __attribute__ ((always_inline));
static inline lpc_pic_rrc_t lpc_pic_ocw3_rrc_extract(lpc_pic_ocw3_t _regval)
{
    return((lpc_pic_rrc_t )((_regval & 0x3) >> 0));
}

static inline lpc_pic_ocw3_t lpc_pic_ocw3_rrc_insert(lpc_pic_ocw3_t _regval, lpc_pic_rrc_t _fieldval) __attribute__ ((always_inline));
static inline lpc_pic_ocw3_t lpc_pic_ocw3_rrc_insert(lpc_pic_ocw3_t _regval, lpc_pic_rrc_t _fieldval)
{
    return((lpc_pic_ocw3_t )((_regval & 0xfc) | (0x3 & (((lpc_pic_ocw3_t )(_fieldval)) << 0))));
}

static inline uint8_t lpc_pic_ocw3_pmc_extract(lpc_pic_ocw3_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_ocw3_pmc_extract(lpc_pic_ocw3_t _regval)
{
    return((uint8_t )((_regval & 0x4) >> 2));
}

static inline lpc_pic_ocw3_t lpc_pic_ocw3_pmc_insert(lpc_pic_ocw3_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_pic_ocw3_t lpc_pic_ocw3_pmc_insert(lpc_pic_ocw3_t _regval, uint8_t _fieldval)
{
    return((lpc_pic_ocw3_t )((_regval & 0xfb) | (0x4 & (((lpc_pic_ocw3_t )(_fieldval)) << 2))));
}

static inline uint8_t lpc_pic_ocw3_esmm_extract(lpc_pic_ocw3_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_ocw3_esmm_extract(lpc_pic_ocw3_t _regval)
{
    return((uint8_t )((_regval & 0x20) >> 5));
}

static inline lpc_pic_ocw3_t lpc_pic_ocw3_esmm_insert(lpc_pic_ocw3_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_pic_ocw3_t lpc_pic_ocw3_esmm_insert(lpc_pic_ocw3_t _regval, uint8_t _fieldval)
{
    return((lpc_pic_ocw3_t )((_regval & 0xdf) | (0x20 & (((lpc_pic_ocw3_t )(_fieldval)) << 5))));
}

static inline uint8_t lpc_pic_ocw3_smm_extract(lpc_pic_ocw3_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_ocw3_smm_extract(lpc_pic_ocw3_t _regval)
{
    return((uint8_t )((_regval & 0x40) >> 6));
}

static inline lpc_pic_ocw3_t lpc_pic_ocw3_smm_insert(lpc_pic_ocw3_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_pic_ocw3_t lpc_pic_ocw3_smm_insert(lpc_pic_ocw3_t _regval, uint8_t _fieldval)
{
    return((lpc_pic_ocw3_t )((_regval & 0xbf) | (0x40 & (((lpc_pic_ocw3_t )(_fieldval)) << 6))));
}

static inline dout_t& operator<<(dout_t& _os, lpc_pic_ocw3_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, lpc_pic_ocw3_t _regval)
{
    ((_os << (" rrc =\t")) << lpc_pic_ocw3_rrc_extract(_regval)) << ("\t(Register read command)\n");
    ((_os << (" pmc =\t")) << lpc_pic_ocw3_pmc_extract(_regval)) << ("\t(Poll mode command)\n");
    ((_os << (" esmm =\t")) << lpc_pic_ocw3_esmm_extract(_regval)) << ("\t(Enable special mask mode)\n");
    ((_os << (" smm =\t")) << lpc_pic_ocw3_smm_extract(_regval)) << ("\t(Special mask mode)\n");
    return(_os);
}

/*
 * Register type: lpc_pic_pic_master_trigger_t
 * Description: Master Controller Edge/Level Triggered
 * Fields:
 *   _anon0	(size 3, offset 0, init 0):	MBZ	_
 *   irq3_ecl	(size 1, offset 3, init 0):	NOATTR	IRQ3 ECL
 *   irq4_ecl	(size 1, offset 4, init 0):	NOATTR	IRQ4 ECL
 *   irq5_ecl	(size 1, offset 5, init 0):	NOATTR	IRQ5 ECL
 *   irq6_ecl	(size 1, offset 6, init 0):	NOATTR	IRQ6 ECL
 *   irq7_ecl	(size 1, offset 7, init 0):	NOATTR	IRQ7 ECL
 */
HOH_STRONG_TYPEDEF( uint8_t , lpc_pic_pic_master_trigger_t);
#define lpc_pic_pic_master_trigger_default (lpc_pic_pic_master_trigger_t )(0x0)
static inline uint8_t lpc_pic_pic_master_trigger_irq3_ecl_extract(lpc_pic_pic_master_trigger_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_pic_master_trigger_irq3_ecl_extract(lpc_pic_pic_master_trigger_t _regval)
{
    return((uint8_t )((_regval & 0x8) >> 3));
}

static inline lpc_pic_pic_master_trigger_t lpc_pic_pic_master_trigger_irq3_ecl_insert(lpc_pic_pic_master_trigger_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_pic_pic_master_trigger_t lpc_pic_pic_master_trigger_irq3_ecl_insert(lpc_pic_pic_master_trigger_t _regval, uint8_t _fieldval)
{
    return((lpc_pic_pic_master_trigger_t )((_regval & 0xf7) | (0x8 & (((lpc_pic_pic_master_trigger_t )(_fieldval)) << 3))));
}

static inline uint8_t lpc_pic_pic_master_trigger_irq4_ecl_extract(lpc_pic_pic_master_trigger_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_pic_master_trigger_irq4_ecl_extract(lpc_pic_pic_master_trigger_t _regval)
{
    return((uint8_t )((_regval & 0x10) >> 4));
}

static inline lpc_pic_pic_master_trigger_t lpc_pic_pic_master_trigger_irq4_ecl_insert(lpc_pic_pic_master_trigger_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_pic_pic_master_trigger_t lpc_pic_pic_master_trigger_irq4_ecl_insert(lpc_pic_pic_master_trigger_t _regval, uint8_t _fieldval)
{
    return((lpc_pic_pic_master_trigger_t )((_regval & 0xef) | (0x10 & (((lpc_pic_pic_master_trigger_t )(_fieldval)) << 4))));
}

static inline uint8_t lpc_pic_pic_master_trigger_irq5_ecl_extract(lpc_pic_pic_master_trigger_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_pic_master_trigger_irq5_ecl_extract(lpc_pic_pic_master_trigger_t _regval)
{
    return((uint8_t )((_regval & 0x20) >> 5));
}

static inline lpc_pic_pic_master_trigger_t lpc_pic_pic_master_trigger_irq5_ecl_insert(lpc_pic_pic_master_trigger_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_pic_pic_master_trigger_t lpc_pic_pic_master_trigger_irq5_ecl_insert(lpc_pic_pic_master_trigger_t _regval, uint8_t _fieldval)
{
    return((lpc_pic_pic_master_trigger_t )((_regval & 0xdf) | (0x20 & (((lpc_pic_pic_master_trigger_t )(_fieldval)) << 5))));
}

static inline uint8_t lpc_pic_pic_master_trigger_irq6_ecl_extract(lpc_pic_pic_master_trigger_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_pic_master_trigger_irq6_ecl_extract(lpc_pic_pic_master_trigger_t _regval)
{
    return((uint8_t )((_regval & 0x40) >> 6));
}

static inline lpc_pic_pic_master_trigger_t lpc_pic_pic_master_trigger_irq6_ecl_insert(lpc_pic_pic_master_trigger_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_pic_pic_master_trigger_t lpc_pic_pic_master_trigger_irq6_ecl_insert(lpc_pic_pic_master_trigger_t _regval, uint8_t _fieldval)
{
    return((lpc_pic_pic_master_trigger_t )((_regval & 0xbf) | (0x40 & (((lpc_pic_pic_master_trigger_t )(_fieldval)) << 6))));
}

static inline uint8_t lpc_pic_pic_master_trigger_irq7_ecl_extract(lpc_pic_pic_master_trigger_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_pic_master_trigger_irq7_ecl_extract(lpc_pic_pic_master_trigger_t _regval)
{
    return((uint8_t )((_regval & 0x80) >> 7));
}

static inline lpc_pic_pic_master_trigger_t lpc_pic_pic_master_trigger_irq7_ecl_insert(lpc_pic_pic_master_trigger_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_pic_pic_master_trigger_t lpc_pic_pic_master_trigger_irq7_ecl_insert(lpc_pic_pic_master_trigger_t _regval, uint8_t _fieldval)
{
    return((lpc_pic_pic_master_trigger_t )((_regval & 0x7f) | (0x80 & (((lpc_pic_pic_master_trigger_t )(_fieldval)) << 7))));
}

static inline dout_t& operator<<(dout_t& _os, lpc_pic_pic_master_trigger_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, lpc_pic_pic_master_trigger_t _regval)
{
    ((_os << (" irq3_ecl =\t")) << lpc_pic_pic_master_trigger_irq3_ecl_extract(_regval)) << ("\t(IRQ3 ECL)\n");
    ((_os << (" irq4_ecl =\t")) << lpc_pic_pic_master_trigger_irq4_ecl_extract(_regval)) << ("\t(IRQ4 ECL)\n");
    ((_os << (" irq5_ecl =\t")) << lpc_pic_pic_master_trigger_irq5_ecl_extract(_regval)) << ("\t(IRQ5 ECL)\n");
    ((_os << (" irq6_ecl =\t")) << lpc_pic_pic_master_trigger_irq6_ecl_extract(_regval)) << ("\t(IRQ6 ECL)\n");
    ((_os << (" irq7_ecl =\t")) << lpc_pic_pic_master_trigger_irq7_ecl_extract(_regval)) << ("\t(IRQ7 ECL)\n");
    return(_os);
}

/*
 * Register type: lpc_pic_pic_slave_trigger_t
 * Description: Slave Controller Edge/Level Triggered
 * Fields:
 *   _anon0	(size 1, offset 0, init 0):	MBZ	_
 *   irq9_ecl	(size 1, offset 1, init 0):	NOATTR	IRQ9 ECL
 *   irq10_ecl	(size 1, offset 2, init 0):	NOATTR	IRQ10 ECL
 *   irq11_ecl	(size 1, offset 3, init 0):	NOATTR	IRQ11 ECL
 *   irq12_ecl	(size 1, offset 4, init 0):	NOATTR	IRQ12 ECL
 *   _anon5	(size 1, offset 5, init 0):	MBZ	_
 *   irq14_ecl	(size 1, offset 6, init 0):	NOATTR	IRQ14 ECL
 *   irq15_ecl	(size 1, offset 7, init 0):	NOATTR	IRQ15 ECL
 */
HOH_STRONG_TYPEDEF( uint8_t , lpc_pic_pic_slave_trigger_t);
#define lpc_pic_pic_slave_trigger_default (lpc_pic_pic_slave_trigger_t )(0x0)
static inline uint8_t lpc_pic_pic_slave_trigger_irq9_ecl_extract(lpc_pic_pic_slave_trigger_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_pic_slave_trigger_irq9_ecl_extract(lpc_pic_pic_slave_trigger_t _regval)
{
    return((uint8_t )((_regval & 0x2) >> 1));
}

static inline lpc_pic_pic_slave_trigger_t lpc_pic_pic_slave_trigger_irq9_ecl_insert(lpc_pic_pic_slave_trigger_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_pic_pic_slave_trigger_t lpc_pic_pic_slave_trigger_irq9_ecl_insert(lpc_pic_pic_slave_trigger_t _regval, uint8_t _fieldval)
{
    return((lpc_pic_pic_slave_trigger_t )((_regval & 0xfd) | (0x2 & (((lpc_pic_pic_slave_trigger_t )(_fieldval)) << 1))));
}

static inline uint8_t lpc_pic_pic_slave_trigger_irq10_ecl_extract(lpc_pic_pic_slave_trigger_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_pic_slave_trigger_irq10_ecl_extract(lpc_pic_pic_slave_trigger_t _regval)
{
    return((uint8_t )((_regval & 0x4) >> 2));
}

static inline lpc_pic_pic_slave_trigger_t lpc_pic_pic_slave_trigger_irq10_ecl_insert(lpc_pic_pic_slave_trigger_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_pic_pic_slave_trigger_t lpc_pic_pic_slave_trigger_irq10_ecl_insert(lpc_pic_pic_slave_trigger_t _regval, uint8_t _fieldval)
{
    return((lpc_pic_pic_slave_trigger_t )((_regval & 0xfb) | (0x4 & (((lpc_pic_pic_slave_trigger_t )(_fieldval)) << 2))));
}

static inline uint8_t lpc_pic_pic_slave_trigger_irq11_ecl_extract(lpc_pic_pic_slave_trigger_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_pic_slave_trigger_irq11_ecl_extract(lpc_pic_pic_slave_trigger_t _regval)
{
    return((uint8_t )((_regval & 0x8) >> 3));
}

static inline lpc_pic_pic_slave_trigger_t lpc_pic_pic_slave_trigger_irq11_ecl_insert(lpc_pic_pic_slave_trigger_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_pic_pic_slave_trigger_t lpc_pic_pic_slave_trigger_irq11_ecl_insert(lpc_pic_pic_slave_trigger_t _regval, uint8_t _fieldval)
{
    return((lpc_pic_pic_slave_trigger_t )((_regval & 0xf7) | (0x8 & (((lpc_pic_pic_slave_trigger_t )(_fieldval)) << 3))));
}

static inline uint8_t lpc_pic_pic_slave_trigger_irq12_ecl_extract(lpc_pic_pic_slave_trigger_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_pic_slave_trigger_irq12_ecl_extract(lpc_pic_pic_slave_trigger_t _regval)
{
    return((uint8_t )((_regval & 0x10) >> 4));
}

static inline lpc_pic_pic_slave_trigger_t lpc_pic_pic_slave_trigger_irq12_ecl_insert(lpc_pic_pic_slave_trigger_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_pic_pic_slave_trigger_t lpc_pic_pic_slave_trigger_irq12_ecl_insert(lpc_pic_pic_slave_trigger_t _regval, uint8_t _fieldval)
{
    return((lpc_pic_pic_slave_trigger_t )((_regval & 0xef) | (0x10 & (((lpc_pic_pic_slave_trigger_t )(_fieldval)) << 4))));
}

static inline uint8_t lpc_pic_pic_slave_trigger_irq14_ecl_extract(lpc_pic_pic_slave_trigger_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_pic_slave_trigger_irq14_ecl_extract(lpc_pic_pic_slave_trigger_t _regval)
{
    return((uint8_t )((_regval & 0x40) >> 6));
}

static inline lpc_pic_pic_slave_trigger_t lpc_pic_pic_slave_trigger_irq14_ecl_insert(lpc_pic_pic_slave_trigger_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_pic_pic_slave_trigger_t lpc_pic_pic_slave_trigger_irq14_ecl_insert(lpc_pic_pic_slave_trigger_t _regval, uint8_t _fieldval)
{
    return((lpc_pic_pic_slave_trigger_t )((_regval & 0xbf) | (0x40 & (((lpc_pic_pic_slave_trigger_t )(_fieldval)) << 6))));
}

static inline uint8_t lpc_pic_pic_slave_trigger_irq15_ecl_extract(lpc_pic_pic_slave_trigger_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_pic_slave_trigger_irq15_ecl_extract(lpc_pic_pic_slave_trigger_t _regval)
{
    return((uint8_t )((_regval & 0x80) >> 7));
}

static inline lpc_pic_pic_slave_trigger_t lpc_pic_pic_slave_trigger_irq15_ecl_insert(lpc_pic_pic_slave_trigger_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_pic_pic_slave_trigger_t lpc_pic_pic_slave_trigger_irq15_ecl_insert(lpc_pic_pic_slave_trigger_t _regval, uint8_t _fieldval)
{
    return((lpc_pic_pic_slave_trigger_t )((_regval & 0x7f) | (0x80 & (((lpc_pic_pic_slave_trigger_t )(_fieldval)) << 7))));
}

static inline dout_t& operator<<(dout_t& _os, lpc_pic_pic_slave_trigger_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, lpc_pic_pic_slave_trigger_t _regval)
{
    ((_os << (" irq9_ecl =\t")) << lpc_pic_pic_slave_trigger_irq9_ecl_extract(_regval)) << ("\t(IRQ9 ECL)\n");
    ((_os << (" irq10_ecl =\t")) << lpc_pic_pic_slave_trigger_irq10_ecl_extract(_regval)) << ("\t(IRQ10 ECL)\n");
    ((_os << (" irq11_ecl =\t")) << lpc_pic_pic_slave_trigger_irq11_ecl_extract(_regval)) << ("\t(IRQ11 ECL)\n");
    ((_os << (" irq12_ecl =\t")) << lpc_pic_pic_slave_trigger_irq12_ecl_extract(_regval)) << ("\t(IRQ12 ECL)\n");
    ((_os << (" irq14_ecl =\t")) << lpc_pic_pic_slave_trigger_irq14_ecl_extract(_regval)) << ("\t(IRQ14 ECL)\n");
    ((_os << (" irq15_ecl =\t")) << lpc_pic_pic_slave_trigger_irq15_ecl_extract(_regval)) << ("\t(IRQ15 ECL)\n");
    return(_os);
}

/*
 * Device representation structure
 */
struct __DN(t) {
    io_t base;
    lpc_pic_icw1_t master_icw1_shadow;
    lpc_pic_ocw2_t master_ocw2_shadow;
    lpc_pic_ocw3_t master_ocw3_shadow;
    lpc_pic_icw2_t master_icw2_shadow;
    lpc_pic_pic_master_icw3_t master_icw3_shadow;
    lpc_pic_icw4_t master_icw4_shadow;
    lpc_pic_icw1_t slave_icw1_shadow;
    lpc_pic_ocw2_t slave_ocw2_shadow;
    lpc_pic_ocw3_t slave_ocw3_shadow;
    lpc_pic_icw2_t slave_icw2_shadow;
    lpc_pic_pic_slave_icw3_t slave_icw3_shadow;
    lpc_pic_icw4_t slave_icw4_shadow;
};

/*
 * Initial register values (currently 0)
 */
enum lpc_pic_initials {
    lpc_pic_master_icw1_initial = 0x0,
    lpc_pic_master_ocw2_initial = 0x0,
    lpc_pic_master_ocw3_initial = 0x0,
    lpc_pic_master_ocw3rd_initial = 0x0,
    lpc_pic_master_icw2_initial = 0x0,
    lpc_pic_master_icw3_initial = 0x0,
    lpc_pic_master_icw4_initial = 0x0,
    lpc_pic_master_ocw1_initial = 0x0,
    lpc_pic_slave_icw1_initial = 0x0,
    lpc_pic_slave_ocw2_initial = 0x0,
    lpc_pic_slave_ocw3_initial = 0x0,
    lpc_pic_slave_ocw3rd_initial = 0x0,
    lpc_pic_slave_icw2_initial = 0x0,
    lpc_pic_slave_icw3_initial = 0x0,
    lpc_pic_slave_icw4_initial = 0x0,
    lpc_pic_slave_ocw1_initial = 0x0,
    lpc_pic_master_trigger_initial = 0x0,
    lpc_pic_slave_trigger_initial = 0x0
};

/*
 * Device Initialization function
 */
static inline void lpc_pic_initialize(__DN(t) *_dev, io_t base) __attribute__ ((always_inline));
static inline void lpc_pic_initialize(__DN(t) *_dev, io_t base)
{
    _dev->base = base;
}

/*
 * No user-defined spaces
 */
/*
 * Register master_icw1: Master PIC Initialization Command Word 1
 * Type: lpc_pic.icw1 (Initialization Command Word 1)
 *   _anon0	(size 1, offset 0, init 1):	MB1	_
 *   _anon1	(size 1, offset 1, init 0):	MBZ	_
 *   _anon2	(size 1, offset 2, init 0):	MBZ	_
 *   ltim	(size 1, offset 3, init 0):	WO	Edge / Level bank select (ignored)
 *   _anon4	(size 1, offset 4, init 1):	MB1	_
 *   _anon5	(size 3, offset 5, init 0):	MBZ	_
 */
static inline lpc_pic_icw1_t lpc_pic_master_icw1_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_pic_icw1_t lpc_pic_master_icw1_rawrd(__DN(t) *_dev)
{
    return((lpc_pic_icw1_t )(io::read8(_dev->base, 0x20)));
}

static inline lpc_pic_icw1_t lpc_pic_master_icw1_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_pic_icw1_t lpc_pic_master_icw1_rd(__DN(t) *_dev)
{
    return(_dev->master_icw1_shadow);
}

static inline void lpc_pic_master_icw1_rawwr(__DN(t) *_dev, lpc_pic_icw1_t _regval) __attribute__ ((always_inline));
static inline void lpc_pic_master_icw1_rawwr(__DN(t) *_dev, lpc_pic_icw1_t _regval)
{
    io::write8(_dev->base, 0x20, _regval);
}

static inline void lpc_pic_master_icw1_wr(__DN(t) *_dev, lpc_pic_icw1_t _regval) __attribute__ ((always_inline));
static inline void lpc_pic_master_icw1_wr(__DN(t) *_dev, lpc_pic_icw1_t _regval)
{
    _regval = (_regval & 0x19);
    _regval = (_regval | 0x11);
    // No pre-read of register required
    io::write8(_dev->base, 0x20, _regval);
}

static inline dout_t& lpc_pic_master_icw1_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_pic_master_icw1_pr(dout_t& _os, __DN(t) *_dev)
{
    lpc_pic_icw1_t _regval = _dev->master_icw1_shadow;
    _os << ("Register master_icw1 (Master PIC Initialization Command Word 1): ");
    _os << ("\n");
    // _anon0 is anonymous
    // _anon1 is anonymous
    // _anon2 is anonymous
    ((_os << (" ltim =\t")) << lpc_pic_icw1_ltim_extract(_regval)) << ("\t(Edge / Level bank select (ignored))\n");
    // _anon4 is anonymous
    // _anon5 is anonymous
    return(_os);
}

static inline uint8_t lpc_pic_master_icw1_ltim_rd_shadow(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_master_icw1_ltim_rd_shadow(__DN(t) *_dev)
{
    return(lpc_pic_icw1_ltim_extract(_dev->master_icw1_shadow));
}

static inline void lpc_pic_master_icw1_ltim_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_pic_master_icw1_ltim_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_pic_icw1_t _regval = (lpc_pic_icw1_t )(0x8 & (((lpc_pic_icw1_t )(_fieldval)) << 3));
    // No pre-read of register required
    // No read of register shadow required
    _regval = (_regval & 0x19);
    _regval = (_regval | 0x11);
    io::write8(_dev->base, 0x20, _regval);
    _dev->master_icw1_shadow = _regval;
}

/*
 * Register master_ocw2: Master PIC Op Ctrl Word 2
 * Type: lpc_pic.ocw2 (Operational Control Word 2)
 *   level	(size 3, offset 0, init 0):	WO	Interrupt level select
 *   _anon3	(size 2, offset 3, init 0):	MBZ	_
 *   rsleoi	(size 3, offset 5, init 0):	WO	Rotate and EOI Codes
 */
static inline lpc_pic_ocw2_t lpc_pic_master_ocw2_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_pic_ocw2_t lpc_pic_master_ocw2_rawrd(__DN(t) *_dev)
{
    return((lpc_pic_ocw2_t )(io::read8(_dev->base, 0x20)));
}

static inline lpc_pic_ocw2_t lpc_pic_master_ocw2_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_pic_ocw2_t lpc_pic_master_ocw2_rd(__DN(t) *_dev)
{
    return(_dev->master_ocw2_shadow);
}

static inline void lpc_pic_master_ocw2_rawwr(__DN(t) *_dev, lpc_pic_ocw2_t _regval) __attribute__ ((always_inline));
static inline void lpc_pic_master_ocw2_rawwr(__DN(t) *_dev, lpc_pic_ocw2_t _regval)
{
    io::write8(_dev->base, 0x20, _regval);
}

static inline void lpc_pic_master_ocw2_wr(__DN(t) *_dev, lpc_pic_ocw2_t _regval) __attribute__ ((always_inline));
static inline void lpc_pic_master_ocw2_wr(__DN(t) *_dev, lpc_pic_ocw2_t _regval)
{
    _regval = (_regval & 0xe7);
    // No MB1 fields present
    // No pre-read of register required
    io::write8(_dev->base, 0x20, _regval);
}

static inline dout_t& lpc_pic_master_ocw2_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_pic_master_ocw2_pr(dout_t& _os, __DN(t) *_dev)
{
    lpc_pic_ocw2_t _regval = _dev->master_ocw2_shadow;
    _os << ("Register master_ocw2 (Master PIC Op Ctrl Word 2): ");
    _os << ("\n");
    ((_os << (" level =\t")) << lpc_pic_ocw2_level_extract(_regval)) << ("\t(Interrupt level select)\n");
    // _anon3 is anonymous
    ((_os << (" rsleoi =\t")) << lpc_pic_ocw2_rsleoi_extract(_regval)) << ("\t(Rotate and EOI Codes)\n");
    return(_os);
}

static inline uint8_t lpc_pic_master_ocw2_level_rd_shadow(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_master_ocw2_level_rd_shadow(__DN(t) *_dev)
{
    return(lpc_pic_ocw2_level_extract(_dev->master_ocw2_shadow));
}

static inline lpc_pic_rsleoi_t lpc_pic_master_ocw2_rsleoi_rd_shadow(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_pic_rsleoi_t lpc_pic_master_ocw2_rsleoi_rd_shadow(__DN(t) *_dev)
{
    return(lpc_pic_ocw2_rsleoi_extract(_dev->master_ocw2_shadow));
}

static inline void lpc_pic_master_ocw2_level_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_pic_master_ocw2_level_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_pic_ocw2_t _regval = (lpc_pic_ocw2_t )(0x7 & (((lpc_pic_ocw2_t )(_fieldval)) << 0));
    // No pre-read of register required
    _regval = (_regval | (0xe0 & (_dev->master_ocw2_shadow)));
    _regval = (_regval & 0xe7);
    // No MB1 fields present
    io::write8(_dev->base, 0x20, _regval);
    _dev->master_ocw2_shadow = _regval;
}

static inline void lpc_pic_master_ocw2_rsleoi_wrf(__DN(t) *_dev, lpc_pic_rsleoi_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_pic_master_ocw2_rsleoi_wrf(__DN(t) *_dev, lpc_pic_rsleoi_t _fieldval)
{
    lpc_pic_ocw2_t _regval = (lpc_pic_ocw2_t )(0xe0 & (((lpc_pic_ocw2_t )(_fieldval)) << 5));
    // No pre-read of register required
    _regval = (_regval | (0x7 & (_dev->master_ocw2_shadow)));
    _regval = (_regval & 0xe7);
    // No MB1 fields present
    io::write8(_dev->base, 0x20, _regval);
    _dev->master_ocw2_shadow = _regval;
}

/*
 * Register master_ocw3: Master PIC Op Ctrl Word 3
 * Type: lpc_pic.ocw3 (Operational Control Word 3)
 *   rrc	(size 2, offset 0, init 0):	WO	Register read command
 *   pmc	(size 1, offset 2, init 0):	WO	Poll mode command
 *   _anon3	(size 1, offset 3, init 1):	MB1	_
 *   _anon4	(size 1, offset 4, init 0):	MBZ	_
 *   esmm	(size 1, offset 5, init 0):	WO	Enable special mask mode
 *   smm	(size 1, offset 6, init 0):	WO	Special mask mode
 *   _anon7	(size 1, offset 7, init 0):	MBZ	_
 */
static inline lpc_pic_ocw3_t lpc_pic_master_ocw3_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_pic_ocw3_t lpc_pic_master_ocw3_rawrd(__DN(t) *_dev)
{
    return((lpc_pic_ocw3_t )(io::read8(_dev->base, 0x20)));
}

static inline lpc_pic_ocw3_t lpc_pic_master_ocw3_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_pic_ocw3_t lpc_pic_master_ocw3_rd(__DN(t) *_dev)
{
    return(_dev->master_ocw3_shadow);
}

static inline void lpc_pic_master_ocw3_rawwr(__DN(t) *_dev, lpc_pic_ocw3_t _regval) __attribute__ ((always_inline));
static inline void lpc_pic_master_ocw3_rawwr(__DN(t) *_dev, lpc_pic_ocw3_t _regval)
{
    io::write8(_dev->base, 0x20, _regval);
}

static inline void lpc_pic_master_ocw3_wr(__DN(t) *_dev, lpc_pic_ocw3_t _regval) __attribute__ ((always_inline));
static inline void lpc_pic_master_ocw3_wr(__DN(t) *_dev, lpc_pic_ocw3_t _regval)
{
    _regval = (_regval & 0x6f);
    _regval = (_regval | 0x8);
    // No pre-read of register required
    io::write8(_dev->base, 0x20, _regval);
}

static inline dout_t& lpc_pic_master_ocw3_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_pic_master_ocw3_pr(dout_t& _os, __DN(t) *_dev)
{
    lpc_pic_ocw3_t _regval = _dev->master_ocw3_shadow;
    _os << ("Register master_ocw3 (Master PIC Op Ctrl Word 3): ");
    _os << ("\n");
    ((_os << (" rrc =\t")) << lpc_pic_ocw3_rrc_extract(_regval)) << ("\t(Register read command)\n");
    ((_os << (" pmc =\t")) << lpc_pic_ocw3_pmc_extract(_regval)) << ("\t(Poll mode command)\n");
    // _anon3 is anonymous
    // _anon4 is anonymous
    ((_os << (" esmm =\t")) << lpc_pic_ocw3_esmm_extract(_regval)) << ("\t(Enable special mask mode)\n");
    ((_os << (" smm =\t")) << lpc_pic_ocw3_smm_extract(_regval)) << ("\t(Special mask mode)\n");
    // _anon7 is anonymous
    return(_os);
}

static inline lpc_pic_rrc_t lpc_pic_master_ocw3_rrc_rd_shadow(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_pic_rrc_t lpc_pic_master_ocw3_rrc_rd_shadow(__DN(t) *_dev)
{
    return(lpc_pic_ocw3_rrc_extract(_dev->master_ocw3_shadow));
}

static inline uint8_t lpc_pic_master_ocw3_pmc_rd_shadow(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_master_ocw3_pmc_rd_shadow(__DN(t) *_dev)
{
    return(lpc_pic_ocw3_pmc_extract(_dev->master_ocw3_shadow));
}

static inline uint8_t lpc_pic_master_ocw3_esmm_rd_shadow(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_master_ocw3_esmm_rd_shadow(__DN(t) *_dev)
{
    return(lpc_pic_ocw3_esmm_extract(_dev->master_ocw3_shadow));
}

static inline uint8_t lpc_pic_master_ocw3_smm_rd_shadow(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_master_ocw3_smm_rd_shadow(__DN(t) *_dev)
{
    return(lpc_pic_ocw3_smm_extract(_dev->master_ocw3_shadow));
}

static inline void lpc_pic_master_ocw3_rrc_wrf(__DN(t) *_dev, lpc_pic_rrc_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_pic_master_ocw3_rrc_wrf(__DN(t) *_dev, lpc_pic_rrc_t _fieldval)
{
    lpc_pic_ocw3_t _regval = (lpc_pic_ocw3_t )(0x3 & (((lpc_pic_ocw3_t )(_fieldval)) << 0));
    // No pre-read of register required
    _regval = (_regval | (0x64 & (_dev->master_ocw3_shadow)));
    _regval = (_regval & 0x6f);
    _regval = (_regval | 0x8);
    io::write8(_dev->base, 0x20, _regval);
    _dev->master_ocw3_shadow = _regval;
}

static inline void lpc_pic_master_ocw3_pmc_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_pic_master_ocw3_pmc_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_pic_ocw3_t _regval = (lpc_pic_ocw3_t )(0x4 & (((lpc_pic_ocw3_t )(_fieldval)) << 2));
    // No pre-read of register required
    _regval = (_regval | (0x63 & (_dev->master_ocw3_shadow)));
    _regval = (_regval & 0x6f);
    _regval = (_regval | 0x8);
    io::write8(_dev->base, 0x20, _regval);
    _dev->master_ocw3_shadow = _regval;
}

static inline void lpc_pic_master_ocw3_esmm_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_pic_master_ocw3_esmm_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_pic_ocw3_t _regval = (lpc_pic_ocw3_t )(0x20 & (((lpc_pic_ocw3_t )(_fieldval)) << 5));
    // No pre-read of register required
    _regval = (_regval | (0x47 & (_dev->master_ocw3_shadow)));
    _regval = (_regval & 0x6f);
    _regval = (_regval | 0x8);
    io::write8(_dev->base, 0x20, _regval);
    _dev->master_ocw3_shadow = _regval;
}

static inline void lpc_pic_master_ocw3_smm_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_pic_master_ocw3_smm_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_pic_ocw3_t _regval = (lpc_pic_ocw3_t )(0x40 & (((lpc_pic_ocw3_t )(_fieldval)) << 6));
    // No pre-read of register required
    _regval = (_regval | (0x27 & (_dev->master_ocw3_shadow)));
    _regval = (_regval & 0x6f);
    _regval = (_regval | 0x8);
    io::write8(_dev->base, 0x20, _regval);
    _dev->master_ocw3_shadow = _regval;
}

/*
 * Register master_ocw3rd: Master PIC Op Ctrl Word 3
 * Type: lpc_pic.uint8 (primitive type)
 */
static inline uint8_t lpc_pic_master_ocw3rd_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_master_ocw3rd_rawrd(__DN(t) *_dev)
{
    return((uint8_t )(io::read8(_dev->base, 0x20)));
}

static inline uint8_t lpc_pic_master_ocw3rd_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_master_ocw3rd_rd(__DN(t) *_dev)
{
    return((uint8_t )(io::read8(_dev->base, 0x20)));
}

static inline void lpc_pic_master_ocw3rd_rawwr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_pic_master_ocw3rd_rawwr(__DN(t) *_dev, uint8_t _regval)
{
    io::write8(_dev->base, 0x20, _regval);
}

// Register master_ocw3rd is not writeable
static inline dout_t& lpc_pic_master_ocw3rd_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_pic_master_ocw3rd_pr(dout_t& _os, __DN(t) *_dev)
{
    uint8_t _regval = (uint8_t )(io::read8(_dev->base, 0x20));
    _os << ("Register master_ocw3rd (Master PIC Op Ctrl Word 3): ");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

/*
 * Register master_icw2: Master PIC Initialization Command Word 2
 * Type: lpc_pic.icw2 (Initialization Command Word 2)
 *   req_level	(size 3, offset 0, init 0):	WO	Interrupt request level
 *   base	(size 5, offset 3, init 0):	WO	Interrupt vector base address
 */
static inline lpc_pic_icw2_t lpc_pic_master_icw2_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_pic_icw2_t lpc_pic_master_icw2_rawrd(__DN(t) *_dev)
{
    return((lpc_pic_icw2_t )(io::read8(_dev->base, 0x21)));
}

static inline lpc_pic_icw2_t lpc_pic_master_icw2_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_pic_icw2_t lpc_pic_master_icw2_rd(__DN(t) *_dev)
{
    return(_dev->master_icw2_shadow);
}

static inline void lpc_pic_master_icw2_rawwr(__DN(t) *_dev, lpc_pic_icw2_t _regval) __attribute__ ((always_inline));
static inline void lpc_pic_master_icw2_rawwr(__DN(t) *_dev, lpc_pic_icw2_t _regval)
{
    io::write8(_dev->base, 0x21, _regval);
}

static inline void lpc_pic_master_icw2_wr(__DN(t) *_dev, lpc_pic_icw2_t _regval) __attribute__ ((always_inline));
static inline void lpc_pic_master_icw2_wr(__DN(t) *_dev, lpc_pic_icw2_t _regval)
{
    // No MB0 or RSVD fields present
    // No MB1 fields present
    // No pre-read of register required
    io::write8(_dev->base, 0x21, _regval);
}

static inline dout_t& lpc_pic_master_icw2_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_pic_master_icw2_pr(dout_t& _os, __DN(t) *_dev)
{
    lpc_pic_icw2_t _regval = _dev->master_icw2_shadow;
    _os << ("Register master_icw2 (Master PIC Initialization Command Word 2): ");
    _os << ("\n");
    ((_os << (" req_level =\t")) << lpc_pic_icw2_req_level_extract(_regval)) << ("\t(Interrupt request level)\n");
    ((_os << (" base =\t")) << lpc_pic_icw2_base_extract(_regval)) << ("\t(Interrupt vector base address)\n");
    return(_os);
}

static inline uint8_t lpc_pic_master_icw2_req_level_rd_shadow(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_master_icw2_req_level_rd_shadow(__DN(t) *_dev)
{
    return(lpc_pic_icw2_req_level_extract(_dev->master_icw2_shadow));
}

static inline uint8_t lpc_pic_master_icw2_base_rd_shadow(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_master_icw2_base_rd_shadow(__DN(t) *_dev)
{
    return(lpc_pic_icw2_base_extract(_dev->master_icw2_shadow));
}

static inline void lpc_pic_master_icw2_req_level_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_pic_master_icw2_req_level_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_pic_icw2_t _regval = (lpc_pic_icw2_t )(0x7 & (((lpc_pic_icw2_t )(_fieldval)) << 0));
    // No pre-read of register required
    _regval = (_regval | (0xf8 & (_dev->master_icw2_shadow)));
    // No MB0 fields present
    // No MB1 fields present
    io::write8(_dev->base, 0x21, _regval);
    _dev->master_icw2_shadow = _regval;
}

static inline void lpc_pic_master_icw2_base_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_pic_master_icw2_base_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_pic_icw2_t _regval = (lpc_pic_icw2_t )(0xf8 & (((lpc_pic_icw2_t )(_fieldval)) << 3));
    // No pre-read of register required
    _regval = (_regval | (0x7 & (_dev->master_icw2_shadow)));
    // No MB0 fields present
    // No MB1 fields present
    io::write8(_dev->base, 0x21, _regval);
    _dev->master_icw2_shadow = _regval;
}

/*
 * Register master_icw3: Master PIC Initialization Command Word 3
 * Type: lpc_pic.pic_master_icw3 (Master Controller Initialization Command Word 3)
 *   _anon0	(size 2, offset 0, init 0):	MBZ	_
 *   cascade	(size 1, offset 2, init 0):	WO	Cascaded PIC IRQ connection
 *   _anon3	(size 5, offset 3, init 0):	MBZ	_
 */
static inline lpc_pic_pic_master_icw3_t lpc_pic_master_icw3_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_pic_pic_master_icw3_t lpc_pic_master_icw3_rawrd(__DN(t) *_dev)
{
    return((lpc_pic_pic_master_icw3_t )(io::read8(_dev->base, 0x21)));
}

static inline lpc_pic_pic_master_icw3_t lpc_pic_master_icw3_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_pic_pic_master_icw3_t lpc_pic_master_icw3_rd(__DN(t) *_dev)
{
    return(_dev->master_icw3_shadow);
}

static inline void lpc_pic_master_icw3_rawwr(__DN(t) *_dev, lpc_pic_pic_master_icw3_t _regval) __attribute__ ((always_inline));
static inline void lpc_pic_master_icw3_rawwr(__DN(t) *_dev, lpc_pic_pic_master_icw3_t _regval)
{
    io::write8(_dev->base, 0x21, _regval);
}

static inline void lpc_pic_master_icw3_wr(__DN(t) *_dev, lpc_pic_pic_master_icw3_t _regval) __attribute__ ((always_inline));
static inline void lpc_pic_master_icw3_wr(__DN(t) *_dev, lpc_pic_pic_master_icw3_t _regval)
{
    _regval = (_regval & 0x4);
    // No MB1 fields present
    // No pre-read of register required
    io::write8(_dev->base, 0x21, _regval);
}

static inline dout_t& lpc_pic_master_icw3_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_pic_master_icw3_pr(dout_t& _os, __DN(t) *_dev)
{
    lpc_pic_pic_master_icw3_t _regval = _dev->master_icw3_shadow;
    _os << ("Register master_icw3 (Master PIC Initialization Command Word 3): ");
    _os << ("\n");
    // _anon0 is anonymous
    ((_os << (" cascade =\t")) << lpc_pic_pic_master_icw3_cascade_extract(_regval)) << ("\t(Cascaded PIC IRQ connection)\n");
    // _anon3 is anonymous
    return(_os);
}

static inline uint8_t lpc_pic_master_icw3_cascade_rd_shadow(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_master_icw3_cascade_rd_shadow(__DN(t) *_dev)
{
    return(lpc_pic_pic_master_icw3_cascade_extract(_dev->master_icw3_shadow));
}

static inline void lpc_pic_master_icw3_cascade_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_pic_master_icw3_cascade_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_pic_pic_master_icw3_t _regval = (lpc_pic_pic_master_icw3_t )(0x4 & (((lpc_pic_pic_master_icw3_t )(_fieldval)) << 2));
    // No pre-read of register required
    // No read of register shadow required
    _regval = (_regval & 0x4);
    // No MB1 fields present
    io::write8(_dev->base, 0x21, _regval);
    _dev->master_icw3_shadow = _regval;
}

/*
 * Register master_icw4: Master PIC Initialization Command Word 4
 * Type: lpc_pic.icw4 (Initialization Command Word 4)
 *   _anon0	(size 1, offset 0, init 1):	MB1	_
 *   aeoi	(size 1, offset 1, init 0):	WO	Automatic End of Interrupt
 *   _anon2	(size 1, offset 2, init 0):	MBZ	_
 *   _anon3	(size 1, offset 3, init 0):	MBZ	_
 *   sfnm	(size 1, offset 4, init 0):	WO	Special fully nested mode
 *   _anon5	(size 3, offset 5, init 0):	MBZ	_
 */
static inline lpc_pic_icw4_t lpc_pic_master_icw4_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_pic_icw4_t lpc_pic_master_icw4_rawrd(__DN(t) *_dev)
{
    return((lpc_pic_icw4_t )(io::read8(_dev->base, 0x21)));
}

static inline lpc_pic_icw4_t lpc_pic_master_icw4_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_pic_icw4_t lpc_pic_master_icw4_rd(__DN(t) *_dev)
{
    return(_dev->master_icw4_shadow);
}

static inline void lpc_pic_master_icw4_rawwr(__DN(t) *_dev, lpc_pic_icw4_t _regval) __attribute__ ((always_inline));
static inline void lpc_pic_master_icw4_rawwr(__DN(t) *_dev, lpc_pic_icw4_t _regval)
{
    io::write8(_dev->base, 0x21, _regval);
}

static inline void lpc_pic_master_icw4_wr(__DN(t) *_dev, lpc_pic_icw4_t _regval) __attribute__ ((always_inline));
static inline void lpc_pic_master_icw4_wr(__DN(t) *_dev, lpc_pic_icw4_t _regval)
{
    _regval = (_regval & 0x13);
    _regval = (_regval | 0x1);
    // No pre-read of register required
    io::write8(_dev->base, 0x21, _regval);
}

static inline dout_t& lpc_pic_master_icw4_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_pic_master_icw4_pr(dout_t& _os, __DN(t) *_dev)
{
    lpc_pic_icw4_t _regval = _dev->master_icw4_shadow;
    _os << ("Register master_icw4 (Master PIC Initialization Command Word 4): ");
    _os << ("\n");
    // _anon0 is anonymous
    ((_os << (" aeoi =\t")) << lpc_pic_icw4_aeoi_extract(_regval)) << ("\t(Automatic End of Interrupt)\n");
    // _anon2 is anonymous
    // _anon3 is anonymous
    ((_os << (" sfnm =\t")) << lpc_pic_icw4_sfnm_extract(_regval)) << ("\t(Special fully nested mode)\n");
    // _anon5 is anonymous
    return(_os);
}

static inline uint8_t lpc_pic_master_icw4_aeoi_rd_shadow(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_master_icw4_aeoi_rd_shadow(__DN(t) *_dev)
{
    return(lpc_pic_icw4_aeoi_extract(_dev->master_icw4_shadow));
}

static inline uint8_t lpc_pic_master_icw4_sfnm_rd_shadow(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_master_icw4_sfnm_rd_shadow(__DN(t) *_dev)
{
    return(lpc_pic_icw4_sfnm_extract(_dev->master_icw4_shadow));
}

static inline void lpc_pic_master_icw4_aeoi_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_pic_master_icw4_aeoi_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_pic_icw4_t _regval = (lpc_pic_icw4_t )(0x2 & (((lpc_pic_icw4_t )(_fieldval)) << 1));
    // No pre-read of register required
    _regval = (_regval | (0x10 & (_dev->master_icw4_shadow)));
    _regval = (_regval & 0x13);
    _regval = (_regval | 0x1);
    io::write8(_dev->base, 0x21, _regval);
    _dev->master_icw4_shadow = _regval;
}

static inline void lpc_pic_master_icw4_sfnm_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_pic_master_icw4_sfnm_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_pic_icw4_t _regval = (lpc_pic_icw4_t )(0x10 & (((lpc_pic_icw4_t )(_fieldval)) << 4));
    // No pre-read of register required
    _regval = (_regval | (0x2 & (_dev->master_icw4_shadow)));
    _regval = (_regval & 0x13);
    _regval = (_regval | 0x1);
    io::write8(_dev->base, 0x21, _regval);
    _dev->master_icw4_shadow = _regval;
}

/*
 * Register master_ocw1: Master PIC Operation Control Word 1
 * Type: lpc_pic.uint8 (primitive type)
 */
static inline uint8_t lpc_pic_master_ocw1_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_master_ocw1_rawrd(__DN(t) *_dev)
{
    return((uint8_t )(io::read8(_dev->base, 0x21)));
}

static inline uint8_t lpc_pic_master_ocw1_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_master_ocw1_rd(__DN(t) *_dev)
{
    return((uint8_t )(io::read8(_dev->base, 0x21)));
}

static inline void lpc_pic_master_ocw1_rawwr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_pic_master_ocw1_rawwr(__DN(t) *_dev, uint8_t _regval)
{
    io::write8(_dev->base, 0x21, _regval);
}

static inline void lpc_pic_master_ocw1_wr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_pic_master_ocw1_wr(__DN(t) *_dev, uint8_t _regval)
{
    // No MB0 or RSVD fields present
    // No MB1 fields present
    // No pre-read of register required
    io::write8(_dev->base, 0x21, _regval);
}

static inline dout_t& lpc_pic_master_ocw1_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_pic_master_ocw1_pr(dout_t& _os, __DN(t) *_dev)
{
    uint8_t _regval = (uint8_t )(io::read8(_dev->base, 0x21));
    _os << ("Register master_ocw1 (Master PIC Operation Control Word 1): ");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

/*
 * Register slave_icw1: Slave PIC Initialization Command Word 1
 * Type: lpc_pic.icw1 (Initialization Command Word 1)
 *   _anon0	(size 1, offset 0, init 1):	MB1	_
 *   _anon1	(size 1, offset 1, init 0):	MBZ	_
 *   _anon2	(size 1, offset 2, init 0):	MBZ	_
 *   ltim	(size 1, offset 3, init 0):	WO	Edge / Level bank select (ignored)
 *   _anon4	(size 1, offset 4, init 1):	MB1	_
 *   _anon5	(size 3, offset 5, init 0):	MBZ	_
 */
static inline lpc_pic_icw1_t lpc_pic_slave_icw1_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_pic_icw1_t lpc_pic_slave_icw1_rawrd(__DN(t) *_dev)
{
    return((lpc_pic_icw1_t )(io::read8(_dev->base, 0xa0)));
}

static inline lpc_pic_icw1_t lpc_pic_slave_icw1_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_pic_icw1_t lpc_pic_slave_icw1_rd(__DN(t) *_dev)
{
    return(_dev->slave_icw1_shadow);
}

static inline void lpc_pic_slave_icw1_rawwr(__DN(t) *_dev, lpc_pic_icw1_t _regval) __attribute__ ((always_inline));
static inline void lpc_pic_slave_icw1_rawwr(__DN(t) *_dev, lpc_pic_icw1_t _regval)
{
    io::write8(_dev->base, 0xa0, _regval);
}

static inline void lpc_pic_slave_icw1_wr(__DN(t) *_dev, lpc_pic_icw1_t _regval) __attribute__ ((always_inline));
static inline void lpc_pic_slave_icw1_wr(__DN(t) *_dev, lpc_pic_icw1_t _regval)
{
    _regval = (_regval & 0x19);
    _regval = (_regval | 0x11);
    // No pre-read of register required
    io::write8(_dev->base, 0xa0, _regval);
}

static inline dout_t& lpc_pic_slave_icw1_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_pic_slave_icw1_pr(dout_t& _os, __DN(t) *_dev)
{
    lpc_pic_icw1_t _regval = _dev->slave_icw1_shadow;
    _os << ("Register slave_icw1 (Slave PIC Initialization Command Word 1): ");
    _os << ("\n");
    // _anon0 is anonymous
    // _anon1 is anonymous
    // _anon2 is anonymous
    ((_os << (" ltim =\t")) << lpc_pic_icw1_ltim_extract(_regval)) << ("\t(Edge / Level bank select (ignored))\n");
    // _anon4 is anonymous
    // _anon5 is anonymous
    return(_os);
}

static inline uint8_t lpc_pic_slave_icw1_ltim_rd_shadow(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_slave_icw1_ltim_rd_shadow(__DN(t) *_dev)
{
    return(lpc_pic_icw1_ltim_extract(_dev->slave_icw1_shadow));
}

static inline void lpc_pic_slave_icw1_ltim_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_pic_slave_icw1_ltim_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_pic_icw1_t _regval = (lpc_pic_icw1_t )(0x8 & (((lpc_pic_icw1_t )(_fieldval)) << 3));
    // No pre-read of register required
    // No read of register shadow required
    _regval = (_regval & 0x19);
    _regval = (_regval | 0x11);
    io::write8(_dev->base, 0xa0, _regval);
    _dev->slave_icw1_shadow = _regval;
}

/*
 * Register slave_ocw2: Slave PIC Op Ctrl Word 2
 * Type: lpc_pic.ocw2 (Operational Control Word 2)
 *   level	(size 3, offset 0, init 0):	WO	Interrupt level select
 *   _anon3	(size 2, offset 3, init 0):	MBZ	_
 *   rsleoi	(size 3, offset 5, init 0):	WO	Rotate and EOI Codes
 */
static inline lpc_pic_ocw2_t lpc_pic_slave_ocw2_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_pic_ocw2_t lpc_pic_slave_ocw2_rawrd(__DN(t) *_dev)
{
    return((lpc_pic_ocw2_t )(io::read8(_dev->base, 0xa0)));
}

static inline lpc_pic_ocw2_t lpc_pic_slave_ocw2_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_pic_ocw2_t lpc_pic_slave_ocw2_rd(__DN(t) *_dev)
{
    return(_dev->slave_ocw2_shadow);
}

static inline void lpc_pic_slave_ocw2_rawwr(__DN(t) *_dev, lpc_pic_ocw2_t _regval) __attribute__ ((always_inline));
static inline void lpc_pic_slave_ocw2_rawwr(__DN(t) *_dev, lpc_pic_ocw2_t _regval)
{
    io::write8(_dev->base, 0xa0, _regval);
}

static inline void lpc_pic_slave_ocw2_wr(__DN(t) *_dev, lpc_pic_ocw2_t _regval) __attribute__ ((always_inline));
static inline void lpc_pic_slave_ocw2_wr(__DN(t) *_dev, lpc_pic_ocw2_t _regval)
{
    _regval = (_regval & 0xe7);
    // No MB1 fields present
    // No pre-read of register required
    io::write8(_dev->base, 0xa0, _regval);
}

static inline dout_t& lpc_pic_slave_ocw2_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_pic_slave_ocw2_pr(dout_t& _os, __DN(t) *_dev)
{
    lpc_pic_ocw2_t _regval = _dev->slave_ocw2_shadow;
    _os << ("Register slave_ocw2 (Slave PIC Op Ctrl Word 2): ");
    _os << ("\n");
    ((_os << (" level =\t")) << lpc_pic_ocw2_level_extract(_regval)) << ("\t(Interrupt level select)\n");
    // _anon3 is anonymous
    ((_os << (" rsleoi =\t")) << lpc_pic_ocw2_rsleoi_extract(_regval)) << ("\t(Rotate and EOI Codes)\n");
    return(_os);
}

static inline uint8_t lpc_pic_slave_ocw2_level_rd_shadow(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_slave_ocw2_level_rd_shadow(__DN(t) *_dev)
{
    return(lpc_pic_ocw2_level_extract(_dev->slave_ocw2_shadow));
}

static inline lpc_pic_rsleoi_t lpc_pic_slave_ocw2_rsleoi_rd_shadow(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_pic_rsleoi_t lpc_pic_slave_ocw2_rsleoi_rd_shadow(__DN(t) *_dev)
{
    return(lpc_pic_ocw2_rsleoi_extract(_dev->slave_ocw2_shadow));
}

static inline void lpc_pic_slave_ocw2_level_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_pic_slave_ocw2_level_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_pic_ocw2_t _regval = (lpc_pic_ocw2_t )(0x7 & (((lpc_pic_ocw2_t )(_fieldval)) << 0));
    // No pre-read of register required
    _regval = (_regval | (0xe0 & (_dev->slave_ocw2_shadow)));
    _regval = (_regval & 0xe7);
    // No MB1 fields present
    io::write8(_dev->base, 0xa0, _regval);
    _dev->slave_ocw2_shadow = _regval;
}

static inline void lpc_pic_slave_ocw2_rsleoi_wrf(__DN(t) *_dev, lpc_pic_rsleoi_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_pic_slave_ocw2_rsleoi_wrf(__DN(t) *_dev, lpc_pic_rsleoi_t _fieldval)
{
    lpc_pic_ocw2_t _regval = (lpc_pic_ocw2_t )(0xe0 & (((lpc_pic_ocw2_t )(_fieldval)) << 5));
    // No pre-read of register required
    _regval = (_regval | (0x7 & (_dev->slave_ocw2_shadow)));
    _regval = (_regval & 0xe7);
    // No MB1 fields present
    io::write8(_dev->base, 0xa0, _regval);
    _dev->slave_ocw2_shadow = _regval;
}

/*
 * Register slave_ocw3: Slave PIC Op Ctrl Word 3
 * Type: lpc_pic.ocw3 (Operational Control Word 3)
 *   rrc	(size 2, offset 0, init 0):	WO	Register read command
 *   pmc	(size 1, offset 2, init 0):	WO	Poll mode command
 *   _anon3	(size 1, offset 3, init 1):	MB1	_
 *   _anon4	(size 1, offset 4, init 0):	MBZ	_
 *   esmm	(size 1, offset 5, init 0):	WO	Enable special mask mode
 *   smm	(size 1, offset 6, init 0):	WO	Special mask mode
 *   _anon7	(size 1, offset 7, init 0):	MBZ	_
 */
static inline lpc_pic_ocw3_t lpc_pic_slave_ocw3_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_pic_ocw3_t lpc_pic_slave_ocw3_rawrd(__DN(t) *_dev)
{
    return((lpc_pic_ocw3_t )(io::read8(_dev->base, 0xa0)));
}

static inline lpc_pic_ocw3_t lpc_pic_slave_ocw3_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_pic_ocw3_t lpc_pic_slave_ocw3_rd(__DN(t) *_dev)
{
    return(_dev->slave_ocw3_shadow);
}

static inline void lpc_pic_slave_ocw3_rawwr(__DN(t) *_dev, lpc_pic_ocw3_t _regval) __attribute__ ((always_inline));
static inline void lpc_pic_slave_ocw3_rawwr(__DN(t) *_dev, lpc_pic_ocw3_t _regval)
{
    io::write8(_dev->base, 0xa0, _regval);
}

static inline void lpc_pic_slave_ocw3_wr(__DN(t) *_dev, lpc_pic_ocw3_t _regval) __attribute__ ((always_inline));
static inline void lpc_pic_slave_ocw3_wr(__DN(t) *_dev, lpc_pic_ocw3_t _regval)
{
    _regval = (_regval & 0x6f);
    _regval = (_regval | 0x8);
    // No pre-read of register required
    io::write8(_dev->base, 0xa0, _regval);
}

static inline dout_t& lpc_pic_slave_ocw3_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_pic_slave_ocw3_pr(dout_t& _os, __DN(t) *_dev)
{
    lpc_pic_ocw3_t _regval = _dev->slave_ocw3_shadow;
    _os << ("Register slave_ocw3 (Slave PIC Op Ctrl Word 3): ");
    _os << ("\n");
    ((_os << (" rrc =\t")) << lpc_pic_ocw3_rrc_extract(_regval)) << ("\t(Register read command)\n");
    ((_os << (" pmc =\t")) << lpc_pic_ocw3_pmc_extract(_regval)) << ("\t(Poll mode command)\n");
    // _anon3 is anonymous
    // _anon4 is anonymous
    ((_os << (" esmm =\t")) << lpc_pic_ocw3_esmm_extract(_regval)) << ("\t(Enable special mask mode)\n");
    ((_os << (" smm =\t")) << lpc_pic_ocw3_smm_extract(_regval)) << ("\t(Special mask mode)\n");
    // _anon7 is anonymous
    return(_os);
}

static inline lpc_pic_rrc_t lpc_pic_slave_ocw3_rrc_rd_shadow(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_pic_rrc_t lpc_pic_slave_ocw3_rrc_rd_shadow(__DN(t) *_dev)
{
    return(lpc_pic_ocw3_rrc_extract(_dev->slave_ocw3_shadow));
}

static inline uint8_t lpc_pic_slave_ocw3_pmc_rd_shadow(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_slave_ocw3_pmc_rd_shadow(__DN(t) *_dev)
{
    return(lpc_pic_ocw3_pmc_extract(_dev->slave_ocw3_shadow));
}

static inline uint8_t lpc_pic_slave_ocw3_esmm_rd_shadow(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_slave_ocw3_esmm_rd_shadow(__DN(t) *_dev)
{
    return(lpc_pic_ocw3_esmm_extract(_dev->slave_ocw3_shadow));
}

static inline uint8_t lpc_pic_slave_ocw3_smm_rd_shadow(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_slave_ocw3_smm_rd_shadow(__DN(t) *_dev)
{
    return(lpc_pic_ocw3_smm_extract(_dev->slave_ocw3_shadow));
}

static inline void lpc_pic_slave_ocw3_rrc_wrf(__DN(t) *_dev, lpc_pic_rrc_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_pic_slave_ocw3_rrc_wrf(__DN(t) *_dev, lpc_pic_rrc_t _fieldval)
{
    lpc_pic_ocw3_t _regval = (lpc_pic_ocw3_t )(0x3 & (((lpc_pic_ocw3_t )(_fieldval)) << 0));
    // No pre-read of register required
    _regval = (_regval | (0x64 & (_dev->slave_ocw3_shadow)));
    _regval = (_regval & 0x6f);
    _regval = (_regval | 0x8);
    io::write8(_dev->base, 0xa0, _regval);
    _dev->slave_ocw3_shadow = _regval;
}

static inline void lpc_pic_slave_ocw3_pmc_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_pic_slave_ocw3_pmc_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_pic_ocw3_t _regval = (lpc_pic_ocw3_t )(0x4 & (((lpc_pic_ocw3_t )(_fieldval)) << 2));
    // No pre-read of register required
    _regval = (_regval | (0x63 & (_dev->slave_ocw3_shadow)));
    _regval = (_regval & 0x6f);
    _regval = (_regval | 0x8);
    io::write8(_dev->base, 0xa0, _regval);
    _dev->slave_ocw3_shadow = _regval;
}

static inline void lpc_pic_slave_ocw3_esmm_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_pic_slave_ocw3_esmm_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_pic_ocw3_t _regval = (lpc_pic_ocw3_t )(0x20 & (((lpc_pic_ocw3_t )(_fieldval)) << 5));
    // No pre-read of register required
    _regval = (_regval | (0x47 & (_dev->slave_ocw3_shadow)));
    _regval = (_regval & 0x6f);
    _regval = (_regval | 0x8);
    io::write8(_dev->base, 0xa0, _regval);
    _dev->slave_ocw3_shadow = _regval;
}

static inline void lpc_pic_slave_ocw3_smm_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_pic_slave_ocw3_smm_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_pic_ocw3_t _regval = (lpc_pic_ocw3_t )(0x40 & (((lpc_pic_ocw3_t )(_fieldval)) << 6));
    // No pre-read of register required
    _regval = (_regval | (0x27 & (_dev->slave_ocw3_shadow)));
    _regval = (_regval & 0x6f);
    _regval = (_regval | 0x8);
    io::write8(_dev->base, 0xa0, _regval);
    _dev->slave_ocw3_shadow = _regval;
}

/*
 * Register slave_ocw3rd: Slave PIC Op Ctrl Word 3
 * Type: lpc_pic.uint8 (primitive type)
 */
static inline uint8_t lpc_pic_slave_ocw3rd_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_slave_ocw3rd_rawrd(__DN(t) *_dev)
{
    return((uint8_t )(io::read8(_dev->base, 0xa0)));
}

static inline uint8_t lpc_pic_slave_ocw3rd_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_slave_ocw3rd_rd(__DN(t) *_dev)
{
    return((uint8_t )(io::read8(_dev->base, 0xa0)));
}

static inline void lpc_pic_slave_ocw3rd_rawwr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_pic_slave_ocw3rd_rawwr(__DN(t) *_dev, uint8_t _regval)
{
    io::write8(_dev->base, 0xa0, _regval);
}

// Register slave_ocw3rd is not writeable
static inline dout_t& lpc_pic_slave_ocw3rd_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_pic_slave_ocw3rd_pr(dout_t& _os, __DN(t) *_dev)
{
    uint8_t _regval = (uint8_t )(io::read8(_dev->base, 0xa0));
    _os << ("Register slave_ocw3rd (Slave PIC Op Ctrl Word 3): ");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

/*
 * Register slave_icw2: Slave PIC Initialization Command Word 2
 * Type: lpc_pic.icw2 (Initialization Command Word 2)
 *   req_level	(size 3, offset 0, init 0):	WO	Interrupt request level
 *   base	(size 5, offset 3, init 0):	WO	Interrupt vector base address
 */
static inline lpc_pic_icw2_t lpc_pic_slave_icw2_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_pic_icw2_t lpc_pic_slave_icw2_rawrd(__DN(t) *_dev)
{
    return((lpc_pic_icw2_t )(io::read8(_dev->base, 0xa1)));
}

static inline lpc_pic_icw2_t lpc_pic_slave_icw2_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_pic_icw2_t lpc_pic_slave_icw2_rd(__DN(t) *_dev)
{
    return(_dev->slave_icw2_shadow);
}

static inline void lpc_pic_slave_icw2_rawwr(__DN(t) *_dev, lpc_pic_icw2_t _regval) __attribute__ ((always_inline));
static inline void lpc_pic_slave_icw2_rawwr(__DN(t) *_dev, lpc_pic_icw2_t _regval)
{
    io::write8(_dev->base, 0xa1, _regval);
}

static inline void lpc_pic_slave_icw2_wr(__DN(t) *_dev, lpc_pic_icw2_t _regval) __attribute__ ((always_inline));
static inline void lpc_pic_slave_icw2_wr(__DN(t) *_dev, lpc_pic_icw2_t _regval)
{
    // No MB0 or RSVD fields present
    // No MB1 fields present
    // No pre-read of register required
    io::write8(_dev->base, 0xa1, _regval);
}

static inline dout_t& lpc_pic_slave_icw2_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_pic_slave_icw2_pr(dout_t& _os, __DN(t) *_dev)
{
    lpc_pic_icw2_t _regval = _dev->slave_icw2_shadow;
    _os << ("Register slave_icw2 (Slave PIC Initialization Command Word 2): ");
    _os << ("\n");
    ((_os << (" req_level =\t")) << lpc_pic_icw2_req_level_extract(_regval)) << ("\t(Interrupt request level)\n");
    ((_os << (" base =\t")) << lpc_pic_icw2_base_extract(_regval)) << ("\t(Interrupt vector base address)\n");
    return(_os);
}

static inline uint8_t lpc_pic_slave_icw2_req_level_rd_shadow(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_slave_icw2_req_level_rd_shadow(__DN(t) *_dev)
{
    return(lpc_pic_icw2_req_level_extract(_dev->slave_icw2_shadow));
}

static inline uint8_t lpc_pic_slave_icw2_base_rd_shadow(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_slave_icw2_base_rd_shadow(__DN(t) *_dev)
{
    return(lpc_pic_icw2_base_extract(_dev->slave_icw2_shadow));
}

static inline void lpc_pic_slave_icw2_req_level_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_pic_slave_icw2_req_level_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_pic_icw2_t _regval = (lpc_pic_icw2_t )(0x7 & (((lpc_pic_icw2_t )(_fieldval)) << 0));
    // No pre-read of register required
    _regval = (_regval | (0xf8 & (_dev->slave_icw2_shadow)));
    // No MB0 fields present
    // No MB1 fields present
    io::write8(_dev->base, 0xa1, _regval);
    _dev->slave_icw2_shadow = _regval;
}

static inline void lpc_pic_slave_icw2_base_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_pic_slave_icw2_base_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_pic_icw2_t _regval = (lpc_pic_icw2_t )(0xf8 & (((lpc_pic_icw2_t )(_fieldval)) << 3));
    // No pre-read of register required
    _regval = (_regval | (0x7 & (_dev->slave_icw2_shadow)));
    // No MB0 fields present
    // No MB1 fields present
    io::write8(_dev->base, 0xa1, _regval);
    _dev->slave_icw2_shadow = _regval;
}

/*
 * Register slave_icw3: Slave PIC Initialization Command Word 3
 * Type: lpc_pic.pic_slave_icw3 (Slave Controller Initialization Command Word 3)
 *   slave_id	(size 3, offset 0, init 0):	WO	Slave Identification Code
 *   _anon3	(size 5, offset 3, init 0):	MBZ	_
 */
static inline lpc_pic_pic_slave_icw3_t lpc_pic_slave_icw3_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_pic_pic_slave_icw3_t lpc_pic_slave_icw3_rawrd(__DN(t) *_dev)
{
    return((lpc_pic_pic_slave_icw3_t )(io::read8(_dev->base, 0xa1)));
}

static inline lpc_pic_pic_slave_icw3_t lpc_pic_slave_icw3_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_pic_pic_slave_icw3_t lpc_pic_slave_icw3_rd(__DN(t) *_dev)
{
    return(_dev->slave_icw3_shadow);
}

static inline void lpc_pic_slave_icw3_rawwr(__DN(t) *_dev, lpc_pic_pic_slave_icw3_t _regval) __attribute__ ((always_inline));
static inline void lpc_pic_slave_icw3_rawwr(__DN(t) *_dev, lpc_pic_pic_slave_icw3_t _regval)
{
    io::write8(_dev->base, 0xa1, _regval);
}

static inline void lpc_pic_slave_icw3_wr(__DN(t) *_dev, lpc_pic_pic_slave_icw3_t _regval) __attribute__ ((always_inline));
static inline void lpc_pic_slave_icw3_wr(__DN(t) *_dev, lpc_pic_pic_slave_icw3_t _regval)
{
    _regval = (_regval & 0x7);
    // No MB1 fields present
    // No pre-read of register required
    io::write8(_dev->base, 0xa1, _regval);
}

static inline dout_t& lpc_pic_slave_icw3_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_pic_slave_icw3_pr(dout_t& _os, __DN(t) *_dev)
{
    lpc_pic_pic_slave_icw3_t _regval = _dev->slave_icw3_shadow;
    _os << ("Register slave_icw3 (Slave PIC Initialization Command Word 3): ");
    _os << ("\n");
    ((_os << (" slave_id =\t")) << lpc_pic_pic_slave_icw3_slave_id_extract(_regval)) << ("\t(Slave Identification Code)\n");
    // _anon3 is anonymous
    return(_os);
}

static inline uint8_t lpc_pic_slave_icw3_slave_id_rd_shadow(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_slave_icw3_slave_id_rd_shadow(__DN(t) *_dev)
{
    return(lpc_pic_pic_slave_icw3_slave_id_extract(_dev->slave_icw3_shadow));
}

static inline void lpc_pic_slave_icw3_slave_id_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_pic_slave_icw3_slave_id_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_pic_pic_slave_icw3_t _regval = (lpc_pic_pic_slave_icw3_t )(0x7 & (((lpc_pic_pic_slave_icw3_t )(_fieldval)) << 0));
    // No pre-read of register required
    // No read of register shadow required
    _regval = (_regval & 0x7);
    // No MB1 fields present
    io::write8(_dev->base, 0xa1, _regval);
    _dev->slave_icw3_shadow = _regval;
}

/*
 * Register slave_icw4: Slave PIC Initialization Command Word 4
 * Type: lpc_pic.icw4 (Initialization Command Word 4)
 *   _anon0	(size 1, offset 0, init 1):	MB1	_
 *   aeoi	(size 1, offset 1, init 0):	WO	Automatic End of Interrupt
 *   _anon2	(size 1, offset 2, init 0):	MBZ	_
 *   _anon3	(size 1, offset 3, init 0):	MBZ	_
 *   sfnm	(size 1, offset 4, init 0):	WO	Special fully nested mode
 *   _anon5	(size 3, offset 5, init 0):	MBZ	_
 */
static inline lpc_pic_icw4_t lpc_pic_slave_icw4_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_pic_icw4_t lpc_pic_slave_icw4_rawrd(__DN(t) *_dev)
{
    return((lpc_pic_icw4_t )(io::read8(_dev->base, 0xa1)));
}

static inline lpc_pic_icw4_t lpc_pic_slave_icw4_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_pic_icw4_t lpc_pic_slave_icw4_rd(__DN(t) *_dev)
{
    return(_dev->slave_icw4_shadow);
}

static inline void lpc_pic_slave_icw4_rawwr(__DN(t) *_dev, lpc_pic_icw4_t _regval) __attribute__ ((always_inline));
static inline void lpc_pic_slave_icw4_rawwr(__DN(t) *_dev, lpc_pic_icw4_t _regval)
{
    io::write8(_dev->base, 0xa1, _regval);
}

static inline void lpc_pic_slave_icw4_wr(__DN(t) *_dev, lpc_pic_icw4_t _regval) __attribute__ ((always_inline));
static inline void lpc_pic_slave_icw4_wr(__DN(t) *_dev, lpc_pic_icw4_t _regval)
{
    _regval = (_regval & 0x13);
    _regval = (_regval | 0x1);
    // No pre-read of register required
    io::write8(_dev->base, 0xa1, _regval);
}

static inline dout_t& lpc_pic_slave_icw4_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_pic_slave_icw4_pr(dout_t& _os, __DN(t) *_dev)
{
    lpc_pic_icw4_t _regval = _dev->slave_icw4_shadow;
    _os << ("Register slave_icw4 (Slave PIC Initialization Command Word 4): ");
    _os << ("\n");
    // _anon0 is anonymous
    ((_os << (" aeoi =\t")) << lpc_pic_icw4_aeoi_extract(_regval)) << ("\t(Automatic End of Interrupt)\n");
    // _anon2 is anonymous
    // _anon3 is anonymous
    ((_os << (" sfnm =\t")) << lpc_pic_icw4_sfnm_extract(_regval)) << ("\t(Special fully nested mode)\n");
    // _anon5 is anonymous
    return(_os);
}

static inline uint8_t lpc_pic_slave_icw4_aeoi_rd_shadow(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_slave_icw4_aeoi_rd_shadow(__DN(t) *_dev)
{
    return(lpc_pic_icw4_aeoi_extract(_dev->slave_icw4_shadow));
}

static inline uint8_t lpc_pic_slave_icw4_sfnm_rd_shadow(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_slave_icw4_sfnm_rd_shadow(__DN(t) *_dev)
{
    return(lpc_pic_icw4_sfnm_extract(_dev->slave_icw4_shadow));
}

static inline void lpc_pic_slave_icw4_aeoi_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_pic_slave_icw4_aeoi_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_pic_icw4_t _regval = (lpc_pic_icw4_t )(0x2 & (((lpc_pic_icw4_t )(_fieldval)) << 1));
    // No pre-read of register required
    _regval = (_regval | (0x10 & (_dev->slave_icw4_shadow)));
    _regval = (_regval & 0x13);
    _regval = (_regval | 0x1);
    io::write8(_dev->base, 0xa1, _regval);
    _dev->slave_icw4_shadow = _regval;
}

static inline void lpc_pic_slave_icw4_sfnm_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_pic_slave_icw4_sfnm_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_pic_icw4_t _regval = (lpc_pic_icw4_t )(0x10 & (((lpc_pic_icw4_t )(_fieldval)) << 4));
    // No pre-read of register required
    _regval = (_regval | (0x2 & (_dev->slave_icw4_shadow)));
    _regval = (_regval & 0x13);
    _regval = (_regval | 0x1);
    io::write8(_dev->base, 0xa1, _regval);
    _dev->slave_icw4_shadow = _regval;
}

/*
 * Register slave_ocw1: Slave PIC Operation Control Word 1
 * Type: lpc_pic.uint8 (primitive type)
 */
static inline uint8_t lpc_pic_slave_ocw1_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_slave_ocw1_rawrd(__DN(t) *_dev)
{
    return((uint8_t )(io::read8(_dev->base, 0xa1)));
}

static inline uint8_t lpc_pic_slave_ocw1_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_slave_ocw1_rd(__DN(t) *_dev)
{
    return((uint8_t )(io::read8(_dev->base, 0xa1)));
}

static inline void lpc_pic_slave_ocw1_rawwr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_pic_slave_ocw1_rawwr(__DN(t) *_dev, uint8_t _regval)
{
    io::write8(_dev->base, 0xa1, _regval);
}

static inline void lpc_pic_slave_ocw1_wr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void lpc_pic_slave_ocw1_wr(__DN(t) *_dev, uint8_t _regval)
{
    // No MB0 or RSVD fields present
    // No MB1 fields present
    // No pre-read of register required
    io::write8(_dev->base, 0xa1, _regval);
}

static inline dout_t& lpc_pic_slave_ocw1_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_pic_slave_ocw1_pr(dout_t& _os, __DN(t) *_dev)
{
    uint8_t _regval = (uint8_t )(io::read8(_dev->base, 0xa1));
    _os << ("Register slave_ocw1 (Slave PIC Operation Control Word 1): ");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

/*
 * Register master_trigger: Master PIC Edge/Level Triggered
 * Type: lpc_pic.pic_master_trigger (Master Controller Edge/Level Triggered)
 *   _anon0	(size 3, offset 0, init 0):	MBZ	_
 *   irq3_ecl	(size 1, offset 3, init 0):	RW	IRQ3 ECL
 *   irq4_ecl	(size 1, offset 4, init 0):	RW	IRQ4 ECL
 *   irq5_ecl	(size 1, offset 5, init 0):	RW	IRQ5 ECL
 *   irq6_ecl	(size 1, offset 6, init 0):	RW	IRQ6 ECL
 *   irq7_ecl	(size 1, offset 7, init 0):	RW	IRQ7 ECL
 */
static inline lpc_pic_pic_master_trigger_t lpc_pic_master_trigger_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_pic_pic_master_trigger_t lpc_pic_master_trigger_rawrd(__DN(t) *_dev)
{
    return((lpc_pic_pic_master_trigger_t )(io::read8(_dev->base, 0x4d0)));
}

static inline lpc_pic_pic_master_trigger_t lpc_pic_master_trigger_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_pic_pic_master_trigger_t lpc_pic_master_trigger_rd(__DN(t) *_dev)
{
    return((lpc_pic_pic_master_trigger_t )(io::read8(_dev->base, 0x4d0)));
}

static inline void lpc_pic_master_trigger_rawwr(__DN(t) *_dev, lpc_pic_pic_master_trigger_t _regval) __attribute__ ((always_inline));
static inline void lpc_pic_master_trigger_rawwr(__DN(t) *_dev, lpc_pic_pic_master_trigger_t _regval)
{
    io::write8(_dev->base, 0x4d0, _regval);
}

static inline void lpc_pic_master_trigger_wr(__DN(t) *_dev, lpc_pic_pic_master_trigger_t _regval) __attribute__ ((always_inline));
static inline void lpc_pic_master_trigger_wr(__DN(t) *_dev, lpc_pic_pic_master_trigger_t _regval)
{
    _regval = (_regval & 0xf8);
    // No MB1 fields present
    // No pre-read of register required
    io::write8(_dev->base, 0x4d0, _regval);
}

static inline dout_t& lpc_pic_master_trigger_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_pic_master_trigger_pr(dout_t& _os, __DN(t) *_dev)
{
    lpc_pic_pic_master_trigger_t _regval = (lpc_pic_pic_master_trigger_t )(io::read8(_dev->base, 0x4d0));
    _os << ("Register master_trigger (Master PIC Edge/Level Triggered): ");
    _os << ("\n");
    // _anon0 is anonymous
    ((_os << (" irq3_ecl =\t")) << lpc_pic_pic_master_trigger_irq3_ecl_extract(_regval)) << ("\t(IRQ3 ECL)\n");
    ((_os << (" irq4_ecl =\t")) << lpc_pic_pic_master_trigger_irq4_ecl_extract(_regval)) << ("\t(IRQ4 ECL)\n");
    ((_os << (" irq5_ecl =\t")) << lpc_pic_pic_master_trigger_irq5_ecl_extract(_regval)) << ("\t(IRQ5 ECL)\n");
    ((_os << (" irq6_ecl =\t")) << lpc_pic_pic_master_trigger_irq6_ecl_extract(_regval)) << ("\t(IRQ6 ECL)\n");
    ((_os << (" irq7_ecl =\t")) << lpc_pic_pic_master_trigger_irq7_ecl_extract(_regval)) << ("\t(IRQ7 ECL)\n");
    return(_os);
}

static inline uint8_t lpc_pic_master_trigger_irq3_ecl_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_master_trigger_irq3_ecl_rdf(__DN(t) *_dev)
{
    lpc_pic_pic_master_trigger_t _regval = (lpc_pic_pic_master_trigger_t )(io::read8(_dev->base, 0x4d0));
    return(lpc_pic_pic_master_trigger_irq3_ecl_extract(_regval));
}

static inline uint8_t lpc_pic_master_trigger_irq4_ecl_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_master_trigger_irq4_ecl_rdf(__DN(t) *_dev)
{
    lpc_pic_pic_master_trigger_t _regval = (lpc_pic_pic_master_trigger_t )(io::read8(_dev->base, 0x4d0));
    return(lpc_pic_pic_master_trigger_irq4_ecl_extract(_regval));
}

static inline uint8_t lpc_pic_master_trigger_irq5_ecl_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_master_trigger_irq5_ecl_rdf(__DN(t) *_dev)
{
    lpc_pic_pic_master_trigger_t _regval = (lpc_pic_pic_master_trigger_t )(io::read8(_dev->base, 0x4d0));
    return(lpc_pic_pic_master_trigger_irq5_ecl_extract(_regval));
}

static inline uint8_t lpc_pic_master_trigger_irq6_ecl_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_master_trigger_irq6_ecl_rdf(__DN(t) *_dev)
{
    lpc_pic_pic_master_trigger_t _regval = (lpc_pic_pic_master_trigger_t )(io::read8(_dev->base, 0x4d0));
    return(lpc_pic_pic_master_trigger_irq6_ecl_extract(_regval));
}

static inline uint8_t lpc_pic_master_trigger_irq7_ecl_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_master_trigger_irq7_ecl_rdf(__DN(t) *_dev)
{
    lpc_pic_pic_master_trigger_t _regval = (lpc_pic_pic_master_trigger_t )(io::read8(_dev->base, 0x4d0));
    return(lpc_pic_pic_master_trigger_irq7_ecl_extract(_regval));
}

static inline void lpc_pic_master_trigger_irq3_ecl_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_pic_master_trigger_irq3_ecl_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_pic_pic_master_trigger_t _regval = (lpc_pic_pic_master_trigger_t )(0x8 & (((lpc_pic_pic_master_trigger_t )(_fieldval)) << 3));
    _regval = (_regval | (0xf0 & ((lpc_pic_pic_master_trigger_t )(io::read8(_dev->base, 0x4d0)))));
    // No read of register shadow required
    _regval = (_regval & 0xf8);
    // No MB1 fields present
    io::write8(_dev->base, 0x4d0, _regval);
    // No shadow register to write to
}

static inline void lpc_pic_master_trigger_irq4_ecl_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_pic_master_trigger_irq4_ecl_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_pic_pic_master_trigger_t _regval = (lpc_pic_pic_master_trigger_t )(0x10 & (((lpc_pic_pic_master_trigger_t )(_fieldval)) << 4));
    _regval = (_regval | (0xe8 & ((lpc_pic_pic_master_trigger_t )(io::read8(_dev->base, 0x4d0)))));
    // No read of register shadow required
    _regval = (_regval & 0xf8);
    // No MB1 fields present
    io::write8(_dev->base, 0x4d0, _regval);
    // No shadow register to write to
}

static inline void lpc_pic_master_trigger_irq5_ecl_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_pic_master_trigger_irq5_ecl_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_pic_pic_master_trigger_t _regval = (lpc_pic_pic_master_trigger_t )(0x20 & (((lpc_pic_pic_master_trigger_t )(_fieldval)) << 5));
    _regval = (_regval | (0xd8 & ((lpc_pic_pic_master_trigger_t )(io::read8(_dev->base, 0x4d0)))));
    // No read of register shadow required
    _regval = (_regval & 0xf8);
    // No MB1 fields present
    io::write8(_dev->base, 0x4d0, _regval);
    // No shadow register to write to
}

static inline void lpc_pic_master_trigger_irq6_ecl_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_pic_master_trigger_irq6_ecl_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_pic_pic_master_trigger_t _regval = (lpc_pic_pic_master_trigger_t )(0x40 & (((lpc_pic_pic_master_trigger_t )(_fieldval)) << 6));
    _regval = (_regval | (0xb8 & ((lpc_pic_pic_master_trigger_t )(io::read8(_dev->base, 0x4d0)))));
    // No read of register shadow required
    _regval = (_regval & 0xf8);
    // No MB1 fields present
    io::write8(_dev->base, 0x4d0, _regval);
    // No shadow register to write to
}

static inline void lpc_pic_master_trigger_irq7_ecl_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_pic_master_trigger_irq7_ecl_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_pic_pic_master_trigger_t _regval = (lpc_pic_pic_master_trigger_t )(0x80 & (((lpc_pic_pic_master_trigger_t )(_fieldval)) << 7));
    _regval = (_regval | (0x78 & ((lpc_pic_pic_master_trigger_t )(io::read8(_dev->base, 0x4d0)))));
    // No read of register shadow required
    _regval = (_regval & 0xf8);
    // No MB1 fields present
    io::write8(_dev->base, 0x4d0, _regval);
    // No shadow register to write to
}

/*
 * Register slave_trigger: Slave PIC Edge/Level Triggered
 * Type: lpc_pic.pic_slave_trigger (Slave Controller Edge/Level Triggered)
 *   _anon0	(size 1, offset 0, init 0):	MBZ	_
 *   irq9_ecl	(size 1, offset 1, init 0):	RW	IRQ9 ECL
 *   irq10_ecl	(size 1, offset 2, init 0):	RW	IRQ10 ECL
 *   irq11_ecl	(size 1, offset 3, init 0):	RW	IRQ11 ECL
 *   irq12_ecl	(size 1, offset 4, init 0):	RW	IRQ12 ECL
 *   _anon5	(size 1, offset 5, init 0):	MBZ	_
 *   irq14_ecl	(size 1, offset 6, init 0):	RW	IRQ14 ECL
 *   irq15_ecl	(size 1, offset 7, init 0):	RW	IRQ15 ECL
 */
static inline lpc_pic_pic_slave_trigger_t lpc_pic_slave_trigger_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_pic_pic_slave_trigger_t lpc_pic_slave_trigger_rawrd(__DN(t) *_dev)
{
    return((lpc_pic_pic_slave_trigger_t )(io::read8(_dev->base, 0x4d1)));
}

static inline lpc_pic_pic_slave_trigger_t lpc_pic_slave_trigger_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_pic_pic_slave_trigger_t lpc_pic_slave_trigger_rd(__DN(t) *_dev)
{
    return((lpc_pic_pic_slave_trigger_t )(io::read8(_dev->base, 0x4d1)));
}

static inline void lpc_pic_slave_trigger_rawwr(__DN(t) *_dev, lpc_pic_pic_slave_trigger_t _regval) __attribute__ ((always_inline));
static inline void lpc_pic_slave_trigger_rawwr(__DN(t) *_dev, lpc_pic_pic_slave_trigger_t _regval)
{
    io::write8(_dev->base, 0x4d1, _regval);
}

static inline void lpc_pic_slave_trigger_wr(__DN(t) *_dev, lpc_pic_pic_slave_trigger_t _regval) __attribute__ ((always_inline));
static inline void lpc_pic_slave_trigger_wr(__DN(t) *_dev, lpc_pic_pic_slave_trigger_t _regval)
{
    _regval = (_regval & 0xde);
    // No MB1 fields present
    // No pre-read of register required
    io::write8(_dev->base, 0x4d1, _regval);
}

static inline dout_t& lpc_pic_slave_trigger_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_pic_slave_trigger_pr(dout_t& _os, __DN(t) *_dev)
{
    lpc_pic_pic_slave_trigger_t _regval = (lpc_pic_pic_slave_trigger_t )(io::read8(_dev->base, 0x4d1));
    _os << ("Register slave_trigger (Slave PIC Edge/Level Triggered): ");
    _os << ("\n");
    // _anon0 is anonymous
    ((_os << (" irq9_ecl =\t")) << lpc_pic_pic_slave_trigger_irq9_ecl_extract(_regval)) << ("\t(IRQ9 ECL)\n");
    ((_os << (" irq10_ecl =\t")) << lpc_pic_pic_slave_trigger_irq10_ecl_extract(_regval)) << ("\t(IRQ10 ECL)\n");
    ((_os << (" irq11_ecl =\t")) << lpc_pic_pic_slave_trigger_irq11_ecl_extract(_regval)) << ("\t(IRQ11 ECL)\n");
    ((_os << (" irq12_ecl =\t")) << lpc_pic_pic_slave_trigger_irq12_ecl_extract(_regval)) << ("\t(IRQ12 ECL)\n");
    // _anon5 is anonymous
    ((_os << (" irq14_ecl =\t")) << lpc_pic_pic_slave_trigger_irq14_ecl_extract(_regval)) << ("\t(IRQ14 ECL)\n");
    ((_os << (" irq15_ecl =\t")) << lpc_pic_pic_slave_trigger_irq15_ecl_extract(_regval)) << ("\t(IRQ15 ECL)\n");
    return(_os);
}

static inline uint8_t lpc_pic_slave_trigger_irq9_ecl_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_slave_trigger_irq9_ecl_rdf(__DN(t) *_dev)
{
    lpc_pic_pic_slave_trigger_t _regval = (lpc_pic_pic_slave_trigger_t )(io::read8(_dev->base, 0x4d1));
    return(lpc_pic_pic_slave_trigger_irq9_ecl_extract(_regval));
}

static inline uint8_t lpc_pic_slave_trigger_irq10_ecl_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_slave_trigger_irq10_ecl_rdf(__DN(t) *_dev)
{
    lpc_pic_pic_slave_trigger_t _regval = (lpc_pic_pic_slave_trigger_t )(io::read8(_dev->base, 0x4d1));
    return(lpc_pic_pic_slave_trigger_irq10_ecl_extract(_regval));
}

static inline uint8_t lpc_pic_slave_trigger_irq11_ecl_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_slave_trigger_irq11_ecl_rdf(__DN(t) *_dev)
{
    lpc_pic_pic_slave_trigger_t _regval = (lpc_pic_pic_slave_trigger_t )(io::read8(_dev->base, 0x4d1));
    return(lpc_pic_pic_slave_trigger_irq11_ecl_extract(_regval));
}

static inline uint8_t lpc_pic_slave_trigger_irq12_ecl_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_slave_trigger_irq12_ecl_rdf(__DN(t) *_dev)
{
    lpc_pic_pic_slave_trigger_t _regval = (lpc_pic_pic_slave_trigger_t )(io::read8(_dev->base, 0x4d1));
    return(lpc_pic_pic_slave_trigger_irq12_ecl_extract(_regval));
}

static inline uint8_t lpc_pic_slave_trigger_irq14_ecl_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_slave_trigger_irq14_ecl_rdf(__DN(t) *_dev)
{
    lpc_pic_pic_slave_trigger_t _regval = (lpc_pic_pic_slave_trigger_t )(io::read8(_dev->base, 0x4d1));
    return(lpc_pic_pic_slave_trigger_irq14_ecl_extract(_regval));
}

static inline uint8_t lpc_pic_slave_trigger_irq15_ecl_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_pic_slave_trigger_irq15_ecl_rdf(__DN(t) *_dev)
{
    lpc_pic_pic_slave_trigger_t _regval = (lpc_pic_pic_slave_trigger_t )(io::read8(_dev->base, 0x4d1));
    return(lpc_pic_pic_slave_trigger_irq15_ecl_extract(_regval));
}

static inline void lpc_pic_slave_trigger_irq9_ecl_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_pic_slave_trigger_irq9_ecl_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_pic_pic_slave_trigger_t _regval = (lpc_pic_pic_slave_trigger_t )(0x2 & (((lpc_pic_pic_slave_trigger_t )(_fieldval)) << 1));
    _regval = (_regval | (0xdc & ((lpc_pic_pic_slave_trigger_t )(io::read8(_dev->base, 0x4d1)))));
    // No read of register shadow required
    _regval = (_regval & 0xde);
    // No MB1 fields present
    io::write8(_dev->base, 0x4d1, _regval);
    // No shadow register to write to
}

static inline void lpc_pic_slave_trigger_irq10_ecl_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_pic_slave_trigger_irq10_ecl_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_pic_pic_slave_trigger_t _regval = (lpc_pic_pic_slave_trigger_t )(0x4 & (((lpc_pic_pic_slave_trigger_t )(_fieldval)) << 2));
    _regval = (_regval | (0xda & ((lpc_pic_pic_slave_trigger_t )(io::read8(_dev->base, 0x4d1)))));
    // No read of register shadow required
    _regval = (_regval & 0xde);
    // No MB1 fields present
    io::write8(_dev->base, 0x4d1, _regval);
    // No shadow register to write to
}

static inline void lpc_pic_slave_trigger_irq11_ecl_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_pic_slave_trigger_irq11_ecl_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_pic_pic_slave_trigger_t _regval = (lpc_pic_pic_slave_trigger_t )(0x8 & (((lpc_pic_pic_slave_trigger_t )(_fieldval)) << 3));
    _regval = (_regval | (0xd6 & ((lpc_pic_pic_slave_trigger_t )(io::read8(_dev->base, 0x4d1)))));
    // No read of register shadow required
    _regval = (_regval & 0xde);
    // No MB1 fields present
    io::write8(_dev->base, 0x4d1, _regval);
    // No shadow register to write to
}

static inline void lpc_pic_slave_trigger_irq12_ecl_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_pic_slave_trigger_irq12_ecl_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_pic_pic_slave_trigger_t _regval = (lpc_pic_pic_slave_trigger_t )(0x10 & (((lpc_pic_pic_slave_trigger_t )(_fieldval)) << 4));
    _regval = (_regval | (0xce & ((lpc_pic_pic_slave_trigger_t )(io::read8(_dev->base, 0x4d1)))));
    // No read of register shadow required
    _regval = (_regval & 0xde);
    // No MB1 fields present
    io::write8(_dev->base, 0x4d1, _regval);
    // No shadow register to write to
}

static inline void lpc_pic_slave_trigger_irq14_ecl_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_pic_slave_trigger_irq14_ecl_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_pic_pic_slave_trigger_t _regval = (lpc_pic_pic_slave_trigger_t )(0x40 & (((lpc_pic_pic_slave_trigger_t )(_fieldval)) << 6));
    _regval = (_regval | (0x9e & ((lpc_pic_pic_slave_trigger_t )(io::read8(_dev->base, 0x4d1)))));
    // No read of register shadow required
    _regval = (_regval & 0xde);
    // No MB1 fields present
    io::write8(_dev->base, 0x4d1, _regval);
    // No shadow register to write to
}

static inline void lpc_pic_slave_trigger_irq15_ecl_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_pic_slave_trigger_irq15_ecl_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_pic_pic_slave_trigger_t _regval = (lpc_pic_pic_slave_trigger_t )(0x80 & (((lpc_pic_pic_slave_trigger_t )(_fieldval)) << 7));
    _regval = (_regval | (0x5e & ((lpc_pic_pic_slave_trigger_t )(io::read8(_dev->base, 0x4d1)))));
    // No read of register shadow required
    _regval = (_regval & 0xde);
    // No MB1 fields present
    io::write8(_dev->base, 0x4d1, _regval);
    // No shadow register to write to
}

static inline dout_t& operator<<(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, __DN(t) *_dev)
{
    _os << ("-------------------------\n");
    _os << ("Dump of device lpc_pic (LPC IHC PIC function):\n");
    lpc_pic_master_icw1_pr(_os, _dev);
    lpc_pic_master_ocw2_pr(_os, _dev);
    lpc_pic_master_ocw3_pr(_os, _dev);
    lpc_pic_master_ocw3rd_pr(_os, _dev);
    lpc_pic_master_icw2_pr(_os, _dev);
    lpc_pic_master_icw3_pr(_os, _dev);
    lpc_pic_master_icw4_pr(_os, _dev);
    lpc_pic_master_ocw1_pr(_os, _dev);
    lpc_pic_slave_icw1_pr(_os, _dev);
    lpc_pic_slave_ocw2_pr(_os, _dev);
    lpc_pic_slave_ocw3_pr(_os, _dev);
    lpc_pic_slave_ocw3rd_pr(_os, _dev);
    lpc_pic_slave_icw2_pr(_os, _dev);
    lpc_pic_slave_icw3_pr(_os, _dev);
    lpc_pic_slave_icw4_pr(_os, _dev);
    lpc_pic_slave_ocw1_pr(_os, _dev);
    lpc_pic_master_trigger_pr(_os, _dev);
    lpc_pic_slave_trigger_pr(_os, _dev);
    _os << ("End of dump of device lpc_pic\n");
    _os << ("-------------------------\n");
    return(_os);
}

#undef __DN
