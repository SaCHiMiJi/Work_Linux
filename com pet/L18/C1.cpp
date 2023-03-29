#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1005;

struct State
{
    int u, fuel, cost;
    State(int u, int fuel, int cost) : u(u), fuel(fuel), cost(cost) {}
    bool operator<(const State &other) const
    {
        return cost > other.cost;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> price(n);
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }

    int q;
    cin >> q;
    while (q--)
    {
        int c, s, e;
        cin >> c >> s >> e;

        vector<vector<int>> dist(n, vector<int>(c + 1, INF));
        dist[s][0] = 0;

        priority_queue<State> pq;
        pq.push(State(s, 0, 0));

        bool found = false;
        while (!pq.empty())
        {
            State state = pq.top();
            pq.pop();

            int u = state.u, fuel = state.fuel, cost = state.cost;

            if (u == e)
            {
                found = true;
                cout << cost << "\n";
                break;
            }

            if (cost > dist[u][fuel])
            {
                continue;
            }

            for (const auto &edge : adj[u])
            {
                int v = edge.first, w = edge.second;
                int required_fuel = w;

                if (fuel >= required_fuel)
                {
                    int new_fuel = fuel - required_fuel;
                    if (cost < dist[v][new_fuel])
                    {
                        dist[v][new_fuel] = cost;
                        pq.push(State(v, new_fuel, cost));
                    }
                }
            }

            if (fuel + 1 <= c)
            {
                int new_cost = cost + price[u];
                int new_fuel = fuel + 1;
                if (new_cost < dist[u][new_fuel])
                {
                    dist[u][new_fuel] = new_cost;
                    pq.push(State(u, new_fuel, new_cost));
                }
            }
        }

        if (!found)
        {
            cout << "impossible\n";
        }
    }

    return 0;
}
