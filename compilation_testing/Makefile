# Kernel module parts
obj-m := your_module.o

KERNEL_DIR := /lib/modules/$(shell uname -r)/build
KERNEL_INCLUDE := -I$(KERNEL_DIR)/arch/x86/include -I$(KERNEL_DIR)/arch/x86/include/generated  -I$(KERNEL_DIR)/include -I$(KERNEL_DIR)/ubuntu/include

# C++ parts - Specify your C++ source files here
CPP_SOURCES := test.cpp
CPP_OBJECTS := $(CPP_SOURCES:.cpp=.o)
CPP_FLAGS := -Wall -Wextra -nostdlib -fno-exceptions -fno-rtti 



# Rule to compile C++ files
$(CPP_OBJECTS): %.o: %.cpp
	$(CXX) $(CPP_FLAGS) -c $< -o $@

# Custom target for C++ compilation
cpp-objs: $(CPP_OBJECTS)

# Include Linux Kernel's build system Makefile
all:
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	rm -f $(CPP_OBJECTS)

# Tell the kernel build system about your C++ object files
your_module-objs := $(CPP_OBJECTS) other_module_parts.o
