#include<iostream>
#include<stack>
using namespace std;
int main()
{ stack<int>s;
  s.push(10);
  s.push(20);
  s.push(30);
  cout<<s.size()<<endl; //3
  cout<<s.top()<<endl; //30
  s.pop();
  cout<<s.top()<<endl; //20
 }
 
 //Traversal:
#include<iostream>
#include<stack>
using namespace std;
int main()
{ stack<int>s;
  s.push(10);
  s.push(20);
  s.push(30);
  while(s.empty()==false)
  { cout<<s.top()<<" "; //30 20 10
    s.pop();
  }
 }
