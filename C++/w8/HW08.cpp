#include "BSTNode.cpp"
#include <string>

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
        BSTNode *p, *previous, *new_node;
        new_node->value = value
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
        return root;
    }

    void remove(int value)
    {
        string text ="";
        BSTNode *p, *previous, *x;
        p = root;
        while (p != value)
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
        if (previous->left->value == value)
        {
            x = previous->left;
        }
        else if (previous->right->value == value)
        {
            x = previous->right;
        }

        // case 1 no child
        if (p->left == nullptr && p->right == nullptr)
        {
            if (previous ->left->value == value)
            {
                 previous->left = nullptr;
            }
            else
            {
                 previous->right = nullptr;
            }
            free(x);
        }
        // case 2 one child
        else if ((p->left != nullptr && p->right == nullptr) || (p->left == nullptr && p->right != nullptr))
        {
            if (p->left != nullptr)
            {
                previous->right = x;
                free(x);
            }
            else if (p->right != nullptr)
            {
                previous->left = x;
                free(x);
            }
        }
        // case 3 two child
        else
        {
            
        }
        
    }

    int get_depth(int value)
    {
        /*
         Write your code here
         */
        return -1;
    }

    void free(BSTNode *x)
    {
        x->value = 0;
        x->left = nullptr;
        x->right = nullptr;
        delete x;
    }
};