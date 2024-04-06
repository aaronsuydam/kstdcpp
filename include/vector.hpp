
#include "memory.hpp"
#include "algorithm.hpp"
#include "optional.hpp"

template <typename T>
class kvector {

    private:
    // private members
    kstd::kunique_ptr<T[]> data;
    size_t size;
    size_t current_elements;

    public:
    // public members

    /* Constructors */

    // Default constructor
    kvector()
    {
        data = new T[0];
        size = 0;
        current_elements = 0;
    };

    // Constructor with size
    explicit kvector(size_t count)
    {
        data = new T[count];
        size = count;
        current_elements = 0;
    };

    // Constructor with size and default value
    kvector(size_t count, const T& value)
    {
        data = new T[count];
        for(size_t i = 0; i < count; i++)
        {
            data[i] = value;
        }
        size = count;
        current_elements = count;
    };

    kvector(const kvector<T>& other) : size(other.size), current_elements(other.current_elements)
    {
        data = new kstd::kunique_ptr<T[]>(other.size);
        kstd::copy(other.data.get(), other.data.get() + other.size, data.get());
    }
    
    ~kvector()
    {
        // Data automatically cleans up after itself.
    }

    /* Member functions */

    /**
     * @brief Adds an already existing element to the end of the vector
     * 
     * Takes in a value and attempts to add it to the vector using copy
     * semantics. If the vector is full, then a couple things need to 
     * happen. First, a new array will need to be allocated, then the
     * contents of the existing array will need to be copied into it,
     * and then that old array deleted, and the new array be assigned 
     * as data. 
     * 
     * 
     * @param value 
     * @return void 
     
     * 
     */
    bool push_back(const T& value)
    {
        if(current_elements == size)
        {
            // allocate new array and copy
            float scale_factor = 1.5;

            kstd::kunique_ptr<T[]> new_data = new T[size * scale_factor];
            if(new_data == nullptr)
            {
                // Allocation failed
                return false;
            }
            kstd::copy(data.get(), data.get() + size, new_data.get());
            data = new_data;
            size = size * scale_factor;
        }

        data[current_elements] = value;
        current_elements++;
        return true;
    }

    kstd::optional<T> at(size_t index)
    {
        if(index >= 0 && index < current_elements)
        {
            kstd::optional<T> element_at(this->data[index]);
            return element_at;
        }
        else
        {
            return kstd::nullopt;
        }
    }


};