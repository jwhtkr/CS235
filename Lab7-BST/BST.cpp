#include "BST.h"

using namespace std;

//Please note that the class that implements this interface must be made
//of objects which implement the NodeInterface

Node* find(int);

/*
* Returns the root node for this tree
*
* @return the root node for this tree.
*/
Node * BST::getRootNode() const
{
    return root;
}

/*
* Attempts to add the given int to the BST tree
*
* @return true if added
* @return false if unsuccessful (i.e. the int is already in tree)
*/
bool BST::add(int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return true;
    }
    else
    {
        Node* tmp = find(data);
        if (data < tmp -> value)
        {
            tmp -> left = new Node(data);
            return true;
        }
        else if (data > tmp -> getData())
        {
            tmp -> right = new Node(data);
            return true;
        }
        else
        {
            return false;
        }
    }
}

/*
* Attempts to remove the given int from the BST tree
*
* @return true if successfully removed
* @return false if remove is unsuccessful(i.e. the int is not in the tree)
*/
bool BST::remove(int data)
{
    
}

/*
* Removes all nodes from the tree, resulting in an empty tree.
*/
void BST::clear()
{
    
}

Node* BST::find (int data)
{
    Node* tmp = root;
    Node* current = tmp;
    while (current != NULL)
    {
        tmp = current;
        if(data < current -> value)
        {
            current = current -> left;
        }
        else if (data > current -> value)
        {
            current = current -> right;
        }
        else
        {
            break;
        }
    }
    return tmp;
}