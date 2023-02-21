#include <bits/stdc++.h>
using namespace std;
bool prime(int x) {
    if (x == 1) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}
int main() {
    int n, x;
    cin >> n;
    bool has_prime = false;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (prime(x)) {
            cout << x;
            return 0;
        }
    }
    return 0;
}