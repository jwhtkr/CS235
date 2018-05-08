#include "Node.h"

using namespace std;

Node::Node(int data)
{
    value = data;
    height = 1;
    left = NULL;
    right = NULL;
    balance = BALANCED;
}

/*
* Returns the data stored in this node
*
* @return the data stored in this node.
*/
int Node::getData() const
{
    return this -> value;
}

/*
* Returns the left child of this node or null if empty left child.
*
* @return the left child of this node or null if empty left child.
*/
Node * Node::getLeftChild() const
{
    return this -> left;
}

/*
* Returns the right child of this node or null if empty right child.
*
* @return the right child of this node or null if empty right child.
*/
Node * Node::getRightChild() const
{
    return this -> right;
}

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
int Node::getHeight()
{
    return this -> height;
}


int Node::getBalance()
{
    return static_cast<int>(this -> balance);
}