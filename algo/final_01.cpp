#include <iostream>
#include <vector>
using namespace std;

int longest_common_subsequence(vector<int>& arr1, vector<int>& arr2) {
    int n = arr1.size();
    int m = arr2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr1[i - 1] == arr2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> correct_order(N);
    for (int i = 0; i < N; i++) {
        cin >> correct_order[i];
    }

    for (int k = 0; k < M; k++) {
        vector<int> answer(N);
        for (int i = 0; i < N; i++) {
            cin >> answer[i];
        }

        int length = longest_common_subsequence(correct_order, answer);
        cout << length << endl;
    }

    return 0;
}
