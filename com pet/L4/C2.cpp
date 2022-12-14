#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b,r=0;
    cin >>a>>b;
    bool lp[b+1];
    memset(lp, true, b + 1);
    for (int i = 2; i*i <= b; i++)
    {
        if (lp[i] == true)
        {
            for (int j = i * 2; j <= b; j += i)
            {
                lp[j] = false;
            }
        }
    }

    for (int i = a; i <= b; i++){
        if (lp[i]){
            // cout<<i<<" ";
            r++;
        }
    }
    cout<<r<<endl;
    return 0;
}