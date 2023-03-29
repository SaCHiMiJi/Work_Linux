#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<pair<int,int>> adj[N];
int n, m;
int dist[N];
bool vis[N];

void dijkstra_shortest(int start) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, false, sizeof(vis));
    dist[start] = 0;
    pq.push({0, start});
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto e : adj[u]) {
            int v = e.first, w = e.second;
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

void dijkstra_longest(int start) {
    priority_queue<pair<int,int>> pq;
    memset(dist, -0x3f, sizeof(dist));
    memset(vis, false, sizeof(vis));
    dist[start] = 0;
    pq.push({0, start});
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto e : adj[u]) {
            int v = e.first, w = e.second;
            if(dist[v] < dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    dijkstra_shortest(0);
    cout << dist[n-1] << endl;
    
    dijkstra_longest(0);
    cout << dist[n-1] << endl;
    
    return 0;
}