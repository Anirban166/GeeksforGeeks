int maxcut(int n, int a, int b, int c)
{ if(n==0) return 0; 
  if(n<0) return -1;
  int res = ( max(abs(n-a,a,b,c))
                 (abs(n-b,a,b,c))
                 (abs(n-c,a,b,c)));
  if(res==-1) return -1;
  return (res+1);
}

//Worst Time Complexity : 0(3^n)
//With Dynamic programming : 0(n)
