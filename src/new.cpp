#include "../include/new.hpp"
#include "linux/slab.h"

void* operator new(std::size_t size) noexcept
{
    return kmalloc(size, GFP_KERNEL);
}

void* operator new[](std::size_t size) noexcept
{
    return operator new(size);
}


void operator delete(void* pointer) noexcept
{
    if(pointer != nullptr)
    {
        kfree(pointer);
    }
}

void operator delete[](void* pointer) noexcept
{
    operator delete(pointer);
}