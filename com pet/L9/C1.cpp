#include <bits/stdc++.h>
using namespace std;
#define N 20
#define MAX (1 + (1 << 6))
#define inf 0x7fffffff
int arr[N];
int tree[MAX];
int lazy[MAX];

void build_tree(int node, int a, int b)
{
    // Out of range
    if (a > b)
        return;
    // Leaf node
    if (a == b)
    {
        tree[node] = arr[a];
        return;
    }
    // Init left and right child
    build_tree(node * 2, a, (a + b) / 2);
    build_tree(node * 2 + 1, 1 + (a + b) / 2, b);
    // Init node value
    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

void update_tree(int node, int a, int b, int i, int j, int value)
{
    if (lazy[node] != 0)
    {                             // This node needs to be updated
        tree[node] += lazy[node]; // Update it
        if (a != b)
        {
            lazy[node * 2] += lazy[node];     // Mark child as lazy
            lazy[node * 2 + 1] += lazy[node]; // Mark child as lazy
        }
        lazy[node] = 0; // Reset it
    }
    if (a > b || a > j || b < i) // Current segment is not within range [i, j]
        return;
    if (a >= i && b <= j)
    { // Segment is fuinty within range
        tree[node] += value;
        if (a != b)
        {
            lazy[node * 2] += value;
            lazy[node * 2 + 1] += value;
        }
        return;
    }
    update_tree(node * 2, a, (a + b) / 2, i, j, value); // Updating left child
    update_tree(1 + node * 2, 1 + (a + b) / 2, b, i, j, value);
    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

int query_tree(int node, int a, int b, int i, int j, int val)
{
    if (a > b || a > j || b < i)
        return -inf;
    if (lazy[node] != 0)
    {                             // This node needs to be updated
        tree[node] += lazy[node]; // Update it
        if (a != b)
        { // Mark child as lazy
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0; // Reset it
    }
    if (a >= i && b <= j)
        return 1;
    int q1 = query_tree(node * 2, a, (a + b) / 2, i, j);
    int q2 = query_tree(1 + node * 2, 1 + (a + b) / 2, b, i, j);
    int res = q1 + q2; // Return final result
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, Q, i, X, S, T, K, num;
    char mode;
    cin >> n >> Q;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        arr[i] = num;
    }
    build_tree(1, 0, N - 1);
    memset(lazy, 0, sizeof(lazy));
    for (int j = 0; j < Q; j++)
    {
        cin >> mode;
        if (mode == 'M')
        {
            cin >> i >> X;
            update_tree(1, 0, n - 1, 0, i, X);
        }
        else
        {
            cin >> S >> T >> K;
            cout << (long long)query_tree(1, 0, n - 1, K, S) << endl;
        }
    }

    // update_tree(1, 0, N - 1, 0, 6, 5);
    // update_tree(1, 0, N - 1, 7, 10, 12);
    // update_tree(1, 0, N - 1, 10, N - 1, 100);
    // cout << query_tree(1, 0, N - 1, 0, N - 1) << endl;
    return 0;
}