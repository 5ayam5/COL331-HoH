#pragma once

enum {
  lapic_internal_lint0=0x0,
  lapic_internal_lint1,
  lapic_internal_perfcnt,
  lapic_internal_thermal,
  lapic_internal_err,
  lapic_internal_spurious,
  lapic_internal_timer=0x6, // should be the last

  pic_master_base=0x20,
  pic_slave_base=0x28,
  lapic_base=0x30,
  lapic_internal_base = 0x40
};




struct descriptor_register{
        uint16_t limit;
        uint32_t base;
} __attribute__((packed));


