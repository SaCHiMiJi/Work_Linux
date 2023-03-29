#include <bits/stdc++.h>
using namespace std;

int main() {
    long long health, first_run, second_run, damage = 0, count = 2;
    cin >> health >> first_run >> second_run;
    vector<long long> run(2, 0);
    run[0] = first_run;
    run[1] = second_run;
    damage = pow(first_run, 2);
    if(damage >= health){
        count--;
        cout << count << endl;
        cout << damage << endl;
    }
    else{
        damage += pow(second_run, 2);
        while (health > damage) {
            long long next_run = run[count-2] + run[count-1];
            run.push_back(next_run);
            damage += pow(next_run, 2);
            count++;
        }
        cout << count << endl;
        cout << damage << endl;
    }
    return 0;
}