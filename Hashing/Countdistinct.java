import java.util.*;
import java.io.*;
import java.lang.*;

class Distinct
{
    public static void main (String[] args) {
        int arr[] = new int[]{15, 16, 27, 27, 28, 15};
        int n = arr.length;
        
        System.out.println(countDistinct(arr, n));
    }
    
    static int countDistinct(int arr[], int n)
    {
        Set<Integer> hs = new HashSet<Integer>();
        for(int i = 0; i < n; i++)
          hs.add(arr[i]);
    
       return hs.size();        
    }
}
