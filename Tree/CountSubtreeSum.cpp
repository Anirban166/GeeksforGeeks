#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
// Your are required to complete this function
int countSubtreesWithSumX(Node* root, int x);
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
        cin>>n1>>n2>>lr;
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)root = parent;
        }
        else parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')parent->left = child;
        else parent->right = child;
        m[n2]  = child;
     }
     int x;
     cin>>x;
     cout << countSubtreesWithSumX(root, x)<<endl;
  }
  return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
// your are required to complete this function
// function should return the count of the number of 
// subtrees with Sum equal to X
int value(Node* root,int x,int &count)
{
if(root==NULL)
return 0;
int s1=value(root->left,x,count);
int s2=value(root->right,x,count);
if(s1+s2+root->data==x)
count++;

}
int countSubtreesWithSumX(Node* root, int x)
{
if(root==NULL)
return 0;
int count=0;
value(root,x,count);
return count;
}
