#include <bits/stdc++.h>
using namespace std;

int editDist(string str1, string str2, int m, int n)
{
    if (m == 0)
        return n;
    if (n == 0)
        return m;
    if (str1[m - 1] == str2[n - 1])
        return editDist(str1, str2, m - 1, n - 1);
    return 1 + min({
                   editDist(str1, str2, m, n - 1),    // Insert
                   editDist(str1, str2, m - 1, n),    // Remove
                   editDist(str1, str2, m - 1, n - 1) // Replace
               });
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string txt1, txt2;
    int sub, val;
    cin >> txt1 >> txt2;
    sub = ceil(max(txt1.size(), txt2.size()) / 2.0);
    val = editDist(txt1, txt2, txt1.size(), txt2.size());

    if (val >= sub)
        cout << val << " 0" << endl;
    else
        cout << val << " 1" << endl;

    return 0;
}
