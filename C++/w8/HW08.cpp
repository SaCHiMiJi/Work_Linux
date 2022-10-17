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
    void delete_element(BSTNode *a, BSTNode *before, int value) {
        if (a != nullptr) {
            if (value < a->value) {
                before = a;
                delete_element(a->left, before, value);
            } else if (value > a->value) {
                before = a;
                delete_element(a->right, before, value);
            } else {
                if (a->left == nullptr && a->right == nullptr) {
                // cout << "Both empty"
                //<< "\n";
                if (before->value == a->value) {
                    root = nullptr;
            
                } else if (before->left->value == a->value){
                    before->left = nullptr;
                } else {
                    before->right = nullptr;
                }
                } else if (a->left == nullptr) {
                // cout << "child on right";
                if (before->value == a->value) {
                    root = a->right;
                } else if (before->left->value == a->value) {
                    before->left = a->right;
                    // cout <<" insert "<<before->left->value<<"\n";
                } else {
                    before->right = a->right;
                    // cout <<" insert "<<before->right->value<<"\n";
                }
                } else if (a->right == nullptr) {
                // cout << "child on left";
                if (before->value == a->value) {
                    root = a->left;
                } else if (before->left->value == a->value) {
                    before->left = a->left;
                    // cout <<" insert "<<before->left->value<<"\n";
                } else {
                    before->right = a->left;
                    // cout <<" insert "<<before->right->value<<"\n";
                }
                } else {
                // cout << "Both child"<<"\n";
                BSTNode *Curr = new BSTNode;
                Curr = MinNode(a->right);
                // cout << "minnode = "<<Curr->value<<"\n";
                int num = Curr->value;
                delete_element(root, root, Curr->value);
                if (before->value == a->value) {
                    before->value = num;
                } else if (before->left->value == a->value) {
                    before->left->value = num;
                } else {
                    before->right->value = num;
                }
                }
            }
        }
    }
  void remove(int value) { delete_element(root, root, value); }
  BSTNode *MinNode(BSTNode *a) {

    /* loop down to find the leftmost leaf */
    while (a != nullptr && a->left != nullptr)
      a = a->left;

    return a;
  }
};