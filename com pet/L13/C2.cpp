#include <bits/stdc++.h>
using namespace std;

int maxContiguousSum(int A[], int n)
{
    int j;
    int max_so_far = A[0], i;
    int curr_max = A[0];
    for (j = 1; j < n; j++)
    {
        curr_max = max(curr_max + A[j], A[j]);
        max_so_far = max(curr_max, max_so_far);
    }
    return max_so_far;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int A[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    cout << maxContiguousSum(A, n ) << endl;
    
    return 0;
}