#include <bits/stdc++.h>
using namespace std;

int maxDamage = 0;
vector<vector<int>> grid(8, vector<int>(8));
vector<bool> rowUsed(8, false), colUsed(8, false), diag1Used(15, false), diag2Used(15, false);

void search(int col, int damage)
{
    if (col == 8)
    {
        maxDamage = max(maxDamage, damage);
        return;
    }

    for (int row = 0; row < 8; row++)
    {
        if (!rowUsed[row] && !colUsed[col] && !diag1Used[row + col] && !diag2Used[row - col + 7])
        {
            rowUsed[row] = colUsed[col] = diag1Used[row + col] = diag2Used[row - col + 7] = true;
            search(col + 1, damage + grid[row][col]);
            rowUsed[row] = colUsed[col] = diag1Used[row + col] = diag2Used[row - col + 7] = false;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                cin >> grid[i][j];
            }
        }

        maxDamage = 0;
        search(0, 0);
        cout << maxDamage << endl;
    }
    return 0;
}
