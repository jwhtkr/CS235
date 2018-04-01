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
    cout << "rotating left" << endl;
}

void AVL::rotateRight(Node* & tmp)
{
    cout << "rotating right" << endl;
}

void AVL::setBalance(Node* & tmp)
{
    if(tmp -> right != NULL && tmp -> left != NULL)
    {
        tmp -> balance = static_cast<Node::balanceState> 
        (((tmp -> right) -> height) - ((tmp -> left) -> height));
    }
    else if(tmp -> right == NULL && tmp -> left == NULL)
    {
        tmp -> balance = Node::BALANCED;
    }
    else if(tmp -> right != NULL)
    {
        tmp -> balance = static_cast<Node::balanceState> ((tmp -> right) -> height);
    }
    else
    {
        tmp -> balance = static_cast<Node::balanceState> (-(tmp -> left) -> height);
    }

    if(tmp -> balance == Node::UNBALANCED_LEFT || tmp -> balance == Node::UNBALANCED_RIGHT)
    {
        if(tmp -> balance == Node::UNBALANCED_LEFT)
        {
            if((tmp -> left) -> balance == Node::LEFT)
            {
                cout << "Node " << tmp -> value << " has LL unbalance" << endl;
                rotateRight(tmp);
            }
            else
            {
                cout << "Node " << tmp -> value << " has LR unbalance" << endl;
                rotateLeft(tmp -> left);
                rotateRight(tmp);
            }
        }
        else
        {
            if((tmp -> right) -> balance == Node::RIGHT)
            {
                cout << "Node " << tmp -> value << " has RR unbalance" << endl;
                rotateLeft(tmp);
            }
            else
            {
                cout << "Node " << tmp -> value << " has RL unbalance" << endl;
                rotateRight(tmp -> right);
                rotateLeft(tmp);
            }
        }
    }
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
        root = new Node(data);
        // cout << "node " << data << " added at root" << endl;
        return true;
    }
}

bool AVL::add(Node* & current, int data)
{
    bool returnVal = false;
    if (data > current -> value)
    {
        if (current -> right != NULL)a
        {
            returnVal = add(current -> right, data);
            if(returnVal && (current -> height) <= (current -> right) -> height)
            {
                (current -> height) = (current -> right) -> height + 1;
            }
            if (returnVal)
            {
                setBalance(current);
            }
            return returnVal;
        }
        else
        {
            current -> right = new Node(data);
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
            if (returnVal)
            {
                setBalance(current);
            }
            return returnVal;
        }
        else
        {
            current -> left = new Node(data);
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

bool AVL::remove(Node* & tmp, int data)
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