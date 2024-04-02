#include <cstdint>

namespace kstd {
    struct nothrow_t {};
    extern const nothrow_t nothrow = {};
}




void* operator new(std::size_t size);
void* operator new[](size_t size);

void operator delete(void* pointer) noexcept;
void operator delete[](void* pointer) noexcept;


