#ifndef _ABSTRACT_BAG_HPP_
#define _ABSTRACT_BAG_HPP_

#include <cstdlib>

template<typename T>
class AbstractBag
{
  public:

    /** virtual destructor to ensure overriding */
    virtual ~AbstractBag(){};

    /** add an item to the bag
     * @param item new item to add
     * @return true if the add was successful (there was space to add), false if not
     * @post item is added to the bag */ 
    virtual bool add(const T & item) = 0;
    
    /** remove the first instance of the item
     * if more than one copy of the item exists, only remove one at a time
     * @param item value of item to remove
     * @return true if the item was found and removed, false if not found
     * @post item is removed from the bag */
    virtual bool remove(const T & item) = 0;

    /** determine if the bag is empty 
     * @return true if there are 0 items in the bag, false otherwise */
    virtual bool isEmpty() const = 0;

    /** get number of items in the bag
     * @return the number of items in the bag */ 
    virtual std::size_t getCurrentSize() const = 0;

    /** remove all items in the bag
     * @post bag contains no items */
    virtual void clear() = 0;

    /** count how many times the specified item occurs in bag
     * @param item value of item to count
     * @return number of occurrences of item */ 
    virtual std::size_t getFrequencyOf(const T & item) const = 0;

    /** check if the specified item is in the bag
     * @param item value of item to find
     * @return true if the item is found in the bag, false if not */ 
    virtual bool contains(const T& item) const = 0;
};

#endif