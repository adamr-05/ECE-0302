#include <stdexcept>

#include "Stack.hpp"

template<class ItemType>
Stack<ItemType>::Stack() 
{
	//initialize headPtr as empty
	headPtr = nullptr;
} 

template<class ItemType>
Stack<ItemType>::~Stack()
{
	//set next to first node
	Node<ItemType>* current = headPtr;

	//loop through all ptrs in sequence
	while (current != nullptr)
	{
		Node<ItemType>* nextNode = current->getNext();//save next node ptr
		delete current;								  //delete current node ptr
		current = nextNode;							  //move currentptr to next
	}
	headPtr = nullptr;
}

template<class ItemType>
bool Stack<ItemType>::isEmpty() const
{
	// TODO
	return true;
}

template<class ItemType>
int Stack<ItemType>::size() const
{
	// TODO
	return 0;
}

template<class ItemType>
bool Stack<ItemType>::push(const ItemType& newItem)
{
	// TODO
	return true;
}

template<class ItemType>
ItemType Stack<ItemType>::peek() const
{
	// TODO
	return ItemType();
}

template<class ItemType>
bool Stack<ItemType>::pop() 
{
	// TODO
	return false;
}

template<class ItemType>
void Stack<ItemType>::clear()
{
	// TODO
}

