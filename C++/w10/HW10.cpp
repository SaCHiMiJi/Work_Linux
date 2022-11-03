#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Village{
    int numHouse;
    vector<int> *adjLists;
    bool *visited;
    
    
public:
    Village(int V){
        numHouse = V;
        adjLists = new vector<int>[V];
    }
    void addRoad(int src, int dest){
        adjLists[src].push_back(dest);
        adjLists[dest].push_back(src);
    }
    void BFS(int firstHouse){
        visited = new bool[numHouse];
        for (int i = 0; i < numHouse; i++)
        {
            visited[i] = false;
        }
        queue<int> q;
        q.push(firstHouse);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            if (visited[u])
            {
                continue;
            }
            visited[u] = true;
            cout<<u<<" ";
            sort_adjLists();
            vector<int>::iterator it;
            for (it = adjLists[u].begin(); it!=adjLists[u].end(); it++)
            {
                if (!visited[*it])
                {
                    q.push(*it);
                }
                
            }
            
        }
        
    }


    void DFS(int firstHouse){
        visited = new bool[numHouse];
        for (int i = 0; i < numHouse; i++)
        {
            visited[i] = false;
        }
        DFSVISIT(firstHouse);
        for (int i = 0; i < numHouse; i++)
        {
            if (visited[i] == false)
            {
                DFSVISIT(i);
            }
            
        }
        
        
    }
    
    void sort_adjLists(){
      for(int i = 0; i < numHouse; i++){
        sort(adjLists[i].begin(),adjLists[i].end());
      }
    }
    void DFSVISIT(int vertex){
        visited[vertex] = true;
        cout<<vertex<<" ";
        sort_adjLists();
        vector<int>::iterator it;
        for (it  = adjLists[vertex].begin(); it != adjLists[vertex].end(); it++)
        {
            if (!visited[*it])
            {
                DFSVISIT(*it);
            }
            
        }
        
    }
    // void printGraph(){
    //   for(int i=0; i<numHouse; i++){
    //   vector<int> adjList = adjLists[i];
    //   vector<int>::iterator it;
    //   cout<<i<<"->";
    //   for(it = adjList.begin(); it!=adjList.end(); it++){
    //     cout<<*it<<" ";
    //   }
    //   cout<<"\n";
    // }
};



