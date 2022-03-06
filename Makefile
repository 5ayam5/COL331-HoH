M=./make
include $M/header.mk

I           =.#
O           =$I/_tmp#
TYPE        =exe#
NAME        =hoh#
ARCH        =linux#
B           =release#



SOURCES     = \
              $I/x86/boot.S   \
              $I/x86/main.cc  \
              $I/x86/except.cc  \
              $I/util/debug.cc  \
              $I/util/lib.cc  \
              $I/apps/labs.cc  \
              $I/labs/shell.cc  \
              $I/labs/coroutine.cc  \
              $I/labs/fiber.cc  \
              $I/labs/fiber_scheduler.cc  \

ISO_SOURCES = \
              $O/iso/boot/$(NAME).exe   \
              $O/iso/boot/grub/grub.cfg \


CPPFLAGS    = -I$I -I$I/apps
TARGET_MACH = -m32
TARGET_ARCH = -m32

#options for B=debug
CXXFLAGS.debug=-g
ASFLAGS.debug=-g
#options for B=release
CXXFLAGS.release=-O3

WARNINGS = -Wall -Wextra -pedantic -Wshadow -Wpointer-arith -Wcast-align \
  -Wwrite-strings  -Wmissing-declarations \
  -Wredundant-decls  -Winline -Wno-long-long \
  -Wuninitialized -Wconversion 

WARNINGS=

#-Wmissing-prototypes -Wnested-externs -Wstrict-prototypes

NO_SIMD=-mno-mmx -mno-sse -mno-sse2 -mno-sse3 -mno-sse4 -mno-avx -mno-3dnow 


CXXFLAGS    = -std=c++0x \
              $(WARNINGS) \
              -ffreestanding -fno-rtti -fno-exceptions \
              -fstrength-reduce -fomit-frame-pointer -finline-functions \
              -mno-red-zone \
              -z max-page-size=0x1000    \

#options specific for except.cc
CXXFLAGS.x86/except.cc = $(NO_SIMD)
CXXFLAGS.util/lib.cc   = $(NO_SIMD) -fno-tree-loop-distribute-patterns

# simd
CXXFLAGS.x86/main.cc             = -msse -msse2 -mfpmath=sse
CXXFLAGS.apps/labs.cc            = -msse -msse2 -mfpmath=sse
CXXFLAGS.labs/shell.cc           = -msse -msse2 -mfpmath=sse
CXXFLAGS.labs/coroutine.cc       = -msse -msse2 -mfpmath=sse
CXXFLAGS.labs/fiber.cc           = -msse -msse2 -mfpmath=sse
CXXFLAGS.labs/fiber_scheduler.cc = -msse -msse2 -mfpmath=sse


LINK.script = $I/make/util/linker.t
LDFLAGS     = -static -T $(LINK.script) \
              -nostdlib -nodefaultlibs -nostartfiles \
              -z max-page-size=0x1000 \


QEMU=qemu-system-i386
#QEMU = ~/X/qemu.git/i386-softmmu/qemu-system-i386 
QEMUFLAGS = -cpu Haswell -smp 2 -m 1024 
QEMULOG= -D qemu.log -d in_asm,int

all:: exe

qemu:: iso
	$(QEMU) $(QEMUFLAGS) $(QEMULOG) -serial stdio -serial null -cdrom $O/$(NAME).iso

qemu-gdb:: iso
	$(QEMU) $(QEMUFLAGS) -S -s -serial stdio  -serial null -cdrom $O/$(NAME).iso 

qemu-direct:: exe
	$(QEMU) $(QEMUFLAGS) $(QEMULOG) -serial stdio -serial null -kernel $O/$(NAME).exe -append "/help" 

qemu-gdb-direct:: exe
	$(QEMU) $(QEMUFLAGS) -S -s -serial stdio  -serial null -kernel $O/$(NAME).exe -append "/help"

iso:: $O/$(NAME).iso



$O/$(NAME).iso: $(ISO_SOURCES) 
	grub-mkrescue -o $@ $O/iso

$O/iso/boot/$(NAME).exe: exe
	mkdir -p $O/iso/boot
	cp $O/$(NAME).exe $@

$O/iso/boot/grub/grub.cfg: $I/make/util/grub.cfg
	mkdir -p $O/iso/boot/grub
	cp $< $@


include $M/footer.mk
