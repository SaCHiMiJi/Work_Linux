#include<bits/stdc++.h>
using namespace std;
class Interval {
public:
    int open, close;
    bool operator < (const Interval& x) const   {
        if (close != x.close)
            return close < x.close;
        return open < x.open;
    }
} *intervals;

int main()  {
    int n, last_buf;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n; 
    intervals = new Interval[n];
    for (int i = 0; i < n; i++)
        cin >> intervals[i].open >> intervals[i].close;

    sort(intervals, intervals + n);

    queue <int> opt;
    for (int i = 0, last_buf = 0; i < n; i++)
        if (intervals[i].open >= last_buf)    {
            opt.push(i);
            last_buf = intervals[i].close;
        }

    cout << opt.size() << endl;

    return 0;
}