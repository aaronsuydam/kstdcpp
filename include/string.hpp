#include "memory.hpp"
// #include "wrappers/cstring.h"
// #include "wrappers/kernel.h"

namespace kstd
{

    size_t strlen(const char *str) 
    {
        const char* s;
        for (s = str; *s; ++s) {}
        return s - str;
    }

    char* strcpy(char* dest, const char* src)
    {
        char* ret = dest;
        while ((*dest++ = *src++));
        return ret;
    }

    char* strcat(char* dest, const char* src) 
    {
        char* save = dest;

        // Move `dest` pointer to the end of the destination string
        while (*dest) {
            dest++;
        }

        // Copy `src` to the end of `dest`, including the null terminator
        while ((*dest++ = *src++)) {
            // Empty loop body; the work is done in the condition.
        }

        return save; // Return the original `dest` pointer
    }

    class string
    {

        private:
        kstd::kunique_ptr<char[]> data;
        size_t length;


        public:

        string() : data(new char[0]) {};
        string(const char* str) : data(new char[strlen(str) + 1]) {
            strcpy(data.get(), str);
        };

        string& operator=(const char* data)
        {
            size_t new_string_length = strlen(data) + 1;
            kstd::kunique_ptr<char[]> new_data(new char[new_string_length]);
            strcpy(new_data.get(), data);
            this->data = kstd::move(new_data);
        }

        string& operator+=(const string& str)
        {
            size_t new_string_length = strlen(data.get()) + strlen(str.data.get()) + 1;
            kstd::kunique_ptr<char[]> new_data(new char[new_string_length]); // allocate new space for the combined string
            strcpy(new_data.get(), data.get()); // copy the first string
            strcat(new_data.get(), str.data.get()); // concatenate the second string
            data = kstd::move(new_data); // move the new data to the current data
            return *this;
        };

        const char* c_str() const
        {
            return data.get();
        }

        size_t size() const
        {
            return this->length;
        }

    };

    // string to_string(int number)
    // {
    //     auto buf = make_kunique<char[]>(21);     
    //     snprintf(buf.get(), 21, %d, number);
    //     return string(buf.get());
    // }

    // string to_string(size_t number)
    // {
    //     auto buf = make_kunique<char[]>(21);     
    //     snprintf(buf.get(), 21, %zu, number);
    //     return string(buf.get());
    // }
}