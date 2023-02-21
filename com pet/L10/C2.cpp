#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, abcde, fghij;
    bool b = true;
    cin >> n;
    for (fghij = 1234; fghij <= 98765/n; fghij++)
    {
        abcde = fghij * n;
        int temp, used = (fghij < 10000);
        temp = abcde;
        while (temp) {
            used = used | 1 << (temp % 10);
            temp = temp / 10;
        }
        temp = fghij;
        while (temp) {
            used = used | 1 << (temp % 10);
            temp = temp / 10;
        }
        if (used == (1 << 10) - 1 && fghij <= 98765) {
            printf("%05d / %05d = %d\n", abcde, fghij, n);
            b = false;
        }
    }
    if (b)
    {
        cout << "There are no solutions for N." << endl;
    }

    return 0;
}
  