
#ifndef _ABSTRACT_PRIORITY_QUEUE_HPP_
#define _ABSTRACT_PRIORITY_QUEUE_HPP_

// type T must be orderable (support operator<)
template <typename T>
class AbstractPriorityQueue
{
  public:

    /** virtual destructor to ensure overriding */
    virtual ~AbstractPriorityQueue(){};

    /** determine if the priority queue is empty
     * @return true if the queue is empty, false otherwise */
    virtual bool isEmpty() const = 0;

    /** insert item at the correct position based on priority
     * @param item item to insert
     * @post item is inserted in priority order,
     * the order of other items is preserved */    
    virtual void add(const T& item) = 0;

    /** remove the highest-priority item from the queue
     * @throws std::out_of_range if the queue is empty
     * @post item is removed, the order of other items is preserved */    
    virtual void remove() = 0;

    /** get a copy of the highest-priority item in the queue
     * @throws std::out_of_range if queue is empty */ 
    virtual T peek() const = 0;
};

#endif 
