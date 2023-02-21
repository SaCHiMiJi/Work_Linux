#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define DFS_WHITE -1
#define DFS_BLACK 1
vector<vii> AdjList;
vi dfs_num;
int numCC;

void dfs(int u) {
    printf(" %d", u);
    dfs_num[u] = DFS_BLACK;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == DFS_WHITE)
            dfs(v.first);   
    }
}

int main(){
    int V, total_neighbors, id, weight;
    scanf("%d", &V);
    AdjList.assign(V, vii());
    for (int i = 0; i < V; i++) {
        scanf("%d", &total_neighbors);
        for (int j = 0; j < total_neighbors; j++) {
            scanf("%d %d", &id, &weight);
            AdjList[i].push_back(ii(id, weight));
        }
    }
    numCC = 0;
    dfs_num.assign(V, DFS_WHITE);
    for (int i = 0; i < V; i++)
        if (dfs_num[i] == DFS_WHITE){
            printf("Component %d:", ++numCC);
            dfs(i); printf("\n");
        }
    printf("There are %d connected components\n", numCC);
    return 0;
}
