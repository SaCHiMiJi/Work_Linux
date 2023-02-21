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

void update_tree(int node, int start, int end, int idx, int val) {
    if (start == end) {
        tree[node] = val;
    }
    else {
        int mid = (start + end) / 2;
        if (start <= idx && idx <= mid) {
            update_tree(node * 2, start, mid, idx, val);
        } 
        else {
            update_tree(node * 2 + 1, mid + 1, end, idx, val);
        }
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

int query_tree(int node, int a, int b, int i, int j, int val)
{
    
    if (a > b || a > j || b < i)
    {
        return 0;
    }   if (lazy[node] != 0)
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
    {
        if (tree[node] <= val)
        {
            return 1;
        }
        return 0;
    }

    int q1 = query_tree(node * 2, a, (a + b) / 2, i, j, val);
    int q2 = query_tree(1 + node * 2, 1 + (a + b) / 2, b, i, j, val);
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

    build_tree(1, 0, n - 1);
    memset(lazy, 0, sizeof(lazy));

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        arr[i] = num;
    }

    for (int j = 0; j < Q; j++)
    {
        cin >> mode;
        if (mode == 'M')
        {
            cin >> i >> X;
            update_tree(1, 0, n - 1, i - 1, X);
        }
        else
        {
            cin >> S >> T >> K;
            cout << query_tree(1, 0, n - 1, S - 1, T - 1, K) << endl;
        }
    }

    return 0;
}