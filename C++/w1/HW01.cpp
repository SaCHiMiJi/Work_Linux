#include <iostream>
#include <string>
#include "card.cpp"

using namespace std;

class CardList
{

public:
    Card *head;
    int size = 0;
    CardList()
    {
        /*
         WRITE YOUR CODE HERE
         */
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
        newcard->name = newItem;
        // cout<<"insert\n";
        if (size == 1)
        {
            // cout <<"in 1"<<endl;
            head = newcard;
        }
        else
        {
            Card *curr = head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = newcard;
        }
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
        pos %= (size);
        // cout<<"pos: "<<pos<<endl;
        if (pos >= 1)
        {
            // find last node & find pre
            int i = 0;
            while (Last->next != NULL)
            {
                Last = Last->next;
                if (i < size - pos - 1)
                {
                    pre = pre->next;
                    i++;
                }
            }

            // cout<<"Last: "<<Last->name<<endl;
            // cout<<"pre: "<<pre->name<<endl;

            curr = pre->next;
            // cout<<"curr name: "<<curr->name<<endl;

            head = curr;
            pre->next = NULL;
            // cout<<"first :"<<first->name;
            Last->next = first;
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