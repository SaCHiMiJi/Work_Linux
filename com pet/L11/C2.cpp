#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(int set[], int n, int sum)
{
    
    // Base Cases
    if (sum == 0)
        return true;
    if (n == 0)
        return false;
  
    // If last element is greater than sum,
    // then ignore it
    if (set[n - 1] > sum)
        return isSubsetSum(set, n - 1, sum);
  
    return isSubsetSum(set, n - 1, sum)
           || isSubsetSum(set, n - 1, sum - set[n - 1]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, p, num;
    int l_l[p];
    cin >> n >> p;
    for (int i = 0; i < p; i++)
    {
        cin >> num;
        l_l[i] = num;
    }
    if (isSubsetSum(l_l,p,n)){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    

    return 0;
}
