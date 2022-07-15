#include <iostream>
#include <string>
#include "card.cpp"

using namespace std;

class CardList
{

public:
    Card *head;
    Card *prev_last;
    int size = 0;
    CardList()
    {
        /*
         WRITE YOUR CODE HERE
         */
        prev_last = NULL;
        head = NULL;
        // cout<<"Cardlist"<<endl;
    }

    void pop_back()
    {
        /*
        WRITE YOUR CODE HERE
        */
        Card *curr;
        Card *pre = head;
        // cout<<"size : "<<size<<endl;
        if (size == 1)
        {
            size--;
            curr = head;
            head = head->next;
            delete curr;
            curr = NULL;
        }
        else if (size > 1)
        {
            size--;
            while (pre->next->next != NULL)
            {
                pre = pre->next;
            }
            curr = pre->next;
            pre->next = NULL;
            delete curr;
            curr = NULL;
        }
        // cout<<"pop\n";
    }

    void insert_back(string newItem)
    {
        /*
        WRITE YOUR CODE HERE
        */

        size++;
        Card *newcard = new Card;
        Card *curr = head;
        newcard->name = newItem;
        // cout<<"insert\nsize:"<<size<<endl;
        if (size == 1)
        {
            // cout <<"in 1"<<endl;
            head = newcard;
        }
        else 
        {
            // cout<<"in 2"<<endl;
            prev_last = head->next;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = newcard;
        }
        
        // cout<<"prev_last:"<<prev_last<<endl;
        // cout << head->next->name<<" ";
    }

    void shuffle(int pos)
    { // 1<=pos<=size-1
        /*
        WRITE YOUR CODE HERE
        */
        Card *curr;
        Card *pre = head;
        Card *first = head;
        Card *Last = head;

        // cout<<"pos: "<<pos<<endl;
        // cout<<"size: "<<size<<endl;
        if (pos >= 1 && size - 1 >= pos)
        {
            // find last node & find pre
            int i = 0;
            while (Last->next != NULL)
            {
                Last = Last->next; 
                if (size - 1 == pos)
                {
                    if (i < size - 3)
                    {
                        // cout << "i :" << i << endl;
                        pre = pre->next;
                        i++;
                    }
                }
                else if (i < pos-1)
                {
                    // cout << "i :" << i << endl;
                    pre = pre->next;
                    
                }
                
                i++;
            }
            if (size == 2)
            {
                head = Last;
                head->next = first;
                head->next->next = NULL;
            }
            else if (size - 1 == pos)
            {   
                // cout<<"in"<<endl;
                head = Last;
                curr = Last;
                curr->next = first;
                pre->next->next = NULL;
            }
            else
            {
                curr = pre->next;
                head = curr;
                pre->next = NULL;
                Last->next = first;
            }

            // cout<<"Last: "<<Last->name<<endl;
            // cout<<"pre: "<<pre->name<<endl;

            // cout<<"curr name: "<<curr->name<<endl;

            // cout<<"first :"<<first->name;
        }
        // cout<<"\nshuffle\n";
    }

    void printCardList()
    {
        /*
        DO NOT DELETE OR EDIT
        */
        cout << "[ ";
        Card *ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->name << " ";
            ptr = ptr->next;
        }
        cout << "]\n";
    }
};