#pragma once
/*
 * Device Definition: LPC IHC I/O APIC function
 * 
 * Automatically Generated from Spec.
 * Using a modified mackerel.
 * 
 * DO NOT EDIT!
 */
#include "util/debug.h"
#include "util/io.h"
#undef __DN
#define __DN(x) lpc_ioapic ## _ ## x
/*
 * Constants defn: lpc_ioapic.delivery_mode (Delivery Mode)
 *  - no width specified
 */
HOH_STRONG_TYPEDEF( uint8_t , lpc_ioapic_delivery_mode_t);
#define lpc_ioapic_fixed ((lpc_ioapic_delivery_mode_t)0x0)
#define lpc_ioapic_lowest ((lpc_ioapic_delivery_mode_t)0x1)
#define lpc_ioapic_smi ((lpc_ioapic_delivery_mode_t)0x2)
#define lpc_ioapic_nmi ((lpc_ioapic_delivery_mode_t)0x4)
#define lpc_ioapic_init ((lpc_ioapic_delivery_mode_t)0x5)
#define lpc_ioapic_extint ((lpc_ioapic_delivery_mode_t)0x7)

static inline const char* lpc_ioapic_delivery_mode_describe(lpc_ioapic_delivery_mode_t _e) __attribute__ ((always_inline));
static inline const char* lpc_ioapic_delivery_mode_describe(lpc_ioapic_delivery_mode_t _e)
{
    switch ((uint8_t )(_e)) {
    case (uint8_t )(0x0):
        return("fixed: Fixed");
    case (uint8_t )(0x1):
        return("lowest: Lowest Priority");
    case (uint8_t )(0x2):
        return("smi: SMI (System Management Interrupt)");
    case (uint8_t )(0x4):
        return("nmi: NMI (Non-maskable Interrupt)");
    case (uint8_t )(0x5):
        return("init: INIT");
    case (uint8_t )(0x7):
        return("extint: ExtINT");
    default:
        return(NULL);
    }
}

static inline dout_t& operator<<(dout_t& _os, lpc_ioapic_delivery_mode_t _e) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, lpc_ioapic_delivery_mode_t _e)
{
    const char* d = lpc_ioapic_delivery_mode_describe(_e);
    if (d) {
        return(_os << d);
    } else {
        return((((_os << ("Unknown constant:")) << ("lpc_ioapic_delivery_mode_t")) << ("value:")) << ((uint64_t )(_e)));
    }
}

/*
 * Constants defn: lpc_ioapic.dest_mode (Destination Mode)
 *  - no width specified
 */
HOH_STRONG_TYPEDEF( uint8_t , lpc_ioapic_dest_mode_t);
#define lpc_ioapic_physical ((lpc_ioapic_dest_mode_t)0x0)
#define lpc_ioapic_logical ((lpc_ioapic_dest_mode_t)0x1)

static inline const char* lpc_ioapic_dest_mode_describe(lpc_ioapic_dest_mode_t _e) __attribute__ ((always_inline));
static inline const char* lpc_ioapic_dest_mode_describe(lpc_ioapic_dest_mode_t _e)
{
    switch ((uint8_t )(_e)) {
    case (uint8_t )(0x0):
        return("physical: Physical");
    case (uint8_t )(0x1):
        return("logical: Logical");
    default:
        return(NULL);
    }
}

static inline dout_t& operator<<(dout_t& _os, lpc_ioapic_dest_mode_t _e) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, lpc_ioapic_dest_mode_t _e)
{
    const char* d = lpc_ioapic_dest_mode_describe(_e);
    if (d) {
        return(_os << d);
    } else {
        return((((_os << ("Unknown constant:")) << ("lpc_ioapic_dest_mode_t")) << ("value:")) << ((uint64_t )(_e)));
    }
}

/*
 * Constants defn: lpc_ioapic.delivery_status (Delivery Status)
 *  - no width specified
 */
HOH_STRONG_TYPEDEF( uint8_t , lpc_ioapic_delivery_status_t);
#define lpc_ioapic_idle ((lpc_ioapic_delivery_status_t)0x0)
#define lpc_ioapic_pending ((lpc_ioapic_delivery_status_t)0x1)

static inline const char* lpc_ioapic_delivery_status_describe(lpc_ioapic_delivery_status_t _e) __attribute__ ((always_inline));
static inline const char* lpc_ioapic_delivery_status_describe(lpc_ioapic_delivery_status_t _e)
{
    switch ((uint8_t )(_e)) {
    case (uint8_t )(0x0):
        return("idle: Idle");
    case (uint8_t )(0x1):
        return("pending: Pending");
    default:
        return(NULL);
    }
}

static inline dout_t& operator<<(dout_t& _os, lpc_ioapic_delivery_status_t _e) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, lpc_ioapic_delivery_status_t _e)
{
    const char* d = lpc_ioapic_delivery_status_describe(_e);
    if (d) {
        return(_os << d);
    } else {
        return((((_os << ("Unknown constant:")) << ("lpc_ioapic_delivery_status_t")) << ("value:")) << ((uint64_t )(_e)));
    }
}

/*
 * Constants defn: lpc_ioapic.polarity (Interrupt Input Pin Polarity)
 *  - no width specified
 */
HOH_STRONG_TYPEDEF( uint8_t , lpc_ioapic_polarity_t);
#define lpc_ioapic_active_high ((lpc_ioapic_polarity_t)0x0)
#define lpc_ioapic_active_low ((lpc_ioapic_polarity_t)0x1)

static inline const char* lpc_ioapic_polarity_describe(lpc_ioapic_polarity_t _e) __attribute__ ((always_inline));
static inline const char* lpc_ioapic_polarity_describe(lpc_ioapic_polarity_t _e)
{
    switch ((uint8_t )(_e)) {
    case (uint8_t )(0x0):
        return("active_high: Active high");
    case (uint8_t )(0x1):
        return("active_low: Active low");
    default:
        return(NULL);
    }
}

static inline dout_t& operator<<(dout_t& _os, lpc_ioapic_polarity_t _e) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, lpc_ioapic_polarity_t _e)
{
    const char* d = lpc_ioapic_polarity_describe(_e);
    if (d) {
        return(_os << d);
    } else {
        return((((_os << ("Unknown constant:")) << ("lpc_ioapic_polarity_t")) << ("value:")) << ((uint64_t )(_e)));
    }
}

/*
 * Constants defn: lpc_ioapic.trigger_mode (Trigger Mode)
 *  - no width specified
 */
HOH_STRONG_TYPEDEF( uint8_t , lpc_ioapic_trigger_mode_t);
#define lpc_ioapic_edge ((lpc_ioapic_trigger_mode_t)0x0)
#define lpc_ioapic_level ((lpc_ioapic_trigger_mode_t)0x1)

static inline const char* lpc_ioapic_trigger_mode_describe(lpc_ioapic_trigger_mode_t _e) __attribute__ ((always_inline));
static inline const char* lpc_ioapic_trigger_mode_describe(lpc_ioapic_trigger_mode_t _e)
{
    switch ((uint8_t )(_e)) {
    case (uint8_t )(0x0):
        return("edge: Edge Triggered");
    case (uint8_t )(0x1):
        return("level: Level Triggered");
    default:
        return(NULL);
    }
}

static inline dout_t& operator<<(dout_t& _os, lpc_ioapic_trigger_mode_t _e) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, lpc_ioapic_trigger_mode_t _e)
{
    const char* d = lpc_ioapic_trigger_mode_describe(_e);
    if (d) {
        return(_os << d);
    } else {
        return((((_os << ("Unknown constant:")) << ("lpc_ioapic_trigger_mode_t")) << ("value:")) << ((uint64_t )(_e)));
    }
}

/*
 * Register type: lpc_ioapic_eoir_t
 * Description: Implicit type of EOI register
 * Fields:
 *   rec	(size 8, offset 0, init 0):	WO	Redirection Entry Clear
 *   _anon8	(size 24, offset 8, init 0):	MBZ	_
 */
HOH_STRONG_TYPEDEF( uint32_t , lpc_ioapic_eoir_t);
#define lpc_ioapic_eoir_default (lpc_ioapic_eoir_t )(0x0)
static inline uint8_t lpc_ioapic_eoir_rec_extract(lpc_ioapic_eoir_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_ioapic_eoir_rec_extract(lpc_ioapic_eoir_t _regval)
{
    return((uint8_t )((_regval & 0xff) >> 0));
}

static inline lpc_ioapic_eoir_t lpc_ioapic_eoir_rec_insert(lpc_ioapic_eoir_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_ioapic_eoir_t lpc_ioapic_eoir_rec_insert(lpc_ioapic_eoir_t _regval, uint8_t _fieldval)
{
    return((lpc_ioapic_eoir_t )((_regval & 0xffffff00) | (0xff & (((lpc_ioapic_eoir_t )(_fieldval)) << 0))));
}

static inline dout_t& operator<<(dout_t& _os, lpc_ioapic_eoir_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, lpc_ioapic_eoir_t _regval)
{
    ((_os << (" rec =\t")) << lpc_ioapic_eoir_rec_extract(_regval)) << ("\t(Redirection Entry Clear)\n");
    return(_os);
}

/*
 * Register type: lpc_ioapic_id_t
 * Description: Implicit type of Identification register
 * Fields:
 *   _anon0	(size 15, offset 0, init 0):	RSVD	_
 *   spb	(size 1, offset 15, init 0):	RW	Scratchpad bit
 *   _anon16	(size 8, offset 16, init 0):	RSVD	_
 *   id	(size 4, offset 24, init 0):	RW	APIC ID
 *   _anon28	(size 4, offset 28, init 0):	RSVD	_
 */
HOH_STRONG_TYPEDEF( uint32_t , lpc_ioapic_id_t);
#define lpc_ioapic_id_default (lpc_ioapic_id_t )(0x0)
static inline uint8_t lpc_ioapic_id_spb_extract(lpc_ioapic_id_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_ioapic_id_spb_extract(lpc_ioapic_id_t _regval)
{
    return((uint8_t )((_regval & 0x8000) >> 15));
}

static inline lpc_ioapic_id_t lpc_ioapic_id_spb_insert(lpc_ioapic_id_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_ioapic_id_t lpc_ioapic_id_spb_insert(lpc_ioapic_id_t _regval, uint8_t _fieldval)
{
    return((lpc_ioapic_id_t )((_regval & 0xffff7fff) | (0x8000 & (((lpc_ioapic_id_t )(_fieldval)) << 15))));
}

static inline uint8_t lpc_ioapic_id_id_extract(lpc_ioapic_id_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_ioapic_id_id_extract(lpc_ioapic_id_t _regval)
{
    return((uint8_t )((_regval & 0xf000000) >> 24));
}

static inline lpc_ioapic_id_t lpc_ioapic_id_id_insert(lpc_ioapic_id_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_ioapic_id_t lpc_ioapic_id_id_insert(lpc_ioapic_id_t _regval, uint8_t _fieldval)
{
    return((lpc_ioapic_id_t )((_regval & 0xf0ffffff) | (0xf000000 & (((lpc_ioapic_id_t )(_fieldval)) << 24))));
}

static inline dout_t& operator<<(dout_t& _os, lpc_ioapic_id_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, lpc_ioapic_id_t _regval)
{
    ((_os << (" spb =\t")) << lpc_ioapic_id_spb_extract(_regval)) << ("\t(Scratchpad bit)\n");
    ((_os << (" id =\t")) << lpc_ioapic_id_id_extract(_regval)) << ("\t(APIC ID)\n");
    return(_os);
}

/*
 * Register type: lpc_ioapic_ver_t
 * Description: Implicit type of Version register
 * Fields:
 *   ver	(size 8, offset 0, init 0):	RO	Version
 *   _anon8	(size 7, offset 8, init 0):	RSVD	_
 *   prq	(size 1, offset 15, init 0):	RO	Pin assertion register non-support
 *   mre	(size 8, offset 16, init 0):	RO	Maximum redirection entries
 *   _anon24	(size 8, offset 24, init 0):	RSVD	_
 */
HOH_STRONG_TYPEDEF( uint32_t , lpc_ioapic_ver_t);
#define lpc_ioapic_ver_default (lpc_ioapic_ver_t )(0x0)
static inline uint8_t lpc_ioapic_ver_ver_extract(lpc_ioapic_ver_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_ioapic_ver_ver_extract(lpc_ioapic_ver_t _regval)
{
    return((uint8_t )((_regval & 0xff) >> 0));
}

static inline lpc_ioapic_ver_t lpc_ioapic_ver_ver_insert(lpc_ioapic_ver_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_ioapic_ver_t lpc_ioapic_ver_ver_insert(lpc_ioapic_ver_t _regval, uint8_t _fieldval)
{
    return((lpc_ioapic_ver_t )((_regval & 0xffffff00) | (0xff & (((lpc_ioapic_ver_t )(_fieldval)) << 0))));
}

static inline uint8_t lpc_ioapic_ver_prq_extract(lpc_ioapic_ver_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_ioapic_ver_prq_extract(lpc_ioapic_ver_t _regval)
{
    return((uint8_t )((_regval & 0x8000) >> 15));
}

static inline lpc_ioapic_ver_t lpc_ioapic_ver_prq_insert(lpc_ioapic_ver_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_ioapic_ver_t lpc_ioapic_ver_prq_insert(lpc_ioapic_ver_t _regval, uint8_t _fieldval)
{
    return((lpc_ioapic_ver_t )((_regval & 0xffff7fff) | (0x8000 & (((lpc_ioapic_ver_t )(_fieldval)) << 15))));
}

static inline uint8_t lpc_ioapic_ver_mre_extract(lpc_ioapic_ver_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_ioapic_ver_mre_extract(lpc_ioapic_ver_t _regval)
{
    return((uint8_t )((_regval & 0xff0000) >> 16));
}

static inline lpc_ioapic_ver_t lpc_ioapic_ver_mre_insert(lpc_ioapic_ver_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_ioapic_ver_t lpc_ioapic_ver_mre_insert(lpc_ioapic_ver_t _regval, uint8_t _fieldval)
{
    return((lpc_ioapic_ver_t )((_regval & 0xff00ffff) | (0xff0000 & (((lpc_ioapic_ver_t )(_fieldval)) << 16))));
}

static inline dout_t& operator<<(dout_t& _os, lpc_ioapic_ver_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, lpc_ioapic_ver_t _regval)
{
    ((_os << (" ver =\t")) << lpc_ioapic_ver_ver_extract(_regval)) << ("\t(Version)\n");
    ((_os << (" prq =\t")) << lpc_ioapic_ver_prq_extract(_regval)) << ("\t(Pin assertion register non-support)\n");
    ((_os << (" mre =\t")) << lpc_ioapic_ver_mre_extract(_regval)) << ("\t(Maximum redirection entries)\n");
    return(_os);
}

/*
 * Register type: lpc_ioapic_arb_t
 * Description: Implicit type of Arbitration register
 * Fields:
 *   _anon0	(size 24, offset 0, init 0):	RSVD	_
 *   id	(size 4, offset 24, init 0):	RO	IOAPIC Arbitration ID
 *   _anon28	(size 4, offset 28, init 0):	RSVD	_
 */
HOH_STRONG_TYPEDEF( uint32_t , lpc_ioapic_arb_t);
#define lpc_ioapic_arb_default (lpc_ioapic_arb_t )(0x0)
static inline uint8_t lpc_ioapic_arb_id_extract(lpc_ioapic_arb_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_ioapic_arb_id_extract(lpc_ioapic_arb_t _regval)
{
    return((uint8_t )((_regval & 0xf000000) >> 24));
}

static inline lpc_ioapic_arb_t lpc_ioapic_arb_id_insert(lpc_ioapic_arb_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_ioapic_arb_t lpc_ioapic_arb_id_insert(lpc_ioapic_arb_t _regval, uint8_t _fieldval)
{
    return((lpc_ioapic_arb_t )((_regval & 0xf0ffffff) | (0xf000000 & (((lpc_ioapic_arb_t )(_fieldval)) << 24))));
}

static inline dout_t& operator<<(dout_t& _os, lpc_ioapic_arb_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, lpc_ioapic_arb_t _regval)
{
    ((_os << (" id =\t")) << lpc_ioapic_arb_id_extract(_regval)) << ("\t(IOAPIC Arbitration ID)\n");
    return(_os);
}

/*
 * Register type: lpc_ioapic_redir_tbl_t
 * Description: Redirection Table
 * Fields:
 *   vector	(size 8, offset 0, init 0):	NOATTR	Vector
 *   mode	(size 3, offset 8, init 0):	NOATTR	Delivery mode
 *   destmode	(size 1, offset 11, init 0):	NOATTR	Destination mode
 *   status	(size 1, offset 12, init 0):	RO	Delivery status
 *   polarity	(size 1, offset 13, init 0):	NOATTR	Interrupt input pin polarity
 *   rirr	(size 1, offset 14, init 0):	RO	Remote IRR
 *   trigger	(size 1, offset 15, init 0):	NOATTR	Trigger mode
 *   mask	(size 1, offset 16, init 0):	NOATTR	Mask
 *   _anon17	(size 31, offset 17, init 0):	RSVD	_
 *   edid	(size 8, offset 48, init 0):	RO	Extended destination ID
 *   dest	(size 8, offset 56, init 0):	NOATTR	Destination
 */
HOH_STRONG_TYPEDEF( uint64_t , lpc_ioapic_redir_tbl_t);
#define lpc_ioapic_redir_tbl_default (lpc_ioapic_redir_tbl_t )(0x0)
static inline uint8_t lpc_ioapic_redir_tbl_vector_extract(lpc_ioapic_redir_tbl_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_ioapic_redir_tbl_vector_extract(lpc_ioapic_redir_tbl_t _regval)
{
    return((uint8_t )((_regval & 0xff) >> 0));
}

static inline lpc_ioapic_redir_tbl_t lpc_ioapic_redir_tbl_vector_insert(lpc_ioapic_redir_tbl_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_ioapic_redir_tbl_t lpc_ioapic_redir_tbl_vector_insert(lpc_ioapic_redir_tbl_t _regval, uint8_t _fieldval)
{
    return((lpc_ioapic_redir_tbl_t )((_regval & 0xffffffffffffff00) | (0xff & (((lpc_ioapic_redir_tbl_t )(_fieldval)) << 0))));
}

static inline lpc_ioapic_delivery_mode_t lpc_ioapic_redir_tbl_mode_extract(lpc_ioapic_redir_tbl_t _regval) __attribute__ ((always_inline));
static inline lpc_ioapic_delivery_mode_t lpc_ioapic_redir_tbl_mode_extract(lpc_ioapic_redir_tbl_t _regval)
{
    return((lpc_ioapic_delivery_mode_t )((_regval & 0x700) >> 8));
}

static inline lpc_ioapic_redir_tbl_t lpc_ioapic_redir_tbl_mode_insert(lpc_ioapic_redir_tbl_t _regval, lpc_ioapic_delivery_mode_t _fieldval) __attribute__ ((always_inline));
static inline lpc_ioapic_redir_tbl_t lpc_ioapic_redir_tbl_mode_insert(lpc_ioapic_redir_tbl_t _regval, lpc_ioapic_delivery_mode_t _fieldval)
{
    return((lpc_ioapic_redir_tbl_t )((_regval & 0xfffffffffffff8ff) | (0x700 & (((lpc_ioapic_redir_tbl_t )(_fieldval)) << 8))));
}

static inline lpc_ioapic_dest_mode_t lpc_ioapic_redir_tbl_destmode_extract(lpc_ioapic_redir_tbl_t _regval) __attribute__ ((always_inline));
static inline lpc_ioapic_dest_mode_t lpc_ioapic_redir_tbl_destmode_extract(lpc_ioapic_redir_tbl_t _regval)
{
    return((lpc_ioapic_dest_mode_t )((_regval & 0x800) >> 11));
}

static inline lpc_ioapic_redir_tbl_t lpc_ioapic_redir_tbl_destmode_insert(lpc_ioapic_redir_tbl_t _regval, lpc_ioapic_dest_mode_t _fieldval) __attribute__ ((always_inline));
static inline lpc_ioapic_redir_tbl_t lpc_ioapic_redir_tbl_destmode_insert(lpc_ioapic_redir_tbl_t _regval, lpc_ioapic_dest_mode_t _fieldval)
{
    return((lpc_ioapic_redir_tbl_t )((_regval & 0xfffffffffffff7ff) | (0x800 & (((lpc_ioapic_redir_tbl_t )(_fieldval)) << 11))));
}

static inline lpc_ioapic_delivery_status_t lpc_ioapic_redir_tbl_status_extract(lpc_ioapic_redir_tbl_t _regval) __attribute__ ((always_inline));
static inline lpc_ioapic_delivery_status_t lpc_ioapic_redir_tbl_status_extract(lpc_ioapic_redir_tbl_t _regval)
{
    return((lpc_ioapic_delivery_status_t )((_regval & 0x1000) >> 12));
}

static inline lpc_ioapic_redir_tbl_t lpc_ioapic_redir_tbl_status_insert(lpc_ioapic_redir_tbl_t _regval, lpc_ioapic_delivery_status_t _fieldval) __attribute__ ((always_inline));
static inline lpc_ioapic_redir_tbl_t lpc_ioapic_redir_tbl_status_insert(lpc_ioapic_redir_tbl_t _regval, lpc_ioapic_delivery_status_t _fieldval)
{
    return((lpc_ioapic_redir_tbl_t )((_regval & 0xffffffffffffefff) | (0x1000 & (((lpc_ioapic_redir_tbl_t )(_fieldval)) << 12))));
}

static inline lpc_ioapic_polarity_t lpc_ioapic_redir_tbl_polarity_extract(lpc_ioapic_redir_tbl_t _regval) __attribute__ ((always_inline));
static inline lpc_ioapic_polarity_t lpc_ioapic_redir_tbl_polarity_extract(lpc_ioapic_redir_tbl_t _regval)
{
    return((lpc_ioapic_polarity_t )((_regval & 0x2000) >> 13));
}

static inline lpc_ioapic_redir_tbl_t lpc_ioapic_redir_tbl_polarity_insert(lpc_ioapic_redir_tbl_t _regval, lpc_ioapic_polarity_t _fieldval) __attribute__ ((always_inline));
static inline lpc_ioapic_redir_tbl_t lpc_ioapic_redir_tbl_polarity_insert(lpc_ioapic_redir_tbl_t _regval, lpc_ioapic_polarity_t _fieldval)
{
    return((lpc_ioapic_redir_tbl_t )((_regval & 0xffffffffffffdfff) | (0x2000 & (((lpc_ioapic_redir_tbl_t )(_fieldval)) << 13))));
}

static inline uint8_t lpc_ioapic_redir_tbl_rirr_extract(lpc_ioapic_redir_tbl_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_ioapic_redir_tbl_rirr_extract(lpc_ioapic_redir_tbl_t _regval)
{
    return((uint8_t )((_regval & 0x4000) >> 14));
}

static inline lpc_ioapic_redir_tbl_t lpc_ioapic_redir_tbl_rirr_insert(lpc_ioapic_redir_tbl_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_ioapic_redir_tbl_t lpc_ioapic_redir_tbl_rirr_insert(lpc_ioapic_redir_tbl_t _regval, uint8_t _fieldval)
{
    return((lpc_ioapic_redir_tbl_t )((_regval & 0xffffffffffffbfff) | (0x4000 & (((lpc_ioapic_redir_tbl_t )(_fieldval)) << 14))));
}

static inline lpc_ioapic_trigger_mode_t lpc_ioapic_redir_tbl_trigger_extract(lpc_ioapic_redir_tbl_t _regval) __attribute__ ((always_inline));
static inline lpc_ioapic_trigger_mode_t lpc_ioapic_redir_tbl_trigger_extract(lpc_ioapic_redir_tbl_t _regval)
{
    return((lpc_ioapic_trigger_mode_t )((_regval & 0x8000) >> 15));
}

static inline lpc_ioapic_redir_tbl_t lpc_ioapic_redir_tbl_trigger_insert(lpc_ioapic_redir_tbl_t _regval, lpc_ioapic_trigger_mode_t _fieldval) __attribute__ ((always_inline));
static inline lpc_ioapic_redir_tbl_t lpc_ioapic_redir_tbl_trigger_insert(lpc_ioapic_redir_tbl_t _regval, lpc_ioapic_trigger_mode_t _fieldval)
{
    return((lpc_ioapic_redir_tbl_t )((_regval & 0xffffffffffff7fff) | (0x8000 & (((lpc_ioapic_redir_tbl_t )(_fieldval)) << 15))));
}

static inline uint8_t lpc_ioapic_redir_tbl_mask_extract(lpc_ioapic_redir_tbl_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_ioapic_redir_tbl_mask_extract(lpc_ioapic_redir_tbl_t _regval)
{
    return((uint8_t )((_regval & 0x10000) >> 16));
}

static inline lpc_ioapic_redir_tbl_t lpc_ioapic_redir_tbl_mask_insert(lpc_ioapic_redir_tbl_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_ioapic_redir_tbl_t lpc_ioapic_redir_tbl_mask_insert(lpc_ioapic_redir_tbl_t _regval, uint8_t _fieldval)
{
    return((lpc_ioapic_redir_tbl_t )((_regval & 0xfffffffffffeffff) | (0x10000 & (((lpc_ioapic_redir_tbl_t )(_fieldval)) << 16))));
}

static inline uint8_t lpc_ioapic_redir_tbl_edid_extract(lpc_ioapic_redir_tbl_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_ioapic_redir_tbl_edid_extract(lpc_ioapic_redir_tbl_t _regval)
{
    return((uint8_t )((_regval & 0xff000000000000) >> 48));
}

static inline lpc_ioapic_redir_tbl_t lpc_ioapic_redir_tbl_edid_insert(lpc_ioapic_redir_tbl_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_ioapic_redir_tbl_t lpc_ioapic_redir_tbl_edid_insert(lpc_ioapic_redir_tbl_t _regval, uint8_t _fieldval)
{
    return((lpc_ioapic_redir_tbl_t )((_regval & 0xff00ffffffffffff) | (0xff000000000000 & (((lpc_ioapic_redir_tbl_t )(_fieldval)) << 48))));
}

static inline uint8_t lpc_ioapic_redir_tbl_dest_extract(lpc_ioapic_redir_tbl_t _regval) __attribute__ ((always_inline));
static inline uint8_t lpc_ioapic_redir_tbl_dest_extract(lpc_ioapic_redir_tbl_t _regval)
{
    return((uint8_t )((_regval & 0xff00000000000000) >> 56));
}

static inline lpc_ioapic_redir_tbl_t lpc_ioapic_redir_tbl_dest_insert(lpc_ioapic_redir_tbl_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline lpc_ioapic_redir_tbl_t lpc_ioapic_redir_tbl_dest_insert(lpc_ioapic_redir_tbl_t _regval, uint8_t _fieldval)
{
    return((lpc_ioapic_redir_tbl_t )((_regval & 0xffffffffffffff) | (0xff00000000000000 & (((lpc_ioapic_redir_tbl_t )(_fieldval)) << 56))));
}

static inline dout_t& operator<<(dout_t& _os, lpc_ioapic_redir_tbl_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, lpc_ioapic_redir_tbl_t _regval)
{
    ((_os << (" vector =\t")) << lpc_ioapic_redir_tbl_vector_extract(_regval)) << ("\t(Vector)\n");
    ((_os << (" mode =\t")) << lpc_ioapic_redir_tbl_mode_extract(_regval)) << ("\t(Delivery mode)\n");
    ((_os << (" destmode =\t")) << lpc_ioapic_redir_tbl_destmode_extract(_regval)) << ("\t(Destination mode)\n");
    ((_os << (" status =\t")) << lpc_ioapic_redir_tbl_status_extract(_regval)) << ("\t(Delivery status)\n");
    ((_os << (" polarity =\t")) << lpc_ioapic_redir_tbl_polarity_extract(_regval)) << ("\t(Interrupt input pin polarity)\n");
    ((_os << (" rirr =\t")) << lpc_ioapic_redir_tbl_rirr_extract(_regval)) << ("\t(Remote IRR)\n");
    ((_os << (" trigger =\t")) << lpc_ioapic_redir_tbl_trigger_extract(_regval)) << ("\t(Trigger mode)\n");
    ((_os << (" mask =\t")) << lpc_ioapic_redir_tbl_mask_extract(_regval)) << ("\t(Mask)\n");
    ((_os << (" edid =\t")) << lpc_ioapic_redir_tbl_edid_extract(_regval)) << ("\t(Extended destination ID)\n");
    ((_os << (" dest =\t")) << lpc_ioapic_redir_tbl_dest_extract(_regval)) << ("\t(Destination)\n");
    return(_os);
}

/*
 * Device representation structure
 */
struct __DN(t) {
    addr_t base;
    lpc_ioapic_eoir_t eoir_shadow;
};

/*
 * Initial register values (currently 0)
 */
enum lpc_ioapic_initials {
    lpc_ioapic_ind_initial = 0x0,
    lpc_ioapic_wdw_initial = 0x0,
    lpc_ioapic_eoir_initial = 0x0,
    lpc_ioapic_id_initial = 0x0,
    lpc_ioapic_ver_initial = 0x0,
    lpc_ioapic_arb_initial = 0x0,
    lpc_ioapic_redirtbl_initial = 0x0
};

/*
 * Device Initialization function
 */
static inline void lpc_ioapic_initialize(__DN(t) *_dev, addr_t base) __attribute__ ((always_inline));
static inline void lpc_ioapic_initialize(__DN(t) *_dev, addr_t base)
{
    _dev->base = base;
}

/*
 * Include access functions for user-defined spaces
 */
#include "generated/lpc_ioapic.spaces.h"
/*
 * Register ind: Index
 * Type: lpc_ioapic.uint32 (primitive type)
 */
static inline uint32_t lpc_ioapic_ind_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint32_t lpc_ioapic_ind_rawrd(__DN(t) *_dev)
{
    return((uint32_t )(mmio::read32(_dev->base, 0x0)));
}

static inline uint32_t lpc_ioapic_ind_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint32_t lpc_ioapic_ind_rd(__DN(t) *_dev)
{
    return((uint32_t )(mmio::read32(_dev->base, 0x0)));
}

static inline void lpc_ioapic_ind_rawwr(__DN(t) *_dev, uint32_t _regval) __attribute__ ((always_inline));
static inline void lpc_ioapic_ind_rawwr(__DN(t) *_dev, uint32_t _regval)
{
    mmio::write32(_dev->base, 0x0, _regval);
}

static inline void lpc_ioapic_ind_wr(__DN(t) *_dev, uint32_t _regval) __attribute__ ((always_inline));
static inline void lpc_ioapic_ind_wr(__DN(t) *_dev, uint32_t _regval)
{
    // No MB0 or RSVD fields present
    // No MB1 fields present
    // No pre-read of register required
    mmio::write32(_dev->base, 0x0, _regval);
}

static inline dout_t& lpc_ioapic_ind_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_ioapic_ind_pr(dout_t& _os, __DN(t) *_dev)
{
    uint32_t _regval = (uint32_t )(mmio::read32(_dev->base, 0x0));
    _os << ("Register ind (Index): ");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

/*
 * Register wdw: Window
 * Type: lpc_ioapic.uint32 (primitive type)
 */
static inline uint32_t lpc_ioapic_wdw_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint32_t lpc_ioapic_wdw_rawrd(__DN(t) *_dev)
{
    return((uint32_t )(mmio::read32(_dev->base, 0x10)));
}

static inline uint32_t lpc_ioapic_wdw_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint32_t lpc_ioapic_wdw_rd(__DN(t) *_dev)
{
    return((uint32_t )(mmio::read32(_dev->base, 0x10)));
}

static inline void lpc_ioapic_wdw_rawwr(__DN(t) *_dev, uint32_t _regval) __attribute__ ((always_inline));
static inline void lpc_ioapic_wdw_rawwr(__DN(t) *_dev, uint32_t _regval)
{
    mmio::write32(_dev->base, 0x10, _regval);
}

static inline void lpc_ioapic_wdw_wr(__DN(t) *_dev, uint32_t _regval) __attribute__ ((always_inline));
static inline void lpc_ioapic_wdw_wr(__DN(t) *_dev, uint32_t _regval)
{
    // No MB0 or RSVD fields present
    // No MB1 fields present
    // No pre-read of register required
    mmio::write32(_dev->base, 0x10, _regval);
}

static inline dout_t& lpc_ioapic_wdw_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_ioapic_wdw_pr(dout_t& _os, __DN(t) *_dev)
{
    uint32_t _regval = (uint32_t )(mmio::read32(_dev->base, 0x10));
    _os << ("Register wdw (Window): ");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

/*
 * Register eoir: EOI
 * Type: lpc_ioapic.eoir (Implicit type of EOI register)
 *   rec	(size 8, offset 0, init 0):	WO	Redirection Entry Clear
 *   _anon8	(size 24, offset 8, init 0):	MBZ	_
 */
static inline lpc_ioapic_eoir_t lpc_ioapic_eoir_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_ioapic_eoir_t lpc_ioapic_eoir_rawrd(__DN(t) *_dev)
{
    return((lpc_ioapic_eoir_t )(mmio::read32(_dev->base, 0x40)));
}

static inline lpc_ioapic_eoir_t lpc_ioapic_eoir_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_ioapic_eoir_t lpc_ioapic_eoir_rd(__DN(t) *_dev)
{
    return(_dev->eoir_shadow);
}

static inline void lpc_ioapic_eoir_rawwr(__DN(t) *_dev, lpc_ioapic_eoir_t _regval) __attribute__ ((always_inline));
static inline void lpc_ioapic_eoir_rawwr(__DN(t) *_dev, lpc_ioapic_eoir_t _regval)
{
    mmio::write32(_dev->base, 0x40, _regval);
}

static inline void lpc_ioapic_eoir_wr(__DN(t) *_dev, lpc_ioapic_eoir_t _regval) __attribute__ ((always_inline));
static inline void lpc_ioapic_eoir_wr(__DN(t) *_dev, lpc_ioapic_eoir_t _regval)
{
    _regval = (_regval & 0xff);
    // No MB1 fields present
    // No pre-read of register required
    mmio::write32(_dev->base, 0x40, _regval);
}

static inline dout_t& lpc_ioapic_eoir_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_ioapic_eoir_pr(dout_t& _os, __DN(t) *_dev)
{
    lpc_ioapic_eoir_t _regval = _dev->eoir_shadow;
    _os << ("Register eoir (EOI): ");
    _os << ("\n");
    ((_os << (" rec =\t")) << lpc_ioapic_eoir_rec_extract(_regval)) << ("\t(Redirection Entry Clear)\n");
    // _anon8 is anonymous
    return(_os);
}

static inline uint8_t lpc_ioapic_eoir_rec_rd_shadow(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_ioapic_eoir_rec_rd_shadow(__DN(t) *_dev)
{
    return(lpc_ioapic_eoir_rec_extract(_dev->eoir_shadow));
}

static inline void lpc_ioapic_eoir_rec_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_ioapic_eoir_rec_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_ioapic_eoir_t _regval = (lpc_ioapic_eoir_t )(0xff & (((lpc_ioapic_eoir_t )(_fieldval)) << 0));
    // No pre-read of register required
    // No read of register shadow required
    _regval = (_regval & 0xff);
    // No MB1 fields present
    mmio::write32(_dev->base, 0x40, _regval);
    _dev->eoir_shadow = _regval;
}

/*
 * Register id: Identification
 * Type: lpc_ioapic.id (Implicit type of Identification register)
 *   _anon0	(size 15, offset 0, init 0):	RSVD	_
 *   spb	(size 1, offset 15, init 0):	RW	Scratchpad bit
 *   _anon16	(size 8, offset 16, init 0):	RSVD	_
 *   id	(size 4, offset 24, init 0):	RW	APIC ID
 *   _anon28	(size 4, offset 28, init 0):	RSVD	_
 */
static inline lpc_ioapic_id_t lpc_ioapic_id_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_ioapic_id_t lpc_ioapic_id_rawrd(__DN(t) *_dev)
{
    return((lpc_ioapic_id_t )(__DN(ioapic)::read32(_dev, 0x0)));
}

static inline lpc_ioapic_id_t lpc_ioapic_id_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_ioapic_id_t lpc_ioapic_id_rd(__DN(t) *_dev)
{
    return((lpc_ioapic_id_t )(__DN(ioapic)::read32(_dev, 0x0)));
}

static inline void lpc_ioapic_id_rawwr(__DN(t) *_dev, lpc_ioapic_id_t _regval) __attribute__ ((always_inline));
static inline void lpc_ioapic_id_rawwr(__DN(t) *_dev, lpc_ioapic_id_t _regval)
{
    __DN(ioapic)::write32(_dev, 0x0, _regval);
}

static inline void lpc_ioapic_id_wr(__DN(t) *_dev, lpc_ioapic_id_t _regval) __attribute__ ((always_inline));
static inline void lpc_ioapic_id_wr(__DN(t) *_dev, lpc_ioapic_id_t _regval)
{
    _regval = (_regval & 0xf008000);
    // No MB1 fields present
    _regval = (_regval | (0xf0ff7fff & ((lpc_ioapic_id_t )(__DN(ioapic)::read32(_dev, 0x0)))));
    __DN(ioapic)::write32(_dev, 0x0, _regval);
}

static inline dout_t& lpc_ioapic_id_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_ioapic_id_pr(dout_t& _os, __DN(t) *_dev)
{
    lpc_ioapic_id_t _regval = (lpc_ioapic_id_t )(__DN(ioapic)::read32(_dev, 0x0));
    _os << ("Register id (Identification): ");
    _os << ("\n");
    // _anon0 is anonymous
    ((_os << (" spb =\t")) << lpc_ioapic_id_spb_extract(_regval)) << ("\t(Scratchpad bit)\n");
    // _anon16 is anonymous
    ((_os << (" id =\t")) << lpc_ioapic_id_id_extract(_regval)) << ("\t(APIC ID)\n");
    // _anon28 is anonymous
    return(_os);
}

static inline uint8_t lpc_ioapic_id_spb_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_ioapic_id_spb_rdf(__DN(t) *_dev)
{
    lpc_ioapic_id_t _regval = (lpc_ioapic_id_t )(__DN(ioapic)::read32(_dev, 0x0));
    return(lpc_ioapic_id_spb_extract(_regval));
}

static inline uint8_t lpc_ioapic_id_id_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_ioapic_id_id_rdf(__DN(t) *_dev)
{
    lpc_ioapic_id_t _regval = (lpc_ioapic_id_t )(__DN(ioapic)::read32(_dev, 0x0));
    return(lpc_ioapic_id_id_extract(_regval));
}

static inline void lpc_ioapic_id_spb_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_ioapic_id_spb_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_ioapic_id_t _regval = (lpc_ioapic_id_t )(0x8000 & (((lpc_ioapic_id_t )(_fieldval)) << 15));
    _regval = (_regval | (0xffff7fff & ((lpc_ioapic_id_t )(__DN(ioapic)::read32(_dev, 0x0)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    __DN(ioapic)::write32(_dev, 0x0, _regval);
    // No shadow register to write to
}

static inline void lpc_ioapic_id_id_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_ioapic_id_id_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    lpc_ioapic_id_t _regval = (lpc_ioapic_id_t )(0xf000000 & (((lpc_ioapic_id_t )(_fieldval)) << 24));
    _regval = (_regval | (0xf0ffffff & ((lpc_ioapic_id_t )(__DN(ioapic)::read32(_dev, 0x0)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    __DN(ioapic)::write32(_dev, 0x0, _regval);
    // No shadow register to write to
}

/*
 * Register ver: Version
 * Type: lpc_ioapic.ver (Implicit type of Version register)
 *   ver	(size 8, offset 0, init 0):	RO	Version
 *   _anon8	(size 7, offset 8, init 0):	RSVD	_
 *   prq	(size 1, offset 15, init 0):	RO	Pin assertion register non-support
 *   mre	(size 8, offset 16, init 0):	RO	Maximum redirection entries
 *   _anon24	(size 8, offset 24, init 0):	RSVD	_
 */
static inline lpc_ioapic_ver_t lpc_ioapic_ver_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_ioapic_ver_t lpc_ioapic_ver_rawrd(__DN(t) *_dev)
{
    return((lpc_ioapic_ver_t )(__DN(ioapic)::read32(_dev, 0x1)));
}

static inline lpc_ioapic_ver_t lpc_ioapic_ver_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_ioapic_ver_t lpc_ioapic_ver_rd(__DN(t) *_dev)
{
    return((lpc_ioapic_ver_t )(__DN(ioapic)::read32(_dev, 0x1)));
}

static inline void lpc_ioapic_ver_rawwr(__DN(t) *_dev, lpc_ioapic_ver_t _regval) __attribute__ ((always_inline));
static inline void lpc_ioapic_ver_rawwr(__DN(t) *_dev, lpc_ioapic_ver_t _regval)
{
    __DN(ioapic)::write32(_dev, 0x1, _regval);
}

// Register ver is not writeable
static inline dout_t& lpc_ioapic_ver_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_ioapic_ver_pr(dout_t& _os, __DN(t) *_dev)
{
    lpc_ioapic_ver_t _regval = (lpc_ioapic_ver_t )(__DN(ioapic)::read32(_dev, 0x1));
    _os << ("Register ver (Version): ");
    _os << ("\n");
    ((_os << (" ver =\t")) << lpc_ioapic_ver_ver_extract(_regval)) << ("\t(Version)\n");
    // _anon8 is anonymous
    ((_os << (" prq =\t")) << lpc_ioapic_ver_prq_extract(_regval)) << ("\t(Pin assertion register non-support)\n");
    ((_os << (" mre =\t")) << lpc_ioapic_ver_mre_extract(_regval)) << ("\t(Maximum redirection entries)\n");
    // _anon24 is anonymous
    return(_os);
}

static inline uint8_t lpc_ioapic_ver_ver_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_ioapic_ver_ver_rdf(__DN(t) *_dev)
{
    lpc_ioapic_ver_t _regval = (lpc_ioapic_ver_t )(__DN(ioapic)::read32(_dev, 0x1));
    return(lpc_ioapic_ver_ver_extract(_regval));
}

static inline uint8_t lpc_ioapic_ver_prq_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_ioapic_ver_prq_rdf(__DN(t) *_dev)
{
    lpc_ioapic_ver_t _regval = (lpc_ioapic_ver_t )(__DN(ioapic)::read32(_dev, 0x1));
    return(lpc_ioapic_ver_prq_extract(_regval));
}

static inline uint8_t lpc_ioapic_ver_mre_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_ioapic_ver_mre_rdf(__DN(t) *_dev)
{
    lpc_ioapic_ver_t _regval = (lpc_ioapic_ver_t )(__DN(ioapic)::read32(_dev, 0x1));
    return(lpc_ioapic_ver_mre_extract(_regval));
}

/*
 * Register arb: Arbitration
 * Type: lpc_ioapic.arb (Implicit type of Arbitration register)
 *   _anon0	(size 24, offset 0, init 0):	RSVD	_
 *   id	(size 4, offset 24, init 0):	RO	IOAPIC Arbitration ID
 *   _anon28	(size 4, offset 28, init 0):	RSVD	_
 */
static inline lpc_ioapic_arb_t lpc_ioapic_arb_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_ioapic_arb_t lpc_ioapic_arb_rawrd(__DN(t) *_dev)
{
    return((lpc_ioapic_arb_t )(__DN(ioapic)::read32(_dev, 0x2)));
}

static inline lpc_ioapic_arb_t lpc_ioapic_arb_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline lpc_ioapic_arb_t lpc_ioapic_arb_rd(__DN(t) *_dev)
{
    return((lpc_ioapic_arb_t )(__DN(ioapic)::read32(_dev, 0x2)));
}

static inline void lpc_ioapic_arb_rawwr(__DN(t) *_dev, lpc_ioapic_arb_t _regval) __attribute__ ((always_inline));
static inline void lpc_ioapic_arb_rawwr(__DN(t) *_dev, lpc_ioapic_arb_t _regval)
{
    __DN(ioapic)::write32(_dev, 0x2, _regval);
}

// Register arb is not writeable
static inline dout_t& lpc_ioapic_arb_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_ioapic_arb_pr(dout_t& _os, __DN(t) *_dev)
{
    lpc_ioapic_arb_t _regval = (lpc_ioapic_arb_t )(__DN(ioapic)::read32(_dev, 0x2));
    _os << ("Register arb (Arbitration): ");
    _os << ("\n");
    // _anon0 is anonymous
    ((_os << (" id =\t")) << lpc_ioapic_arb_id_extract(_regval)) << ("\t(IOAPIC Arbitration ID)\n");
    // _anon28 is anonymous
    return(_os);
}

static inline uint8_t lpc_ioapic_arb_id_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t lpc_ioapic_arb_id_rdf(__DN(t) *_dev)
{
    lpc_ioapic_arb_t _regval = (lpc_ioapic_arb_t )(__DN(ioapic)::read32(_dev, 0x2));
    return(lpc_ioapic_arb_id_extract(_regval));
}

/*
 * Register array redirtbl: redirtbl
 * Type: lpc_ioapic.redir_tbl (Redirection Table)
 *   vector	(size 8, offset 0, init 0):	RW	Vector
 *   mode	(size 3, offset 8, init 0):	RW	Delivery mode
 *   destmode	(size 1, offset 11, init 0):	RW	Destination mode
 *   status	(size 1, offset 12, init 0):	RO	Delivery status
 *   polarity	(size 1, offset 13, init 0):	RW	Interrupt input pin polarity
 *   rirr	(size 1, offset 14, init 0):	RO	Remote IRR
 *   trigger	(size 1, offset 15, init 0):	RW	Trigger mode
 *   mask	(size 1, offset 16, init 0):	RW	Mask
 *   _anon17	(size 31, offset 17, init 0):	RSVD	_
 *   edid	(size 8, offset 48, init 0):	RO	Extended destination ID
 *   dest	(size 8, offset 56, init 0):	RW	Destination
 */
static const size_t lpc_ioapic_redirtbl_length = 24;
static inline lpc_ioapic_redir_tbl_t lpc_ioapic_redirtbl_rawrd(__DN(t) *_dev, int _i) __attribute__ ((always_inline));
static inline lpc_ioapic_redir_tbl_t lpc_ioapic_redirtbl_rawrd(__DN(t) *_dev, int _i)
{
    return((lpc_ioapic_redir_tbl_t )(__DN(ioapic)::read64(_dev, 0x10 + (_i * (16 / 8)))));
}

static inline lpc_ioapic_redir_tbl_t lpc_ioapic_redirtbl_rd(__DN(t) *_dev, int _i) __attribute__ ((always_inline));
static inline lpc_ioapic_redir_tbl_t lpc_ioapic_redirtbl_rd(__DN(t) *_dev, int _i)
{
    return((lpc_ioapic_redir_tbl_t )(__DN(ioapic)::read64(_dev, 0x10 + (_i * (16 / 8)))));
}

static inline void lpc_ioapic_redirtbl_rawwr(__DN(t) *_dev, int _i, lpc_ioapic_redir_tbl_t _regval) __attribute__ ((always_inline));
static inline void lpc_ioapic_redirtbl_rawwr(__DN(t) *_dev, int _i, lpc_ioapic_redir_tbl_t _regval)
{
    __DN(ioapic)::write64(_dev, 0x10 + (_i * (16 / 8)), _regval);
}

static inline void lpc_ioapic_redirtbl_wr(__DN(t) *_dev, int _i, lpc_ioapic_redir_tbl_t _regval) __attribute__ ((always_inline));
static inline void lpc_ioapic_redirtbl_wr(__DN(t) *_dev, int _i, lpc_ioapic_redir_tbl_t _regval)
{
    _regval = (_regval & 0xffff00000001ffff);
    // No MB1 fields present
    _regval = (_regval | (0xfffffffe0000 & ((lpc_ioapic_redir_tbl_t )(__DN(ioapic)::read64(_dev, 0x10 + (_i * (16 / 8)))))));
    __DN(ioapic)::write64(_dev, 0x10 + (_i * (16 / 8)), _regval);
}

static inline dout_t& lpc_ioapic_redirtbl_pri(dout_t& _os, __DN(t) *_dev, int _i) __attribute__ ((always_inline));
static inline dout_t& lpc_ioapic_redirtbl_pri(dout_t& _os, __DN(t) *_dev, int _i)
{
    lpc_ioapic_redir_tbl_t _regval = (lpc_ioapic_redir_tbl_t )(__DN(ioapic)::read64(_dev, 0x10 + (_i * (16 / 8))));
    ((((_os << ("Register ")) << ("redirtbl")) << _i) << ("redirtbl")) << (":");
    _os << ("\n");
    ((_os << (" vector =\t")) << lpc_ioapic_redir_tbl_vector_extract(_regval)) << ("\t(Vector)\n");
    ((_os << (" mode =\t")) << lpc_ioapic_redir_tbl_mode_extract(_regval)) << ("\t(Delivery mode)\n");
    ((_os << (" destmode =\t")) << lpc_ioapic_redir_tbl_destmode_extract(_regval)) << ("\t(Destination mode)\n");
    ((_os << (" status =\t")) << lpc_ioapic_redir_tbl_status_extract(_regval)) << ("\t(Delivery status)\n");
    ((_os << (" polarity =\t")) << lpc_ioapic_redir_tbl_polarity_extract(_regval)) << ("\t(Interrupt input pin polarity)\n");
    ((_os << (" rirr =\t")) << lpc_ioapic_redir_tbl_rirr_extract(_regval)) << ("\t(Remote IRR)\n");
    ((_os << (" trigger =\t")) << lpc_ioapic_redir_tbl_trigger_extract(_regval)) << ("\t(Trigger mode)\n");
    ((_os << (" mask =\t")) << lpc_ioapic_redir_tbl_mask_extract(_regval)) << ("\t(Mask)\n");
    // _anon17 is anonymous
    ((_os << (" edid =\t")) << lpc_ioapic_redir_tbl_edid_extract(_regval)) << ("\t(Extended destination ID)\n");
    ((_os << (" dest =\t")) << lpc_ioapic_redir_tbl_dest_extract(_regval)) << ("\t(Destination)\n");
    return(_os);
}

static inline dout_t& lpc_ioapic_redirtbl_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& lpc_ioapic_redirtbl_pr(dout_t& _os, __DN(t) *_dev)
{
    int _i;
    for( _i = 0; _i < 24; _i++) {
        lpc_ioapic_redirtbl_pri(_os, _dev, _i);
    }
    return(_os);
}

static inline uint8_t lpc_ioapic_redirtbl_vector_rdf(__DN(t) *_dev, int _i) __attribute__ ((always_inline));
static inline uint8_t lpc_ioapic_redirtbl_vector_rdf(__DN(t) *_dev, int _i)
{
    lpc_ioapic_redir_tbl_t _regval = (lpc_ioapic_redir_tbl_t )(__DN(ioapic)::read64(_dev, 0x10 + (_i * (16 / 8))));
    return(lpc_ioapic_redir_tbl_vector_extract(_regval));
}

static inline lpc_ioapic_delivery_mode_t lpc_ioapic_redirtbl_mode_rdf(__DN(t) *_dev, int _i) __attribute__ ((always_inline));
static inline lpc_ioapic_delivery_mode_t lpc_ioapic_redirtbl_mode_rdf(__DN(t) *_dev, int _i)
{
    lpc_ioapic_redir_tbl_t _regval = (lpc_ioapic_redir_tbl_t )(__DN(ioapic)::read64(_dev, 0x10 + (_i * (16 / 8))));
    return(lpc_ioapic_redir_tbl_mode_extract(_regval));
}

static inline lpc_ioapic_dest_mode_t lpc_ioapic_redirtbl_destmode_rdf(__DN(t) *_dev, int _i) __attribute__ ((always_inline));
static inline lpc_ioapic_dest_mode_t lpc_ioapic_redirtbl_destmode_rdf(__DN(t) *_dev, int _i)
{
    lpc_ioapic_redir_tbl_t _regval = (lpc_ioapic_redir_tbl_t )(__DN(ioapic)::read64(_dev, 0x10 + (_i * (16 / 8))));
    return(lpc_ioapic_redir_tbl_destmode_extract(_regval));
}

static inline lpc_ioapic_delivery_status_t lpc_ioapic_redirtbl_status_rdf(__DN(t) *_dev, int _i) __attribute__ ((always_inline));
static inline lpc_ioapic_delivery_status_t lpc_ioapic_redirtbl_status_rdf(__DN(t) *_dev, int _i)
{
    lpc_ioapic_redir_tbl_t _regval = (lpc_ioapic_redir_tbl_t )(__DN(ioapic)::read64(_dev, 0x10 + (_i * (16 / 8))));
    return(lpc_ioapic_redir_tbl_status_extract(_regval));
}

static inline lpc_ioapic_polarity_t lpc_ioapic_redirtbl_polarity_rdf(__DN(t) *_dev, int _i) __attribute__ ((always_inline));
static inline lpc_ioapic_polarity_t lpc_ioapic_redirtbl_polarity_rdf(__DN(t) *_dev, int _i)
{
    lpc_ioapic_redir_tbl_t _regval = (lpc_ioapic_redir_tbl_t )(__DN(ioapic)::read64(_dev, 0x10 + (_i * (16 / 8))));
    return(lpc_ioapic_redir_tbl_polarity_extract(_regval));
}

static inline uint8_t lpc_ioapic_redirtbl_rirr_rdf(__DN(t) *_dev, int _i) __attribute__ ((always_inline));
static inline uint8_t lpc_ioapic_redirtbl_rirr_rdf(__DN(t) *_dev, int _i)
{
    lpc_ioapic_redir_tbl_t _regval = (lpc_ioapic_redir_tbl_t )(__DN(ioapic)::read64(_dev, 0x10 + (_i * (16 / 8))));
    return(lpc_ioapic_redir_tbl_rirr_extract(_regval));
}

static inline lpc_ioapic_trigger_mode_t lpc_ioapic_redirtbl_trigger_rdf(__DN(t) *_dev, int _i) __attribute__ ((always_inline));
static inline lpc_ioapic_trigger_mode_t lpc_ioapic_redirtbl_trigger_rdf(__DN(t) *_dev, int _i)
{
    lpc_ioapic_redir_tbl_t _regval = (lpc_ioapic_redir_tbl_t )(__DN(ioapic)::read64(_dev, 0x10 + (_i * (16 / 8))));
    return(lpc_ioapic_redir_tbl_trigger_extract(_regval));
}

static inline uint8_t lpc_ioapic_redirtbl_mask_rdf(__DN(t) *_dev, int _i) __attribute__ ((always_inline));
static inline uint8_t lpc_ioapic_redirtbl_mask_rdf(__DN(t) *_dev, int _i)
{
    lpc_ioapic_redir_tbl_t _regval = (lpc_ioapic_redir_tbl_t )(__DN(ioapic)::read64(_dev, 0x10 + (_i * (16 / 8))));
    return(lpc_ioapic_redir_tbl_mask_extract(_regval));
}

static inline uint8_t lpc_ioapic_redirtbl_edid_rdf(__DN(t) *_dev, int _i) __attribute__ ((always_inline));
static inline uint8_t lpc_ioapic_redirtbl_edid_rdf(__DN(t) *_dev, int _i)
{
    lpc_ioapic_redir_tbl_t _regval = (lpc_ioapic_redir_tbl_t )(__DN(ioapic)::read64(_dev, 0x10 + (_i * (16 / 8))));
    return(lpc_ioapic_redir_tbl_edid_extract(_regval));
}

static inline uint8_t lpc_ioapic_redirtbl_dest_rdf(__DN(t) *_dev, int _i) __attribute__ ((always_inline));
static inline uint8_t lpc_ioapic_redirtbl_dest_rdf(__DN(t) *_dev, int _i)
{
    lpc_ioapic_redir_tbl_t _regval = (lpc_ioapic_redir_tbl_t )(__DN(ioapic)::read64(_dev, 0x10 + (_i * (16 / 8))));
    return(lpc_ioapic_redir_tbl_dest_extract(_regval));
}

static inline void lpc_ioapic_redirtbl_vector_wrf(__DN(t) *_dev, int _i, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_ioapic_redirtbl_vector_wrf(__DN(t) *_dev, int _i, uint8_t _fieldval)
{
    lpc_ioapic_redir_tbl_t _regval = (lpc_ioapic_redir_tbl_t )(0xff & (((lpc_ioapic_redir_tbl_t )(_fieldval)) << 0));
    _regval = (_regval | (0xff00ffffffffaf00 & ((lpc_ioapic_redir_tbl_t )(__DN(ioapic)::read64(_dev, 0x10 + (_i * (16 / 8)))))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    __DN(ioapic)::write64(_dev, 0x10 + (_i * (16 / 8)), _regval);
    // No shadow register to write to
}

static inline void lpc_ioapic_redirtbl_mode_wrf(__DN(t) *_dev, int _i, lpc_ioapic_delivery_mode_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_ioapic_redirtbl_mode_wrf(__DN(t) *_dev, int _i, lpc_ioapic_delivery_mode_t _fieldval)
{
    lpc_ioapic_redir_tbl_t _regval = (lpc_ioapic_redir_tbl_t )(0x700 & (((lpc_ioapic_redir_tbl_t )(_fieldval)) << 8));
    _regval = (_regval | (0xff00ffffffffa8ff & ((lpc_ioapic_redir_tbl_t )(__DN(ioapic)::read64(_dev, 0x10 + (_i * (16 / 8)))))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    __DN(ioapic)::write64(_dev, 0x10 + (_i * (16 / 8)), _regval);
    // No shadow register to write to
}

static inline void lpc_ioapic_redirtbl_destmode_wrf(__DN(t) *_dev, int _i, lpc_ioapic_dest_mode_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_ioapic_redirtbl_destmode_wrf(__DN(t) *_dev, int _i, lpc_ioapic_dest_mode_t _fieldval)
{
    lpc_ioapic_redir_tbl_t _regval = (lpc_ioapic_redir_tbl_t )(0x800 & (((lpc_ioapic_redir_tbl_t )(_fieldval)) << 11));
    _regval = (_regval | (0xff00ffffffffa7ff & ((lpc_ioapic_redir_tbl_t )(__DN(ioapic)::read64(_dev, 0x10 + (_i * (16 / 8)))))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    __DN(ioapic)::write64(_dev, 0x10 + (_i * (16 / 8)), _regval);
    // No shadow register to write to
}

static inline void lpc_ioapic_redirtbl_polarity_wrf(__DN(t) *_dev, int _i, lpc_ioapic_polarity_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_ioapic_redirtbl_polarity_wrf(__DN(t) *_dev, int _i, lpc_ioapic_polarity_t _fieldval)
{
    lpc_ioapic_redir_tbl_t _regval = (lpc_ioapic_redir_tbl_t )(0x2000 & (((lpc_ioapic_redir_tbl_t )(_fieldval)) << 13));
    _regval = (_regval | (0xff00ffffffff8fff & ((lpc_ioapic_redir_tbl_t )(__DN(ioapic)::read64(_dev, 0x10 + (_i * (16 / 8)))))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    __DN(ioapic)::write64(_dev, 0x10 + (_i * (16 / 8)), _regval);
    // No shadow register to write to
}

static inline void lpc_ioapic_redirtbl_trigger_wrf(__DN(t) *_dev, int _i, lpc_ioapic_trigger_mode_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_ioapic_redirtbl_trigger_wrf(__DN(t) *_dev, int _i, lpc_ioapic_trigger_mode_t _fieldval)
{
    lpc_ioapic_redir_tbl_t _regval = (lpc_ioapic_redir_tbl_t )(0x8000 & (((lpc_ioapic_redir_tbl_t )(_fieldval)) << 15));
    _regval = (_regval | (0xff00ffffffff2fff & ((lpc_ioapic_redir_tbl_t )(__DN(ioapic)::read64(_dev, 0x10 + (_i * (16 / 8)))))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    __DN(ioapic)::write64(_dev, 0x10 + (_i * (16 / 8)), _regval);
    // No shadow register to write to
}

static inline void lpc_ioapic_redirtbl_mask_wrf(__DN(t) *_dev, int _i, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_ioapic_redirtbl_mask_wrf(__DN(t) *_dev, int _i, uint8_t _fieldval)
{
    lpc_ioapic_redir_tbl_t _regval = (lpc_ioapic_redir_tbl_t )(0x10000 & (((lpc_ioapic_redir_tbl_t )(_fieldval)) << 16));
    _regval = (_regval | (0xff00fffffffeafff & ((lpc_ioapic_redir_tbl_t )(__DN(ioapic)::read64(_dev, 0x10 + (_i * (16 / 8)))))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    __DN(ioapic)::write64(_dev, 0x10 + (_i * (16 / 8)), _regval);
    // No shadow register to write to
}

static inline void lpc_ioapic_redirtbl_dest_wrf(__DN(t) *_dev, int _i, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void lpc_ioapic_redirtbl_dest_wrf(__DN(t) *_dev, int _i, uint8_t _fieldval)
{
    lpc_ioapic_redir_tbl_t _regval = (lpc_ioapic_redir_tbl_t )(0xff00000000000000 & (((lpc_ioapic_redir_tbl_t )(_fieldval)) << 56));
    _regval = (_regval | (0xffffffffafff & ((lpc_ioapic_redir_tbl_t )(__DN(ioapic)::read64(_dev, 0x10 + (_i * (16 / 8)))))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    __DN(ioapic)::write64(_dev, 0x10 + (_i * (16 / 8)), _regval);
    // No shadow register to write to
}

static inline dout_t& operator<<(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, __DN(t) *_dev)
{
    _os << ("-------------------------\n");
    _os << ("Dump of device lpc_ioapic (LPC IHC I/O APIC function):\n");
    lpc_ioapic_ind_pr(_os, _dev);
    lpc_ioapic_wdw_pr(_os, _dev);
    lpc_ioapic_eoir_pr(_os, _dev);
    lpc_ioapic_id_pr(_os, _dev);
    lpc_ioapic_ver_pr(_os, _dev);
    lpc_ioapic_arb_pr(_os, _dev);
    lpc_ioapic_redirtbl_pr(_os, _dev);
    _os << ("End of dump of device lpc_ioapic\n");
    _os << ("-------------------------\n");
    return(_os);
}

#undef __DN
