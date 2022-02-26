#pragma once
/*
 * Device Definition: Local APIC
 * 
 * Automatically Generated from Spec.
 * Using a modified mackerel.
 * 
 * DO NOT EDIT!
 */
#include "util/debug.h"
#include "util/io.h"
#undef __DN
#define __DN(x) xapic ## _ ## x
/*
 * Constants defn: xapic.timer_mode (Timer mode)
 *  - no width specified
 */
HOH_STRONG_TYPEDEF( uint8_t , xapic_timer_mode_t);
#define xapic_one_shot ((xapic_timer_mode_t)0x0)
#define xapic_periodic ((xapic_timer_mode_t)0x1)

static inline const char* xapic_timer_mode_describe(xapic_timer_mode_t _e) __attribute__ ((always_inline));
static inline const char* xapic_timer_mode_describe(xapic_timer_mode_t _e)
{
    switch ((uint8_t )(_e)) {
    case (uint8_t )(0x0):
        return("one_shot: one_shot");
    case (uint8_t )(0x1):
        return("periodic: periodic");
    default:
        return(NULL);
    }
}

static inline dout_t& operator<<(dout_t& _os, xapic_timer_mode_t _e) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, xapic_timer_mode_t _e)
{
    const char* d = xapic_timer_mode_describe(_e);
    if (d) {
        return(_os << d);
    } else {
        return((((_os << ("Unknown constant:")) << ("xapic_timer_mode_t")) << ("value:")) << ((uint64_t )(_e)));
    }
}

/*
 * Constants defn: xapic.int_mask (Interrupt mask)
 *  - no width specified
 */
HOH_STRONG_TYPEDEF( uint8_t , xapic_int_mask_t);
#define xapic_not_masked ((xapic_int_mask_t)0x0)
#define xapic_masked ((xapic_int_mask_t)0x1)

static inline const char* xapic_int_mask_describe(xapic_int_mask_t _e) __attribute__ ((always_inline));
static inline const char* xapic_int_mask_describe(xapic_int_mask_t _e)
{
    switch ((uint8_t )(_e)) {
    case (uint8_t )(0x0):
        return("not_masked: Not masked");
    case (uint8_t )(0x1):
        return("masked: Masked");
    default:
        return(NULL);
    }
}

static inline dout_t& operator<<(dout_t& _os, xapic_int_mask_t _e) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, xapic_int_mask_t _e)
{
    const char* d = xapic_int_mask_describe(_e);
    if (d) {
        return(_os << d);
    } else {
        return((((_os << ("Unknown constant:")) << ("xapic_int_mask_t")) << ("value:")) << ((uint64_t )(_e)));
    }
}

/*
 * Constants defn: xapic.vdm (Vector delivery mode)
 *  - no width specified
 */
HOH_STRONG_TYPEDEF( uint8_t , xapic_vdm_t);
#define xapic_fixed ((xapic_vdm_t)0x0)
#define xapic_lowest ((xapic_vdm_t)0x1)
#define xapic_smi ((xapic_vdm_t)0x2)
#define xapic_nmi ((xapic_vdm_t)0x4)
#define xapic_init ((xapic_vdm_t)0x5)
#define xapic_startup ((xapic_vdm_t)0x6)
#define xapic_extint ((xapic_vdm_t)0x7)

static inline const char* xapic_vdm_describe(xapic_vdm_t _e) __attribute__ ((always_inline));
static inline const char* xapic_vdm_describe(xapic_vdm_t _e)
{
    switch ((uint8_t )(_e)) {
    case (uint8_t )(0x0):
        return("fixed: Fixed");
    case (uint8_t )(0x1):
        return("lowest: Lowest priority");
    case (uint8_t )(0x2):
        return("smi: SMI");
    case (uint8_t )(0x4):
        return("nmi: NMI");
    case (uint8_t )(0x5):
        return("init: INIT");
    case (uint8_t )(0x6):
        return("startup: Start Up");
    case (uint8_t )(0x7):
        return("extint: ExtINT");
    default:
        return(NULL);
    }
}

static inline dout_t& operator<<(dout_t& _os, xapic_vdm_t _e) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, xapic_vdm_t _e)
{
    const char* d = xapic_vdm_describe(_e);
    if (d) {
        return(_os << d);
    } else {
        return((((_os << ("Unknown constant:")) << ("xapic_vdm_t")) << ("value:")) << ((uint64_t )(_e)));
    }
}

/*
 * Constants defn: xapic.trigm (Trigger mode)
 *  - no width specified
 */
HOH_STRONG_TYPEDEF( uint8_t , xapic_trigm_t);
#define xapic_edge ((xapic_trigm_t)0x0)
#define xapic_level ((xapic_trigm_t)0x1)

static inline const char* xapic_trigm_describe(xapic_trigm_t _e) __attribute__ ((always_inline));
static inline const char* xapic_trigm_describe(xapic_trigm_t _e)
{
    switch ((uint8_t )(_e)) {
    case (uint8_t )(0x0):
        return("edge: Edge");
    case (uint8_t )(0x1):
        return("level: Level");
    default:
        return(NULL);
    }
}

static inline dout_t& operator<<(dout_t& _os, xapic_trigm_t _e) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, xapic_trigm_t _e)
{
    const char* d = xapic_trigm_describe(_e);
    if (d) {
        return(_os << d);
    } else {
        return((((_os << ("Unknown constant:")) << ("xapic_trigm_t")) << ("value:")) << ((uint64_t )(_e)));
    }
}

/*
 * Constants defn: xapic.divide (Timer Divide values)
 *  - no width specified
 */
HOH_STRONG_TYPEDEF( uint8_t , xapic_divide_t);
#define xapic_by1 ((xapic_divide_t)0xb)
#define xapic_by2 ((xapic_divide_t)0x0)
#define xapic_by4 ((xapic_divide_t)0x1)
#define xapic_by8 ((xapic_divide_t)0x2)
#define xapic_by16 ((xapic_divide_t)0x3)
#define xapic_by32 ((xapic_divide_t)0x8)
#define xapic_by64 ((xapic_divide_t)0x9)
#define xapic_by128 ((xapic_divide_t)0xa)

static inline const char* xapic_divide_describe(xapic_divide_t _e) __attribute__ ((always_inline));
static inline const char* xapic_divide_describe(xapic_divide_t _e)
{
    switch ((uint8_t )(_e)) {
    case (uint8_t )(0xb):
        return("by1: by1");
    case (uint8_t )(0x0):
        return("by2: by2");
    case (uint8_t )(0x1):
        return("by4: by4");
    case (uint8_t )(0x2):
        return("by8: by8");
    case (uint8_t )(0x3):
        return("by16: by16");
    case (uint8_t )(0x8):
        return("by32: by32");
    case (uint8_t )(0x9):
        return("by64: by64");
    case (uint8_t )(0xa):
        return("by128: by128");
    default:
        return(NULL);
    }
}

static inline dout_t& operator<<(dout_t& _os, xapic_divide_t _e) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, xapic_divide_t _e)
{
    const char* d = xapic_divide_describe(_e);
    if (d) {
        return(_os << d);
    } else {
        return((((_os << ("Unknown constant:")) << ("xapic_divide_t")) << ("value:")) << ((uint64_t )(_e)));
    }
}

/*
 * Constants defn: xapic.dst_shorthand (Destination shorthand)
 *  - no width specified
 */
HOH_STRONG_TYPEDEF( uint8_t , xapic_dst_shorthand_t);
#define xapic_none ((xapic_dst_shorthand_t)0x0)
#define xapic_self ((xapic_dst_shorthand_t)0x1)
#define xapic_all_inc ((xapic_dst_shorthand_t)0x2)
#define xapic_all_exc ((xapic_dst_shorthand_t)0x3)

static inline const char* xapic_dst_shorthand_describe(xapic_dst_shorthand_t _e) __attribute__ ((always_inline));
static inline const char* xapic_dst_shorthand_describe(xapic_dst_shorthand_t _e)
{
    switch ((uint8_t )(_e)) {
    case (uint8_t )(0x0):
        return("none: No shorthand");
    case (uint8_t )(0x1):
        return("self: Self");
    case (uint8_t )(0x2):
        return("all_inc: All including self");
    case (uint8_t )(0x3):
        return("all_exc: All excluding self");
    default:
        return(NULL);
    }
}

static inline dout_t& operator<<(dout_t& _os, xapic_dst_shorthand_t _e) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, xapic_dst_shorthand_t _e)
{
    const char* d = xapic_dst_shorthand_describe(_e);
    if (d) {
        return(_os << d);
    } else {
        return((((_os << ("Unknown constant:")) << ("xapic_dst_shorthand_t")) << ("value:")) << ((uint64_t )(_e)));
    }
}

/*
 * Constants defn: xapic.dst_mode (Destination mode)
 *  - no width specified
 */
HOH_STRONG_TYPEDEF( uint8_t , xapic_dst_mode_t);
#define xapic_dst_phys ((xapic_dst_mode_t)0x0)
#define xapic_dst_log ((xapic_dst_mode_t)0x1)

static inline const char* xapic_dst_mode_describe(xapic_dst_mode_t _e) __attribute__ ((always_inline));
static inline const char* xapic_dst_mode_describe(xapic_dst_mode_t _e)
{
    switch ((uint8_t )(_e)) {
    case (uint8_t )(0x0):
        return("dst_phys: Physical");
    case (uint8_t )(0x1):
        return("dst_log: Logical");
    default:
        return(NULL);
    }
}

static inline dout_t& operator<<(dout_t& _os, xapic_dst_mode_t _e) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, xapic_dst_mode_t _e)
{
    const char* d = xapic_dst_mode_describe(_e);
    if (d) {
        return(_os << d);
    } else {
        return((((_os << ("Unknown constant:")) << ("xapic_dst_mode_t")) << ("value:")) << ((uint64_t )(_e)));
    }
}

/*
 * Constants defn: xapic.int_level (Interrupt level)
 *  - no width specified
 */
HOH_STRONG_TYPEDEF( uint8_t , xapic_int_level_t);
#define xapic_lvl_clr ((xapic_int_level_t)0x0)
#define xapic_lvl_set ((xapic_int_level_t)0x1)

static inline const char* xapic_int_level_describe(xapic_int_level_t _e) __attribute__ ((always_inline));
static inline const char* xapic_int_level_describe(xapic_int_level_t _e)
{
    switch ((uint8_t )(_e)) {
    case (uint8_t )(0x0):
        return("lvl_clr: Clear");
    case (uint8_t )(0x1):
        return("lvl_set: Set");
    default:
        return(NULL);
    }
}

static inline dout_t& operator<<(dout_t& _os, xapic_int_level_t _e) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, xapic_int_level_t _e)
{
    const char* d = xapic_int_level_describe(_e);
    if (d) {
        return(_os << d);
    } else {
        return((((_os << ("Unknown constant:")) << ("xapic_int_level_t")) << ("value:")) << ((uint64_t )(_e)));
    }
}

/*
 * Constants defn: xapic.model_type (Destination model type)
 *  - no width specified
 */
HOH_STRONG_TYPEDEF( uint8_t , xapic_model_type_t);
#define xapic_flat ((xapic_model_type_t)0xf)
#define xapic_cluster ((xapic_model_type_t)0x0)

static inline const char* xapic_model_type_describe(xapic_model_type_t _e) __attribute__ ((always_inline));
static inline const char* xapic_model_type_describe(xapic_model_type_t _e)
{
    switch ((uint8_t )(_e)) {
    case (uint8_t )(0xf):
        return("flat: flat");
    case (uint8_t )(0x0):
        return("cluster: cluster");
    default:
        return(NULL);
    }
}

static inline dout_t& operator<<(dout_t& _os, xapic_model_type_t _e) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, xapic_model_type_t _e)
{
    const char* d = xapic_model_type_describe(_e);
    if (d) {
        return(_os << d);
    } else {
        return((((_os << ("Unknown constant:")) << ("xapic_model_type_t")) << ("value:")) << ((uint64_t )(_e)));
    }
}

/*
 * Register type: xapic_id_t
 * Description: Implicit type of Local APIC ID register
 * Fields:
 *   _anon0	(size 24, offset 0, init 0):	RSVD	_
 *   id	(size 8, offset 24, init 0):	RW	apic id
 */
HOH_STRONG_TYPEDEF( uint32_t , xapic_id_t);
#define xapic_id_default (xapic_id_t )(0x0)
static inline uint8_t xapic_id_id_extract(xapic_id_t _regval) __attribute__ ((always_inline));
static inline uint8_t xapic_id_id_extract(xapic_id_t _regval)
{
    return((uint8_t )((_regval & 0xff000000) >> 24));
}

static inline xapic_id_t xapic_id_id_insert(xapic_id_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xapic_id_t xapic_id_id_insert(xapic_id_t _regval, uint8_t _fieldval)
{
    return((xapic_id_t )((_regval & 0xffffff) | (0xff000000 & (((xapic_id_t )(_fieldval)) << 24))));
}

static inline dout_t& operator<<(dout_t& _os, xapic_id_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, xapic_id_t _regval)
{
    ((_os << (" id =\t")) << xapic_id_id_extract(_regval)) << ("\t(apic id)\n");
    return(_os);
}

/*
 * Register type: xapic_version_t
 * Description: Implicit type of Local APIC Version register
 * Fields:
 *   ver	(size 8, offset 0, init 0):	RO	version
 *   _anon8	(size 8, offset 8, init 0):	RSVD	_
 *   max_lvt	(size 8, offset 16, init 0):	RO	max LVT entry
 *   _anon24	(size 8, offset 24, init 0):	RSVD	_
 */
HOH_STRONG_TYPEDEF( uint32_t , xapic_version_t);
#define xapic_version_default (xapic_version_t )(0x0)
static inline uint8_t xapic_version_ver_extract(xapic_version_t _regval) __attribute__ ((always_inline));
static inline uint8_t xapic_version_ver_extract(xapic_version_t _regval)
{
    return((uint8_t )((_regval & 0xff) >> 0));
}

static inline xapic_version_t xapic_version_ver_insert(xapic_version_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xapic_version_t xapic_version_ver_insert(xapic_version_t _regval, uint8_t _fieldval)
{
    return((xapic_version_t )((_regval & 0xffffff00) | (0xff & (((xapic_version_t )(_fieldval)) << 0))));
}

static inline uint8_t xapic_version_max_lvt_extract(xapic_version_t _regval) __attribute__ ((always_inline));
static inline uint8_t xapic_version_max_lvt_extract(xapic_version_t _regval)
{
    return((uint8_t )((_regval & 0xff0000) >> 16));
}

static inline xapic_version_t xapic_version_max_lvt_insert(xapic_version_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xapic_version_t xapic_version_max_lvt_insert(xapic_version_t _regval, uint8_t _fieldval)
{
    return((xapic_version_t )((_regval & 0xff00ffff) | (0xff0000 & (((xapic_version_t )(_fieldval)) << 16))));
}

static inline dout_t& operator<<(dout_t& _os, xapic_version_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, xapic_version_t _regval)
{
    ((_os << (" ver =\t")) << xapic_version_ver_extract(_regval)) << ("\t(version)\n");
    ((_os << (" max_lvt =\t")) << xapic_version_max_lvt_extract(_regval)) << ("\t(max LVT entry)\n");
    return(_os);
}

/*
 * Register type: xapic_lvt_timer_t
 * Description: Implicit type of LVT Timer register
 * Fields:
 *   vector	(size 8, offset 0, init 0):	RW	Vector
 *   _anon8	(size 4, offset 8, init 0):	RSVD	_
 *   status	(size 1, offset 12, init 0):	RW	Delivery status
 *   _anon13	(size 3, offset 13, init 0):	RSVD	_
 *   mask	(size 1, offset 16, init 0):	RW	Masked
 *   mode	(size 1, offset 17, init 0):	RW	Mode
 *   _anon18	(size 14, offset 18, init 0):	RSVD	_
 */
HOH_STRONG_TYPEDEF( uint32_t , xapic_lvt_timer_t);
#define xapic_lvt_timer_default (xapic_lvt_timer_t )(0x0)
static inline uint8_t xapic_lvt_timer_vector_extract(xapic_lvt_timer_t _regval) __attribute__ ((always_inline));
static inline uint8_t xapic_lvt_timer_vector_extract(xapic_lvt_timer_t _regval)
{
    return((uint8_t )((_regval & 0xff) >> 0));
}

static inline xapic_lvt_timer_t xapic_lvt_timer_vector_insert(xapic_lvt_timer_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xapic_lvt_timer_t xapic_lvt_timer_vector_insert(xapic_lvt_timer_t _regval, uint8_t _fieldval)
{
    return((xapic_lvt_timer_t )((_regval & 0xffffff00) | (0xff & (((xapic_lvt_timer_t )(_fieldval)) << 0))));
}

static inline uint8_t xapic_lvt_timer_status_extract(xapic_lvt_timer_t _regval) __attribute__ ((always_inline));
static inline uint8_t xapic_lvt_timer_status_extract(xapic_lvt_timer_t _regval)
{
    return((uint8_t )((_regval & 0x1000) >> 12));
}

static inline xapic_lvt_timer_t xapic_lvt_timer_status_insert(xapic_lvt_timer_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xapic_lvt_timer_t xapic_lvt_timer_status_insert(xapic_lvt_timer_t _regval, uint8_t _fieldval)
{
    return((xapic_lvt_timer_t )((_regval & 0xffffefff) | (0x1000 & (((xapic_lvt_timer_t )(_fieldval)) << 12))));
}

static inline xapic_int_mask_t xapic_lvt_timer_mask_extract(xapic_lvt_timer_t _regval) __attribute__ ((always_inline));
static inline xapic_int_mask_t xapic_lvt_timer_mask_extract(xapic_lvt_timer_t _regval)
{
    return((xapic_int_mask_t )((_regval & 0x10000) >> 16));
}

static inline xapic_lvt_timer_t xapic_lvt_timer_mask_insert(xapic_lvt_timer_t _regval, xapic_int_mask_t _fieldval) __attribute__ ((always_inline));
static inline xapic_lvt_timer_t xapic_lvt_timer_mask_insert(xapic_lvt_timer_t _regval, xapic_int_mask_t _fieldval)
{
    return((xapic_lvt_timer_t )((_regval & 0xfffeffff) | (0x10000 & (((xapic_lvt_timer_t )(_fieldval)) << 16))));
}

static inline xapic_timer_mode_t xapic_lvt_timer_mode_extract(xapic_lvt_timer_t _regval) __attribute__ ((always_inline));
static inline xapic_timer_mode_t xapic_lvt_timer_mode_extract(xapic_lvt_timer_t _regval)
{
    return((xapic_timer_mode_t )((_regval & 0x20000) >> 17));
}

static inline xapic_lvt_timer_t xapic_lvt_timer_mode_insert(xapic_lvt_timer_t _regval, xapic_timer_mode_t _fieldval) __attribute__ ((always_inline));
static inline xapic_lvt_timer_t xapic_lvt_timer_mode_insert(xapic_lvt_timer_t _regval, xapic_timer_mode_t _fieldval)
{
    return((xapic_lvt_timer_t )((_regval & 0xfffdffff) | (0x20000 & (((xapic_lvt_timer_t )(_fieldval)) << 17))));
}

static inline dout_t& operator<<(dout_t& _os, xapic_lvt_timer_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, xapic_lvt_timer_t _regval)
{
    ((_os << (" vector =\t")) << xapic_lvt_timer_vector_extract(_regval)) << ("\t(Vector)\n");
    ((_os << (" status =\t")) << xapic_lvt_timer_status_extract(_regval)) << ("\t(Delivery status)\n");
    ((_os << (" mask =\t")) << xapic_lvt_timer_mask_extract(_regval)) << ("\t(Masked)\n");
    ((_os << (" mode =\t")) << xapic_lvt_timer_mode_extract(_regval)) << ("\t(Mode)\n");
    return(_os);
}

/*
 * Register type: xapic_lvt_lint_t
 * Description: LVT Int
 * Fields:
 *   vector	(size 8, offset 0, init 0):	NOATTR	Vector
 *   dlv_mode	(size 4, offset 8, init 0):	NOATTR	Delivery mode
 *   _anon12	(size 1, offset 12, init 0):	RSVD	_
 *   status	(size 1, offset 13, init 0):	NOATTR	Delivery status
 *   pinpol	(size 1, offset 14, init 0):	NOATTR	Pin polarity
 *   rirr	(size 1, offset 15, init 0):	NOATTR	Remote IRR
 *   trig_mode	(size 1, offset 16, init 0):	NOATTR	Trigger mode
 *   mask	(size 1, offset 17, init 0):	NOATTR	Mask
 *   _anon18	(size 14, offset 18, init 0):	RSVD	_
 */
HOH_STRONG_TYPEDEF( uint32_t , xapic_lvt_lint_t);
#define xapic_lvt_lint_default (xapic_lvt_lint_t )(0x0)
static inline uint8_t xapic_lvt_lint_vector_extract(xapic_lvt_lint_t _regval) __attribute__ ((always_inline));
static inline uint8_t xapic_lvt_lint_vector_extract(xapic_lvt_lint_t _regval)
{
    return((uint8_t )((_regval & 0xff) >> 0));
}

static inline xapic_lvt_lint_t xapic_lvt_lint_vector_insert(xapic_lvt_lint_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xapic_lvt_lint_t xapic_lvt_lint_vector_insert(xapic_lvt_lint_t _regval, uint8_t _fieldval)
{
    return((xapic_lvt_lint_t )((_regval & 0xffffff00) | (0xff & (((xapic_lvt_lint_t )(_fieldval)) << 0))));
}

static inline xapic_vdm_t xapic_lvt_lint_dlv_mode_extract(xapic_lvt_lint_t _regval) __attribute__ ((always_inline));
static inline xapic_vdm_t xapic_lvt_lint_dlv_mode_extract(xapic_lvt_lint_t _regval)
{
    return((xapic_vdm_t )((_regval & 0xf00) >> 8));
}

static inline xapic_lvt_lint_t xapic_lvt_lint_dlv_mode_insert(xapic_lvt_lint_t _regval, xapic_vdm_t _fieldval) __attribute__ ((always_inline));
static inline xapic_lvt_lint_t xapic_lvt_lint_dlv_mode_insert(xapic_lvt_lint_t _regval, xapic_vdm_t _fieldval)
{
    return((xapic_lvt_lint_t )((_regval & 0xfffff0ff) | (0xf00 & (((xapic_lvt_lint_t )(_fieldval)) << 8))));
}

static inline uint8_t xapic_lvt_lint_status_extract(xapic_lvt_lint_t _regval) __attribute__ ((always_inline));
static inline uint8_t xapic_lvt_lint_status_extract(xapic_lvt_lint_t _regval)
{
    return((uint8_t )((_regval & 0x2000) >> 13));
}

static inline xapic_lvt_lint_t xapic_lvt_lint_status_insert(xapic_lvt_lint_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xapic_lvt_lint_t xapic_lvt_lint_status_insert(xapic_lvt_lint_t _regval, uint8_t _fieldval)
{
    return((xapic_lvt_lint_t )((_regval & 0xffffdfff) | (0x2000 & (((xapic_lvt_lint_t )(_fieldval)) << 13))));
}

static inline uint8_t xapic_lvt_lint_pinpol_extract(xapic_lvt_lint_t _regval) __attribute__ ((always_inline));
static inline uint8_t xapic_lvt_lint_pinpol_extract(xapic_lvt_lint_t _regval)
{
    return((uint8_t )((_regval & 0x4000) >> 14));
}

static inline xapic_lvt_lint_t xapic_lvt_lint_pinpol_insert(xapic_lvt_lint_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xapic_lvt_lint_t xapic_lvt_lint_pinpol_insert(xapic_lvt_lint_t _regval, uint8_t _fieldval)
{
    return((xapic_lvt_lint_t )((_regval & 0xffffbfff) | (0x4000 & (((xapic_lvt_lint_t )(_fieldval)) << 14))));
}

static inline uint8_t xapic_lvt_lint_rirr_extract(xapic_lvt_lint_t _regval) __attribute__ ((always_inline));
static inline uint8_t xapic_lvt_lint_rirr_extract(xapic_lvt_lint_t _regval)
{
    return((uint8_t )((_regval & 0x8000) >> 15));
}

static inline xapic_lvt_lint_t xapic_lvt_lint_rirr_insert(xapic_lvt_lint_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xapic_lvt_lint_t xapic_lvt_lint_rirr_insert(xapic_lvt_lint_t _regval, uint8_t _fieldval)
{
    return((xapic_lvt_lint_t )((_regval & 0xffff7fff) | (0x8000 & (((xapic_lvt_lint_t )(_fieldval)) << 15))));
}

static inline xapic_trigm_t xapic_lvt_lint_trig_mode_extract(xapic_lvt_lint_t _regval) __attribute__ ((always_inline));
static inline xapic_trigm_t xapic_lvt_lint_trig_mode_extract(xapic_lvt_lint_t _regval)
{
    return((xapic_trigm_t )((_regval & 0x10000) >> 16));
}

static inline xapic_lvt_lint_t xapic_lvt_lint_trig_mode_insert(xapic_lvt_lint_t _regval, xapic_trigm_t _fieldval) __attribute__ ((always_inline));
static inline xapic_lvt_lint_t xapic_lvt_lint_trig_mode_insert(xapic_lvt_lint_t _regval, xapic_trigm_t _fieldval)
{
    return((xapic_lvt_lint_t )((_regval & 0xfffeffff) | (0x10000 & (((xapic_lvt_lint_t )(_fieldval)) << 16))));
}

static inline xapic_int_mask_t xapic_lvt_lint_mask_extract(xapic_lvt_lint_t _regval) __attribute__ ((always_inline));
static inline xapic_int_mask_t xapic_lvt_lint_mask_extract(xapic_lvt_lint_t _regval)
{
    return((xapic_int_mask_t )((_regval & 0x20000) >> 17));
}

static inline xapic_lvt_lint_t xapic_lvt_lint_mask_insert(xapic_lvt_lint_t _regval, xapic_int_mask_t _fieldval) __attribute__ ((always_inline));
static inline xapic_lvt_lint_t xapic_lvt_lint_mask_insert(xapic_lvt_lint_t _regval, xapic_int_mask_t _fieldval)
{
    return((xapic_lvt_lint_t )((_regval & 0xfffdffff) | (0x20000 & (((xapic_lvt_lint_t )(_fieldval)) << 17))));
}

static inline dout_t& operator<<(dout_t& _os, xapic_lvt_lint_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, xapic_lvt_lint_t _regval)
{
    ((_os << (" vector =\t")) << xapic_lvt_lint_vector_extract(_regval)) << ("\t(Vector)\n");
    ((_os << (" dlv_mode =\t")) << xapic_lvt_lint_dlv_mode_extract(_regval)) << ("\t(Delivery mode)\n");
    ((_os << (" status =\t")) << xapic_lvt_lint_status_extract(_regval)) << ("\t(Delivery status)\n");
    ((_os << (" pinpol =\t")) << xapic_lvt_lint_pinpol_extract(_regval)) << ("\t(Pin polarity)\n");
    ((_os << (" rirr =\t")) << xapic_lvt_lint_rirr_extract(_regval)) << ("\t(Remote IRR)\n");
    ((_os << (" trig_mode =\t")) << xapic_lvt_lint_trig_mode_extract(_regval)) << ("\t(Trigger mode)\n");
    ((_os << (" mask =\t")) << xapic_lvt_lint_mask_extract(_regval)) << ("\t(Mask)\n");
    return(_os);
}

/*
 * Register type: xapic_lvt_err_t
 * Description: Implicit type of lvt_err register
 * Fields:
 *   vector	(size 8, offset 0, init 0):	RW	Vector
 *   _anon8	(size 4, offset 8, init 0):	RSVD	_
 *   status	(size 1, offset 12, init 0):	RW	Delivery status
 *   _anon13	(size 3, offset 13, init 0):	RSVD	_
 *   mask	(size 1, offset 16, init 0):	RW	Mask
 *   _anon17	(size 15, offset 17, init 0):	RSVD	_
 */
HOH_STRONG_TYPEDEF( uint32_t , xapic_lvt_err_t);
#define xapic_lvt_err_default (xapic_lvt_err_t )(0x0)
static inline uint8_t xapic_lvt_err_vector_extract(xapic_lvt_err_t _regval) __attribute__ ((always_inline));
static inline uint8_t xapic_lvt_err_vector_extract(xapic_lvt_err_t _regval)
{
    return((uint8_t )((_regval & 0xff) >> 0));
}

static inline xapic_lvt_err_t xapic_lvt_err_vector_insert(xapic_lvt_err_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xapic_lvt_err_t xapic_lvt_err_vector_insert(xapic_lvt_err_t _regval, uint8_t _fieldval)
{
    return((xapic_lvt_err_t )((_regval & 0xffffff00) | (0xff & (((xapic_lvt_err_t )(_fieldval)) << 0))));
}

static inline uint8_t xapic_lvt_err_status_extract(xapic_lvt_err_t _regval) __attribute__ ((always_inline));
static inline uint8_t xapic_lvt_err_status_extract(xapic_lvt_err_t _regval)
{
    return((uint8_t )((_regval & 0x1000) >> 12));
}

static inline xapic_lvt_err_t xapic_lvt_err_status_insert(xapic_lvt_err_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xapic_lvt_err_t xapic_lvt_err_status_insert(xapic_lvt_err_t _regval, uint8_t _fieldval)
{
    return((xapic_lvt_err_t )((_regval & 0xffffefff) | (0x1000 & (((xapic_lvt_err_t )(_fieldval)) << 12))));
}

static inline xapic_int_mask_t xapic_lvt_err_mask_extract(xapic_lvt_err_t _regval) __attribute__ ((always_inline));
static inline xapic_int_mask_t xapic_lvt_err_mask_extract(xapic_lvt_err_t _regval)
{
    return((xapic_int_mask_t )((_regval & 0x10000) >> 16));
}

static inline xapic_lvt_err_t xapic_lvt_err_mask_insert(xapic_lvt_err_t _regval, xapic_int_mask_t _fieldval) __attribute__ ((always_inline));
static inline xapic_lvt_err_t xapic_lvt_err_mask_insert(xapic_lvt_err_t _regval, xapic_int_mask_t _fieldval)
{
    return((xapic_lvt_err_t )((_regval & 0xfffeffff) | (0x10000 & (((xapic_lvt_err_t )(_fieldval)) << 16))));
}

static inline dout_t& operator<<(dout_t& _os, xapic_lvt_err_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, xapic_lvt_err_t _regval)
{
    ((_os << (" vector =\t")) << xapic_lvt_err_vector_extract(_regval)) << ("\t(Vector)\n");
    ((_os << (" status =\t")) << xapic_lvt_err_status_extract(_regval)) << ("\t(Delivery status)\n");
    ((_os << (" mask =\t")) << xapic_lvt_err_mask_extract(_regval)) << ("\t(Mask)\n");
    return(_os);
}

/*
 * Register type: xapic_lvt_mon_t
 * Description: LVT monitor
 * Fields:
 *   vector	(size 8, offset 0, init 0):	NOATTR	Vector
 *   msgType	(size 3, offset 8, init 0):	NOATTR	msgType
 *   _anon11	(size 1, offset 11, init 0):	RSVD	_
 *   status	(size 1, offset 12, init 0):	NOATTR	Delivery status
 *   _anon13	(size 3, offset 13, init 0):	RSVD	_
 *   mask	(size 1, offset 16, init 0):	NOATTR	Masked
 *   _anon17	(size 15, offset 17, init 0):	RSVD	_
 */
HOH_STRONG_TYPEDEF( uint32_t , xapic_lvt_mon_t);
#define xapic_lvt_mon_default (xapic_lvt_mon_t )(0x0)
static inline uint8_t xapic_lvt_mon_vector_extract(xapic_lvt_mon_t _regval) __attribute__ ((always_inline));
static inline uint8_t xapic_lvt_mon_vector_extract(xapic_lvt_mon_t _regval)
{
    return((uint8_t )((_regval & 0xff) >> 0));
}

static inline xapic_lvt_mon_t xapic_lvt_mon_vector_insert(xapic_lvt_mon_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xapic_lvt_mon_t xapic_lvt_mon_vector_insert(xapic_lvt_mon_t _regval, uint8_t _fieldval)
{
    return((xapic_lvt_mon_t )((_regval & 0xffffff00) | (0xff & (((xapic_lvt_mon_t )(_fieldval)) << 0))));
}

static inline uint8_t xapic_lvt_mon_msgType_extract(xapic_lvt_mon_t _regval) __attribute__ ((always_inline));
static inline uint8_t xapic_lvt_mon_msgType_extract(xapic_lvt_mon_t _regval)
{
    return((uint8_t )((_regval & 0x700) >> 8));
}

static inline xapic_lvt_mon_t xapic_lvt_mon_msgType_insert(xapic_lvt_mon_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xapic_lvt_mon_t xapic_lvt_mon_msgType_insert(xapic_lvt_mon_t _regval, uint8_t _fieldval)
{
    return((xapic_lvt_mon_t )((_regval & 0xfffff8ff) | (0x700 & (((xapic_lvt_mon_t )(_fieldval)) << 8))));
}

static inline uint8_t xapic_lvt_mon_status_extract(xapic_lvt_mon_t _regval) __attribute__ ((always_inline));
static inline uint8_t xapic_lvt_mon_status_extract(xapic_lvt_mon_t _regval)
{
    return((uint8_t )((_regval & 0x1000) >> 12));
}

static inline xapic_lvt_mon_t xapic_lvt_mon_status_insert(xapic_lvt_mon_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xapic_lvt_mon_t xapic_lvt_mon_status_insert(xapic_lvt_mon_t _regval, uint8_t _fieldval)
{
    return((xapic_lvt_mon_t )((_regval & 0xffffefff) | (0x1000 & (((xapic_lvt_mon_t )(_fieldval)) << 12))));
}

static inline xapic_int_mask_t xapic_lvt_mon_mask_extract(xapic_lvt_mon_t _regval) __attribute__ ((always_inline));
static inline xapic_int_mask_t xapic_lvt_mon_mask_extract(xapic_lvt_mon_t _regval)
{
    return((xapic_int_mask_t )((_regval & 0x10000) >> 16));
}

static inline xapic_lvt_mon_t xapic_lvt_mon_mask_insert(xapic_lvt_mon_t _regval, xapic_int_mask_t _fieldval) __attribute__ ((always_inline));
static inline xapic_lvt_mon_t xapic_lvt_mon_mask_insert(xapic_lvt_mon_t _regval, xapic_int_mask_t _fieldval)
{
    return((xapic_lvt_mon_t )((_regval & 0xfffeffff) | (0x10000 & (((xapic_lvt_mon_t )(_fieldval)) << 16))));
}

static inline dout_t& operator<<(dout_t& _os, xapic_lvt_mon_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, xapic_lvt_mon_t _regval)
{
    ((_os << (" vector =\t")) << xapic_lvt_mon_vector_extract(_regval)) << ("\t(Vector)\n");
    ((_os << (" msgType =\t")) << xapic_lvt_mon_msgType_extract(_regval)) << ("\t(msgType)\n");
    ((_os << (" status =\t")) << xapic_lvt_mon_status_extract(_regval)) << ("\t(Delivery status)\n");
    ((_os << (" mask =\t")) << xapic_lvt_mon_mask_extract(_regval)) << ("\t(Masked)\n");
    return(_os);
}

/*
 * Register type: xapic_esr_t
 * Description: Implicit type of Error Status register
 * Fields:
 *   sce	(size 1, offset 0, init 0):	RW	Send checksum error
 *   rce	(size 1, offset 1, init 0):	RW	Receive checksum error
 *   sae	(size 1, offset 2, init 0):	RW	Send accept error
 *   rae	(size 1, offset 3, init 0):	RW	Receive accept error
 *   _anon4	(size 1, offset 4, init 0):	RSVD	_
 *   siv	(size 1, offset 5, init 0):	RW	Send illegal vector
 *   riv	(size 1, offset 6, init 0):	RW	Receive illegal vector
 *   ira	(size 1, offset 7, init 0):	RW	Illegal register address
 *   _anon8	(size 24, offset 8, init 0):	RSVD	_
 */
HOH_STRONG_TYPEDEF( uint32_t , xapic_esr_t);
#define xapic_esr_default (xapic_esr_t )(0x0)
static inline uint8_t xapic_esr_sce_extract(xapic_esr_t _regval) __attribute__ ((always_inline));
static inline uint8_t xapic_esr_sce_extract(xapic_esr_t _regval)
{
    return((uint8_t )((_regval & 0x1) >> 0));
}

static inline xapic_esr_t xapic_esr_sce_insert(xapic_esr_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xapic_esr_t xapic_esr_sce_insert(xapic_esr_t _regval, uint8_t _fieldval)
{
    return((xapic_esr_t )((_regval & 0xfffffffe) | (0x1 & (((xapic_esr_t )(_fieldval)) << 0))));
}

static inline uint8_t xapic_esr_rce_extract(xapic_esr_t _regval) __attribute__ ((always_inline));
static inline uint8_t xapic_esr_rce_extract(xapic_esr_t _regval)
{
    return((uint8_t )((_regval & 0x2) >> 1));
}

static inline xapic_esr_t xapic_esr_rce_insert(xapic_esr_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xapic_esr_t xapic_esr_rce_insert(xapic_esr_t _regval, uint8_t _fieldval)
{
    return((xapic_esr_t )((_regval & 0xfffffffd) | (0x2 & (((xapic_esr_t )(_fieldval)) << 1))));
}

static inline uint8_t xapic_esr_sae_extract(xapic_esr_t _regval) __attribute__ ((always_inline));
static inline uint8_t xapic_esr_sae_extract(xapic_esr_t _regval)
{
    return((uint8_t )((_regval & 0x4) >> 2));
}

static inline xapic_esr_t xapic_esr_sae_insert(xapic_esr_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xapic_esr_t xapic_esr_sae_insert(xapic_esr_t _regval, uint8_t _fieldval)
{
    return((xapic_esr_t )((_regval & 0xfffffffb) | (0x4 & (((xapic_esr_t )(_fieldval)) << 2))));
}

static inline uint8_t xapic_esr_rae_extract(xapic_esr_t _regval) __attribute__ ((always_inline));
static inline uint8_t xapic_esr_rae_extract(xapic_esr_t _regval)
{
    return((uint8_t )((_regval & 0x8) >> 3));
}

static inline xapic_esr_t xapic_esr_rae_insert(xapic_esr_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xapic_esr_t xapic_esr_rae_insert(xapic_esr_t _regval, uint8_t _fieldval)
{
    return((xapic_esr_t )((_regval & 0xfffffff7) | (0x8 & (((xapic_esr_t )(_fieldval)) << 3))));
}

static inline uint8_t xapic_esr_siv_extract(xapic_esr_t _regval) __attribute__ ((always_inline));
static inline uint8_t xapic_esr_siv_extract(xapic_esr_t _regval)
{
    return((uint8_t )((_regval & 0x20) >> 5));
}

static inline xapic_esr_t xapic_esr_siv_insert(xapic_esr_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xapic_esr_t xapic_esr_siv_insert(xapic_esr_t _regval, uint8_t _fieldval)
{
    return((xapic_esr_t )((_regval & 0xffffffdf) | (0x20 & (((xapic_esr_t )(_fieldval)) << 5))));
}

static inline uint8_t xapic_esr_riv_extract(xapic_esr_t _regval) __attribute__ ((always_inline));
static inline uint8_t xapic_esr_riv_extract(xapic_esr_t _regval)
{
    return((uint8_t )((_regval & 0x40) >> 6));
}

static inline xapic_esr_t xapic_esr_riv_insert(xapic_esr_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xapic_esr_t xapic_esr_riv_insert(xapic_esr_t _regval, uint8_t _fieldval)
{
    return((xapic_esr_t )((_regval & 0xffffffbf) | (0x40 & (((xapic_esr_t )(_fieldval)) << 6))));
}

static inline uint8_t xapic_esr_ira_extract(xapic_esr_t _regval) __attribute__ ((always_inline));
static inline uint8_t xapic_esr_ira_extract(xapic_esr_t _regval)
{
    return((uint8_t )((_regval & 0x80) >> 7));
}

static inline xapic_esr_t xapic_esr_ira_insert(xapic_esr_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xapic_esr_t xapic_esr_ira_insert(xapic_esr_t _regval, uint8_t _fieldval)
{
    return((xapic_esr_t )((_regval & 0xffffff7f) | (0x80 & (((xapic_esr_t )(_fieldval)) << 7))));
}

static inline dout_t& operator<<(dout_t& _os, xapic_esr_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, xapic_esr_t _regval)
{
    ((_os << (" sce =\t")) << xapic_esr_sce_extract(_regval)) << ("\t(Send checksum error)\n");
    ((_os << (" rce =\t")) << xapic_esr_rce_extract(_regval)) << ("\t(Receive checksum error)\n");
    ((_os << (" sae =\t")) << xapic_esr_sae_extract(_regval)) << ("\t(Send accept error)\n");
    ((_os << (" rae =\t")) << xapic_esr_rae_extract(_regval)) << ("\t(Receive accept error)\n");
    ((_os << (" siv =\t")) << xapic_esr_siv_extract(_regval)) << ("\t(Send illegal vector)\n");
    ((_os << (" riv =\t")) << xapic_esr_riv_extract(_regval)) << ("\t(Receive illegal vector)\n");
    ((_os << (" ira =\t")) << xapic_esr_ira_extract(_regval)) << ("\t(Illegal register address)\n");
    return(_os);
}

/*
 * Register type: xapic_dcr_t
 * Description: Implicit type of Divide Configuration register
 * Fields:
 *   div_val	(size 4, offset 0, init 0):	RW	Timer divide value
 *   _anon4	(size 28, offset 4, init 0):	RSVD	_
 */
HOH_STRONG_TYPEDEF( uint32_t , xapic_dcr_t);
#define xapic_dcr_default (xapic_dcr_t )(0x0)
static inline uint8_t xapic_dcr_div_val_extract(xapic_dcr_t _regval) __attribute__ ((always_inline));
static inline uint8_t xapic_dcr_div_val_extract(xapic_dcr_t _regval)
{
    return((uint8_t )((_regval & 0xf) >> 0));
}

static inline xapic_dcr_t xapic_dcr_div_val_insert(xapic_dcr_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xapic_dcr_t xapic_dcr_div_val_insert(xapic_dcr_t _regval, uint8_t _fieldval)
{
    return((xapic_dcr_t )((_regval & 0xfffffff0) | (0xf & (((xapic_dcr_t )(_fieldval)) << 0))));
}

static inline dout_t& operator<<(dout_t& _os, xapic_dcr_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, xapic_dcr_t _regval)
{
    ((_os << (" div_val =\t")) << xapic_dcr_div_val_extract(_regval)) << ("\t(Timer divide value)\n");
    return(_os);
}

/*
 * Register type: xapic_icr_lo_t
 * Description: Implicit type of Interrupt Command (lo) register
 * Fields:
 *   vector	(size 8, offset 0, init 0):	RW	Vector
 *   dlv_mode	(size 3, offset 8, init 0):	RW	Delivery mode
 *   dst_mode	(size 1, offset 11, init 0):	RW	Destination mode
 *   dlv_stat	(size 1, offset 12, init 0):	RO	Delivery status
 *   _anon13	(size 1, offset 13, init 0):	RSVD	_
 *   level	(size 1, offset 14, init 0):	RW	Level
 *   trig_mode	(size 1, offset 15, init 0):	RW	Trigger mode
 *   _anon16	(size 2, offset 16, init 0):	RSVD	_
 *   dst_short	(size 2, offset 18, init 0):	RW	Destination shorthand
 *   _anon20	(size 12, offset 20, init 0):	RSVD	_
 */
HOH_STRONG_TYPEDEF( uint32_t , xapic_icr_lo_t);
#define xapic_icr_lo_default (xapic_icr_lo_t )(0x0)
static inline uint8_t xapic_icr_lo_vector_extract(xapic_icr_lo_t _regval) __attribute__ ((always_inline));
static inline uint8_t xapic_icr_lo_vector_extract(xapic_icr_lo_t _regval)
{
    return((uint8_t )((_regval & 0xff) >> 0));
}

static inline xapic_icr_lo_t xapic_icr_lo_vector_insert(xapic_icr_lo_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xapic_icr_lo_t xapic_icr_lo_vector_insert(xapic_icr_lo_t _regval, uint8_t _fieldval)
{
    return((xapic_icr_lo_t )((_regval & 0xffffff00) | (0xff & (((xapic_icr_lo_t )(_fieldval)) << 0))));
}

static inline xapic_vdm_t xapic_icr_lo_dlv_mode_extract(xapic_icr_lo_t _regval) __attribute__ ((always_inline));
static inline xapic_vdm_t xapic_icr_lo_dlv_mode_extract(xapic_icr_lo_t _regval)
{
    return((xapic_vdm_t )((_regval & 0x700) >> 8));
}

static inline xapic_icr_lo_t xapic_icr_lo_dlv_mode_insert(xapic_icr_lo_t _regval, xapic_vdm_t _fieldval) __attribute__ ((always_inline));
static inline xapic_icr_lo_t xapic_icr_lo_dlv_mode_insert(xapic_icr_lo_t _regval, xapic_vdm_t _fieldval)
{
    return((xapic_icr_lo_t )((_regval & 0xfffff8ff) | (0x700 & (((xapic_icr_lo_t )(_fieldval)) << 8))));
}

static inline xapic_dst_mode_t xapic_icr_lo_dst_mode_extract(xapic_icr_lo_t _regval) __attribute__ ((always_inline));
static inline xapic_dst_mode_t xapic_icr_lo_dst_mode_extract(xapic_icr_lo_t _regval)
{
    return((xapic_dst_mode_t )((_regval & 0x800) >> 11));
}

static inline xapic_icr_lo_t xapic_icr_lo_dst_mode_insert(xapic_icr_lo_t _regval, xapic_dst_mode_t _fieldval) __attribute__ ((always_inline));
static inline xapic_icr_lo_t xapic_icr_lo_dst_mode_insert(xapic_icr_lo_t _regval, xapic_dst_mode_t _fieldval)
{
    return((xapic_icr_lo_t )((_regval & 0xfffff7ff) | (0x800 & (((xapic_icr_lo_t )(_fieldval)) << 11))));
}

static inline uint8_t xapic_icr_lo_dlv_stat_extract(xapic_icr_lo_t _regval) __attribute__ ((always_inline));
static inline uint8_t xapic_icr_lo_dlv_stat_extract(xapic_icr_lo_t _regval)
{
    return((uint8_t )((_regval & 0x1000) >> 12));
}

static inline xapic_icr_lo_t xapic_icr_lo_dlv_stat_insert(xapic_icr_lo_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xapic_icr_lo_t xapic_icr_lo_dlv_stat_insert(xapic_icr_lo_t _regval, uint8_t _fieldval)
{
    return((xapic_icr_lo_t )((_regval & 0xffffefff) | (0x1000 & (((xapic_icr_lo_t )(_fieldval)) << 12))));
}

static inline xapic_int_level_t xapic_icr_lo_level_extract(xapic_icr_lo_t _regval) __attribute__ ((always_inline));
static inline xapic_int_level_t xapic_icr_lo_level_extract(xapic_icr_lo_t _regval)
{
    return((xapic_int_level_t )((_regval & 0x4000) >> 14));
}

static inline xapic_icr_lo_t xapic_icr_lo_level_insert(xapic_icr_lo_t _regval, xapic_int_level_t _fieldval) __attribute__ ((always_inline));
static inline xapic_icr_lo_t xapic_icr_lo_level_insert(xapic_icr_lo_t _regval, xapic_int_level_t _fieldval)
{
    return((xapic_icr_lo_t )((_regval & 0xffffbfff) | (0x4000 & (((xapic_icr_lo_t )(_fieldval)) << 14))));
}

static inline xapic_trigm_t xapic_icr_lo_trig_mode_extract(xapic_icr_lo_t _regval) __attribute__ ((always_inline));
static inline xapic_trigm_t xapic_icr_lo_trig_mode_extract(xapic_icr_lo_t _regval)
{
    return((xapic_trigm_t )((_regval & 0x8000) >> 15));
}

static inline xapic_icr_lo_t xapic_icr_lo_trig_mode_insert(xapic_icr_lo_t _regval, xapic_trigm_t _fieldval) __attribute__ ((always_inline));
static inline xapic_icr_lo_t xapic_icr_lo_trig_mode_insert(xapic_icr_lo_t _regval, xapic_trigm_t _fieldval)
{
    return((xapic_icr_lo_t )((_regval & 0xffff7fff) | (0x8000 & (((xapic_icr_lo_t )(_fieldval)) << 15))));
}

static inline xapic_dst_shorthand_t xapic_icr_lo_dst_short_extract(xapic_icr_lo_t _regval) __attribute__ ((always_inline));
static inline xapic_dst_shorthand_t xapic_icr_lo_dst_short_extract(xapic_icr_lo_t _regval)
{
    return((xapic_dst_shorthand_t )((_regval & 0xc0000) >> 18));
}

static inline xapic_icr_lo_t xapic_icr_lo_dst_short_insert(xapic_icr_lo_t _regval, xapic_dst_shorthand_t _fieldval) __attribute__ ((always_inline));
static inline xapic_icr_lo_t xapic_icr_lo_dst_short_insert(xapic_icr_lo_t _regval, xapic_dst_shorthand_t _fieldval)
{
    return((xapic_icr_lo_t )((_regval & 0xfff3ffff) | (0xc0000 & (((xapic_icr_lo_t )(_fieldval)) << 18))));
}

static inline dout_t& operator<<(dout_t& _os, xapic_icr_lo_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, xapic_icr_lo_t _regval)
{
    ((_os << (" vector =\t")) << xapic_icr_lo_vector_extract(_regval)) << ("\t(Vector)\n");
    ((_os << (" dlv_mode =\t")) << xapic_icr_lo_dlv_mode_extract(_regval)) << ("\t(Delivery mode)\n");
    ((_os << (" dst_mode =\t")) << xapic_icr_lo_dst_mode_extract(_regval)) << ("\t(Destination mode)\n");
    ((_os << (" dlv_stat =\t")) << xapic_icr_lo_dlv_stat_extract(_regval)) << ("\t(Delivery status)\n");
    ((_os << (" level =\t")) << xapic_icr_lo_level_extract(_regval)) << ("\t(Level)\n");
    ((_os << (" trig_mode =\t")) << xapic_icr_lo_trig_mode_extract(_regval)) << ("\t(Trigger mode)\n");
    ((_os << (" dst_short =\t")) << xapic_icr_lo_dst_short_extract(_regval)) << ("\t(Destination shorthand)\n");
    return(_os);
}

/*
 * Register type: xapic_icr_hi_t
 * Description: Implicit type of Interrupt Commmand (hi) register
 * Fields:
 *   _anon0	(size 24, offset 0, init 0):	RSVD	_
 *   dest	(size 8, offset 24, init 0):	RW	Destination field
 */
HOH_STRONG_TYPEDEF( uint32_t , xapic_icr_hi_t);
#define xapic_icr_hi_default (xapic_icr_hi_t )(0x0)
static inline uint8_t xapic_icr_hi_dest_extract(xapic_icr_hi_t _regval) __attribute__ ((always_inline));
static inline uint8_t xapic_icr_hi_dest_extract(xapic_icr_hi_t _regval)
{
    return((uint8_t )((_regval & 0xff000000) >> 24));
}

static inline xapic_icr_hi_t xapic_icr_hi_dest_insert(xapic_icr_hi_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xapic_icr_hi_t xapic_icr_hi_dest_insert(xapic_icr_hi_t _regval, uint8_t _fieldval)
{
    return((xapic_icr_hi_t )((_regval & 0xffffff) | (0xff000000 & (((xapic_icr_hi_t )(_fieldval)) << 24))));
}

static inline dout_t& operator<<(dout_t& _os, xapic_icr_hi_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, xapic_icr_hi_t _regval)
{
    ((_os << (" dest =\t")) << xapic_icr_hi_dest_extract(_regval)) << ("\t(Destination field)\n");
    return(_os);
}

/*
 * Register type: xapic_ldr_t
 * Description: Implicit type of Logical Destination register
 * Fields:
 *   _anon0	(size 24, offset 0, init 0):	RSVD	_
 *   log_id	(size 8, offset 24, init 0):	RW	Logical APIC ID
 */
HOH_STRONG_TYPEDEF( uint32_t , xapic_ldr_t);
#define xapic_ldr_default (xapic_ldr_t )(0x0)
static inline uint8_t xapic_ldr_log_id_extract(xapic_ldr_t _regval) __attribute__ ((always_inline));
static inline uint8_t xapic_ldr_log_id_extract(xapic_ldr_t _regval)
{
    return((uint8_t )((_regval & 0xff000000) >> 24));
}

static inline xapic_ldr_t xapic_ldr_log_id_insert(xapic_ldr_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xapic_ldr_t xapic_ldr_log_id_insert(xapic_ldr_t _regval, uint8_t _fieldval)
{
    return((xapic_ldr_t )((_regval & 0xffffff) | (0xff000000 & (((xapic_ldr_t )(_fieldval)) << 24))));
}

static inline dout_t& operator<<(dout_t& _os, xapic_ldr_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, xapic_ldr_t _regval)
{
    ((_os << (" log_id =\t")) << xapic_ldr_log_id_extract(_regval)) << ("\t(Logical APIC ID)\n");
    return(_os);
}

/*
 * Register type: xapic_dfr_t
 * Description: Implicit type of Destination Format register
 * Fields:
 *   _anon0	(size 28, offset 0, init fffffff):	MB1	_
 *   model	(size 4, offset 28, init 0):	RW	Model
 */
HOH_STRONG_TYPEDEF( uint32_t , xapic_dfr_t);
#define xapic_dfr_default (xapic_dfr_t )(0xfffffff)
static inline xapic_model_type_t xapic_dfr_model_extract(xapic_dfr_t _regval) __attribute__ ((always_inline));
static inline xapic_model_type_t xapic_dfr_model_extract(xapic_dfr_t _regval)
{
    return((xapic_model_type_t )((_regval & 0xf0000000) >> 28));
}

static inline xapic_dfr_t xapic_dfr_model_insert(xapic_dfr_t _regval, xapic_model_type_t _fieldval) __attribute__ ((always_inline));
static inline xapic_dfr_t xapic_dfr_model_insert(xapic_dfr_t _regval, xapic_model_type_t _fieldval)
{
    return((xapic_dfr_t )((_regval & 0xfffffff) | (0xf0000000 & (((xapic_dfr_t )(_fieldval)) << 28))));
}

static inline dout_t& operator<<(dout_t& _os, xapic_dfr_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, xapic_dfr_t _regval)
{
    ((_os << (" model =\t")) << xapic_dfr_model_extract(_regval)) << ("\t(Model)\n");
    return(_os);
}

/*
 * Register type: xapic_priority_t
 * Description: Various priorities
 * Fields:
 *   sub_class	(size 4, offset 0, init 0):	NOATTR	Priority subclass
 *   priority	(size 4, offset 4, init 0):	NOATTR	Priority
 *   _anon8	(size 24, offset 8, init 0):	RSVD	_
 */
HOH_STRONG_TYPEDEF( uint32_t , xapic_priority_t);
#define xapic_priority_default (xapic_priority_t )(0x0)
static inline uint8_t xapic_priority_sub_class_extract(xapic_priority_t _regval) __attribute__ ((always_inline));
static inline uint8_t xapic_priority_sub_class_extract(xapic_priority_t _regval)
{
    return((uint8_t )((_regval & 0xf) >> 0));
}

static inline xapic_priority_t xapic_priority_sub_class_insert(xapic_priority_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xapic_priority_t xapic_priority_sub_class_insert(xapic_priority_t _regval, uint8_t _fieldval)
{
    return((xapic_priority_t )((_regval & 0xfffffff0) | (0xf & (((xapic_priority_t )(_fieldval)) << 0))));
}

static inline uint8_t xapic_priority_priority_extract(xapic_priority_t _regval) __attribute__ ((always_inline));
static inline uint8_t xapic_priority_priority_extract(xapic_priority_t _regval)
{
    return((uint8_t )((_regval & 0xf0) >> 4));
}

static inline xapic_priority_t xapic_priority_priority_insert(xapic_priority_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xapic_priority_t xapic_priority_priority_insert(xapic_priority_t _regval, uint8_t _fieldval)
{
    return((xapic_priority_t )((_regval & 0xffffff0f) | (0xf0 & (((xapic_priority_t )(_fieldval)) << 4))));
}

static inline dout_t& operator<<(dout_t& _os, xapic_priority_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, xapic_priority_t _regval)
{
    ((_os << (" sub_class =\t")) << xapic_priority_sub_class_extract(_regval)) << ("\t(Priority subclass)\n");
    ((_os << (" priority =\t")) << xapic_priority_priority_extract(_regval)) << ("\t(Priority)\n");
    return(_os);
}

/*
 * Register type: xapic_svr_t
 * Description: Implicit type of Spurious Interrupt Vector Register register
 * Fields:
 *   vector	(size 8, offset 0, init 0):	RW	Vector
 *   enable	(size 1, offset 8, init 0):	RW	APIC Software Enable/Disable
 *   focus	(size 1, offset 9, init 0):	RW	Focus Processor Checking
 *   _anon10	(size 22, offset 10, init 0):	RSVD	_
 */
HOH_STRONG_TYPEDEF( uint32_t , xapic_svr_t);
#define xapic_svr_default (xapic_svr_t )(0x0)
static inline uint8_t xapic_svr_vector_extract(xapic_svr_t _regval) __attribute__ ((always_inline));
static inline uint8_t xapic_svr_vector_extract(xapic_svr_t _regval)
{
    return((uint8_t )((_regval & 0xff) >> 0));
}

static inline xapic_svr_t xapic_svr_vector_insert(xapic_svr_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xapic_svr_t xapic_svr_vector_insert(xapic_svr_t _regval, uint8_t _fieldval)
{
    return((xapic_svr_t )((_regval & 0xffffff00) | (0xff & (((xapic_svr_t )(_fieldval)) << 0))));
}

static inline uint8_t xapic_svr_enable_extract(xapic_svr_t _regval) __attribute__ ((always_inline));
static inline uint8_t xapic_svr_enable_extract(xapic_svr_t _regval)
{
    return((uint8_t )((_regval & 0x100) >> 8));
}

static inline xapic_svr_t xapic_svr_enable_insert(xapic_svr_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xapic_svr_t xapic_svr_enable_insert(xapic_svr_t _regval, uint8_t _fieldval)
{
    return((xapic_svr_t )((_regval & 0xfffffeff) | (0x100 & (((xapic_svr_t )(_fieldval)) << 8))));
}

static inline uint8_t xapic_svr_focus_extract(xapic_svr_t _regval) __attribute__ ((always_inline));
static inline uint8_t xapic_svr_focus_extract(xapic_svr_t _regval)
{
    return((uint8_t )((_regval & 0x200) >> 9));
}

static inline xapic_svr_t xapic_svr_focus_insert(xapic_svr_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xapic_svr_t xapic_svr_focus_insert(xapic_svr_t _regval, uint8_t _fieldval)
{
    return((xapic_svr_t )((_regval & 0xfffffdff) | (0x200 & (((xapic_svr_t )(_fieldval)) << 9))));
}

static inline dout_t& operator<<(dout_t& _os, xapic_svr_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, xapic_svr_t _regval)
{
    ((_os << (" vector =\t")) << xapic_svr_vector_extract(_regval)) << ("\t(Vector)\n");
    ((_os << (" enable =\t")) << xapic_svr_enable_extract(_regval)) << ("\t(APIC Software Enable/Disable)\n");
    ((_os << (" focus =\t")) << xapic_svr_focus_extract(_regval)) << ("\t(Focus Processor Checking)\n");
    return(_os);
}

/*
 * Register type: xapic_eafr_t
 * Description: Implicit type of Extended APIC feature register
 * Fields:
 *   inc	(size 1, offset 0, init 0):	RO	Interrupt enable register capable
 *   snic	(size 1, offset 1, init 0):	RO	Specific EOI capable
 *   xaidc	(size 1, offset 2, init 0):	RO	Extended APIC ID capability
 *   _anon3	(size 13, offset 3, init 0):	MBZ	_
 *   xlc	(size 8, offset 16, init 0):	RO	Extended LVT count
 *   _anon24	(size 8, offset 24, init 0):	MBZ	_
 */
HOH_STRONG_TYPEDEF( uint32_t , xapic_eafr_t);
#define xapic_eafr_default (xapic_eafr_t )(0x0)
static inline uint8_t xapic_eafr_inc_extract(xapic_eafr_t _regval) __attribute__ ((always_inline));
static inline uint8_t xapic_eafr_inc_extract(xapic_eafr_t _regval)
{
    return((uint8_t )((_regval & 0x1) >> 0));
}

static inline xapic_eafr_t xapic_eafr_inc_insert(xapic_eafr_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xapic_eafr_t xapic_eafr_inc_insert(xapic_eafr_t _regval, uint8_t _fieldval)
{
    return((xapic_eafr_t )((_regval & 0xfffffffe) | (0x1 & (((xapic_eafr_t )(_fieldval)) << 0))));
}

static inline uint8_t xapic_eafr_snic_extract(xapic_eafr_t _regval) __attribute__ ((always_inline));
static inline uint8_t xapic_eafr_snic_extract(xapic_eafr_t _regval)
{
    return((uint8_t )((_regval & 0x2) >> 1));
}

static inline xapic_eafr_t xapic_eafr_snic_insert(xapic_eafr_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xapic_eafr_t xapic_eafr_snic_insert(xapic_eafr_t _regval, uint8_t _fieldval)
{
    return((xapic_eafr_t )((_regval & 0xfffffffd) | (0x2 & (((xapic_eafr_t )(_fieldval)) << 1))));
}

static inline uint8_t xapic_eafr_xaidc_extract(xapic_eafr_t _regval) __attribute__ ((always_inline));
static inline uint8_t xapic_eafr_xaidc_extract(xapic_eafr_t _regval)
{
    return((uint8_t )((_regval & 0x4) >> 2));
}

static inline xapic_eafr_t xapic_eafr_xaidc_insert(xapic_eafr_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xapic_eafr_t xapic_eafr_xaidc_insert(xapic_eafr_t _regval, uint8_t _fieldval)
{
    return((xapic_eafr_t )((_regval & 0xfffffffb) | (0x4 & (((xapic_eafr_t )(_fieldval)) << 2))));
}

static inline uint8_t xapic_eafr_xlc_extract(xapic_eafr_t _regval) __attribute__ ((always_inline));
static inline uint8_t xapic_eafr_xlc_extract(xapic_eafr_t _regval)
{
    return((uint8_t )((_regval & 0xff0000) >> 16));
}

static inline xapic_eafr_t xapic_eafr_xlc_insert(xapic_eafr_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xapic_eafr_t xapic_eafr_xlc_insert(xapic_eafr_t _regval, uint8_t _fieldval)
{
    return((xapic_eafr_t )((_regval & 0xff00ffff) | (0xff0000 & (((xapic_eafr_t )(_fieldval)) << 16))));
}

static inline dout_t& operator<<(dout_t& _os, xapic_eafr_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, xapic_eafr_t _regval)
{
    ((_os << (" inc =\t")) << xapic_eafr_inc_extract(_regval)) << ("\t(Interrupt enable register capable)\n");
    ((_os << (" snic =\t")) << xapic_eafr_snic_extract(_regval)) << ("\t(Specific EOI capable)\n");
    ((_os << (" xaidc =\t")) << xapic_eafr_xaidc_extract(_regval)) << ("\t(Extended APIC ID capability)\n");
    ((_os << (" xlc =\t")) << xapic_eafr_xlc_extract(_regval)) << ("\t(Extended LVT count)\n");
    return(_os);
}

/*
 * Register type: xapic_eacr_t
 * Description: Implicit type of Extended APIC control register
 * Fields:
 *   iern	(size 1, offset 0, init 0):	RW	Enable interrupt enable registers
 *   sn	(size 1, offset 1, init 0):	RW	Enable SEOI generation
 *   xaidn	(size 1, offset 2, init 0):	RW	Extended APIC ID enable
 *   _anon3	(size 29, offset 3, init 0):	RSVD	_
 */
HOH_STRONG_TYPEDEF( uint32_t , xapic_eacr_t);
#define xapic_eacr_default (xapic_eacr_t )(0x0)
static inline uint8_t xapic_eacr_iern_extract(xapic_eacr_t _regval) __attribute__ ((always_inline));
static inline uint8_t xapic_eacr_iern_extract(xapic_eacr_t _regval)
{
    return((uint8_t )((_regval & 0x1) >> 0));
}

static inline xapic_eacr_t xapic_eacr_iern_insert(xapic_eacr_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xapic_eacr_t xapic_eacr_iern_insert(xapic_eacr_t _regval, uint8_t _fieldval)
{
    return((xapic_eacr_t )((_regval & 0xfffffffe) | (0x1 & (((xapic_eacr_t )(_fieldval)) << 0))));
}

static inline uint8_t xapic_eacr_sn_extract(xapic_eacr_t _regval) __attribute__ ((always_inline));
static inline uint8_t xapic_eacr_sn_extract(xapic_eacr_t _regval)
{
    return((uint8_t )((_regval & 0x2) >> 1));
}

static inline xapic_eacr_t xapic_eacr_sn_insert(xapic_eacr_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xapic_eacr_t xapic_eacr_sn_insert(xapic_eacr_t _regval, uint8_t _fieldval)
{
    return((xapic_eacr_t )((_regval & 0xfffffffd) | (0x2 & (((xapic_eacr_t )(_fieldval)) << 1))));
}

static inline uint8_t xapic_eacr_xaidn_extract(xapic_eacr_t _regval) __attribute__ ((always_inline));
static inline uint8_t xapic_eacr_xaidn_extract(xapic_eacr_t _regval)
{
    return((uint8_t )((_regval & 0x4) >> 2));
}

static inline xapic_eacr_t xapic_eacr_xaidn_insert(xapic_eacr_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xapic_eacr_t xapic_eacr_xaidn_insert(xapic_eacr_t _regval, uint8_t _fieldval)
{
    return((xapic_eacr_t )((_regval & 0xfffffffb) | (0x4 & (((xapic_eacr_t )(_fieldval)) << 2))));
}

static inline dout_t& operator<<(dout_t& _os, xapic_eacr_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, xapic_eacr_t _regval)
{
    ((_os << (" iern =\t")) << xapic_eacr_iern_extract(_regval)) << ("\t(Enable interrupt enable registers)\n");
    ((_os << (" sn =\t")) << xapic_eacr_sn_extract(_regval)) << ("\t(Enable SEOI generation)\n");
    ((_os << (" xaidn =\t")) << xapic_eacr_xaidn_extract(_regval)) << ("\t(Extended APIC ID enable)\n");
    return(_os);
}

/*
 * Register type: xapic_seoi_t
 * Description: Implicit type of Specific end-of-interrupt register
 * Fields:
 *   vector	(size 8, offset 0, init 0):	WO	Vector
 *   _anon8	(size 24, offset 8, init 0):	MBZ	_
 */
HOH_STRONG_TYPEDEF( uint32_t , xapic_seoi_t);
#define xapic_seoi_default (xapic_seoi_t )(0x0)
static inline uint8_t xapic_seoi_vector_extract(xapic_seoi_t _regval) __attribute__ ((always_inline));
static inline uint8_t xapic_seoi_vector_extract(xapic_seoi_t _regval)
{
    return((uint8_t )((_regval & 0xff) >> 0));
}

static inline xapic_seoi_t xapic_seoi_vector_insert(xapic_seoi_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xapic_seoi_t xapic_seoi_vector_insert(xapic_seoi_t _regval, uint8_t _fieldval)
{
    return((xapic_seoi_t )((_regval & 0xffffff00) | (0xff & (((xapic_seoi_t )(_fieldval)) << 0))));
}

static inline dout_t& operator<<(dout_t& _os, xapic_seoi_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, xapic_seoi_t _regval)
{
    ((_os << (" vector =\t")) << xapic_seoi_vector_extract(_regval)) << ("\t(Vector)\n");
    return(_os);
}

/*
 * Device representation structure
 */
struct __DN(t) {
    addr_t base;
    uint32_t eoi_shadow;
    xapic_seoi_t seoi_shadow;
};

/*
 * Initial register values (currently 0)
 */
enum xapic_initials {
    xapic_id_initial = 0x0,
    xapic_version_initial = 0x0,
    xapic_lvt_timer_initial = 0x0,
    xapic_lvt_lint0_initial = 0x0,
    xapic_lvt_lint1_initial = 0x0,
    xapic_lvt_err_initial = 0x0,
    xapic_lvt_perf_cnt_initial = 0x0,
    xapic_lvt_thermal_initial = 0x0,
    xapic_esr_initial = 0x0,
    xapic_dcr_initial = 0x0,
    xapic_init_count_initial = 0x0,
    xapic_cur_count_initial = 0x0,
    xapic_icr_lo_initial = 0x0,
    xapic_icr_hi_initial = 0x0,
    xapic_ldr_initial = 0x0,
    xapic_dfr_initial = 0x0,
    xapic_apr_initial = 0x0,
    xapic_tpr_initial = 0x0,
    xapic_ppr_initial = 0x0,
    xapic_isr_initial = 0x0,
    xapic_tmr_initial = 0x0,
    xapic_irr_initial = 0x0,
    xapic_eoi_initial = 0x0,
    xapic_svr_initial = 0x0,
    xapic_eafr_initial = 0x0,
    xapic_eacr_initial = 0x0,
    xapic_seoi_initial = 0x0,
    xapic_ier_initial = 0x0
};

/*
 * Device Initialization function
 */
static inline void xapic_initialize(__DN(t) *_dev, addr_t base) __attribute__ ((always_inline));
static inline void xapic_initialize(__DN(t) *_dev, addr_t base)
{
    _dev->base = base;
}

/*
 * No user-defined spaces
 */
/*
 * Register id: Local APIC ID
 * Type: xapic.id (Implicit type of Local APIC ID register)
 *   _anon0	(size 24, offset 0, init 0):	RSVD	_
 *   id	(size 8, offset 24, init 0):	RW	apic id
 */
static inline xapic_id_t xapic_id_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_id_t xapic_id_rawrd(__DN(t) *_dev)
{
    return((xapic_id_t )(mmio::read32(_dev->base, 0x20)));
}

static inline xapic_id_t xapic_id_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_id_t xapic_id_rd(__DN(t) *_dev)
{
    return((xapic_id_t )(mmio::read32(_dev->base, 0x20)));
}

static inline void xapic_id_rawwr(__DN(t) *_dev, xapic_id_t _regval) __attribute__ ((always_inline));
static inline void xapic_id_rawwr(__DN(t) *_dev, xapic_id_t _regval)
{
    mmio::write32(_dev->base, 0x20, _regval);
}

static inline void xapic_id_wr(__DN(t) *_dev, xapic_id_t _regval) __attribute__ ((always_inline));
static inline void xapic_id_wr(__DN(t) *_dev, xapic_id_t _regval)
{
    _regval = (_regval & 0xff000000);
    // No MB1 fields present
    _regval = (_regval | (0xffffff & ((xapic_id_t )(mmio::read32(_dev->base, 0x20)))));
    mmio::write32(_dev->base, 0x20, _regval);
}

static inline dout_t& xapic_id_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& xapic_id_pr(dout_t& _os, __DN(t) *_dev)
{
    xapic_id_t _regval = (xapic_id_t )(mmio::read32(_dev->base, 0x20));
    _os << ("Register id (Local APIC ID): ");
    _os << ("\n");
    // _anon0 is anonymous
    ((_os << (" id =\t")) << xapic_id_id_extract(_regval)) << ("\t(apic id)\n");
    return(_os);
}

static inline uint8_t xapic_id_id_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_id_id_rdf(__DN(t) *_dev)
{
    xapic_id_t _regval = (xapic_id_t )(mmio::read32(_dev->base, 0x20));
    return(xapic_id_id_extract(_regval));
}

static inline void xapic_id_id_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_id_id_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xapic_id_t _regval = (xapic_id_t )(0xff000000 & (((xapic_id_t )(_fieldval)) << 24));
    _regval = (_regval | (0xffffff & ((xapic_id_t )(mmio::read32(_dev->base, 0x20)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x20, _regval);
    // No shadow register to write to
}

/*
 * Register version: Local APIC Version
 * Type: xapic.version (Implicit type of Local APIC Version register)
 *   ver	(size 8, offset 0, init 0):	RO	version
 *   _anon8	(size 8, offset 8, init 0):	RSVD	_
 *   max_lvt	(size 8, offset 16, init 0):	RO	max LVT entry
 *   _anon24	(size 8, offset 24, init 0):	RSVD	_
 */
static inline xapic_version_t xapic_version_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_version_t xapic_version_rawrd(__DN(t) *_dev)
{
    return((xapic_version_t )(mmio::read32(_dev->base, 0x30)));
}

static inline xapic_version_t xapic_version_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_version_t xapic_version_rd(__DN(t) *_dev)
{
    return((xapic_version_t )(mmio::read32(_dev->base, 0x30)));
}

static inline void xapic_version_rawwr(__DN(t) *_dev, xapic_version_t _regval) __attribute__ ((always_inline));
static inline void xapic_version_rawwr(__DN(t) *_dev, xapic_version_t _regval)
{
    mmio::write32(_dev->base, 0x30, _regval);
}

// Register version is not writeable
static inline dout_t& xapic_version_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& xapic_version_pr(dout_t& _os, __DN(t) *_dev)
{
    xapic_version_t _regval = (xapic_version_t )(mmio::read32(_dev->base, 0x30));
    _os << ("Register version (Local APIC Version): ");
    _os << ("\n");
    ((_os << (" ver =\t")) << xapic_version_ver_extract(_regval)) << ("\t(version)\n");
    // _anon8 is anonymous
    ((_os << (" max_lvt =\t")) << xapic_version_max_lvt_extract(_regval)) << ("\t(max LVT entry)\n");
    // _anon24 is anonymous
    return(_os);
}

static inline uint8_t xapic_version_ver_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_version_ver_rdf(__DN(t) *_dev)
{
    xapic_version_t _regval = (xapic_version_t )(mmio::read32(_dev->base, 0x30));
    return(xapic_version_ver_extract(_regval));
}

static inline uint8_t xapic_version_max_lvt_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_version_max_lvt_rdf(__DN(t) *_dev)
{
    xapic_version_t _regval = (xapic_version_t )(mmio::read32(_dev->base, 0x30));
    return(xapic_version_max_lvt_extract(_regval));
}

/*
 * Register lvt_timer: LVT Timer
 * Type: xapic.lvt_timer (Implicit type of LVT Timer register)
 *   vector	(size 8, offset 0, init 0):	RW	Vector
 *   _anon8	(size 4, offset 8, init 0):	RSVD	_
 *   status	(size 1, offset 12, init 0):	RW	Delivery status
 *   _anon13	(size 3, offset 13, init 0):	RSVD	_
 *   mask	(size 1, offset 16, init 0):	RW	Masked
 *   mode	(size 1, offset 17, init 0):	RW	Mode
 *   _anon18	(size 14, offset 18, init 0):	RSVD	_
 */
static inline xapic_lvt_timer_t xapic_lvt_timer_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_lvt_timer_t xapic_lvt_timer_rawrd(__DN(t) *_dev)
{
    return((xapic_lvt_timer_t )(mmio::read32(_dev->base, 0x320)));
}

static inline xapic_lvt_timer_t xapic_lvt_timer_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_lvt_timer_t xapic_lvt_timer_rd(__DN(t) *_dev)
{
    return((xapic_lvt_timer_t )(mmio::read32(_dev->base, 0x320)));
}

static inline void xapic_lvt_timer_rawwr(__DN(t) *_dev, xapic_lvt_timer_t _regval) __attribute__ ((always_inline));
static inline void xapic_lvt_timer_rawwr(__DN(t) *_dev, xapic_lvt_timer_t _regval)
{
    mmio::write32(_dev->base, 0x320, _regval);
}

static inline void xapic_lvt_timer_wr(__DN(t) *_dev, xapic_lvt_timer_t _regval) __attribute__ ((always_inline));
static inline void xapic_lvt_timer_wr(__DN(t) *_dev, xapic_lvt_timer_t _regval)
{
    _regval = (_regval & 0x310ff);
    // No MB1 fields present
    _regval = (_regval | (0xfffcef00 & ((xapic_lvt_timer_t )(mmio::read32(_dev->base, 0x320)))));
    mmio::write32(_dev->base, 0x320, _regval);
}

static inline dout_t& xapic_lvt_timer_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& xapic_lvt_timer_pr(dout_t& _os, __DN(t) *_dev)
{
    xapic_lvt_timer_t _regval = (xapic_lvt_timer_t )(mmio::read32(_dev->base, 0x320));
    _os << ("Register lvt_timer (LVT Timer): ");
    _os << ("\n");
    ((_os << (" vector =\t")) << xapic_lvt_timer_vector_extract(_regval)) << ("\t(Vector)\n");
    // _anon8 is anonymous
    ((_os << (" status =\t")) << xapic_lvt_timer_status_extract(_regval)) << ("\t(Delivery status)\n");
    // _anon13 is anonymous
    ((_os << (" mask =\t")) << xapic_lvt_timer_mask_extract(_regval)) << ("\t(Masked)\n");
    ((_os << (" mode =\t")) << xapic_lvt_timer_mode_extract(_regval)) << ("\t(Mode)\n");
    // _anon18 is anonymous
    return(_os);
}

static inline uint8_t xapic_lvt_timer_vector_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_lvt_timer_vector_rdf(__DN(t) *_dev)
{
    xapic_lvt_timer_t _regval = (xapic_lvt_timer_t )(mmio::read32(_dev->base, 0x320));
    return(xapic_lvt_timer_vector_extract(_regval));
}

static inline uint8_t xapic_lvt_timer_status_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_lvt_timer_status_rdf(__DN(t) *_dev)
{
    xapic_lvt_timer_t _regval = (xapic_lvt_timer_t )(mmio::read32(_dev->base, 0x320));
    return(xapic_lvt_timer_status_extract(_regval));
}

static inline xapic_int_mask_t xapic_lvt_timer_mask_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_int_mask_t xapic_lvt_timer_mask_rdf(__DN(t) *_dev)
{
    xapic_lvt_timer_t _regval = (xapic_lvt_timer_t )(mmio::read32(_dev->base, 0x320));
    return(xapic_lvt_timer_mask_extract(_regval));
}

static inline xapic_timer_mode_t xapic_lvt_timer_mode_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_timer_mode_t xapic_lvt_timer_mode_rdf(__DN(t) *_dev)
{
    xapic_lvt_timer_t _regval = (xapic_lvt_timer_t )(mmio::read32(_dev->base, 0x320));
    return(xapic_lvt_timer_mode_extract(_regval));
}

static inline void xapic_lvt_timer_vector_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_lvt_timer_vector_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xapic_lvt_timer_t _regval = (xapic_lvt_timer_t )(0xff & (((xapic_lvt_timer_t )(_fieldval)) << 0));
    _regval = (_regval | (0xffffff00 & ((xapic_lvt_timer_t )(mmio::read32(_dev->base, 0x320)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x320, _regval);
    // No shadow register to write to
}

static inline void xapic_lvt_timer_status_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_lvt_timer_status_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xapic_lvt_timer_t _regval = (xapic_lvt_timer_t )(0x1000 & (((xapic_lvt_timer_t )(_fieldval)) << 12));
    _regval = (_regval | (0xffffefff & ((xapic_lvt_timer_t )(mmio::read32(_dev->base, 0x320)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x320, _regval);
    // No shadow register to write to
}

static inline void xapic_lvt_timer_mask_wrf(__DN(t) *_dev, xapic_int_mask_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_lvt_timer_mask_wrf(__DN(t) *_dev, xapic_int_mask_t _fieldval)
{
    xapic_lvt_timer_t _regval = (xapic_lvt_timer_t )(0x10000 & (((xapic_lvt_timer_t )(_fieldval)) << 16));
    _regval = (_regval | (0xfffeffff & ((xapic_lvt_timer_t )(mmio::read32(_dev->base, 0x320)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x320, _regval);
    // No shadow register to write to
}

static inline void xapic_lvt_timer_mode_wrf(__DN(t) *_dev, xapic_timer_mode_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_lvt_timer_mode_wrf(__DN(t) *_dev, xapic_timer_mode_t _fieldval)
{
    xapic_lvt_timer_t _regval = (xapic_lvt_timer_t )(0x20000 & (((xapic_lvt_timer_t )(_fieldval)) << 17));
    _regval = (_regval | (0xfffdffff & ((xapic_lvt_timer_t )(mmio::read32(_dev->base, 0x320)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x320, _regval);
    // No shadow register to write to
}

/*
 * Register lvt_lint0: lvt_lint0
 * Type: xapic.lvt_lint (LVT Int)
 *   vector	(size 8, offset 0, init 0):	RW	Vector
 *   dlv_mode	(size 4, offset 8, init 0):	RW	Delivery mode
 *   _anon12	(size 1, offset 12, init 0):	RSVD	_
 *   status	(size 1, offset 13, init 0):	RW	Delivery status
 *   pinpol	(size 1, offset 14, init 0):	RW	Pin polarity
 *   rirr	(size 1, offset 15, init 0):	RW	Remote IRR
 *   trig_mode	(size 1, offset 16, init 0):	RW	Trigger mode
 *   mask	(size 1, offset 17, init 0):	RW	Mask
 *   _anon18	(size 14, offset 18, init 0):	RSVD	_
 */
static inline xapic_lvt_lint_t xapic_lvt_lint0_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_lvt_lint_t xapic_lvt_lint0_rawrd(__DN(t) *_dev)
{
    return((xapic_lvt_lint_t )(mmio::read32(_dev->base, 0x350)));
}

static inline xapic_lvt_lint_t xapic_lvt_lint0_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_lvt_lint_t xapic_lvt_lint0_rd(__DN(t) *_dev)
{
    return((xapic_lvt_lint_t )(mmio::read32(_dev->base, 0x350)));
}

static inline void xapic_lvt_lint0_rawwr(__DN(t) *_dev, xapic_lvt_lint_t _regval) __attribute__ ((always_inline));
static inline void xapic_lvt_lint0_rawwr(__DN(t) *_dev, xapic_lvt_lint_t _regval)
{
    mmio::write32(_dev->base, 0x350, _regval);
}

static inline void xapic_lvt_lint0_wr(__DN(t) *_dev, xapic_lvt_lint_t _regval) __attribute__ ((always_inline));
static inline void xapic_lvt_lint0_wr(__DN(t) *_dev, xapic_lvt_lint_t _regval)
{
    _regval = (_regval & 0x3efff);
    // No MB1 fields present
    _regval = (_regval | (0xfffc1000 & ((xapic_lvt_lint_t )(mmio::read32(_dev->base, 0x350)))));
    mmio::write32(_dev->base, 0x350, _regval);
}

static inline dout_t& xapic_lvt_lint0_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& xapic_lvt_lint0_pr(dout_t& _os, __DN(t) *_dev)
{
    xapic_lvt_lint_t _regval = (xapic_lvt_lint_t )(mmio::read32(_dev->base, 0x350));
    _os << ("Register lvt_lint0 (lvt_lint0): ");
    _os << ("\n");
    ((_os << (" vector =\t")) << xapic_lvt_lint_vector_extract(_regval)) << ("\t(Vector)\n");
    ((_os << (" dlv_mode =\t")) << xapic_lvt_lint_dlv_mode_extract(_regval)) << ("\t(Delivery mode)\n");
    // _anon12 is anonymous
    ((_os << (" status =\t")) << xapic_lvt_lint_status_extract(_regval)) << ("\t(Delivery status)\n");
    ((_os << (" pinpol =\t")) << xapic_lvt_lint_pinpol_extract(_regval)) << ("\t(Pin polarity)\n");
    ((_os << (" rirr =\t")) << xapic_lvt_lint_rirr_extract(_regval)) << ("\t(Remote IRR)\n");
    ((_os << (" trig_mode =\t")) << xapic_lvt_lint_trig_mode_extract(_regval)) << ("\t(Trigger mode)\n");
    ((_os << (" mask =\t")) << xapic_lvt_lint_mask_extract(_regval)) << ("\t(Mask)\n");
    // _anon18 is anonymous
    return(_os);
}

static inline uint8_t xapic_lvt_lint0_vector_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_lvt_lint0_vector_rdf(__DN(t) *_dev)
{
    xapic_lvt_lint_t _regval = (xapic_lvt_lint_t )(mmio::read32(_dev->base, 0x350));
    return(xapic_lvt_lint_vector_extract(_regval));
}

static inline xapic_vdm_t xapic_lvt_lint0_dlv_mode_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_vdm_t xapic_lvt_lint0_dlv_mode_rdf(__DN(t) *_dev)
{
    xapic_lvt_lint_t _regval = (xapic_lvt_lint_t )(mmio::read32(_dev->base, 0x350));
    return(xapic_lvt_lint_dlv_mode_extract(_regval));
}

static inline uint8_t xapic_lvt_lint0_status_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_lvt_lint0_status_rdf(__DN(t) *_dev)
{
    xapic_lvt_lint_t _regval = (xapic_lvt_lint_t )(mmio::read32(_dev->base, 0x350));
    return(xapic_lvt_lint_status_extract(_regval));
}

static inline uint8_t xapic_lvt_lint0_pinpol_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_lvt_lint0_pinpol_rdf(__DN(t) *_dev)
{
    xapic_lvt_lint_t _regval = (xapic_lvt_lint_t )(mmio::read32(_dev->base, 0x350));
    return(xapic_lvt_lint_pinpol_extract(_regval));
}

static inline uint8_t xapic_lvt_lint0_rirr_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_lvt_lint0_rirr_rdf(__DN(t) *_dev)
{
    xapic_lvt_lint_t _regval = (xapic_lvt_lint_t )(mmio::read32(_dev->base, 0x350));
    return(xapic_lvt_lint_rirr_extract(_regval));
}

static inline xapic_trigm_t xapic_lvt_lint0_trig_mode_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_trigm_t xapic_lvt_lint0_trig_mode_rdf(__DN(t) *_dev)
{
    xapic_lvt_lint_t _regval = (xapic_lvt_lint_t )(mmio::read32(_dev->base, 0x350));
    return(xapic_lvt_lint_trig_mode_extract(_regval));
}

static inline xapic_int_mask_t xapic_lvt_lint0_mask_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_int_mask_t xapic_lvt_lint0_mask_rdf(__DN(t) *_dev)
{
    xapic_lvt_lint_t _regval = (xapic_lvt_lint_t )(mmio::read32(_dev->base, 0x350));
    return(xapic_lvt_lint_mask_extract(_regval));
}

static inline void xapic_lvt_lint0_vector_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_lvt_lint0_vector_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xapic_lvt_lint_t _regval = (xapic_lvt_lint_t )(0xff & (((xapic_lvt_lint_t )(_fieldval)) << 0));
    _regval = (_regval | (0xffffff00 & ((xapic_lvt_lint_t )(mmio::read32(_dev->base, 0x350)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x350, _regval);
    // No shadow register to write to
}

static inline void xapic_lvt_lint0_dlv_mode_wrf(__DN(t) *_dev, xapic_vdm_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_lvt_lint0_dlv_mode_wrf(__DN(t) *_dev, xapic_vdm_t _fieldval)
{
    xapic_lvt_lint_t _regval = (xapic_lvt_lint_t )(0xf00 & (((xapic_lvt_lint_t )(_fieldval)) << 8));
    _regval = (_regval | (0xfffff0ff & ((xapic_lvt_lint_t )(mmio::read32(_dev->base, 0x350)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x350, _regval);
    // No shadow register to write to
}

static inline void xapic_lvt_lint0_status_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_lvt_lint0_status_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xapic_lvt_lint_t _regval = (xapic_lvt_lint_t )(0x2000 & (((xapic_lvt_lint_t )(_fieldval)) << 13));
    _regval = (_regval | (0xffffdfff & ((xapic_lvt_lint_t )(mmio::read32(_dev->base, 0x350)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x350, _regval);
    // No shadow register to write to
}

static inline void xapic_lvt_lint0_pinpol_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_lvt_lint0_pinpol_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xapic_lvt_lint_t _regval = (xapic_lvt_lint_t )(0x4000 & (((xapic_lvt_lint_t )(_fieldval)) << 14));
    _regval = (_regval | (0xffffbfff & ((xapic_lvt_lint_t )(mmio::read32(_dev->base, 0x350)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x350, _regval);
    // No shadow register to write to
}

static inline void xapic_lvt_lint0_rirr_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_lvt_lint0_rirr_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xapic_lvt_lint_t _regval = (xapic_lvt_lint_t )(0x8000 & (((xapic_lvt_lint_t )(_fieldval)) << 15));
    _regval = (_regval | (0xffff7fff & ((xapic_lvt_lint_t )(mmio::read32(_dev->base, 0x350)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x350, _regval);
    // No shadow register to write to
}

static inline void xapic_lvt_lint0_trig_mode_wrf(__DN(t) *_dev, xapic_trigm_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_lvt_lint0_trig_mode_wrf(__DN(t) *_dev, xapic_trigm_t _fieldval)
{
    xapic_lvt_lint_t _regval = (xapic_lvt_lint_t )(0x10000 & (((xapic_lvt_lint_t )(_fieldval)) << 16));
    _regval = (_regval | (0xfffeffff & ((xapic_lvt_lint_t )(mmio::read32(_dev->base, 0x350)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x350, _regval);
    // No shadow register to write to
}

static inline void xapic_lvt_lint0_mask_wrf(__DN(t) *_dev, xapic_int_mask_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_lvt_lint0_mask_wrf(__DN(t) *_dev, xapic_int_mask_t _fieldval)
{
    xapic_lvt_lint_t _regval = (xapic_lvt_lint_t )(0x20000 & (((xapic_lvt_lint_t )(_fieldval)) << 17));
    _regval = (_regval | (0xfffdffff & ((xapic_lvt_lint_t )(mmio::read32(_dev->base, 0x350)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x350, _regval);
    // No shadow register to write to
}

/*
 * Register lvt_lint1: lvt_lint1
 * Type: xapic.lvt_lint (LVT Int)
 *   vector	(size 8, offset 0, init 0):	RW	Vector
 *   dlv_mode	(size 4, offset 8, init 0):	RW	Delivery mode
 *   _anon12	(size 1, offset 12, init 0):	RSVD	_
 *   status	(size 1, offset 13, init 0):	RW	Delivery status
 *   pinpol	(size 1, offset 14, init 0):	RW	Pin polarity
 *   rirr	(size 1, offset 15, init 0):	RW	Remote IRR
 *   trig_mode	(size 1, offset 16, init 0):	RW	Trigger mode
 *   mask	(size 1, offset 17, init 0):	RW	Mask
 *   _anon18	(size 14, offset 18, init 0):	RSVD	_
 */
static inline xapic_lvt_lint_t xapic_lvt_lint1_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_lvt_lint_t xapic_lvt_lint1_rawrd(__DN(t) *_dev)
{
    return((xapic_lvt_lint_t )(mmio::read32(_dev->base, 0x360)));
}

static inline xapic_lvt_lint_t xapic_lvt_lint1_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_lvt_lint_t xapic_lvt_lint1_rd(__DN(t) *_dev)
{
    return((xapic_lvt_lint_t )(mmio::read32(_dev->base, 0x360)));
}

static inline void xapic_lvt_lint1_rawwr(__DN(t) *_dev, xapic_lvt_lint_t _regval) __attribute__ ((always_inline));
static inline void xapic_lvt_lint1_rawwr(__DN(t) *_dev, xapic_lvt_lint_t _regval)
{
    mmio::write32(_dev->base, 0x360, _regval);
}

static inline void xapic_lvt_lint1_wr(__DN(t) *_dev, xapic_lvt_lint_t _regval) __attribute__ ((always_inline));
static inline void xapic_lvt_lint1_wr(__DN(t) *_dev, xapic_lvt_lint_t _regval)
{
    _regval = (_regval & 0x3efff);
    // No MB1 fields present
    _regval = (_regval | (0xfffc1000 & ((xapic_lvt_lint_t )(mmio::read32(_dev->base, 0x360)))));
    mmio::write32(_dev->base, 0x360, _regval);
}

static inline dout_t& xapic_lvt_lint1_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& xapic_lvt_lint1_pr(dout_t& _os, __DN(t) *_dev)
{
    xapic_lvt_lint_t _regval = (xapic_lvt_lint_t )(mmio::read32(_dev->base, 0x360));
    _os << ("Register lvt_lint1 (lvt_lint1): ");
    _os << ("\n");
    ((_os << (" vector =\t")) << xapic_lvt_lint_vector_extract(_regval)) << ("\t(Vector)\n");
    ((_os << (" dlv_mode =\t")) << xapic_lvt_lint_dlv_mode_extract(_regval)) << ("\t(Delivery mode)\n");
    // _anon12 is anonymous
    ((_os << (" status =\t")) << xapic_lvt_lint_status_extract(_regval)) << ("\t(Delivery status)\n");
    ((_os << (" pinpol =\t")) << xapic_lvt_lint_pinpol_extract(_regval)) << ("\t(Pin polarity)\n");
    ((_os << (" rirr =\t")) << xapic_lvt_lint_rirr_extract(_regval)) << ("\t(Remote IRR)\n");
    ((_os << (" trig_mode =\t")) << xapic_lvt_lint_trig_mode_extract(_regval)) << ("\t(Trigger mode)\n");
    ((_os << (" mask =\t")) << xapic_lvt_lint_mask_extract(_regval)) << ("\t(Mask)\n");
    // _anon18 is anonymous
    return(_os);
}

static inline uint8_t xapic_lvt_lint1_vector_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_lvt_lint1_vector_rdf(__DN(t) *_dev)
{
    xapic_lvt_lint_t _regval = (xapic_lvt_lint_t )(mmio::read32(_dev->base, 0x360));
    return(xapic_lvt_lint_vector_extract(_regval));
}

static inline xapic_vdm_t xapic_lvt_lint1_dlv_mode_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_vdm_t xapic_lvt_lint1_dlv_mode_rdf(__DN(t) *_dev)
{
    xapic_lvt_lint_t _regval = (xapic_lvt_lint_t )(mmio::read32(_dev->base, 0x360));
    return(xapic_lvt_lint_dlv_mode_extract(_regval));
}

static inline uint8_t xapic_lvt_lint1_status_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_lvt_lint1_status_rdf(__DN(t) *_dev)
{
    xapic_lvt_lint_t _regval = (xapic_lvt_lint_t )(mmio::read32(_dev->base, 0x360));
    return(xapic_lvt_lint_status_extract(_regval));
}

static inline uint8_t xapic_lvt_lint1_pinpol_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_lvt_lint1_pinpol_rdf(__DN(t) *_dev)
{
    xapic_lvt_lint_t _regval = (xapic_lvt_lint_t )(mmio::read32(_dev->base, 0x360));
    return(xapic_lvt_lint_pinpol_extract(_regval));
}

static inline uint8_t xapic_lvt_lint1_rirr_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_lvt_lint1_rirr_rdf(__DN(t) *_dev)
{
    xapic_lvt_lint_t _regval = (xapic_lvt_lint_t )(mmio::read32(_dev->base, 0x360));
    return(xapic_lvt_lint_rirr_extract(_regval));
}

static inline xapic_trigm_t xapic_lvt_lint1_trig_mode_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_trigm_t xapic_lvt_lint1_trig_mode_rdf(__DN(t) *_dev)
{
    xapic_lvt_lint_t _regval = (xapic_lvt_lint_t )(mmio::read32(_dev->base, 0x360));
    return(xapic_lvt_lint_trig_mode_extract(_regval));
}

static inline xapic_int_mask_t xapic_lvt_lint1_mask_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_int_mask_t xapic_lvt_lint1_mask_rdf(__DN(t) *_dev)
{
    xapic_lvt_lint_t _regval = (xapic_lvt_lint_t )(mmio::read32(_dev->base, 0x360));
    return(xapic_lvt_lint_mask_extract(_regval));
}

static inline void xapic_lvt_lint1_vector_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_lvt_lint1_vector_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xapic_lvt_lint_t _regval = (xapic_lvt_lint_t )(0xff & (((xapic_lvt_lint_t )(_fieldval)) << 0));
    _regval = (_regval | (0xffffff00 & ((xapic_lvt_lint_t )(mmio::read32(_dev->base, 0x360)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x360, _regval);
    // No shadow register to write to
}

static inline void xapic_lvt_lint1_dlv_mode_wrf(__DN(t) *_dev, xapic_vdm_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_lvt_lint1_dlv_mode_wrf(__DN(t) *_dev, xapic_vdm_t _fieldval)
{
    xapic_lvt_lint_t _regval = (xapic_lvt_lint_t )(0xf00 & (((xapic_lvt_lint_t )(_fieldval)) << 8));
    _regval = (_regval | (0xfffff0ff & ((xapic_lvt_lint_t )(mmio::read32(_dev->base, 0x360)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x360, _regval);
    // No shadow register to write to
}

static inline void xapic_lvt_lint1_status_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_lvt_lint1_status_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xapic_lvt_lint_t _regval = (xapic_lvt_lint_t )(0x2000 & (((xapic_lvt_lint_t )(_fieldval)) << 13));
    _regval = (_regval | (0xffffdfff & ((xapic_lvt_lint_t )(mmio::read32(_dev->base, 0x360)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x360, _regval);
    // No shadow register to write to
}

static inline void xapic_lvt_lint1_pinpol_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_lvt_lint1_pinpol_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xapic_lvt_lint_t _regval = (xapic_lvt_lint_t )(0x4000 & (((xapic_lvt_lint_t )(_fieldval)) << 14));
    _regval = (_regval | (0xffffbfff & ((xapic_lvt_lint_t )(mmio::read32(_dev->base, 0x360)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x360, _regval);
    // No shadow register to write to
}

static inline void xapic_lvt_lint1_rirr_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_lvt_lint1_rirr_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xapic_lvt_lint_t _regval = (xapic_lvt_lint_t )(0x8000 & (((xapic_lvt_lint_t )(_fieldval)) << 15));
    _regval = (_regval | (0xffff7fff & ((xapic_lvt_lint_t )(mmio::read32(_dev->base, 0x360)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x360, _regval);
    // No shadow register to write to
}

static inline void xapic_lvt_lint1_trig_mode_wrf(__DN(t) *_dev, xapic_trigm_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_lvt_lint1_trig_mode_wrf(__DN(t) *_dev, xapic_trigm_t _fieldval)
{
    xapic_lvt_lint_t _regval = (xapic_lvt_lint_t )(0x10000 & (((xapic_lvt_lint_t )(_fieldval)) << 16));
    _regval = (_regval | (0xfffeffff & ((xapic_lvt_lint_t )(mmio::read32(_dev->base, 0x360)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x360, _regval);
    // No shadow register to write to
}

static inline void xapic_lvt_lint1_mask_wrf(__DN(t) *_dev, xapic_int_mask_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_lvt_lint1_mask_wrf(__DN(t) *_dev, xapic_int_mask_t _fieldval)
{
    xapic_lvt_lint_t _regval = (xapic_lvt_lint_t )(0x20000 & (((xapic_lvt_lint_t )(_fieldval)) << 17));
    _regval = (_regval | (0xfffdffff & ((xapic_lvt_lint_t )(mmio::read32(_dev->base, 0x360)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x360, _regval);
    // No shadow register to write to
}

/*
 * Register lvt_err: lvt_err
 * Type: xapic.lvt_err (Implicit type of lvt_err register)
 *   vector	(size 8, offset 0, init 0):	RW	Vector
 *   _anon8	(size 4, offset 8, init 0):	RSVD	_
 *   status	(size 1, offset 12, init 0):	RW	Delivery status
 *   _anon13	(size 3, offset 13, init 0):	RSVD	_
 *   mask	(size 1, offset 16, init 0):	RW	Mask
 *   _anon17	(size 15, offset 17, init 0):	RSVD	_
 */
static inline xapic_lvt_err_t xapic_lvt_err_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_lvt_err_t xapic_lvt_err_rawrd(__DN(t) *_dev)
{
    return((xapic_lvt_err_t )(mmio::read32(_dev->base, 0x370)));
}

static inline xapic_lvt_err_t xapic_lvt_err_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_lvt_err_t xapic_lvt_err_rd(__DN(t) *_dev)
{
    return((xapic_lvt_err_t )(mmio::read32(_dev->base, 0x370)));
}

static inline void xapic_lvt_err_rawwr(__DN(t) *_dev, xapic_lvt_err_t _regval) __attribute__ ((always_inline));
static inline void xapic_lvt_err_rawwr(__DN(t) *_dev, xapic_lvt_err_t _regval)
{
    mmio::write32(_dev->base, 0x370, _regval);
}

static inline void xapic_lvt_err_wr(__DN(t) *_dev, xapic_lvt_err_t _regval) __attribute__ ((always_inline));
static inline void xapic_lvt_err_wr(__DN(t) *_dev, xapic_lvt_err_t _regval)
{
    _regval = (_regval & 0x110ff);
    // No MB1 fields present
    _regval = (_regval | (0xfffeef00 & ((xapic_lvt_err_t )(mmio::read32(_dev->base, 0x370)))));
    mmio::write32(_dev->base, 0x370, _regval);
}

static inline dout_t& xapic_lvt_err_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& xapic_lvt_err_pr(dout_t& _os, __DN(t) *_dev)
{
    xapic_lvt_err_t _regval = (xapic_lvt_err_t )(mmio::read32(_dev->base, 0x370));
    _os << ("Register lvt_err (lvt_err): ");
    _os << ("\n");
    ((_os << (" vector =\t")) << xapic_lvt_err_vector_extract(_regval)) << ("\t(Vector)\n");
    // _anon8 is anonymous
    ((_os << (" status =\t")) << xapic_lvt_err_status_extract(_regval)) << ("\t(Delivery status)\n");
    // _anon13 is anonymous
    ((_os << (" mask =\t")) << xapic_lvt_err_mask_extract(_regval)) << ("\t(Mask)\n");
    // _anon17 is anonymous
    return(_os);
}

static inline uint8_t xapic_lvt_err_vector_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_lvt_err_vector_rdf(__DN(t) *_dev)
{
    xapic_lvt_err_t _regval = (xapic_lvt_err_t )(mmio::read32(_dev->base, 0x370));
    return(xapic_lvt_err_vector_extract(_regval));
}

static inline uint8_t xapic_lvt_err_status_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_lvt_err_status_rdf(__DN(t) *_dev)
{
    xapic_lvt_err_t _regval = (xapic_lvt_err_t )(mmio::read32(_dev->base, 0x370));
    return(xapic_lvt_err_status_extract(_regval));
}

static inline xapic_int_mask_t xapic_lvt_err_mask_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_int_mask_t xapic_lvt_err_mask_rdf(__DN(t) *_dev)
{
    xapic_lvt_err_t _regval = (xapic_lvt_err_t )(mmio::read32(_dev->base, 0x370));
    return(xapic_lvt_err_mask_extract(_regval));
}

static inline void xapic_lvt_err_vector_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_lvt_err_vector_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xapic_lvt_err_t _regval = (xapic_lvt_err_t )(0xff & (((xapic_lvt_err_t )(_fieldval)) << 0));
    _regval = (_regval | (0xffffff00 & ((xapic_lvt_err_t )(mmio::read32(_dev->base, 0x370)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x370, _regval);
    // No shadow register to write to
}

static inline void xapic_lvt_err_status_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_lvt_err_status_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xapic_lvt_err_t _regval = (xapic_lvt_err_t )(0x1000 & (((xapic_lvt_err_t )(_fieldval)) << 12));
    _regval = (_regval | (0xffffefff & ((xapic_lvt_err_t )(mmio::read32(_dev->base, 0x370)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x370, _regval);
    // No shadow register to write to
}

static inline void xapic_lvt_err_mask_wrf(__DN(t) *_dev, xapic_int_mask_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_lvt_err_mask_wrf(__DN(t) *_dev, xapic_int_mask_t _fieldval)
{
    xapic_lvt_err_t _regval = (xapic_lvt_err_t )(0x10000 & (((xapic_lvt_err_t )(_fieldval)) << 16));
    _regval = (_regval | (0xfffeffff & ((xapic_lvt_err_t )(mmio::read32(_dev->base, 0x370)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x370, _regval);
    // No shadow register to write to
}

/*
 * Register lvt_perf_cnt: lvt_perf_cnt
 * Type: xapic.lvt_mon (LVT monitor)
 *   vector	(size 8, offset 0, init 0):	RW	Vector
 *   msgType	(size 3, offset 8, init 0):	RW	msgType
 *   _anon11	(size 1, offset 11, init 0):	RSVD	_
 *   status	(size 1, offset 12, init 0):	RW	Delivery status
 *   _anon13	(size 3, offset 13, init 0):	RSVD	_
 *   mask	(size 1, offset 16, init 0):	RW	Masked
 *   _anon17	(size 15, offset 17, init 0):	RSVD	_
 */
static inline xapic_lvt_mon_t xapic_lvt_perf_cnt_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_lvt_mon_t xapic_lvt_perf_cnt_rawrd(__DN(t) *_dev)
{
    return((xapic_lvt_mon_t )(mmio::read32(_dev->base, 0x340)));
}

static inline xapic_lvt_mon_t xapic_lvt_perf_cnt_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_lvt_mon_t xapic_lvt_perf_cnt_rd(__DN(t) *_dev)
{
    return((xapic_lvt_mon_t )(mmio::read32(_dev->base, 0x340)));
}

static inline void xapic_lvt_perf_cnt_rawwr(__DN(t) *_dev, xapic_lvt_mon_t _regval) __attribute__ ((always_inline));
static inline void xapic_lvt_perf_cnt_rawwr(__DN(t) *_dev, xapic_lvt_mon_t _regval)
{
    mmio::write32(_dev->base, 0x340, _regval);
}

static inline void xapic_lvt_perf_cnt_wr(__DN(t) *_dev, xapic_lvt_mon_t _regval) __attribute__ ((always_inline));
static inline void xapic_lvt_perf_cnt_wr(__DN(t) *_dev, xapic_lvt_mon_t _regval)
{
    _regval = (_regval & 0x117ff);
    // No MB1 fields present
    _regval = (_regval | (0xfffee800 & ((xapic_lvt_mon_t )(mmio::read32(_dev->base, 0x340)))));
    mmio::write32(_dev->base, 0x340, _regval);
}

static inline dout_t& xapic_lvt_perf_cnt_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& xapic_lvt_perf_cnt_pr(dout_t& _os, __DN(t) *_dev)
{
    xapic_lvt_mon_t _regval = (xapic_lvt_mon_t )(mmio::read32(_dev->base, 0x340));
    _os << ("Register lvt_perf_cnt (lvt_perf_cnt): ");
    _os << ("\n");
    ((_os << (" vector =\t")) << xapic_lvt_mon_vector_extract(_regval)) << ("\t(Vector)\n");
    ((_os << (" msgType =\t")) << xapic_lvt_mon_msgType_extract(_regval)) << ("\t(msgType)\n");
    // _anon11 is anonymous
    ((_os << (" status =\t")) << xapic_lvt_mon_status_extract(_regval)) << ("\t(Delivery status)\n");
    // _anon13 is anonymous
    ((_os << (" mask =\t")) << xapic_lvt_mon_mask_extract(_regval)) << ("\t(Masked)\n");
    // _anon17 is anonymous
    return(_os);
}

static inline uint8_t xapic_lvt_perf_cnt_vector_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_lvt_perf_cnt_vector_rdf(__DN(t) *_dev)
{
    xapic_lvt_mon_t _regval = (xapic_lvt_mon_t )(mmio::read32(_dev->base, 0x340));
    return(xapic_lvt_mon_vector_extract(_regval));
}

static inline uint8_t xapic_lvt_perf_cnt_msgType_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_lvt_perf_cnt_msgType_rdf(__DN(t) *_dev)
{
    xapic_lvt_mon_t _regval = (xapic_lvt_mon_t )(mmio::read32(_dev->base, 0x340));
    return(xapic_lvt_mon_msgType_extract(_regval));
}

static inline uint8_t xapic_lvt_perf_cnt_status_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_lvt_perf_cnt_status_rdf(__DN(t) *_dev)
{
    xapic_lvt_mon_t _regval = (xapic_lvt_mon_t )(mmio::read32(_dev->base, 0x340));
    return(xapic_lvt_mon_status_extract(_regval));
}

static inline xapic_int_mask_t xapic_lvt_perf_cnt_mask_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_int_mask_t xapic_lvt_perf_cnt_mask_rdf(__DN(t) *_dev)
{
    xapic_lvt_mon_t _regval = (xapic_lvt_mon_t )(mmio::read32(_dev->base, 0x340));
    return(xapic_lvt_mon_mask_extract(_regval));
}

static inline void xapic_lvt_perf_cnt_vector_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_lvt_perf_cnt_vector_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xapic_lvt_mon_t _regval = (xapic_lvt_mon_t )(0xff & (((xapic_lvt_mon_t )(_fieldval)) << 0));
    _regval = (_regval | (0xffffff00 & ((xapic_lvt_mon_t )(mmio::read32(_dev->base, 0x340)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x340, _regval);
    // No shadow register to write to
}

static inline void xapic_lvt_perf_cnt_msgType_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_lvt_perf_cnt_msgType_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xapic_lvt_mon_t _regval = (xapic_lvt_mon_t )(0x700 & (((xapic_lvt_mon_t )(_fieldval)) << 8));
    _regval = (_regval | (0xfffff8ff & ((xapic_lvt_mon_t )(mmio::read32(_dev->base, 0x340)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x340, _regval);
    // No shadow register to write to
}

static inline void xapic_lvt_perf_cnt_status_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_lvt_perf_cnt_status_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xapic_lvt_mon_t _regval = (xapic_lvt_mon_t )(0x1000 & (((xapic_lvt_mon_t )(_fieldval)) << 12));
    _regval = (_regval | (0xffffefff & ((xapic_lvt_mon_t )(mmio::read32(_dev->base, 0x340)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x340, _regval);
    // No shadow register to write to
}

static inline void xapic_lvt_perf_cnt_mask_wrf(__DN(t) *_dev, xapic_int_mask_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_lvt_perf_cnt_mask_wrf(__DN(t) *_dev, xapic_int_mask_t _fieldval)
{
    xapic_lvt_mon_t _regval = (xapic_lvt_mon_t )(0x10000 & (((xapic_lvt_mon_t )(_fieldval)) << 16));
    _regval = (_regval | (0xfffeffff & ((xapic_lvt_mon_t )(mmio::read32(_dev->base, 0x340)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x340, _regval);
    // No shadow register to write to
}

/*
 * Register lvt_thermal: lvt_thermal
 * Type: xapic.lvt_mon (LVT monitor)
 *   vector	(size 8, offset 0, init 0):	RW	Vector
 *   msgType	(size 3, offset 8, init 0):	RW	msgType
 *   _anon11	(size 1, offset 11, init 0):	RSVD	_
 *   status	(size 1, offset 12, init 0):	RW	Delivery status
 *   _anon13	(size 3, offset 13, init 0):	RSVD	_
 *   mask	(size 1, offset 16, init 0):	RW	Masked
 *   _anon17	(size 15, offset 17, init 0):	RSVD	_
 */
static inline xapic_lvt_mon_t xapic_lvt_thermal_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_lvt_mon_t xapic_lvt_thermal_rawrd(__DN(t) *_dev)
{
    return((xapic_lvt_mon_t )(mmio::read32(_dev->base, 0x330)));
}

static inline xapic_lvt_mon_t xapic_lvt_thermal_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_lvt_mon_t xapic_lvt_thermal_rd(__DN(t) *_dev)
{
    return((xapic_lvt_mon_t )(mmio::read32(_dev->base, 0x330)));
}

static inline void xapic_lvt_thermal_rawwr(__DN(t) *_dev, xapic_lvt_mon_t _regval) __attribute__ ((always_inline));
static inline void xapic_lvt_thermal_rawwr(__DN(t) *_dev, xapic_lvt_mon_t _regval)
{
    mmio::write32(_dev->base, 0x330, _regval);
}

static inline void xapic_lvt_thermal_wr(__DN(t) *_dev, xapic_lvt_mon_t _regval) __attribute__ ((always_inline));
static inline void xapic_lvt_thermal_wr(__DN(t) *_dev, xapic_lvt_mon_t _regval)
{
    _regval = (_regval & 0x117ff);
    // No MB1 fields present
    _regval = (_regval | (0xfffee800 & ((xapic_lvt_mon_t )(mmio::read32(_dev->base, 0x330)))));
    mmio::write32(_dev->base, 0x330, _regval);
}

static inline dout_t& xapic_lvt_thermal_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& xapic_lvt_thermal_pr(dout_t& _os, __DN(t) *_dev)
{
    xapic_lvt_mon_t _regval = (xapic_lvt_mon_t )(mmio::read32(_dev->base, 0x330));
    _os << ("Register lvt_thermal (lvt_thermal): ");
    _os << ("\n");
    ((_os << (" vector =\t")) << xapic_lvt_mon_vector_extract(_regval)) << ("\t(Vector)\n");
    ((_os << (" msgType =\t")) << xapic_lvt_mon_msgType_extract(_regval)) << ("\t(msgType)\n");
    // _anon11 is anonymous
    ((_os << (" status =\t")) << xapic_lvt_mon_status_extract(_regval)) << ("\t(Delivery status)\n");
    // _anon13 is anonymous
    ((_os << (" mask =\t")) << xapic_lvt_mon_mask_extract(_regval)) << ("\t(Masked)\n");
    // _anon17 is anonymous
    return(_os);
}

static inline uint8_t xapic_lvt_thermal_vector_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_lvt_thermal_vector_rdf(__DN(t) *_dev)
{
    xapic_lvt_mon_t _regval = (xapic_lvt_mon_t )(mmio::read32(_dev->base, 0x330));
    return(xapic_lvt_mon_vector_extract(_regval));
}

static inline uint8_t xapic_lvt_thermal_msgType_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_lvt_thermal_msgType_rdf(__DN(t) *_dev)
{
    xapic_lvt_mon_t _regval = (xapic_lvt_mon_t )(mmio::read32(_dev->base, 0x330));
    return(xapic_lvt_mon_msgType_extract(_regval));
}

static inline uint8_t xapic_lvt_thermal_status_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_lvt_thermal_status_rdf(__DN(t) *_dev)
{
    xapic_lvt_mon_t _regval = (xapic_lvt_mon_t )(mmio::read32(_dev->base, 0x330));
    return(xapic_lvt_mon_status_extract(_regval));
}

static inline xapic_int_mask_t xapic_lvt_thermal_mask_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_int_mask_t xapic_lvt_thermal_mask_rdf(__DN(t) *_dev)
{
    xapic_lvt_mon_t _regval = (xapic_lvt_mon_t )(mmio::read32(_dev->base, 0x330));
    return(xapic_lvt_mon_mask_extract(_regval));
}

static inline void xapic_lvt_thermal_vector_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_lvt_thermal_vector_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xapic_lvt_mon_t _regval = (xapic_lvt_mon_t )(0xff & (((xapic_lvt_mon_t )(_fieldval)) << 0));
    _regval = (_regval | (0xffffff00 & ((xapic_lvt_mon_t )(mmio::read32(_dev->base, 0x330)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x330, _regval);
    // No shadow register to write to
}

static inline void xapic_lvt_thermal_msgType_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_lvt_thermal_msgType_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xapic_lvt_mon_t _regval = (xapic_lvt_mon_t )(0x700 & (((xapic_lvt_mon_t )(_fieldval)) << 8));
    _regval = (_regval | (0xfffff8ff & ((xapic_lvt_mon_t )(mmio::read32(_dev->base, 0x330)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x330, _regval);
    // No shadow register to write to
}

static inline void xapic_lvt_thermal_status_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_lvt_thermal_status_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xapic_lvt_mon_t _regval = (xapic_lvt_mon_t )(0x1000 & (((xapic_lvt_mon_t )(_fieldval)) << 12));
    _regval = (_regval | (0xffffefff & ((xapic_lvt_mon_t )(mmio::read32(_dev->base, 0x330)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x330, _regval);
    // No shadow register to write to
}

static inline void xapic_lvt_thermal_mask_wrf(__DN(t) *_dev, xapic_int_mask_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_lvt_thermal_mask_wrf(__DN(t) *_dev, xapic_int_mask_t _fieldval)
{
    xapic_lvt_mon_t _regval = (xapic_lvt_mon_t )(0x10000 & (((xapic_lvt_mon_t )(_fieldval)) << 16));
    _regval = (_regval | (0xfffeffff & ((xapic_lvt_mon_t )(mmio::read32(_dev->base, 0x330)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x330, _regval);
    // No shadow register to write to
}

/*
 * Register esr: Error Status
 * Type: xapic.esr (Implicit type of Error Status register)
 *   sce	(size 1, offset 0, init 0):	RW	Send checksum error
 *   rce	(size 1, offset 1, init 0):	RW	Receive checksum error
 *   sae	(size 1, offset 2, init 0):	RW	Send accept error
 *   rae	(size 1, offset 3, init 0):	RW	Receive accept error
 *   _anon4	(size 1, offset 4, init 0):	RSVD	_
 *   siv	(size 1, offset 5, init 0):	RW	Send illegal vector
 *   riv	(size 1, offset 6, init 0):	RW	Receive illegal vector
 *   ira	(size 1, offset 7, init 0):	RW	Illegal register address
 *   _anon8	(size 24, offset 8, init 0):	RSVD	_
 */
static inline xapic_esr_t xapic_esr_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_esr_t xapic_esr_rawrd(__DN(t) *_dev)
{
    return((xapic_esr_t )(mmio::read32(_dev->base, 0x280)));
}

static inline xapic_esr_t xapic_esr_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_esr_t xapic_esr_rd(__DN(t) *_dev)
{
    return((xapic_esr_t )(mmio::read32(_dev->base, 0x280)));
}

static inline void xapic_esr_rawwr(__DN(t) *_dev, xapic_esr_t _regval) __attribute__ ((always_inline));
static inline void xapic_esr_rawwr(__DN(t) *_dev, xapic_esr_t _regval)
{
    mmio::write32(_dev->base, 0x280, _regval);
}

static inline void xapic_esr_wr(__DN(t) *_dev, xapic_esr_t _regval) __attribute__ ((always_inline));
static inline void xapic_esr_wr(__DN(t) *_dev, xapic_esr_t _regval)
{
    _regval = (_regval & 0xef);
    // No MB1 fields present
    _regval = (_regval | (0xffffff10 & ((xapic_esr_t )(mmio::read32(_dev->base, 0x280)))));
    mmio::write32(_dev->base, 0x280, _regval);
}

static inline dout_t& xapic_esr_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& xapic_esr_pr(dout_t& _os, __DN(t) *_dev)
{
    xapic_esr_t _regval = (xapic_esr_t )(mmio::read32(_dev->base, 0x280));
    _os << ("Register esr (Error Status): ");
    _os << ("\n");
    ((_os << (" sce =\t")) << xapic_esr_sce_extract(_regval)) << ("\t(Send checksum error)\n");
    ((_os << (" rce =\t")) << xapic_esr_rce_extract(_regval)) << ("\t(Receive checksum error)\n");
    ((_os << (" sae =\t")) << xapic_esr_sae_extract(_regval)) << ("\t(Send accept error)\n");
    ((_os << (" rae =\t")) << xapic_esr_rae_extract(_regval)) << ("\t(Receive accept error)\n");
    // _anon4 is anonymous
    ((_os << (" siv =\t")) << xapic_esr_siv_extract(_regval)) << ("\t(Send illegal vector)\n");
    ((_os << (" riv =\t")) << xapic_esr_riv_extract(_regval)) << ("\t(Receive illegal vector)\n");
    ((_os << (" ira =\t")) << xapic_esr_ira_extract(_regval)) << ("\t(Illegal register address)\n");
    // _anon8 is anonymous
    return(_os);
}

static inline uint8_t xapic_esr_sce_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_esr_sce_rdf(__DN(t) *_dev)
{
    xapic_esr_t _regval = (xapic_esr_t )(mmio::read32(_dev->base, 0x280));
    return(xapic_esr_sce_extract(_regval));
}

static inline uint8_t xapic_esr_rce_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_esr_rce_rdf(__DN(t) *_dev)
{
    xapic_esr_t _regval = (xapic_esr_t )(mmio::read32(_dev->base, 0x280));
    return(xapic_esr_rce_extract(_regval));
}

static inline uint8_t xapic_esr_sae_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_esr_sae_rdf(__DN(t) *_dev)
{
    xapic_esr_t _regval = (xapic_esr_t )(mmio::read32(_dev->base, 0x280));
    return(xapic_esr_sae_extract(_regval));
}

static inline uint8_t xapic_esr_rae_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_esr_rae_rdf(__DN(t) *_dev)
{
    xapic_esr_t _regval = (xapic_esr_t )(mmio::read32(_dev->base, 0x280));
    return(xapic_esr_rae_extract(_regval));
}

static inline uint8_t xapic_esr_siv_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_esr_siv_rdf(__DN(t) *_dev)
{
    xapic_esr_t _regval = (xapic_esr_t )(mmio::read32(_dev->base, 0x280));
    return(xapic_esr_siv_extract(_regval));
}

static inline uint8_t xapic_esr_riv_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_esr_riv_rdf(__DN(t) *_dev)
{
    xapic_esr_t _regval = (xapic_esr_t )(mmio::read32(_dev->base, 0x280));
    return(xapic_esr_riv_extract(_regval));
}

static inline uint8_t xapic_esr_ira_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_esr_ira_rdf(__DN(t) *_dev)
{
    xapic_esr_t _regval = (xapic_esr_t )(mmio::read32(_dev->base, 0x280));
    return(xapic_esr_ira_extract(_regval));
}

static inline void xapic_esr_sce_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_esr_sce_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xapic_esr_t _regval = (xapic_esr_t )(0x1 & (((xapic_esr_t )(_fieldval)) << 0));
    _regval = (_regval | (0xfffffffe & ((xapic_esr_t )(mmio::read32(_dev->base, 0x280)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x280, _regval);
    // No shadow register to write to
}

static inline void xapic_esr_rce_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_esr_rce_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xapic_esr_t _regval = (xapic_esr_t )(0x2 & (((xapic_esr_t )(_fieldval)) << 1));
    _regval = (_regval | (0xfffffffd & ((xapic_esr_t )(mmio::read32(_dev->base, 0x280)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x280, _regval);
    // No shadow register to write to
}

static inline void xapic_esr_sae_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_esr_sae_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xapic_esr_t _regval = (xapic_esr_t )(0x4 & (((xapic_esr_t )(_fieldval)) << 2));
    _regval = (_regval | (0xfffffffb & ((xapic_esr_t )(mmio::read32(_dev->base, 0x280)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x280, _regval);
    // No shadow register to write to
}

static inline void xapic_esr_rae_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_esr_rae_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xapic_esr_t _regval = (xapic_esr_t )(0x8 & (((xapic_esr_t )(_fieldval)) << 3));
    _regval = (_regval | (0xfffffff7 & ((xapic_esr_t )(mmio::read32(_dev->base, 0x280)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x280, _regval);
    // No shadow register to write to
}

static inline void xapic_esr_siv_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_esr_siv_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xapic_esr_t _regval = (xapic_esr_t )(0x20 & (((xapic_esr_t )(_fieldval)) << 5));
    _regval = (_regval | (0xffffffdf & ((xapic_esr_t )(mmio::read32(_dev->base, 0x280)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x280, _regval);
    // No shadow register to write to
}

static inline void xapic_esr_riv_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_esr_riv_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xapic_esr_t _regval = (xapic_esr_t )(0x40 & (((xapic_esr_t )(_fieldval)) << 6));
    _regval = (_regval | (0xffffffbf & ((xapic_esr_t )(mmio::read32(_dev->base, 0x280)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x280, _regval);
    // No shadow register to write to
}

static inline void xapic_esr_ira_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_esr_ira_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xapic_esr_t _regval = (xapic_esr_t )(0x80 & (((xapic_esr_t )(_fieldval)) << 7));
    _regval = (_regval | (0xffffff7f & ((xapic_esr_t )(mmio::read32(_dev->base, 0x280)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x280, _regval);
    // No shadow register to write to
}

/*
 * Register dcr: Divide Configuration
 * Type: xapic.dcr (Implicit type of Divide Configuration register)
 *   div_val	(size 4, offset 0, init 0):	RW	Timer divide value
 *   _anon4	(size 28, offset 4, init 0):	RSVD	_
 */
static inline xapic_dcr_t xapic_dcr_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_dcr_t xapic_dcr_rawrd(__DN(t) *_dev)
{
    return((xapic_dcr_t )(mmio::read32(_dev->base, 0x3e0)));
}

static inline xapic_dcr_t xapic_dcr_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_dcr_t xapic_dcr_rd(__DN(t) *_dev)
{
    return((xapic_dcr_t )(mmio::read32(_dev->base, 0x3e0)));
}

static inline void xapic_dcr_rawwr(__DN(t) *_dev, xapic_dcr_t _regval) __attribute__ ((always_inline));
static inline void xapic_dcr_rawwr(__DN(t) *_dev, xapic_dcr_t _regval)
{
    mmio::write32(_dev->base, 0x3e0, _regval);
}

static inline void xapic_dcr_wr(__DN(t) *_dev, xapic_dcr_t _regval) __attribute__ ((always_inline));
static inline void xapic_dcr_wr(__DN(t) *_dev, xapic_dcr_t _regval)
{
    _regval = (_regval & 0xf);
    // No MB1 fields present
    _regval = (_regval | (0xfffffff0 & ((xapic_dcr_t )(mmio::read32(_dev->base, 0x3e0)))));
    mmio::write32(_dev->base, 0x3e0, _regval);
}

static inline dout_t& xapic_dcr_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& xapic_dcr_pr(dout_t& _os, __DN(t) *_dev)
{
    xapic_dcr_t _regval = (xapic_dcr_t )(mmio::read32(_dev->base, 0x3e0));
    _os << ("Register dcr (Divide Configuration): ");
    _os << ("\n");
    ((_os << (" div_val =\t")) << xapic_dcr_div_val_extract(_regval)) << ("\t(Timer divide value)\n");
    // _anon4 is anonymous
    return(_os);
}

static inline uint8_t xapic_dcr_div_val_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_dcr_div_val_rdf(__DN(t) *_dev)
{
    xapic_dcr_t _regval = (xapic_dcr_t )(mmio::read32(_dev->base, 0x3e0));
    return(xapic_dcr_div_val_extract(_regval));
}

static inline void xapic_dcr_div_val_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_dcr_div_val_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xapic_dcr_t _regval = (xapic_dcr_t )(0xf & (((xapic_dcr_t )(_fieldval)) << 0));
    _regval = (_regval | (0xfffffff0 & ((xapic_dcr_t )(mmio::read32(_dev->base, 0x3e0)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x3e0, _regval);
    // No shadow register to write to
}

/*
 * Register init_count: Initial Count
 * Type: xapic.uint32 (primitive type)
 */
static inline uint32_t xapic_init_count_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint32_t xapic_init_count_rawrd(__DN(t) *_dev)
{
    return((uint32_t )(mmio::read32(_dev->base, 0x380)));
}

static inline uint32_t xapic_init_count_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint32_t xapic_init_count_rd(__DN(t) *_dev)
{
    return((uint32_t )(mmio::read32(_dev->base, 0x380)));
}

static inline void xapic_init_count_rawwr(__DN(t) *_dev, uint32_t _regval) __attribute__ ((always_inline));
static inline void xapic_init_count_rawwr(__DN(t) *_dev, uint32_t _regval)
{
    mmio::write32(_dev->base, 0x380, _regval);
}

static inline void xapic_init_count_wr(__DN(t) *_dev, uint32_t _regval) __attribute__ ((always_inline));
static inline void xapic_init_count_wr(__DN(t) *_dev, uint32_t _regval)
{
    // No MB0 or RSVD fields present
    // No MB1 fields present
    // No pre-read of register required
    mmio::write32(_dev->base, 0x380, _regval);
}

static inline dout_t& xapic_init_count_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& xapic_init_count_pr(dout_t& _os, __DN(t) *_dev)
{
    uint32_t _regval = (uint32_t )(mmio::read32(_dev->base, 0x380));
    _os << ("Register init_count (Initial Count): ");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

/*
 * Register cur_count: Current Count
 * Type: xapic.uint32 (primitive type)
 */
static inline uint32_t xapic_cur_count_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint32_t xapic_cur_count_rawrd(__DN(t) *_dev)
{
    return((uint32_t )(mmio::read32(_dev->base, 0x390)));
}

static inline uint32_t xapic_cur_count_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint32_t xapic_cur_count_rd(__DN(t) *_dev)
{
    return((uint32_t )(mmio::read32(_dev->base, 0x390)));
}

static inline void xapic_cur_count_rawwr(__DN(t) *_dev, uint32_t _regval) __attribute__ ((always_inline));
static inline void xapic_cur_count_rawwr(__DN(t) *_dev, uint32_t _regval)
{
    mmio::write32(_dev->base, 0x390, _regval);
}

static inline void xapic_cur_count_wr(__DN(t) *_dev, uint32_t _regval) __attribute__ ((always_inline));
static inline void xapic_cur_count_wr(__DN(t) *_dev, uint32_t _regval)
{
    // No MB0 or RSVD fields present
    // No MB1 fields present
    // No pre-read of register required
    mmio::write32(_dev->base, 0x390, _regval);
}

static inline dout_t& xapic_cur_count_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& xapic_cur_count_pr(dout_t& _os, __DN(t) *_dev)
{
    uint32_t _regval = (uint32_t )(mmio::read32(_dev->base, 0x390));
    _os << ("Register cur_count (Current Count): ");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

/*
 * Register icr_lo: Interrupt Command (lo)
 * Type: xapic.icr_lo (Implicit type of Interrupt Command (lo) register)
 *   vector	(size 8, offset 0, init 0):	RW	Vector
 *   dlv_mode	(size 3, offset 8, init 0):	RW	Delivery mode
 *   dst_mode	(size 1, offset 11, init 0):	RW	Destination mode
 *   dlv_stat	(size 1, offset 12, init 0):	RO	Delivery status
 *   _anon13	(size 1, offset 13, init 0):	RSVD	_
 *   level	(size 1, offset 14, init 0):	RW	Level
 *   trig_mode	(size 1, offset 15, init 0):	RW	Trigger mode
 *   _anon16	(size 2, offset 16, init 0):	RSVD	_
 *   dst_short	(size 2, offset 18, init 0):	RW	Destination shorthand
 *   _anon20	(size 12, offset 20, init 0):	RSVD	_
 */
static inline xapic_icr_lo_t xapic_icr_lo_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_icr_lo_t xapic_icr_lo_rawrd(__DN(t) *_dev)
{
    return((xapic_icr_lo_t )(mmio::read32(_dev->base, 0x300)));
}

static inline xapic_icr_lo_t xapic_icr_lo_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_icr_lo_t xapic_icr_lo_rd(__DN(t) *_dev)
{
    return((xapic_icr_lo_t )(mmio::read32(_dev->base, 0x300)));
}

static inline void xapic_icr_lo_rawwr(__DN(t) *_dev, xapic_icr_lo_t _regval) __attribute__ ((always_inline));
static inline void xapic_icr_lo_rawwr(__DN(t) *_dev, xapic_icr_lo_t _regval)
{
    mmio::write32(_dev->base, 0x300, _regval);
}

static inline void xapic_icr_lo_wr(__DN(t) *_dev, xapic_icr_lo_t _regval) __attribute__ ((always_inline));
static inline void xapic_icr_lo_wr(__DN(t) *_dev, xapic_icr_lo_t _regval)
{
    _regval = (_regval & 0xcdfff);
    // No MB1 fields present
    _regval = (_regval | (0xfff32000 & ((xapic_icr_lo_t )(mmio::read32(_dev->base, 0x300)))));
    mmio::write32(_dev->base, 0x300, _regval);
}

static inline dout_t& xapic_icr_lo_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& xapic_icr_lo_pr(dout_t& _os, __DN(t) *_dev)
{
    xapic_icr_lo_t _regval = (xapic_icr_lo_t )(mmio::read32(_dev->base, 0x300));
    _os << ("Register icr_lo (Interrupt Command (lo)): ");
    _os << ("\n");
    ((_os << (" vector =\t")) << xapic_icr_lo_vector_extract(_regval)) << ("\t(Vector)\n");
    ((_os << (" dlv_mode =\t")) << xapic_icr_lo_dlv_mode_extract(_regval)) << ("\t(Delivery mode)\n");
    ((_os << (" dst_mode =\t")) << xapic_icr_lo_dst_mode_extract(_regval)) << ("\t(Destination mode)\n");
    ((_os << (" dlv_stat =\t")) << xapic_icr_lo_dlv_stat_extract(_regval)) << ("\t(Delivery status)\n");
    // _anon13 is anonymous
    ((_os << (" level =\t")) << xapic_icr_lo_level_extract(_regval)) << ("\t(Level)\n");
    ((_os << (" trig_mode =\t")) << xapic_icr_lo_trig_mode_extract(_regval)) << ("\t(Trigger mode)\n");
    // _anon16 is anonymous
    ((_os << (" dst_short =\t")) << xapic_icr_lo_dst_short_extract(_regval)) << ("\t(Destination shorthand)\n");
    // _anon20 is anonymous
    return(_os);
}

static inline uint8_t xapic_icr_lo_vector_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_icr_lo_vector_rdf(__DN(t) *_dev)
{
    xapic_icr_lo_t _regval = (xapic_icr_lo_t )(mmio::read32(_dev->base, 0x300));
    return(xapic_icr_lo_vector_extract(_regval));
}

static inline xapic_vdm_t xapic_icr_lo_dlv_mode_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_vdm_t xapic_icr_lo_dlv_mode_rdf(__DN(t) *_dev)
{
    xapic_icr_lo_t _regval = (xapic_icr_lo_t )(mmio::read32(_dev->base, 0x300));
    return(xapic_icr_lo_dlv_mode_extract(_regval));
}

static inline xapic_dst_mode_t xapic_icr_lo_dst_mode_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_dst_mode_t xapic_icr_lo_dst_mode_rdf(__DN(t) *_dev)
{
    xapic_icr_lo_t _regval = (xapic_icr_lo_t )(mmio::read32(_dev->base, 0x300));
    return(xapic_icr_lo_dst_mode_extract(_regval));
}

static inline uint8_t xapic_icr_lo_dlv_stat_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_icr_lo_dlv_stat_rdf(__DN(t) *_dev)
{
    xapic_icr_lo_t _regval = (xapic_icr_lo_t )(mmio::read32(_dev->base, 0x300));
    return(xapic_icr_lo_dlv_stat_extract(_regval));
}

static inline xapic_int_level_t xapic_icr_lo_level_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_int_level_t xapic_icr_lo_level_rdf(__DN(t) *_dev)
{
    xapic_icr_lo_t _regval = (xapic_icr_lo_t )(mmio::read32(_dev->base, 0x300));
    return(xapic_icr_lo_level_extract(_regval));
}

static inline xapic_trigm_t xapic_icr_lo_trig_mode_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_trigm_t xapic_icr_lo_trig_mode_rdf(__DN(t) *_dev)
{
    xapic_icr_lo_t _regval = (xapic_icr_lo_t )(mmio::read32(_dev->base, 0x300));
    return(xapic_icr_lo_trig_mode_extract(_regval));
}

static inline xapic_dst_shorthand_t xapic_icr_lo_dst_short_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_dst_shorthand_t xapic_icr_lo_dst_short_rdf(__DN(t) *_dev)
{
    xapic_icr_lo_t _regval = (xapic_icr_lo_t )(mmio::read32(_dev->base, 0x300));
    return(xapic_icr_lo_dst_short_extract(_regval));
}

static inline void xapic_icr_lo_vector_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_icr_lo_vector_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xapic_icr_lo_t _regval = (xapic_icr_lo_t )(0xff & (((xapic_icr_lo_t )(_fieldval)) << 0));
    _regval = (_regval | (0xffffef00 & ((xapic_icr_lo_t )(mmio::read32(_dev->base, 0x300)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x300, _regval);
    // No shadow register to write to
}

static inline void xapic_icr_lo_dlv_mode_wrf(__DN(t) *_dev, xapic_vdm_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_icr_lo_dlv_mode_wrf(__DN(t) *_dev, xapic_vdm_t _fieldval)
{
    xapic_icr_lo_t _regval = (xapic_icr_lo_t )(0x700 & (((xapic_icr_lo_t )(_fieldval)) << 8));
    _regval = (_regval | (0xffffe8ff & ((xapic_icr_lo_t )(mmio::read32(_dev->base, 0x300)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x300, _regval);
    // No shadow register to write to
}

static inline void xapic_icr_lo_dst_mode_wrf(__DN(t) *_dev, xapic_dst_mode_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_icr_lo_dst_mode_wrf(__DN(t) *_dev, xapic_dst_mode_t _fieldval)
{
    xapic_icr_lo_t _regval = (xapic_icr_lo_t )(0x800 & (((xapic_icr_lo_t )(_fieldval)) << 11));
    _regval = (_regval | (0xffffe7ff & ((xapic_icr_lo_t )(mmio::read32(_dev->base, 0x300)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x300, _regval);
    // No shadow register to write to
}

static inline void xapic_icr_lo_level_wrf(__DN(t) *_dev, xapic_int_level_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_icr_lo_level_wrf(__DN(t) *_dev, xapic_int_level_t _fieldval)
{
    xapic_icr_lo_t _regval = (xapic_icr_lo_t )(0x4000 & (((xapic_icr_lo_t )(_fieldval)) << 14));
    _regval = (_regval | (0xffffafff & ((xapic_icr_lo_t )(mmio::read32(_dev->base, 0x300)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x300, _regval);
    // No shadow register to write to
}

static inline void xapic_icr_lo_trig_mode_wrf(__DN(t) *_dev, xapic_trigm_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_icr_lo_trig_mode_wrf(__DN(t) *_dev, xapic_trigm_t _fieldval)
{
    xapic_icr_lo_t _regval = (xapic_icr_lo_t )(0x8000 & (((xapic_icr_lo_t )(_fieldval)) << 15));
    _regval = (_regval | (0xffff6fff & ((xapic_icr_lo_t )(mmio::read32(_dev->base, 0x300)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x300, _regval);
    // No shadow register to write to
}

static inline void xapic_icr_lo_dst_short_wrf(__DN(t) *_dev, xapic_dst_shorthand_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_icr_lo_dst_short_wrf(__DN(t) *_dev, xapic_dst_shorthand_t _fieldval)
{
    xapic_icr_lo_t _regval = (xapic_icr_lo_t )(0xc0000 & (((xapic_icr_lo_t )(_fieldval)) << 18));
    _regval = (_regval | (0xfff3efff & ((xapic_icr_lo_t )(mmio::read32(_dev->base, 0x300)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x300, _regval);
    // No shadow register to write to
}

/*
 * Register icr_hi: Interrupt Commmand (hi)
 * Type: xapic.icr_hi (Implicit type of Interrupt Commmand (hi) register)
 *   _anon0	(size 24, offset 0, init 0):	RSVD	_
 *   dest	(size 8, offset 24, init 0):	RW	Destination field
 */
static inline xapic_icr_hi_t xapic_icr_hi_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_icr_hi_t xapic_icr_hi_rawrd(__DN(t) *_dev)
{
    return((xapic_icr_hi_t )(mmio::read32(_dev->base, 0x310)));
}

static inline xapic_icr_hi_t xapic_icr_hi_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_icr_hi_t xapic_icr_hi_rd(__DN(t) *_dev)
{
    return((xapic_icr_hi_t )(mmio::read32(_dev->base, 0x310)));
}

static inline void xapic_icr_hi_rawwr(__DN(t) *_dev, xapic_icr_hi_t _regval) __attribute__ ((always_inline));
static inline void xapic_icr_hi_rawwr(__DN(t) *_dev, xapic_icr_hi_t _regval)
{
    mmio::write32(_dev->base, 0x310, _regval);
}

static inline void xapic_icr_hi_wr(__DN(t) *_dev, xapic_icr_hi_t _regval) __attribute__ ((always_inline));
static inline void xapic_icr_hi_wr(__DN(t) *_dev, xapic_icr_hi_t _regval)
{
    _regval = (_regval & 0xff000000);
    // No MB1 fields present
    _regval = (_regval | (0xffffff & ((xapic_icr_hi_t )(mmio::read32(_dev->base, 0x310)))));
    mmio::write32(_dev->base, 0x310, _regval);
}

static inline dout_t& xapic_icr_hi_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& xapic_icr_hi_pr(dout_t& _os, __DN(t) *_dev)
{
    xapic_icr_hi_t _regval = (xapic_icr_hi_t )(mmio::read32(_dev->base, 0x310));
    _os << ("Register icr_hi (Interrupt Commmand (hi)): ");
    _os << ("\n");
    // _anon0 is anonymous
    ((_os << (" dest =\t")) << xapic_icr_hi_dest_extract(_regval)) << ("\t(Destination field)\n");
    return(_os);
}

static inline uint8_t xapic_icr_hi_dest_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_icr_hi_dest_rdf(__DN(t) *_dev)
{
    xapic_icr_hi_t _regval = (xapic_icr_hi_t )(mmio::read32(_dev->base, 0x310));
    return(xapic_icr_hi_dest_extract(_regval));
}

static inline void xapic_icr_hi_dest_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_icr_hi_dest_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xapic_icr_hi_t _regval = (xapic_icr_hi_t )(0xff000000 & (((xapic_icr_hi_t )(_fieldval)) << 24));
    _regval = (_regval | (0xffffff & ((xapic_icr_hi_t )(mmio::read32(_dev->base, 0x310)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x310, _regval);
    // No shadow register to write to
}

/*
 * Register ldr: Logical Destination
 * Type: xapic.ldr (Implicit type of Logical Destination register)
 *   _anon0	(size 24, offset 0, init 0):	RSVD	_
 *   log_id	(size 8, offset 24, init 0):	RW	Logical APIC ID
 */
static inline xapic_ldr_t xapic_ldr_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_ldr_t xapic_ldr_rawrd(__DN(t) *_dev)
{
    return((xapic_ldr_t )(mmio::read32(_dev->base, 0xd0)));
}

static inline xapic_ldr_t xapic_ldr_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_ldr_t xapic_ldr_rd(__DN(t) *_dev)
{
    return((xapic_ldr_t )(mmio::read32(_dev->base, 0xd0)));
}

static inline void xapic_ldr_rawwr(__DN(t) *_dev, xapic_ldr_t _regval) __attribute__ ((always_inline));
static inline void xapic_ldr_rawwr(__DN(t) *_dev, xapic_ldr_t _regval)
{
    mmio::write32(_dev->base, 0xd0, _regval);
}

static inline void xapic_ldr_wr(__DN(t) *_dev, xapic_ldr_t _regval) __attribute__ ((always_inline));
static inline void xapic_ldr_wr(__DN(t) *_dev, xapic_ldr_t _regval)
{
    _regval = (_regval & 0xff000000);
    // No MB1 fields present
    _regval = (_regval | (0xffffff & ((xapic_ldr_t )(mmio::read32(_dev->base, 0xd0)))));
    mmio::write32(_dev->base, 0xd0, _regval);
}

static inline dout_t& xapic_ldr_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& xapic_ldr_pr(dout_t& _os, __DN(t) *_dev)
{
    xapic_ldr_t _regval = (xapic_ldr_t )(mmio::read32(_dev->base, 0xd0));
    _os << ("Register ldr (Logical Destination): ");
    _os << ("\n");
    // _anon0 is anonymous
    ((_os << (" log_id =\t")) << xapic_ldr_log_id_extract(_regval)) << ("\t(Logical APIC ID)\n");
    return(_os);
}

static inline uint8_t xapic_ldr_log_id_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_ldr_log_id_rdf(__DN(t) *_dev)
{
    xapic_ldr_t _regval = (xapic_ldr_t )(mmio::read32(_dev->base, 0xd0));
    return(xapic_ldr_log_id_extract(_regval));
}

static inline void xapic_ldr_log_id_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_ldr_log_id_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xapic_ldr_t _regval = (xapic_ldr_t )(0xff000000 & (((xapic_ldr_t )(_fieldval)) << 24));
    _regval = (_regval | (0xffffff & ((xapic_ldr_t )(mmio::read32(_dev->base, 0xd0)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0xd0, _regval);
    // No shadow register to write to
}

/*
 * Register dfr: Destination Format
 * Type: xapic.dfr (Implicit type of Destination Format register)
 *   _anon0	(size 28, offset 0, init fffffff):	MB1	_
 *   model	(size 4, offset 28, init 0):	RW	Model
 */
static inline xapic_dfr_t xapic_dfr_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_dfr_t xapic_dfr_rawrd(__DN(t) *_dev)
{
    return((xapic_dfr_t )(mmio::read32(_dev->base, 0xe0)));
}

static inline xapic_dfr_t xapic_dfr_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_dfr_t xapic_dfr_rd(__DN(t) *_dev)
{
    return((xapic_dfr_t )(mmio::read32(_dev->base, 0xe0)));
}

static inline void xapic_dfr_rawwr(__DN(t) *_dev, xapic_dfr_t _regval) __attribute__ ((always_inline));
static inline void xapic_dfr_rawwr(__DN(t) *_dev, xapic_dfr_t _regval)
{
    mmio::write32(_dev->base, 0xe0, _regval);
}

static inline void xapic_dfr_wr(__DN(t) *_dev, xapic_dfr_t _regval) __attribute__ ((always_inline));
static inline void xapic_dfr_wr(__DN(t) *_dev, xapic_dfr_t _regval)
{
    // No MB0 or RSVD fields present
    _regval = (_regval | 0xfffffff);
    // No pre-read of register required
    mmio::write32(_dev->base, 0xe0, _regval);
}

static inline dout_t& xapic_dfr_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& xapic_dfr_pr(dout_t& _os, __DN(t) *_dev)
{
    xapic_dfr_t _regval = (xapic_dfr_t )(mmio::read32(_dev->base, 0xe0));
    _os << ("Register dfr (Destination Format): ");
    _os << ("\n");
    // _anon0 is anonymous
    ((_os << (" model =\t")) << xapic_dfr_model_extract(_regval)) << ("\t(Model)\n");
    return(_os);
}

static inline xapic_model_type_t xapic_dfr_model_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_model_type_t xapic_dfr_model_rdf(__DN(t) *_dev)
{
    xapic_dfr_t _regval = (xapic_dfr_t )(mmio::read32(_dev->base, 0xe0));
    return(xapic_dfr_model_extract(_regval));
}

static inline void xapic_dfr_model_wrf(__DN(t) *_dev, xapic_model_type_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_dfr_model_wrf(__DN(t) *_dev, xapic_model_type_t _fieldval)
{
    xapic_dfr_t _regval = (xapic_dfr_t )(0xf0000000 & (((xapic_dfr_t )(_fieldval)) << 28));
    // No pre-read of register required
    // No read of register shadow required
    // No MB0 fields present
    _regval = (_regval | 0xfffffff);
    mmio::write32(_dev->base, 0xe0, _regval);
    // No shadow register to write to
}

/*
 * Register apr: Arbitration priority
 * Type: xapic.priority (Various priorities)
 *   sub_class	(size 4, offset 0, init 0):	RO	Priority subclass
 *   priority	(size 4, offset 4, init 0):	RO	Priority
 *   _anon8	(size 24, offset 8, init 0):	RSVD	_
 */
static inline xapic_priority_t xapic_apr_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_priority_t xapic_apr_rawrd(__DN(t) *_dev)
{
    return((xapic_priority_t )(mmio::read32(_dev->base, 0x90)));
}

static inline xapic_priority_t xapic_apr_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_priority_t xapic_apr_rd(__DN(t) *_dev)
{
    return((xapic_priority_t )(mmio::read32(_dev->base, 0x90)));
}

static inline void xapic_apr_rawwr(__DN(t) *_dev, xapic_priority_t _regval) __attribute__ ((always_inline));
static inline void xapic_apr_rawwr(__DN(t) *_dev, xapic_priority_t _regval)
{
    mmio::write32(_dev->base, 0x90, _regval);
}

// Register apr is not writeable
static inline dout_t& xapic_apr_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& xapic_apr_pr(dout_t& _os, __DN(t) *_dev)
{
    xapic_priority_t _regval = (xapic_priority_t )(mmio::read32(_dev->base, 0x90));
    _os << ("Register apr (Arbitration priority): ");
    _os << ("\n");
    ((_os << (" sub_class =\t")) << xapic_priority_sub_class_extract(_regval)) << ("\t(Priority subclass)\n");
    ((_os << (" priority =\t")) << xapic_priority_priority_extract(_regval)) << ("\t(Priority)\n");
    // _anon8 is anonymous
    return(_os);
}

static inline uint8_t xapic_apr_sub_class_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_apr_sub_class_rdf(__DN(t) *_dev)
{
    xapic_priority_t _regval = (xapic_priority_t )(mmio::read32(_dev->base, 0x90));
    return(xapic_priority_sub_class_extract(_regval));
}

static inline uint8_t xapic_apr_priority_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_apr_priority_rdf(__DN(t) *_dev)
{
    xapic_priority_t _regval = (xapic_priority_t )(mmio::read32(_dev->base, 0x90));
    return(xapic_priority_priority_extract(_regval));
}

/*
 * Register tpr: Task priority
 * Type: xapic.priority (Various priorities)
 *   sub_class	(size 4, offset 0, init 0):	RW	Priority subclass
 *   priority	(size 4, offset 4, init 0):	RW	Priority
 *   _anon8	(size 24, offset 8, init 0):	RSVD	_
 */
static inline xapic_priority_t xapic_tpr_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_priority_t xapic_tpr_rawrd(__DN(t) *_dev)
{
    return((xapic_priority_t )(mmio::read32(_dev->base, 0x80)));
}

static inline xapic_priority_t xapic_tpr_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_priority_t xapic_tpr_rd(__DN(t) *_dev)
{
    return((xapic_priority_t )(mmio::read32(_dev->base, 0x80)));
}

static inline void xapic_tpr_rawwr(__DN(t) *_dev, xapic_priority_t _regval) __attribute__ ((always_inline));
static inline void xapic_tpr_rawwr(__DN(t) *_dev, xapic_priority_t _regval)
{
    mmio::write32(_dev->base, 0x80, _regval);
}

static inline void xapic_tpr_wr(__DN(t) *_dev, xapic_priority_t _regval) __attribute__ ((always_inline));
static inline void xapic_tpr_wr(__DN(t) *_dev, xapic_priority_t _regval)
{
    _regval = (_regval & 0xff);
    // No MB1 fields present
    _regval = (_regval | (0xffffff00 & ((xapic_priority_t )(mmio::read32(_dev->base, 0x80)))));
    mmio::write32(_dev->base, 0x80, _regval);
}

static inline dout_t& xapic_tpr_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& xapic_tpr_pr(dout_t& _os, __DN(t) *_dev)
{
    xapic_priority_t _regval = (xapic_priority_t )(mmio::read32(_dev->base, 0x80));
    _os << ("Register tpr (Task priority): ");
    _os << ("\n");
    ((_os << (" sub_class =\t")) << xapic_priority_sub_class_extract(_regval)) << ("\t(Priority subclass)\n");
    ((_os << (" priority =\t")) << xapic_priority_priority_extract(_regval)) << ("\t(Priority)\n");
    // _anon8 is anonymous
    return(_os);
}

static inline uint8_t xapic_tpr_sub_class_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_tpr_sub_class_rdf(__DN(t) *_dev)
{
    xapic_priority_t _regval = (xapic_priority_t )(mmio::read32(_dev->base, 0x80));
    return(xapic_priority_sub_class_extract(_regval));
}

static inline uint8_t xapic_tpr_priority_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_tpr_priority_rdf(__DN(t) *_dev)
{
    xapic_priority_t _regval = (xapic_priority_t )(mmio::read32(_dev->base, 0x80));
    return(xapic_priority_priority_extract(_regval));
}

static inline void xapic_tpr_sub_class_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_tpr_sub_class_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xapic_priority_t _regval = (xapic_priority_t )(0xf & (((xapic_priority_t )(_fieldval)) << 0));
    _regval = (_regval | (0xfffffff0 & ((xapic_priority_t )(mmio::read32(_dev->base, 0x80)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x80, _regval);
    // No shadow register to write to
}

static inline void xapic_tpr_priority_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_tpr_priority_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xapic_priority_t _regval = (xapic_priority_t )(0xf0 & (((xapic_priority_t )(_fieldval)) << 4));
    _regval = (_regval | (0xffffff0f & ((xapic_priority_t )(mmio::read32(_dev->base, 0x80)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x80, _regval);
    // No shadow register to write to
}

/*
 * Register ppr: Processor priority
 * Type: xapic.priority (Various priorities)
 *   sub_class	(size 4, offset 0, init 0):	RO	Priority subclass
 *   priority	(size 4, offset 4, init 0):	RO	Priority
 *   _anon8	(size 24, offset 8, init 0):	RSVD	_
 */
static inline xapic_priority_t xapic_ppr_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_priority_t xapic_ppr_rawrd(__DN(t) *_dev)
{
    return((xapic_priority_t )(mmio::read32(_dev->base, 0xa0)));
}

static inline xapic_priority_t xapic_ppr_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_priority_t xapic_ppr_rd(__DN(t) *_dev)
{
    return((xapic_priority_t )(mmio::read32(_dev->base, 0xa0)));
}

static inline void xapic_ppr_rawwr(__DN(t) *_dev, xapic_priority_t _regval) __attribute__ ((always_inline));
static inline void xapic_ppr_rawwr(__DN(t) *_dev, xapic_priority_t _regval)
{
    mmio::write32(_dev->base, 0xa0, _regval);
}

// Register ppr is not writeable
static inline dout_t& xapic_ppr_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& xapic_ppr_pr(dout_t& _os, __DN(t) *_dev)
{
    xapic_priority_t _regval = (xapic_priority_t )(mmio::read32(_dev->base, 0xa0));
    _os << ("Register ppr (Processor priority): ");
    _os << ("\n");
    ((_os << (" sub_class =\t")) << xapic_priority_sub_class_extract(_regval)) << ("\t(Priority subclass)\n");
    ((_os << (" priority =\t")) << xapic_priority_priority_extract(_regval)) << ("\t(Priority)\n");
    // _anon8 is anonymous
    return(_os);
}

static inline uint8_t xapic_ppr_sub_class_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_ppr_sub_class_rdf(__DN(t) *_dev)
{
    xapic_priority_t _regval = (xapic_priority_t )(mmio::read32(_dev->base, 0xa0));
    return(xapic_priority_sub_class_extract(_regval));
}

static inline uint8_t xapic_ppr_priority_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_ppr_priority_rdf(__DN(t) *_dev)
{
    xapic_priority_t _regval = (xapic_priority_t )(mmio::read32(_dev->base, 0xa0));
    return(xapic_priority_priority_extract(_regval));
}

/*
 * Register array isr: ISR
 * Type: xapic.uint32 (primitive type)
 */
static const size_t xapic_isr_length = 8;
static inline uint32_t xapic_isr_rawrd(__DN(t) *_dev, int _i) __attribute__ ((always_inline));
static inline uint32_t xapic_isr_rawrd(__DN(t) *_dev, int _i)
{
    return((uint32_t )(mmio::read32(_dev->base, 0x100 + (_i * 16))));
}

static inline uint32_t xapic_isr_rd(__DN(t) *_dev, int _i) __attribute__ ((always_inline));
static inline uint32_t xapic_isr_rd(__DN(t) *_dev, int _i)
{
    return((uint32_t )(mmio::read32(_dev->base, 0x100 + (_i * 16))));
}

static inline void xapic_isr_rawwr(__DN(t) *_dev, int _i, uint32_t _regval) __attribute__ ((always_inline));
static inline void xapic_isr_rawwr(__DN(t) *_dev, int _i, uint32_t _regval)
{
    mmio::write32(_dev->base, 0x100 + (_i * 16), _regval);
}

// Register isr is not writeable
static inline dout_t& xapic_isr_pri(dout_t& _os, __DN(t) *_dev, int _i) __attribute__ ((always_inline));
static inline dout_t& xapic_isr_pri(dout_t& _os, __DN(t) *_dev, int _i)
{
    uint32_t _regval = (uint32_t )(mmio::read32(_dev->base, 0x100 + (_i * 16)));
    ((((_os << ("Register ")) << ("isr")) << _i) << ("ISR")) << (":");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

static inline dout_t& xapic_isr_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& xapic_isr_pr(dout_t& _os, __DN(t) *_dev)
{
    int _i;
    for( _i = 0; _i < 8; _i++) {
        xapic_isr_pri(_os, _dev, _i);
    }
    return(_os);
}

/*
 * Register array tmr: TMR
 * Type: xapic.uint32 (primitive type)
 */
static const size_t xapic_tmr_length = 8;
static inline uint32_t xapic_tmr_rawrd(__DN(t) *_dev, int _i) __attribute__ ((always_inline));
static inline uint32_t xapic_tmr_rawrd(__DN(t) *_dev, int _i)
{
    return((uint32_t )(mmio::read32(_dev->base, 0x180 + (_i * 16))));
}

static inline uint32_t xapic_tmr_rd(__DN(t) *_dev, int _i) __attribute__ ((always_inline));
static inline uint32_t xapic_tmr_rd(__DN(t) *_dev, int _i)
{
    return((uint32_t )(mmio::read32(_dev->base, 0x180 + (_i * 16))));
}

static inline void xapic_tmr_rawwr(__DN(t) *_dev, int _i, uint32_t _regval) __attribute__ ((always_inline));
static inline void xapic_tmr_rawwr(__DN(t) *_dev, int _i, uint32_t _regval)
{
    mmio::write32(_dev->base, 0x180 + (_i * 16), _regval);
}

// Register tmr is not writeable
static inline dout_t& xapic_tmr_pri(dout_t& _os, __DN(t) *_dev, int _i) __attribute__ ((always_inline));
static inline dout_t& xapic_tmr_pri(dout_t& _os, __DN(t) *_dev, int _i)
{
    uint32_t _regval = (uint32_t )(mmio::read32(_dev->base, 0x180 + (_i * 16)));
    ((((_os << ("Register ")) << ("tmr")) << _i) << ("TMR")) << (":");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

static inline dout_t& xapic_tmr_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& xapic_tmr_pr(dout_t& _os, __DN(t) *_dev)
{
    int _i;
    for( _i = 0; _i < 8; _i++) {
        xapic_tmr_pri(_os, _dev, _i);
    }
    return(_os);
}

/*
 * Register array irr: IRR
 * Type: xapic.uint32 (primitive type)
 */
static const size_t xapic_irr_length = 8;
static inline uint32_t xapic_irr_rawrd(__DN(t) *_dev, int _i) __attribute__ ((always_inline));
static inline uint32_t xapic_irr_rawrd(__DN(t) *_dev, int _i)
{
    return((uint32_t )(mmio::read32(_dev->base, 0x200 + (_i * 16))));
}

static inline uint32_t xapic_irr_rd(__DN(t) *_dev, int _i) __attribute__ ((always_inline));
static inline uint32_t xapic_irr_rd(__DN(t) *_dev, int _i)
{
    return((uint32_t )(mmio::read32(_dev->base, 0x200 + (_i * 16))));
}

static inline void xapic_irr_rawwr(__DN(t) *_dev, int _i, uint32_t _regval) __attribute__ ((always_inline));
static inline void xapic_irr_rawwr(__DN(t) *_dev, int _i, uint32_t _regval)
{
    mmio::write32(_dev->base, 0x200 + (_i * 16), _regval);
}

// Register irr is not writeable
static inline dout_t& xapic_irr_pri(dout_t& _os, __DN(t) *_dev, int _i) __attribute__ ((always_inline));
static inline dout_t& xapic_irr_pri(dout_t& _os, __DN(t) *_dev, int _i)
{
    uint32_t _regval = (uint32_t )(mmio::read32(_dev->base, 0x200 + (_i * 16)));
    ((((_os << ("Register ")) << ("irr")) << _i) << ("IRR")) << (":");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

static inline dout_t& xapic_irr_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& xapic_irr_pr(dout_t& _os, __DN(t) *_dev)
{
    int _i;
    for( _i = 0; _i < 8; _i++) {
        xapic_irr_pri(_os, _dev, _i);
    }
    return(_os);
}

/*
 * Register eoi: End Of Interrupt
 * Type: xapic.uint32 (primitive type)
 */
static inline uint32_t xapic_eoi_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint32_t xapic_eoi_rawrd(__DN(t) *_dev)
{
    return((uint32_t )(mmio::read32(_dev->base, 0xb0)));
}

static inline uint32_t xapic_eoi_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint32_t xapic_eoi_rd(__DN(t) *_dev)
{
    return(_dev->eoi_shadow);
}

static inline void xapic_eoi_rawwr(__DN(t) *_dev, uint32_t _regval) __attribute__ ((always_inline));
static inline void xapic_eoi_rawwr(__DN(t) *_dev, uint32_t _regval)
{
    mmio::write32(_dev->base, 0xb0, _regval);
}

static inline void xapic_eoi_wr(__DN(t) *_dev, uint32_t _regval) __attribute__ ((always_inline));
static inline void xapic_eoi_wr(__DN(t) *_dev, uint32_t _regval)
{
    // No MB0 or RSVD fields present
    // No MB1 fields present
    // No pre-read of register required
    mmio::write32(_dev->base, 0xb0, _regval);
}

static inline dout_t& xapic_eoi_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& xapic_eoi_pr(dout_t& _os, __DN(t) *_dev)
{
    uint32_t _regval = _dev->eoi_shadow;
    _os << ("Register eoi (End Of Interrupt): ");
    ((_os << ("\t")) << _regval) << (" (SHADOW copy)");
    return(_os);
}

/*
 * Register svr: Spurious Interrupt Vector Register
 * Type: xapic.svr (Implicit type of Spurious Interrupt Vector Register register)
 *   vector	(size 8, offset 0, init 0):	RW	Vector
 *   enable	(size 1, offset 8, init 0):	RW	APIC Software Enable/Disable
 *   focus	(size 1, offset 9, init 0):	RW	Focus Processor Checking
 *   _anon10	(size 22, offset 10, init 0):	RSVD	_
 */
static inline xapic_svr_t xapic_svr_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_svr_t xapic_svr_rawrd(__DN(t) *_dev)
{
    return((xapic_svr_t )(mmio::read32(_dev->base, 0xf0)));
}

static inline xapic_svr_t xapic_svr_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_svr_t xapic_svr_rd(__DN(t) *_dev)
{
    return((xapic_svr_t )(mmio::read32(_dev->base, 0xf0)));
}

static inline void xapic_svr_rawwr(__DN(t) *_dev, xapic_svr_t _regval) __attribute__ ((always_inline));
static inline void xapic_svr_rawwr(__DN(t) *_dev, xapic_svr_t _regval)
{
    mmio::write32(_dev->base, 0xf0, _regval);
}

static inline void xapic_svr_wr(__DN(t) *_dev, xapic_svr_t _regval) __attribute__ ((always_inline));
static inline void xapic_svr_wr(__DN(t) *_dev, xapic_svr_t _regval)
{
    _regval = (_regval & 0x3ff);
    // No MB1 fields present
    _regval = (_regval | (0xfffffc00 & ((xapic_svr_t )(mmio::read32(_dev->base, 0xf0)))));
    mmio::write32(_dev->base, 0xf0, _regval);
}

static inline dout_t& xapic_svr_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& xapic_svr_pr(dout_t& _os, __DN(t) *_dev)
{
    xapic_svr_t _regval = (xapic_svr_t )(mmio::read32(_dev->base, 0xf0));
    _os << ("Register svr (Spurious Interrupt Vector Register): ");
    _os << ("\n");
    ((_os << (" vector =\t")) << xapic_svr_vector_extract(_regval)) << ("\t(Vector)\n");
    ((_os << (" enable =\t")) << xapic_svr_enable_extract(_regval)) << ("\t(APIC Software Enable/Disable)\n");
    ((_os << (" focus =\t")) << xapic_svr_focus_extract(_regval)) << ("\t(Focus Processor Checking)\n");
    // _anon10 is anonymous
    return(_os);
}

static inline uint8_t xapic_svr_vector_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_svr_vector_rdf(__DN(t) *_dev)
{
    xapic_svr_t _regval = (xapic_svr_t )(mmio::read32(_dev->base, 0xf0));
    return(xapic_svr_vector_extract(_regval));
}

static inline uint8_t xapic_svr_enable_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_svr_enable_rdf(__DN(t) *_dev)
{
    xapic_svr_t _regval = (xapic_svr_t )(mmio::read32(_dev->base, 0xf0));
    return(xapic_svr_enable_extract(_regval));
}

static inline uint8_t xapic_svr_focus_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_svr_focus_rdf(__DN(t) *_dev)
{
    xapic_svr_t _regval = (xapic_svr_t )(mmio::read32(_dev->base, 0xf0));
    return(xapic_svr_focus_extract(_regval));
}

static inline void xapic_svr_vector_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_svr_vector_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xapic_svr_t _regval = (xapic_svr_t )(0xff & (((xapic_svr_t )(_fieldval)) << 0));
    _regval = (_regval | (0xffffff00 & ((xapic_svr_t )(mmio::read32(_dev->base, 0xf0)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0xf0, _regval);
    // No shadow register to write to
}

static inline void xapic_svr_enable_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_svr_enable_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xapic_svr_t _regval = (xapic_svr_t )(0x100 & (((xapic_svr_t )(_fieldval)) << 8));
    _regval = (_regval | (0xfffffeff & ((xapic_svr_t )(mmio::read32(_dev->base, 0xf0)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0xf0, _regval);
    // No shadow register to write to
}

static inline void xapic_svr_focus_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_svr_focus_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xapic_svr_t _regval = (xapic_svr_t )(0x200 & (((xapic_svr_t )(_fieldval)) << 9));
    _regval = (_regval | (0xfffffdff & ((xapic_svr_t )(mmio::read32(_dev->base, 0xf0)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0xf0, _regval);
    // No shadow register to write to
}

/*
 * Register eafr: Extended APIC feature
 * Type: xapic.eafr (Implicit type of Extended APIC feature register)
 *   inc	(size 1, offset 0, init 0):	RO	Interrupt enable register capable
 *   snic	(size 1, offset 1, init 0):	RO	Specific EOI capable
 *   xaidc	(size 1, offset 2, init 0):	RO	Extended APIC ID capability
 *   _anon3	(size 13, offset 3, init 0):	MBZ	_
 *   xlc	(size 8, offset 16, init 0):	RO	Extended LVT count
 *   _anon24	(size 8, offset 24, init 0):	MBZ	_
 */
static inline xapic_eafr_t xapic_eafr_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_eafr_t xapic_eafr_rawrd(__DN(t) *_dev)
{
    return((xapic_eafr_t )(mmio::read32(_dev->base, 0x400)));
}

static inline xapic_eafr_t xapic_eafr_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_eafr_t xapic_eafr_rd(__DN(t) *_dev)
{
    return((xapic_eafr_t )(mmio::read32(_dev->base, 0x400)));
}

static inline void xapic_eafr_rawwr(__DN(t) *_dev, xapic_eafr_t _regval) __attribute__ ((always_inline));
static inline void xapic_eafr_rawwr(__DN(t) *_dev, xapic_eafr_t _regval)
{
    mmio::write32(_dev->base, 0x400, _regval);
}

// Register eafr is not writeable
static inline dout_t& xapic_eafr_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& xapic_eafr_pr(dout_t& _os, __DN(t) *_dev)
{
    xapic_eafr_t _regval = (xapic_eafr_t )(mmio::read32(_dev->base, 0x400));
    _os << ("Register eafr (Extended APIC feature): ");
    _os << ("\n");
    ((_os << (" inc =\t")) << xapic_eafr_inc_extract(_regval)) << ("\t(Interrupt enable register capable)\n");
    ((_os << (" snic =\t")) << xapic_eafr_snic_extract(_regval)) << ("\t(Specific EOI capable)\n");
    ((_os << (" xaidc =\t")) << xapic_eafr_xaidc_extract(_regval)) << ("\t(Extended APIC ID capability)\n");
    // _anon3 is anonymous
    ((_os << (" xlc =\t")) << xapic_eafr_xlc_extract(_regval)) << ("\t(Extended LVT count)\n");
    // _anon24 is anonymous
    return(_os);
}

static inline uint8_t xapic_eafr_inc_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_eafr_inc_rdf(__DN(t) *_dev)
{
    xapic_eafr_t _regval = (xapic_eafr_t )(mmio::read32(_dev->base, 0x400));
    return(xapic_eafr_inc_extract(_regval));
}

static inline uint8_t xapic_eafr_snic_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_eafr_snic_rdf(__DN(t) *_dev)
{
    xapic_eafr_t _regval = (xapic_eafr_t )(mmio::read32(_dev->base, 0x400));
    return(xapic_eafr_snic_extract(_regval));
}

static inline uint8_t xapic_eafr_xaidc_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_eafr_xaidc_rdf(__DN(t) *_dev)
{
    xapic_eafr_t _regval = (xapic_eafr_t )(mmio::read32(_dev->base, 0x400));
    return(xapic_eafr_xaidc_extract(_regval));
}

static inline uint8_t xapic_eafr_xlc_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_eafr_xlc_rdf(__DN(t) *_dev)
{
    xapic_eafr_t _regval = (xapic_eafr_t )(mmio::read32(_dev->base, 0x400));
    return(xapic_eafr_xlc_extract(_regval));
}

/*
 * Register eacr: Extended APIC control
 * Type: xapic.eacr (Implicit type of Extended APIC control register)
 *   iern	(size 1, offset 0, init 0):	RW	Enable interrupt enable registers
 *   sn	(size 1, offset 1, init 0):	RW	Enable SEOI generation
 *   xaidn	(size 1, offset 2, init 0):	RW	Extended APIC ID enable
 *   _anon3	(size 29, offset 3, init 0):	RSVD	_
 */
static inline xapic_eacr_t xapic_eacr_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_eacr_t xapic_eacr_rawrd(__DN(t) *_dev)
{
    return((xapic_eacr_t )(mmio::read32(_dev->base, 0x410)));
}

static inline xapic_eacr_t xapic_eacr_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_eacr_t xapic_eacr_rd(__DN(t) *_dev)
{
    return((xapic_eacr_t )(mmio::read32(_dev->base, 0x410)));
}

static inline void xapic_eacr_rawwr(__DN(t) *_dev, xapic_eacr_t _regval) __attribute__ ((always_inline));
static inline void xapic_eacr_rawwr(__DN(t) *_dev, xapic_eacr_t _regval)
{
    mmio::write32(_dev->base, 0x410, _regval);
}

static inline void xapic_eacr_wr(__DN(t) *_dev, xapic_eacr_t _regval) __attribute__ ((always_inline));
static inline void xapic_eacr_wr(__DN(t) *_dev, xapic_eacr_t _regval)
{
    _regval = (_regval & 0x7);
    // No MB1 fields present
    _regval = (_regval | (0xfffffff8 & ((xapic_eacr_t )(mmio::read32(_dev->base, 0x410)))));
    mmio::write32(_dev->base, 0x410, _regval);
}

static inline dout_t& xapic_eacr_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& xapic_eacr_pr(dout_t& _os, __DN(t) *_dev)
{
    xapic_eacr_t _regval = (xapic_eacr_t )(mmio::read32(_dev->base, 0x410));
    _os << ("Register eacr (Extended APIC control): ");
    _os << ("\n");
    ((_os << (" iern =\t")) << xapic_eacr_iern_extract(_regval)) << ("\t(Enable interrupt enable registers)\n");
    ((_os << (" sn =\t")) << xapic_eacr_sn_extract(_regval)) << ("\t(Enable SEOI generation)\n");
    ((_os << (" xaidn =\t")) << xapic_eacr_xaidn_extract(_regval)) << ("\t(Extended APIC ID enable)\n");
    // _anon3 is anonymous
    return(_os);
}

static inline uint8_t xapic_eacr_iern_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_eacr_iern_rdf(__DN(t) *_dev)
{
    xapic_eacr_t _regval = (xapic_eacr_t )(mmio::read32(_dev->base, 0x410));
    return(xapic_eacr_iern_extract(_regval));
}

static inline uint8_t xapic_eacr_sn_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_eacr_sn_rdf(__DN(t) *_dev)
{
    xapic_eacr_t _regval = (xapic_eacr_t )(mmio::read32(_dev->base, 0x410));
    return(xapic_eacr_sn_extract(_regval));
}

static inline uint8_t xapic_eacr_xaidn_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_eacr_xaidn_rdf(__DN(t) *_dev)
{
    xapic_eacr_t _regval = (xapic_eacr_t )(mmio::read32(_dev->base, 0x410));
    return(xapic_eacr_xaidn_extract(_regval));
}

static inline void xapic_eacr_iern_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_eacr_iern_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xapic_eacr_t _regval = (xapic_eacr_t )(0x1 & (((xapic_eacr_t )(_fieldval)) << 0));
    _regval = (_regval | (0xfffffffe & ((xapic_eacr_t )(mmio::read32(_dev->base, 0x410)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x410, _regval);
    // No shadow register to write to
}

static inline void xapic_eacr_sn_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_eacr_sn_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xapic_eacr_t _regval = (xapic_eacr_t )(0x2 & (((xapic_eacr_t )(_fieldval)) << 1));
    _regval = (_regval | (0xfffffffd & ((xapic_eacr_t )(mmio::read32(_dev->base, 0x410)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x410, _regval);
    // No shadow register to write to
}

static inline void xapic_eacr_xaidn_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_eacr_xaidn_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xapic_eacr_t _regval = (xapic_eacr_t )(0x4 & (((xapic_eacr_t )(_fieldval)) << 2));
    _regval = (_regval | (0xfffffffb & ((xapic_eacr_t )(mmio::read32(_dev->base, 0x410)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mmio::write32(_dev->base, 0x410, _regval);
    // No shadow register to write to
}

/*
 * Register seoi: Specific end-of-interrupt
 * Type: xapic.seoi (Implicit type of Specific end-of-interrupt register)
 *   vector	(size 8, offset 0, init 0):	WO	Vector
 *   _anon8	(size 24, offset 8, init 0):	MBZ	_
 */
static inline xapic_seoi_t xapic_seoi_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_seoi_t xapic_seoi_rawrd(__DN(t) *_dev)
{
    return((xapic_seoi_t )(mmio::read32(_dev->base, 0x420)));
}

static inline xapic_seoi_t xapic_seoi_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xapic_seoi_t xapic_seoi_rd(__DN(t) *_dev)
{
    return(_dev->seoi_shadow);
}

static inline void xapic_seoi_rawwr(__DN(t) *_dev, xapic_seoi_t _regval) __attribute__ ((always_inline));
static inline void xapic_seoi_rawwr(__DN(t) *_dev, xapic_seoi_t _regval)
{
    mmio::write32(_dev->base, 0x420, _regval);
}

static inline void xapic_seoi_wr(__DN(t) *_dev, xapic_seoi_t _regval) __attribute__ ((always_inline));
static inline void xapic_seoi_wr(__DN(t) *_dev, xapic_seoi_t _regval)
{
    _regval = (_regval & 0xff);
    // No MB1 fields present
    // No pre-read of register required
    mmio::write32(_dev->base, 0x420, _regval);
}

static inline dout_t& xapic_seoi_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& xapic_seoi_pr(dout_t& _os, __DN(t) *_dev)
{
    xapic_seoi_t _regval = _dev->seoi_shadow;
    _os << ("Register seoi (Specific end-of-interrupt): ");
    _os << ("\n");
    ((_os << (" vector =\t")) << xapic_seoi_vector_extract(_regval)) << ("\t(Vector)\n");
    // _anon8 is anonymous
    return(_os);
}

static inline uint8_t xapic_seoi_vector_rd_shadow(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xapic_seoi_vector_rd_shadow(__DN(t) *_dev)
{
    return(xapic_seoi_vector_extract(_dev->seoi_shadow));
}

static inline void xapic_seoi_vector_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xapic_seoi_vector_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xapic_seoi_t _regval = (xapic_seoi_t )(0xff & (((xapic_seoi_t )(_fieldval)) << 0));
    // No pre-read of register required
    // No read of register shadow required
    _regval = (_regval & 0xff);
    // No MB1 fields present
    mmio::write32(_dev->base, 0x420, _regval);
    _dev->seoi_shadow = _regval;
}

/*
 * Register array ier: IER
 * Type: xapic.uint32 (primitive type)
 */
static const size_t xapic_ier_length = 8;
static inline uint32_t xapic_ier_rawrd(__DN(t) *_dev, int _i) __attribute__ ((always_inline));
static inline uint32_t xapic_ier_rawrd(__DN(t) *_dev, int _i)
{
    return((uint32_t )(mmio::read32(_dev->base, 0x480 + (_i * 16))));
}

static inline uint32_t xapic_ier_rd(__DN(t) *_dev, int _i) __attribute__ ((always_inline));
static inline uint32_t xapic_ier_rd(__DN(t) *_dev, int _i)
{
    return((uint32_t )(mmio::read32(_dev->base, 0x480 + (_i * 16))));
}

static inline void xapic_ier_rawwr(__DN(t) *_dev, int _i, uint32_t _regval) __attribute__ ((always_inline));
static inline void xapic_ier_rawwr(__DN(t) *_dev, int _i, uint32_t _regval)
{
    mmio::write32(_dev->base, 0x480 + (_i * 16), _regval);
}

// Register ier is not writeable
static inline dout_t& xapic_ier_pri(dout_t& _os, __DN(t) *_dev, int _i) __attribute__ ((always_inline));
static inline dout_t& xapic_ier_pri(dout_t& _os, __DN(t) *_dev, int _i)
{
    uint32_t _regval = (uint32_t )(mmio::read32(_dev->base, 0x480 + (_i * 16)));
    ((((_os << ("Register ")) << ("ier")) << _i) << ("IER")) << (":");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

static inline dout_t& xapic_ier_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& xapic_ier_pr(dout_t& _os, __DN(t) *_dev)
{
    int _i;
    for( _i = 0; _i < 8; _i++) {
        xapic_ier_pri(_os, _dev, _i);
    }
    return(_os);
}

static inline dout_t& operator<<(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, __DN(t) *_dev)
{
    _os << ("-------------------------\n");
    _os << ("Dump of device xapic (Local APIC):\n");
    xapic_id_pr(_os, _dev);
    xapic_version_pr(_os, _dev);
    xapic_lvt_timer_pr(_os, _dev);
    xapic_lvt_lint0_pr(_os, _dev);
    xapic_lvt_lint1_pr(_os, _dev);
    xapic_lvt_err_pr(_os, _dev);
    xapic_lvt_perf_cnt_pr(_os, _dev);
    xapic_lvt_thermal_pr(_os, _dev);
    xapic_esr_pr(_os, _dev);
    xapic_dcr_pr(_os, _dev);
    xapic_init_count_pr(_os, _dev);
    xapic_cur_count_pr(_os, _dev);
    xapic_icr_lo_pr(_os, _dev);
    xapic_icr_hi_pr(_os, _dev);
    xapic_ldr_pr(_os, _dev);
    xapic_dfr_pr(_os, _dev);
    xapic_apr_pr(_os, _dev);
    xapic_tpr_pr(_os, _dev);
    xapic_ppr_pr(_os, _dev);
    xapic_isr_pr(_os, _dev);
    xapic_tmr_pr(_os, _dev);
    xapic_irr_pr(_os, _dev);
    xapic_eoi_pr(_os, _dev);
    xapic_svr_pr(_os, _dev);
    xapic_eafr_pr(_os, _dev);
    xapic_eacr_pr(_os, _dev);
    xapic_seoi_pr(_os, _dev);
    xapic_ier_pr(_os, _dev);
    _os << ("End of dump of device xapic\n");
    _os << ("-------------------------\n");
    return(_os);
}

#undef __DN
