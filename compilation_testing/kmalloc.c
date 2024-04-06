#include <stddef.h>
#include <linux/slab.h>
#include "kmalloc.h"

void* kmalloc_wrapper(size_t size)
{
    return kmalloc(size, GFP_KERNEL);
}

void kfree_wrapper(void* to_free)
{
    kfree(to_free);
}