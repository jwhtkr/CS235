#include "Node.h"

using namespace std;

Node::Node(int val, Node* less, Node* more)
{
    value = val;
    left = less;
    right = more;
}

Node::Node(int val)
{
    value = val;
    left = NULL;
    right = NULL;
}
/*
* Returns the data that is stored in this node
*
* @return the data that is stored in this node.
*/
int Node::getData() const
{
    return value;
}

/*
* Returns the left child of this node or null if it doesn't have one.
*
* @return the left child of this node or null if it doesn't have one.
*/
Node * Node::getLeftChild() const
{
    return left;
}

/*
* Returns the right child of this node or null if it doesn't have one.
*
* @return the right child of this node or null if it doesn't have one.
*/
Node * Node::getRightChild() const
{
    return right;
}
