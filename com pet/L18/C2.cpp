#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const int INF = 1e9 + 7;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int a, b;
        vector<vector<int>> dist(MAXN, vector<int>(MAXN, INF));

        while (cin >> a >> b, a || b)
        {
            dist[a][b] = 1;
        }

        for (int i = 1; i < MAXN; i++)
        {
            dist[i][i] = 0;
        }

        for (int k = 1; k < MAXN; k++)
        {
            for (int i = 1; i < MAXN; i++)
            {
                for (int j = 1; j < MAXN; j++)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int sum = 0, cnt = 0;
        for (int i = 1; i < MAXN; i++)
        {
            for (int j = 1; j < MAXN; j++)
            {
                if (i != j && dist[i][j] != INF)
                {
                    sum += dist[i][j];
                    cnt++;
                }
            }
        }

        double avg = static_cast<double>(sum) / cnt;
        cout << fixed << setprecision(3) << avg << '\n';
    }

    return 0;
}
