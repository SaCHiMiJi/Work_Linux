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

    void remove(int value)
    {
        // int i =0;
        BSTNode *p, = root;
        BSTNode *previous = nullptr;

        while (p != nullptr && p->value != value)
        {

            previous = p;
            if (p->value > value)
            {
                p = p->left;
            }
            else
            {
                p = p->right;
            }
        }
        // tree empty
        if (p == nullptr)
        {
            return;
        } 
        // leaf child
        if (isLeaf(p)) 
        {
            if (p != root)
            {
                if (p->left == p)
                {
                    previous->left = nullptr;
                }
                else
                {
                    previous->right = nullptr;
                }
            }
            else
            {
                root = nullptr;
            }

            free(p);
        }
        // two child
        else if (p->left && p->right)
        {
            BSTNode *l_most = leftMost(p->right);
            int v_lmost = l_most->value;
            remove(v_lmost);
            p->value = v_lmost;
        }
        else
        {
            if (p != root)
            {
                if (p == previous->left)
                {
                    previous->left = oneChild(p);
                }
                else
                {
                    previous->right = oneChild(p);
                }
            }
            else
            {
                root = oneChild(p);
            }
            free(p);
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

    void free(BSTNode *x)
    {
        // cout << "free node" << endl;
        delete x;
    }
    bool isLeaf(BSTNode *p)
    {
        return (p->left != nullptr && p->right == nullptr);
    }

    BSTNode *oneChild(BSTNode *p)
    {
        if (p->left != nullptr && p->right == nullptr)
        {
            return p->left;
        }
        else if (p->left == nullptr && p->right != nullptr)
        {
            return p->right;
        }
    }

    BSTNode *leftMost(BSTNode *p)
    {
        while (p->left != nullptr)
        {
            p = p->left;
        }
        return p;
    }
};