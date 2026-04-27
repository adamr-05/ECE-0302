#ifndef FRONTIER_QUEUE_HPP
#define FRONTIER_QUEUE_HPP

#include <cstdlib>
#include <vector>

#include "State.hpp"

template <typename T>
class FrontierQueue {
public:

  /** Check if the queue is empty.
   * @return true if the queue is empty, false otherwise */ 
  bool empty() const;

  /** Add a State with its value, path cost, and heuristic into the queue.
   * This should be a O(log n) operation
   * @param val state value 
   * @param path_cost path cost
   * @param heur heuristic 
   * @post State is added to the queue, ordered by f-cost */
  void push(const T &val, std::size_t path_cost, std::size_t heur);

  /** Pop the State with the smallest f-cost.
   * This should be a O(log n) operation 
   * @return State that was popped 
   * @post smallest f-cost state is removed from the queue */
  State<T> pop();

  /** Check if a State with the specified value is in the queue.
   * This may be at most an O(n) operation.
   * @param val State value to search
   * @return true if a State with the specified value is found */
  bool contains(const T &val) const;

  /** Replace a State with the specified value in the queue 
   * if the specified path cost is lower.
   * The State and the ordering of the queue should be updated  
   * according to the new path and f-cost if replaced.
   * This should be at most a O(n) operation.
   * Do nothing if the value is not found or the cost is not lower.
   * @param val State value to search
   * @param path_cost path cost to replace if lower
   * @post if cost is lower, State costs are updated and queue is reordered accordingly
   * @post if State value is not found or cost is not lower, no change */
  void replaceif(const T &val, std::size_t path_cost);

private:

  std::vector<State<T>> queue;
  
};

#include "FrontierQueue.tpp"

#endif
