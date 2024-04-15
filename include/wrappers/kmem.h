#define size_t long unsigned int 

#ifdef __cplusplus
extern "C" {
#endif
    void* kmalloc_wrapper(size_t size);
    void kfree_wrapper(void* to_free);
    void copy_from_user_wrapper(void *to, const void *from, unsigned long n);
    bool check_user_space(void* ptr);
#ifdef __cplusplus
}
#endif