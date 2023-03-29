#include <bits/stdc++.h>
using namespace std;

long long countDer(long long n)
{
    if (n == 1 || n == 2)
    {
        return n - 1;
    }
    long long a = 0, b = 1, c;
    for (long long i = 3; i <= n; i++)
    {
        c = ((i - 1) % 1000000007) * (a + b) % 1000000007;
        a = b;
        b = c;
    }
    return b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    cout << countDer(n) << "\n";
    return 0;
}