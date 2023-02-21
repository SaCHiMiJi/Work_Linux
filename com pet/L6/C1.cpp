#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n, b;
    long long result = 0;
    long long cost = 0;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 0; i < n; i++)
    {
        cin >> b;
        q.push(b);
    }
    for (int i = 0; i < n - 1; i++)
    {
        cost = q.top();
        q.pop();
        cost += q.top();
        q.pop();
        result += cost;
        q.push(cost);
        // cout << "i : " << i <<"\ncurr : " << cost << "\nresult : "<< result << endl;
    }

    cout << result << endl;
    return 0;
}
