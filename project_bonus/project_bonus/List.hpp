#ifndef _LIST_HPP_
#define _LIST_HPP_

#include <cstdlib>
#include <stdexcept>
#include "AbstractList.hpp"

template <typename T>
class List: public AbstractList<T>
{
public:
  
  List();
  
  List(const List& x);
    
  ~List();
  
  List& operator=(List x);

  void swap(List& x);
  
  bool isEmpty() const noexcept;

  std::size_t getLength() const noexcept;

  void insert(std::size_t position, const T& item);

  void remove(std::size_t position);

  void clear();

  T getEntry(std::size_t position) const;

  void setEntry(std::size_t position, const T& newValue);

private:

  template <typename U>
  struct Node {
    U item;
    Node<U>* next;
    Node(const U& i, Node<U>* n) : item(i), next(n) {}
    U getItem() const { return item; }
    Node<U>* getNext() const { return next; }
    void setItem(const U& i) { item = i; }
    void setNext(Node<U>* n) { next = n; }
  };

  Node<T>* headptr;
  std::size_t length;
  
};

#include "List.tpp"

#endif