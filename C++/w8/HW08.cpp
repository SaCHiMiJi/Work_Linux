#include "BSTNode.cpp"
#include <iostream>
using namespace std;
class BST
{

public:
    BSTNode *root;

    BST()
    {
        root = nullptr;
    }

    void insert(int value)
    {
        // cout<<"in"<<endl;
        BSTNode *p, *previous, *new_node = new BSTNode;
        new_node->value = value;
        new_node->left = nullptr;
        new_node->right = nullptr;

        if (root == nullptr)
        {
            root = new_node;
        }
        else
        {
            p = root;
            while (p != nullptr)
            {
                previous = p;
                if (p->value > new_node->value)
                {
                    p = p->left;
                }
                else
                {
                    p = p->right;
                }
            }
            if (previous->value > new_node->value)
            {
                previous->left = new_node;
            }
            else
            {
                previous->right = new_node;
            }
        }
    }

    int get_depth(int value)
    {
        // cout<<"value : "<<value<<endl;
        int depth = 0;
        BSTNode *p;

        if (root == NULL)
        {
            return 0;
        }

        p = root;
        // cout<<p->value<<endl;
        while (p != nullptr)
        {
            if (p->value != value)
            {
                if (p->value > value)
                {
                    p = p->left;
                }
                else
                {
                    p = p->right;
                }
                depth++;
            }
            else
            {
                break;
            }
        }
        if (p != nullptr)
        {
            return depth;
        }
        else
        {
            return -1;
        }
    }
    void delete_Node(BSTNode *p, BSTNode *previous, int value)
    {
        if (p != nullptr)
        {
            if (value < p->value)
            {
                previous = p;
                delete_Node(p->left, previous, value);
            }
            else if (value > p->value)
            {
                previous = p;
                delete_Node(p->right, previous, value);
            }
            else
            {
                if (p->left == nullptr && p->right == nullptr)
                {
                    // cout << "Both empty"
                    //<< "\n";
                    if (previous->value == p->value)
                    {
                        root = nullptr;
                    }
                    else if (previous->left->value == p->value)
                    {
                        previous->left = nullptr;
                    }
                    else
                    {
                        previous->right = nullptr;
                    }
                }
                else if (p->left == nullptr)
                {
                    // cout << "child on right";
                    if (previous->value == p->value)
                    {
                        root = p->right;
                    }
                    else if (previous->left->value == p->value)
                    {
                        previous->left = p->right;
                        // cout <<" insert "<<previous->left->value<<"\n";
                    }
                    else
                    {
                        previous->right = p->right;
                        // cout <<" insert "<<previous->right->value<<"\n";
                    }
                }
                else if (p->right == nullptr)
                {
                    // cout << "child on left";
                    if (previous->value == p->value)
                    {
                        root = p->left;
                    }
                    else if (previous->left->value == p->value)
                    {
                        previous->left = p->left;
                        // cout <<" insert "<<previous->left->value<<"\n";
                    }
                    else
                    {
                        previous->right = p->left;
                        // cout <<" insert "<<previous->right->value<<"\n";
                    }
                }
                else
                {
                    // cout << "Both child"<<"\n";
                    BSTNode *Curr = new BSTNode;
                    Curr = MinNode(p->right);
                    // cout << "minnode = "<<Curr->value<<"\n";
                    int num = Curr->value;
                    delete_Node(root, root, Curr->value);
                    if (previous->value == p->value)
                    {
                        previous->value = num;
                    }
                    else if (previous->left->value == p->value)
                    {
                        previous->left->value = num;
                    }
                    else
                    {
                        previous->right->value = num;
                    }
                }
            }
        }
    }
    void remove(int value)
    {
        delete_Node(root, root, value);
    }
    BSTNode *MinNode(BSTNode *p)
    {

        /* loop down to find the leftmost leaf */
        while (p != nullptr && p->left != nullptr)
            p = p->left;

        return p;
    }
};