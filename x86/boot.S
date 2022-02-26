#define MB_FLAGS                (1|2)
#define STACK_SIZE              0x300
#define MULTIBOOT_HEADER_MAGIC  0x1BADB002
#define OP_ADDR16               0x66
#define OP_JMP                  0xea
#define PC_RELATIVE(x,y)        leal (x-g_ia32_start16)(%ebx),y


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
s_mymsg:
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

   # real mode.  make sure DS is zero.
   xorw %ax, %ax
   movw %ax, %ds
   movw %ax, %es
   movw %ax, %ss


   #
   #self patching code
   # - starting location will be CS*16
   #
   xorl %ebx, %ebx
   movw %cs,  %bx
   shl  $4,   %bx
   PC_RELATIVE(patch1, %esi)
   addl %ebx, (%esi)
   PC_RELATIVE(patch2, %esi)
   addl %ebx, (%esi)
   PC_RELATIVE(patch3, %esi)
   addl %ebx, (%esi)



   # load gdt. and switch to 32 bit mode
   PC_RELATIVE(gdtdesc_slave, %esi)
   lgdtl (%esi)
   movl %cr0, %eax
   orl  $1,   %eax
   movl %eax, %cr0
   .byte OP_ADDR16
   .byte OP_JMP
patch1:
   .long boot32 - g_ia32_start16
   .word (1<<3)


.code32
boot32:
   # load Kernel Data segment
   movw $(2<<3), %ax
   movw %ax, %ds
   movw %ax, %es
   movw %ax, %ss
   xorw %ax, %ax
   movw %ax, %fs
   movw %ax, %gs
   .byte OP_JMP
patch2:
   .long 1f - g_ia32_start16
   .word (1<<3)
1:
   nop

   # load stack, clear flags
   movl $0, %ebp
   PC_RELATIVE(tmp_stackbottom, %esp)

   pushl $0
   popf

   PC_RELATIVE(lapic_message, %esi)
   pushl %esi
   movl $(hoh_debug_string), %esi
   call  *%esi
   addl $4, %esp


   #enable fpu and simd
   movl  $fpu_simd_reset, %esi
   call  *%esi

   # initialize mem
   PC_RELATIVE(s_pcore, %esi)
   pushl %esi           # core pointer
   PC_RELATIVE(s_pstack, %esi)
   pushl %esi           # stack pointer
   PC_RELATIVE(s_pooltmp2, %esi)
   pushl %esi           # s_pooltmp2 pointer
   PC_RELATIVE(s_pooltmp, %esi)
   pushl %esi           # s_pooltmp pointer
   PC_RELATIVE(s_mymsg, %esi)
   pushl (%esi)         # mymsg
   PC_RELATIVE(s_mastermsg, %esi)
   pushl (%esi)         # mastermsg
   PC_RELATIVE(s_rank, %esi)
   pushl (%esi)         # rank

   # from now onwards, don't use PC_RELATIVE -- ebx cleared
   movl  $core_mem_init, %esi
   call  *%esi
   addl  $28, %esp


   PC_RELATIVE(s_pstack, %esi)
   movl (%esi), %esp    #stack
   movl $0, %ebp

   #reset core
   PC_RELATIVE(s_pcore, %esi)
   pushl (%esi)           # core
   pushl $0               # rank
   movl  $core_reset, %esi
   call  *%esi
   addl  $8, %esp

   #core: main loop
   PC_RELATIVE(s_pcore, %esi)
   pushl (%esi)           # core
   pushl $0               # rank
   movl  $core_loop, %esi
   call  *%esi
   addl  $8, %esp


   # should never reach
   pushl $halt_message
   movl $(hoh_debug_string), %esi
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
   # load gdt and kernel data segment
   lgdtl gdtdesc_master
   movw $(2<<3), %cx
   movw %cx, %ds
   movw %cx, %es
   movw %cx, %ss
   xorw %cx, %cx
   movw %cx, %fs
   movw %cx, %gs
   ljmp $(1<<3), $1f
1:
   nop

   #set stack
   movl $0, %ebp
   movl  $tmp_stackbottom, %esp

   #clear flags
   pushl $0
   popf

   #enable fpu and simd
   pushl %eax
   call  fpu_simd_reset
   popl  %eax

   # initialize pooltmp
   pushl $s_pooltmp
   pushl $s_mymsg
   pushl %ebx   # multiboot
   pushl %eax   # magic
   call  core_master_init
   addl  $16, %esp

   # initialize mem
   pushl $(s_pcore)     # core pointer
   pushl $(s_pstack)    # stack pointer
   pushl $(s_pooltmp2)  # pooltmp2 pointer
   pushl $(s_pooltmp)   # pooltmp  pointer
   pushl s_mymsg        # mymesg
   pushl $0             # mastermsg
   pushl $0             # rank
   call  core_mem_init
   addl  $28, %esp


   #set real stack
   movl $0, %ebp
   movl s_pstack, %esp    #stack

   #reset core
   pushl s_pcore
   pushl $0             # rank
   call  core_reset
   addl  $8, %esp

   #core: main loop
   pushl s_pcore
   pushl $0             # rank
   call  core_loop
   addl  $8, %esp

   #core_boot returned!: disable interrupt and enter infinite loop
   pushl $halt_message
   call  hoh_debug_string
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
   .byte 0xff,0xff,0,0,0,(0x90|(8|2)),(0xc0|0xf),0
   .byte 0xff,0xff,0,0,0,(0x90|(2|1)),(0xc0|0xf),0
gdtdesc_master:
   .word (3*8-1)
   .long gdt
   .word 0
gdtdesc_slave:
   .word (3*8-1)
patch3:
   .long (gdt-g_ia32_start16)
   .word 0


#STACK
   .zero STACK_SIZE
.align 64
tmp_stackbottom:
   .zero 32

g_ia32_end16:

