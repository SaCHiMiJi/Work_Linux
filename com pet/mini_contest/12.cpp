#include <bits/stdc++.h>
using namespace std;

// Define an edge as a pair of destination and weight
typedef pair<int, int> Edge;

// Define a graph as a vector of edges
vector<Edge> graph[100001];

struct Point {
    int x, y;
};

double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// Function to find the shortest path with weight using Dijkstra's algorithm
void dijkstra(int start, int dest) {
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    vector<int> dist(100001, INT_MAX);

    dist[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto i : graph[u]) {
            int v = i.first;
            int weight = i.second;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    if (dist[dest] == INT_MAX) {
        cout << "No path found\n";
    } else {
        cout << "Shortest path with weight from " << start << " to " << dest << " is " << dist[dest] << endl;
    }
}

int main() {
    // Add edges to the graph
    int n;
    cin >> n;
    vector<Point> rocks;
    for (int i = 0; i < n; i++)
    {
         cin >> rocks[i].x >> rocks[i].y;
        for (int j = 0; j < i; j++) {
            double w = distance(rocks[i], rocks[j]);
            if (w > 0) {
                graph[rocks[i].x].push_back(make_pair(rocks[i].y, w));
            }
        }
        
    }
    
    dijkstra(1, 6);

    return 0;
}
