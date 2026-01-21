#ifndef BITARRAY_HPP
#define BITARRAY_HPP
#include <stdint.h>
#include <string>

#include "Bitset.hpp"

class BitArray : public Bitset{
public:

  BitArray(); //default constructor

  BitArray(intmax_t size); // parameterized constructor w/ integer

  BitArray(const std::string & value); // parameterized constructor w/ string.  value passed as const reference, cannot be modified and prevents copying large data by value

  ~BitArray(); //destructor

  BitArray(const BitArray & ) = delete;               // delete copy constructor and copy assignment operator,
  BitArray & operator=(const BitArray &) = delete;    // as we are not using them according to problem specs.

  intmax_t size() const;

  bool good() const;

  void set(intmax_t index);

  void reset(intmax_t index);

  void toggle(intmax_t index);

  bool test(intmax_t index);

  std::string asString() const;

private:

  // TODO
};

#endif
