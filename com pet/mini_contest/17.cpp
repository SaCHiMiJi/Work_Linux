#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, num, key=0;
    string text;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        
        getline(cin >> ws, text);

        int len = text.length();
        for (int j = 0; j < len; j++)
        {
            if (text[j] == ' '){
                cout << " ";
            }else if (num % 2 == 0){  
                key += abs(num);                                    
                cout << char((int(text[j]) + key - 97) % 26 + 97);      
            }else{
                key += abs(num);                                                        
                cout << char((int(text[j]) - key + 26 - 97) % 26 + 97);
            }
        }
        cout << endl;
    }
    return 0;
}
