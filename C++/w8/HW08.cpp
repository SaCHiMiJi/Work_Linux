#include "BSTNode.cpp"
#include<iostream>
#include <string>
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
        int i =0;
        string pre_point,last_move;
        BSTNode *p, *previous, *x, *y = new BSTNode;
        p = root;
        
        if (p == nullptr){
            return ;
        }
        
        while (p->value != value )
        {
            if (p == nullptr){return ;}
            i++;
            cout << "i : " << i << endl;
            previous = p;
            if (p->value > value)
            {
                p = p->left;
                pre_point = "left";
            }
            else
            {
                p = p->right;
                pre_point = "right";
            }
            
            
        }
        cout << (p == root) << endl;
        
        // case 1 no child
        if (p->left == nullptr && p->right == nullptr)
        {
            if (pre_point == "left")
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
                if (pre_point == "left")
                {
                    x = previous->left;
                    previous->left = x->left;
                }
                else // pre_point == "right" 
                {
                    x = previous->right;
                    previous->right = x->left;
                }
                free(x);
            }
            else // (p->right != nullptr)
            {
                if (pre_point == "left")
                {
                    x = previous->left;
                    previous->left = x->right;
                }
                else // pre_point == "right" 
                {
                    x = previous->right;
                    previous->right = x->right;
                }
                free(x);
            }
        }
        // case 3 two child
        else
        {
            cout << p -> value<< endl;
            cout << "in1" << endl;
            if (p == root){
                root->right = nullptr;
                root->left = p->left;
                root->value = p->right->value;
                // cout << p -> value<< endl;
                // cout << root -> value<< endl;
                // x = p;
                cout << "in2" << endl;
                free(p);
                
                
                return ;
            }
            
            //case 3.1 child have one child
            if(p->right->left != nullptr)
            {
                
                if (pre_point == "left")
                {
                    x = previous->left;
                }
                else // pre_point == "right" 
                {
                    x = previous->right;
                }
                y = x->right;
                x->value = y->value;
                x->right = y->left;
                free(y);
            }
            else if (p->right->right == nullptr)
            {
                if (pre_point == "left")
                {
                    x = previous->left;
                }
                else // pre_point == "right" 
                {
                    x = previous->right;
                }
                cout << x->value<<endl;
                y = x->right;
                x->value = y->value;
                x->right = y->right;
                free(y);
            }
            //case 3.2 child have two child
            else
            {
                BSTNode *pre_y = new BSTNode;
                if (pre_point == "left")
                {
                    x = previous->left;
                }
                else // pre_point == "right" 
                {
                    x = previous->right;
                }

                y = p -> right;

                while (y != nullptr)
                {
                    pre_y = y;
                    y = y->left;    
                }
                x->value = y->value;
                pre_y->left = nullptr;
                free(y);
                
            }

            
        }
    }

    int get_depth(int value)
    {
        int depth=0;
        BSTNode *p;
        
        if (root == NULL){
            return 0;
        }
        p = root;
        while (p->value != value  && p != nullptr)
        {
            if (p->value > value )
            {
                p = p->left;
            }
            else
            {
                p = p->right;
            }
            depth++;
        }
        if (p != nullptr){
            return depth;
        }
        else
        {
            return -1;
        }
        

    }

    void free(BSTNode *x)
    {
        x->left = nullptr;
        x->right = nullptr;
        delete x;
        cout << "in4" << endl;

    }
};