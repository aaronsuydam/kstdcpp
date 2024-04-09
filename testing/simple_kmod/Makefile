# The name of your kernel module
obj-m += simple_kmod.o
simple_kmod-objs := helper.o 

KERNELDIR := /lib/modules/$(shell uname -r)/build

# Source files for your C++ library
CPP_SOURCES := helper.cpp
CPP_OBJECTS := $(CPP_SOURCES:.cpp=.o)
CXXFLAGS := -Wall -Wextra -std=c++20 -nostdlib -fno-exceptions -fno-rtti -fno-builtin -ffreestanding -fpermissive

srctree = $(KERNELDIR)
objtree = $(pwd)

LINUXINCLUDE    := \
                -I$(srctree)/arch/x86/include \
                -I$(objtree)/arch/x86/include/generated \
                -I$(srctree)/include \
                -I$(objtree)/include \
                $(USERINCLUDE)

C_SOURCES := simple_kmod.c
C_OBJECTS := $(C_SOURCES:.c=.o)
C_FLAGS := $(LINUXINCLUDE) $(KBUILD_CFLAGS)


# Use g++ as the compiler for C++ files
CXX := g++
CC := gcc
# Rule to compile C++ files
$(CPP_OBJECTS): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to compile C++ files
$(C_OBJECTS): %.o: %.c
	$(CC) $(C_FLAGS) -c $< -o $@

# Custom target for C++ compilation
cpp-objs: $(CPP_OBJECTS)
c-objs: $(C_OBJECTS)

# Default make command
all: cpp-objs c-objs
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

# Clean command
clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean

dummy:
	@echo "KBUILD_CFLAGS = $(KBUILD_CFLAGS)"
	@echo "LINUXINCLUDE = $(LINUXINCLUDE)"