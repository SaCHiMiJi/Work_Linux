#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
vector<int> dfs_num;
vector<int> adj[N];
void dfs(int s)
{
    printf("%d ", s);
    dfs_num[s] = true;
    for (auto u : adj[s])
    {
        if (dfs_num[u] == -1)
            dfs(u);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, link;
    cin >> n;
    dfs_num.assign(n, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> link;
            if (link == 1)
            {
                adj[i].push_back(j);
            }
        }
    }
    dfs(1);
    cout << endl;
    return 0;
}
