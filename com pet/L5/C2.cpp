#include <bits/stdc++.h>
using namespace std;

string reverse_str(string str, int n){
    n = str.length();
    for (int i = 0; i < n / 2; i++){
        swap(str[i], str[n - i - 1]);
    }
    return str;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string str, text, r ="";

    getline(cin, str);
    stringstream s(str);
    n = str.length();
    while (s >> text)
    {
        // cout << text <<endl;
        n = text.length();
        for (int i = 0; i < n / 2; i++){
            swap(text[i], text[n - i - 1]);
        }
        cout << text << " ";    
    }
    
    cout << endl;
    return 0;
}

