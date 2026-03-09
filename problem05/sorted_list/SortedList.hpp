#ifndef _SORTED_LIST_HPP_
#define _SORTED_LIST_HPP_

#include "AbstractSortedList.hpp"
#include "List.hpp"

template <typename T>
class SortedList: public AbstractSortedList<T>, private List<T>
{
public:

  SortedList();

  SortedList(List<T> unsorted_list);

  SortedList(const SortedList & x);

  SortedList& operator=(SortedList x);

  ~SortedList();

  bool isEmpty() const noexcept;

  std::size_t getLength() const noexcept;

  void insert(const T& item);

  void remove(const T& item);

  void removeAt(std::size_t position);

  void clear();

  T getEntry(std::size_t position) const;

  std::size_t getPosition(const T& item);

private:

  T* items;                 //holds array data
  std::size_t length;       //length of current array
  std::size_t capacity;     //memory allocated for aarray (increase memory allocated if length gets close to or exceeds capacity size)

};

#include "SortedList.tpp"

#endif 
