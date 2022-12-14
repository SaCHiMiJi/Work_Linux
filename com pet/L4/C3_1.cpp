#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, r = 0;
    int p = 2;
    cin >> n;
    for (int i = 1; i <= 13; i++)
    {

        p *= 2;
        if (n<=3)
        {
            r = n;
            break;
        }
        if (n<=p)
        {
            r = i;
        }
        
    }
   
    cout << r;

    return 0;
}