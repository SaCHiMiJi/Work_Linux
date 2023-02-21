#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    for (int x = -c; x < a / 2; x++)
    {
        for (int y = x; y <= a / 2; y++)
        {
            int z = a - x - y;
            if (x + y + z == a)
            {
                if (x * y * z == b)
                {
                    if (x * x + y * y + z * z == c)
                    {
                        printf("%d %d %d\n", x, y, z);
                        goto end;                
                    }
                }
            }
        }
    }
    cout << "No solution." << endl;
    end:
    return 0;
}
