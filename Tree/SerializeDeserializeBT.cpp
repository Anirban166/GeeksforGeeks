#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};
void serialize(Node *root,vector<int> &);
Node * deSerialize(vector<int> &);
/* Computes the number of nodes in a tree. */
int height(struct Node* node)
{
  if (node==NULL)
    return 0;
  else
    return 1 + max(height(node->left), height(node->right));
}
void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d
", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     int N = n;
     struct Node *root = NULL;
     struct Node *child;
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
        m[n2]  = child;
     }
    vector<int> A;
    A.clear();
    serialize(root,A);
  //  for(int i=0;i<A.size();i++)
    //    cout<<A[i]<<" ";
      //  cout<<endl;
    // inorder(root);
     //cout<<endl;
    Node *tree_made = deSerialize(A);
    inorder(tree_made);
    cout<<endl;
  }
  return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
//-------------------
void serialize(Node *root,vector<int> &A)
{
    //Your code here
    if(root==NULL){
        A.push_back(-1);
        return;
    }
    A.push_back(root->data);
    serialize(root->left,A);
    serialize(root->right,A);
}
/*this function deserializes
 the serialized vector A*/


int pre_index = 0;
Node * deSerialize(vector<int> &Arr)
{
    if (pre_index == Arr.size() || Arr[pre_index] == -1) {
        pre_index += 1;
        pre_index %= Arr.size();
        return NULL; 
    } 
    Node *root = new Node(Arr[pre_index]); 
    pre_index += 1;
    pre_index %= Arr.size();
    root->left = deSerialize(Arr); 
    root->right = deSerialize(Arr); 
    return root;
}
