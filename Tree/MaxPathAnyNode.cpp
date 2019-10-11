// C/C++ program to find maximum path sum in Binary Tree
#include<bits/stdc++.h>
using namespace std;
// A binary tree node
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
int findMaxSum(Node*);
void insert(struct Node *root,int n1,int n2,char lr)
 {
     if(root==NULL)
        return;
     if(root->data==n1)
     {
         switch(lr)
         {
          case 'L': root->left=new Node(n2);
                    break;
          case 'R': root->right=new Node(n2);
                    break;
         }
     }
     else
     {
         insert(root->left,n1,n2,lr);
         insert(root->right,n1,n2,lr);
     }
 }
 
int main()
{
    /* Let us construct the tree shown in above diagram */
    int t,k;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    struct Node *root=NULL;
    while(n--)
    {
        char lr;
        int n1,n2;
        cin>>n1>>n2;
        cin>>lr;
        if(root==NULL)
        {
            root=new Node(n1);
            switch(lr){
                    case 'L': root->left=new Node(n2);
                    break;
                    case 'R': root->right=new Node(n2);
                    break;
                    }
        }
        else
        {
            insert(root,n1,n2,lr);
        }
    }
        cout<<findMaxSum(root)<<endl;
        
    }
    return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
// This function should returns sum of
// maximum sum path from any node in
// a tree rooted with given root.
int maxpathsum(Node *root, bool isanytaken)
{
    if(root==NULL && isanytaken==false)
        return INT_MIN;
    if(root==NULL)
        return 0;
    if(isanytaken==false)
    {
        int op1 = root->data + maxpathsum(root->left,true);
        int op2 = root->data + maxpathsum(root->right,true);
        int op3 = root->data + maxpathsum(root->left,true) + maxpathsum(root->right,true);
        int op4 = max(maxpathsum(root->left,isanytaken),maxpathsum(root->right,isanytaken));        
        return max(op1,max(op2,max(op3,op4)));
    }
    int op1 = root->data + maxpathsum(root->left,true);
    int op2 = root->data + maxpathsum(root->right,true);
    int op3 = 0;
    return max(op1,max(op2,op3));
}
int findMaxSum(Node* root)
{
    // Your code goes here
    return maxpathsum(root,false);
}
