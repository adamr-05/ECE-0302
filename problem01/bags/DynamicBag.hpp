#ifndef _DYNAMIC_BAG_HPP_
#define _DYNAMIC_BAG_HPP_

#include "AbstractBag.hpp"

template <typename T>
class DynamicBag: public AbstractBag<T>
{
public:
  // default constructor
  DynamicBag();
  
  // copy constructor
  DynamicBag(const DynamicBag& x);
    
  // destructor
  ~DynamicBag();
  
  // copy assignment
  DynamicBag& operator=(DynamicBag x);

  // swap for copy swap idiom
  void swap(DynamicBag& x);

  bool add(const T & item);
  
  bool remove(const T & item);

  bool isEmpty() const;

  std::size_t getCurrentSize() const;

  void clear();

  std::size_t getFrequencyOf(const T & item) const;

  bool contains(const T& item) const;

private:

};

#include "DynamicBag.tpp"

#endif
