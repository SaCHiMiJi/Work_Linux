#include<iostream>
#include "HW01.cpp"
using namespace std;

int main()
{
  CardList L;
  L.printCardList();
  // L.pop_back();
  L.insert_back("Pokemon");
  L.printCardList();
  
  L.insert_back("Steelix");
  L.insert_back("Dragonite");
  L.insert_back("Natu");
  L.insert_back("Kamax");
  L.insert_back("Latios");
  L.insert_back("Suicune");
  L.insert_back("Lugia");
  L.insert_back("Rayquaza");
  L.insert_back("Xerneas");
  L.insert_back("Yveltal");
  L.printCardList();
  L.pop_back();
  L.pop_back();
  L.pop_back();
  L.pop_back();
  L.pop_back();
  L.printCardList();
  L.shuffle(10);
  L.printCardList();
  L.pop_back();
  L.pop_back();
  L.pop_back();
  L.pop_back();
  L.pop_back();
  L.pop_back();
  L.pop_back();
  L.printCardList();
  L.insert_back("Yveltal");
  L.insert_back("Xerneas");
  L.printCardList();
  L.shuffle(11);
  L.insert_back("Rayquaza");
  L.printCardList();
  L.shuffle(16);
  L.printCardList();
  Card * curr = L.head;
  while(curr!=NULL) {
    cout << curr->name << endl;
    curr = curr->next;
  }
  return 0;
}