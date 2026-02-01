#ifndef LIMITED_SIZE_BAG_HPP
#define LIMITED_SIZE_BAG_HPP

#include "AbstractBag.hpp"

template <typename T>
class LimitedSizeBag: public AbstractBag<T>
{
public:
  // default constructor
  LimitedSizeBag();
  
  bool add(const T & item);
  
  bool remove(const T & item);

  bool isEmpty() const;

  std::size_t getCurrentSize() const;

  void clear();

  std::size_t getFrequencyOf(const T & item) const;

  bool contains(const T& item) const;
  
  //static variable to store the limited size 
  static const std::size_t maxsize = 100;

private:
  T items[maxsize]; // static size array of 100 elements (max size above ^^)
  std::size_t count; // counter to track current number items

};

#include "LimitedSizeBag.tpp"

#endif
