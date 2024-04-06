#include "../include/new.hpp"
#include "../include/wrappers/kmem.h"

void* operator new(size_t size) noexcept
{
    return kmalloc_wrapper(size);
}

void* operator new[](size_t size) noexcept
{
    return operator new(size);
}


void operator delete(void* pointer) noexcept
{
    if(pointer != nullptr)
    {
        kfree_wrapper(pointer);
    }
}

void operator delete[](void* pointer) noexcept
{
    operator delete(pointer);
}