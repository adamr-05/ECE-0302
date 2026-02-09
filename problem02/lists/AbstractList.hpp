
#ifndef _ABSTRACT_LIST_HPP_
#define _ABSTRACT_LIST_HPP_

#include <cstdlib>

template <typename T>
class AbstractList
{
  public:

    /** virtual destructor to ensure overriding */
    virtual ~AbstractList(){};

    /** determine if the list is empty 
     * @return true if the list is empty, false otherwise */
    virtual bool isEmpty() const noexcept = 0;

    /** get the length of the list 
     * @return the number of items in the list */ 
    virtual std::size_t getLength() const noexcept = 0;

    /** insert item at specified position in the list, 
     * uses 0-based indexing
     * @param position index to insert the item
     * @param item item to insert
     * @throws std::out_of_range if position is invalid
     * @post item is inserted at position, 
     * the order of other items is preserved */ 
    virtual void insert(std::size_t position, const T& item) = 0;

    /** remove item at specified position in the list,
     * uses 0-based indexing 
     * @param position index of item to remove
     * @throws std::out_of_range if position is invalid
     * @post item is removed, the order of other items is preserved */ 
    virtual void remove(std::size_t position) = 0;

    /** remove all items from the list 
     * @post list is empty */ 
    virtual void clear() = 0;

    /** get a copy of the item at the specified position,
     * uses 0-based indexing 
     * @param position index of item to retrieve
     * @throws std::out_of_range if position is invalid */ 
    virtual T getEntry(std::size_t position) const = 0;

    /** change the value of the item at the specified position,
     * uses 0-based indexing 
     * @param position index of item to set
     * @param newValue new value of the item at the specified position
     * @throws std::out_of_range if position is invalid 
     * @post item value at position is now newValue */ 
    virtual void setEntry(std::size_t position, const T& newValue) = 0;
  
};

#endif
