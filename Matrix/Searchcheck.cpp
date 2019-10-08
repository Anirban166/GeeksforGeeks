#include <bits/stdc++.h>
using namespace std;

bool isPresent(int mat[][4], int m, int n, int ele)
{
    int row = 0, col = n-1;
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

int main()
{
    int mat[3][4] = {{10, 20,  30, 40}, {15, 25, 80, 85}, {35, 90, 100, 120}};
    int ele = 90;
    if(isPresent(mat, 3, 4, ele))
      cout << "yes";
      else cout << "no";
    
}
