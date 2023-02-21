#include <bits/stdc++.h>
using namespace std;

void printarr(int myArray[])
{
    for (int i = 0; i < sizeof(myArray); i++) {
        cout << myArray[i] << " ";
    }
    
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a;
    int result = 0;
    int match = 0;
    cin >> n >> m;
    n = (int)pow(2, n);
    int arr[n];
    memset(arr, 0, sizeof(arr));
    // printarr(arr);
    for (int i = 0; i < m; i++)
    {
        cin >> a;
        arr[a - 1] = 1;
    }
    // printarr(arr);
    int j = 0;
    while (n > 0)
    {

        // printf("=========== j = %d ===========\n",j);
        for (int i = 0; i < n; i += 2)
        {
            match = arr[i] + arr[i + 1];
            if (match == 0)
            {
                arr[j] = 0;
            }
            else if (match == 1)
            {
                result += 1;
                arr[j] = 0;
                
            }
            else if (match== 2)
            {
                arr[j] = 1;
            }

            // cout << "i : " << i << "\nresult : " <<  result << endl;
            // printarr(arr);
            j++;
        }
        j = 0;
        n /= 2;
        // std::fill(arr + j, arr + sizeof(arr) / sizeof(int), 0);
    }

    cout << result << endl;
    return 0;
}

