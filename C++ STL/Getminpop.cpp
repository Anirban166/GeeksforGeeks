#include <bits/stdc++.h>
using namespace std;
stack<int>_push(int arr[],int n);
void _getMinAtPop(stack<int>s);
//Position this line where user code will be pasted.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    stack<int>mys=_push(arr,n);
	    _getMinAtPop(mys);
	    cout<<endl;
	    
	    
	    
	}
	return 0;
}


/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
/* inserts elements of the array into 
   stack and return the stack
*/
stack<int>_push(int arr[],int n)
{
    stack<int> stk;
   // your code here

   for(int i=0;i<n;i++){
       stk.push(arr[i]);
   }

   return stk;
}
/* print minimum element of the stack each time
   after popping.
*/
void _getMinAtPop(stack<int>s)
{
    while(!s.empty()){
        stack<int> sdash=s;
        int min=INT_MAX,min_index=-1;
        int i=0;
        while(!sdash.empty()){
            if(sdash.top()<min){
                min=sdash.top();
                min_index=i;
            }
            i++;
            sdash.pop();
        }
        for(int j=0;j<=min_index;j++){
            cout<<min<<" ";
            s.pop();
        }
    }
}
