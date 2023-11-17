#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int edit_distance(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else {
                int insert_cost = dp[i][j - 1] + 1;
                int delete_cost = dp[i - 1][j] + 1;
                int replace_cost = dp[i - 1][j - 1] + (str1[i - 1] != str2[j - 1] ? 1 : 0);
                dp[i][j] = min({insert_cost, delete_cost, replace_cost});
            }
        }
    }

    return dp[m][n];
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    int cost = edit_distance(str1, str2);
    cout << cost << endl;
    return 0;
}
