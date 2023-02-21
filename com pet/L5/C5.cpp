#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,t,com;
    cin >> n >> t;
    int cur_arr[n];
    int result[n][t];
    for (int i = 0; i < n; i++){
        cin >> cur_arr[i];
    }

    int i=0,j=0;
    for (int k = 0; k < t; k++){   
        cin >> com;
        if (com == 1){
            cin >> i >> j;
            if (i <= n && j > cur_arr[i-1])
                cur_arr[i-1] += 1;
        } 
        else if (com == 2){
            cin >> i >> j;
            if (i <= n && j <= cur_arr[i-1])
                cur_arr[i-1] -= 1;
        } 
        else if (com == 3){
            cin >> i >> j;
            // left
            if(i == 1){
                //No. == I
                if(cur_arr[i-1] <= j - 2){
                    cur_arr[i-1] = cur_arr[i-1];
                }
                else if(cur_arr[i-1] == j - 1){
                    cur_arr[i-1] -= 1;
                }
                else if(cur_arr[i-1] == j){
                    cur_arr[i-1] -= 2;
                }
                else{
                    cur_arr[i-1] -= 3;
                }
                //No. == I + 1
                if(cur_arr[i] <= j - 2){
                    cur_arr[i] = cur_arr[i];
                }
                else if(cur_arr[i] == j - 1){
                    cur_arr[i] -= 1;
                }
                else if(cur_arr[i] == j){
                    cur_arr[i] -= 2;
                }
                else{
                    cur_arr[i] -= 3;
                }
            }
            //right
            else if(i == n){
                if(cur_arr[i-2] <= j - 2){
                    cur_arr[i-2] = cur_arr[i-2];
                }
                else if(cur_arr[i-2] == j - 1){
                    cur_arr[i-2] -= 1;
                }
                else if(cur_arr[i-2] == j){
                    cur_arr[i-2] -= 2;
                }
                else{
                    cur_arr[i-2] -= 3;
                }
                if(cur_arr[i-1] <= j - 2){
                    cur_arr[i-1] = cur_arr[i-1];
                }
                else if(cur_arr[i-1] == j - 1){
                    cur_arr[i-1] -= 1;
                }
                else if(cur_arr[i-1] == j){
                    cur_arr[i-1] -= 2;
                }
                else{
                    cur_arr[i-1] -= 3;
                }
            }
            //middle
            else if(i < n){
                if(cur_arr[i-2] <= j - 2){
                    cur_arr[i-2] = cur_arr[i-2];
                }
                else if(cur_arr[i-2] == j - 1){
                    cur_arr[i-2] -= 1;
                }
                else if(cur_arr[i-2] == j){
                    cur_arr[i-2] -= 2;
                }
                else{
                    cur_arr[i-2] -= 3;
                }
                if(cur_arr[i-1] <= j - 2){
                    cur_arr[i-1] = cur_arr[i-1];
                }
                else if(cur_arr[i-1] == j - 1){
                    cur_arr[i-1] -= 1;
                }
                else if(cur_arr[i-1] == j){
                    cur_arr[i-1] -= 2;
                }
                else{
                    cur_arr[i-1] -= 3;
                }
                if(cur_arr[i] <= j - 2){
                    cur_arr[i] = cur_arr[i];
                }
                else if(cur_arr[i] == j - 1){
                    cur_arr[i] -= 1;
                }
                else if(cur_arr[i] == j){
                    cur_arr[i] -= 2;
                }
                else{
                    cur_arr[i] -= 3;
                }
            }
            else{
                cur_arr[i] = cur_arr[i];
            }
        } 
        else if (com == 4){
            cin >> j;
            if(j > 0){
                for (int l = 0;l < n;l++){
                    if (cur_arr[l] >= j){
                        cur_arr[l] -= 1;
                    }
                }
            }
            else{
                cur_arr[i] = cur_arr[i];
            }
        }
        for(int a = 0;a < n; a++){
            result[a][k] = cur_arr[a];
        }
    }

    for (int x = 0; x < t; x++){
        for(int y = 0;y < n;y++){
        cout << result[y][x] << " ";
        }
        cout << "\n";
    }
    return 0;
}
