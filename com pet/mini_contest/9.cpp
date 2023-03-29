#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30000;
vector<int> adj[MAXN];
vector<int> path;
set<vector<int>> com_path;

int value[MAXN];
bool visited[MAXN];
int cnt = 0;
int first_node = 0;

void dfs(int u, int prev) {
    visited[u] = true;
    path.push_back(u);
    for (int v : adj[u]) {
        if (v != prev && !visited[v] && value[first_node] <= value[v]) {
            if (value[first_node] == value[v]) {
                cnt++;
                com_path.insert(path);
            }
            dfs(v, u);
        }
    }
    path.pop_back();
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            path.clear();
            first_node = i;
            dfs(i, -1);
        }
    }

    cout << com_path.size() + n << endl;
    return 0;
}
