#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (b)
        return gcd(b, a % b);
    else
        return a;
}
int main(){
    long long n,r = 0;
    cin>>n;
    for (int i = 1; i < n; i++)
    {
        // cout<<i<<endl;
        for (int j = i+1; j <= n; j++)
        {
            r += gcd(i,j);
        }
        
    }
    
    cout<<r;
    return 0;
}

