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
  L.insert_back("Kamax");
  L.insert_back("Latios");
  L.insert_back("Suicune");
  L.printCardList();
  L.shuffle(6);
  L.printCardList();
  // L.shuffle(3);
  // L.printCardList();
  
  // 
  // 
  // L.insert_back("Lugia");
  // L.pop_back();
  // L.insert_back("Rayquaza");
  // L.insert_back("Xerneas");
  // L.insert_back("Yveltal");
  // L.pop_back();
  // L.printCardList();
  Card * curr = L.head;
  while(curr!=NULL) {
    cout << curr->name << endl;
    curr = curr->next;
  }
  return 0;
}