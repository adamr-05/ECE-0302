#include "LinkedList.hpp"

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), length(0)
{
}

template <typename T>
LinkedList<T>::~LinkedList()
{
  clear();
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &x) : head(nullptr), length(0)
{
  if (x.head != nullptr)
  {
    Node<T>* xCurrent = x.head;

    //copy node 1
    head = new Node<T>(xCurrent->getItem());
    Node<T>* current = head;
    xCurrent = xCurrent->getNext();
    length++;

    //copy other nodes
    while (xCurrent != nullptr)
    {
      Node<T>* newNode = new Node<T>(xCurrent->getItem());
      current->setNext(newNode);
      current = newNode;
      xCurrent = xCurrent->getNext();
      length++;
    }
  }
}

template <typename T>
LinkedList<T> &LinkedList<T>::operator=(LinkedList<T> x)
{
  swap(x);
  return *this;
}

template <typename T>
void LinkedList<T>::swap(LinkedList &x)
{
  std::swap(head, x.head);
  std::swap(length, x.length);
}

template <typename T>
bool LinkedList<T>::isEmpty() const noexcept
{
  return length == 0;
}

template <typename T>
std::size_t LinkedList<T>::getLength() const noexcept
{
  return length;
}

template <typename T>
void LinkedList<T>::insert(std::size_t position, const T &item)
{
  if (position > length)
  {
    throw std::out_of_range("Insert position out of range!");
  }

  Node <T>* newNode = new Node<T>(item);

  if (position == 0)
  {
    newNode->setNext(head);
    head = newNode;
  }
  else
  {
    Node<T>* current = head;
    for (std::size_t i = 0; i < position - 1; i++)
    {
      current = current->getNext();
    }

    newNode->setNext(current->getNext());
    current->setNext(newNode);
  }

  length++;
}

template <typename T>
void LinkedList<T>::remove(std::size_t position)
{
  if (position >= length)
  {
    throw std::out_of_range("Remove position out of range!");
  }

  Node<T>* toDelete = nullptr;

  if (position == 0)
  {
    toDelete = head;
    head = head->getNext();
  }
  else
  {
    Node<T>* current = head;
    for (std::size_t i = 0; i < position - 1; i++)
    {
      current = current->getNext();
    }

    toDelete = current->getNext();
    current->setNext(toDelete->getNext());
  }

  delete toDelete;
  length--;
}

template <typename T>
void LinkedList<T>::clear()
{
  while (head != nullptr)
  {
    Node<T>* temp = head;
    head = head->getNext();
    delete temp;
  }
  length = 0;
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
  if (position >= length)
  {
    throw std::out_of_range("getEntry position out of range!");
  }

  Node<T>* current = head;
  for (std::size_t i = 0; i < position; i++)
  {
    current = current->getNext();
  }

  return current->getItem();
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T &newValue)
{
  if (position >= length)
  {
    throw std::out_of_range("setEntry position out of range!");
  }

  Node<T>* current = head;
  for (std::size_t i = 0; i < position; i++)
  {
    current = current->getNext();
  }

  current->setItem(newValue);
}
