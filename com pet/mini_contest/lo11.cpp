#include <iostream>
#include <string>

using namespace std;

string convert_base(long long n, int k) {
    string base = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    string res = "";
    while (n > 0) {
        int remainder = n % k;
        res = base[remainder] + res;
        n /= k;
    }
    return res.empty() ? "0" : res;
}

int main() {
    long long n;
    int k;
    cin >> n >> k;
    cout << convert_base(n, k) << endl;
    return 0;
}
