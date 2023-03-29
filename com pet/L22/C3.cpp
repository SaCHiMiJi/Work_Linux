#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;

int numTilings(int N){
    if (N < 3) {
        return N;
    }
 
    vector<vector<long long> > dp(N + 1, vector<long long>(3, 0));
 
    dp[0][0] = dp[1][0] = 1;
    dp[1][1] = dp[1][2] = 1;
 
    for (int i = 2; i <= N; i++) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 2][0] + dp[i - 2][1] + dp[i - 2][2]) % MOD;
 
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
 
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
    }

    return dp[N][0];
}

int main(){
    int n;
    cin >> n;
    cout << numTilings(n);
 
    return 0;
}