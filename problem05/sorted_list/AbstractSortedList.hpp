
#ifndef _ABSTRACT_SORTED_LIST_HPP_
#define _ABSTRACT_SORTED_LIST_HPP_

#include <cstdlib>

template <typename T>
class AbstractSortedList
{
  public:

    /** virtual destructor to ensure overriding */
    virtual ~AbstractSortedList(){};

    /** determine if the list is empty
     * @return true if the list is empty, false otherwise */
    virtual bool isEmpty() const noexcept = 0;

    /** get the length of the list
     * @return the number of items in the list */
    virtual std::size_t getLength() const noexcept = 0;

    /** insert item in sorted order in the list,
     * allowing duplicates
     * @param item item to insert
     * @post item is inserted in sorted order */    
    virtual void insert(const T& item) = 0;

    /** remove first occurrence of item from the list
     * @param item item to remove
     * @throws std::invalid_argument if not found
     * @post item is removed, the order of other items is preserved */
    virtual void remove(const T& item) = 0;

    /** remove item at specified position in the list,
     * uses 0-based indexing
     * @param position index of item to remove
     * @throws std::out_of_range if position is invalid
     * @post item is removed, the order of other items is preserved */
    virtual void removeAt(std::size_t position) = 0;

    /** remove all items from the list
     * @post list is empty */
    virtual void clear() = 0;

    /** get a copy of the item at the specified position,
     * uses 0-based indexing
     * @param position index of item to retrieve
     * @throws std::out_of_range if position is invalid */
    virtual T getEntry(std::size_t position) const = 0;

    /** get the position of the first occurrence of item
     * @param item item to search
     * @throws std::invalid_argument if not found */
    virtual std::size_t getPosition(const T& item) = 0;

};

#endif 
