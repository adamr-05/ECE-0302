#include "FrontierQueue.hpp"

template <typename T>
State<T> FrontierQueue<T>::pop() {

  //TODO: implement this the same way we implemented pop in the heap lecture. Compare states using getFCost.
  // trickle down
  // implemented same as lecture, flipped comparisions (max heap --> min heap)
  int parent = 0;
  int size = queue.size();
  while (true) 
  {
    int left = 2 * parent + 1;
    int right = 2 * parent + 2;
    int smallest = parent;
    if (left < size && queue[left].getFCost() < queue[smallest].getFCost()) smallest = left;
    if (right < size && queue[right].getFCost() < queue[smallest].getFCost()) smallest = right;
    if (smallest == parent) break;
    std::swap(queue[parent], queue[smallest]);
    parent = smallest;
  }
  
  return top;
}

template <typename T>
void FrontierQueue<T>::push(const T &p, std::size_t cost, std::size_t heur) {

  //TODO: implement this the same way we implemented push in the heap lecture.
  // bubble up
  // same code as lecture, but comparisons flipped (max heap to min heap)
  int child = queue.size() - 1;
  int parent = (child - 1) / 2;
  while (child > 0 && queue[child].getFCost() < queue[parent].getFCost()) 
  {
    std::swap(queue[child], queue[parent]);
    child = parent;
    parent = (child - 1) / 2;
  }
}


template <typename T>
bool FrontierQueue<T>::empty() const {

  return queue.empty();
}

template <typename T> 
bool FrontierQueue<T>::contains(const T &p) const {

  //TODO
  //loop through size
  for (std::size_t i = 0; i < queue.size(); i++)
  {
    //check value at every position against p
    if (queue[i].getValue() == p) return true;
  }
  return false;
}

template <typename T>
void FrontierQueue<T>::replaceif(const T &p, std::size_t cost) {

  //TODO

}


