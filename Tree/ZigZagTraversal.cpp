#include <bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	struct Node *left, *right;
};
Node* newNode(int data)
{
	Node* node = new struct Node;
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}
void zigZagTraversal(Node* root);
int main()
{
  int t;
  cin>>t;
  while (t--)
  {
     map<int, Node*> m;
     int n;
     cin>>n;
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     zigZagTraversal(root);
  }
  return 0;
}
// Contributed by: Hashit Sidhwa

/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
/*Structure of the node of the binary tree is as
struct Node {
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function 
// Function takes a single argument as input
// the root of the binary tree
// print a new line after each test case
void zigZagTraversal(Node* root)
{
	// Code here
	queue<Node*> q;
	stack<int> s;
	q.push(root);
	int flag=0;
	while(!q.empty())
	{
	    int size=q.size();
	    while(size--)
	    {
	        Node* temp=q.front();
	        q.pop();
	        if(flag==0)
	        {
	            cout<<temp->data<<" ";
	        }
	        else
	        {
	            s.push(temp->data);
	        }
	        if(temp->left)
	        {
	            q.push(temp->left);
	        }
	        if(temp->right)
	        {
	            q.push(temp->right);
	        }
	    }
	    while(!s.empty())
	    {
	        cout<<s.top()<<" ";
	        s.pop();
	    }
	    flag=!flag;
	}cout<<endl;
}
