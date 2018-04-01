#pragma once

#include "NodeInterface.h"
#include<cstddef>

using namespace std;

class Node : public NodeInterface {
friend class AVL;

protected:
    Node * left;
    Node * right;
    int value;
    int height;
    enum balanceState{UNBALANCED_LEFT = -2, LEFT = -1, BALANCED = 0, RIGHT = 1, UNBALANCED_RIGHT = 2} balance;
public:
	Node() {}
	Node(int);
	virtual ~Node() {}

	/*
	* Returns the data stored in this node
	*
	* @return the data stored in this node.
	*/
	virtual int getData() const;

	/*
	* Returns the left child of this node or null if empty left child.
	*
	* @return the left child of this node or null if empty left child.
	*/
	virtual Node * getLeftChild() const;

	/*
	* Returns the right child of this node or null if empty right child.
	*
	* @return the right child of this node or null if empty right child.
	*/
	virtual Node * getRightChild() const;

	/*
	* Returns the height of this node. The height is the number of nodes
	* along the longest path from this node to a leaf.  While a conventional
	* interface only gives information on the functionality of a class and does
	* not comment on how a class should be implemented, this function has been
	* provided to point you in the right direction for your solution.  For an
	* example on height, see page 448 of the text book.
	*
	* @return the height of this tree with this node as the local root.
	*/
	virtual int getHeight();
	
};