#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    bool lp[n + 1];
    memset(lp, true, n + 1);
    for (int i = 2; i*i <= n; i++)
    {
        if (lp[i] == true)
        {
            for (int j = i * 2; j <= n; j += i)
            {
                lp[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++){
        if (lp[i]){
            cout << i << " ";}
    }
    return 0;
}