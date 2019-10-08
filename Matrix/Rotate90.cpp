void rotateby90(int n, int a[][N])
{
    
    int i,j,t[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            t[i][j]=a[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            a[i][j]=t[j][n-1-i];
        }
    }
    
}
