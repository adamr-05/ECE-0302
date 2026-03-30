#include "List.hpp"

template <typename T>
List<T>::List() : headptr(nullptr), length(0) {}

template <typename T>
List<T>::~List()
{
  clear();
}

template <typename T>
List<T>::List(const List<T>& x) : headptr(nullptr), length(0)
{
  //creat ptr curr to head of x
  Node<T>* curr = x.headptr;
  std::size_t pos = 0;

  //loop through curr
  while (curr != nullptr)
  {
    //insert new item, update curr pointer, and increase pos to insert)
    insert(pos, curr->getItem());
    curr = curr->getNext();
    pos++;
  }
}

template <typename T>
List<T>& List<T>::operator=(List<T> x)
{
  //use swap method to copy
  // (copy swap idiom) (maximize code reuse)
  swap(x);
  return *this;
}

template <typename T>
void List<T>::swap(List<T>& x) 
{
  //use std::swap to swap head of x and head of this
  std::swap(headptr, x.headptr);
  std::swamp(length, x.length);
}

template <typename T>
bool List<T>::isEmpty() const noexcept
{
  //TODO
  return true;
}

template <typename T>
std::size_t List<T>::getLength() const noexcept
{
  //TODO
  return 0;
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
ListIterator<T> List<T>::begin() 
{
  // TODO
  return ListIterator<T>(nullptr, nullptr);
}

template <typename T>
ListIterator<T> List<T>::end() 
{
  // TODO
  return ListIterator<T>(nullptr, nullptr);
}