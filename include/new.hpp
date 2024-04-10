
#define size_t long unsigned int

namespace kstd {
    struct nothrow_t {};
    inline extern const nothrow_t nothrow = {};
}




void* operator new(size_t size) noexcept;
void* operator new[](size_t size) noexcept;

void operator delete(void* pointer) noexcept;
void operator delete[](void* pointer) noexcept;


