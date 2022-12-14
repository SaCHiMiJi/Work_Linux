#include <bits/stdc++.h>
using namespace std;
int main(){
    cin<<
    return 0;
}

int gcd(int a, int b)
{
    if (b)
        return gcd(b, a % b);
    else
        return a;
}