#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
            {
                K[i][w] = 0;
            }
            else if (wt[i - 1] <= w)
            {
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            }
            else
            {
                K[i][w] = K[i - 1][w];
            }
        }
    }
    return K[n][W];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, g, result = 0, num = 0;
    cin >> n;
    int arr_p[n], arr_w[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr_p[i] >> arr_w[i];
    }

    cin >> g;
    for (int i = 0; i < g; i++)
    {
        cin >> num;
        result += knapSack(num, arr_w, arr_p, n);
    }

    cout << result << endl;

    return 0;
}
