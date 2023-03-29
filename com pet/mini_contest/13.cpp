#include <bits/stdc++.h>
using namespace std;

void findMin(long long V, vector<long long>& denomination)
{
    sort(denomination.rbegin(), denomination.rend());

    vector<long long> ans;
    for (long long i = 0; i < denomination.size(); i++) {
        while (V >= denomination[i]) {
            ans.push_back(denomination[i]);
            V -= denomination[i];
        }
    }

    if (V > 0) {
        cout << "-1" << endl;
    } else {
        cout << ans.size() << endl;
    }
}

int main()
{
    long long start, stop, n;
    cin >> start >> stop >> n;
    
    long long V = abs(stop - start);

    vector<long long> denomination(n);
    for (long long i = 0; i < n; i++) {
        cin >> denomination[i];
    }

    findMin(V, denomination);

    return 0;
}
