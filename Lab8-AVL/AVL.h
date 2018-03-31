#pragma once

#include "AVLInterface.h"
#include "Node.h"
#include <iostream>

using namespace std;

class AVL : public AVLInterface {
protected:
    Node * root;
    
public:
	AVL();
	virtual ~AVL() {}

	//Please note that the class that implements this interface must be made
	//of objects which implement the NodeInterface

	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	virtual Node * getRootNode() const;
	
	virtual void rotateLeft(Node* &);
	virtual void rotateRight(Node* &);

	/*
	* Attempts to add the given int to the AVL tree
	* Rebalances the tree if data is successfully added
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
	virtual bool add(int data);
	
	virtual bool add(Node* &, int);

	/*
	* Attempts to remove the given int from the AVL tree
	* Rebalances the tree if data is successfully removed
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
	virtual bool remove(int data);
	
	virtual bool remove(Node* &, int);

	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	virtual void clear();
	
	virtual void clear(Node* &);
};