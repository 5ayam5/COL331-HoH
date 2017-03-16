#define MB_FLAGS                (1|2)
#define STACK_SIZE              0x300
#define MULTIBOOT_HEADER_MAGIC  0x1BADB002
#define OP_ADDR16               0x66
#define OP_JMP                  0xea
#define LOWPC_RELATIVE(x,y)     leal (x-g_ia32_start16)(%edi),y
#define PC_RELATIVE(x,y)        leal (x-g_ia32_start16)(%ebx),y
#define UNPC_RELATIVE(x,y)      leal (g_ia32_start16-x)(%ebx),y


.text
.globl start, _start
.globl g_ia32_start16, g_ia32_end16, g_ia32_data16


#
#################################################################
# LAPIC BOOT START
#################################################################
#

.align  64   # highest of all alignment
.code16
g_ia32_start16:
   jmp boot16

.align  4
multiboot_header:
   .long   MULTIBOOT_HEADER_MAGIC
   .long   MB_FLAGS
   .long   -(MULTIBOOT_HEADER_MAGIC + MB_FLAGS)
.align 16
g_ia32_data16:
s_pooltmp:
   .zero 512
s_rank:
   .long   0
s_mastermsg:
   .long   0
s_sharedmsg:
   .long   0
.align 16
s_pooltmp2:
   .zero 512
#end


s_pcore:
   .long 0
s_pstack:
   .long 0

boot16:
   cli
   cld

   # real mode.  make sure DS is zero.
   xorw %ax, %ax
   movw %ax, %ds
   movw %ax, %es
   movw %ax, %ss

   #
   # make sure we readjust %ebx
   # - starting location will be CS*16
   #
   xorl %edi, %edi
   movw %cs,  %di
   shl  $4,   %di

   LOWPC_RELATIVE(tmp_stackbottom, %esp)
   #pushl $0
   #popf

   #
   #self patching code
   #
   LOWPC_RELATIVE(spatch0, %esi)
   addl %edi, (%esi) # patch with edi not ebx
   LOWPC_RELATIVE(spatch1, %esi)
   addl %edi, (%esi)
   LOWPC_RELATIVE(spatch2, %esi)
   addl %edi, (%esi)



   # load gdt. and switch to 32 bit mode
   LOWPC_RELATIVE(gdtdesc_slave, %esi)
   lgdtl (%esi)
   movl %cr0, %eax
   orl  $1,   %eax
   movl %eax, %cr0
   .byte OP_ADDR16
   .byte OP_JMP
spatch0:
   .long boot32 - g_ia32_start16
   .word (1<<3)


.code32
boot32:
   # load Kernel Data segment
   movl $(2<<3), %eax
   movw %ax, %ds
   movw %ax, %es
   movw %ax, %ss
   xorw %ax, %ax
   movw %ax, %fs
   movw %ax, %gs
   .byte OP_JMP
spatch1:
   .long 1f - g_ia32_start16
   .word (1<<3)
1:
   nop

   # load stack, clear flags
   movl $0, %ebp
   LOWPC_RELATIVE(tmp_stackbottom, %esp)

   pushl $0
   popf

   # make sure we readjust %ebx
   movl $g_ia32_start16, %ebx            # TODO: pass the load address as arg

   LOWPC_RELATIVE(lapic_message, %esi)
   pushl %esi
   PC_RELATIVE(hoh_debug_string, %esi)   # first PC_RELATIVE
   call  *%esi
   addl $4, %esp

   #enable fpu and simd
   PC_RELATIVE(fpu_simd_reset, %esi)
   call  *%esi

   # initialize mem
   LOWPC_RELATIVE(s_pcore, %esi)
   pushl %esi           # core pointer
   LOWPC_RELATIVE(s_pstack, %esi)
   pushl %esi           # stack pointer
   LOWPC_RELATIVE(s_pooltmp2, %esi)
   pushl %esi           # s_pooltmp2 pointer
   LOWPC_RELATIVE(s_pooltmp, %esi)
   pushl %esi           # s_pooltmp pointer
   LOWPC_RELATIVE(s_sharedmsg, %esi)
   pushl (%esi)         # sharedmsg
   LOWPC_RELATIVE(s_mastermsg, %esi)
   pushl (%esi)         # mastermsg
   LOWPC_RELATIVE(s_rank, %esi)
   pushl (%esi)         # rank

   PC_RELATIVE(core_mem_init, %esi)
   call  *%esi
   addl  $28, %esp


   LOWPC_RELATIVE(s_pstack, %esi)
   movl (%esi), %esp    #stack
   movl $0, %ebp

   #reset core

   LOWPC_RELATIVE(s_pcore, %esi)
   pushl (%esi)            # core
   LOWPC_RELATIVE(s_rank, %esi)
   pushl (%esi)            # rank

   #we couldve release boot loader data structure: we need to save core
   #(gdt is also fine accord to x86)

   PC_RELATIVE(core_reset, %esi)
   call  *%esi

   # Let's reuse stack: NO addl  $8, %esp

   # boot loader rw data structure not available beyond this point

   #core: main loop
   # Let's reuse stack
   PC_RELATIVE(core_loop, %esi)
   call  *%esi
   addl  $8, %esp


   #core_boot returned!: disable interrupt and enter infinite loop
   PC_RELATIVE(halt_message, %esi)
   pushl (%esi)
   PC_RELATIVE(hoh_debug_string, %esi)
   call  *%esi
   addl  $4, %esp

   cli
   jmp loop

 #
 #################################################################
 #  MULTIBOOT START
 #################################################################
 #


#
# Asimdmbly code to call C function
#
# Steps:
#
#  1. When an OS is booted, stack is not set
#     so we need to set stack
#  2. We need to clear the FLAGS register to a known value
#  3. we can call any C function
#  4. Incase by mistake if that C function returned, enter infinite loop
#
#  That's it.
#
#



.align  16
.code32
start:
_start:

   # save args eax and ebx in other regs
   movl %ebx, %edi

   #rely on grub2 stack for a moment - we need to compute PC
   # make sure we readjust %ebx
   call 1f
1:
   popl %ebx
   UNPC_RELATIVE(1b, %ebx)

   #
   #self patching code
   #
   PC_RELATIVE(mpatch1, %esi)
   addl %ebx, (%esi)
   PC_RELATIVE(mpatch2, %esi)
   addl %ebx, (%esi)


   # load gdt and kernel data segment
   PC_RELATIVE(gdtdesc_master, %esi)
   lgdtl (%esi)
   movw $(2<<3), %cx
   movw %cx, %ds
   movw %cx, %es
   movw %cx, %ss
   xorw %cx, %cx
   movw %cx, %fs
   movw %cx, %gs

   .byte OP_JMP
mpatch1:
   .long 1f - g_ia32_start16
   .word (1<<3)

1:
   nop

   #set stack
   movl $0, %ebp
   PC_RELATIVE(tmp_stackbottom, %esp)

   #clear flags
   pushl $0
   popf

   #enable fpu and simd
   pushl %eax
   PC_RELATIVE(fpu_simd_reset, %esi)
   call *%esi
   popl  %eax

   # initialize pooltmp
   PC_RELATIVE(s_pooltmp, %esi)
   pushl %esi          # s_pooltmp
   PC_RELATIVE(s_sharedmsg, %esi)
   pushl %esi          # s_sharedmsg
   pushl %edi          # multiboot
   pushl %eax          # magic
   PC_RELATIVE(core_master_init, %esi)
   call  *%esi
   addl  $16, %esp

   # initialize mem
   PC_RELATIVE(s_pcore, %esi)
   pushl %esi           # core pointer
   PC_RELATIVE(s_pstack, %esi)
   pushl %esi           # stack pointer
   PC_RELATIVE(s_pooltmp2, %esi)
   pushl %esi           # s_pooltmp2 pointer
   PC_RELATIVE(s_pooltmp, %esi)
   pushl %esi           # s_pooltmp pointer
   PC_RELATIVE(s_sharedmsg, %esi)
   pushl (%esi)         # sharedmsg
   pushl $0             # mastermsg
   pushl $0             # rank

   PC_RELATIVE(core_mem_init, %esi)
   call  *%esi
   addl  $28, %esp


   #set real stack
   PC_RELATIVE(s_pstack, %esi)
   movl (%esi), %esp    #stack
   movl $0, %ebp

   #reset core
   PC_RELATIVE(s_pcore, %esi)
   pushl (%esi)           # core
   pushl $0               # rank
   PC_RELATIVE(core_reset, %esi)
   call  *%esi
   addl  $8, %esp

   #core: main loop
   PC_RELATIVE(s_pcore, %esi)
   pushl (%esi)           # core
   pushl $0               # rank
   PC_RELATIVE(core_loop, %esi)
   call  *%esi
   addl  $8, %esp

   #core_boot returned!: disable interrupt and enter infinite loop
   PC_RELATIVE(halt_message, %esi)
   pushl (%esi)
   PC_RELATIVE(hoh_debug_string, %esi)
   call  *%esi
   addl  $4, %esp

   cli
loop:
   hlt
   jmp   loop


lapic_message:
   .asciz  "remote core booting"
halt_message:
   .asciz  "System halted."

.align 16
gdt:
   .byte 0,0,0,0,0,0,0,0
   .byte 0xff,0xff,0,0,0,0x9a,(0xc0|0xf),0
   .byte 0xff,0xff,0,0,0,0x93,(0xc0|0xf),0

.align 16
gdtdesc_master:
   .word (3*8-1)
mpatch2:
   .long (gdt-g_ia32_start16)
   .word 0
gdtdesc_slave:
   .word (3*8-1)
spatch2:
   .long (gdt-g_ia32_start16)
   .word 0


#STACK
   .zero STACK_SIZE
.align 64
tmp_stackbottom:
   .zero 32

g_ia32_end16:

