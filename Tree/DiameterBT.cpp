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
/* Function to get diameter of a binary tree */
int diameter(struct Node * tree);
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
     cout << diameter(root) << endl;
  }
  return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
/* Tree node structure  used in the program
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
int height(Node *node)
{
if(node==NULL)
return 0;
else
return max(height(node->left)+1,height(node->right)+1);
}

int diameter(Node* node)
{
//base
if(node==NULL) return 0;

//recursion
//passing through root
int l_h = height(node->left);
int r_h = height(node->right);
int t_h = l_h+r_h+1;

//not passing through root
int l_d = diameter(node->left);
int r_d = diameter(node->right);
int max_val = max(l_d,r_d);

int res = max(t_h,max_val);

return res;
}
