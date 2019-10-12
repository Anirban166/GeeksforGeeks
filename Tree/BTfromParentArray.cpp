#include <bits/stdc++.h>
using namespace std;
vector<int> result;
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
void printGivenLevel(Node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        result.push_back(root->data);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}
int height(struct Node* node)
{
    if (node==NULL)
        return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}
void printLevelOrder(struct Node* root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++){
        result.clear();
        printGivenLevel(root, i);
        sort(result.begin(),result.end());
        for(int i=0;i<result.size();i++)
            cout<<result[i]<<" ";
    }
}
Node *createTree(int parent[], int n);
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,k;
/*reading input*/
    cin>>T;
    while(T--){
    int N;
    cin>>N;
    int a[N];
    for(int i=0;i<N;i++)
        cin>>a[i];
        struct Node *res = createTree(a,N);
       printLevelOrder(res);
     cout<<endl;
    }
    return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
/* node structure  used in the program
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */
/*  Function which returns the  root of 
    the constructed binary tree. */
Node *crate(int arr[], int n,int p)
{
  int index=-1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==p) {index=i;break;}
    } 
    if(index==-1) return NULL;
    arr[index]=-2;
    
struct Node* root=new Node(index);
root->left=crate( arr,  n,index);
root->right=crate( arr,  n,index);
    return root;  
}
Node *createTree(int arr[], int n)
{
   return crate(arr,n,-1);
}
