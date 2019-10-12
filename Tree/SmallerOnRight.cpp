#include<iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    int lg;
    Node* left;Node* right;
    Node(int x)
    {
        data=x;
        left=NULL;right=NULL;
        lg=0;
    }
};
void inorder(Node* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout << root->data <<" "<<root->lg<<"\n";
    inorder(root->right);
}

bool insert(Node* root,int val,int *ct)
{
    
    if(root->data>val)
    {
        root->lg=root->lg+1;
        if(!root->left)
        {
            Node* newnode=new Node(val);
            root->left=newnode;
            return 1;
        }
        else
        {
        if(!insert(root->left,val,ct))
        {
            root->lg=root->lg-1;
            return 0;
        }
        else
            return 1;
        }
    }
    else if(root->data<val)
    {
        (*ct)+=root->lg+1;
        if(!root->right)
        {
            Node* newnode=new Node(val);
            root->right=newnode;
            return 1;
        }
        else
        {
        if(!insert(root->right,val,ct))
           { return 0;}
         else
            return 1;
        }
    }
    else
    {
        (*ct)=(*ct)+root->lg;
        return 0;
    }
}
int main()
 {
	int test;
	cin >> test;
	while(test--)
	{
	    int n;
	    cin >> n;
	    
	    int *a=new int[n];
	    
	    for(int i=0;i<n;i++)
	        cin >> a[i];
	   Node* root=new Node(a[n-1]);
	   int max=0;
	   for(int i=n-2;i>=0;i--)
	   {
	       int c=0;
	       int *ct=&c;
	       insert(root,a[i],ct);
	       if((*ct)>max)
	        max=*ct;
	   }
	   //inorder(root);
	   cout << max<<"\n";
	}
	return 0;
}
