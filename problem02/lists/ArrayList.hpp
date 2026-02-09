#ifndef ARRAY_LIST_HPP
#define ARRAY_LIST_HPP

#include "AbstractList.hpp"

template<typename T>
class ArrayList: public AbstractList<T>
{
  public:

    ArrayList();

    ~ArrayList();

    ArrayList(const ArrayList& rhs);

    ArrayList& operator=(ArrayList rhs);

    // use for copy swap idiom
    void swap(ArrayList& rhs);
    
    bool isEmpty() const noexcept;

    std::size_t getLength() const noexcept;
    
    void insert(std::size_t position, const T& item);

    void remove(std::size_t position);

    void clear();

    T getEntry(std::size_t position) const;

    void setEntry(std::size_t position, const T& newValue);

  private:

    T* data;
    std::size_t length;
  
};

#include "ArrayList.tpp"

#endif
