#include <bits/stdc++.h>
using namespace std;

long double f(long double a, long double b)
{
    return (a * a * a) / (1 - b) + (b * b * b) / (1 - a);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long double n,k;
    cin >> n;
    long double min_val = INFINITY;

    for ( k = n+2; k <= 30; k++)
    {
        long double a = (-n + sqrt((n * n) + (4 * k))) / 2;
        long double b = (-n - sqrt((n * n) + (4 * k))) / 2;
        long double result = f(a, b);
        cout << result << endl;
        min_val = min(min_val, result);
        
    }
    std::cout << fixed << setprecision(8) << min_val << endl;

    return 0;
}
