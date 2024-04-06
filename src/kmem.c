#include <stddef.h>
#include <linux/slab.h>
#include "../include/wrappers/kmem.h"

void* kmalloc_wrapper(size_t size)
{
    return kmalloc(size, GFP_KERNEL);
}

void kfree_wrapper(void* to_free)
{
    kfree(to_free);
}