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
    if (value.empty()) invalid = true; //check if empty, then get length of string

    int stringSize = value.size();

     
    for(int i=0; i<stringSize; i++) // if any index in the string is not 0 and not 1, then invalid.
    {
        if (value[i] != 0 && value[i] != 1)
        {
            invalid = true;
        }
    }

    arraySize = stringSize; //array size is now size of the string
    data = new intmax_t[arraySize]; //dynamically allocate
    
    for (int i=0;i<arraySize;i++) // set data of array to string data
    {
        data[i] = value[i];
    }

}

BitArray::~BitArray() 
{
    delete[] data; //delete content of array
    data = nullptr; //set pointer to empty
}

intmax_t BitArray::size() const
{
    return arraySize; // return size variable
}

bool BitArray::good() const
{
    if (invalid == true) return false;
    return true;
}

void BitArray::set(intmax_t index)
{
    if (index<0 || index>(arraySize-1)) invalid == true;
    data[index] = 1;
}

void BitArray::reset(intmax_t index)
{
    if (index<0 || index>(arraySize-1)) invalid == true;
    data[index] = 1;
}

void BitArray::toggle(intmax_t index)
{
    if (index<0 || index>(arraySize-1)) invalid == true;
    
    if (data[index] == 0) data[index] = 1;
    if (data[index] == 1) data[index] = 0;
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
