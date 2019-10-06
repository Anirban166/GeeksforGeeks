int recp(int n, int p)
{ if(p==1)
  { return n;
  }
  else
  { return n*recp(n,p-1);
  }
}
