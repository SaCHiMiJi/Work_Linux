#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin >> str;
    
    if (next_permutation(str.begin(), str.end())){
        cout << str << endl;
    } else {
        cout << "No Successor" << endl;
    }

}
