#include<iostream>
#include "HW01.cpp"
using namespace std;

int main()
{
  CardList L;
  L.insert_back("Pokemon");
  L.insert_back("Steelix");
  L.insert_back("Dragonite");
  L.insert_back("Natu");
  L.printCardList();
  L.shuffle(327);
  L.printCardList();
  L.pop_back();
  L.printCardList();
  Card * curr = L.head;
  while(curr!=NULL) {
    cout << curr->name << endl;
    curr = curr->next;
  }
  return 0;
}