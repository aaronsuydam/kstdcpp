

#include "new.hpp"

namespace kstd {


    template <typename T> struct remove_reference { typedef T type; };
    template <typename T> struct remove_reference<T&> { typedef T type; };
    template <typename T> struct remove_reference<T&&> { typedef T type; };

    template <typename T>
    typename remove_reference<T>::type&& move(T&& t) noexcept
    {
        return static_cast<typename remove_reference<T>::type&&>(t);
    }

    template<typename T>
    T&& forward(typename std::remove_reference<T>::type&& arg) noexcept 
    {
        return static_cast<T&&>(arg);
    }



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

        T* get()
        {
            return data;
        }
    };

    template <typename T> class kunique_ptr;
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

        T* get() const
        {
            return data;
        }
    };

    template <typename T, typename... Args>
    kunique_ptr<T> make_kunique(Args&&... args)
    {
        return kstd::kunique_ptr<T>(new T(kstd::forward<Args>(args)...));
    }

    template <typename T>
    kunique_ptr<T> make_kunique(size_t size)
    {
        return kstd::kunique_ptr<T[]>(new T[size]);
    }
}