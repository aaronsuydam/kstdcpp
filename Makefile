# The name of your static library
LIB_NAME := libkstdcpp.a

# Compiler and archiver
CXX := g++
AR := ar

# Include paths, add more with -I if needed
INCLUDES := -I/usr/src/linux-headers-6.2.0-39-generic/include

# Compiler flags
# -fno-exceptions and -fno-rtti are important for kernel space
CXXFLAGS := -Wall -Wextra -fnostdlib -fno-exceptions -fno-rtti -g $(INCLUDES)

# Source files
SOURCES := $(wildcard *.cpp)

# Object files
OBJECTS := $(SOURCES:.cpp=.o)

# Targets
.PHONY: all clean

all: $(LIB_NAME)

$(LIB_NAME): $(OBJECTS)
	$(AR) rcs $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(LIB_NAME)