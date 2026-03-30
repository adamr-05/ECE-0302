#include "SortedList.hpp"

template <typename T, typename L>
SortedList<T, L>::SortedList()
{
  // nothing to do, plist gets created on the stack
}

template <typename T, typename L>
SortedList<T, L>::SortedList(const SortedList<T, L> & x)
{
  plist = x.plist; // uses plist copy assignment
}

template <typename T, typename L>
SortedList<T, L>& SortedList<T, L>::operator=(SortedList<T, L> x)
{
  plist = x.plist; // use plist copy assignment
  return *this;
}

template <typename T, typename L>
SortedList<T, L>::~SortedList()
{
  // plist destructor gets called automatically
}

template <typename T, typename L>
bool SortedList<T, L>::isEmpty() const noexcept
{
  return plist.isEmpty();
}

template <typename T, typename L>
std::size_t SortedList<T, L>::getLength() const noexcept
{
  return plist.getLength();
}

template <typename T, typename L>
void SortedList<T, L>::insert(const T& item)
{
  // TODO
  // Must use range-based for loop syntax!!
  std::size_t pos = 0;

  for (T listItem : plist)
  {
    if (item <= listItem)
    {
      plist.insert(pos, item);
      return;
    }
    pos++;
  }
  plist.insert(pos, item);
}

template <typename T, typename L>
void SortedList<T, L>::remove(const T& item)
{
  // TODO
  // Must use range-based for loop syntax!!

  std::size_t pos = 0;

  for (T listItem : plist)
  {
    if (item == listItem)
    {
      plist.remove(pos);
      return;
    }
    pos++;
  }
  throw std::invalid_argument("remove item not found");


}

template <typename T, typename L>
void SortedList<T, L>::removeAt(std::size_t position)
{
  plist.remove(position);
}

template <typename T, typename L>
void SortedList<T, L>::clear()
{
  plist.clear();
}

template <typename T, typename L>
T SortedList<T, L>::getEntry(std::size_t position) const
{
  return plist.getEntry(position);
}

template <typename T, typename L>
std::size_t SortedList<T, L>::getPosition(const T& newValue)
{
  std::size_t pos = 0;
  for (T item : plist)
  {
    if (item == newValue)
    {
      return pos;
    }
    pos++;
  }
  throw std::invalid_argument("getPosition item not found");
}
