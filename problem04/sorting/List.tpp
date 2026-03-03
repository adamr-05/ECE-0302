#include "List.hpp"

template <typename T>
List<T>::List()
{
  items = new T[10] //set default capacity to 10
  length = 0;
  capacity = 10;
}

template <typename T>
List<T>::~List()
{
  //must clear array data to prevent memory leak
  delete[] items;

  // These are kind of redundant as they will be destroyed when object goes out of scope
  items = nullptr;
  length = 0;
  capacity = 0;
}

template <typename T>
List<T>::List(const List<T>& x)
{
  //allocate new array
  items = new T[x.capacity];
  //set private members to match x
  length = x.length;
  capacity = x.capacity;

  //copy data from old array to new array
  for (std::size_t i = 0; i < length; i++)
  {
    items[i] = x.items[i];
  }
}

template <typename T>
List<T>& List<T>::operator=(List<T> x)
{
  swap(x); //use swap method to swap data of THIS (current object) and x (copy of object passed in function)
  return *this; //return current object (will have data of x, x will have data of THIS, x's old data will be destroyed (copy of x!!!)
}

template <typename T>
void List<T>::swap(List& x) 
{
  //swap data of THIS and x (use std::swap to do this for us)
  //x is passed as reference, so it doesnt get destroyed
  std::swap(items, x.items);
  std::swap(length, x.length);
  std::swap(capacity, x.capacity);
}

template <typename T>
bool List<T>::isEmpty() const noexcept
{
  return length == 0;
}

template <typename T>
std::size_t List<T>::getLength() const noexcept
{
  return length;
}

template <typename T>
void List<T>::insert(std::size_t position, const T& item)
{ 
  //check validity of position
  if (position >= length)
  {
    throw std::out_of_range("insert index invalid, must be between 0 and length of list");
  }

  //check if capacity needs increased
  if (length >= capacity)
  {
    //double the current capacity
    capacity *= 2;
    //allocate new array
    T* newItems = new T[capacity];
    //copy data
    for (std::size_t i = 0; i < length; i++)
    {
      newItems[i] = items[i];
    }
    //delete old arr
    delete[] items;
    //point items to new arr
    items = newItems;
  }

  //shift items right of index
  for (std::size_t i = length; i > position; i--)
  {
    items[i] = items[i-1];
  }

  //insert item at position
  items[position] = item;
  //update length
  length++;

}

template <typename T>
void List<T>::remove(std::size_t position)
{
  //check validity of position
  if (position >= length)
  {
    throw std::out_of_range("remove index invalid, must be between 0 and length of list");
  }

  //shift items right of index left
  for (std::size_t i = position; i < length - 1; i++)
  {
    items[i] = items[i+1];
  }
  //update length
  length--;

  //we just skipped over the item to be removed, so it will be destroyed
}

template <typename T>
void List<T>::clear()
{
  //reset private members to default, and delete old array, allocate new empty array
  length = 0;
  capacity = 10;
  delete[] items;
  items = new T[capacity];

}

template <typename T>
T List<T>::getEntry(std::size_t position) const
{
  //check validity of position
  if (position >= length)
  {
    throw std::out_of_range("getEntry index invalid, must be between 0 and length of list");
  }

  //return copy of item at position
  return items[position];
}

template <typename T>
void List<T>::setEntry(std::size_t position, const T& newValue)
{
  //check validity of position
  if (position >= length)
  {
    throw std::out_of_range("setEntry index invalid, must be between 0 and length of list");
  }

  //set item at position
  items[position] = newValue;
}

template <typename T>
void List<T>::moveEntry(std::size_t from, std::size_t to)
{
  //TODO
}
