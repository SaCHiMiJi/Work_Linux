#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,max_n,curr = 0;
    int a;
    cin>>n;
    int ar[n];
    
    for (int i = 0; i < n; i++){
        cin>>a;
        ar[i] = a;
        // cout<<i<<" : "<<ar[i]<<endl;
        if (curr > 0 || ar[i]>0){
            if (ar[i] > 0){
                curr += ar[i];
                // cout<<"plus"<<endl;
                if (i == n-1){
                    max_n = std::max(curr,max_n);
                }
                
            }else{
                if(ar[i+1] + ar[i] >= 0){
                    curr += ar[i];
                    // cout<<"plus"<<endl;
                }else{
                    max_n = std::max(curr,max_n);
                    curr = 0;
                    // cout<<"set"<<endl; 
                }
            }
        }
        
    }
    cout<<max_n;
    return 0;
}
