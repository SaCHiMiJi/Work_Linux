#include <iostream>
#include <map>
#include <string>
#include <functional>
#include <bits/stdc++.h>
using namespace std;

vector<string> split(const string& s, char c, vector<string>& v) {
    string::size_type i = 0;
    string::size_type j = s.find(c);

    while (j != string::npos) {
        v.push_back(s.substr(i, j-i));
        i = ++j;
        j = s.find(c, j);

        if (j == string::npos)
            v.push_back(s.substr(i, s.length()));
    }
    return v;
}

int main()
{
    int T, d;
    cin>>T>>d;
    string arr[] = {
        " ","o"," ",
        "/","|","\\",
        "/"," ","\\"
    };
    map<string, map<string, map<string, string>>> my_map = {
        {"left",
           {
                {
                    "hand",{
                        {"head", ")"},
                        {"hip", ">"},
                        {"start", "\\"},
                    }
                },
                {
                    "leg",{
                        {"in", ">"},
                        {"out", "\\"}
                    }
                }
            }
        },
        {"right",
            {            
                {
                    "hand",{
                        {"head", "("},
                        {"hip", "<"},
                        {"start", "/"}
                    }
                },
                {
                    "leg",{
                        {"in", "<"},
                        {"out", "/"}
                    }
                }
            }
        }

    };
    for (int i = 0; i < d; i++)
    {
        vector<string> v;
        string s;
        cin>>s;
        v = split(s,' ',v);
        
        cout<<v[0]<<endl;
        if (v[0] == "say")
        {
            for (int i = 1; i < v.size(); i++)
            {
            cout<<v[i]<<" ";
            }
        cout<<endl;
            
        }
        
    }
    
    
    // cout << my_map["left"]["hand"].find("\\")<<endl;
    
    // cout<<my_map["left"]["hand"]["start"]<<endl;
    
    
    
    return 0;
}

// int* updatehuman(int* arr){
//     return arr;
// }

void print_human(int* arr){
    int j = 0;
    for (int i = 0; i < 9; i++)
    {
        j++;
        cout<<arr[i];
        if (j == 3)
        {
            cout<<endl;
            j=0;
        }
        
    }
}