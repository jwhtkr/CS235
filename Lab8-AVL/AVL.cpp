#include "AVL.h"

using namespace std;

AVL::AVL()
{
    root = NULL;
}

AVL::~AVL()
{
    clear();
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

void AVL::setHeight(Node* & current)
{
    if (current != NULL)
    {
        if (current -> right == NULL && current -> left == NULL)
        {
            current -> height = 1;
        }
        else if (current -> right == NULL)
        {
            current -> height = (current -> left) -> height + 1;
        }
        else if (current -> left == NULL)
        {
            current -> height = (current -> right) -> height + 1;
        }
        else
        {
            if ((current -> right) -> height >= (current -> left) -> height)
            {
            current -> height = (current -> right) -> height + 1;
            }
            else if ((current -> right) -> height < (current -> left) -> height)
            {
            current -> height = (current -> left) -> height + 1;
            }
        }
    }
}

void AVL::rotateLeft(Node* & current)
{
    if (current != NULL)
    {
        // cout << "rotating left" << endl;
        Node* tmp = current;
        current = current -> right;
        tmp -> right = current -> left;
        
        current -> left = tmp;
        if(current -> right != NULL)
        {
            setHeight(current -> right);
            setBalance(current -> right);
        }
        if(current -> left != NULL)
        {
            setHeight(current -> left);
            setBalance(current -> left);
        }
        setBalance(current);
        // return current;
    }
}

void AVL::rotateRight(Node* & current)
{
    if (current != NULL)
    {
        // cout << "rotating right" << endl;
        Node* tmp = current;
        current = current -> left;
        tmp -> left = current -> right;
        current -> right = tmp;
        if(current -> right != NULL)
        {
            setHeight(current -> right);
            setBalance(current -> right);
        }
        if(current -> left != NULL)
        {
            setHeight(current -> left);
            setBalance(current -> left);
        }
        setBalance(current);
        
        // return current;
    }
}

void AVL::setBalance(Node* & tmp)
{
    if (tmp != NULL)
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
    }
}

void AVL::balance(Node* & tmp)
{
    if (tmp != NULL)
    {
        if(tmp -> balance == Node::UNBALANCED_LEFT || tmp -> balance == Node::UNBALANCED_RIGHT)
        {
            if(tmp -> balance == Node::UNBALANCED_LEFT)
            {
                if((tmp -> left) -> balance == Node::LEFT||(tmp -> left) -> balance == Node::BALANCED)
                {
                    // cout << "Node " << tmp -> value << " has LL unbalance" << endl;
                    rotateRight(tmp);
                }
                else
                {
                    // cout << "Node " << tmp -> value << " has LR unbalance" << endl;
                    rotateLeft(tmp -> left);
                    rotateRight(tmp);
                }
            }
            else
            {
                if((tmp -> right) -> balance == Node::RIGHT||(tmp -> right) -> balance == Node::BALANCED)
                {
                    // cout << "Node " << tmp -> value << " has RR unbalance" << endl;
                    rotateLeft(tmp);
                }
                else
                {
                    // cout << "Node " << tmp -> value << " has RL unbalance" << endl;
                    rotateRight(tmp -> right);
                    rotateLeft(tmp);
                }
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
        if (current -> right != NULL)
        {
            returnVal = add(current -> right, data);
            // if(returnVal && (current -> height) <= (current -> right) -> height)
            // {
            //     (current -> height) = (current -> right) -> height + 1;
            //     // cout << "Node " << current -> value << " has height " << current -> height << endl;
            // }
            if (returnVal)
            {
                setBalance(current);
                balance(current);
                setHeight(current);
            }
            return returnVal;
        }
        else
        {
            current -> right = new Node(data);
            // cout << "node " << data << " added on right" << endl;
            // if((current -> height) <= (current -> right) -> height)
            // {
            //     (current -> height) = (current -> right) -> height + 1;
            //     // cout << "Node " << current -> value << " has height " << current -> height << endl;
            // }
            setBalance(current);
            balance(current);
            setHeight(current);
            return true;
        }
    }
    else if (data < current -> value)
    {
        if (current -> left != NULL)
        {
            returnVal = add(current -> left, data);
            // if(returnVal && (current -> height) <= (current -> left) -> height)
            // {
            //     (current -> height) = (current -> left) -> height + 1;
            //     // cout << "Node " << current -> value << " has height " << current -> height << endl;
            // }
            if (returnVal)
            {
                setBalance(current);
                balance(current);
                setHeight(current);
            }
            return returnVal;
        }
        else
        {
            current -> left = new Node(data);
            // cout << "node " << data << " added on left" << endl;
            // if((current -> height) <= (current -> left) -> height)
            // {
            //     (current -> height) = (current -> left) -> height + 1;
            //     // cout << "Node " << current -> value << " has height " << current -> height << endl;
            // }
            setBalance(current);
            balance(current);
            setHeight(current);
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
    return remove(this -> root, data);
}

bool AVL::remove(Node* & tmp, int data)
{
    bool returnVal = false;
    if(tmp == NULL)
    {
        return false;
    }
    else
    {
        if (data < tmp -> value)
        {
            returnVal = remove(tmp -> left, data);
            setBalance(tmp);
            balance(tmp);
            setHeight(tmp);
            return returnVal;
        }
        else if (data > tmp -> value)
        {
            returnVal = remove(tmp -> right, data);
            setBalance(tmp);
            balance(tmp);
            setHeight(tmp);
            return returnVal;
        }
        else
        {
            Node* old = tmp;
            if (tmp -> right == NULL)
            {
                tmp = tmp -> left;
            }
            else if (tmp -> left == NULL)
            {
                tmp = tmp -> right;
            }
            else
            {
                replaceParent(old, old -> left);
                setBalance(tmp);
                balance(tmp);
                setHeight(tmp);
            }
            delete old;
            return true;
        }
    }
}

void AVL::replaceParent(Node* & old, Node* & local)
{
    if (local -> right != NULL)
    {
        replaceParent(old, local -> right);
        setBalance(local);
        balance(local);
        setHeight(local);
    }
    else
    {
        old -> value = local -> value;
        old = local;
        local = local -> left;
        if (local != NULL)
        {
            setBalance(local);
            balance(local);
            setHeight(local);
        }
    }
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