# The name of your C++ library module
obj-m += kstdcpp.o

# Source files for your C++ library
# Assuming 'new.cpp' is located under a 'src' directory.
KSTD_CPP_SOURCES := src/new.cpp

# Convert your .cpp files to .o object files to be included in kstdcpp-objs
kstdcpp-objs := $(KSTD_CPP_SOURCES:.cpp=.o)

# Path to the kernel source
KERNELDIR ?= /lib/modules/$(shell uname -r)/build

# Use g++ as the compiler for C++ files
CXX := g++
# Global C++ compile flags
GLOBAL_CXXFLAGS := -std=gnu++17 $(LINUXINCLUDE)  -nostdlib -fno-exceptions -fno-rtti

# Rule to compile C++ source files
$(src)/%.o: $(src)/%.cpp
	$(CXX) $(GLOBAL_CXXFLAGS) -c $< -o $@

# Default make command
all:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

# Clean command
clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean
