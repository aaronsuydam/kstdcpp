# The name of your kernel module
MODULE_NAME := complex_kmod
$(MODULE_NAME)-y := $(MODULE_NAME)combined.o

KERNELDIR := /lib/modules/$(shell uname -r)/build

srctree = $(KERNELDIR)
objtree = $(pwd)

LINUXINCLUDE    := \
                -I$(srctree)/arch/x86/include \
				-I$(srctree)/arch/x86/include/generated \
				-I$(srctree)/arch/x86/include/uapi \
				-I$(srctree)/arch/x86/include/generated/uapi \
				-I$(objtree)/arch/x86/include/generated \
                -I$(srctree)/include \
				-I$(srctree)/include/uapi \
				-I$(srctree)/include/generated/uapi \
                -I$(objtree)/include \
				-include $(srctree)/include/linux/compiler-version.h \
				-include $(srctree)/include/linux/kconfig.h \
				-I$(srctree)/ubuntu/include \
				-include $(srctree)/include/linux/compiler_types.h
                $(USERINCLUDE)



KBUILD_CFLAGS := -D__KERNEL__ -fmacro-prefix-map=./= -std=gnu11
KBUILD_CFLAGS += -fshort-wchar -funsigned-char -fno-common -fno-PIE -fno-strict-aliasing -Wall -Wundef 
KBUILD_CFLAGS += -Werror=implicit-function-declaration -Werror=implicit-int -Werror=return-type -Werror=strict-prototypes
KBUILD_CFLAGS += -Wno-format-security -Wno-trigraphs -mno-sse -mno-mmx -mno-sse2 -mno-3dnow -mno-avx -fcf-protection=none 
KBUILD_CFLAGS += -m64 -falign-jumps=1 -falign-loops=1 -mno-80387 -mno-fp-ret-in-387 -mpreferred-stack-boundary=3
KBUILD_CFLAGS += -mskip-rax-setup -mtune=generic -mno-red-zone -mcmodel=kernel -Wno-sign-compare
KBUILD_CFLAGS += -fno-asynchronous-unwind-tables -mindirect-branch=thunk-extern -mindirect-branch-register
KBUILD_CFLAGS += -mindirect-branch-cs-prefix -mfunction-return=thunk-extern -fno-jump-tables -mharden-sls=all
KBUILD_CFLAGS += -fpatchable-function-entry=16,16 -fno-delete-null-pointer-checks -Wno-frame-address -Wno-format-truncation
KBUILD_CFLAGS += -Wno-format-overflow -Wno-address-of-packed-member -O2 -fno-allow-store-data-races -Wframe-larger-than=1024
KBUILD_CFLAGS += -fstack-protector-strong -Wno-main -Wno-unused-but-set-variable -Wno-unused-const-variable
KBUILD_CFLAGS += -Wno-dangling-pointer -fno-omit-frame-pointer -fno-optimize-sibling-calls -ftrivial-auto-var-init=zero
KBUILD_CFLAGS += -fno-stack-clash-protection -fzero-call-used-regs=used-gpr -pg -mrecord-mcount -mfentry -DCC_USING_FENTRY
KBUILD_CFLAGS += -falign-functions=16 -Wvla -Wno-pointer-sign -Wcast-function-type -fstrict-flex-arrays=3
KBUILD_CFLAGS += -Wno-stringop-truncation -Wno-stringop-overflow -Wno-restrict -Wno-maybe-uninitialized
KBUILD_CFLAGS += -Wno-array-bounds -Wno-alloc-size-larger-than -Wimplicit-fallthrough=5 -fno-strict-overflow
KBUILD_CFLAGS += -fno-stack-check -fconserve-stack -Werror=date-time -Werror=incompatible-pointer-types
KBUILD_CFLAGS += -Werror=designated-init -Wno-packed-not-aligned -g -gdwarf-5  -fsanitize=bounds-strict
KBUILD_CFLAGS += -fsanitize=shift -fsanitize=bool -fsanitize=enum  -DMODULE  -DKBUILD_BASENAME='"complex_kmod"'
KBUILD_CFLAGS += -DKBUILD_MODNAME='"complex_kmod"' -D__KBUILD_MODNAME=kmod_complex_kmod

KSTD_CPP_SRCDIR = /home/aaron-suydam/dev/kstdcpp/src/
MODULE_SRCDIR = /home/aaron-suydam/dev/kstdcpp/testing/complex_kmod/

# Source files for your C++ library
CPP_SOURCES := $(MODULE_SRCDIR)/helper.cpp $(KSTD_CPP_SRCDIR)/new.cpp
CPP_OBJECTS := $(CPP_SOURCES:.cpp=.o)
CXXFLAGS := -Wall -Wextra -std=c++20 -nostdlib -fno-exceptions -fno-rtti -fno-builtin -ffreestanding -fpermissive


C_SOURCES := complex_kmod.c $(KSTD_CPP_SRCDIR)/kmem.c
C_OBJECTS := $(C_SOURCES:.c=.o)
C_FLAGS := $(LINUXINCLUDE) $(KBUILD_CFLAGS)


# Use g++ as the compiler for C++ files
CXX := g++
CC := gcc
# Rule to compile C++ files
$(CPP_OBJECTS): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	echo '# Dummy cpp cmd file' > $@.cmd

# Rule to compile C++ files
$(C_OBJECTS): %.o: %.c
	$(CC) $(C_FLAGS) -c $< -o $@
	echo '# Dummy c cmd file' > $@.cmd

# Custom target for C++ compilation
cpp-objs: $(CPP_OBJECTS)
c-objs: $(C_OBJECTS)


# Path to modpost utility - adjust as needed
MODPOST := $(KERNELDIR)/scripts/mod/modpost

# Combine C and C++ object files into a single object file
$(MODULE_NAME)combined.o: $(C_OBJECTS) $(CPP_OBJECTS)
	$(LD) -r -o $@ $^
	echo '# Dummy cmd file' > .$@.cmd

# Use the kernel build system to create the .ko file from the combined object file
$(MODULE_NAME).ko: $(MODULE_NAME)combined.o
	$(MAKE) -C $(KERNELDIR) M=$(PWD) $(MODULE_NAME)combined.ko
# $(MODPOST) -o $(MODULE_NAME).mod.c -N  # Generating .mod.c
# $(CC) -c $(MODULE_NAME).mod.c -o $(MODULE_NAME).mod.o  # Compiling .mod.c to .mod.o
# $(LD) -r -o $(MODULE_NAME).ko $(MODULE_NAME)combined.o $(MODULE_NAME).mod.o  # Linking to create .ko

all: $(MODULE_NAME).ko


clean:
	rm -f *.o *.ko *.mod.c .*.cmd Module.symvers modules.order *.o.cmd *.mod
	cd $(KSTD_CPP_SRCDIR) && rm -f *.o *.ko *.mod.c .*.cmd *.o.cmd Module.symvers modules.order *.mod

dummy:
	@echo "KBUILD_CFLAGS = $(KBUILD_CFLAGS)"
	@echo "LINUXINCLUDE = $(LINUXINCLUDE)"