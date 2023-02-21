#include <bits/stdc++.h>
using namespace std;

void findcup(long long s, long long n)
{
    if (n % (s + 1) == 0)
    {
        cout << s << " ";
    }
    findcup(0, n / 2);
    findcup(n / 2, n);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long N;
    cin >> N;
    set<long long> result;
    for (long long i = 1; i <= sqrt(N); i++)
    {
        
        if (N % i == 0)
        {
            result.insert(i-1);
            result.insert((N-1) / i);
        }
    }
    for (auto &&i : result)
    {
        cout << i << " ";
    }
    
    cout << endl;

    return 0;
}
