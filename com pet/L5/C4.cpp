#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;

    cin >> str;
    set<char> x;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            x.insert(str[i]);
        }
        
    } 
    
    cout << x.size();

    return 0;
}