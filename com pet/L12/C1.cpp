#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
long long dp[MAXN];

long long solve(int n)
{ // base case
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    for (int i = 4; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 3] + dp[i - 4];
    return dp[n];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    cout <<(long long)solve(n) << endl;
    return 0;
}