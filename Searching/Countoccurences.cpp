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

int rightIndex(int arr[], int n, int x)
{
    int l = 0, h = n-1;
    int mid = 0;
    
    while(l <= h)
    {
        mid = l + (h-l)/2;
        
        if(arr[mid] == x && (mid == n-1 || arr[mid+1] != x))
          return mid;
        
        else if(arr[mid] > x)
          h = mid-1;
        else l = mid + 1;
    }
    return -1;
}

int main()
{
    int arr[] = {2, 3, 4, 5, 5, 5, 6, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int ele = 5;
    int leftOccur = leftIndex(arr, n, ele);
    int rightOccur = rightIndex(arr, n, ele);
    cout << rightOccur - leftOccur + 1;
    return 0;
}
