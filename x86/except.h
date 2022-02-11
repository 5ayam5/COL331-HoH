#pragma once

#include "devices/idt32.h"
#include "devices/lapic.h"



#define __isr   extern "C" __attribute__ ((visibility("hidden")))
#define __isr_helper extern "C" __attribute__((used,visibility("hidden"))) __attribute__((force_align_arg_pointer))



//
// interface
//
extern "C" void idt_reset(dev_idt32_t& idt);

//
//guaranteed not to floats or simd
//
extern "C" void lapic_eoi();
extern "C" void pic_eoi_master();
extern "C" void pic_eoi_slave();
extern "C" void lapic_dump();
extern "C" void pic_dump();


