#ifndef STUDENT_ADD_HPP
#define STUDENT_ADD_HPP

#include "AbstractOperator.hpp"

template<typename T> class Add : public AbstractOperator<T>{
  public:

    Add();
    
    ~Add();

    // Add the two arguments arg1+arg2 and return the sum
    T call(T arg1, T arg2) const;

  private:

};

#include "Add.tpp"

#endif 