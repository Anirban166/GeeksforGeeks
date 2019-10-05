void f(int n)
{ if(n==0) return;
  cout<<n<<" ";
  f(n-1);
}
//print n to 1

void f(int n)
{ if(n==0) return;
  f(n-1);
  cout<<n<<" ";
}
//print 1 to n

tail recursive - when recursive call comes at end of function.
eg above : n to 1 function.
eg : quick sort.
thats why quick sort is faster than merge sort.

convert into tail recursive:

void f(int n)
{ f(n-1);
  cout<<n;
}

void f(int n, int k=1)
{ 
  cout<<n;
  f(n-1,k+1);
}
