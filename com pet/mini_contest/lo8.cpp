#include <bits/stdc++.h>
using namespace std;

int max_knight(int n, int m){
    if (m == 1 || n == 1){
        return max(m, n);
    }

    else if (m == 2 || n == 2){
        int c = 0;
        c = (max(m, n) / 4) * 4;

        if (max(m, n) % 4 == 1){
            c += 2;
        }else if (max(m, n) % 4 > 1){
            c += 4;
        }
        return c;
    } else{
        return (((m * n) + 1) / 2);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    cout << max_knight(n, m);

    return 0;
}