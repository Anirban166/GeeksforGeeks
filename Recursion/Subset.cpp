void printsub(string str, string curr=" ", int index=0)
{ if(index==str.length())
  { cout<<curr<<" "; return; }
  printsub(str,curr,index+1);
  printsub(str,curr+str[index],index+1);
}
