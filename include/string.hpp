#include "memory.hpp"
#include <cstring>

namespace kstd
{
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

        string& operator+=(const string& str)
        {
            size_t new_string_length = strlen(data.get()) + strlen(str.data.get()) + 1;
            kstd::kunique_ptr<char[]> new_data(new char[new_string_length]); // allocate new space for the combined string
            strcpy(new_data.get(), data.get()); // copy the first string
            strcat(new_data.get(), str.data.get()); // concatenate the second string
            data = kstd::move(new_data); // move the new data to the current data
        };

        const char* c_str() const
        {
            return data.get();
        }

        size_t size() const
        {
            return this->length;
        }

    }
}