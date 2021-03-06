#include<bits/stdc++.h>
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
void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        *tree = new Node(val);
        return;
    }
    if(val < (*tree)->data)
    { insert(&(*tree)->left, val);}
    else if(val > (*tree)->data)
    { insert(&(*tree)->right, val);}
}
void inorder(Node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
Node * deleteNode(Node *root,  int );
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
        root = NULL;
        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);}
        int r;
        cin>>r;
        root = deleteNode(root,r);
        inorder(root);
        cout<<endl;
    }
}
}
/*This is a function problem.You only need to complete the function given below*/

/* The structure of a BST Node is as follows:
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
Node* sucessor(Node* root)
{
    if(root==NULL)
        return NULL;
    while(root->left!=NULL)
        root=root->left;
    return root;    
}
Node * deleteNode(Node *root,  int x)
{
    if(root==NULL)
        return root;
    if(root->data>x)
        root->left= deleteNode(root->left,x);
    else if(root->data<x)
        root->right=deleteNode(root->right,x);
    else
    {
       
        if(root->right==NULL)
        {
              Node* temp=root->left;
            free(root);
            return temp;
        }
        if(root->left==NULL)
        {
              Node* temp=root->right;
            free(root);
            return temp;
        }
          Node* suc=sucessor(root->right);
          root->data=suc->data;
          root->right=deleteNode(root->right,suc->data);
         
    }
    return root;
  // your code goes here   
}
