#include <bits/stdc++.h>
using namespace std;

int leftIndex(int arr[], int n, int x)
{
    int l = 0, h = n-1;
    int mid = 0;
    
    while(l <= h)
    {
        mid = l + (h-l)/2;
        
        if(arr[mid] == x && (mid == 0 || arr[mid-1] != x))
          return mid;
        
        else if(arr[mid] >= x)
          h = mid-1;
        else l = mid + 1;
    }
    return -1;
}

int main()
{
    int arr[] = {2, 3, 3, 3, 3, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int ele = 3;
    cout << leftIndex(arr, n, ele);
    
    return 0;
}
