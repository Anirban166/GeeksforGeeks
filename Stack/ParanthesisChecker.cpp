#include<bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       if(ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}

/*This is a function problem.You only need to complete the function given below*/
// Function to return if the paranthesis are balanced or not
bool ispar(string x)
{
string stack;
stack.push_back(x[0]);
int top = 0;
int n = x.length();

for(int i = 1; i < n; i++)
{

char ch = x[i];

if(top == -1)
{
stack.push_back(x[i]);
top++;
}
else if(x[i] == ')')
{
if(stack[top] != '(')
return false;
stack.pop_back();
top--;
}
else if(x[i] == ']')
{
if(stack[top] != '[')
return false;
stack.pop_back();
top--;
}
else if(x[i] == '}')
{
if(stack[top] != '{')
return false;
stack.pop_back();
top--;
}
else
{
stack.push_back(x[i]);
top++;
}

}
if(top != -1)
return false;
return true;
}

