#include <iostream>
#include <vector>

using namespace std;

// Function to build the prefix table
void buildPrefixTable(const string &pattern, vector<int> &prefixTable) {
    int length = 0;  // Length of the current proper prefix that is also a suffix
    
    prefixTable[0] = 0;  // The first character doesn't have a proper prefix
    
    for (int i = 1; i < pattern.length(); ) {
        if (pattern[i] == pattern[length]) {
            length++;
            prefixTable[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = prefixTable[length - 1];
            } else {
                prefixTable[i] = 0;
                i++;
            }
        }
    }
}

// Function to print the prefix table
void printPrefixTable(const vector<int> &prefixTable) {
    cout << "Prefix Table: ";
    for (int value : prefixTable) {
        cout << value << " ";
    }
    cout << endl;
}

// Function to perform pattern matching using KMP algorithm
void kmpSearch(const string &text, const string &pattern) {
    int textSize = text.length();
    int patternSize = pattern.length();
    
    vector<int> prefixTable(patternSize);
    buildPrefixTable(pattern, prefixTable);
    
    printPrefixTable(prefixTable);
    
    int i = 0;  // Index for text
    int j = 0;  // Index for pattern
    
    while (i < textSize) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        
        if (j == patternSize) {
            cout << "Pattern found at index " << i - j << endl;
            j = prefixTable[j - 1];
        } else if (i < textSize && pattern[j] != text[i]) {
            if (j != 0) {
                j = prefixTable[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    string text = "causecaqcqcqcsqsqaqqcsqac";
    string pattern = "caqcqcqc";
    
    kmpSearch(text, pattern);
    
    return 0;
}
