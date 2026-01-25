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
    if (size <= 0)
    {
        invalid = true;
        arraySize = 0;
        data = nullptr;
        return;
    }

    invalid = false;
    arraySize = size;
    data = new intmax_t[arraySize];
    for (intmax_t i = 0; i < arraySize; i++)
    {
        data[i] = 0;
    }
}

BitArray::BitArray(const std::string & value) 
{
    if (value.empty())
    {
        invalid = true;
        arraySize = 0;
        data = nullptr;
        return;
    }


    arraySize = value.size(); //array size is now size of the string
    data = new intmax_t[arraySize]; //dynamically allocate
    invalid = false;

    for (int i=0;i<arraySize;i++) // set data of array to string data
    {
        if (value[i] != '0' && value[i] != '1')
        {
            invalid = true;
            return;
        }

        data[arraySize -1 -i] = value[i] - '0'; // convert char to int by subracting '0' from ascii value
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
    if (index<0 || index>(arraySize-1))
    {
        invalid = true;
        return;
    }
    data[index] = 1;
}

void BitArray::reset(intmax_t index)
{
    if (index<0 || index>(arraySize-1))
    {
        invalid = true;
        return;
    }
    data[index] = 0;
}

void BitArray::toggle(intmax_t index)
{
    if (index<0 || index>(arraySize-1)) 
    {
        invalid = true;
        return;
    }
    
    data[index] ^= 1; // XOR on a bit flips the bit
}

bool BitArray::test(intmax_t index)
{
    if (index<0 || index>(arraySize-1))
    {
        invalid = true;
        return false;
    }

    if (data[index] == 1) return true;
    return false;
}

std::string BitArray::asString() const
{
    std::string stringData;
    for (int i=0; i<arraySize; i++)
    {
        stringData += std::to_string(data[arraySize-1-i]);
    }
    return stringData;
}

