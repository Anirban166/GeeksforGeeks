import java.util.*;
import java.io.*;
import java.lang.*;

class Intersecting
{
    public static void main (String[] args) {
        int arr1[] = new int[]{15, 17, 27, 27, 28, 15};
        int arr2[] = new int[]{16, 17, 28, 17, 31, 17};
        int m = arr1.length;
        int n = arr2.length;
        
        System.out.println(intersection(arr1, m, arr2, n));
    }
    
    static int intersection(int arr1[], int m, int arr2[], int n)
    {
        Set<Integer> hs = new HashSet<Integer>();
        for(int i = 0; i < m; i++)
          hs.add(arr1[i]);
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            if(hs.contains(arr2[i]))
            {
                res++;
                hs.remove(arr2[i]);
            }
        }
        return res;
    }
}
