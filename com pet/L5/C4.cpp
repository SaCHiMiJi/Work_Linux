#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int count = 0,c =0,row =0;
    string str;
    cin >> str;
    char l_str[1000];
    for (int i = 0; i < str.length(); i++)
    {
        if (i == 0)
        {
            l_str[0] = str[i];
            count++;
            row++;
        }
        else
        {
            for (int j = 0; j < row; ++j)
            {
                // cout << "i : " << i << endl;
                // cout << "j : " << j << endl;
                if (l_str[j] >= str[i])
                {
                    // cout << "update" << endl;
                    l_str[j] = str[i];
                    c++;
                    break;
                }
            }
            if (c != 1)
            {
                l_str[row] = str[i];
                row++;
                count += 1;
            }
            else{
                c = 0;
            }
        }
    }

    cout << count << endl;

    return 0;
}