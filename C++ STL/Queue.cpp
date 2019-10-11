//Basic Push (enqueue) Pop (dequeue) - push adds an item at the end of the queue. pop deletes.
#include<iostream>
#include<queue>
using namespace std;
int main()
{ queue<int>q;
  q.push(10);
  q.push(20);
  q.push(30);
  cout<<q.front()<<" "<<q.back()<<endl;
  q.pop();
 } 
-----------------
//Queue Traversal
#include<iostream>
#include<queue>
using namespace std;
int main()
{ queue<int>q;
  q.push(10);
  q.push(20);
  q.push(30);
  cout<<q.size(); //3
   while(q.empty()==false)
   { cout<<q.front()<<" "<<q.back()<<endl;
     q.pop();
   }
  }
  //time complexity of all operations : O(1), like stack.
  //push(),pop(),front(),back(),empty(),size()
  //push_back(),pop_front()
  //containers - queue is implemented using : list, dequeue container (default)
