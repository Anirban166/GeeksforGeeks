import java.util.*;
import java.io.*;
import java.lang.*;

class solution
{
    public static void main (String[] args) {
        int mat[][] = new int[][]{{10, 20, 30, 40}, {15, 25, 80, 85}, {35, 90, 100, 120}};
        int ele = 90;
        
        System.out.println(isPresent(mat, ele, 3, 4) ? "yes" : "no");
    }
    
    static boolean isPresent(int mat[][], int ele, int m, int n)
    {
        int row = 0, col = 3;
        while(row < m && col >= 0)
        {
            if(mat[row][col] < ele)
              row++;
            else if(mat[row][col] > ele)
               col--;
            else if(mat[row][col] == ele)
              return true;
        }
        return false;
    }
}
