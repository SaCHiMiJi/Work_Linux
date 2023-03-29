#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main() {

    // define the mapping between digits and characters
    map<char, string> mapping = {
        {'1', "ijIJ"},
        {'2', "abcABC"},
        {'3', "defDEF"},
        {'4', "ghGH"},
        {'5', "klKL"},
        {'6', "mnMN"},
        {'7', "prsPRS"},
        {'8', "tuvTUV"},
        {'9', "wxyWXY"},
        {'0', "oqzOQZ"}
    };

    string number;
    cin >> number;

    int n;
    cin >> n;

    vector<string> words;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;

        bool match = true;
        for (int j = 0; j < number.length(); j++) {
            if (mapping.find(number[j]) == mapping.end() || mapping[number[j]].empty() || mapping[number[j]].find(tolower(word[j])) == string::npos) {
                match = false;
                break;
            }
        }

        if (match and word.size() <= number.size()) {
            words.push_back(word);
        }
    }

    sort(words.begin(), words.end());
    if (words.empty()) {
        cout << "No\n";
    } else {
        for (string word : words) {
            cout << word << "\n";
        }
    }

    return 0;
}
