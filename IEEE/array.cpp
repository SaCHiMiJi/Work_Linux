#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> vect[n,0];
    for (int i = 0; i < m; i++)
    {
        
    }
    
    return 0;
}


void Lexicographic(int i,int j,int arr[]){
    for (int i = 0; i < j; i++)
    {
        if (arr[i] > arr[i+!])
        {
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
        
    }
    
}

void print_array(int arr[]){
    for (int i = 0; i < arr.Size(); i++)
    {
        cout<<arr[i]<<" ";

    }
    cout<<endl;
}



template <typename T>
bool nextPermutation(std::vector<T> &vec) {
    // Find non-increasing suffix
    if (vec.size() == 0)
        return false;
    typename std::vector<T>::iterator i = vec.end() - 1;
    while (i > vec.begin() && *(i - 1) >= *i)
        --i;
    if (i == vec.begin())
        return false;
    
    // Find successor to pivot
    typename std::vector<T>::iterator j = vec.end() - 1;
    while (*j <= *(i - 1))
        --j;
    std::iter_swap(i - 1, j);
    
    // Reverse suffix
    std::reverse(i, vec.end());
    return true;
}