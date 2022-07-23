#include <iostream>
#include <string>
#include "station.cpp"
using namespace std;

class Trip {

public:

    Station* header;
    Station* trailer;
    int size;
    Trip()
    {
         /*
         WRITE YOUR CODE HERE
         */   
          header = NULL;
          trailer = NULL;
          size = 0;
    }

    void printList()
    {
        cout << "[ ";
        Station* ptr = header->next;
        while (ptr != trailer) {
            cout << ptr->name << " ";
            ptr = ptr->next;
        }
        cout << "]\n";
    }


    void insert_front(string newItem)
    {
         /*
         WRITE YOUR CODE HERE
         */
        Station *ptr; 
        if (size == 0)
        {
          
          header = ptr;
          ptr->next = trailer;
          trailer->prev = ptr;

        } 
        else
        {
          Station *curr; 
          curr = header->next;
        }
     
    }
    void insert_back(string newItem)
    {
         /*
         WRITE YOUR CODE HERE
         */
        if (size == 0)
        {
          
          header = ptr;
          ptr->next = trailer;
          trailer->prev = ptr;

        } 
        else
        {
          Station *curr; 
          curr = trailer->next;
        }
    }

    void remove_front()
    {
         /*
         WRITE YOUR CODE HERE
         */
    }
    void remove_back()
    {
         /*
         WRITE YOUR CODE HERE
         */
    }

    Station* visit(int nStep, string stepText)
    {
         /*
         WRITE YOUR CODE HERE
         */
        
    }
};