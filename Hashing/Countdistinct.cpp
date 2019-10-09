#include <bits/stdc++.h>
using namespace std;

int countDistinct(int arr[], int n)
{
    unordered_set<int> us;
    for(int i = 0; i < n; i++)
      us.insert(arr[i]);
      
    return us.size();
}

int main()
{
    int arr[] = {15, 16, 27, 27, 28, 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << countDistinct(arr, n);
    
    return 0;
}
