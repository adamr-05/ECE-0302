
#ifndef _PRIORITY_QUEUE_HPP_
#define _PRIORITY_QUEUE_HPP_

#include "AbstractPriorityQueue.hpp"

// T is any orderable type
// L must conform to the AbstractSortedList Interface
template <typename T, typename L>
class PriorityQueue: public AbstractPriorityQueue<T>
{
public:

  bool isEmpty() const;

  void add(const T& item);

  void remove();

  T peek() const;

private:

  L slist; // internal sorted list
};

#include "PriorityQueue.tpp"
  
#endif 
