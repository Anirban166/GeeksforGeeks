#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
void preorderTraversal(Node* root)
{
	if (!root)return;
	cout << root->data << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right); 
}
Node* constructBst(int arr[], int n);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
        Node *root = constructBst(arr, n);
        preorderTraversal(root);
        cout<<endl;
    }
	return 0; 
}
}
/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
/*
Structure of the Node of the node of the bst 
should be as
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/
// You are required to complete this function
void con(Node* root,int *a,int n,int i)
{   Node* head=root;
   Node* curr=head;
    while(1)
    {
        if(i==n)
        break;
    if(root==NULL)
    {
        if(a[i]<curr->data)
        {
            Node* temp=new Node(a[i]);
            curr->left=temp;
            i++;
    
        }
        else
        {
            Node* temp=new Node(a[i]);
            curr->right=temp;
            i++;
        
        }
        root=head;
    }
    else{
    if(a[i]<root->data)
    {
        curr=root;
    root=root->left;
    }
    else
    {
        curr=root;
    root=root->right;
    }
    }

    }
}
Node* constructBst(int arr[], int n)
{
    int i=1;
    Node* root=new Node(arr[0]);
    Node* curr=root;
    con(root,arr,n,i);
    return curr;
	
}
