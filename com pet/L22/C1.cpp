#include <bits/stdc++.h>
using namespace std;

long long countWays(int n, int m)
{
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (i < m)
        {
            dp[i] = 1;
        }
        else
        {
            dp[i] = dp[i - 1] + dp[i - m];
        }
    }
    return dp[n];
}

int main()
{
    int n, m;
    cin >> n >> m;

    cout << countWays(n, m) << endl;

    return 0;
}
