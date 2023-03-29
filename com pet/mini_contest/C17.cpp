#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, date;
    int date_curr = 0;
    cin >> n;
    string arr[n];
    string result[n];
    string word;
    for (int i = 0; i < n; i++)
    {
        cin >> date;
        getline(cin, arr[i]);
        size_t found = arr[i].find_first_not_of(' ');
        if (found != string::npos)
        {
            arr[i] = arr[i].substr(found);
        }
        if (date % 2 == 0)
        {
            date_curr += date;
            word = arr[i];
            for (auto &c : word)
            {
                if (c != ' ' && islower(c))
                {
                        c = 'a' + (c - 'a' + (26 + (date_curr % 26))) % 26;
                }
            }

            result[i] = word;
        }
        else
        {
            date_curr -= date;
            word = arr[i];
            for (auto &c : word)
            {
                if (c != ' ' && islower(c))
                {
                        c = 'a' + (c - 'a' + (26 + (date_curr % 26))) % 26;
                }
            }
            result[i] = word;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << endl;
    }
    return 0;
}