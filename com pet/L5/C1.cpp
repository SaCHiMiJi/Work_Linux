#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, x, r = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        arr[i] = m;
        r += m;
    }
    x =  r /n;
    r = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > x)
        {
            r += arr[i] - x;        
        }
        
    }
    cout << r;
    return 0;
}