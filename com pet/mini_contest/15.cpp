#include <bits/stdc++.h>

using namespace std;

const long long MAX = 100;
long long n, m, c = 0, no_entry = 0;
long long matrix[MAX][MAX];
bool visited[MAX][MAX];

long long dx[] = {1, -1, 0, 0};
long long dy[] = {0, 0, 1, -1};

long long dfs(long long x, long long y, long long cnt)
{
    visited[x][y] = true;
    long long longest_path = 0;
    for (long long i = 0; i < 4; i++)
    {
        long long nx = x + dx[i];
        long long ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && matrix[nx][ny] != -1)
        {
            if (matrix[nx][ny] == 2)
            {
                // cout << "cnt : " << cnt << endl;
                if(cnt == (m*n)-no_entry-2 ){
                    c++;
                }
                longest_path = max(longest_path, cnt + 1);
            }
            else
            {
                longest_path = max(longest_path, dfs(nx, ny, cnt + 1));
            }
        }
    }
    visited[x][y] = false;
    return longest_path;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    long long start_x, start_y;
    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == -1){
                no_entry++;
            }
            if (matrix[i][j] == 1)
            {
                start_x = i;
                start_y = j;
            }
        }
    }

    dfs(start_x, start_y, 0);
    // cout << longest_path << endl;
    cout << c << endl;
    return 0;
}