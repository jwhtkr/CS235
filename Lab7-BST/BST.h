#pragma once
#include "BSTInterface.h"
#include "Node.h"

using namespace std;

class BST : public BSTInterface 
{
protected:
Node* root;
    
public:
	BST() {root = NULL;}
	virtual ~BST() {clear();}

	//Please note that the class that implements this interface must be made
	//of objects which implement the NodeInterface

	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	virtual Node * getRootNode() const;

	/*
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
	virtual bool add(int data);

	/*
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
	virtual bool remove(int data);
	
	virtual bool remove(Node* &, int);
	
	virtual void replaceParent(Node* &, Node* &);

	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	virtual void clear();
	
	virtual void clear(Node* &);
	
	virtual Node* find(int);
};
