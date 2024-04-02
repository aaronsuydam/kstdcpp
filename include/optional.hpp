#include "./new.hpp"

struct nullopt_t {};
constexpr nullopt_t nullopt{};


template <typename T>
class koptional {
    private:
    
    bool value_present;
    T contained_value;

    public:

    koptional() : value_present(false) {}
    koptional(nullopt) : value_present(false) {}
    koptional(const T& value) : value_present(true), contained_value(value) {}

    bool has_value() const 
    {
        return this->value_present;
    }

    T& value()
    {
        if(this->value_present)
        {
            return this->contained_value;
        }
        else
        {
            return nullopt;
        }
    }

    void reset()
    {
        this->value_present = false;
        contained_value.~T();
    }
};