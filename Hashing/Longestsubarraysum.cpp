#include <bits/stdc++.h>
using namespace std;

int largestSubarrayWithSumX(int arr[], int n, int sum)
{
    int prefix_sum = 0;
    unordered_set<int> us;
    us.insert(0);
    for(int i = 0; i < n; i++)
    {
        prefix_sum += arr[i];
        if(us.find(prefix_sum - sum) != us.end())
          return 1;
        us.insert(prefix_sum);
    }
    return 0;
}

int main()
{
    int arr[] = {8, 3, -7, -4, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = -8;
    
    cout << largestSubarrayWithSumX(arr, n, sum);
    
}
