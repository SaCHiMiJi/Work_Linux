#include <bits/stdc++.h>
using namespace std;

int CHANGE(int n ,int d[], int k)
{
    int C[n + 1],min;
    C[0] = 0; // base case
    for (int p = 1; p <= n; p++)
    {
        min = n;
        for (int i = 0; i < k; i++)
        { // ลองทุกเหรียญ
            if (p >= d[i])
            { // ถ้าค่าของเหรียญมากกว่าไม่ท า
                if (C[p - d[i]] + 1 < min)
                {
                    min = C[p - d[i]] + 1;
                }
            }
        }
        C[p] = min;
    }
    return C[n];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, k;
    cin >> N >> k;
    int atk[k];
    for (int i = 0; i < k; i++)
    {
        cin >> atk[i];
    }
    cout << CHANGE(N, atk, k) << endl;
}
