#include <bits/stdc++.h>
using namespace std;

int check(int M, int N, int r, int c, int count, string l_t[])
{
    if (r + count > M || r - count < 0 || c + count > N || c - count < 0)
    {
        return (2*(count-1))+1;
    }

    for (int i = r - count; i <= r + count; i++)
    {
        for (int j = c - count; j <= c + count; j++)
        {
            if (l_t[i][j] != l_t[r][c])
            {
                return (2*(count-1))+1;
            }
        }
    }
    return check(M, N, r, c, count + 1, l_t);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string text;
    int M, N, Q, r, c;
    cin >> M >> N >> Q;
    string arr[N];

    for (int i = 0; i < M; i++)
    {
        cin >> text;
        arr[i] = text;
    }

    for (int i = 0; i < Q; i++)
    {
        cin >> r >> c;
        cout << check(M - 1, N - 1, r, c, 1, arr) << endl;
    }

    return 0;
}
