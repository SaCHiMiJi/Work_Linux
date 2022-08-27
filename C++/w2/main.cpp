#include <iostream>
#include "HW02_t.cpp"
using namespace std;
int main()
{
    Trip T;
    T.insert_front("UENO");
    T.insert_front("KANDA");
    T.insert_front("TOKYO");
    T.insert_back("ASAKUSA");
    T.insert_back("A");
    // T.insert_back("B");
    // T.insert_back("C");
    T.insert_front("D");
    // T.insert_front("F");
    T.remove_back();
    T.remove_front();
    T.printList();
    Station *lastStation;
    lastStation= T.visit(7,"RRRLLL");
    cout<<lastStation->name<<endl;
    return 0;
}