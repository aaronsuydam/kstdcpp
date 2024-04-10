// SPDX-License-Identifier: GPL-2.0 OR MIT
#define size_t long unsigned int
#include "helper.h"
#include "../../include/new.hpp"

// const char my_metadata[] __attribute__((section(".modinfo"))) = "Version=1.0.0 Author=John Doe license=GPL";

void* some_kernel_memory = nullptr;

size_t cpp_initialization()
{
    some_kernel_memory = new char[20];
    if(some_kernel_memory == nullptr)
    {
        return 1;
    }
    return 0;
}

size_t cpp_destruction()
{
    delete(some_kernel_memory);
    return 0;
}