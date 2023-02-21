#include <bits/stdc++.h>
using namespace std;

int cutRod(int price[], int n)
{
    int val[n + 1];
    val[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int max_val = INT_MIN;
        for (int j = 0; j < i; j++)
        {
            max_val = max(max_val, price[j] + val[i - j - 1]);
        }
        val[i] = max_val;
    }

    return val[n];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> k;

    cout << cutRod(arr, k) << endl;

    return 0;
}
