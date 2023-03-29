#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<pair<int,int>> adj[N];
int n, m;
int dist_shortest[N];
int dist_longest[N];
bool vis[N];

void dijkstra_shortest(int start) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    memset(dist_shortest, 0x3f, sizeof(dist_shortest));
    memset(vis, false, sizeof(vis));
    dist_shortest[start] = 0;
    pq.push({0, start});
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto e : adj[u]) {
            int v = e.first, w = e.second;
            if(dist_shortest[v] > dist_shortest[u] + w) {
                dist_shortest[v] = dist_shortest[u] + w;
                pq.push({dist_shortest[v], v});
            }
        }
    }
}

void topological_sort(int u, stack<int>& s) {
    vis[u] = true;
    for(auto e : adj[u]) {
        int v = e.first;
        if(!vis[v]) {
            topological_sort(v, s);
        }
    }
    s.push(u);
}

int longest_path(int start, int end) {
    memset(dist_longest, -0x3f, sizeof(dist_longest));
    dist_longest[start] = 0;
    stack<int> s;
    memset(vis, false, sizeof(vis));
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            topological_sort(i, s);
        }
    }
    while(!s.empty()) {
        int u = s.top();
        s.pop();
        if(dist_longest[u] == -0x3f) continue;
        for(auto e : adj[u]) {
            int v = e.first, w = e.second;
            if(dist_longest[v] < dist_longest[u] + w) {
                dist_longest[v] = dist_longest[u] + w;
            }
        }
    }
    return dist_longest[end];
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    dijkstra_shortest(0);
    cout << dist_shortest[n-1] << endl;
    
    cout << longest_path(0, n-1) << endl;
        
    return 0;
}
