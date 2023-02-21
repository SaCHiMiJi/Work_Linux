#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, Q, i, X, S, T, K, num;
    char mode;

    cin >> n >> Q;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        arr[i] = num;
    }
    for (int j = 0; j < Q; j++)
    {
        cin >> mode;
        if (mode == 'M')
        {
            cin >> i >> X;
            arr[i-1] = X;
        }
        else
        {
            int count = 0;
            cin >> S >> T >> K;
            while (T != S-1)
            {
                if (arr[T] <= K)
                {
                    count++;
                }
                T--;
            }
            
            
            cout << count << endl;
        }
    }

    return 0;
}