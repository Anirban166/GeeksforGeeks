import java.util.*;
import java.io.*;
import java.lang.*;

class Solution
{
    static int count1s(int arr[], int n)
    {
        int l = 0, h = n-1;
        int mid= 0;
        while(l <= h)
        {
            mid = l + (h-l)/2;
            if(arr[mid] == 1 && (mid == 0 || arr[mid-1] != 1))
              return n-mid;
            else if(arr[mid] == 0)
               l = mid+  1;
             else h = mid - 1;
        }
        return 0;
    }
    public static void main (String[] args) {
        int arr[] = {0, 0, 0, 0, 1, 1, 1, 1, 1};
        int n = arr.length;
        System.out.println(count1s(arr, n));
    }
}
