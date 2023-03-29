#include <bits/stdc++.h>
using namespace std;

const int MAX_NODES = 101;
const int INF = 1e9;

vector<int> graph[MAX_NODES];
int capacities[MAX_NODES][MAX_NODES];

int bfs(int source, int destination, vector<int> &parent)
{
    fill(parent.begin(), parent.end(), -1);
    parent[source] = -2;
    queue<pair<int, int>> q;
    q.push({source, INF});

    while (!q.empty())
    {
        int node = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : graph[node])
        {
            if (parent[next] == -1 && capacities[node][next])
            {
                parent[next] = node;
                int new_flow = min(flow, capacities[node][next]);
                if (next == destination)
                {
                    return new_flow;
                }
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}

int max_flow(int source, int destination, int n)
{
    int flow = 0;
    vector<int> parent(n + 1);
    int new_flow;

    while (new_flow = bfs(source, destination, parent))
    {
        flow += new_flow;
        int current = destination;
        while (current != source)
        {
            int previous = parent[current];
            capacities[previous][current] -= new_flow;
            capacities[current][previous] += new_flow;
            current = previous;
        }
    }
    return flow;
}

int main()
{
    int n, s, t, c;
    cin >> n >> s >> t >> c;

    for (int i = 0; i < c; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(v);
        graph[v].push_back(u);
        capacities[u][v] += w;
        capacities[v][u] += w;
    }

    int total_bandwidth = max_flow(s, t, n);
    cout << total_bandwidth << endl;

    return 0;
}
