#include <iostream>
#include <vector>
using namespace std;

class SegmentTree
{
private:
    int *tree;
    int *lazy;
    int size;

    void push(int node, int left, int right)
    {
        if (lazy[node])
        {
            tree[node] = right - left + 1 - tree[node]; // toggle the count
            if (left != right)
            {
                lazy[node * 2] ^= 1;     // toggle left child's lazy flag
                lazy[node * 2 + 1] ^= 1; // toggle right child's lazy flag
            }
            lazy[node] = 0; // clear current node's lazy flag
        }
    }

    void build(vector<bool> &values, int node, int left, int right)
    {
        if (left == right)
        {
            tree[node] = values[left];
            return;
        }

        int mid = (left + right) / 2;
        build(values, node * 2, left, mid);
        build(values, node * 2 + 1, mid + 1, right);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    int query(int node, int left, int right, int qLeft, int qRight)
    {
        push(node, left, right);

        if (left > qRight || right < qLeft)
        {
            return 0;
        }

        if (qLeft <= left && right <= qRight)
        {
            return tree[node];
        }

        int mid = (left + right) / 2;
        int leftCount = query(node * 2, left, mid, qLeft, qRight);
        int rightCount = query(node * 2 + 1, mid + 1, right, qLeft, qRight);
        return leftCount + rightCount;
    }

    void update(int node, int left, int right, int uLeft, int uRight)
    {
        push(node, left, right);

        if (left > uRight || right < uLeft)
        {
            return;
        }

        if (uLeft <= left && right <= uRight)
        {
            tree[node] = right - left + 1 - tree[node]; // toggle the count
            if (left != right)
            {
                lazy[node * 2] ^= 1;     // toggle left child's lazy flag
                lazy[node * 2 + 1] ^= 1; // toggle right child's lazy flag
            }
            return;
        }

        int mid = (left + right) / 2;
        update(node * 2, left, mid, uLeft, uRight);
        update(node * 2 + 1, mid + 1, right, uLeft, uRight);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

public:
    SegmentTree(vector<bool> &values, int N)
    {
        size = N;
        tree = new int[4 * size];
        lazy = new int[4 * size]();
        build(values, 1, 0, size - 1);
    }

    int query(int left, int right)
    {
        return query(1, 0, size - 1, left, right);
    }

    void update(int left, int right)
    {
        update(1, 0, size - 1, left, right);
    }

    ~SegmentTree()
    {
        delete[] tree;
        delete[] lazy;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q;
    scanf("%d %d\n", &N, &Q);

    vector<bool> values(N, false);
    SegmentTree tree(values, N);

    for (int i = 0; i < Q; i++)
    {
        int C, S, T;
        scanf("%d %d %d\n", &C, &S, &T);

        if (C == 0)
        {
            tree.update(S - 1, T - 1);
        }
        else
        {
            printf("%d \n", tree.query(S - 1, T - 1));
        }
    }
}

// 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 = 0
// 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 = 7 (0-6)
// 1 1 1 0 0 0 0 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0 = 8 (3-11)
// 1 1 1 0 0 0 0 1 1 1 0 0 1 1 1 1 1 0 0 0 0 0 = 11 (10-16)