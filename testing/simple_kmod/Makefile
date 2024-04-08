# The name of your kernel module
obj-m += simple_kmod.o $(CPP_OBJECTS)

KERNELDIR := /lib/modules/$(shell uname -r)/build

# Source files for your C++ library
CPP_SOURCES := helper.cpp
CPP_OBJECTS := $(CPP_SOURCES:.cpp=.o)
CXXFLAGS := -Wall -Wextra -std=c++20 -nostdlib -fno-exceptions -fno-rtti

# Use g++ as the compiler for C++ files
CXX := g++



# Rule to compile C++ files
$(CPP_OBJECTS): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Custom target for C++ compilation
cpp-objs: $(CPP_OBJECTS)

# Default make command
all: 
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

# Clean command
clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean