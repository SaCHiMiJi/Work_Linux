#include <iostream>
#include <bits/stdc++.h>
#include "HW06.cpp"
using namespace std;

int main(){
    int n = 10;
    // cin>>n;
    Scoreboard S(n);
    S.showTeamAtRank(1) ;
    S.match(0,1,2,3);
    S.showTeamAtRank(1);
    S.showTeamAtRank(4);
    S.match(3,2,1,1);
    S.showTeamAtRank(1);
    S.showTeamAtRank(2);
    S.match(3,2,4,3);
    S.showTeamAtRank(1);
    S.showTeamAtRank(3);
    S.match(2,3,1,1);
    S.match(5,7,1,1);
    S.match(6,9,4,5);
    S.match(8,4,3,0);
    S.match(4,7,4,4);
    S.match(6,0,2,5);


    return 0;
}