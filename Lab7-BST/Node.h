#pragma once
#include "NodeInterface.h"

class Node: public NodeInterface 
{

public:
	Node() {}
	virtual ~Node() {}

	/*
	* Returns the data that is stored in this node
	*
	* @return the data that is stored in this node.
	*/
	virtual int getData() const;

	/*
	* Returns the left child of this node or null if it doesn't have one.
	*
	* @return the left child of this node or null if it doesn't have one.
	*/
	virtual Node * getLeftChild() const;

	/*
	* Returns the right child of this node or null if it doesn't have one.
	*
	* @return the right child of this node or null if it doesn't have one.
	*/
	virtual Node * getRightChild() const;

};