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
// A utility function to do inorder traversal
void inorder(struct Node *root)
{
	if (root)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
/* A utility function to insert a new Node with given key in BST */
struct Node* insert(struct Node* node, int key)
{
	/* If the tree is empty, return a new Node */
	if (node == NULL) return new Node(key);
	/* Otherwise, recur down the tree */
	if (key < node->data)
		node->left = insert(node->left, key);
	else if (key > node->data)
		node->right = insert(node->right, key);
	/* return the (unchanged) Node pointer */
	return node;
}
void printCommon(Node *root1, Node *root2);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n1,n2,tmp;
	 cin>>n1;
	 Node *root1 = NULL;
	 for(int i=0; i<n1; i++){
	     cin>>tmp;
	     root1 = insert(root1, tmp);
	 }
	 Node *root2 = NULL;
	 cin>>n2;
	 for(int i=0; i<n2; i++)
	 {
	     cin>>tmp;
	     root2 = insert(root2, tmp);
	 }
	 printCommon(root1, root2);
	 cout << endl;
    }
	return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
/*Node structure
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
/* Function should print common elements in given two trees */
void printCommon(Node *root1, Node *root2)
{
     //Your code here
     stack<Node *> s1, s2;
     Node *curr1=root1, *curr2=root2;
     
     while((curr1!=NULL || !s1.empty()) && (curr2!=NULL || !s2.empty()))
     {
         while(curr1)
         {
             s1.push(curr1);
             curr1 = curr1->left;
         }
         while(curr2) {
             s2.push(curr2);
             curr2 = curr2->left;
         }
         curr1 = s1.top(); 
         curr2 = s2.top();
         if(curr1->data == curr2->data) {
             cout<<curr1->data<<" ";
             s1.pop(); s2.pop();
             curr1 = curr1->right;
             curr2 = curr2->right;
         } else if(curr1->data > curr2->data) {
             curr2 = curr2->right;
             s2.pop();
             curr1 = NULL;
         } else {
             curr1 = curr1->right;
             s1.pop();
             curr2 = NULL;
         }
     }
}
