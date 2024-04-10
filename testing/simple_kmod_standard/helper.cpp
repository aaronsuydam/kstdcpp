// SPDX-License-Identifier: GPL-2.0 OR MIT
#define size_t long unsigned int
#include "helper.h"

// const char my_metadata[] __attribute__((section(".modinfo"))) = "Version=1.0.0 Author=John Doe license=GPL";



size_t helper_function(void) {
    return 5;
}