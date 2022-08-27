#include <iostream>
#include <string>
#include "station.cpp"
using namespace std;

class Trip {

public:
     Station* header= new Station;
     Station* trailer= new Station;

     Trip(){ 
          header->prev = NULL;
          header->next = trailer;
          trailer->prev = header;
          trailer->next = NULL;
     }     

     void printList(){
          cout << "[ ";
          Station* ptr = header->next;
          while (ptr != trailer) {
               cout << ptr->name << " ";
               ptr = ptr->next;
          }
          cout << "]\n";
     }

     void insert_front(string newItem){ // got it
          Station* newSta = new Station;
          newSta->name = newItem;

          newSta->next = header->next;
          header->next = newSta;

          newSta->prev = header;
          (newSta->next)->prev = newSta;
    }

     void insert_back(string newItem){ // got it
          Station* newSta = new Station;
          newSta->name = newItem;
          Station* cur = trailer->prev;
          
          newSta->next = trailer;
          newSta->prev = cur;
          cur->next = newSta;
          trailer->prev = newSta;

     }

     void remove_front(){ // got it
          if (header->next != trailer){
               Station* temp = header->next;
               (temp->next)->prev = header;
               header->next = temp->next;
               delete temp;  
          }
     }

     void remove_back(){ // ยังไม่ได้
          if (trailer->prev != header){
               Station* temp = trailer->prev;
               (temp->prev)->next = trailer;
               trailer->prev = temp->prev;
               delete temp;  
          }
     }     

     Station* visit(int nStep, string stepText){
          Station* cur = header->next;
          int i = 0;
          while (i<nStep){
               i++;
               if (stepText[i] == 'R' && cur->next != trailer ){
                    cur = cur->next;
                    
               }else if (stepText[i] == 'L' && cur->prev != header){
                    cur = cur->prev;
               }
          }
          return cur;
     }
};