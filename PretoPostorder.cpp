#include <bits/stdc++.h>
using namespace std;
struct Node 
{
    int data;
    Node * left;
    Node * right;
};
Node * createNode(int x)
{
    Node* root=new Node;
    root->data=x;
    root->left=NULL;
    root->right=NULL;
    return root;
}
Node * makeTree(vector< int > arr,int n)
{
    stack< Node * > st;
    Node * root=createNode(arr[0]);
    st.push(root);
    for(int i=1;i<n;i++)
    {
    struct Node * temp=NULL;
    while(!st.empty() && arr[i]>(st.top()->data))
    {
        temp=st.top();
        st.pop();
    }
    if(temp!=NULL)
    {
        temp->right=createNode(arr[i]);
        st.push(temp->right);
    }
    else
    {
        temp=st.top();
        temp->left=createNode(arr[i]);
        st.push(temp->left);
    }
    
}
return root;
}
void Inorder(vector< int > & inorder,Node* root)
{
    if(root==NULL)
    {
        return;
    }
    Inorder(inorder,root->left);
    inorder.push_back(root->data);
    //cout<<root->data<<" ";
    Inorder(inorder,root->right);
    
}
void Postorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector< int > arr(n);
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    Node * root=makeTree(arr,n);
	    vector< int > inorder;
	    Inorder(inorder,root);
	    
	    int flag=0;
	    for(int i=0;i<n-1;i++)
	    {
	        if(inorder[i]>inorder[i+1])
	        {
	            cout<<"NO";
	            flag=1;
	            break;
	        }
	    }
	    if(flag==0)
	    {
	        Postorder(root);
	    }
cout<<endl;
}

	return 0;
}
