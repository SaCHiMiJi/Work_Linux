#include <bits/stdc++.h>
using namespace std;
int main(){
    unsigned long long int n ;
    int r =1000000007;
    cin>>n;
    n = n%r;
    cout<<(n*n)%r;
    return 0;
}
