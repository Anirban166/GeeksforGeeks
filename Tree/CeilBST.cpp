//Ceil BST:
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
/* This function is used to insert 
new values in BST*/
Node* insert(Node* root, int key) 
{ 
	if (!root) 
		return new Node(key); 
	if (key < root->data) 
		root->left = insert(root->left, key); 
	else
		root->right = insert(root->right, key); 
	return root; 
} 
//Position this line where user code will be pasted.
int main() 
{ 
	
	int t;
	cin >> t;
	
	while(t--){
	    Node* root = NULL;
	    int n, x;
	    cin >> n;
	    int arr[n];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	        if(root == NULL) root = insert(root, arr[i]);
	        else insert(root, arr[i]);
	    }
	    cin >> x;
	    cout << findCeil(root, x) << endl;
	}
	
	return 0; 
}
}
/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
/*
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
// Function to find ceil of a given input in BST. If input is more 
// than the max key in BST, return -1 
Node *previ;

Node *search(Node *root, int x)
{
if(root==NULL) return previ;
if(root->data < x) return search(root->right, x);
else {
previ=root;
return search(root->left, x);
}
}

int findCeil(Node* root, int input)
{
// Base case
if (root == NULL)
return -1;

previ=NULL;
Node *temp = search(root, input);
if(temp==NULL) return -1;
else return previ->data;
// Your code here


}
