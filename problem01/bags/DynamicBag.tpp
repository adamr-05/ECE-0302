#include "DynamicBag.hpp"
#include <utility>

template<typename T>
DynamicBag<T>::DynamicBag() : items(nullptr), count(0) {}
  
template<typename T>
DynamicBag<T>::DynamicBag(const DynamicBag<T>& x) : count(x.count)
{
  if (count == 0) {
    items = nullptr;
  } else {
    items = new T[count];
    for (std::size_t i = 0; i < count; i++) {
      items[i] = x.items[i];
    }
  }
}
    
template<typename T>
DynamicBag<T>::~DynamicBag()
{
  delete[] items;
}
  
template<typename T>
DynamicBag<T>& DynamicBag<T>::operator=(DynamicBag<T> x)
{
  swap(x);
  return *this;
}

template<typename T>
void DynamicBag<T>::swap(DynamicBag<T>& x)
{
  std::swap(items, x.items);
  std::swap(count, x.count);
}

template<typename T>
bool DynamicBag<T>::add(const T& item)
{
  T* newItems = new T[count + 1]; //create new array with +1 size

  for (std::size_t i = 0; i < count; i++) //copy items from old array into new array
  {
    newItems[i] = items[i];
  }

  newItems[count] = item; // add the new item

  delete[] items; //delete old array
  items = newItems; //update pointer
  count++; //update count

  return true;
}

template<typename T>
bool DynamicBag<T>::remove(const T& item)
{
  std::size_t i = count;
  
  for (std::size_t j = 0; j < count; j++)
  {
    if (items[j] == item) // loop through all items to find item
    {
      i = j;
      break;      // if item found break loop, set item number to i
    }
  }

  if (i == count) return false;     //if item not found (loops through all numbers and doesn't find) return false

  if (count == 1) // if item to remove is only item in array, clear array
  {
    delete[] items;
    items = nullptr;
    count = 0;
    return true;
  }

  T* newItems = new T[count - 1]; // allocate new array with updated size

  std::size_t k = 0;
  for (std::size_t n = 0; n < count; n++)
  {
    if (n != i)       //copy items to new array, skip one of index j (removed item)
    {
      newItems[k] = items[n];
      k++;
    }
  }

  // delete old array and update size
  delete[] items;
  items = newItems;
  count--;

  return true;
}

template<typename T>
bool DynamicBag<T>::isEmpty() const
{
  return (count == 0);
}

template<typename T>
std::size_t DynamicBag<T>::getCurrentSize() const
{
  return count;
}

template<typename T>
bool DynamicBag<T>::contains(const T& item) const
{  
  for (std::size_t i = 0; i < count; i++)
  {
    if (items[i] == item)
    {
      return true;
    }
  }
  return false;
}

template<typename T>
void DynamicBag<T>::clear()
{
  delete[] items;
  items = nullptr;
  count = 0;
}

template<typename T>
std::size_t DynamicBag<T>::getFrequencyOf(const T & item) const
{
  std::size_t frequency = 0;

  for (std::size_t i = 0; i < count; i++)
  {
    if (items[i] == item) frequency++;
  }
  return frequency;
};
