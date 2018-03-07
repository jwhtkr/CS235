#pragma once
#include "LinkedListInterface.h"
#include <sstream>

using namespace std;

template<typename T>
class LinkedList : public LinkedListInterface<T>
{
private:
	struct Node 
	{
	 T data;
	 Node* next;
	 Node(const T& the_data, Node* next_val = NULL) :
	   data(the_data) {next = next_val;}
	};
	
	Node* myList;
	int numItems;

public:

	LinkedList(void) 
	{
		numItems = 0;
		myList = NULL;
	};
	virtual ~LinkedList(void) 
	{
		LinkedList::clear();
	};

	/*
	insertHead

	A node with the given value should be inserted at the beginning of the list.

	Do not allow duplicate values in the list.
	*/
	virtual void insertHead(T value)
	{
		// cout << "in insertHead...";
	    Node* tmp = myList;
	    bool isThere = false;
	    if (myList != NULL)
	    {
	    	// cout << "myList is not NULL...";
		    while (tmp != NULL)
		    {
		    	if (tmp -> data == value)
		    	{
		    		isThere = true;
		    	}
		    	tmp = tmp -> next;
		    }
		    if (!isThere)
		    // {
		    // 	throw out_of_range("insertHead error");
		    // }
		    // else
		    {
		    	tmp = myList;
		    	myList = new Node(value, tmp);
		    	numItems++;
		    	// cout << "new Node created" << endl;
		    }
	    }
	    else
	    {
	    	// cout << "myList is NULL...";
	    	myList = new Node(value, NULL);
	    	numItems++;
	    	// cout << "new Node created" << endl;
	    }
	    return;
	}

	/*
	insertTail

	A node with the given value should be inserted at the end of the list.

	Do not allow duplicate values in the list.
	*/
	virtual void insertTail(T value)
	{
		// cout << "in insertTail...";
	    Node* tmp = myList;
	    bool isThere = false;
	    if (myList != NULL)
	    {
	    	// cout << "myList is not NULL...";
		    while (tmp -> next != NULL)
		    {
		    	if (tmp -> data == value)
		    	{
		    		isThere = true;
		    	}
		    	tmp = tmp -> next;
		    }
	    	if (tmp -> data == value){isThere = true;}
		    if(!isThere)
		    // {
		    // 	throw out_of_range("insertTail error");
		    // }
		    // else
		    {
		    	// cout << "there's no duplicate...";
		    	tmp -> next = new Node(value, NULL);
		    	numItems++;
		    	// cout << "new Node created...";
		    }
	    }
	    else
	    {
	    	// cout << "myList is NULL...";
	    	myList = new Node(value, NULL);
	    	numItems++;
	    	// cout << "new Node created...";
	    }
	    // cout << endl;
	    return;
	}

	/*
	insertAfter

	A node with the given value should be inserted immediately after the
	node whose value is equal to insertionNode.

	A node should only be added if the node whose value is equal to
	insertionNode is in the list. Do not allow duplicate values in the list.
	*/
	virtual void insertAfter(T value, T insertionNode)
	{
		// cout << "in insertAfter..." << "list: " << LinkedList::toString() << "...";
	    Node* tmp = myList;
	    bool isThere = false;
	    if (myList != NULL)
	    {
	    	// cout << "myList is not NULL...";
	    	while (tmp -> next != NULL && !isThere)
		    {
		    	if (tmp -> data == value)
		    	{
		    		isThere = true;
		    		// cout << "there's a duplicate...";
		    	}
		    	tmp = tmp -> next;
		    }
		    if (!isThere)
		    // {
		    // 	throw out_of_range("insertAfter duplicate error");
		    // }
		    // else
		    {
		    	tmp = myList;
		    	while (tmp -> next != NULL)
		    	{
		    		if (tmp -> data == insertionNode)
		    		{
		    			// cout << "found insertionNode...";
		    			Node* tmpNext = tmp -> next;
		    			tmp -> next = new Node(value, tmpNext);
		    			tmp = tmp -> next;
		    			numItems++;
		    			// cout << "new Node created...";
		    			break;
		    		}
		    		else
		    		{
		    			tmp = tmp -> next;
		    		}
		    	}
		    	if (tmp -> data == insertionNode)
		    	{
		    		// cout << "found insertionNode...";
		    		Node* tmpNext = tmp -> next;
		    		tmp -> next = new Node(value, tmpNext);
		    		numItems++;
		    		// cout << "new Node created...";
		    	}
		    }
	    }
	    else
	    {
	    	throw out_of_range("insertAfter no list error");
	    }
	    // cout << endl;
	    return;
	}

	/*
	remove

	The node with the given value should be removed from the list.

	The list may or may not include a node with the given value.
	*/
	virtual void remove(T value)
	{
		Node* tmp = myList;
		if (myList != NULL)
		{
			if (tmp -> data != value)
			{
				while (tmp -> next != NULL)
				{
					if ((tmp -> next) -> data == value)
					{
						Node* tmpAfter = tmp -> next;
						if (tmpAfter != NULL)
						{
							tmpAfter = tmpAfter -> next;
						}
						delete tmp -> next;
						tmp -> next = tmpAfter;
						numItems--;
						break;
					}
					else
					{
						tmp = tmp -> next;
					}
				}
			}
			else
			{
				myList = tmp -> next;
				delete tmp;
				numItems--;
			}
		}
	    return;
	}

	/*
	clear

	Remove all nodes from the list.
	*/
	virtual void clear()
	{
		Node* current = NULL;
	    while (myList != NULL)
		{
			current = myList;
			myList = current->next;
			delete current;
		}
		numItems = 0;
		return;
	}

	/*
	at

	Returns the value of the node at the given index. The list begins at
	index 0.

	If the given index is out of range of the list, throw an out of range exception.
	*/
	virtual T at(int index)
	{
	    if(index < 0 || index >= numItems)
	    {
	    	throw out_of_range("at error");
	    }
	    else
	    {
	    	Node* tmp = myList;
	    	for(int i = 0; i < index; i++)
	    	{
	    		tmp = tmp -> next;
	    	}
	    	return tmp -> data;
	    }
	}

	/*
	size

	Returns the number of nodes in the list.
	*/
	virtual int size()
	{
	    return numItems;
	}

	/*
	toString
	
	Returns a string representation of the list, with the value of each node listed in order (Starting from the head) and separated by a single space
	There should be no trailing space at the end of the string

	For example, a LinkedList containing the value 1, 2, 3, 4, and 5 should return
	"1 2 3 4 5"
	*/
	virtual string toString()
	{
	    ostringstream ss;
	    Node* tmp = myList;
	    while (tmp != NULL)
	    {
	    	ss << tmp -> data;
	    	if (tmp -> next != NULL)
	    	{
	    		ss << " ";
	    	}
	    	tmp = tmp -> next;
	    }
	    return ss.str();
	}

};