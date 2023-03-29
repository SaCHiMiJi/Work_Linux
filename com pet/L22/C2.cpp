#include <bits/stdc++.h>
using namespace std;

vector<long long> dp(31);

void prepareDP()
{
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;
    dp[3] = 0;

    for (int i = 4; i <= 30; ++i)
    {
        dp[i] = 4 * dp[i - 2] - dp[i - 4];
    }
}

int main()
{
    int t, n;
    cin >> t;
    prepareDP();

    while (t--)
    {
        cin >> n;
        cout << dp[n] << endl;
    }

    return 0;
}
