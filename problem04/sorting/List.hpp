#ifndef _LIST_HPP_
#define _LIST_HPP_

#include "AbstractList.hpp"

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

  void moveEntry(std::size_t from, std::size_t to);

private:
  
  T* items;                 //holds array data
  std::size_t length;       //length of current array
  std::size_t capacity;     //memory allocated for aarray (increase memory allocated if length gets close to or exceeds capacity size)
  
};

#include "List.tpp"

#endif
