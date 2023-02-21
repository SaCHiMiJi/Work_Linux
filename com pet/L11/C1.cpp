#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, num, be;
    cin >> n;

    vector<int> arr_n;
    vector<int> pre_n;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        arr_n.push_back(num);
    }

    be = arr_n[0] + arr_n[1];
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            pre_n.push_back(arr_n[i] + arr_n[j]);
        }
    }

    // cout << "[ ";
    // for (auto &&i : pre_n)
    // {
    //     cout << i << " ";
    // }
    // cout << " ]" << endl;

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> num;
        int min_m = abs(pre_n[0] - num);
        for (auto &&a : pre_n)
        {
            // cout << a << endl;

            if (min_m > abs(a - num))
            {
                min_m = abs(a - num);
            }
        }
        cout << min_m << endl;
    }

    return 0;
}

// 5
// 3 12 17 33 34
// 3
// 1
// 51
// 30

// 3
// 1 2 3
// 3
// 1
// 2
// 3