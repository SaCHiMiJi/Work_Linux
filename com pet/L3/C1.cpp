#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int result = 0;
    int arr[n];
    int max_;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        max_ += arr[i];
        if (result < max_){
            result = max_;
        }
        if(max_ < 0){
            max_ = 0;
        }
    }
    cout << result;

    return 0;
}