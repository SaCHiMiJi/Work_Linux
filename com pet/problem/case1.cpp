#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<pair<int,int>> adj[N];
int n, m;
int dist[N];
bool vis[N];

void bellman_ford_shortest(int start) {
    memset(dist, 0x3f, sizeof(dist));
    dist[start] = 0;
    for(int i = 0; i < n - 1; i++) {
        for(int u = 0; u < n; u++) {
            for(auto e : adj[u]) {
                int v = e.first, w = e.second;
                dist[v] = min(dist[v], dist[u] + w);
            }
        }
    }
}

void bellman_ford_longest(int start) {
    memset(dist, -0x3f, sizeof(dist));
    dist[start] = 0;
    for(int i = 0; i < n - 1; i++) {
        for(int u = 0; u < n; u++) {
            for(auto e : adj[u]) {
                int v = e.first, w = e.second;
                dist[v] = max(dist[v], dist[u] + w);
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

    bellman_ford_shortest(0);
    cout << dist[n-1] << endl;
    
    bellman_ford_longest(0);
    cout << dist[n-1] << endl;
    
    return 0;
}
