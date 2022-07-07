#include <iostream>
#include <string>
#include "card.cpp"

using namespace std;

class CardList{
    private:
        int size = 0 ;
        

    public:
	    Card* head;
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
            size--;
            if (size !=0){
                Card *curr = head;
                while(curr->next != NULL){
                    curr = curr->next;
                }
                //curr = NULL;
                delete curr;
                curr = NULL;
            }
            cout<<"pop\n";
	    }   


        void insert_back(string newItem){
            /*
            WRITE YOUR CODE HERE
            */
            
            size +=1;
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
            pos = pos % size-1;
            if (pos >= 1 && pos <= size-1){

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