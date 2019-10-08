class ModifyMat
{
    static void booleanMatrix(int r, int c, int mat[][])
{
    int row[] = new int[r];
	int col[] = new int[c];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (mat[i][j] == 1) {
				row[i] = 1;
				col[j] = 1;
			}
		}
	}
	StringBuilder sb=new StringBuilder();
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (col[j] == 1 || row[i] == 1)
				mat[i][j] = 1;
			sb.append(mat[i][j] + " ");
		}
		sb.append("\n");
	}
	System.out.print(sb);
}

}
//--------------------------------------------------
//Initial Template for Java
import java.lang.*;
import java.io.*;
import java.util.*;
class Driverclass
{
    
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        
        while(t-- > 0)
        {
            int r = 0, c = 0;
            String str[] = read.readLine().trim().split("\\s+");
            r = Integer.parseInt(str[0]);
            c = Integer.parseInt(str[1]);
             int mat[][] = new int[r][c];
            
            for(int i = 0; i < r; i++)
            {
                int k = 0;
                str = read.readLine().trim().split("\\s+");
                for(int j = 0; j < c; j++)
                {
                  mat[i][j] = Integer.parseInt(str[k]);
                  k++;
                }
            }
            new ModifyMat().booleanMatrix(r, c, mat);
        }
    }
}
