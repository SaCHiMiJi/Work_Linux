#include <bits/stdc++.h>
using namespace std; 

int sum(int a, int b, int arr[]){
    int s = 0;
    for (int i = a; i <= b; i++)
    {
        s = s + arr[i];
    }
    return s;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int max = 0 ,min, n, m, a;
    
    cin >> n >> m;
    int arr[n],result[m];
    for (int i = 0; i < n; i++){
        cin >> a;
        arr[i] = a;
    }
    for (int i = 0; i < m; i++){
        cin >> min >> max;
        result[i] = sum(min,max,arr);
    }
    for (int i = 0; i < m; i++){
        cout << result[i] << endl;
    }
    
    return 0;
}