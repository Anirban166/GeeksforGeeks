
stack<int> deleteMidUtil(stack<int> s,int sof, int mid);
stack<int> deleteMid(stack<int>s,int sizeOfStack,int current)
{
if(sizeOfStack <= 1){return(s);}
int mid=ceil(sizeOfStack/2.0);
return(deleteMidUtil(s,sizeOfStack,mid));
}
stack<int> deleteMidUtil(stack<int> s,int sof, int mid)
{
int item=s.top();
s.pop();
if(sof == mid){return(s);}
s=deleteMidUtil(s,sof-1,mid);
s.push(item);
return(s);
}

//----------------------recursive, throws error:
void rec_func(stack<int>&x,int index,int n)
{
if (index<0) return;
if(index!=(n/2)){
int temp = x.top();
x.pop();
rec_func(x,index-1,n);
x.push(temp);
}
else{
x.pop();
rec_func(x,index-1,n);
}
}
stack<int> DeleteMid(stack<int>s,int sizeOfStack,int current)
{
rec_func(s,sizeOfStack-1,sizeOfStack-1);
return s;
}
