#include <bits/stdc++.h>

using namespace std;
int main() {
    string rna, port;
    cin >> rna >> port;
    
    for (long long i = 0; i < rna.size(); i++) {
        if (rna[i] == 'A') rna[i] = 'U';
        else if (rna[i] == 'U') rna[i] = 'A';
        else if (rna[i] == 'G') rna[i] = 'C';
        else if (rna[i] == 'C') rna[i] = 'G';
    }
    
    int count = 0;
    for (long long i = 0; i <= rna.size() - port.size(); i++) {
        if (rna[i] == port[0] && 
            memcmp(&rna[i], &port[0], port.size()) == 0) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
