import java.util.*;
import java.lang.*;
import java.io.*;

class Solution
{
    public static void main (String[] args) 
    {
        int arr[] = new int[]{8, 3, -7, -4, 1};
        int n = arr.length;
        int sum = -8;
        
        System.out.println(largestSubarrayWithSumX(arr, n, sum));
        
    }
    
    static int largestSubarrayWithSumX(int arr[], int n, int sum)
    {
        int prefix_sum = 0;
        HashSet<Integer> us = new HashSet<>();
        us.add(0);
        for(int i = 0; i < n; i++)
        {
            prefix_sum += arr[i];
            if(us.contains(prefix_sum - sum))
              return 1;
            us.add(prefix_sum);
        }
        return 0;
    }
}
