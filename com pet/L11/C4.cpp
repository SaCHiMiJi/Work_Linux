#include <bits/stdc++.h>
using namespace std;

#define N 8
// int c = 0;

void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << " " << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int board[N][N], int row, int col)
{
    int i, j;

    //  row col
    for (i = 0; i < N; i++)
        if (board[row][i])
            return false;
    // if (board[i][col])
    //     return false;

    // <= up
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // => up
    for (i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;

    // <= down
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    // => down
    for (i = row, j = col; j < N && i < N; i++, j++)
        if (board[i][j])
            return false;

    return true;
}

void solveNQUtill(int board[N][N], int col)
{
    if (col >= N)
    {
        // c++;
        printSolution(board);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (board[j][i])
                {
                    cout << j + 1 << " ";
                    break;
                }
            }
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;
            solveNQUtill(board, col + 1);
            board[i][col] = 0;
        }
    }
    if (col != 8)
    {
        solveNQUtill(board, col + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, r, c;

    cin >> n;
    int board[N][N] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}};
    for (int i = 0; i < n; i++)
    {
        cin >> r >> c;
        board[r - 1][c - 1] = 1;
        solveNQUtill(board, n);
        board[r - 1][c - 1] = 0;
    }

    // printSolution(board);
    // cout << "\n";
    return 0;
}
