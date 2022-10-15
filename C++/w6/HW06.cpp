#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Team{
    public:
    int ID = 0;
    int GD = 0;//Goal Difference = Goal score - Goal conced
    int PTS = 0;//Point (win = 3, draw = 1, lose = 0)

    //Constructor
    Team(int x, int y, int z) : ID(x), GD(y), PTS(z) {}
    
};

class Scoreboard{
public:
    vector<Team> T;
    int numberOfTeams = 0;
    bool debug = false;
    
    Scoreboard(int n){ 
        numberOfTeams = n;
        for(int i=0;i<n;i++){
            Team x(i,0,0);
            T.push_back(x);
        }
    }

    void match(int ID1, int ID2,int G1,int G2){
        int p_id1,p_id2,GD = 0;
        
        for (int i = 0; i < numberOfTeams; i++)
        {   
            // cout << "ID : " << T[i].ID << endl; 
            if (T[i].ID == ID1)
            {
                p_id1 = i;
                // cout << "p_id1 : " << p_id1 << endl;
            }
            if (T[i].ID == ID2)
            {
                p_id2 = i;
                // cout << "p_id2 : " << p_id2 << endl;
            }
            
        }

        if (G1 > G2) //G1 win
        {
            GD = G1 - G2;
            T[p_id1].PTS += 3;
            T[p_id1].GD += GD;
            T[p_id2].GD -= GD;
        } else if (G2 > G1) //G2 win
        {
            GD = G2 - G1;
            T[p_id2].PTS += 3;
            T[p_id2].GD += GD;
            T[p_id1].GD -= GD;
        } else // draw 
        {
            T[p_id1].PTS += 1;
            T[p_id2].PTS += 1;
        }
        // cout<<endl;
        // cout << "Team " << T[p_id1].ID << " " << T[p_id1].PTS << " " << T[p_id1].GD << endl;
        // cout << "Team " << T[p_id2].ID << " " << T[p_id2].PTS << " " << T[p_id2].GD << endl;
        
        sort_team();
        
        } 
    void showTeamAtRank(int i){
        // cout << "Show Team " << i <<endl; 
        // vector<Team> output = sort_team();
        i--;
        
        cout << T[i].ID << " ";
        cout << T[i].PTS << " ";
        cout << T[i].GD << endl;

    }
    void sort_team(){

        
        for (int i = numberOfTeams-1; i >= 0 ; i--)
        {
            // cout << i << endl;
            for (int j = 1; j <= i; j++)
            {
                if (T[j-1].PTS < T[j].PTS)
                {
                    Team temp(T[j-1].ID,T[j-1].GD,T[j-1].PTS);
                    T[j-1] = T[j];
                    T[j] = temp;
                }
                else if(T[j-1].PTS == T[j].PTS)
                {
                    if (T[j-1].GD < T[j].GD)
                    {
                        Team temp(T[j-1].ID,T[j-1].GD,T[j-1].PTS);
                        T[j-1] = T[j];
                        T[j] = temp;
                    }
                    else if( T[j-1].GD == T[j].GD){
                        if (T[j-1].ID > T[j].ID)
                        {
                            Team temp(T[j-1].ID,T[j-1].GD,T[j-1].PTS);
                            T[j-1] = T[j];
                            T[j] = temp;
                        }
                        
                    }
                    
                    
                }
            }
            
        }
        if (debug)
        {
            cout << endl;
            for (int i = 0; i < numberOfTeams; i++)
            {
                cout << T[i].ID << " " << T[i].PTS << " " << T[i].GD << endl;

            }
            cout << endl;
        }
            
    }

    void merge_sort(int ){

    }

    void merge(){

    }
};