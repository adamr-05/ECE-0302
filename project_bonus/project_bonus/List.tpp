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
  Node<T>* curr = x.headptr;
  std::size_t pos = 0;

  while (curr != nullptr)
  {
    insert(pos, curr->getItem());
    curr = curr->getNext();
    pos++;
  }
}

template <typename T>
List<T>& List<T>::operator=(List<T> x)
{
  swap(x);
  return *this;
}

template <typename T>
void List<T>::swap(List<T>& x) 
{
  std::swap(headptr, x.headptr);
  std::swap(length, x.length);
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
  if (position > length)
  {
    throw std::out_of_range("insert position larger than list size!");
  }

  if (position == 0)
  {
    headptr = new Node<T>(item, headptr);
  }
  else
  {
    Node<T>* prev = headptr;
    for (std::size_t i=0; i < position - 1; i++)
    {
      prev = prev->getNext();
    }
    prev->setNext(new Node<T>(item, prev->getNext()));
  }
  length++;
}

template <typename T>
void List<T>::remove(std::size_t position)
{
  if (position >= length)
  {
    throw std::out_of_range("remove position does not contain node! (too large)");
  }

  Node<T>* toDelete;

  if (position == 0)
  {
    toDelete = headptr;
    headptr = headptr->getNext();
  }
  else
  {
    Node<T>* prev = headptr;
    
    for (std::size_t i=0; i < position - 1; i++)
    {
      prev = prev->getNext();
    }

    toDelete = prev->getNext();
    prev->setNext(toDelete->getNext());
  }
  delete toDelete;
  length--;
}

template <typename T>
void List<T>::clear()
{
  while (headptr != nullptr)
  {
    Node<T>* temp = headptr;
    headptr = headptr->getNext();
    delete temp;
  }
  length = 0;
}

template <typename T>
T List<T>::getEntry(std::size_t position) const
{
  if (position >= length) {
    throw std::out_of_range("getEntry: position out of range");
  }
  Node<T>* curr = headptr;
  for (std::size_t i = 0; i < position; i++) {
    curr = curr->getNext();
  }
  return curr->getItem();
}

template <typename T>
void List<T>::setEntry(std::size_t position, const T& newValue)
{
  if (position >= length) {
    throw std::out_of_range("setEntry: position out of range");
  }

  Node<T>* curr = headptr;
  for (std::size_t i = 0; i < position; i++) {
    curr = curr->getNext();
  }
  curr->setItem(newValue);
}