#include "BitArray.hpp"

BitArray::BitArray() //bitset of size 8, set values to 0
{
    invalid = false;
    arraySize = 8;
    data = new intmax_t[arraySize];

    for (intmax_t i = 0; i < arraySize; i++)
    {
        data[i] = 0;
    }
}

BitArray::BitArray(intmax_t size) //bitset of size "size", set values to 0
{
    if (size < 0)
    {
        invalid = true;
    }
    else invalid = false;
    
    arraySize = size;
    data = new intmax_t[arraySize];
    for (intmax_t i = 0; i < arraySize; i++)
    {
        data[i] = 0;
    }
}

BitArray::BitArray(const std::string & value) 
{
    if (value.empty()) invalid = true;

    int stringSize = value.size();

     
    for(int i=0; i<stringSize; i++)
    {
        if (value[i] != 0 && value[i] != 1)
        {
            invalid = true;
        }
    }

    arraySize = stringSize;
    data = new intmax_t[arraySize];
    
    for (int i=0;i<arraySize;i++)
    {
        data[i] = value[i];
    }

}

BitArray::~BitArray() 
{
    delete[] data;
    data = nullptr;
}

intmax_t BitArray::size() const
{
    return intmax_t();
}

bool BitArray::good() const
{
    return false;
}

void BitArray::set(intmax_t index)
{
}

void BitArray::reset(intmax_t index)
{
}

void BitArray::toggle(intmax_t index)
{
}

bool BitArray::test(intmax_t index)
{
    return false;
}

std::string BitArray::asString() const
{
    return std::string();
}

// TODO: other methods
