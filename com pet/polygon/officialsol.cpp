#include <bits/stdc++.h>
using namespace std;
bool prime[10001];
void sieve() {
    memset(prime, true, sizeof(prime));
    for (int i = 2; i * i < 10001; i++) {
        if (prime[i]) {
            for (int j = i * 2; j <= 1001; j = j + i) {
                prime[j] = false;
            }
        }
    }
}
int main() {
    int n, x;
    cin >> n;
    sieve();
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (prime[x]) {
            cout << x;
            return 0;
        }
    }
    return 0;
}