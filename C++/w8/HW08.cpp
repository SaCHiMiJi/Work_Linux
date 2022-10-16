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
        // int i =0;
        string pre_point,last_move;
        BSTNode *p, *previous, *x, *y = new BSTNode;
        p = root;
        
        if (p == nullptr){
            return ;
        }
        
        while (p->value != value )
        {
            if (p == nullptr){return ;}
            // i++;
            // cout << "i : " << i << endl;
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
        
        
        // case 1 no child
        if (p->left == nullptr && p->right == nullptr)
        {
            cout << "in case 1" << endl;
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
            cout << "in case 2" << endl;

            if (p->left != nullptr) 
            {
                cout << "part 1" << endl;
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
                cout << "part 2" << endl;
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
            // cout << p -> value<< endl;
            // cout << "in1" << endl;
            //case 3.0 child have on child
            if (p == root&& p->left->right == nullptr || p->left->left == nullptr ){
                cout << "in case 3.0" << endl;
                
                root->value = p->right->value;
                root->right = nullptr;
                root->left = p->left;
                // cout << p -> value<< endl;
                // cout << root -> value<< endl;
                // x = p;
                // cout << "in2" << endl;
                free(p);
                
                
                return ;
            }
            
            //case 3.1 child have one child
            if(p->right->left != nullptr)
            {
                cout << "in case 3.1" << endl;
                
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
                cout << "in case 3.1" << endl;

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
                cout << "in case 3.2" << endl;

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
        // cout<<"value : "<<value<<endl;
        int depth=0;
        BSTNode *p;
        
        if (root == NULL){
            return 0;
        }
        
        p = root;
        // cout<<p->value<<endl;
        while (p->value != value )
        {   
            if( p == nullptr){
                break;
            }
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
        cout << "free node" << endl;

        x->left = nullptr;
        x->right = nullptr;
        delete x;

    }
};