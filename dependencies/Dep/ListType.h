#pragma once
#include <iostream>
#include "NodeType.h"
#include "ListIterator.h"
#include <cassert>

using namespace std;
template<class Type>
class LinkedListType
{
protected:
	//Variable to store the number of elements in the list
	int count; 
	//Pointer to the first node of the list.
	NodeType<Type> *first;
	//Pointer to the last node of the list.
	NodeType<Type> *last;

public:
	//Overload the assignment operator
	const LinkedListType<Type>& operator =(const LinkedListType<Type>& other)
	{
		return other.CopyList();
	}

	//Initialize the list to an empty state
	//PostCondition: first = NULL, last = NULL, count = 0
	void InitializeList()
	{
		DestroyList();
	}

	//Function to determine whether the list is empty in the list PostCondition
	//PostCondition: Returns true if the list is empty otherwise it returns false
	bool IsEmptyList()
	{
		return true;
	}

	//Function to return the number of nodes in the list
	//PostCondition: node
	const void Print()
	{
		NodeType<Type> *showMe;
		showMe = first;
		for (int i = 0; i < count; i++)
		{
			cout << showMe->info << endl;
			showMe = showMe->link;
		}
	}

	//Function to return the nodes in the list
	//Postcondition: The value of count is returned
	int Length()
	{
		return count;
	}

	//Function to return the nodes in the list
	//Post Condition: first = NULL, last = NULL, and count = 0
	void DestroyList()
	{
		NodeType<Type> *temp;
		for (int i = 0; i>count; i++)
		{
			temp = first;
			first = first->link;
			delete temp;
		}
		last = NULL;
		count = 0;
	}

	//Function to return the first element of the list
	//Precondition: The list must exist and must not be empty
	//PostCondition: If the list is empty , the program terminatese
	Type Front()
	{
		assert(first != NULL);
		return first;
	}

	//Function to return the last element of the list
	//Precondition: The list must exist and not be empty. 
	//PostCondition:if the list is empty, the program terminates; otherwise,
	//the last element of the list is returned
	Type Back()
	{
		assert(last != NULL);
		return last->info;
	}

	//Function to determine whether other is in the list
	//PostCondition: Returns true if other is in the list, otherwise the value false is returned
	const bool Search(const Type& other)
	{
		NodeType<Type> temp;
		temp = first;
		while (temp != NULL)
		{
			if (other == temp.info)
			{
				return true;
			}
			temp = temp->link;
		}
		return false;
	}

	//Function to insert other at the beginning of the list
	//PostCondition: First points to the new list, other is inserted at the beginning of the list
	//last points to the last node in the list, and count in incremented by 1
	void InsertFirst(const Type &other)
	{ 
		NodeType<Type> *someFirst = new NodeType<Type>;
		someFirst->info = other;
		someFirst->link = first;
		first = someFirst;
		if (count == 0)
		{
			last = first;
		}
		count++;
	}

	//Function to insert other at the end of the list
	//PostCondition: first points to the new list, other is inserted at teh end of the list,
	//last points to the last node in the list and count is incremented by 1
	void InsertLast(const Type& other)
	{
		NodeType<Type> *someLast = new NodeType<Type>;
		someLast->info = other;
		if (count != 0)
		{
			last->link = someLast;
		}
		else
			first = last;
		last = someLast;
		count++;
	}

	//Function to delete other from the list
	//PostCondition: If found the node containing other is deleted from the list.
	//First points to the first node, list points to the last node of the updated list, and counts
	// is decremented by 1
	void DeleteNode(const Type& other)
	{
		delete other;
		if (count > 0)
		{
			count -= 1;
		}
	}

	//Function to return an iterator at the beginning of the linked list
	//PostCondition: Returns an iterator such that current is set to first 
	LinkedListIterator<Type> Begin()
	{
		LinkedListIterator<Type> *temp = new LinkedListIterator<Type>();
		temp->current = first;
		return first; 
	}

	//Function to return an iterator at the end of the linked list
	//PostCondition: Returns an iterator such current is set to NULL
	LinkedListIterator<Type> End()
	{
		LinkedListIterator<Type> *temp = new LinkedListIterator<Type>();
		temp->current = last;
		return last;
	}

	//Default Constructor
	LinkedListType()
	{
		first = NULL;
		last = NULL;
		count = 0;
	}

	//
	//Constructor that takes in an arguement that 
	LinkedListType(const LinkedListType<Type>&other)
	{
		InitializeList();
		CopyList(other);
	}

	//Default Deconstructor
	~LinkedListType()
	{
		DestroyList();
	}
private:
	//Function to make a copy of other.
	//PostCondition: A copy of other is created and assigned to this list
	void CopyList(const LinkedListType<Type>&other)
	{
		DestroyList();
		NodeType<Type> *myNode = new NodeType<Type>;
		myNode->info = other.first->info;
		InsertFirst(myNode->info);
		for(int i = 0; i < other.count-1; i++)
		{
			InsertLast(myNode->info);
			myNode = myNode->link;
		}
	}
};