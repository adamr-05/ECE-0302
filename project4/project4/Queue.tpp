#include "Queue.hpp"

template <typename T, typename L>
void Queue<T,L>::enqueue(const T& item)
{
  //add to back, index position = length of list
  internal_list.insert(internal_list.getLength(), item);
}

template <typename T, typename L>
void Queue<T,L>::dequeue()
{
  //remove item at front (index position 0)
  internal_list.remove(0);
}

template <typename T, typename L>
T Queue<T,L>::peekFront() const
{
  // TODO
  return T();
}

template <typename T, typename L>
bool Queue<T,L>::isEmpty() const
{
  return internal_list.isEmpty();
}

