#include "kmalloc.h"

void some_pointless_function(void)
{
    void* ptr = kmalloc_wrapper(10);
    kfree_wrapper(ptr);
}