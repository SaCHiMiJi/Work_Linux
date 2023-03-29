#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<char>> &board, int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        if (board[row][i] == 'Q')
            return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }
    for (int i = row, j = col; i < board.size() && j >= 0; i++, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }
    return true;
}

int solve(vector<vector<char>> &board, int col)
{
    if (col == board.size())
        return 1;

    int count = 0;
    for (int row = 0; row < board.size(); row++)
    {
        if (board[row][col] == '*' || !isValid(board, row, col))
            continue;

        board[row][col] = 'Q';
        count += solve(board, col + 1);
        board[row][col] = '.';
    }
    return count;
}

int main()
{
    int C;
    cin >> C;
    while (C--)
    {
        int N;
        cin >> N;
        vector<vector<char>> board(N, vector<char>(N));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> board[i][j];
            }
        }

        cout << solve(board, 0) << endl;
    }
    return 0;
}
