#include <iostream>
#include <string>
#include "card.cpp"

using namespace std;

class CardList{

    public:
	    Card* head;
        int size = 0;
        CardList(){
            /*
             WRITE YOUR CODE HERE
             */
            head=NULL;
            cout<<"Cardlist"<<endl;
        }

	    void pop_back(){
            /*
            WRITE YOUR CODE HERE
            */
            Card *curr;
            Card *pre = head;

            if (size == 1){
                size--;
                curr = pre->next;
                pre->next = NULL;
                delete curr;
                curr = NULL;
                
            } else if(size > 1){
                size--;
                while(pre->next->next != NULL){
                    pre = pre->next;
                }
                curr = pre->next;
                pre->next = NULL; 
                delete curr;
                curr = NULL;
            }
            cout<<"pop\n";
	    }   


        void insert_back(string newItem){
            /*
            WRITE YOUR CODE HERE
            */
            
            size++;
            Card *newcard = new Card;
            newcard -> name = newItem;
            //cout<<"insert\n";
            if (size == 1){
                //cout <<"in 1"<<endl;
                head= newcard;
            } else {
                Card *curr= head;
                while (curr->next!= NULL){
                    curr=curr->next;
                }
                curr->next = newcard;
            }
           // cout << head->next->name<<" ";
        }

        void shuffle(int pos){ //1<=pos<=size-1
            /*
            WRITE YOUR CODE HERE
            */
            Card *curr;
            Card *pre = head;
            Card *first = head->next;
            Card *Last = head;
            pos = pos % (size-1);
            if (pos >= 1){
                //find last node
                while (Last != NULL){
                    Last = Last->next;
                }
                
                for (int i = 0; i < pos-1; i++){
                    pre = pre->next;
                }
                while (pre->next != NULL){
                    pre = pre->next;
                }
                curr = pre->next;
                head->next = curr;
                pre->next = NULL;
                Last->next = first;

            }
            cout<<"shuffle\n";
        }
    
        void printCardList(){
            /*
            DO NOT DELETE OR EDIT
            */
            cout << "[ ";
            Card* ptr = head;
            while(ptr!=NULL){
                cout << ptr->name << " ";
                ptr = ptr->next;
            }
            cout << "]\n";
        }
        
};