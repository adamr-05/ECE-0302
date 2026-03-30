#ifndef _LIST_ITERATOR_HPP_
#define _LIST_ITERATOR_HPP_

#include <iterator>

#include "List.hpp"

// forward declaration
template <typename T> class List;

// iterator class
template <typename T> 
class ListIterator : public std::iterator<std::input_iterator_tag, T> {
    public:
        /* Change the second constructor argument to Node<T>* if using a linked implementation */
        // ListIterator(List<T>* listPtr, Node<T>* nodePtr);
        ListIterator(List<T>* listPtr, Node<T>* nodePtr);

        T operator*() const;

        ListIterator<T> operator++();

        bool operator==(const ListIterator<T>& rhs) const;

        bool operator!=(const ListIterator<T>& rhs) const;
    
    private:
        List<T>* listPtr;
        Node<T>* current;
};

#include "ListIterator.tpp"

#endif