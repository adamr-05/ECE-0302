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
  //TODO
  return *this;
}

template <typename T>
void List<T>::swap(List& x) 
{
  //TODO
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
  //TODO
}

template <typename T>
void List<T>::remove(std::size_t position)
{
  //TODO
}

template <typename T>
void List<T>::clear()
{
  //TODO
}

template <typename T>
T List<T>::getEntry(std::size_t position) const
{
  //TODO
  return T();
}

template <typename T>
void List<T>::setEntry(std::size_t position, const T& newValue)
{
  //TODO
}

template <typename T>
void List<T>::moveEntry(std::size_t from, std::size_t to)
{
  //TODO
}
