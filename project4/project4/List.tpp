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
  std::swap(length, x.length);
}

template <typename T>
bool List<T>::isEmpty() const noexcept
{
  //if length is 0 list is empty
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
  //check validity of pos
  if (position > length)
  {
    throw std::out_of_range("insert position larger than list size!");
  }

  //if position 0, no pointer to loop through, so create new ptr
  if (position == 0)
  {
    //create new node, new ptr, with item
    headptr = new Node<T>(item, headptr);
  }
  else
  {
    //create pointer to loop and find insert position
    Node<T>* prev = headptr;
    //loop through list using linked pointers (position amount of loops)
    for (std::size_t i=0; i < position - 1; i++)
    {
      prev = prev->getNext();
    }

    //create new node with proper position, then add it to end of linked list
    prev->setNext(new Node<T>(item, prev->getNext()));
  }
  length++;
}

template <typename T>
void List<T>::remove(std::size_t position)
{
  //check pos validity
  if (position >= length)
  {
    throw std::out_of_range("remove position does not contain node! (too large)");
  }

  //temporary node
  Node<T>* toDelete;

  //if pos = 0 delete headptr node and increment headptr by one
  if (position == 0)
  {
    toDelete = headptr;
    headptr = headptr->getNext();
  }

  //else loop through linked list as before
  else
  {
    Node<T>* prev = headptr;
    
    for (std::size_t i=0; i < position - 1; i++)
    {
      prev = prev->getNext();
    }

    //set delete node as found node
    toDelete = prev->getNext();
    //update pointer
    prev->setNext(toDelete->getNext());
  }
  delete toDelete;
  length--;
}

template <typename T>
void List<T>::clear()
{
  //keep deleting first node until headptr is empty (moving to next node)
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
  //check pos validity
  if (position >= length) {
    throw std::out_of_range("getEntry: position out of range");
  }
  //loop through nodes
  Node<T>* curr = headptr;
  for (std::size_t i = 0; i < position; i++) {
    curr = curr->getNext();
  }
  //return item at node found at position
  return curr->getItem();
}

template <typename T>
void List<T>::setEntry(std::size_t position, const T& newValue)
{
  //check validity of pos
  if (position >= length) {
    throw std::out_of_range("setEntry: position out of range");
  }

  //loop through nodes again (same as getEntry)
  Node<T>* curr = headptr;
  for (std::size_t i = 0; i < position; i++) {
    curr = curr->getNext();
  }
  //almost identical to getEntry
  //here instead of returning item,
  //use setItem to change item at node to newValue
  curr->setItem(newValue);
}
