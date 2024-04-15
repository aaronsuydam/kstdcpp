#include <stddef.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/mm.h>
#include "../include/wrappers/kmem.h"

void* kmalloc_wrapper(size_t size)
{
    return kmalloc(size, GFP_KERNEL);
}

void kfree_wrapper(void* to_free)
{
    kfree(to_free);
}

void copy_from_user_wrapper(void *to, const void *from, unsigned long n)
{
    copy_from_user(to, from, n);
}

bool check_user_space(void* ptr)
{
    return (unsigned long)ptr < TASK_SIZE;
}