#ifndef _LINKED_LIST_HPP_
#define _LINKED_LIST_HPP_

#include "AbstractList.hpp"
#include "Node.hpp"

template <typename T>
class LinkedList: public AbstractList<T>
{
  public:
    
    LinkedList();
    
    LinkedList(const LinkedList& x);
      
    ~LinkedList();
    
    LinkedList& operator=(LinkedList x);

    // use for copy swap idiom
    void swap(LinkedList& x);
    
    bool isEmpty() const noexcept;

    std::size_t getLength() const noexcept;

    void insert(std::size_t position, const T& item);

    void remove(std::size_t position);

    void clear();

    T getEntry(std::size_t position) const;

    void setEntry(std::size_t position, const T& newValue);

  private:

    Node<T>* head;
    std::size_t length;
  
};

#include "LinkedList.tpp"

#endif