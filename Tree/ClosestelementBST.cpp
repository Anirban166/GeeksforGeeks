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
int maxDiff(Node* , int );
void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        *tree = new Node(val);
        return;
    }
    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }
}
int getCountOfNode(Node *root, int l, int h)
{
    if (!root) return 0;
    if (root->data == h && root->data == l)
        return 1;
    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);
    else if (root->data < l)
         return getCountOfNode(root->right, l, h);
    else return getCountOfNode(root->left, l, h);
}
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
            insert(&root, k);
        }
        int s;
        cin>>s;
     cout<<maxDiff(root,s);
     cout<<endl;
    }
}

}
/*This is a function problem.You only need to complete the function given below*/
/*The Node structure is
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
/*You are required to complete below method */
int maxDiff(Node *root, int k)
{
int t= abs(k - root->data);
if( root->data <= k && root->right!=NULL ){
t= min( t , maxDiff(root->right , k ) );
}
else if( root->left !=NULL ) {
t= min( t , maxDiff(root->left , k ) );
}
return t;
}
