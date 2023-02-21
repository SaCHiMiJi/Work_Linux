#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, k, x, a;
    char mode;
    vector<vector<string>> stu;
    vector<string> school;
    priority_queue<int, vector<int>, greater<int> > pq;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> k;
        for (int i = 0; i < k; i++)
        {
            cin >> a;
            string txt = string(i) + string(a);
            school.push_back(txt);
        }
        stu.push_back(school);
    }
    while (true)
    {
        cin >> mode;
        if (mode == 'E')
        {
            cin >> x;
            pq.push(x);
        }
        else if (mode == 'D')
        {
            cout << pq.top() << endl;
            pq.pop();
        }
        else
        {
            break;
        }
    }

    return 0;
}
