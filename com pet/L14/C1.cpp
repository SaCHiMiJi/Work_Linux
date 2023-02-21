#include <bits/stdc++.h>
using namespace std;

bool find_partition(vector<int> &arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    if (sum % 2 != 0)
        return false;
    sum = sum / 2;
    bool dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
        }
    }
    return dp[n][sum];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, temp;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }
    if (find_partition(arr, n) == true)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}