#pragma once
/*
 * Device Definition: PCI Type 0 Configuration
 * 
 * Automatically Generated from Spec.
 * Using a modified mackerel.
 * 
 * DO NOT EDIT!
 */
#include "util/debug.h"
#include "util/io.h"
#undef __DN
#define __DN(x) pci_hdr0 ## _ ## x
/*
 * Constants defn: pci_hdr0.classcode (Class code)
 *  - no width specified
 */
HOH_STRONG_TYPEDEF( uint8_t , pci_hdr0_classcode_t);
#define pci_hdr0_old ((pci_hdr0_classcode_t)0x0)
#define pci_hdr0_mass ((pci_hdr0_classcode_t)0x1)
#define pci_hdr0_network ((pci_hdr0_classcode_t)0x2)
#define pci_hdr0_display ((pci_hdr0_classcode_t)0x3)
#define pci_hdr0_multimedia ((pci_hdr0_classcode_t)0x4)
#define pci_hdr0_memory ((pci_hdr0_classcode_t)0x5)
#define pci_hdr0_bridge ((pci_hdr0_classcode_t)0x6)
#define pci_hdr0_simple ((pci_hdr0_classcode_t)0x7)
#define pci_hdr0_base ((pci_hdr0_classcode_t)0x8)
#define pci_hdr0_input ((pci_hdr0_classcode_t)0x9)
#define pci_hdr0_docking ((pci_hdr0_classcode_t)0xa)
#define pci_hdr0_processor ((pci_hdr0_classcode_t)0xb)
#define pci_hdr0_serial ((pci_hdr0_classcode_t)0xc)
#define pci_hdr0_wireless ((pci_hdr0_classcode_t)0xd)
#define pci_hdr0_intelligent ((pci_hdr0_classcode_t)0xe)
#define pci_hdr0_satellite ((pci_hdr0_classcode_t)0xf)
#define pci_hdr0_crypt ((pci_hdr0_classcode_t)0x10)
#define pci_hdr0_acquisition ((pci_hdr0_classcode_t)0x11)
#define pci_hdr0_misc ((pci_hdr0_classcode_t)0xff)

static inline const char* pci_hdr0_classcode_describe(pci_hdr0_classcode_t _e) __attribute__ ((always_inline));
static inline const char* pci_hdr0_classcode_describe(pci_hdr0_classcode_t _e)
{
    switch ((uint8_t )(_e)) {
    case (uint8_t )(0x0):
        return("old: Pre-2.0 PCI device");
    case (uint8_t )(0x1):
        return("mass: Mass storage controller");
    case (uint8_t )(0x2):
        return("network: Network controller");
    case (uint8_t )(0x3):
        return("display: Display controller");
    case (uint8_t )(0x4):
        return("multimedia: Multimedia device");
    case (uint8_t )(0x5):
        return("memory: Memory controller");
    case (uint8_t )(0x6):
        return("bridge: Bridge device");
    case (uint8_t )(0x7):
        return("simple: Simple communications controller");
    case (uint8_t )(0x8):
        return("base: Base system peripherals");
    case (uint8_t )(0x9):
        return("input: Input device");
    case (uint8_t )(0xa):
        return("docking: Docking station");
    case (uint8_t )(0xb):
        return("processor: Processor");
    case (uint8_t )(0xc):
        return("serial: Serial bus controller");
    case (uint8_t )(0xd):
        return("wireless: Wireless controller");
    case (uint8_t )(0xe):
        return("intelligent: Intelligent I/O controller");
    case (uint8_t )(0xf):
        return("satellite: Satellite communications controller");
    case (uint8_t )(0x10):
        return("crypt: Encryption/decryption device");
    case (uint8_t )(0x11):
        return("acquisition: Data acquisition controller");
    case (uint8_t )(0xff):
        return("misc: Miscellaneous");
    default:
        return(NULL);
    }
}

static inline dout_t& operator<<(dout_t& _os, pci_hdr0_classcode_t _e) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, pci_hdr0_classcode_t _e)
{
    const char* d = pci_hdr0_classcode_describe(_e);
    if (d) {
        return(_os << d);
    } else {
        return((((_os << ("Unknown constant:")) << ("pci_hdr0_classcode_t")) << ("value:")) << ((uint64_t )(_e)));
    }
}

/*
 * Constants defn: pci_hdr0.hdrtype (Configuration header types)
 *  - no width specified
 */
HOH_STRONG_TYPEDEF( uint8_t , pci_hdr0_hdrtype_t);
#define pci_hdr0_nonbridge ((pci_hdr0_hdrtype_t)0x0)
#define pci_hdr0_pci2pci ((pci_hdr0_hdrtype_t)0x1)
#define pci_hdr0_cardbus ((pci_hdr0_hdrtype_t)0x2)

static inline const char* pci_hdr0_hdrtype_describe(pci_hdr0_hdrtype_t _e) __attribute__ ((always_inline));
static inline const char* pci_hdr0_hdrtype_describe(pci_hdr0_hdrtype_t _e)
{
    switch ((uint8_t )(_e)) {
    case (uint8_t )(0x0):
        return("nonbridge: non-bridge function");
    case (uint8_t )(0x1):
        return("pci2pci: PCI-to-PCI bridge");
    case (uint8_t )(0x2):
        return("cardbus: CardBus bridge");
    default:
        return(NULL);
    }
}

static inline dout_t& operator<<(dout_t& _os, pci_hdr0_hdrtype_t _e) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, pci_hdr0_hdrtype_t _e)
{
    const char* d = pci_hdr0_hdrtype_describe(_e);
    if (d) {
        return(_os << d);
    } else {
        return((((_os << ("Unknown constant:")) << ("pci_hdr0_hdrtype_t")) << ("value:")) << ((uint64_t )(_e)));
    }
}

/*
 * Constants defn: pci_hdr0.bardecoder (BAR decoder type)
 *  - no width specified
 */
HOH_STRONG_TYPEDEF( uint8_t , pci_hdr0_bardecoder_t);
#define pci_hdr0_bar_32bit ((pci_hdr0_bardecoder_t)0x0)
#define pci_hdr0_bar_64bit ((pci_hdr0_bardecoder_t)0x2)

static inline const char* pci_hdr0_bardecoder_describe(pci_hdr0_bardecoder_t _e) __attribute__ ((always_inline));
static inline const char* pci_hdr0_bardecoder_describe(pci_hdr0_bardecoder_t _e)
{
    switch ((uint8_t )(_e)) {
    case (uint8_t )(0x0):
        return("bar_32bit: 32-bit decoder");
    case (uint8_t )(0x2):
        return("bar_64bit: 64-bit decoder");
    default:
        return(NULL);
    }
}

static inline dout_t& operator<<(dout_t& _os, pci_hdr0_bardecoder_t _e) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, pci_hdr0_bardecoder_t _e)
{
    const char* d = pci_hdr0_bardecoder_describe(_e);
    if (d) {
        return(_os << d);
    } else {
        return((((_os << ("Unknown constant:")) << ("pci_hdr0_bardecoder_t")) << ("value:")) << ((uint64_t )(_e)));
    }
}

/*
 * Register type: pci_hdr0_command_t
 * Description: Implicit type of Command register
 * Fields:
 *   io_space	(size 1, offset 0, init 0):	RW	I/O space enable
 *   mem_space	(size 1, offset 1, init 0):	RW	Memory space enable
 *   master	(size 1, offset 2, init 0):	RW	Bus master
 *   special	(size 1, offset 3, init 0):	RO	Special cycles
 *   mem_inval	(size 1, offset 4, init 0):	RO	Memory write and invalidate enable
 *   vga_snoop	(size 1, offset 5, init 0):	RO	VGA palette snoop enable
 *   parity	(size 1, offset 6, init 0):	RW	Parity error response
 *   stepping	(size 1, offset 7, init 0):	RO	IDSEL stepping/wait cycle control
 *   serr	(size 1, offset 8, init 0):	RW	SERR# enable
 *   back2back	(size 1, offset 9, init 0):	RO	Fast back-to-back enable
 *   int_dis	(size 1, offset 10, init 0):	RW	Interrupt disable
 *   _anon11	(size 5, offset 11, init 0):	RSVD	_
 */
HOH_STRONG_TYPEDEF( uint16_t , pci_hdr0_command_t);
#define pci_hdr0_command_default (pci_hdr0_command_t )(0x0)
static inline uint8_t pci_hdr0_command_io_space_extract(pci_hdr0_command_t _regval) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_command_io_space_extract(pci_hdr0_command_t _regval)
{
    return((uint8_t )((_regval & 0x1) >> 0));
}

static inline pci_hdr0_command_t pci_hdr0_command_io_space_insert(pci_hdr0_command_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_command_t pci_hdr0_command_io_space_insert(pci_hdr0_command_t _regval, uint8_t _fieldval)
{
    return((pci_hdr0_command_t )((_regval & 0xfffe) | (0x1 & (((pci_hdr0_command_t )(_fieldval)) << 0))));
}

static inline uint8_t pci_hdr0_command_mem_space_extract(pci_hdr0_command_t _regval) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_command_mem_space_extract(pci_hdr0_command_t _regval)
{
    return((uint8_t )((_regval & 0x2) >> 1));
}

static inline pci_hdr0_command_t pci_hdr0_command_mem_space_insert(pci_hdr0_command_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_command_t pci_hdr0_command_mem_space_insert(pci_hdr0_command_t _regval, uint8_t _fieldval)
{
    return((pci_hdr0_command_t )((_regval & 0xfffd) | (0x2 & (((pci_hdr0_command_t )(_fieldval)) << 1))));
}

static inline uint8_t pci_hdr0_command_master_extract(pci_hdr0_command_t _regval) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_command_master_extract(pci_hdr0_command_t _regval)
{
    return((uint8_t )((_regval & 0x4) >> 2));
}

static inline pci_hdr0_command_t pci_hdr0_command_master_insert(pci_hdr0_command_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_command_t pci_hdr0_command_master_insert(pci_hdr0_command_t _regval, uint8_t _fieldval)
{
    return((pci_hdr0_command_t )((_regval & 0xfffb) | (0x4 & (((pci_hdr0_command_t )(_fieldval)) << 2))));
}

static inline uint8_t pci_hdr0_command_special_extract(pci_hdr0_command_t _regval) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_command_special_extract(pci_hdr0_command_t _regval)
{
    return((uint8_t )((_regval & 0x8) >> 3));
}

static inline pci_hdr0_command_t pci_hdr0_command_special_insert(pci_hdr0_command_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_command_t pci_hdr0_command_special_insert(pci_hdr0_command_t _regval, uint8_t _fieldval)
{
    return((pci_hdr0_command_t )((_regval & 0xfff7) | (0x8 & (((pci_hdr0_command_t )(_fieldval)) << 3))));
}

static inline uint8_t pci_hdr0_command_mem_inval_extract(pci_hdr0_command_t _regval) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_command_mem_inval_extract(pci_hdr0_command_t _regval)
{
    return((uint8_t )((_regval & 0x10) >> 4));
}

static inline pci_hdr0_command_t pci_hdr0_command_mem_inval_insert(pci_hdr0_command_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_command_t pci_hdr0_command_mem_inval_insert(pci_hdr0_command_t _regval, uint8_t _fieldval)
{
    return((pci_hdr0_command_t )((_regval & 0xffef) | (0x10 & (((pci_hdr0_command_t )(_fieldval)) << 4))));
}

static inline uint8_t pci_hdr0_command_vga_snoop_extract(pci_hdr0_command_t _regval) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_command_vga_snoop_extract(pci_hdr0_command_t _regval)
{
    return((uint8_t )((_regval & 0x20) >> 5));
}

static inline pci_hdr0_command_t pci_hdr0_command_vga_snoop_insert(pci_hdr0_command_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_command_t pci_hdr0_command_vga_snoop_insert(pci_hdr0_command_t _regval, uint8_t _fieldval)
{
    return((pci_hdr0_command_t )((_regval & 0xffdf) | (0x20 & (((pci_hdr0_command_t )(_fieldval)) << 5))));
}

static inline uint8_t pci_hdr0_command_parity_extract(pci_hdr0_command_t _regval) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_command_parity_extract(pci_hdr0_command_t _regval)
{
    return((uint8_t )((_regval & 0x40) >> 6));
}

static inline pci_hdr0_command_t pci_hdr0_command_parity_insert(pci_hdr0_command_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_command_t pci_hdr0_command_parity_insert(pci_hdr0_command_t _regval, uint8_t _fieldval)
{
    return((pci_hdr0_command_t )((_regval & 0xffbf) | (0x40 & (((pci_hdr0_command_t )(_fieldval)) << 6))));
}

static inline uint8_t pci_hdr0_command_stepping_extract(pci_hdr0_command_t _regval) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_command_stepping_extract(pci_hdr0_command_t _regval)
{
    return((uint8_t )((_regval & 0x80) >> 7));
}

static inline pci_hdr0_command_t pci_hdr0_command_stepping_insert(pci_hdr0_command_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_command_t pci_hdr0_command_stepping_insert(pci_hdr0_command_t _regval, uint8_t _fieldval)
{
    return((pci_hdr0_command_t )((_regval & 0xff7f) | (0x80 & (((pci_hdr0_command_t )(_fieldval)) << 7))));
}

static inline uint8_t pci_hdr0_command_serr_extract(pci_hdr0_command_t _regval) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_command_serr_extract(pci_hdr0_command_t _regval)
{
    return((uint8_t )((_regval & 0x100) >> 8));
}

static inline pci_hdr0_command_t pci_hdr0_command_serr_insert(pci_hdr0_command_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_command_t pci_hdr0_command_serr_insert(pci_hdr0_command_t _regval, uint8_t _fieldval)
{
    return((pci_hdr0_command_t )((_regval & 0xfeff) | (0x100 & (((pci_hdr0_command_t )(_fieldval)) << 8))));
}

static inline uint8_t pci_hdr0_command_back2back_extract(pci_hdr0_command_t _regval) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_command_back2back_extract(pci_hdr0_command_t _regval)
{
    return((uint8_t )((_regval & 0x200) >> 9));
}

static inline pci_hdr0_command_t pci_hdr0_command_back2back_insert(pci_hdr0_command_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_command_t pci_hdr0_command_back2back_insert(pci_hdr0_command_t _regval, uint8_t _fieldval)
{
    return((pci_hdr0_command_t )((_regval & 0xfdff) | (0x200 & (((pci_hdr0_command_t )(_fieldval)) << 9))));
}

static inline uint8_t pci_hdr0_command_int_dis_extract(pci_hdr0_command_t _regval) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_command_int_dis_extract(pci_hdr0_command_t _regval)
{
    return((uint8_t )((_regval & 0x400) >> 10));
}

static inline pci_hdr0_command_t pci_hdr0_command_int_dis_insert(pci_hdr0_command_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_command_t pci_hdr0_command_int_dis_insert(pci_hdr0_command_t _regval, uint8_t _fieldval)
{
    return((pci_hdr0_command_t )((_regval & 0xfbff) | (0x400 & (((pci_hdr0_command_t )(_fieldval)) << 10))));
}

static inline dout_t& operator<<(dout_t& _os, pci_hdr0_command_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, pci_hdr0_command_t _regval)
{
    ((_os << (" io_space =\t")) << pci_hdr0_command_io_space_extract(_regval)) << ("\t(I/O space enable)\n");
    ((_os << (" mem_space =\t")) << pci_hdr0_command_mem_space_extract(_regval)) << ("\t(Memory space enable)\n");
    ((_os << (" master =\t")) << pci_hdr0_command_master_extract(_regval)) << ("\t(Bus master)\n");
    ((_os << (" special =\t")) << pci_hdr0_command_special_extract(_regval)) << ("\t(Special cycles)\n");
    ((_os << (" mem_inval =\t")) << pci_hdr0_command_mem_inval_extract(_regval)) << ("\t(Memory write and invalidate enable)\n");
    ((_os << (" vga_snoop =\t")) << pci_hdr0_command_vga_snoop_extract(_regval)) << ("\t(VGA palette snoop enable)\n");
    ((_os << (" parity =\t")) << pci_hdr0_command_parity_extract(_regval)) << ("\t(Parity error response)\n");
    ((_os << (" stepping =\t")) << pci_hdr0_command_stepping_extract(_regval)) << ("\t(IDSEL stepping/wait cycle control)\n");
    ((_os << (" serr =\t")) << pci_hdr0_command_serr_extract(_regval)) << ("\t(SERR# enable)\n");
    ((_os << (" back2back =\t")) << pci_hdr0_command_back2back_extract(_regval)) << ("\t(Fast back-to-back enable)\n");
    ((_os << (" int_dis =\t")) << pci_hdr0_command_int_dis_extract(_regval)) << ("\t(Interrupt disable)\n");
    return(_os);
}

/*
 * Register type: pci_hdr0_status_t
 * Description: Implicit type of Status register
 * Fields:
 *   _anon0	(size 3, offset 0, init 0):	RSVD	_
 *   intstat	(size 1, offset 3, init 0):	RO	Interrupt status
 *   caplist	(size 1, offset 4, init 0):	RO	Capabilities list
 *   m66	(size 1, offset 5, init 0):	RO	66MHz capable
 *   udf	(size 1, offset 6, init 0):	RO	UDF supported
 *   back2back	(size 1, offset 7, init 0):	RO	Fast Back-to-Back enable
 *   md_parity	(size 1, offset 8, init 0):	RWC	Master data parity error
 *   devsel	(size 2, offset 9, init 0):	RO	DEVSEL timing
 *   sig_t_abrt	(size 1, offset 11, init 0):	RWC	Signalled target abort
 *   rx_t_abrt	(size 1, offset 12, init 0):	RWC	Received target abort
 *   rx_m_abrt	(size 1, offset 13, init 0):	RWC	Received master abort
 *   system_err	(size 1, offset 14, init 0):	RWC	Signalled system error
 *   parity_err	(size 1, offset 15, init 0):	RWC	Detected parity error
 */
HOH_STRONG_TYPEDEF( uint16_t , pci_hdr0_status_t);
#define pci_hdr0_status_default (pci_hdr0_status_t )(0x0)
static inline uint8_t pci_hdr0_status_intstat_extract(pci_hdr0_status_t _regval) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_status_intstat_extract(pci_hdr0_status_t _regval)
{
    return((uint8_t )((_regval & 0x8) >> 3));
}

static inline pci_hdr0_status_t pci_hdr0_status_intstat_insert(pci_hdr0_status_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_status_t pci_hdr0_status_intstat_insert(pci_hdr0_status_t _regval, uint8_t _fieldval)
{
    return((pci_hdr0_status_t )((_regval & 0xfff7) | (0x8 & (((pci_hdr0_status_t )(_fieldval)) << 3))));
}

static inline uint8_t pci_hdr0_status_caplist_extract(pci_hdr0_status_t _regval) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_status_caplist_extract(pci_hdr0_status_t _regval)
{
    return((uint8_t )((_regval & 0x10) >> 4));
}

static inline pci_hdr0_status_t pci_hdr0_status_caplist_insert(pci_hdr0_status_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_status_t pci_hdr0_status_caplist_insert(pci_hdr0_status_t _regval, uint8_t _fieldval)
{
    return((pci_hdr0_status_t )((_regval & 0xffef) | (0x10 & (((pci_hdr0_status_t )(_fieldval)) << 4))));
}

static inline uint8_t pci_hdr0_status_m66_extract(pci_hdr0_status_t _regval) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_status_m66_extract(pci_hdr0_status_t _regval)
{
    return((uint8_t )((_regval & 0x20) >> 5));
}

static inline pci_hdr0_status_t pci_hdr0_status_m66_insert(pci_hdr0_status_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_status_t pci_hdr0_status_m66_insert(pci_hdr0_status_t _regval, uint8_t _fieldval)
{
    return((pci_hdr0_status_t )((_regval & 0xffdf) | (0x20 & (((pci_hdr0_status_t )(_fieldval)) << 5))));
}

static inline uint8_t pci_hdr0_status_udf_extract(pci_hdr0_status_t _regval) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_status_udf_extract(pci_hdr0_status_t _regval)
{
    return((uint8_t )((_regval & 0x40) >> 6));
}

static inline pci_hdr0_status_t pci_hdr0_status_udf_insert(pci_hdr0_status_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_status_t pci_hdr0_status_udf_insert(pci_hdr0_status_t _regval, uint8_t _fieldval)
{
    return((pci_hdr0_status_t )((_regval & 0xffbf) | (0x40 & (((pci_hdr0_status_t )(_fieldval)) << 6))));
}

static inline uint8_t pci_hdr0_status_back2back_extract(pci_hdr0_status_t _regval) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_status_back2back_extract(pci_hdr0_status_t _regval)
{
    return((uint8_t )((_regval & 0x80) >> 7));
}

static inline pci_hdr0_status_t pci_hdr0_status_back2back_insert(pci_hdr0_status_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_status_t pci_hdr0_status_back2back_insert(pci_hdr0_status_t _regval, uint8_t _fieldval)
{
    return((pci_hdr0_status_t )((_regval & 0xff7f) | (0x80 & (((pci_hdr0_status_t )(_fieldval)) << 7))));
}

static inline uint8_t pci_hdr0_status_md_parity_extract(pci_hdr0_status_t _regval) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_status_md_parity_extract(pci_hdr0_status_t _regval)
{
    return((uint8_t )((_regval & 0x100) >> 8));
}

static inline pci_hdr0_status_t pci_hdr0_status_md_parity_insert(pci_hdr0_status_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_status_t pci_hdr0_status_md_parity_insert(pci_hdr0_status_t _regval, uint8_t _fieldval)
{
    return((pci_hdr0_status_t )((_regval & 0xfeff) | (0x100 & (((pci_hdr0_status_t )(_fieldval)) << 8))));
}

static inline uint8_t pci_hdr0_status_devsel_extract(pci_hdr0_status_t _regval) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_status_devsel_extract(pci_hdr0_status_t _regval)
{
    return((uint8_t )((_regval & 0x600) >> 9));
}

static inline pci_hdr0_status_t pci_hdr0_status_devsel_insert(pci_hdr0_status_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_status_t pci_hdr0_status_devsel_insert(pci_hdr0_status_t _regval, uint8_t _fieldval)
{
    return((pci_hdr0_status_t )((_regval & 0xf9ff) | (0x600 & (((pci_hdr0_status_t )(_fieldval)) << 9))));
}

static inline uint8_t pci_hdr0_status_sig_t_abrt_extract(pci_hdr0_status_t _regval) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_status_sig_t_abrt_extract(pci_hdr0_status_t _regval)
{
    return((uint8_t )((_regval & 0x800) >> 11));
}

static inline pci_hdr0_status_t pci_hdr0_status_sig_t_abrt_insert(pci_hdr0_status_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_status_t pci_hdr0_status_sig_t_abrt_insert(pci_hdr0_status_t _regval, uint8_t _fieldval)
{
    return((pci_hdr0_status_t )((_regval & 0xf7ff) | (0x800 & (((pci_hdr0_status_t )(_fieldval)) << 11))));
}

static inline uint8_t pci_hdr0_status_rx_t_abrt_extract(pci_hdr0_status_t _regval) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_status_rx_t_abrt_extract(pci_hdr0_status_t _regval)
{
    return((uint8_t )((_regval & 0x1000) >> 12));
}

static inline pci_hdr0_status_t pci_hdr0_status_rx_t_abrt_insert(pci_hdr0_status_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_status_t pci_hdr0_status_rx_t_abrt_insert(pci_hdr0_status_t _regval, uint8_t _fieldval)
{
    return((pci_hdr0_status_t )((_regval & 0xefff) | (0x1000 & (((pci_hdr0_status_t )(_fieldval)) << 12))));
}

static inline uint8_t pci_hdr0_status_rx_m_abrt_extract(pci_hdr0_status_t _regval) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_status_rx_m_abrt_extract(pci_hdr0_status_t _regval)
{
    return((uint8_t )((_regval & 0x2000) >> 13));
}

static inline pci_hdr0_status_t pci_hdr0_status_rx_m_abrt_insert(pci_hdr0_status_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_status_t pci_hdr0_status_rx_m_abrt_insert(pci_hdr0_status_t _regval, uint8_t _fieldval)
{
    return((pci_hdr0_status_t )((_regval & 0xdfff) | (0x2000 & (((pci_hdr0_status_t )(_fieldval)) << 13))));
}

static inline uint8_t pci_hdr0_status_system_err_extract(pci_hdr0_status_t _regval) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_status_system_err_extract(pci_hdr0_status_t _regval)
{
    return((uint8_t )((_regval & 0x4000) >> 14));
}

static inline pci_hdr0_status_t pci_hdr0_status_system_err_insert(pci_hdr0_status_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_status_t pci_hdr0_status_system_err_insert(pci_hdr0_status_t _regval, uint8_t _fieldval)
{
    return((pci_hdr0_status_t )((_regval & 0xbfff) | (0x4000 & (((pci_hdr0_status_t )(_fieldval)) << 14))));
}

static inline uint8_t pci_hdr0_status_parity_err_extract(pci_hdr0_status_t _regval) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_status_parity_err_extract(pci_hdr0_status_t _regval)
{
    return((uint8_t )((_regval & 0x8000) >> 15));
}

static inline pci_hdr0_status_t pci_hdr0_status_parity_err_insert(pci_hdr0_status_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_status_t pci_hdr0_status_parity_err_insert(pci_hdr0_status_t _regval, uint8_t _fieldval)
{
    return((pci_hdr0_status_t )((_regval & 0x7fff) | (0x8000 & (((pci_hdr0_status_t )(_fieldval)) << 15))));
}

static inline dout_t& operator<<(dout_t& _os, pci_hdr0_status_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, pci_hdr0_status_t _regval)
{
    ((_os << (" intstat =\t")) << pci_hdr0_status_intstat_extract(_regval)) << ("\t(Interrupt status)\n");
    ((_os << (" caplist =\t")) << pci_hdr0_status_caplist_extract(_regval)) << ("\t(Capabilities list)\n");
    ((_os << (" m66 =\t")) << pci_hdr0_status_m66_extract(_regval)) << ("\t(66MHz capable)\n");
    ((_os << (" udf =\t")) << pci_hdr0_status_udf_extract(_regval)) << ("\t(UDF supported)\n");
    ((_os << (" back2back =\t")) << pci_hdr0_status_back2back_extract(_regval)) << ("\t(Fast Back-to-Back enable)\n");
    ((_os << (" md_parity =\t")) << pci_hdr0_status_md_parity_extract(_regval)) << ("\t(Master data parity error)\n");
    ((_os << (" devsel =\t")) << pci_hdr0_status_devsel_extract(_regval)) << ("\t(DEVSEL timing)\n");
    ((_os << (" sig_t_abrt =\t")) << pci_hdr0_status_sig_t_abrt_extract(_regval)) << ("\t(Signalled target abort)\n");
    ((_os << (" rx_t_abrt =\t")) << pci_hdr0_status_rx_t_abrt_extract(_regval)) << ("\t(Received target abort)\n");
    ((_os << (" rx_m_abrt =\t")) << pci_hdr0_status_rx_m_abrt_extract(_regval)) << ("\t(Received master abort)\n");
    ((_os << (" system_err =\t")) << pci_hdr0_status_system_err_extract(_regval)) << ("\t(Signalled system error)\n");
    ((_os << (" parity_err =\t")) << pci_hdr0_status_parity_err_extract(_regval)) << ("\t(Detected parity error)\n");
    return(_os);
}

/*
 * Register type: pci_hdr0_class_code_t
 * Description: Implicit type of Class code register
 * Fields:
 *   _anon0	(size 8, offset 0, init 0):	RSVD	_
 *   prog_if	(size 8, offset 8, init 0):	RO	Programming intf
 *   subclss	(size 8, offset 16, init 0):	RO	Subclass code
 *   clss	(size 8, offset 24, init 0):	RO	Class code
 */
HOH_STRONG_TYPEDEF( uint32_t , pci_hdr0_class_code_t);
#define pci_hdr0_class_code_default (pci_hdr0_class_code_t )(0x0)
static inline uint8_t pci_hdr0_class_code_prog_if_extract(pci_hdr0_class_code_t _regval) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_class_code_prog_if_extract(pci_hdr0_class_code_t _regval)
{
    return((uint8_t )((_regval & 0xff00) >> 8));
}

static inline pci_hdr0_class_code_t pci_hdr0_class_code_prog_if_insert(pci_hdr0_class_code_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_class_code_t pci_hdr0_class_code_prog_if_insert(pci_hdr0_class_code_t _regval, uint8_t _fieldval)
{
    return((pci_hdr0_class_code_t )((_regval & 0xffff00ff) | (0xff00 & (((pci_hdr0_class_code_t )(_fieldval)) << 8))));
}

static inline uint8_t pci_hdr0_class_code_subclss_extract(pci_hdr0_class_code_t _regval) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_class_code_subclss_extract(pci_hdr0_class_code_t _regval)
{
    return((uint8_t )((_regval & 0xff0000) >> 16));
}

static inline pci_hdr0_class_code_t pci_hdr0_class_code_subclss_insert(pci_hdr0_class_code_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_class_code_t pci_hdr0_class_code_subclss_insert(pci_hdr0_class_code_t _regval, uint8_t _fieldval)
{
    return((pci_hdr0_class_code_t )((_regval & 0xff00ffff) | (0xff0000 & (((pci_hdr0_class_code_t )(_fieldval)) << 16))));
}

static inline pci_hdr0_classcode_t pci_hdr0_class_code_clss_extract(pci_hdr0_class_code_t _regval) __attribute__ ((always_inline));
static inline pci_hdr0_classcode_t pci_hdr0_class_code_clss_extract(pci_hdr0_class_code_t _regval)
{
    return((pci_hdr0_classcode_t )((_regval & 0xff000000) >> 24));
}

static inline pci_hdr0_class_code_t pci_hdr0_class_code_clss_insert(pci_hdr0_class_code_t _regval, pci_hdr0_classcode_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_class_code_t pci_hdr0_class_code_clss_insert(pci_hdr0_class_code_t _regval, pci_hdr0_classcode_t _fieldval)
{
    return((pci_hdr0_class_code_t )((_regval & 0xffffff) | (0xff000000 & (((pci_hdr0_class_code_t )(_fieldval)) << 24))));
}

static inline dout_t& operator<<(dout_t& _os, pci_hdr0_class_code_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, pci_hdr0_class_code_t _regval)
{
    ((_os << (" prog_if =\t")) << pci_hdr0_class_code_prog_if_extract(_regval)) << ("\t(Programming intf)\n");
    ((_os << (" subclss =\t")) << pci_hdr0_class_code_subclss_extract(_regval)) << ("\t(Subclass code)\n");
    ((_os << (" clss =\t")) << pci_hdr0_class_code_clss_extract(_regval)) << ("\t(Class code)\n");
    return(_os);
}

/*
 * Register type: pci_hdr0_hdr_type_t
 * Description: Implicit type of Header type register
 * Fields:
 *   fmt	(size 7, offset 0, init 0):	RO	Configuration header format
 *   multi	(size 1, offset 7, init 0):	RO	Multifunction device
 */
HOH_STRONG_TYPEDEF( uint8_t , pci_hdr0_hdr_type_t);
#define pci_hdr0_hdr_type_default (pci_hdr0_hdr_type_t )(0x0)
static inline pci_hdr0_hdrtype_t pci_hdr0_hdr_type_fmt_extract(pci_hdr0_hdr_type_t _regval) __attribute__ ((always_inline));
static inline pci_hdr0_hdrtype_t pci_hdr0_hdr_type_fmt_extract(pci_hdr0_hdr_type_t _regval)
{
    return((pci_hdr0_hdrtype_t )((_regval & 0x7f) >> 0));
}

static inline pci_hdr0_hdr_type_t pci_hdr0_hdr_type_fmt_insert(pci_hdr0_hdr_type_t _regval, pci_hdr0_hdrtype_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_hdr_type_t pci_hdr0_hdr_type_fmt_insert(pci_hdr0_hdr_type_t _regval, pci_hdr0_hdrtype_t _fieldval)
{
    return((pci_hdr0_hdr_type_t )((_regval & 0x80) | (0x7f & (((pci_hdr0_hdr_type_t )(_fieldval)) << 0))));
}

static inline uint8_t pci_hdr0_hdr_type_multi_extract(pci_hdr0_hdr_type_t _regval) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_hdr_type_multi_extract(pci_hdr0_hdr_type_t _regval)
{
    return((uint8_t )((_regval & 0x80) >> 7));
}

static inline pci_hdr0_hdr_type_t pci_hdr0_hdr_type_multi_insert(pci_hdr0_hdr_type_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_hdr_type_t pci_hdr0_hdr_type_multi_insert(pci_hdr0_hdr_type_t _regval, uint8_t _fieldval)
{
    return((pci_hdr0_hdr_type_t )((_regval & 0x7f) | (0x80 & (((pci_hdr0_hdr_type_t )(_fieldval)) << 7))));
}

static inline dout_t& operator<<(dout_t& _os, pci_hdr0_hdr_type_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, pci_hdr0_hdr_type_t _regval)
{
    ((_os << (" fmt =\t")) << pci_hdr0_hdr_type_fmt_extract(_regval)) << ("\t(Configuration header format)\n");
    ((_os << (" multi =\t")) << pci_hdr0_hdr_type_multi_extract(_regval)) << ("\t(Multifunction device)\n");
    return(_os);
}

/*
 * Register type: pci_hdr0_bist_t
 * Description: Implicit type of Built-in self-test register
 * Fields:
 *   comp	(size 4, offset 0, init 0):	RO	Completion code
 *   _anon4	(size 2, offset 4, init 0):	RSVD	_
 *   start	(size 1, offset 6, init 0):	RW	Start BIST
 *   cap	(size 1, offset 7, init 0):	RO	BIST capable
 */
HOH_STRONG_TYPEDEF( uint8_t , pci_hdr0_bist_t);
#define pci_hdr0_bist_default (pci_hdr0_bist_t )(0x0)
static inline uint8_t pci_hdr0_bist_comp_extract(pci_hdr0_bist_t _regval) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_bist_comp_extract(pci_hdr0_bist_t _regval)
{
    return((uint8_t )((_regval & 0xf) >> 0));
}

static inline pci_hdr0_bist_t pci_hdr0_bist_comp_insert(pci_hdr0_bist_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_bist_t pci_hdr0_bist_comp_insert(pci_hdr0_bist_t _regval, uint8_t _fieldval)
{
    return((pci_hdr0_bist_t )((_regval & 0xf0) | (0xf & (((pci_hdr0_bist_t )(_fieldval)) << 0))));
}

static inline uint8_t pci_hdr0_bist_start_extract(pci_hdr0_bist_t _regval) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_bist_start_extract(pci_hdr0_bist_t _regval)
{
    return((uint8_t )((_regval & 0x40) >> 6));
}

static inline pci_hdr0_bist_t pci_hdr0_bist_start_insert(pci_hdr0_bist_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_bist_t pci_hdr0_bist_start_insert(pci_hdr0_bist_t _regval, uint8_t _fieldval)
{
    return((pci_hdr0_bist_t )((_regval & 0xbf) | (0x40 & (((pci_hdr0_bist_t )(_fieldval)) << 6))));
}

static inline uint8_t pci_hdr0_bist_cap_extract(pci_hdr0_bist_t _regval) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_bist_cap_extract(pci_hdr0_bist_t _regval)
{
    return((uint8_t )((_regval & 0x80) >> 7));
}

static inline pci_hdr0_bist_t pci_hdr0_bist_cap_insert(pci_hdr0_bist_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_bist_t pci_hdr0_bist_cap_insert(pci_hdr0_bist_t _regval, uint8_t _fieldval)
{
    return((pci_hdr0_bist_t )((_regval & 0x7f) | (0x80 & (((pci_hdr0_bist_t )(_fieldval)) << 7))));
}

static inline dout_t& operator<<(dout_t& _os, pci_hdr0_bist_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, pci_hdr0_bist_t _regval)
{
    ((_os << (" comp =\t")) << pci_hdr0_bist_comp_extract(_regval)) << ("\t(Completion code)\n");
    ((_os << (" start =\t")) << pci_hdr0_bist_start_extract(_regval)) << ("\t(Start BIST)\n");
    ((_os << (" cap =\t")) << pci_hdr0_bist_cap_extract(_regval)) << ("\t(BIST capable)\n");
    return(_os);
}

/*
 * Register type: pci_hdr0_bar32_t
 * Description: 32-bit memory base address
 * Fields:
 *   space	(size 1, offset 0, init 0):	RO	Memory space indicator
 *   tpe	(size 2, offset 1, init 0):	RO	Memory decoder type
 *   prefetch	(size 1, offset 3, init 0):	RO	Prefetchable
 *   _anon4	(size 3, offset 4, init 0):	RSVD	_
 *   base	(size 25, offset 7, init 0):	RW	Base address
 */
HOH_STRONG_TYPEDEF( uint32_t , pci_hdr0_bar32_t);
#define pci_hdr0_bar32_default (pci_hdr0_bar32_t )(0x0)
static inline uint8_t pci_hdr0_bar32_space_extract(pci_hdr0_bar32_t _regval) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_bar32_space_extract(pci_hdr0_bar32_t _regval)
{
    return((uint8_t )((_regval & 0x1) >> 0));
}

static inline pci_hdr0_bar32_t pci_hdr0_bar32_space_insert(pci_hdr0_bar32_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_bar32_t pci_hdr0_bar32_space_insert(pci_hdr0_bar32_t _regval, uint8_t _fieldval)
{
    return((pci_hdr0_bar32_t )((_regval & 0xfffffffe) | (0x1 & (((pci_hdr0_bar32_t )(_fieldval)) << 0))));
}

static inline pci_hdr0_bardecoder_t pci_hdr0_bar32_tpe_extract(pci_hdr0_bar32_t _regval) __attribute__ ((always_inline));
static inline pci_hdr0_bardecoder_t pci_hdr0_bar32_tpe_extract(pci_hdr0_bar32_t _regval)
{
    return((pci_hdr0_bardecoder_t )((_regval & 0x6) >> 1));
}

static inline pci_hdr0_bar32_t pci_hdr0_bar32_tpe_insert(pci_hdr0_bar32_t _regval, pci_hdr0_bardecoder_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_bar32_t pci_hdr0_bar32_tpe_insert(pci_hdr0_bar32_t _regval, pci_hdr0_bardecoder_t _fieldval)
{
    return((pci_hdr0_bar32_t )((_regval & 0xfffffff9) | (0x6 & (((pci_hdr0_bar32_t )(_fieldval)) << 1))));
}

static inline uint8_t pci_hdr0_bar32_prefetch_extract(pci_hdr0_bar32_t _regval) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_bar32_prefetch_extract(pci_hdr0_bar32_t _regval)
{
    return((uint8_t )((_regval & 0x8) >> 3));
}

static inline pci_hdr0_bar32_t pci_hdr0_bar32_prefetch_insert(pci_hdr0_bar32_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_bar32_t pci_hdr0_bar32_prefetch_insert(pci_hdr0_bar32_t _regval, uint8_t _fieldval)
{
    return((pci_hdr0_bar32_t )((_regval & 0xfffffff7) | (0x8 & (((pci_hdr0_bar32_t )(_fieldval)) << 3))));
}

static inline uint32_t pci_hdr0_bar32_base_extract(pci_hdr0_bar32_t _regval) __attribute__ ((always_inline));
static inline uint32_t pci_hdr0_bar32_base_extract(pci_hdr0_bar32_t _regval)
{
    return((uint32_t )((_regval & 0xffffff80) >> 7));
}

static inline pci_hdr0_bar32_t pci_hdr0_bar32_base_insert(pci_hdr0_bar32_t _regval, uint32_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_bar32_t pci_hdr0_bar32_base_insert(pci_hdr0_bar32_t _regval, uint32_t _fieldval)
{
    return((pci_hdr0_bar32_t )((_regval & 0x7f) | (0xffffff80 & (((pci_hdr0_bar32_t )(_fieldval)) << 7))));
}

static inline dout_t& operator<<(dout_t& _os, pci_hdr0_bar32_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, pci_hdr0_bar32_t _regval)
{
    ((_os << (" space =\t")) << pci_hdr0_bar32_space_extract(_regval)) << ("\t(Memory space indicator)\n");
    ((_os << (" tpe =\t")) << pci_hdr0_bar32_tpe_extract(_regval)) << ("\t(Memory decoder type)\n");
    ((_os << (" prefetch =\t")) << pci_hdr0_bar32_prefetch_extract(_regval)) << ("\t(Prefetchable)\n");
    ((_os << (" base =\t")) << pci_hdr0_bar32_base_extract(_regval)) << ("\t(Base address)\n");
    return(_os);
}

/*
 * Register type: pci_hdr0_bar64_t
 * Description: 64-bit memory base address
 * Fields:
 *   space	(size 1, offset 0, init 0):	RO	Memory space indicator
 *   tpe	(size 2, offset 1, init 0):	RO	Memory decoder type
 *   prefetch	(size 1, offset 3, init 0):	RO	Prefetchable
 *   _anon4	(size 3, offset 4, init 0):	RSVD	_
 *   base	(size 57, offset 7, init 0):	RW	Base address
 */
HOH_STRONG_TYPEDEF( uint64_t , pci_hdr0_bar64_t);
#define pci_hdr0_bar64_default (pci_hdr0_bar64_t )(0x0)
static inline uint8_t pci_hdr0_bar64_space_extract(pci_hdr0_bar64_t _regval) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_bar64_space_extract(pci_hdr0_bar64_t _regval)
{
    return((uint8_t )((_regval & 0x1) >> 0));
}

static inline pci_hdr0_bar64_t pci_hdr0_bar64_space_insert(pci_hdr0_bar64_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_bar64_t pci_hdr0_bar64_space_insert(pci_hdr0_bar64_t _regval, uint8_t _fieldval)
{
    return((pci_hdr0_bar64_t )((_regval & 0xfffffffffffffffe) | (0x1 & (((pci_hdr0_bar64_t )(_fieldval)) << 0))));
}

static inline pci_hdr0_bardecoder_t pci_hdr0_bar64_tpe_extract(pci_hdr0_bar64_t _regval) __attribute__ ((always_inline));
static inline pci_hdr0_bardecoder_t pci_hdr0_bar64_tpe_extract(pci_hdr0_bar64_t _regval)
{
    return((pci_hdr0_bardecoder_t )((_regval & 0x6) >> 1));
}

static inline pci_hdr0_bar64_t pci_hdr0_bar64_tpe_insert(pci_hdr0_bar64_t _regval, pci_hdr0_bardecoder_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_bar64_t pci_hdr0_bar64_tpe_insert(pci_hdr0_bar64_t _regval, pci_hdr0_bardecoder_t _fieldval)
{
    return((pci_hdr0_bar64_t )((_regval & 0xfffffffffffffff9) | (0x6 & (((pci_hdr0_bar64_t )(_fieldval)) << 1))));
}

static inline uint8_t pci_hdr0_bar64_prefetch_extract(pci_hdr0_bar64_t _regval) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_bar64_prefetch_extract(pci_hdr0_bar64_t _regval)
{
    return((uint8_t )((_regval & 0x8) >> 3));
}

static inline pci_hdr0_bar64_t pci_hdr0_bar64_prefetch_insert(pci_hdr0_bar64_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_bar64_t pci_hdr0_bar64_prefetch_insert(pci_hdr0_bar64_t _regval, uint8_t _fieldval)
{
    return((pci_hdr0_bar64_t )((_regval & 0xfffffffffffffff7) | (0x8 & (((pci_hdr0_bar64_t )(_fieldval)) << 3))));
}

static inline uint64_t pci_hdr0_bar64_base_extract(pci_hdr0_bar64_t _regval) __attribute__ ((always_inline));
static inline uint64_t pci_hdr0_bar64_base_extract(pci_hdr0_bar64_t _regval)
{
    return((uint64_t )((_regval & 0xffffffffffffff80) >> 7));
}

static inline pci_hdr0_bar64_t pci_hdr0_bar64_base_insert(pci_hdr0_bar64_t _regval, uint64_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_bar64_t pci_hdr0_bar64_base_insert(pci_hdr0_bar64_t _regval, uint64_t _fieldval)
{
    return((pci_hdr0_bar64_t )((_regval & 0x7f) | (0xffffffffffffff80 & (((pci_hdr0_bar64_t )(_fieldval)) << 7))));
}

static inline dout_t& operator<<(dout_t& _os, pci_hdr0_bar64_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, pci_hdr0_bar64_t _regval)
{
    ((_os << (" space =\t")) << pci_hdr0_bar64_space_extract(_regval)) << ("\t(Memory space indicator)\n");
    ((_os << (" tpe =\t")) << pci_hdr0_bar64_tpe_extract(_regval)) << ("\t(Memory decoder type)\n");
    ((_os << (" prefetch =\t")) << pci_hdr0_bar64_prefetch_extract(_regval)) << ("\t(Prefetchable)\n");
    ((_os << (" base =\t")) << pci_hdr0_bar64_base_extract(_regval)) << ("\t(Base address)\n");
    return(_os);
}

/*
 * Register type: pci_hdr0_bario_t
 * Description: I/O space base address
 * Fields:
 *   space	(size 1, offset 0, init 0):	RO	I/O space indicator
 *   _anon1	(size 1, offset 1, init 0):	RSVD	_
 *   base	(size 30, offset 2, init 0):	RW	Base address
 */
HOH_STRONG_TYPEDEF( uint32_t , pci_hdr0_bario_t);
#define pci_hdr0_bario_default (pci_hdr0_bario_t )(0x0)
static inline uint8_t pci_hdr0_bario_space_extract(pci_hdr0_bario_t _regval) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_bario_space_extract(pci_hdr0_bario_t _regval)
{
    return((uint8_t )((_regval & 0x1) >> 0));
}

static inline pci_hdr0_bario_t pci_hdr0_bario_space_insert(pci_hdr0_bario_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_bario_t pci_hdr0_bario_space_insert(pci_hdr0_bario_t _regval, uint8_t _fieldval)
{
    return((pci_hdr0_bario_t )((_regval & 0xfffffffe) | (0x1 & (((pci_hdr0_bario_t )(_fieldval)) << 0))));
}

static inline uint32_t pci_hdr0_bario_base_extract(pci_hdr0_bario_t _regval) __attribute__ ((always_inline));
static inline uint32_t pci_hdr0_bario_base_extract(pci_hdr0_bario_t _regval)
{
    return((uint32_t )((_regval & 0xfffffffc) >> 2));
}

static inline pci_hdr0_bario_t pci_hdr0_bario_base_insert(pci_hdr0_bario_t _regval, uint32_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_bario_t pci_hdr0_bario_base_insert(pci_hdr0_bario_t _regval, uint32_t _fieldval)
{
    return((pci_hdr0_bario_t )((_regval & 0x3) | (0xfffffffc & (((pci_hdr0_bario_t )(_fieldval)) << 2))));
}

static inline dout_t& operator<<(dout_t& _os, pci_hdr0_bario_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, pci_hdr0_bario_t _regval)
{
    ((_os << (" space =\t")) << pci_hdr0_bario_space_extract(_regval)) << ("\t(I/O space indicator)\n");
    ((_os << (" base =\t")) << pci_hdr0_bario_base_extract(_regval)) << ("\t(Base address)\n");
    return(_os);
}

/*
 * Register type: pci_hdr0_rom_base_t
 * Description: Implicit type of Expansion ROM base addr register
 * Fields:
 *   enable	(size 1, offset 0, init 0):	RW	ROM address decoder enable
 *   _anon1	(size 10, offset 1, init 0):	RSVD	_
 *   base	(size 21, offset 11, init 0):	RW	ROM Base address high bits
 */
HOH_STRONG_TYPEDEF( uint32_t , pci_hdr0_rom_base_t);
#define pci_hdr0_rom_base_default (pci_hdr0_rom_base_t )(0x0)
static inline uint8_t pci_hdr0_rom_base_enable_extract(pci_hdr0_rom_base_t _regval) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_rom_base_enable_extract(pci_hdr0_rom_base_t _regval)
{
    return((uint8_t )((_regval & 0x1) >> 0));
}

static inline pci_hdr0_rom_base_t pci_hdr0_rom_base_enable_insert(pci_hdr0_rom_base_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_rom_base_t pci_hdr0_rom_base_enable_insert(pci_hdr0_rom_base_t _regval, uint8_t _fieldval)
{
    return((pci_hdr0_rom_base_t )((_regval & 0xfffffffe) | (0x1 & (((pci_hdr0_rom_base_t )(_fieldval)) << 0))));
}

static inline uint32_t pci_hdr0_rom_base_base_extract(pci_hdr0_rom_base_t _regval) __attribute__ ((always_inline));
static inline uint32_t pci_hdr0_rom_base_base_extract(pci_hdr0_rom_base_t _regval)
{
    return((uint32_t )((_regval & 0xfffff800) >> 11));
}

static inline pci_hdr0_rom_base_t pci_hdr0_rom_base_base_insert(pci_hdr0_rom_base_t _regval, uint32_t _fieldval) __attribute__ ((always_inline));
static inline pci_hdr0_rom_base_t pci_hdr0_rom_base_base_insert(pci_hdr0_rom_base_t _regval, uint32_t _fieldval)
{
    return((pci_hdr0_rom_base_t )((_regval & 0x7ff) | (0xfffff800 & (((pci_hdr0_rom_base_t )(_fieldval)) << 11))));
}

static inline dout_t& operator<<(dout_t& _os, pci_hdr0_rom_base_t _regval) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, pci_hdr0_rom_base_t _regval)
{
    ((_os << (" enable =\t")) << pci_hdr0_rom_base_enable_extract(_regval)) << ("\t(ROM address decoder enable)\n");
    ((_os << (" base =\t")) << pci_hdr0_rom_base_base_extract(_regval)) << ("\t(ROM Base address high bits)\n");
    return(_os);
}

/*
 * Device representation structure
 */
struct __DN(t) {
    pci_t base;
};

/*
 * Initial register values (currently 0)
 */
enum pci_hdr0_initials {
    pci_hdr0_vendor_id_initial = 0x0,
    pci_hdr0_device_id_initial = 0x0,
    pci_hdr0_command_initial = 0x0,
    pci_hdr0_status_initial = 0x0,
    pci_hdr0_rev_id_initial = 0x0,
    pci_hdr0_class_code_initial = 0x0,
    pci_hdr0_cache_sz_initial = 0x0,
    pci_hdr0_latency_initial = 0x0,
    pci_hdr0_hdr_type_initial = 0x0,
    pci_hdr0_bist_initial = 0x0,
    pci_hdr0_bars_initial = 0x0,
    pci_hdr0_cardbus_initial = 0x0,
    pci_hdr0_subsys_vid_initial = 0x0,
    pci_hdr0_subsys_id_initial = 0x0,
    pci_hdr0_rom_base_initial = 0x0,
    pci_hdr0_cap_ptr_initial = 0x0,
    pci_hdr0_int_line_initial = 0x0,
    pci_hdr0_int_pin_initial = 0x0,
    pci_hdr0_min_gnt_initial = 0x0,
    pci_hdr0_max_lat_initial = 0x0
};

/*
 * Device Initialization function
 */
static inline void pci_hdr0_initialize(__DN(t) *_dev, pci_t base) __attribute__ ((always_inline));
static inline void pci_hdr0_initialize(__DN(t) *_dev, pci_t base)
{
    _dev->base = base;
}

/*
 * No user-defined spaces
 */
/*
 * Register vendor_id: Vendor ID
 * Type: pci_hdr0.uint16 (primitive type)
 */
static inline uint16_t pci_hdr0_vendor_id_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint16_t pci_hdr0_vendor_id_rawrd(__DN(t) *_dev)
{
    return((uint16_t )(pci::read16(_dev->base, 0x0)));
}

static inline uint16_t pci_hdr0_vendor_id_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint16_t pci_hdr0_vendor_id_rd(__DN(t) *_dev)
{
    return((uint16_t )(pci::read16(_dev->base, 0x0)));
}

static inline void pci_hdr0_vendor_id_rawwr(__DN(t) *_dev, uint16_t _regval) __attribute__ ((always_inline));
static inline void pci_hdr0_vendor_id_rawwr(__DN(t) *_dev, uint16_t _regval)
{
    pci::write16(_dev->base, 0x0, _regval);
}

// Register vendor_id is not writeable
static inline dout_t& pci_hdr0_vendor_id_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& pci_hdr0_vendor_id_pr(dout_t& _os, __DN(t) *_dev)
{
    uint16_t _regval = (uint16_t )(pci::read16(_dev->base, 0x0));
    _os << ("Register vendor_id (Vendor ID): ");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

/*
 * Register device_id: Device ID
 * Type: pci_hdr0.uint16 (primitive type)
 */
static inline uint16_t pci_hdr0_device_id_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint16_t pci_hdr0_device_id_rawrd(__DN(t) *_dev)
{
    return((uint16_t )(pci::read16(_dev->base, 0x2)));
}

static inline uint16_t pci_hdr0_device_id_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint16_t pci_hdr0_device_id_rd(__DN(t) *_dev)
{
    return((uint16_t )(pci::read16(_dev->base, 0x2)));
}

static inline void pci_hdr0_device_id_rawwr(__DN(t) *_dev, uint16_t _regval) __attribute__ ((always_inline));
static inline void pci_hdr0_device_id_rawwr(__DN(t) *_dev, uint16_t _regval)
{
    pci::write16(_dev->base, 0x2, _regval);
}

// Register device_id is not writeable
static inline dout_t& pci_hdr0_device_id_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& pci_hdr0_device_id_pr(dout_t& _os, __DN(t) *_dev)
{
    uint16_t _regval = (uint16_t )(pci::read16(_dev->base, 0x2));
    _os << ("Register device_id (Device ID): ");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

/*
 * Register command: Command
 * Type: pci_hdr0.command (Implicit type of Command register)
 *   io_space	(size 1, offset 0, init 0):	RW	I/O space enable
 *   mem_space	(size 1, offset 1, init 0):	RW	Memory space enable
 *   master	(size 1, offset 2, init 0):	RW	Bus master
 *   special	(size 1, offset 3, init 0):	RO	Special cycles
 *   mem_inval	(size 1, offset 4, init 0):	RO	Memory write and invalidate enable
 *   vga_snoop	(size 1, offset 5, init 0):	RO	VGA palette snoop enable
 *   parity	(size 1, offset 6, init 0):	RW	Parity error response
 *   stepping	(size 1, offset 7, init 0):	RO	IDSEL stepping/wait cycle control
 *   serr	(size 1, offset 8, init 0):	RW	SERR# enable
 *   back2back	(size 1, offset 9, init 0):	RO	Fast back-to-back enable
 *   int_dis	(size 1, offset 10, init 0):	RW	Interrupt disable
 *   _anon11	(size 5, offset 11, init 0):	RSVD	_
 */
static inline pci_hdr0_command_t pci_hdr0_command_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline pci_hdr0_command_t pci_hdr0_command_rawrd(__DN(t) *_dev)
{
    return((pci_hdr0_command_t )(pci::read16(_dev->base, 0x4)));
}

static inline pci_hdr0_command_t pci_hdr0_command_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline pci_hdr0_command_t pci_hdr0_command_rd(__DN(t) *_dev)
{
    return((pci_hdr0_command_t )(pci::read16(_dev->base, 0x4)));
}

static inline void pci_hdr0_command_rawwr(__DN(t) *_dev, pci_hdr0_command_t _regval) __attribute__ ((always_inline));
static inline void pci_hdr0_command_rawwr(__DN(t) *_dev, pci_hdr0_command_t _regval)
{
    pci::write16(_dev->base, 0x4, _regval);
}

static inline void pci_hdr0_command_wr(__DN(t) *_dev, pci_hdr0_command_t _regval) __attribute__ ((always_inline));
static inline void pci_hdr0_command_wr(__DN(t) *_dev, pci_hdr0_command_t _regval)
{
    _regval = (_regval & 0x7ff);
    // No MB1 fields present
    _regval = (_regval | (0xf800 & ((pci_hdr0_command_t )(pci::read16(_dev->base, 0x4)))));
    pci::write16(_dev->base, 0x4, _regval);
}

static inline dout_t& pci_hdr0_command_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& pci_hdr0_command_pr(dout_t& _os, __DN(t) *_dev)
{
    pci_hdr0_command_t _regval = (pci_hdr0_command_t )(pci::read16(_dev->base, 0x4));
    _os << ("Register command (Command): ");
    _os << ("\n");
    ((_os << (" io_space =\t")) << pci_hdr0_command_io_space_extract(_regval)) << ("\t(I/O space enable)\n");
    ((_os << (" mem_space =\t")) << pci_hdr0_command_mem_space_extract(_regval)) << ("\t(Memory space enable)\n");
    ((_os << (" master =\t")) << pci_hdr0_command_master_extract(_regval)) << ("\t(Bus master)\n");
    ((_os << (" special =\t")) << pci_hdr0_command_special_extract(_regval)) << ("\t(Special cycles)\n");
    ((_os << (" mem_inval =\t")) << pci_hdr0_command_mem_inval_extract(_regval)) << ("\t(Memory write and invalidate enable)\n");
    ((_os << (" vga_snoop =\t")) << pci_hdr0_command_vga_snoop_extract(_regval)) << ("\t(VGA palette snoop enable)\n");
    ((_os << (" parity =\t")) << pci_hdr0_command_parity_extract(_regval)) << ("\t(Parity error response)\n");
    ((_os << (" stepping =\t")) << pci_hdr0_command_stepping_extract(_regval)) << ("\t(IDSEL stepping/wait cycle control)\n");
    ((_os << (" serr =\t")) << pci_hdr0_command_serr_extract(_regval)) << ("\t(SERR# enable)\n");
    ((_os << (" back2back =\t")) << pci_hdr0_command_back2back_extract(_regval)) << ("\t(Fast back-to-back enable)\n");
    ((_os << (" int_dis =\t")) << pci_hdr0_command_int_dis_extract(_regval)) << ("\t(Interrupt disable)\n");
    // _anon11 is anonymous
    return(_os);
}

static inline uint8_t pci_hdr0_command_io_space_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_command_io_space_rdf(__DN(t) *_dev)
{
    pci_hdr0_command_t _regval = (pci_hdr0_command_t )(pci::read16(_dev->base, 0x4));
    return(pci_hdr0_command_io_space_extract(_regval));
}

static inline uint8_t pci_hdr0_command_mem_space_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_command_mem_space_rdf(__DN(t) *_dev)
{
    pci_hdr0_command_t _regval = (pci_hdr0_command_t )(pci::read16(_dev->base, 0x4));
    return(pci_hdr0_command_mem_space_extract(_regval));
}

static inline uint8_t pci_hdr0_command_master_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_command_master_rdf(__DN(t) *_dev)
{
    pci_hdr0_command_t _regval = (pci_hdr0_command_t )(pci::read16(_dev->base, 0x4));
    return(pci_hdr0_command_master_extract(_regval));
}

static inline uint8_t pci_hdr0_command_special_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_command_special_rdf(__DN(t) *_dev)
{
    pci_hdr0_command_t _regval = (pci_hdr0_command_t )(pci::read16(_dev->base, 0x4));
    return(pci_hdr0_command_special_extract(_regval));
}

static inline uint8_t pci_hdr0_command_mem_inval_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_command_mem_inval_rdf(__DN(t) *_dev)
{
    pci_hdr0_command_t _regval = (pci_hdr0_command_t )(pci::read16(_dev->base, 0x4));
    return(pci_hdr0_command_mem_inval_extract(_regval));
}

static inline uint8_t pci_hdr0_command_vga_snoop_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_command_vga_snoop_rdf(__DN(t) *_dev)
{
    pci_hdr0_command_t _regval = (pci_hdr0_command_t )(pci::read16(_dev->base, 0x4));
    return(pci_hdr0_command_vga_snoop_extract(_regval));
}

static inline uint8_t pci_hdr0_command_parity_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_command_parity_rdf(__DN(t) *_dev)
{
    pci_hdr0_command_t _regval = (pci_hdr0_command_t )(pci::read16(_dev->base, 0x4));
    return(pci_hdr0_command_parity_extract(_regval));
}

static inline uint8_t pci_hdr0_command_stepping_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_command_stepping_rdf(__DN(t) *_dev)
{
    pci_hdr0_command_t _regval = (pci_hdr0_command_t )(pci::read16(_dev->base, 0x4));
    return(pci_hdr0_command_stepping_extract(_regval));
}

static inline uint8_t pci_hdr0_command_serr_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_command_serr_rdf(__DN(t) *_dev)
{
    pci_hdr0_command_t _regval = (pci_hdr0_command_t )(pci::read16(_dev->base, 0x4));
    return(pci_hdr0_command_serr_extract(_regval));
}

static inline uint8_t pci_hdr0_command_back2back_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_command_back2back_rdf(__DN(t) *_dev)
{
    pci_hdr0_command_t _regval = (pci_hdr0_command_t )(pci::read16(_dev->base, 0x4));
    return(pci_hdr0_command_back2back_extract(_regval));
}

static inline uint8_t pci_hdr0_command_int_dis_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_command_int_dis_rdf(__DN(t) *_dev)
{
    pci_hdr0_command_t _regval = (pci_hdr0_command_t )(pci::read16(_dev->base, 0x4));
    return(pci_hdr0_command_int_dis_extract(_regval));
}

static inline void pci_hdr0_command_io_space_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void pci_hdr0_command_io_space_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    pci_hdr0_command_t _regval = (pci_hdr0_command_t )(0x1 & (((pci_hdr0_command_t )(_fieldval)) << 0));
    _regval = (_regval | (0xfd46 & ((pci_hdr0_command_t )(pci::read16(_dev->base, 0x4)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    pci::write16(_dev->base, 0x4, _regval);
    // No shadow register to write to
}

static inline void pci_hdr0_command_mem_space_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void pci_hdr0_command_mem_space_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    pci_hdr0_command_t _regval = (pci_hdr0_command_t )(0x2 & (((pci_hdr0_command_t )(_fieldval)) << 1));
    _regval = (_regval | (0xfd45 & ((pci_hdr0_command_t )(pci::read16(_dev->base, 0x4)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    pci::write16(_dev->base, 0x4, _regval);
    // No shadow register to write to
}

static inline void pci_hdr0_command_master_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void pci_hdr0_command_master_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    pci_hdr0_command_t _regval = (pci_hdr0_command_t )(0x4 & (((pci_hdr0_command_t )(_fieldval)) << 2));
    _regval = (_regval | (0xfd43 & ((pci_hdr0_command_t )(pci::read16(_dev->base, 0x4)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    pci::write16(_dev->base, 0x4, _regval);
    // No shadow register to write to
}

static inline void pci_hdr0_command_parity_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void pci_hdr0_command_parity_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    pci_hdr0_command_t _regval = (pci_hdr0_command_t )(0x40 & (((pci_hdr0_command_t )(_fieldval)) << 6));
    _regval = (_regval | (0xfd07 & ((pci_hdr0_command_t )(pci::read16(_dev->base, 0x4)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    pci::write16(_dev->base, 0x4, _regval);
    // No shadow register to write to
}

static inline void pci_hdr0_command_serr_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void pci_hdr0_command_serr_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    pci_hdr0_command_t _regval = (pci_hdr0_command_t )(0x100 & (((pci_hdr0_command_t )(_fieldval)) << 8));
    _regval = (_regval | (0xfc47 & ((pci_hdr0_command_t )(pci::read16(_dev->base, 0x4)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    pci::write16(_dev->base, 0x4, _regval);
    // No shadow register to write to
}

static inline void pci_hdr0_command_int_dis_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void pci_hdr0_command_int_dis_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    pci_hdr0_command_t _regval = (pci_hdr0_command_t )(0x400 & (((pci_hdr0_command_t )(_fieldval)) << 10));
    _regval = (_regval | (0xf947 & ((pci_hdr0_command_t )(pci::read16(_dev->base, 0x4)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    pci::write16(_dev->base, 0x4, _regval);
    // No shadow register to write to
}

/*
 * Register status: Status
 * Type: pci_hdr0.status (Implicit type of Status register)
 *   _anon0	(size 3, offset 0, init 0):	RSVD	_
 *   intstat	(size 1, offset 3, init 0):	RO	Interrupt status
 *   caplist	(size 1, offset 4, init 0):	RO	Capabilities list
 *   m66	(size 1, offset 5, init 0):	RO	66MHz capable
 *   udf	(size 1, offset 6, init 0):	RO	UDF supported
 *   back2back	(size 1, offset 7, init 0):	RO	Fast Back-to-Back enable
 *   md_parity	(size 1, offset 8, init 0):	RWC	Master data parity error
 *   devsel	(size 2, offset 9, init 0):	RO	DEVSEL timing
 *   sig_t_abrt	(size 1, offset 11, init 0):	RWC	Signalled target abort
 *   rx_t_abrt	(size 1, offset 12, init 0):	RWC	Received target abort
 *   rx_m_abrt	(size 1, offset 13, init 0):	RWC	Received master abort
 *   system_err	(size 1, offset 14, init 0):	RWC	Signalled system error
 *   parity_err	(size 1, offset 15, init 0):	RWC	Detected parity error
 */
static inline pci_hdr0_status_t pci_hdr0_status_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline pci_hdr0_status_t pci_hdr0_status_rawrd(__DN(t) *_dev)
{
    return((pci_hdr0_status_t )(pci::read16(_dev->base, 0x6)));
}

static inline pci_hdr0_status_t pci_hdr0_status_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline pci_hdr0_status_t pci_hdr0_status_rd(__DN(t) *_dev)
{
    return((pci_hdr0_status_t )(pci::read16(_dev->base, 0x6)));
}

static inline void pci_hdr0_status_rawwr(__DN(t) *_dev, pci_hdr0_status_t _regval) __attribute__ ((always_inline));
static inline void pci_hdr0_status_rawwr(__DN(t) *_dev, pci_hdr0_status_t _regval)
{
    pci::write16(_dev->base, 0x6, _regval);
}

static inline void pci_hdr0_status_wr(__DN(t) *_dev, pci_hdr0_status_t _regval) __attribute__ ((always_inline));
static inline void pci_hdr0_status_wr(__DN(t) *_dev, pci_hdr0_status_t _regval)
{
    _regval = (_regval & 0xfff8);
    // No MB1 fields present
    _regval = (_regval | (0x7 & ((pci_hdr0_status_t )(pci::read16(_dev->base, 0x6)))));
    pci::write16(_dev->base, 0x6, _regval);
}

static inline dout_t& pci_hdr0_status_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& pci_hdr0_status_pr(dout_t& _os, __DN(t) *_dev)
{
    pci_hdr0_status_t _regval = (pci_hdr0_status_t )(pci::read16(_dev->base, 0x6));
    _os << ("Register status (Status): ");
    _os << ("\n");
    // _anon0 is anonymous
    ((_os << (" intstat =\t")) << pci_hdr0_status_intstat_extract(_regval)) << ("\t(Interrupt status)\n");
    ((_os << (" caplist =\t")) << pci_hdr0_status_caplist_extract(_regval)) << ("\t(Capabilities list)\n");
    ((_os << (" m66 =\t")) << pci_hdr0_status_m66_extract(_regval)) << ("\t(66MHz capable)\n");
    ((_os << (" udf =\t")) << pci_hdr0_status_udf_extract(_regval)) << ("\t(UDF supported)\n");
    ((_os << (" back2back =\t")) << pci_hdr0_status_back2back_extract(_regval)) << ("\t(Fast Back-to-Back enable)\n");
    ((_os << (" md_parity =\t")) << pci_hdr0_status_md_parity_extract(_regval)) << ("\t(Master data parity error)\n");
    ((_os << (" devsel =\t")) << pci_hdr0_status_devsel_extract(_regval)) << ("\t(DEVSEL timing)\n");
    ((_os << (" sig_t_abrt =\t")) << pci_hdr0_status_sig_t_abrt_extract(_regval)) << ("\t(Signalled target abort)\n");
    ((_os << (" rx_t_abrt =\t")) << pci_hdr0_status_rx_t_abrt_extract(_regval)) << ("\t(Received target abort)\n");
    ((_os << (" rx_m_abrt =\t")) << pci_hdr0_status_rx_m_abrt_extract(_regval)) << ("\t(Received master abort)\n");
    ((_os << (" system_err =\t")) << pci_hdr0_status_system_err_extract(_regval)) << ("\t(Signalled system error)\n");
    ((_os << (" parity_err =\t")) << pci_hdr0_status_parity_err_extract(_regval)) << ("\t(Detected parity error)\n");
    return(_os);
}

static inline uint8_t pci_hdr0_status_intstat_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_status_intstat_rdf(__DN(t) *_dev)
{
    pci_hdr0_status_t _regval = (pci_hdr0_status_t )(pci::read16(_dev->base, 0x6));
    return(pci_hdr0_status_intstat_extract(_regval));
}

static inline uint8_t pci_hdr0_status_caplist_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_status_caplist_rdf(__DN(t) *_dev)
{
    pci_hdr0_status_t _regval = (pci_hdr0_status_t )(pci::read16(_dev->base, 0x6));
    return(pci_hdr0_status_caplist_extract(_regval));
}

static inline uint8_t pci_hdr0_status_m66_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_status_m66_rdf(__DN(t) *_dev)
{
    pci_hdr0_status_t _regval = (pci_hdr0_status_t )(pci::read16(_dev->base, 0x6));
    return(pci_hdr0_status_m66_extract(_regval));
}

static inline uint8_t pci_hdr0_status_udf_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_status_udf_rdf(__DN(t) *_dev)
{
    pci_hdr0_status_t _regval = (pci_hdr0_status_t )(pci::read16(_dev->base, 0x6));
    return(pci_hdr0_status_udf_extract(_regval));
}

static inline uint8_t pci_hdr0_status_back2back_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_status_back2back_rdf(__DN(t) *_dev)
{
    pci_hdr0_status_t _regval = (pci_hdr0_status_t )(pci::read16(_dev->base, 0x6));
    return(pci_hdr0_status_back2back_extract(_regval));
}

static inline uint8_t pci_hdr0_status_md_parity_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_status_md_parity_rdf(__DN(t) *_dev)
{
    pci_hdr0_status_t _regval = (pci_hdr0_status_t )(pci::read16(_dev->base, 0x6));
    return(pci_hdr0_status_md_parity_extract(_regval));
}

static inline uint8_t pci_hdr0_status_devsel_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_status_devsel_rdf(__DN(t) *_dev)
{
    pci_hdr0_status_t _regval = (pci_hdr0_status_t )(pci::read16(_dev->base, 0x6));
    return(pci_hdr0_status_devsel_extract(_regval));
}

static inline uint8_t pci_hdr0_status_sig_t_abrt_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_status_sig_t_abrt_rdf(__DN(t) *_dev)
{
    pci_hdr0_status_t _regval = (pci_hdr0_status_t )(pci::read16(_dev->base, 0x6));
    return(pci_hdr0_status_sig_t_abrt_extract(_regval));
}

static inline uint8_t pci_hdr0_status_rx_t_abrt_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_status_rx_t_abrt_rdf(__DN(t) *_dev)
{
    pci_hdr0_status_t _regval = (pci_hdr0_status_t )(pci::read16(_dev->base, 0x6));
    return(pci_hdr0_status_rx_t_abrt_extract(_regval));
}

static inline uint8_t pci_hdr0_status_rx_m_abrt_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_status_rx_m_abrt_rdf(__DN(t) *_dev)
{
    pci_hdr0_status_t _regval = (pci_hdr0_status_t )(pci::read16(_dev->base, 0x6));
    return(pci_hdr0_status_rx_m_abrt_extract(_regval));
}

static inline uint8_t pci_hdr0_status_system_err_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_status_system_err_rdf(__DN(t) *_dev)
{
    pci_hdr0_status_t _regval = (pci_hdr0_status_t )(pci::read16(_dev->base, 0x6));
    return(pci_hdr0_status_system_err_extract(_regval));
}

static inline uint8_t pci_hdr0_status_parity_err_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_status_parity_err_rdf(__DN(t) *_dev)
{
    pci_hdr0_status_t _regval = (pci_hdr0_status_t )(pci::read16(_dev->base, 0x6));
    return(pci_hdr0_status_parity_err_extract(_regval));
}

static inline void pci_hdr0_status_md_parity_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void pci_hdr0_status_md_parity_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    pci_hdr0_status_t _regval = (pci_hdr0_status_t )(0x100 & (((pci_hdr0_status_t )(_fieldval)) << 8));
    _regval = (_regval | (0x7 & ((pci_hdr0_status_t )(pci::read16(_dev->base, 0x6)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    pci::write16(_dev->base, 0x6, _regval);
    // No shadow register to write to
}

static inline void pci_hdr0_status_sig_t_abrt_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void pci_hdr0_status_sig_t_abrt_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    pci_hdr0_status_t _regval = (pci_hdr0_status_t )(0x800 & (((pci_hdr0_status_t )(_fieldval)) << 11));
    _regval = (_regval | (0x7 & ((pci_hdr0_status_t )(pci::read16(_dev->base, 0x6)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    pci::write16(_dev->base, 0x6, _regval);
    // No shadow register to write to
}

static inline void pci_hdr0_status_rx_t_abrt_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void pci_hdr0_status_rx_t_abrt_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    pci_hdr0_status_t _regval = (pci_hdr0_status_t )(0x1000 & (((pci_hdr0_status_t )(_fieldval)) << 12));
    _regval = (_regval | (0x7 & ((pci_hdr0_status_t )(pci::read16(_dev->base, 0x6)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    pci::write16(_dev->base, 0x6, _regval);
    // No shadow register to write to
}

static inline void pci_hdr0_status_rx_m_abrt_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void pci_hdr0_status_rx_m_abrt_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    pci_hdr0_status_t _regval = (pci_hdr0_status_t )(0x2000 & (((pci_hdr0_status_t )(_fieldval)) << 13));
    _regval = (_regval | (0x7 & ((pci_hdr0_status_t )(pci::read16(_dev->base, 0x6)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    pci::write16(_dev->base, 0x6, _regval);
    // No shadow register to write to
}

static inline void pci_hdr0_status_system_err_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void pci_hdr0_status_system_err_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    pci_hdr0_status_t _regval = (pci_hdr0_status_t )(0x4000 & (((pci_hdr0_status_t )(_fieldval)) << 14));
    _regval = (_regval | (0x7 & ((pci_hdr0_status_t )(pci::read16(_dev->base, 0x6)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    pci::write16(_dev->base, 0x6, _regval);
    // No shadow register to write to
}

static inline void pci_hdr0_status_parity_err_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void pci_hdr0_status_parity_err_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    pci_hdr0_status_t _regval = (pci_hdr0_status_t )(0x8000 & (((pci_hdr0_status_t )(_fieldval)) << 15));
    _regval = (_regval | (0x7 & ((pci_hdr0_status_t )(pci::read16(_dev->base, 0x6)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    pci::write16(_dev->base, 0x6, _regval);
    // No shadow register to write to
}

/*
 * Register rev_id: Revision ID
 * Type: pci_hdr0.uint8 (primitive type)
 */
static inline uint8_t pci_hdr0_rev_id_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_rev_id_rawrd(__DN(t) *_dev)
{
    return((uint8_t )(pci::read8(_dev->base, 0x8)));
}

static inline uint8_t pci_hdr0_rev_id_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_rev_id_rd(__DN(t) *_dev)
{
    return((uint8_t )(pci::read8(_dev->base, 0x8)));
}

static inline void pci_hdr0_rev_id_rawwr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void pci_hdr0_rev_id_rawwr(__DN(t) *_dev, uint8_t _regval)
{
    pci::write8(_dev->base, 0x8, _regval);
}

// Register rev_id is not writeable
static inline dout_t& pci_hdr0_rev_id_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& pci_hdr0_rev_id_pr(dout_t& _os, __DN(t) *_dev)
{
    uint8_t _regval = (uint8_t )(pci::read8(_dev->base, 0x8));
    _os << ("Register rev_id (Revision ID): ");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

/*
 * Register class_code: Class code
 * Type: pci_hdr0.class_code (Implicit type of Class code register)
 *   _anon0	(size 8, offset 0, init 0):	RSVD	_
 *   prog_if	(size 8, offset 8, init 0):	RO	Programming intf
 *   subclss	(size 8, offset 16, init 0):	RO	Subclass code
 *   clss	(size 8, offset 24, init 0):	RO	Class code
 */
static inline pci_hdr0_class_code_t pci_hdr0_class_code_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline pci_hdr0_class_code_t pci_hdr0_class_code_rawrd(__DN(t) *_dev)
{
    return((pci_hdr0_class_code_t )(pci::read32(_dev->base, 0x8)));
}

static inline pci_hdr0_class_code_t pci_hdr0_class_code_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline pci_hdr0_class_code_t pci_hdr0_class_code_rd(__DN(t) *_dev)
{
    return((pci_hdr0_class_code_t )(pci::read32(_dev->base, 0x8)));
}

static inline void pci_hdr0_class_code_rawwr(__DN(t) *_dev, pci_hdr0_class_code_t _regval) __attribute__ ((always_inline));
static inline void pci_hdr0_class_code_rawwr(__DN(t) *_dev, pci_hdr0_class_code_t _regval)
{
    pci::write32(_dev->base, 0x8, _regval);
}

// Register class_code is not writeable
static inline dout_t& pci_hdr0_class_code_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& pci_hdr0_class_code_pr(dout_t& _os, __DN(t) *_dev)
{
    pci_hdr0_class_code_t _regval = (pci_hdr0_class_code_t )(pci::read32(_dev->base, 0x8));
    _os << ("Register class_code (Class code): ");
    _os << ("\n");
    // _anon0 is anonymous
    ((_os << (" prog_if =\t")) << pci_hdr0_class_code_prog_if_extract(_regval)) << ("\t(Programming intf)\n");
    ((_os << (" subclss =\t")) << pci_hdr0_class_code_subclss_extract(_regval)) << ("\t(Subclass code)\n");
    ((_os << (" clss =\t")) << pci_hdr0_class_code_clss_extract(_regval)) << ("\t(Class code)\n");
    return(_os);
}

static inline uint8_t pci_hdr0_class_code_prog_if_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_class_code_prog_if_rdf(__DN(t) *_dev)
{
    pci_hdr0_class_code_t _regval = (pci_hdr0_class_code_t )(pci::read32(_dev->base, 0x8));
    return(pci_hdr0_class_code_prog_if_extract(_regval));
}

static inline uint8_t pci_hdr0_class_code_subclss_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_class_code_subclss_rdf(__DN(t) *_dev)
{
    pci_hdr0_class_code_t _regval = (pci_hdr0_class_code_t )(pci::read32(_dev->base, 0x8));
    return(pci_hdr0_class_code_subclss_extract(_regval));
}

static inline pci_hdr0_classcode_t pci_hdr0_class_code_clss_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline pci_hdr0_classcode_t pci_hdr0_class_code_clss_rdf(__DN(t) *_dev)
{
    pci_hdr0_class_code_t _regval = (pci_hdr0_class_code_t )(pci::read32(_dev->base, 0x8));
    return(pci_hdr0_class_code_clss_extract(_regval));
}

/*
 * Register cache_sz: Cache line size
 * Type: pci_hdr0.uint8 (primitive type)
 */
static inline uint8_t pci_hdr0_cache_sz_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_cache_sz_rawrd(__DN(t) *_dev)
{
    return((uint8_t )(pci::read8(_dev->base, 0xc)));
}

static inline uint8_t pci_hdr0_cache_sz_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_cache_sz_rd(__DN(t) *_dev)
{
    return((uint8_t )(pci::read8(_dev->base, 0xc)));
}

static inline void pci_hdr0_cache_sz_rawwr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void pci_hdr0_cache_sz_rawwr(__DN(t) *_dev, uint8_t _regval)
{
    pci::write8(_dev->base, 0xc, _regval);
}

static inline void pci_hdr0_cache_sz_wr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void pci_hdr0_cache_sz_wr(__DN(t) *_dev, uint8_t _regval)
{
    // No MB0 or RSVD fields present
    // No MB1 fields present
    // No pre-read of register required
    pci::write8(_dev->base, 0xc, _regval);
}

static inline dout_t& pci_hdr0_cache_sz_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& pci_hdr0_cache_sz_pr(dout_t& _os, __DN(t) *_dev)
{
    uint8_t _regval = (uint8_t )(pci::read8(_dev->base, 0xc));
    _os << ("Register cache_sz (Cache line size): ");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

/*
 * Register latency: Master latency timer
 * Type: pci_hdr0.uint8 (primitive type)
 */
static inline uint8_t pci_hdr0_latency_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_latency_rawrd(__DN(t) *_dev)
{
    return((uint8_t )(pci::read8(_dev->base, 0xd)));
}

static inline uint8_t pci_hdr0_latency_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_latency_rd(__DN(t) *_dev)
{
    return((uint8_t )(pci::read8(_dev->base, 0xd)));
}

static inline void pci_hdr0_latency_rawwr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void pci_hdr0_latency_rawwr(__DN(t) *_dev, uint8_t _regval)
{
    pci::write8(_dev->base, 0xd, _regval);
}

static inline void pci_hdr0_latency_wr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void pci_hdr0_latency_wr(__DN(t) *_dev, uint8_t _regval)
{
    // No MB0 or RSVD fields present
    // No MB1 fields present
    // No pre-read of register required
    pci::write8(_dev->base, 0xd, _regval);
}

static inline dout_t& pci_hdr0_latency_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& pci_hdr0_latency_pr(dout_t& _os, __DN(t) *_dev)
{
    uint8_t _regval = (uint8_t )(pci::read8(_dev->base, 0xd));
    _os << ("Register latency (Master latency timer): ");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

/*
 * Register hdr_type: Header type
 * Type: pci_hdr0.hdr_type (Implicit type of Header type register)
 *   fmt	(size 7, offset 0, init 0):	RO	Configuration header format
 *   multi	(size 1, offset 7, init 0):	RO	Multifunction device
 */
static inline pci_hdr0_hdr_type_t pci_hdr0_hdr_type_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline pci_hdr0_hdr_type_t pci_hdr0_hdr_type_rawrd(__DN(t) *_dev)
{
    return((pci_hdr0_hdr_type_t )(pci::read8(_dev->base, 0xe)));
}

static inline pci_hdr0_hdr_type_t pci_hdr0_hdr_type_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline pci_hdr0_hdr_type_t pci_hdr0_hdr_type_rd(__DN(t) *_dev)
{
    return((pci_hdr0_hdr_type_t )(pci::read8(_dev->base, 0xe)));
}

static inline void pci_hdr0_hdr_type_rawwr(__DN(t) *_dev, pci_hdr0_hdr_type_t _regval) __attribute__ ((always_inline));
static inline void pci_hdr0_hdr_type_rawwr(__DN(t) *_dev, pci_hdr0_hdr_type_t _regval)
{
    pci::write8(_dev->base, 0xe, _regval);
}

// Register hdr_type is not writeable
static inline dout_t& pci_hdr0_hdr_type_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& pci_hdr0_hdr_type_pr(dout_t& _os, __DN(t) *_dev)
{
    pci_hdr0_hdr_type_t _regval = (pci_hdr0_hdr_type_t )(pci::read8(_dev->base, 0xe));
    _os << ("Register hdr_type (Header type): ");
    _os << ("\n");
    ((_os << (" fmt =\t")) << pci_hdr0_hdr_type_fmt_extract(_regval)) << ("\t(Configuration header format)\n");
    ((_os << (" multi =\t")) << pci_hdr0_hdr_type_multi_extract(_regval)) << ("\t(Multifunction device)\n");
    return(_os);
}

static inline pci_hdr0_hdrtype_t pci_hdr0_hdr_type_fmt_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline pci_hdr0_hdrtype_t pci_hdr0_hdr_type_fmt_rdf(__DN(t) *_dev)
{
    pci_hdr0_hdr_type_t _regval = (pci_hdr0_hdr_type_t )(pci::read8(_dev->base, 0xe));
    return(pci_hdr0_hdr_type_fmt_extract(_regval));
}

static inline uint8_t pci_hdr0_hdr_type_multi_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_hdr_type_multi_rdf(__DN(t) *_dev)
{
    pci_hdr0_hdr_type_t _regval = (pci_hdr0_hdr_type_t )(pci::read8(_dev->base, 0xe));
    return(pci_hdr0_hdr_type_multi_extract(_regval));
}

/*
 * Register bist: Built-in self-test
 * Type: pci_hdr0.bist (Implicit type of Built-in self-test register)
 *   comp	(size 4, offset 0, init 0):	RO	Completion code
 *   _anon4	(size 2, offset 4, init 0):	RSVD	_
 *   start	(size 1, offset 6, init 0):	RW	Start BIST
 *   cap	(size 1, offset 7, init 0):	RO	BIST capable
 */
static inline pci_hdr0_bist_t pci_hdr0_bist_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline pci_hdr0_bist_t pci_hdr0_bist_rawrd(__DN(t) *_dev)
{
    return((pci_hdr0_bist_t )(pci::read8(_dev->base, 0xf)));
}

static inline pci_hdr0_bist_t pci_hdr0_bist_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline pci_hdr0_bist_t pci_hdr0_bist_rd(__DN(t) *_dev)
{
    return((pci_hdr0_bist_t )(pci::read8(_dev->base, 0xf)));
}

static inline void pci_hdr0_bist_rawwr(__DN(t) *_dev, pci_hdr0_bist_t _regval) __attribute__ ((always_inline));
static inline void pci_hdr0_bist_rawwr(__DN(t) *_dev, pci_hdr0_bist_t _regval)
{
    pci::write8(_dev->base, 0xf, _regval);
}

static inline void pci_hdr0_bist_wr(__DN(t) *_dev, pci_hdr0_bist_t _regval) __attribute__ ((always_inline));
static inline void pci_hdr0_bist_wr(__DN(t) *_dev, pci_hdr0_bist_t _regval)
{
    _regval = (_regval & 0xcf);
    // No MB1 fields present
    _regval = (_regval | (0x30 & ((pci_hdr0_bist_t )(pci::read8(_dev->base, 0xf)))));
    pci::write8(_dev->base, 0xf, _regval);
}

static inline dout_t& pci_hdr0_bist_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& pci_hdr0_bist_pr(dout_t& _os, __DN(t) *_dev)
{
    pci_hdr0_bist_t _regval = (pci_hdr0_bist_t )(pci::read8(_dev->base, 0xf));
    _os << ("Register bist (Built-in self-test): ");
    _os << ("\n");
    ((_os << (" comp =\t")) << pci_hdr0_bist_comp_extract(_regval)) << ("\t(Completion code)\n");
    // _anon4 is anonymous
    ((_os << (" start =\t")) << pci_hdr0_bist_start_extract(_regval)) << ("\t(Start BIST)\n");
    ((_os << (" cap =\t")) << pci_hdr0_bist_cap_extract(_regval)) << ("\t(BIST capable)\n");
    return(_os);
}

static inline uint8_t pci_hdr0_bist_comp_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_bist_comp_rdf(__DN(t) *_dev)
{
    pci_hdr0_bist_t _regval = (pci_hdr0_bist_t )(pci::read8(_dev->base, 0xf));
    return(pci_hdr0_bist_comp_extract(_regval));
}

static inline uint8_t pci_hdr0_bist_start_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_bist_start_rdf(__DN(t) *_dev)
{
    pci_hdr0_bist_t _regval = (pci_hdr0_bist_t )(pci::read8(_dev->base, 0xf));
    return(pci_hdr0_bist_start_extract(_regval));
}

static inline uint8_t pci_hdr0_bist_cap_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_bist_cap_rdf(__DN(t) *_dev)
{
    pci_hdr0_bist_t _regval = (pci_hdr0_bist_t )(pci::read8(_dev->base, 0xf));
    return(pci_hdr0_bist_cap_extract(_regval));
}

static inline void pci_hdr0_bist_start_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void pci_hdr0_bist_start_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    pci_hdr0_bist_t _regval = (pci_hdr0_bist_t )(0x40 & (((pci_hdr0_bist_t )(_fieldval)) << 6));
    _regval = (_regval | (0x30 & ((pci_hdr0_bist_t )(pci::read8(_dev->base, 0xf)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    pci::write8(_dev->base, 0xf, _regval);
    // No shadow register to write to
}

/*
 * Register array bars: Base address registers
 * Type: pci_hdr0.uint32 (primitive type)
 */
static const size_t pci_hdr0_bars_length = 5;
static inline uint32_t pci_hdr0_bars_rawrd(__DN(t) *_dev, int _i) __attribute__ ((always_inline));
static inline uint32_t pci_hdr0_bars_rawrd(__DN(t) *_dev, int _i)
{
    return((uint32_t )(pci::read32(_dev->base, 0x10 + (_i * (32 / 8)))));
}

static inline uint32_t pci_hdr0_bars_rd(__DN(t) *_dev, int _i) __attribute__ ((always_inline));
static inline uint32_t pci_hdr0_bars_rd(__DN(t) *_dev, int _i)
{
    return((uint32_t )(pci::read32(_dev->base, 0x10 + (_i * (32 / 8)))));
}

static inline void pci_hdr0_bars_rawwr(__DN(t) *_dev, int _i, uint32_t _regval) __attribute__ ((always_inline));
static inline void pci_hdr0_bars_rawwr(__DN(t) *_dev, int _i, uint32_t _regval)
{
    pci::write32(_dev->base, 0x10 + (_i * (32 / 8)), _regval);
}

static inline void pci_hdr0_bars_wr(__DN(t) *_dev, int _i, uint32_t _regval) __attribute__ ((always_inline));
static inline void pci_hdr0_bars_wr(__DN(t) *_dev, int _i, uint32_t _regval)
{
    // No MB0 or RSVD fields present
    // No MB1 fields present
    // No pre-read of register required
    pci::write32(_dev->base, 0x10 + (_i * (32 / 8)), _regval);
}

static inline dout_t& pci_hdr0_bars_pri(dout_t& _os, __DN(t) *_dev, int _i) __attribute__ ((always_inline));
static inline dout_t& pci_hdr0_bars_pri(dout_t& _os, __DN(t) *_dev, int _i)
{
    uint32_t _regval = (uint32_t )(pci::read32(_dev->base, 0x10 + (_i * (32 / 8))));
    ((((_os << ("Register ")) << ("bars")) << _i) << ("Base address registers")) << (":");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

static inline dout_t& pci_hdr0_bars_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& pci_hdr0_bars_pr(dout_t& _os, __DN(t) *_dev)
{
    int _i;
    for( _i = 0; _i < 5; _i++) {
        pci_hdr0_bars_pri(_os, _dev, _i);
    }
    return(_os);
}

/*
 * Register cardbus: CardBus CIS ptr
 * Type: pci_hdr0.uint32 (primitive type)
 */
static inline uint32_t pci_hdr0_cardbus_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint32_t pci_hdr0_cardbus_rawrd(__DN(t) *_dev)
{
    return((uint32_t )(pci::read32(_dev->base, 0x28)));
}

static inline uint32_t pci_hdr0_cardbus_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint32_t pci_hdr0_cardbus_rd(__DN(t) *_dev)
{
    return((uint32_t )(pci::read32(_dev->base, 0x28)));
}

static inline void pci_hdr0_cardbus_rawwr(__DN(t) *_dev, uint32_t _regval) __attribute__ ((always_inline));
static inline void pci_hdr0_cardbus_rawwr(__DN(t) *_dev, uint32_t _regval)
{
    pci::write32(_dev->base, 0x28, _regval);
}

// Register cardbus is not writeable
static inline dout_t& pci_hdr0_cardbus_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& pci_hdr0_cardbus_pr(dout_t& _os, __DN(t) *_dev)
{
    uint32_t _regval = (uint32_t )(pci::read32(_dev->base, 0x28));
    _os << ("Register cardbus (CardBus CIS ptr): ");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

/*
 * Register subsys_vid: Subsystem vendor ID
 * Type: pci_hdr0.uint16 (primitive type)
 */
static inline uint16_t pci_hdr0_subsys_vid_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint16_t pci_hdr0_subsys_vid_rawrd(__DN(t) *_dev)
{
    return((uint16_t )(pci::read16(_dev->base, 0x2c)));
}

static inline uint16_t pci_hdr0_subsys_vid_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint16_t pci_hdr0_subsys_vid_rd(__DN(t) *_dev)
{
    return((uint16_t )(pci::read16(_dev->base, 0x2c)));
}

static inline void pci_hdr0_subsys_vid_rawwr(__DN(t) *_dev, uint16_t _regval) __attribute__ ((always_inline));
static inline void pci_hdr0_subsys_vid_rawwr(__DN(t) *_dev, uint16_t _regval)
{
    pci::write16(_dev->base, 0x2c, _regval);
}

// Register subsys_vid is not writeable
static inline dout_t& pci_hdr0_subsys_vid_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& pci_hdr0_subsys_vid_pr(dout_t& _os, __DN(t) *_dev)
{
    uint16_t _regval = (uint16_t )(pci::read16(_dev->base, 0x2c));
    _os << ("Register subsys_vid (Subsystem vendor ID): ");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

/*
 * Register subsys_id: Subsystem ID
 * Type: pci_hdr0.uint16 (primitive type)
 */
static inline uint16_t pci_hdr0_subsys_id_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint16_t pci_hdr0_subsys_id_rawrd(__DN(t) *_dev)
{
    return((uint16_t )(pci::read16(_dev->base, 0x2e)));
}

static inline uint16_t pci_hdr0_subsys_id_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint16_t pci_hdr0_subsys_id_rd(__DN(t) *_dev)
{
    return((uint16_t )(pci::read16(_dev->base, 0x2e)));
}

static inline void pci_hdr0_subsys_id_rawwr(__DN(t) *_dev, uint16_t _regval) __attribute__ ((always_inline));
static inline void pci_hdr0_subsys_id_rawwr(__DN(t) *_dev, uint16_t _regval)
{
    pci::write16(_dev->base, 0x2e, _regval);
}

// Register subsys_id is not writeable
static inline dout_t& pci_hdr0_subsys_id_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& pci_hdr0_subsys_id_pr(dout_t& _os, __DN(t) *_dev)
{
    uint16_t _regval = (uint16_t )(pci::read16(_dev->base, 0x2e));
    _os << ("Register subsys_id (Subsystem ID): ");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

/*
 * Register rom_base: Expansion ROM base addr
 * Type: pci_hdr0.rom_base (Implicit type of Expansion ROM base addr register)
 *   enable	(size 1, offset 0, init 0):	RW	ROM address decoder enable
 *   _anon1	(size 10, offset 1, init 0):	RSVD	_
 *   base	(size 21, offset 11, init 0):	RW	ROM Base address high bits
 */
static inline pci_hdr0_rom_base_t pci_hdr0_rom_base_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline pci_hdr0_rom_base_t pci_hdr0_rom_base_rawrd(__DN(t) *_dev)
{
    return((pci_hdr0_rom_base_t )(pci::read32(_dev->base, 0x30)));
}

static inline pci_hdr0_rom_base_t pci_hdr0_rom_base_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline pci_hdr0_rom_base_t pci_hdr0_rom_base_rd(__DN(t) *_dev)
{
    return((pci_hdr0_rom_base_t )(pci::read32(_dev->base, 0x30)));
}

static inline void pci_hdr0_rom_base_rawwr(__DN(t) *_dev, pci_hdr0_rom_base_t _regval) __attribute__ ((always_inline));
static inline void pci_hdr0_rom_base_rawwr(__DN(t) *_dev, pci_hdr0_rom_base_t _regval)
{
    pci::write32(_dev->base, 0x30, _regval);
}

static inline void pci_hdr0_rom_base_wr(__DN(t) *_dev, pci_hdr0_rom_base_t _regval) __attribute__ ((always_inline));
static inline void pci_hdr0_rom_base_wr(__DN(t) *_dev, pci_hdr0_rom_base_t _regval)
{
    _regval = (_regval & 0xfffff801);
    // No MB1 fields present
    _regval = (_regval | (0x7fe & ((pci_hdr0_rom_base_t )(pci::read32(_dev->base, 0x30)))));
    pci::write32(_dev->base, 0x30, _regval);
}

static inline dout_t& pci_hdr0_rom_base_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& pci_hdr0_rom_base_pr(dout_t& _os, __DN(t) *_dev)
{
    pci_hdr0_rom_base_t _regval = (pci_hdr0_rom_base_t )(pci::read32(_dev->base, 0x30));
    _os << ("Register rom_base (Expansion ROM base addr): ");
    _os << ("\n");
    ((_os << (" enable =\t")) << pci_hdr0_rom_base_enable_extract(_regval)) << ("\t(ROM address decoder enable)\n");
    // _anon1 is anonymous
    ((_os << (" base =\t")) << pci_hdr0_rom_base_base_extract(_regval)) << ("\t(ROM Base address high bits)\n");
    return(_os);
}

static inline uint8_t pci_hdr0_rom_base_enable_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_rom_base_enable_rdf(__DN(t) *_dev)
{
    pci_hdr0_rom_base_t _regval = (pci_hdr0_rom_base_t )(pci::read32(_dev->base, 0x30));
    return(pci_hdr0_rom_base_enable_extract(_regval));
}

static inline uint32_t pci_hdr0_rom_base_base_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint32_t pci_hdr0_rom_base_base_rdf(__DN(t) *_dev)
{
    pci_hdr0_rom_base_t _regval = (pci_hdr0_rom_base_t )(pci::read32(_dev->base, 0x30));
    return(pci_hdr0_rom_base_base_extract(_regval));
}

static inline void pci_hdr0_rom_base_enable_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void pci_hdr0_rom_base_enable_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    pci_hdr0_rom_base_t _regval = (pci_hdr0_rom_base_t )(0x1 & (((pci_hdr0_rom_base_t )(_fieldval)) << 0));
    _regval = (_regval | (0xfffffffe & ((pci_hdr0_rom_base_t )(pci::read32(_dev->base, 0x30)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    pci::write32(_dev->base, 0x30, _regval);
    // No shadow register to write to
}

static inline void pci_hdr0_rom_base_base_wrf(__DN(t) *_dev, uint32_t _fieldval) __attribute__ ((always_inline));
static inline void pci_hdr0_rom_base_base_wrf(__DN(t) *_dev, uint32_t _fieldval)
{
    pci_hdr0_rom_base_t _regval = (pci_hdr0_rom_base_t )(0xfffff800 & (((pci_hdr0_rom_base_t )(_fieldval)) << 11));
    _regval = (_regval | (0x7ff & ((pci_hdr0_rom_base_t )(pci::read32(_dev->base, 0x30)))));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    pci::write32(_dev->base, 0x30, _regval);
    // No shadow register to write to
}

/*
 * Register cap_ptr: Capabilities ptr
 * Type: pci_hdr0.uint8 (primitive type)
 */
static inline uint8_t pci_hdr0_cap_ptr_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_cap_ptr_rawrd(__DN(t) *_dev)
{
    return((uint8_t )(pci::read8(_dev->base, 0x34)));
}

static inline uint8_t pci_hdr0_cap_ptr_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_cap_ptr_rd(__DN(t) *_dev)
{
    return((uint8_t )(pci::read8(_dev->base, 0x34)));
}

static inline void pci_hdr0_cap_ptr_rawwr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void pci_hdr0_cap_ptr_rawwr(__DN(t) *_dev, uint8_t _regval)
{
    pci::write8(_dev->base, 0x34, _regval);
}

// Register cap_ptr is not writeable
static inline dout_t& pci_hdr0_cap_ptr_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& pci_hdr0_cap_ptr_pr(dout_t& _os, __DN(t) *_dev)
{
    uint8_t _regval = (uint8_t )(pci::read8(_dev->base, 0x34));
    _os << ("Register cap_ptr (Capabilities ptr): ");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

/*
 * Register int_line: Interrupt line
 * Type: pci_hdr0.uint8 (primitive type)
 */
static inline uint8_t pci_hdr0_int_line_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_int_line_rawrd(__DN(t) *_dev)
{
    return((uint8_t )(pci::read8(_dev->base, 0x3c)));
}

static inline uint8_t pci_hdr0_int_line_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_int_line_rd(__DN(t) *_dev)
{
    return((uint8_t )(pci::read8(_dev->base, 0x3c)));
}

static inline void pci_hdr0_int_line_rawwr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void pci_hdr0_int_line_rawwr(__DN(t) *_dev, uint8_t _regval)
{
    pci::write8(_dev->base, 0x3c, _regval);
}

static inline void pci_hdr0_int_line_wr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void pci_hdr0_int_line_wr(__DN(t) *_dev, uint8_t _regval)
{
    // No MB0 or RSVD fields present
    // No MB1 fields present
    // No pre-read of register required
    pci::write8(_dev->base, 0x3c, _regval);
}

static inline dout_t& pci_hdr0_int_line_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& pci_hdr0_int_line_pr(dout_t& _os, __DN(t) *_dev)
{
    uint8_t _regval = (uint8_t )(pci::read8(_dev->base, 0x3c));
    _os << ("Register int_line (Interrupt line): ");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

/*
 * Register int_pin: Interrupt ping
 * Type: pci_hdr0.uint8 (primitive type)
 */
static inline uint8_t pci_hdr0_int_pin_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_int_pin_rawrd(__DN(t) *_dev)
{
    return((uint8_t )(pci::read8(_dev->base, 0x3d)));
}

static inline uint8_t pci_hdr0_int_pin_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_int_pin_rd(__DN(t) *_dev)
{
    return((uint8_t )(pci::read8(_dev->base, 0x3d)));
}

static inline void pci_hdr0_int_pin_rawwr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void pci_hdr0_int_pin_rawwr(__DN(t) *_dev, uint8_t _regval)
{
    pci::write8(_dev->base, 0x3d, _regval);
}

// Register int_pin is not writeable
static inline dout_t& pci_hdr0_int_pin_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& pci_hdr0_int_pin_pr(dout_t& _os, __DN(t) *_dev)
{
    uint8_t _regval = (uint8_t )(pci::read8(_dev->base, 0x3d));
    _os << ("Register int_pin (Interrupt ping): ");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

/*
 * Register min_gnt: Min Gnt
 * Type: pci_hdr0.uint8 (primitive type)
 */
static inline uint8_t pci_hdr0_min_gnt_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_min_gnt_rawrd(__DN(t) *_dev)
{
    return((uint8_t )(pci::read8(_dev->base, 0x3e)));
}

static inline uint8_t pci_hdr0_min_gnt_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_min_gnt_rd(__DN(t) *_dev)
{
    return((uint8_t )(pci::read8(_dev->base, 0x3e)));
}

static inline void pci_hdr0_min_gnt_rawwr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void pci_hdr0_min_gnt_rawwr(__DN(t) *_dev, uint8_t _regval)
{
    pci::write8(_dev->base, 0x3e, _regval);
}

// Register min_gnt is not writeable
static inline dout_t& pci_hdr0_min_gnt_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& pci_hdr0_min_gnt_pr(dout_t& _os, __DN(t) *_dev)
{
    uint8_t _regval = (uint8_t )(pci::read8(_dev->base, 0x3e));
    _os << ("Register min_gnt (Min Gnt): ");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

/*
 * Register max_lat: Max Lat
 * Type: pci_hdr0.uint8 (primitive type)
 */
static inline uint8_t pci_hdr0_max_lat_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_max_lat_rawrd(__DN(t) *_dev)
{
    return((uint8_t )(pci::read8(_dev->base, 0x3f)));
}

static inline uint8_t pci_hdr0_max_lat_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t pci_hdr0_max_lat_rd(__DN(t) *_dev)
{
    return((uint8_t )(pci::read8(_dev->base, 0x3f)));
}

static inline void pci_hdr0_max_lat_rawwr(__DN(t) *_dev, uint8_t _regval) __attribute__ ((always_inline));
static inline void pci_hdr0_max_lat_rawwr(__DN(t) *_dev, uint8_t _regval)
{
    pci::write8(_dev->base, 0x3f, _regval);
}

// Register max_lat is not writeable
static inline dout_t& pci_hdr0_max_lat_pr(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& pci_hdr0_max_lat_pr(dout_t& _os, __DN(t) *_dev)
{
    uint8_t _regval = (uint8_t )(pci::read8(_dev->base, 0x3f));
    _os << ("Register max_lat (Max Lat): ");
    ((_os << ("\t")) << _regval) << ("");
    return(_os);
}

static inline dout_t& operator<<(dout_t& _os, __DN(t) *_dev) __attribute__ ((always_inline));
static inline dout_t& operator<<(dout_t& _os, __DN(t) *_dev)
{
    _os << ("-------------------------\n");
    _os << ("Dump of device pci_hdr0 (PCI Type 0 Configuration):\n");
    pci_hdr0_vendor_id_pr(_os, _dev);
    pci_hdr0_device_id_pr(_os, _dev);
    pci_hdr0_command_pr(_os, _dev);
    pci_hdr0_status_pr(_os, _dev);
    pci_hdr0_rev_id_pr(_os, _dev);
    pci_hdr0_class_code_pr(_os, _dev);
    pci_hdr0_cache_sz_pr(_os, _dev);
    pci_hdr0_latency_pr(_os, _dev);
    pci_hdr0_hdr_type_pr(_os, _dev);
    pci_hdr0_bist_pr(_os, _dev);
    pci_hdr0_bars_pr(_os, _dev);
    pci_hdr0_cardbus_pr(_os, _dev);
    pci_hdr0_subsys_vid_pr(_os, _dev);
    pci_hdr0_subsys_id_pr(_os, _dev);
    pci_hdr0_rom_base_pr(_os, _dev);
    pci_hdr0_cap_ptr_pr(_os, _dev);
    pci_hdr0_int_line_pr(_os, _dev);
    pci_hdr0_int_pin_pr(_os, _dev);
    pci_hdr0_min_gnt_pr(_os, _dev);
    pci_hdr0_max_lat_pr(_os, _dev);
    _os << ("End of dump of device pci_hdr0\n");
    _os << ("-------------------------\n");
    return(_os);
}

#undef __DN
