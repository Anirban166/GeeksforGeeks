static void boundaryTraversal(int n1, int m1, int a[][])
{
	if(n1==1 || m1== 1){
		 for(int i=0;i<n1;i++)
			 for(int j=0;j<m1;j++)
				 System.out.print(a[i][j]+" ");
		 return;
	}
	int row = 0, col=0;
	for(col = 0;col<m1; col++)
		System.out.print(a[row][col]+" ");
	col=m1-1;
	for(row=1;row<n1;row++)
		System.out.print(a[row][col]+" ");
	row=n1-1;
	for(col=m1-2;col>=0;col--)
		System.out.print(a[row][col]+" ");
	col = 0;
	for(row=n1-2;row>0;row--)
		System.out.print(a[row][col]+" ");
}

//---------------------------------------
class GFG { 

	public static void printBoundary(int a[][], int m, 
									int n) 
	{ 
		for (int i = 0; i < m; i++) { 
			for (int j = 0; j < n; j++) { 
				if (i == 0) 
					System.out.print(a[i][j] + " "); 
				else if (i == m - 1) 
					System.out.print(a[i][j] + " "); 
				else if (j == 0) 
					System.out.print(a[i][j] + " "); 
				else if (j == n - 1) 
					System.out.print(a[i][j] + " "); 
				else
					System.out.print("  "); 
			} 
			System.out.println(""); 
		} 
	} 

	/* Driver program to test above function */
	public static void main(String[] args) 
	{ 
		int a[][] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 1, 2, 3, 4 }, { 5, 6, 7, 8 } }; 

		printBoundary(a, 4, 4); 
	} 
} 
