#include <bits/stdc++.h>
using namespace std;

bool is_bipartite(vector<vector<int>>& graph) {
    vector<int> colors(graph.size(), -1);
    colors[0] = 0;
    stack<int> st;
    st.push(0);
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        for (int neighbor : graph[node]) {
            if (colors[neighbor] == -1) {
                colors[neighbor] = 1 - colors[node];
                st.push(neighbor);
            } else if (colors[neighbor] == colors[node]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        cin >> m;
        vector<vector<int>> graph(n);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        if (is_bipartite(graph)) {
            cout << "B" << "\n";
        } else {
            cout << "N" << "\n";
        }
    }
    return 0;
}
