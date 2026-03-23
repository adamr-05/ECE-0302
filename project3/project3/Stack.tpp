#include <stdexcept>

#include "Stack.hpp"

template<class ItemType>
Stack<ItemType>::Stack() 
{
	//initialize headPtr as empty
	headPtr = nullptr;
	currentSize = 0;
} 

template<class ItemType>
Stack<ItemType>::~Stack()
{
	clear();
}

template<class ItemType>
bool Stack<ItemType>::isEmpty() const
{	
	//if headPtr is set to null, the list is empty
	return headPtr == nullptr;
}

template<class ItemType>
int Stack<ItemType>::size() const
{
	return currentSize;
}

template<class ItemType>
bool Stack<ItemType>::push(const ItemType& newItem)
{
	Node<ItemType>* temp = new Node<ItemType>(newItem);

	if (temp == nullptr) return false;

	temp->setNext(headPtr);
	headPtr = temp;
	currentSize++;
	return true;
}

template<class ItemType>
ItemType Stack<ItemType>::peek() const
{
	if (headPtr == nullptr)
	{
		throw std::logic_error("Stack is empty");
	}
	return headPtr->getItem();
}

template<class ItemType>
bool Stack<ItemType>::pop() 
{
	if (headPtr == nullptr)
	{
		return false;
	}
	Node<ItemType>* temp = headPtr;
	headPtr = headPtr->getNext();

	delete temp;
	currentSize--;
	return true;
}

template<class ItemType>
void Stack<ItemType>::clear()
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
	currentSize = 0;
	headPtr = nullptr;
}

