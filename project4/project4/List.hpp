#ifndef _LIST_HPP_
#define _LIST_HPP_


#include "AbstractList.hpp"
#include "Node.hpp"
#include "ListIterator.hpp"


template <typename T>
class List: public AbstractList<T>
{
public:
  
  List();
  
  List(const List& x);
    
  ~List();
  
  List& operator=(List x);

  void swap(List& x);
  
  bool isEmpty() const noexcept;

  std::size_t getLength() const noexcept;

  void insert(std::size_t position, const T& item);

  void remove(std::size_t position);

  void clear();

  T getEntry(std::size_t position) const;

  void setEntry(std::size_t position, const T& newValue);

  // iterator methods
  ListIterator<T> begin();
  ListIterator<T> end();

private:

  //TODO
  Node<T>* headptr;
  std::size_t length;
  
};

#include "List.tpp"
#endif
