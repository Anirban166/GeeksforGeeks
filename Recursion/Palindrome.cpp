
int s=0; e=n-1;
bool ispal(string str, int s, int e)
{ if(s==e) return true; //middle element for odd length string
  if(s>e) return true; // after whole array check
  if(str[s]!=str[e])
  return false;
  return ispal(str, s+1, e-1);
}
