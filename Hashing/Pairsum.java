import java.util.*;
import java.io.*;
import java.lang.*;

class Main
{
    public static void main (String[] args) {
        int arr[] = new int[]{3, 8, 4, 7, 6, 1};
        int len = arr.length;
        int x = 14;
        System.out.println(pairWithSumX(arr, len, x));
    }
    
    static int pairWithSumX(int arr[],int n, int X)
    {
        HashSet<Integer> us = new HashSet<>();
        for(int i = 0; i < n; i++)
        {
            if(us.contains(X - arr[i]))
              return 1;
              
            us.add(arr[i]);
        }
        return 0;
        
    }
}
