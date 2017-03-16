#include "x86/except.h"
#include "x86/main.h"


//
// This file should be compiled with floats and SIMDs disabled
//

//
// Classes:
//  1a.  Critical with error code: Double fault(0x8)
//  1b.  Critical: NMI(0x2), Machine check exceptions(0x12)
//  2a. User exceptions with error codes: 0xa,0xb,0xc,0xd,0xe and 0x11
//  2b. User exceptions: 0x0 -> 0x13 (except above)
//  3a. PIC Master exceptions : PIC_BASE+ (0x0 -> 0x7)
//  3b. PIC Slave  exceptions : PIC_BASE+ 0x8 + (0x0 -> 0x7)
//  4a. LAPIC exceptions: LAPIC_BASE+ (0x0 -> 0xf)
//  4b. LAPIC internal exceptions: LAPIC_BASE +0x10 +(0x0 -> 0x6) : LINT0, LINT1, Perfcnt, Thermal, ERR, Spurious, Timer
//
//


//
//  Macro for Class 1a ISRs
//
#define _isr_critical_withec(_n)                  \
         __isr      void isr_critical##_n();      \
         __asm(                                   \
         "  .text                            \n\t"\
         "  .global isr_critical" STR(_n) "  \n\t"\
         "  isr_critical"     STR(_n) ":     \n\t"\
         "   pushl $" STR(_n) "              \n\t"\
         "   jmp handler_critical            \n\t"\
         )                                        \

//
//  Macro for Class 1b ISRs
//
#define _isr_critical(_n)                         \
         __isr      void isr_critical##_n();      \
         __asm(                                   \
         "  .text                            \n\t"\
         "  .global isr_critical" STR(_n) "  \n\t"\
         "  isr_critical"     STR(_n) ":     \n\t"\
         "   pushl $0                        \n\t"\
         "   pushl $" STR(_n) "              \n\t"\
         "   jmp handler_critical            \n\t"\
         )                                        \




//
//  Macro for Class 2a ISRs
//
#define _isr_user_withec(_n)                      \
         __isr      void isr_user##_n();          \
         __asm(                                   \
         "  .text                            \n\t"\
         "  .global isr_user" STR(_n) "      \n\t"\
         "  isr_user" STR(_n) ":             \n\t"\
         "   pushl $" STR(_n) "              \n\t"\
         "   jmp handler_user                \n\t"\
         )                                        \


//
//  Macro for Class 2b ISRs
//
#define _isr_user(_n)                             \
         __isr      void isr_user##_n();          \
         __asm(                                   \
         "  .text                            \n\t"\
         "  .global isr_user" STR(_n) "      \n\t"\
         "  isr_user" STR(_n) ":             \n\t"\
         "   pushl $0                        \n\t"\
         "   pushl $" STR(_n) "              \n\t"\
         "   jmp handler_user                \n\t"\
         )                                        \


//
//  Macro for Class 3a ISRs
//
#define _isr_pic_master(_n)                       \
         __isr      void isr_pic_master##_n();    \
         __asm(                                   \
         "  .text                            \n\t"\
         "  .global isr_pic_master" STR(_n) "\n\t"\
         "  isr_pic_master" STR(_n) ":       \n\t"\
         "   pushl $0                        \n\t"\
         "   pushl $" STR(_n) "              \n\t"\
         "   jmp handler_pic_master          \n\t"\
         )                                        \



//
//  Macro for Class 3b ISRs
//
#define _isr_pic_slave(_n)                        \
         __isr      void isr_pic_slave##_n();     \
         __asm(                                   \
         "  .text                            \n\t"\
         "  .global isr_pic_slave" STR(_n) " \n\t"\
         "  isr_pic_slave" STR(_n) ":        \n\t"\
         "   pushl $0                        \n\t"\
         "   pushl $" STR(_n) "              \n\t"\
         "   jmp handler_pic_slave           \n\t"\
         )                                        \


//
//  Macro for Class 4a ISRs
//
#define _isr_lapic(_n)                            \
         __isr      void isr_lapic##_n();         \
         __asm(                                   \
         "  .text                            \n\t"\
         "  .global isr_lapic" STR(_n) "     \n\t"\
         "  isr_lapic" STR(_n) ":            \n\t"\
         "   pushl $0                        \n\t"\
         "   pushl $" STR(_n) "              \n\t"\
         "   jmp handler_lapic               \n\t"\
         )                                        \


//
//  Macro for Class 4b ISRs
//
#define _isr_lapic_internal(_n)                   \
         __isr      void isr_lapic_internal##_n();\
         __asm(                                   \
         "  .text                            \n\t"\
         "  .global isr_lapic_internal" STR(_n) " \n\t"\
         "  isr_lapic_internal" STR(_n) ":   \n\t"\
         "   pushl $0                        \n\t"\
         "   pushl $" STR(_n) "              \n\t"\
         "   jmp handler_lapic_internal      \n\t"\
         )                                        \



//
// Define Class 1a ISRs: 0x8
//
_isr_critical_withec(0);


//
// Define Class 1b ISRs: 0x12
//
_isr_critical(1);


//
// Define Class 2a ISRs: 0xA 0xB 0xC 0xD 0xE, and 0x11
//
_isr_user_withec(10);
_isr_user_withec(11);
_isr_user_withec(12);
_isr_user_withec(13);
_isr_user_withec(14);
_isr_user_withec(17);

//
// Define Class 2b ISRs
//
_isr_user(0);
_isr_user(1);
_isr_user(2);
_isr_user(3);
_isr_user(4);
_isr_user(5);
_isr_user(6);
_isr_user(7);
// 8 is Class 1a
_isr_user(9);
// 10-14: are class 2a
_isr_user(15);
_isr_user(16);
// 17 is Class 2a
// 18 is Class 1b
_isr_user(19);



//
// Define Class 3a ISRs
//
_isr_pic_master(0);
_isr_pic_master(1);
_isr_pic_master(2);
_isr_pic_master(3);
_isr_pic_master(4);
_isr_pic_master(5);
_isr_pic_master(6);
_isr_pic_master(7);


//
// Define Class 3b ISRs
//
_isr_pic_slave(0);
_isr_pic_slave(1);
_isr_pic_slave(2);
_isr_pic_slave(3);
_isr_pic_slave(4);
_isr_pic_slave(5);
_isr_pic_slave(6);
_isr_pic_slave(7);



//
// Define Class 4a ISRs
//
_isr_lapic(0);
_isr_lapic(1);
_isr_lapic(2);
_isr_lapic(3);
_isr_lapic(4);
_isr_lapic(5);
_isr_lapic(6);
_isr_lapic(7);
_isr_lapic(8);
_isr_lapic(9);
_isr_lapic(10);
_isr_lapic(11);
_isr_lapic(12);
_isr_lapic(13);
_isr_lapic(14);
_isr_lapic(15);



//
// Define Class 4b ISRs
//
_isr_lapic_internal(0);
_isr_lapic_internal(1);
_isr_lapic_internal(2);
_isr_lapic_internal(3);
_isr_lapic_internal(4);
_isr_lapic_internal(5);
_isr_lapic_internal(6);




//
// helper function
//
//  if from kernel mode, call _kf(n,...)
//  if from user mode,   call _uf(n,...)
//
// Note: _kf and _uf shall NOT use floats or SIMDs
//
// Stack Layout:
//    num
//    error code
//    ...
//
#  define  _handler(_name,_kmf,_kff,_uf)          \
         __asm(                                   \
         "  .text                            \n\t"\
         " " STR(_name) ":                   \n\t"\
         "  cli                              \n\t"\
         "  testb $3, 12(%esp)               \n\t"\
         "  jz 1f                            \n\t"\
         "  pushl %eax                       \n\t"\
         "  movw $16, %ax                    \n\t"\
         "  movw %ax, %ds                    \n\t"\
         "  movw %ax, %es                    \n\t"\
         "  movw $48, %ax                    \n\t"\
         "  movw %ax, %fs                    \n\t"\
         "  movw %ax, %gs                    \n\t"\
         "  popl %eax                        \n\t"\
         "  jmp    " STR(_uf) "              \n\t"\
         "1:                                 \n\t"\
         "  cmp %gs:" STR(core_offset_stackend) ", %esp\n\t"\
         "  ja     " STR(_kff) "             \n\t"\
         "  cmp %gs:" STR(core_offset_stackbegin) ", %esp\n\t"\
         "  jbe    " STR(_kff) "             \n\t"\
         "  jmp    " STR(_kmf) "             \n\t"\
         )                                        \

//
// Specialize for each classes
//
_handler(handler_critical,              kmf_critical,               kff_critical,                   uf_critical);
_handler(handler_user,                  kmf_user,                   kff_user,                       uf_user);
_handler(handler_pic_master,            kmf_pic_master,             kff_pic_master,                 uf_pic_master);
_handler(handler_pic_slave,             kmf_pic_slave,              kff_pic_slave,                  uf_pic_slave);
_handler(handler_lapic,                 kmf_lapic,                  kff_lapic,                      uf_lapic);
_handler(handler_lapic_internal,        kmf_lapic_internal,         kff_lapic_internal,             uf_lapic_internal);




//
// Operations:
//   0a. ring0_cfunc     - call C function and return back
//   0b. ring3_cfunc     - call C function and return back
//
//   1a. ring0_setflag   - ring0 set flag
//   1b. ring0_prempt    - switch to ring0 main_stack
//   1c. ring3_prempt    - switch to ring0 main_stack from ring3 but TO_RING0
//
//   2a. ring0_die       - call C function and call die
//   2b. ring3_die       - call C function and call die
//
//   3a. user_setflag    - sched act: ring3 set flag
//   3b. user_interrupt  - sched act: switch to ring3 main_stack
//


//
// call a c function
//
#  define  _ring0_cfunc(_name,_f)                 \
         __asm(                                   \
         "  .text                            \n\t"\
         " " STR(_name) ":                   \n\t"\
         "  pushl %edx                       \n\t"\
         "  pushl %ecx                       \n\t"\
         "  pushl %eax                       \n\t"\
         "  call " STR(_f) "                 \n\t"\
         "  popl  %eax                       \n\t"\
         "  popl  %ecx                       \n\t"\
         "  popl  %edx                       \n\t"\
         "  jmp iret_toring0                 \n\t"\
         )                                        \


#  define  _ring3_cfunc(_name,_f)                 \
         __asm(                                   \
         "  .text                            \n\t"\
         " " STR(_name) ":                   \n\t"\
         "  pushl %edx                       \n\t"\
         "  pushl %ecx                       \n\t"\
         "  pushl %eax                       \n\t"\
         "  call " STR(_f) "                 \n\t"\
         "  popl  %eax                       \n\t"\
         "  popl  %ecx                       \n\t"\
         "  popl  %edx                       \n\t"\
         "  jmp iret_toring3                 \n\t"\
         )                                        \




//
// preemption: To Kernel
//
// LABS: - We don't want preemption on LAPIC(keyboard press etc) 
//       - We want to force students to use Timer based preemption
//       - To motivate use of timer based preemption, we need to have atleast
//         two threads running. So that they need to be executed on round robin
//         manner to ensure fairness ie. we need to have atleast two long
//         computation fibers in our fiber_scheduler part.
//
//


//
// set a flag in core_t.
//
#  define  _ring0_setflag(_name,_f)               \
         __asm(                                   \
         "  .text                            \n\t"\
         " " STR(_name) ":                   \n\t"\
         "  pushl %edx                       \n\t"\
         "  pushl %ecx                       \n\t"\
         "  pushl %eax                       \n\t"\
         "  call " STR(_f) "                 \n\t"\
         "  popl  %eax                       \n\t"\
         "  popl  %ecx                       \n\t"\
         "  popl  %edx                       \n\t"\
         "  jmp iret_toring0                 \n\t"\
         )                                        \

//
// Preempt currently running fiber and switch to core_t::main_stack
//
// Note: set the core_t::idt_flag and mark the interrupt in core_t::idt_interrupts
//
// #  define  _ring0_preempt(_name,_f)               \

//
// Preempt currently running user mode and switch to core_t::main_stack
//
// Note: we don't have a kernel stack per each user mode programs
//       So, you can't save the state on stack.
//
// #  define  _ring3_preempt(_name,_f)               \



//
// debug
//
#  define  _ring0_die(_name,_f)                   \
         __asm(                                   \
         "  .text                            \n\t"\
         " " STR(_name) ":                   \n\t"\
         "  pushl %edx                       \n\t"\
         "  pushl %ecx                       \n\t"\
         "  pushl %eax                       \n\t"\
         "  call  die                        \n\t"\
         "  call " STR(_f) "                 \n\t"\
         "  popl  %eax                       \n\t"\
         "  popl  %ecx                       \n\t"\
         "  popl  %edx                       \n\t"\
         "  jmp iret_toring0                 \n\t"\
         )                                        \


#  define  _ring3_die(_name,_f)                   \
         __asm(                                   \
         "  .text                            \n\t"\
         " " STR(_name) ":                   \n\t"\
         "  pushl %edx                       \n\t"\
         "  pushl %ecx                       \n\t"\
         "  pushl %eax                       \n\t"\
         "  call  die                        \n\t"\
         "  call " STR(_f) "                 \n\t"\
         "  popl  %eax                       \n\t"\
         "  popl  %ecx                       \n\t"\
         "  popl  %edx                       \n\t"\
         "  jmp iret_toring3                 \n\t"\
         )                                        \




// 
// preemption: To User (scheduler activation)
//
// #  define  _user_setflag(_name,_f)                \


//#  define  _user_preempt(_name,_f)                \






//
// Specialize for each sub classes
//
_ring0_cfunc(kmf_critical, wc_critical);
_ring0_cfunc(kff_critical, wc_critical);
_ring3_cfunc(uf_critical,  wc_critical);

_ring0_cfunc(kmf_user, wc_user_ring0);
_ring0_cfunc(kff_user, wc_user_ring0);
_ring3_cfunc(uf_user,  wc_user_ring3);

_ring0_cfunc(kmf_pic_master, wc_pic_master);
_ring0_cfunc(kff_pic_master, wc_pic_master);
_ring3_cfunc(uf_pic_master,  wc_pic_master);

_ring0_cfunc(kmf_pic_slave, wc_pic_slave);
_ring0_cfunc(kff_pic_slave, wc_pic_slave);
_ring3_cfunc(uf_pic_slave,  wc_pic_slave);

_ring0_cfunc(kmf_lapic, wc_lapic);
_ring0_cfunc(kff_lapic, wc_lapic);
_ring3_cfunc(uf_lapic,  wc_lapic);

_ring0_setflag(kmf_lapic_internal, wc_lapic_internal);
_ring0_preempt(kff_lapic_internal, wc_lapic_internal);
_ring3_cfunc(uf_lapic_internal,    wc_lapic_internal);









//
// iret
//
// two paths 
// - for debugging 
// - for TAL: for type checking of these iret
//    Note: We may have to make this a macro and replicate on all paths
//
__asm(
    "  .text                            \n\t"
    " iret_toring0:                     \n\t"
    "  addl $8,%esp                     \n\t"
    "  iretl                            \n\t"
    );
__asm(
    "  .text                            \n\t"
    " iret_toring3:                     \n\t"
    "  pushl %eax                       \n\t"
    "  movw $35, %ax                    \n\t"
    "  movw %ax, %ds                    \n\t"
    "  movw %ax, %es                    \n\t"
    "  movw $0,  %ax                    \n\t"
    "  movw %ax, %fs                    \n\t"
    "  movw %ax, %gs                    \n\t"
    "  popl  %eax                       \n\t"
    "  addl $8,%esp                     \n\t"
    "  iretl                            \n\t"
    );

//
//
// The c_handler functions API has been changed
// to just take the exception number as an argument.
//
// So let's push the exception number with the help of wrapper
// since labs are already out
//
//
#  define  wrap_cfunc(_name,_f)                   \
         __asm(                                   \
         "  .text                            \n\t"\
         " " STR(_name) ":                   \n\t"\
         "  movl  16(%esp), %eax             \n\t"\
         "  pushl %eax                       \n\t"\
         "  call  " STR(_f) "                \n\t"\
         "  addl  $4, %esp                   \n\t"\
         "  retl                             \n\t"\
         )                                        \


wrap_cfunc(wc_critical      ,c_critical);
wrap_cfunc(wc_user_ring0    ,c_user_ring0);
wrap_cfunc(wc_user_ring3    ,c_user_ring3);
wrap_cfunc(wc_pic_master    ,c_pic_master);
wrap_cfunc(wc_pic_slave     ,c_pic_slave);
wrap_cfunc(wc_lapic         ,c_lapic);
wrap_cfunc(wc_lapic_internal,c_lapic_internal);


//
// C helper for Class 1 ISRs
//
__isr_helper void c_critical(int x){
  uint32_t esp;
  asm volatile ("mov %%esp,%0":"=r"(esp)::);
  hoh_debug(": inside isr critical: "<<x<<"  esp="<<esp);
}


//
// C helper for Class 2a,2b ISRs
//
__isr_helper void c_user_ring0(int x){
  uint32_t esp;
  asm volatile ("mov %%esp,%0":"=r"(esp)::);
  hoh_debug(": inside isr user ring0: "<<x<<"  esp="<<esp);
}


//
// C helper for Class 2a,2b ISRs
//
__isr_helper void c_user_ring3(int x){
  uint32_t esp;
  asm volatile ("mov %%esp,%0":"=r"(esp)::);
  hoh_debug(": inside isr user ring3: "<<x<<"  esp="<<esp);
}


//
// C helper for Class 3a ISRs
//
__isr_helper void c_pic_master(int x){
  uint32_t esp;
  asm volatile ("mov %%esp,%0":"=r"(esp)::);
  hoh_debug(": inside isr pic_master: "<<x<<"  esp="<<esp);
  //pic_dump();
  if(x==7){//spurious
    return;
  }
  pic_eoi_master();
}

//
// C helper for Class 3b ISRs
//
__isr_helper void c_pic_slave(int x){
  uint32_t esp;
  asm volatile ("mov %%esp,%0":"=r"(esp)::);
  hoh_debug(": inside isr pic_slave: "<<x<<"  esp="<<esp);
  //pic_dump();
  if(x==7){//spurious
    pic_eoi_master();
    return;
  }
  pic_eoi_slave();
}



//
// C helper for Class 4a ISRs
//
__isr_helper void c_lapic(int x){
  uint32_t esp;
  asm volatile ("mov %%esp,%0":"=r"(esp)::);
  if(x==2){
    lapic_eoi(); //spurious
    return;
  }
  hoh_debug(": inside isr lapic: "<<x<<"  esp="<<esp);
  //lapic_dump();
  lapic_eoi();
}


//
// C helper for Class 4b ISRs
//
__isr_helper void c_lapic_internal(int x){
  uint32_t esp;
  asm volatile ("mov %%esp,%0":"=r"(esp)::);
  if(x==lapic_internal_spurious){
    lapic_eoi(); //spurious
    return;
  }
  hoh_debug(": inside isr lapic_internal: "<<x<<"  esp="<<esp);
  //lapic_dump();
  lapic_eoi();
}
//
//


extern "C" void idt_reset(dev_idt32_t& idt){
  //idt[0x80].init(isr0,GDT::code*sizeof(gdt_node_t),0xee);
#define idt_set(n,f) idt.set(n,(uintptr_t)f,dev_gdt32_tss_t::code*ia32_gdt_size,0x8e)

  //
  // Class 1
  //
  idt_set(0x8,  isr_critical0);
  idt_set(0x12, isr_critical1);


  //
  // Class 2a and 2b
  //
  idt_set(0x0,  isr_user0);
  idt_set(0x1,  isr_user1);
  idt_set(0x2,  isr_user2);
  idt_set(0x3,  isr_user3);
  idt_set(0x4,  isr_user4);
  idt_set(0x5,  isr_user5);
  idt_set(0x6,  isr_user6);
  idt_set(0x7,  isr_user7);
  // 8 is class 1a
  idt_set(0x9,  isr_user9);
  idt_set(0xa,  isr_user10);
  idt_set(0xb,  isr_user11);
  idt_set(0xc,  isr_user12);
  idt_set(0xd,  isr_user13);
  idt_set(0xe,  isr_user14);
  idt_set(0xf,  isr_user15);
  idt_set(0x10, isr_user16);
  idt_set(0x11, isr_user17);
  // 18 is Class 1b
  idt_set(0x13, isr_user19);


  //
  // Class 3a
  //
  idt_set(pic_master_base+0x0, isr_pic_master0);
  idt_set(pic_master_base+0x1, isr_pic_master1);
  idt_set(pic_master_base+0x2, isr_pic_master2);
  idt_set(pic_master_base+0x3, isr_pic_master3);
  idt_set(pic_master_base+0x4, isr_pic_master4);
  idt_set(pic_master_base+0x5, isr_pic_master5);
  idt_set(pic_master_base+0x6, isr_pic_master6);
  idt_set(pic_master_base+0x7, isr_pic_master7);

  //
  // Class 3b
  //
  idt_set(pic_slave_base+0x8, isr_pic_slave0);
  idt_set(pic_slave_base+0x9, isr_pic_slave1);
  idt_set(pic_slave_base+0xa, isr_pic_slave2);
  idt_set(pic_slave_base+0xb, isr_pic_slave3);
  idt_set(pic_slave_base+0xc, isr_pic_slave4);
  idt_set(pic_slave_base+0xd, isr_pic_slave5);
  idt_set(pic_slave_base+0xe, isr_pic_slave6);
  idt_set(pic_slave_base+0xf, isr_pic_slave7);


  //
  // Class 4a
  //
  idt_set(lapic_base+0x0, isr_lapic0);
  idt_set(lapic_base+0x1, isr_lapic1);
  idt_set(lapic_base+0x2, isr_lapic2);
  idt_set(lapic_base+0x3, isr_lapic3);
  idt_set(lapic_base+0x4, isr_lapic4);
  idt_set(lapic_base+0x5, isr_lapic5);
  idt_set(lapic_base+0x6, isr_lapic6);
  idt_set(lapic_base+0x7, isr_lapic7);
  idt_set(lapic_base+0x8, isr_lapic8);
  idt_set(lapic_base+0x9, isr_lapic9);
  idt_set(lapic_base+0xa, isr_lapic10);
  idt_set(lapic_base+0xb, isr_lapic11);
  idt_set(lapic_base+0xc, isr_lapic12);
  idt_set(lapic_base+0xd, isr_lapic13);
  idt_set(lapic_base+0xe, isr_lapic14);
  idt_set(lapic_base+0xf, isr_lapic15);


  //
  // Class 4b
  //
  idt_set(lapic_internal_base+0x0, isr_lapic_internal0);
  idt_set(lapic_internal_base+0x1, isr_lapic_internal1);
  idt_set(lapic_internal_base+0x2, isr_lapic_internal2);
  idt_set(lapic_internal_base+0x3, isr_lapic_internal3);
  idt_set(lapic_internal_base+0x4, isr_lapic_internal4);
  idt_set(lapic_internal_base+0x5, isr_lapic_internal5);
  idt_set(lapic_internal_base+0x6, isr_lapic_internal6);

#undef idt_set
}






//
// helper functions for assembly routines: interrupt hanlders
//
// guaranteed not to use floats/simds
//

static inline core_t& get_core(){
  core_t* p=0;
  asm ("movl %%gs:0x0, %0":"=r"(p));
  hoh_assert(p==p->self && p->magic==0xface600d,"XXX");
  return *p;
}
static inline dev_lapic_t& get_lapic(){
  return get_core().hal.lapic;
}
static inline dev_lpc_pic_t& get_pic(){
  return get_core().hal.pic;
}


extern "C" void lapic_eoi(){
  dev_lapic_t& lapic=get_lapic();
  lapic.eoi();
}

extern "C" void pic_eoi_master(){
  dev_lpc_pic_t& pic=get_pic();
  pic.eoi_master();
}

extern "C" void pic_eoi_slave(){
  dev_lpc_pic_t& pic=get_pic();
  pic.eoi_slave();
}



//
//
// helper functions for assembly routines: boot loader
//
// guaranteed not to use floats/simds
//
extern "C" void hoh_debug_string(const char* s){
  hoh_debug(s);
}

extern "C" void hoh_debug_uint32(uint32_t x){
  hoh_debug(x);
}


extern "C" void fpu_simd_reset(){
  dev_ia32_t ia32;
  ia32.fpu_simd_reset();

}

