
#include "memory.hpp"
#include "algorithm.hpp"

template <typename T>
class kvector {

    private:
    // private members
    kstd::kunique_ptr<T[]> data;
    size_t size;

    public:
    // public members

    /* Constructors */

    // Default constructor
    kvector()
    {
        data = new T[0];
    };

    // Constructor with size
    explicit kvector(size_t count)
    {
        data = new T[count];
    };

    // Constructor with size and default value
    kvector(size_t count, const T& value)
    {
        data = new T[count];
        for(size_t i = 0; i < count; i++)
        {
            data[i] = value;
        }
    };

    kvector(const kvector<T>& other)
    {
        kstd::copy(other.data.get(), other.data.get() + other.size, data.get());
    }
    ~kvector();


};