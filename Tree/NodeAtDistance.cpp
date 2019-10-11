#include<bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 10000
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
int printKDistantfromLeaf(Node* node, int k);
 void insert(struct Node *root,int n1,int n2,char lr)
 {
     if(root==NULL)
        return;
     if(root->key==n1)
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
    cin>>k;
    cout<<printKDistantfromLeaf(root, k)<<endl;
    }
    return 0;
}
}
/*This is a function problem.You only need to complete the function given below*/
//Node Structure
/*struct Node
{
	int key;
	Node *left, *right;
};*/
//This function returns the count of the total distinct nodes that are at a 
//distance k from leaf nodes.
bool funcount(Node*root,int k)
{
if(root==NULL)
return false;
if(!root->left&&!root->right&&!k)
{
return true;
}
return funcount(root->left,k-1)||funcount(root->right,k-1);
}
int printKDistantfromLeaf(Node* root, int k)
{
int count=0;
if(root==NULL)
return 0;
if(funcount(root,k))
return 1+printKDistantfromLeaf(root->left,k)+printKDistantfromLeaf(root->right,k);
else
return printKDistantfromLeaf(root->left,k)+printKDistantfromLeaf(root->right,k);

}
