import java.util.*;
import java.io.*;
import java.lang.*;

class Solution
{
    static int leftIndex(int arr[], int n, int x)
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
    
    static int rightIndex(int arr[], int n, int x)
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
    public static void main (String[] args) {
        int arr[] = new int[]{2, 3, 4, 5, 5, 5, 6, 6};
        int n = arr.length;
        int ele = 5;
        
        int leftOccur = leftIndex(arr, n, ele);
        int rightOccur = rightIndex(arr, n, ele);
        
        System.out.println(rightOccur - leftOccur + 1);
    }
}
