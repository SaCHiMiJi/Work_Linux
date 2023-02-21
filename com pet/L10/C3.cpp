#include<bits/stdc++.h>
using namespace std;

void search(vector<int> S, int k, int start,vector<int> permutation) {

    // base case
    if (k == 0) {
        for (int i = 0; i < permutation.size(); i++)
            cout << permutation[i] << " ";
        cout << endl;
        return;
    }

    for (int i = start; i < S.size(); i++) {
        permutation.push_back(S[i]);
        search(S, k - 1, i + 1, permutation);
        permutation.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> k;
    vector<int> S(k);
    for (int i = 0; i < k; i++)
        cin >> S[i];

    vector<int> permutation;
    search(S, 6, 0, permutation);

    return 0;
}