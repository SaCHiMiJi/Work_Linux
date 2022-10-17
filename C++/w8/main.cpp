#include<iostream>
#include "HW08.cpp"
using namespace std;

int main() {
    BST tree;

    tree.insert(2);
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);
    tree.insert(6);
    tree.insert(4);
    
    cout << tree.get_depth(1) << endl;
    cout << tree.get_depth(2) << endl;
    cout << tree.get_depth(3) << endl;
    cout << tree.get_depth(4) << endl;
    cout << tree.get_depth(5) << endl;
    cout << tree.get_depth(6) << endl;
    
    tree.remove(2);
    
    cout << tree.get_depth(1) << endl;
    cout << tree.get_depth(2) << endl;
    cout << tree.get_depth(3) << endl;
    cout << tree.get_depth(4) << endl;
    cout << tree.get_depth(5) << endl;
    cout << tree.get_depth(6) << endl;
    
    return 0;
}