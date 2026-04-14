#include "Queue.hpp"

template <typename T, typename L>
void Queue<T,L>::enqueue(const T& item)
{
  // TODO
}

template <typename T, typename L>
void Queue<T,L>::dequeue()
{
  // TODO
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

