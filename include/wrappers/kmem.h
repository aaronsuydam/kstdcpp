#define size_t long unsigned int 

#ifdef __cplusplus
extern "C" {
#endif
    void* kmalloc_wrapper(size_t size);
    void kfree_wrapper(void* to_free);
#ifdef __cplusplus
}
#endif