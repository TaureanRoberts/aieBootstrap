#pragma once
#include "NodeType.h"
#

template<class Type>
class LinkedListIterator
{
public:
	//Default Constructor
	//Postcondition: current = null
	LinkedListIterator()
	{
		current = NULL;
	}
	//Constructor with a perameter
	//Postcondition: current = ptr
	LinkedListIterator(NodeType<Type> *ptr)
	{
		current = ptr;
	}
	//Function to overload the dereferencion operator *
	//Postcondition: Return the info contained in the node
	Type operator*()
	{
		current->info;
	}
	//Overload the pre-increment the operator
	//PostCondition: The itterator is advanced to the next node
	LinkedListIterator<Type> operator++()
	{
		current = current->link;
		return *this;
	}
	//Overload the eqaulity operator
	//Postconditon: Returns true if this iterator is equal to the iterator specified by
	//right otherwise it returns false
	bool operator ==(const LinkedListIterator<Type>& other) const
	{
		return current == right->current;
	}
	//Overload the not equals operator
	//PostCondition: Return true if this iterator is not equal to the iterator specified by
	//right otherwise it returns false.
	bool operator !=(const LinkedListIterator<Type>& other) const
	{
		return current != right->current;
	}
private:
	//Pointer to point to the current node in the linked list
	NodeType<Type> *current;
};
