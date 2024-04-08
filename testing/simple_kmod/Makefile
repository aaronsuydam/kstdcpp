# The name of your kernel module
obj-m += simple_kmod.o
simple_kmod-objs := helper.o 

KERNELDIR := /lib/modules/$(shell uname -r)/build

# Source files for your C++ library
CPP_SOURCES := helper.cpp
CPP_OBJECTS := $(CPP_SOURCES:.cpp=.o)
CXXFLAGS := -Wall -Wextra -std=c++20 -nostdlib -fno-exceptions -fno-rtti -fno-builtin -ffreestanding -fpermissive

# Use g++ as the compiler for C++ files
CXX := g++

# Rule to compile C++ files
$(CPP_OBJECTS): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Custom target for C++ compilation
cpp-objs: $(CPP_OBJECTS)

# Default make command
all: cpp-objs
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

# Clean command
clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean