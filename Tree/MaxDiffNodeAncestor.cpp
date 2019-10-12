#include <bits/stdc++.h>
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
int maxDiff(Node *root);
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
   
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
    cout<<maxDiff(root)<<endl;
 }
  return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node
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
 */
//---------------------------
int Traverse(Node *root, int &maxm){
  if(root == nullptr)
    return INT_MAX;
  int mini = min(Traverse(root->left, maxm), Traverse(root->right, maxm));
  maxm = max(maxm, root->data-mini);
  mini = min(mini, root->data);
  return mini;
}

int maxDiff(Node* root){
  int maxm = INT_MIN;
  Traverse(root, maxm);
  return maxm;
}
