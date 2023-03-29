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
    vi prev(V, -1); // predecessor array
    dist[s] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (int j = 0; j < (int)AdjList[u].size(); j++) {
                ii v = AdjList[u][j];
                if (longest) {
                    if (dist[u] + v.second > dist[v.first]) {
                        dist[v.first] = dist[u] + v.second;
                        prev[v.first] = u;
                    }
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

void print_path(int s, int u, const vi& prev) {
    if (u == s) {
        cout << s;
    } else if (prev[u] == -1) {
        cout << "no path from " << s << " to " << u << "\n";
    } else {
        print_path(s, prev[u], prev);
        cout << " -> " << u;
    }
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
    
    int source, destination;
    printf("Enter the source vertex: ");
    scanf("%d", &source);
    printf("Enter the destination vertex: ");
    scanf("%d", &destination);
    
    // find shortest path from source to all vertices
    vi shortest = dijkstra(source);
    // find longest path from source to all vertices
    vi longest = bellman_ford(source, true);

    // print shortest path and longest path from source to destination
    printf("Shortest path from vertex %d to vertex %d: ", source, destination);
    print_path(source, destination, dijkstra(source));
    printf(", distance = %d\n", shortest[destination]);
    
    printf("Longest path from vertex %d to vertex %d: ", source, destination);
    print_path(source, destination, bellman_ford(source, true));
    printf(", distance = %d\n", longest[destination]);

    return 0;
}
