/** Creates bitset class that can have default or custom size, and has functions such as set, reset, toggle, that can change data of bits.
 * @file Bitset.hpp
 * @author Adam Russell */
  
#ifndef BITSET_HPP
#define BITSET_HPP
#include <stdint.h>
#include <string>

class Bitset{
  public:

    /** Default Destructor.
     * @pre None.
     * @post Memory freed and object deleted.
     */
    virtual ~Bitset(){};
    
    /** Returns the size of the current Bitset as an integer.
     * @pre None.
     * @post None.
     * @return Returns an intmax_t, the total size of the array as an integer
     */
    virtual intmax_t size() const = 0;
    
    /** member function that checks validity of bitset, either valid or invalid, true/false
     * @pre None.
     * @post If bitset is invalid it is flagged as invalid
     * @return True if invalid is set to false, false if invalid is set to true
     */
    virtual bool good() const = 0;
    
    /** Sets nth bit of bitset to 1
     * @param index The index of the bit to set
     * @pre None.
     * @post nth bit in bitset is changed to 1, if index is invalid, the bitset becomes invalid
     */
    virtual void set(intmax_t index) = 0;
    
    /** Sets nth bit of bitset to 0
     * @param index The index of the bit to set
     * @pre None.
     * @post nth bit is changed to 0; if index invalid, bitset becomes invalid
     */
    virtual void reset(intmax_t index) = 0;
    
    /** toggles the nth value of the bitset;    1 -> 0  ;  0 -> 1
     * @param index The index of the bit to set
     * @pre None.
     * @post nth bit is toggled; if index invalid, bitset becomes invalid
     */
    virtual void toggle(intmax_t index) = 0;

    /** Tells the value of the nth bit
     * @param index The index of the bit to set
     * @pre None.
     * @post None.
     * @return Returns true if bit is 1, false otherwise.
     */
    virtual bool test(intmax_t index) = 0;

    /** Returns the bitset as a string
     * @pre None.
     * @post None.
     * @return Returns bitset as a string from the function, converting each int to a string and adding to the end
     */
    virtual std::string asString() const = 0;

};

#endif
