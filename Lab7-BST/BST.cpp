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
    // cout << "getting root...";
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
    if (root != NULL)
    {
        return remove(root, data);
    }
    else {return false;}
}

bool BST::remove(Node* & tmp, int data)
{
    if(tmp != NULL)
    {
        if (data < tmp -> value) 
        {
            return remove(tmp -> left, data);
        }
        else if (data > tmp -> value)
        {
            return remove(tmp -> right, data);
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
                Node* current = tmp -> left;
                Node* previous = current;
                // if (current -> right != NULL)
                // {
                while (current -> right != NULL)
                {
                    previous = current; 
                    current = current -> right;
                    // cout << "previous = " << previous -> value << ", current = " << current -> value << endl;
                }
                // }
                // cout << "switching " << current -> value << " for " << tmp -> value << endl;
                tmp -> value = current -> value;
                // cout << "connecting... "; //<< (current -> left) -> data << " to " << pre
                if (previous != current)
                {
                    previous -> right = current -> left;
                    // cout << previous -> left << " " << previous -> right << endl;
                }
                else
                {
                    tmp -> left = current -> left;
                }
                old = current;
                // replaceParent(old, old -> left);
            }
            // cout << "removing " << old -> value << endl;
            delete old;
            // cout << "removed" << endl;
            return true;
        }
    }
    else
    {
        return false;
    }
}
    
void BST::replaceParent(Node* & old, Node* & local)
{
    if(local -> right != NULL)
    {
        replaceParent(old, local -> right);
    }
    else
    {
        old -> value = local -> value;
        old = local;
        local = local -> left;
    }
}

/*
* Removes all nodes from the tree, resulting in an empty tree.
*/
void BST::clear()
{
    if (root != NULL)
    {
        clear(root);
    }
    return;
}

void BST::clear(Node* & tmp)
{
    if (tmp -> right != NULL)
    {
        clear(tmp -> right);
    }
    if (tmp -> left != NULL)
    {
        clear(tmp -> left);
    }
    delete tmp;
    tmp = NULL;
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