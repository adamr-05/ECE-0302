#ifndef BITSET_HPP
#define BITSET_HPP
#include <stdint.h>
#include <string>

class Bitset{
  public:

    // basic destructor
    virtual ~Bitset(){};
    
    // size member function that returns an "intmax_t", or any value of integers in your implementation
    virtual intmax_t size() const = 0;
    
    // member function that checks validity of bitset, either valid or invalid, true/false
    virtual bool good() const = 0;
    
    // TODO COMMENT
    virtual void set(intmax_t index) = 0;
    
    // TODO COMMENT
    virtual void reset(intmax_t index) = 0;
    
    // TODO COMMENT
    virtual void toggle(intmax_t index) = 0;

    // TODO COMMENT
    virtual bool test(intmax_t index) = 0;

    // TODO COMMENT
    virtual std::string asString() const = 0;

};

#endif
