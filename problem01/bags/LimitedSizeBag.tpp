#include "LimitedSizeBag.hpp"

template<typename T>
LimitedSizeBag<T>::LimitedSizeBag() : count(0) {}
  
template<typename T>
bool LimitedSizeBag<T>::add(const T& item)
{
  if (count >= maxsize) return false;

  items[count] = item;
  count++;
  return true;
}

template<typename T>
bool LimitedSizeBag<T>::remove(const T& item)
{
  for (std::size_t i = 0; i<count; i++)
  {
    if (items[i] == item)
    {
      items[i] = items[count-1];
      count--;
      return true;
    }
  }
  return false;
}

template<typename T>
bool LimitedSizeBag<T>::isEmpty() const
{
  if (count == 0) return false;
  return true;
}

template<typename T>
std::size_t LimitedSizeBag<T>::getCurrentSize() const
{
  return count;
}

template<typename T>
bool LimitedSizeBag<T>::contains(const T& item) const
{  
  for (std::size_t i = 0; i<count; i++)
  {
    if (items[i] == item) return true;
  }
  return false;
}

template<typename T>
void LimitedSizeBag<T>::clear()
{
  count = 0;
}

template<typename T>
std::size_t LimitedSizeBag<T>::getFrequencyOf(const T & item) const
{
  std::size_t frequency = 0;
  for (std::size_t i = 0; i<count; i++)
  {
    if (items[i] == item) frequency++;
  }
  return frequency;
};
