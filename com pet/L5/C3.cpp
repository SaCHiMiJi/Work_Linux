#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    list<char> arr;
    list<char>::iterator it = arr.begin();
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '[')
        {
            it = arr.begin();
        }
        else if (str[i] == ']')
        {
            it = arr.end();
        }
        else
        {
            arr.insert(it, str[i]);
        }
    }
    for (it = arr.begin(); it != arr.end(); it++)
    {
        cout <<*it;
    }
    cout<<endl;
    return 0;
}