#include "AVL.h"

using namespace std;

AVL::AVL()
{
    root = NULL;
}

/*
* Returns the root node for this tree
*
* @return the root node for this tree.
*/
Node * AVL::getRootNode() const
{
    return this -> root;
}

void AVL::rotateLeft(Node* & tmp)
{
    
}

void AVL::rotateRight(Node* & tmp)
{
    
}

/*
* Attempts to add the given int to the AVL tree
* Rebalances the tree if data is successfully added
*
* @return true if added
* @return false if unsuccessful (i.e. the int is already in tree)
*/
bool AVL::add(int data)
{
    if (root != NULL)
    {
        return add(root, data);
    }
    else
    {
        root = new Node(data, 0);
        // cout << "node " << data << " added at root" << endl;
        return true;
    }
}

bool AVL::add(Node* & current, int data)
{
    bool returnVal = false;
    if (data > current -> value)
    {
        if (current -> right != NULL)
        {
            returnVal = add(current -> right, data);
            if(returnVal && (current -> height) <= (current -> right) -> height)
            {
                (current -> height) = (current -> right) -> height + 1;
            }
            return returnVal;
        }
        else
        {
            current -> right = new Node(data, 0);
            // cout << "node " << data << " added on right" << endl;
            if((current -> height) <= (current -> right) -> height)
            {
                (current -> height) = (current -> right) -> height + 1;
            }
            return true;
        }
    }
    else if (data < current -> value)
    {
        if (current -> left != NULL)
        {
            returnVal = add(current -> left, data);
            if(returnVal && (current -> height) <= (current -> left) -> height)
            {
                (current -> height) = (current -> left) -> height + 1;
            }
            return returnVal;
        }
        else
        {
            current -> left = new Node(data, 0);
            // cout << "node " << data << " added on left" << endl;
            if((current -> height) <= (current -> left) -> height)
            {
                (current -> height) = (current -> left) -> height + 1;
            }
            return true;
        }
    }
    else
    {
        return returnVal;
    }
}

/*
* Attempts to remove the given int from the AVL tree
* Rebalances the tree if data is successfully removed
*
* @return true if successfully removed
* @return false if remove is unsuccessful(i.e. the int is not in the tree)
*/
bool AVL::remove(int data)
{
    if (root != NULL)
    {
        return remove(root, data);
    }
    else
    {
        return false;
    }
}

bool AVL::remove(Node* & tmp, data)
{
    
}

/*
* Removes all nodes from the tree, resulting in an empty tree.
*/
void AVL::clear()
{
    if (root != NULL)
    {
        clear(root);
    }
    return;
}

void AVL::clear(Node* & tmp)
{
    if (tmp -> right != NULL)
    {
        clear(tmp -> right);
    }
    if (tmp -> left != NULL)
    {
        clear(tmp -> left);
    }
    // cout << "node " << tmp -> value << " being deleted" << endl;
    delete tmp;
    tmp = NULL;
    // cout << "root = " << this -> root << endl;
}