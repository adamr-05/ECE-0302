#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_

#include "AbstractQueue.hpp"

template <typename T, typename L>
class Queue: public AbstractQueue<T>
{
public:

  // default constructor, destructor, and copy are sufficient

  bool isEmpty() const;

  void enqueue(const T& item);

  void dequeue();

  T peekFront() const;

private:

  // L must conform to AbstractList interface
  L internal_list;
};

#include "Queue.tpp"

#endif 
