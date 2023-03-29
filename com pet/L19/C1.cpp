#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v, w;
};

bool compare(const Edge &a, const Edge &b)
{
    return a.w < b.w;
}

int find(int u, vector<int> &parent)
{
    if (u != parent[u])
    {
        parent[u] = find(parent[u], parent);
    }
    return parent[u];
}

void union_set(int u, int v, vector<int> &parent, vector<int> &rank)
{
    int root_u = find(u, parent);
    int root_v = find(v, parent);
    if (root_u == root_v)
        return;
    if (rank[root_u] > rank[root_v])
    {
        parent[root_v] = root_u;
    }
    else
    {
        parent[root_u] = root_v;
        if (rank[root_u] == rank[root_v])
        {
            rank[root_v]++;
        }
    }
}

int kruskal(vector<Edge> &edges, int n)
{
    sort(edges.begin(), edges.end(), compare);
    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    int cost = 0;
    for (const auto &edge : edges)
    {
        if (find(edge.u, parent) != find(edge.v, parent))
        {
            cost += edge.w;
            union_set(edge.u, edge.v, parent, rank);
        }
    }
    return cost;
}

int main()
{
    int n;
    cin >> n;

    vector<Edge> initial_edges(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> initial_edges[i].u >> initial_edges[i].v >> initial_edges[i].w;
    }

    int k;
    cin >> k;

    vector<Edge> new_edges(k);
    for (int i = 0; i < k; i++)
    {
        cin >> new_edges[i].u >> new_edges[i].v >> new_edges[i].w;
    }

    int m;
    cin >> m;

    vector<Edge> all_edges(m + k);
    for (int i = 0; i < m; i++)
    {
        cin >> all_edges[i].u >> all_edges[i].v >> all_edges[i].w;
    }

    for (int i = 0; i < k; i++)
    {
        all_edges[m + i].u = new_edges[i].u;
        all_edges[m + i].v = new_edges[i].v;
        all_edges[m + i].w = new_edges[i].w;
    }

    int initial_cost = kruskal(initial_edges, n);
    int new_cost = kruskal(all_edges, n);

    cout << initial_cost << '\n';
    cout << new_cost << '\n';

    return 0;
}
