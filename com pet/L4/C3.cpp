#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,r=0;
    int p = 2;
    cin>>n;
    if (n<=3)
    {
        r = n;
    }
    else if (n<=4)
    {
        r = 3;
    }
    else if (n<=8)
    {
        r = 4;
    }
    else if (n<=16)
    {
        r = 5;
    }
    else if (n<=32)
    {
        r = 6;
    }
    else if (n<=64)
    {
        r = 7;
    }
    else if (n<=128)
    {
        r = 8;
    }
    else if (n<=256)
    {
        r = 9;
    }
    else if (n<=512)
    {
        r = 10;
    }
    else if (n<=1024)
    {
        r = 11;
    }
    else if (n<=2048)
    {
        r = 12;
    }
    else if (n<=4096)
    {
        r = 13;
    }
    else if (n<=8192)
    {
        r = 14;
    }
    else
    {
        r = 15;
    }
    
    cout<<r;
    
    return 0;
}