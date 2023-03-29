#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int INF = 1e9;

int V, E;
vector<vii> AdjList;

vi dijkstra(int s) {
    vi dist(V, INF);
    dist[s] = 0;
    priority_queue< ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(0, s));

    while (!pq.empty()) {
        ii front = pq.top(); pq.pop();
        int d = front.first, u = front.second;
        if (d > dist[u]) continue;
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            ii v = AdjList[u][j];
            if (dist[u] + v.second < dist[v.first]) {
                dist[v.first] = dist[u] + v.second;
                pq.push(ii(dist[v.first], v.first));
            }
        }
    }
    return dist;
}
vi bellman_ford(int s, bool longest = false) {
    vi dist(V, longest ? -INF : INF);
    dist[s] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (int j = 0; j < (int)AdjList[u].size(); j++) {
                ii v = AdjList[u][j];
                if (longest) {
                    dist[v.first] = max(dist[v.first], dist[u] + v.second);
                } else {
                    if (dist[u] + v.second < dist[v.first]) {
                        dist[v.first] = dist[u] + v.second;
                    }
                }
            }
        }
    }

    // check for negative cycles
    if (!longest) {
        for (int u = 0; u < V; u++) {
            for (int j = 0; j < (int)AdjList[u].size(); j++) {
                ii v = AdjList[u][j];
                if (dist[u] + v.second > dist[v.first]) {
                    dist[v.first] = INF; // mark as infinite to avoid using it in the future
                }
            }
        }
    }

    return dist;
}

int main() {
    // read input
    scanf("%d %d", &V, &E);
    AdjList.assign(V, vii());
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        AdjList[u].push_back(ii(v, w));
        AdjList[v].push_back(ii(u, w)); // for undirected graph
    }

    // find shortest path from vertex 0 to all other vertices
    vi shortest = dijkstra(0);

    // find longest path from vertex 0
    vi longest = bellman_ford(0, true);

    // print shortest path and longest path
    for (int i = 0; i < V; i++) {
        cout << "Shortest path from vertex 0 to vertex " << i << ": " << shortest[i] << "\n";
    }
    for (int i = 0; i < V; i++)
    {
        cout << "Longest path from vertex 0 to vertex " << i << ": " << longest[i] << "\n";
    }
    

    return 0;
}
