#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s,res,word;
    set<string> str;
    set<string>::iterator itr;
    
    while (getline(cin, s)){
        if (s.size() <= 200)
            res += s;
    }
    
    replace_if(res.begin() , res.end() ,  
            [] (const char& c) { return !isalpha(c) ;},' ');
    transform(res.begin(), res.end(), res.begin(), ::tolower);

    stringstream iss(res);
    while (iss >> word){
        str.insert(word);
    }

    // for (auto x : str) {
    //     cout << x << endl;
    // }
    itr = str.begin();
    int set_size = str.size();
    for (int i = 0; i < set_size-1; i++) {
        cout << *itr << endl;
        itr++;
    }
    cout << *itr << endl;

    return 0;
}