#include "ListIterator.hpp"

/* Change the second constructor argument to Node<T>* if using a linked implementation */
template <typename T>
inline ListIterator<T>::ListIterator(List<T>* listPtr, Node<T>* nodePtr)
  : listPtr(listPtr), current(nodePtr) {}

template <typename T>
inline T ListIterator<T>::operator*() const {
  return current->getItem();
}

template <typename T>
inline ListIterator<T> ListIterator<T>::operator++()
{
    current = current->getNext();
    return *this;
}

template <typename T>
inline bool ListIterator<T>::operator==(const ListIterator<T>& rhs) const {
  return current == rhs.current;
}

template <typename T>
inline bool ListIterator<T>::operator!=(const ListIterator<T>& rhs) const {
  return current != rhs.current;
}