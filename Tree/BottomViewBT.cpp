#include<bits/stdc++.h>
using namespace std;
// Tree node class
struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references
    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
};
// Method that prints the bottom view.
void bottomView(Node *root);
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
     scanf("%d
",&n);
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
     bottomView(root);
     cout << endl;
  }
  return 0;
}


/* Tree node class
struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references
    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
}; */
//--------------------------
void bottomView(Node *root)
{
    map<int,int>mp;
   	queue<pair<Node *,int > >q;
	int d=0;
	if(root==NULL)
	return ;
	q.push(make_pair(root,d));
	while(!q.empty())
	{
		pair<Node *,int> p = q.front();
		q.pop();
		struct Node *cur = p.first;
		int val = p.second;
		mp[val] = cur->data;
		if(cur->left!=NULL)
		{
			q.push(make_pair(cur->left,val-1));
		}
		if(cur->right !=NULL)
		{
			q.push(make_pair(cur->right,val+1));
		}
	}
		map<int ,int >::iterator it;
	for(it=mp.begin();it!=mp.end();it++)
	{
		cout<<it->second<<" ";
	}
}
 
