#include "ArrayList.hpp"

template <typename T>
ArrayList<T>::ArrayList() : data(nullptr), length(0)
{
}

template <typename T>
ArrayList<T>::~ArrayList() 
{
  clear();
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList &x) 
{
  if (x.length > 0)
  {
    data = new T[x.length];
    length = x.length;

    for (std::size_t i = 0; i < length; i++)
    {
      data[i] = x.data[i];
    }
  }
}

template <typename T>
ArrayList<T> &ArrayList<T>::operator=(ArrayList x)
{
  swap(x);
  return *this;
}

template <typename T>
void ArrayList<T>::swap(ArrayList &x) 
{
  std::swap(data, x.data);
  std::swap(length, x.length);
}

template <typename T>
bool ArrayList<T>::isEmpty() const noexcept
{
  return length == 0;
}

template <typename T>
std::size_t ArrayList<T>::getLength() const noexcept
{
  return length;
}

template <typename T>
void ArrayList<T>::insert(std::size_t position, const T &item)
{
  // TODO
}

template <typename T>
void ArrayList<T>::remove(std::size_t position)
{
  // TODO
}

template <typename T>
void ArrayList<T>::clear() 
{
  // TODO
}

template <typename T>
T ArrayList<T>::getEntry(std::size_t position) const
{
  // TODO
  return T();
}

template <typename T>
void ArrayList<T>::setEntry(std::size_t position, const T &newValue) 
{
  // TODO
}
