#include<bits/stdc++.h> 
using namespace std; 
class Node 
{ 
public: 
	int data; 
	Node* left, *right; 
	Node(int data) 
	{ 
		this->data = data; 
		left = NULL; 
		right = NULL; 
	} 
};
int getMaxSum(Node* root);
//Position this line where user code will be pasted.
// Driver code 
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2] = child;
     }
     cout<<getMaxSum(root)<<endl;
  }
  return 0;
}
}
/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
//Node Structure
/*struct Node
{
	int key;
	Node *left, *right;
};*/
//This function returns the maximum sum of non-adjacent nodes.
int getMaxSum(Node *root)
{
// Add your code here
if(root == NULL) return 0;
int include = root->data;
if(root->left != NULL)
include += getMaxSum(root->left->left)+getMaxSum(root->left->right);
if(root->right != NULL)
include += getMaxSum(root->right->left)+getMaxSum(root->right->right);
int exclude = getMaxSum(root->left)+getMaxSum(root->right);
return max(include,exclude);
}
