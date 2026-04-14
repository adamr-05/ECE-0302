#ifndef _ABSTRACT_QUEUE_HPP_
#define _ABSTRACT_QUEUE_HPP_

template <typename T>
class AbstractQueue
{
public:

  /** virtual destructor to ensure overriding */
  virtual ~AbstractQueue(){};

  /** determine if the priority queue is empty
   * @return true if the queue is empty, false otherwise */
  virtual bool isEmpty() const = 0;

  /** enqueue (add) item at the back of the queue
   * @param item item to enqueue
   * @post item is appended to the back of the queue
   * the order of other items is preserved */ 
  virtual void enqueue(const T& item) = 0;

  /** remove the item at the front of the queue
   * @throws std::out_of_range if the queue is empty
   * @post front item is removed, the order of other items is preserved */    
  virtual void dequeue() = 0;

  /** get a copy of the item at the front of the queue
   * @throws std::out_of_range if queue is empty */ 
  virtual T peekFront() const = 0;
};

#endif
