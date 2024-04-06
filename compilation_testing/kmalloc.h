#define size_t unsigned long long

extern "C" {
    
    void* kmalloc_wrapper(size_t size);
    void kfree_wrapper(void* to_free);
}