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
/* Function to get the maximum width of a binary tree*/
int getMaxWidth(Node* root);
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d
", &t);
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
     cout << getMaxWidth(root) << endl;
  }
  return 0;
}

/*  Structure of a Binary Tree 
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
 //-----------------------------
map<int,int>mp;
int getMaxWidth(Node* root)
{
mp.clear();
if(!root) return 0;
pair<Node*,int>p;
queue<pair<Node*,int>>q;
q.push(make_pair(root,0));
while(!q.empty()){
p=q.front();
mp[p.second]++;
q.pop();
if(p.first->left){
q.push(make_pair(p.first->left,p.second+1));
}
if(p.first->right){
q.push(make_pair(p.first->right,p.second+1));
}
}
int val=1;
for(auto it=mp.begin();it!=mp.end();it++) val=max(val,it->second);
return val;
}
