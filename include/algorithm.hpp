

namespace kstd
{
    /**
     * @brief 
     * 
     * @tparam InputIt 
     * @tparam OutputIt 
     * @param first 
     * @param last 
     * @param dest 
     * @return OutputIt 
     */
    template < class InputIt, class OutputIt>
    OutputIt copy(InputIt first, InputIt last, OutputIt dest)
    {
        while(first != last)
        {
            *dest = *first;
            dest++;
            first++;
        }
        return dest;
    }

}
