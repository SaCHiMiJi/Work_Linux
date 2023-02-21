#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int X, Y, R, N, T, num, mode, result;
    cin >> N;
    int og_map[N][N], map[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> num;
            og_map[i][j] = num;
            map[i][j] = num;
        }
    }
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> mode;
        if (mode == 3)
        {
            result = 0;
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    result += map[i][j];
                }
            }
            cout << result << endl;
        }
        else
        {
            cin >> X >> Y >> R;
            int min_row = X - R;
            int max_row = X + R;
            int min_col = X - R;
            int max_col = X + R;
            if (X - R < 0)
            {
                min_row = 0;
            }
            if (X + R > N - 1)
            {
                max_row = N - 1;
            }
            if (Y - R < 0)
            {
                min_col = 0;
            }
            if (Y + R > N - 1)
            {
                max_col = N - 1;
            }

            for (int i = min_row; i < max_row; i++)
            {
                for (int j = min_col; j < max_col; j++)
                {
                    if (mode == 1)
                    {
                        map[i][j] = 0;
                    }
                    else
                    {
                        map[i][j] = og_map[i][j];
                    }
                }
            }
        }
    }

    return 0;
}
// for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < N; j++)
//         {
//             cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }