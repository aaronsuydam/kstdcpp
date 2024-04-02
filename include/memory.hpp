

#include "new.hpp"

namespace kstd {

    template <typename T>
    class kunique_ptr
    {
        private:
        T* data;

        public:

        explicit kunique_ptr() = delete;
        explicit kunique_ptr(T* data) : data(data) {}

        kunique_ptr(kunique_ptr&& other) noexcept : data(other.data)
        {
            other.data = nullptr;
        }

        kunique_ptr& operator=(kunique_ptr&& other) noexcept
        {
            if(this != &other)
            {
                delete data;
                data = other.data;
                other.data = nullptr;
            }
            return *this;
        }

        kunique_ptr(const kunique_ptr&) = delete;
        kunique_ptr& operator=(const kunique_ptr&) = delete;


        ~kunique_ptr()
        {
            delete data;
        }

        T* operator->()
        {
            return data;
        }
    };

    template <typename T>
    class kunique_ptr<T[]>
    {
        private:
        T* data;

        public:

        kunique_ptr() = delete;
        explicit kunique_ptr(T* data) : data(data) {}

        kunique_ptr(kunique_ptr&& other) noexcept : data(other.data)
        {
            other.data = nullptr;
        }

        kunique_ptr& operator=(kunique_ptr&& other) noexcept
        {
            if(this != &other)
            {
                delete[] data;
                data = other.data;
                other.data = nullptr;
            }
            return *this;
        }

        kunique_ptr(const kunique_ptr&) = delete;
        kunique_ptr& operator=(const kunique_ptr&) = delete;


        ~kunique_ptr()
        {
            delete[] data;
        }

        T& operator[](size_t index)
        {
            return data[index];
        }
    };
}