#include "SortedList.hpp"
#include <stdexcept>

template <typename T>
SortedList<T>::SortedList()
{
  // base constructor gets called automatically
}

template <typename T>
SortedList<T>::SortedList(List<T> unsorted_list) 
{
  for (int i=0; i < unsorted_list.getLength(); i++)
  {
    insert(unsorted_list.getEntry(i));
  }
}

template <typename T>
SortedList<T>::SortedList(const SortedList<T> & x):
  List<T>(x)
{
}

template <typename T>
SortedList<T>& SortedList<T>::operator=(SortedList<T> x)
{
  List<T>::operator=(x);
  return *this;
}

template <typename T>
SortedList<T>::~SortedList()
{
  // base destructor gets called automatically
}

template <typename T>
bool SortedList<T>::isEmpty() const noexcept
{
  return List<T>::isEmpty();
}

template <typename T>
std::size_t SortedList<T>::getLength() const noexcept
{
  return List<T>::getLength();
}

template <typename T>
void SortedList<T>::insert(const T& item)
{
  //loop through old array
  for (std::size_t i=0; i < List<T>::getLength(); i++)
  {
    //if old array item greater than item to insert
    if (List<T>::getEntry(i) > item)
    {
      //insert new item before that greater item
      List<T>::insert(i, item);
      return;
    }
  }
  //if no greater item found, insert at end
  List<T>::insert(List<T>::getLength(), item);
}

template <typename T>
void SortedList<T>::remove(const T& item)
{  
  for (std::size_t i=0; i < List<T>::getLength(); i++)
  {
    if (List<T>::getEntry(i) == item)
    {
      List<T>::remove(i);
      return;
    }
  }
  throw std::invalid_argument("item not found");
}

template <typename T>
void SortedList<T>::removeAt(std::size_t position)
{  
  List<T>::remove(position);
}

template <typename T>
void SortedList<T>::clear()
{
  List<T>::clear();
}

template <typename T>
T SortedList<T>::getEntry(std::size_t position) const
{
  return List<T>::getEntry(position);
}

template <typename T>
std::size_t SortedList<T>::getPosition(const T& item)
{
  for (std::size_t i = 0; i < List<T>::getLength(); i++)
  {
    if (List<T>::getEntry(i) == item)
    {
      return i;
    }
  }
  throw std::invalid_argument("item not found");
}
