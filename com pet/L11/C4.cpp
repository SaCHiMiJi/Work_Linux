#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<int> &board, int col)
{
    for (int i = 0; i < col; i++)
    {
        if (board[i] == board[col] || abs(board[i] - board[col]) == col - i)
        {
            return false;
        }
    }
    return true;
}

void solve(vector<int> &board, int col, int fixed_row, int fixed_col, vector<vector<int>> &solutions)
{
    if (col == 8)
    {
        if (board[fixed_col] == fixed_row)
        {
            solutions.push_back(board);
        }
        return;
    }

    for (int row = 1; row <= 8; row++)
    {
        board[col] = row;
        if (isValid(board, col))
        {
            solve(board, col + 1, fixed_row, fixed_col, solutions);
        }
    }
}

int main()
{
    int N;
    cin >> N;
    for (int t = 0; t < N; t++)
    {
        int r, c;
        cin >> r >> c;

        vector<int> board(8);
        vector<vector<int>> solutions;
        solve(board, 0, r, c - 1, solutions);

        for (const auto &sol : solutions)
        {
            for (int i = 0; i < sol.size(); i++)
            {
                cout << sol[i] << (i < sol.size() - 1 ? ' ' : '\n');
            }
        }

        if (t < N - 1)
            cout << endl;
    }

    return 0;
}
