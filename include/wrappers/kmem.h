#define size_t long unsigned int 

extern "C" {
    
    void* kmalloc_wrapper(size_t size);
    void kfree_wrapper(void* to_free);
}