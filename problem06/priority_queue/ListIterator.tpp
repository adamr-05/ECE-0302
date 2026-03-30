#include "ListIterator.hpp"

/* Change the second constructor argument to Node<T>* if using a linked implementation */
template <typename T>
inline ListIterator<T>::ListIterator(List<T> *listPtr, T *itemPtr)
{
    // TODO
}

template <typename T>
inline T ListIterator<T>::operator*() const
{
    // TODO
    return T();
}

template <typename T>
inline ListIterator<T> ListIterator<T>::operator++()
{
    // TODO
    return ListIterator<T>(nullptr, nullptr);
}

template <typename T>
inline bool ListIterator<T>::operator==(const ListIterator<T> &rhs) const
{
    // TODO
    return false;
}

template <typename T>
inline bool ListIterator<T>::operator!=(const ListIterator<T> &rhs) const
{
    // TODO
    return false;
}