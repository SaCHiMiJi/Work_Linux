#include <iostream>
#include <string>
#include "station.cpp"
using namespace std;

class Trip
{

public:
    Station *header = new Station;
    Station *trailer = new Station;
    int size = 0;
    Trip()
    {
        /*
        WRITE YOUR CODE HERE
        */
        header->next = trailer;
        header->prev = NULL;
        trailer->next = NULL;
        trailer->prev = header;
        
    }

    void printList()
    {
        cout << "[ ";
        Station *ptr = header->next;
        while (ptr != trailer)
        {
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
        // cout << "in front\n";

        size++;
        Station *n_staion = new Station;
        n_staion->name = newItem;

        if (isEmpty())
        {
            // cout << "in 1\n";

            n_staion->next = trailer;
            n_staion->prev = header;
            
            header->next = n_staion;
            trailer->prev = n_staion;
        }
        else
        {
            // cout << "in 2\n";
            Station *curr = new Station;

            curr = header->next;

            n_staion->prev = header;
            n_staion->next = curr;

            header->next = n_staion;
            curr->prev = n_staion;
        }
        // cout << n_staion->name << endl;
    }
    void insert_back(string newItem)
    {
        /*
        WRITE YOUR CODE HERE
        */
        // cout << "in back\n";
        size++;
        Station *n_staion = new Station;
        n_staion->name = newItem;
        if (isEmpty())
        {
            n_staion->next = trailer;
            n_staion->prev = header;
            
            header->next = n_staion;
            trailer->prev = n_staion;
        }
        else
        {
            Station *curr;

            curr = trailer->prev;

            n_staion->next = trailer;
            n_staion->prev = curr;

            curr->next = n_staion;
            trailer->prev = n_staion;
        }
    }

    void remove_front()
    {
        /*
        WRITE YOUR CODE HERE
        */
        if (!isEmpty())
        {
            Station *curr;
            if (size == 1)
            {   // case 1 data in list
                header->next = trailer;
                trailer->prev = header;

            }
            else
            {
                Station *n_curr; // next curr

                curr = header->next;
                n_curr = curr->next;
                n_curr->prev = header;
                header->next = n_curr;
            }
            size--;

            // return memory
            delete curr;
            
        }
    }

    void remove_back()
    {
        /*
        WRITE YOUR CODE HERE
        */
        if (!isEmpty())
        {
            Station *curr;
            if (size == 1)
            {   // case 1 data in list
                header->next = trailer;
                trailer->prev = header;

            }
            else
            {
                Station *p_curr ; // prev curr

                curr = trailer->prev;
                p_curr = curr->prev;

                // cout<<"curr : "<<curr->name<<"\p_curr : "<<p_curr->name<<endl;

                p_curr->next = trailer;
                trailer->prev = p_curr;

            }
            size--;

            // return memory 
            delete curr;
            
        }
        
    }
    
    bool isEmpty(){
        return(header->next==trailer);
    }

    Station *visit(int nStep, string stepText)
    {
        /*
        WRITE YOUR CODE HERE
        */
        if (!isEmpty())
        {

            Station *curr = header->next;

            for (size_t i = 0; i < stepText.length(); i++)
            {
                if (stepText[i] == 'R')
                {
                    if (curr->next != trailer)
                    {
                        curr = curr->next;
                    }
                    
                }
                else
                {
                    if (curr->prev != header)
                    {
                        curr = curr->prev;
                    }
                    
                    
                }
                
                // cout<<stepText[i]<<endl;
            }

            return curr;
        }
        // return 0;
    }
};