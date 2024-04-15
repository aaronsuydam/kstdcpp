// SPDX-License-Identifier: GPL-2.0 OR MIT
#define size_t long unsigned int
#include "helper.h"
#include "../../include/string.hpp"

// const char my_metadata[] __attribute__((section(".modinfo"))) = "Version=1.0.0 Author=John Doe license=GPL";

kstd::string global_storage;

void initialize_cpp_string(char* data)
{
    kstd::string new_string(data);
    global_storage = kstd::move(new_string);
}

const char* get_cpp_string(void)
{
    return global_storage.c_str();
}

size_t set_cpp_string(const char* new_data) 
{
    global_storage = new_data;
}

size_t get_cpp_string_size(void)
{
    return global_storage.size();
}

void deinitialize_cpp_string(void)
{
    global_storage.~string();
}