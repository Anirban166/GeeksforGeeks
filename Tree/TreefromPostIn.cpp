#include<bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
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
/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node)
{
  if (node == NULL)
     return;
   /* then print the data of node */
  printf("%d ", node->data);
  /* first recur on left child */
  preOrder(node->left);
  /* now recur on right child */
  preOrder(node->right);
}
Node *buildTree(int in[], int post[], int n);
int main()
{
	int t,n;
	cin>>t;
	int in[1000], post[1000];
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>in[i];
		for(int i=0;i<n;i++)
			cin>>post[i];
        Node *root = buildTree(in, post, n);
        preOrder(root);
		cout<<endl;
	}
	return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
/* Tree node structure
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
// Function should construct tree and return
// root of it.  in[] stores inorder traversal
// post[] stores postorder traversal.  n is
// size of these arrays
Node *buildTreeUtil(int in[],int post[],int in_st,int in_end,int post_st,int post_end)
{
    if(in_end<in_st) return NULL;
    Node * root = new Node(post[post_end]);
    if(in_st == in_end) return root;
    
    int ind = -1;
    for(int i=in_st;i<=in_end;i++)
    {
        if(in[i]==root->data) 
        {
            ind = i;
            break;
        }
    }
    
    root->left = buildTreeUtil(in,post,in_st,ind-1,post_st,post_st+ind-in_st-1);
    root->right = buildTreeUtil(in,post,ind+1,in_end,post_st+ind-in_st,post_end-1);
    return root;
}
Node *buildTree(int in[], int post[], int n)
{
    return(buildTreeUtil(in,post,0,n-1,0,n-1));
}
