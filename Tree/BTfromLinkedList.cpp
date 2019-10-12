#include <bits/stdc++.h>
using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
void push(struct Node **head_ref, int new_data) {
    struct Node *new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void convert(Node *head, TreeNode *&root);
void lvl(TreeNode *r) {
    if (r == NULL) return;
    queue<TreeNode *> q;
    q.push(r);
    while (!q.empty()) {
        TreeNode *j = q.front();
        cout << j->data << " ";
        q.pop();
        if (j->left) q.push(j->left);
        if (j->right) q.push(j->right);
    }
}
void reverses(Node **head) {
    Node *prev = NULL;
    Node *cur = *head;
    Node *nxt;
    while (cur != NULL) {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *head = prev;
}
/* Driver program to test above function*/
int main() {
    int T, i, n, l, k;
    cin >> T;
    while (T--) {
        struct Node *head = NULL;
        cin >> n;
        for (i = 1; i <= n; i++) {
            cin >> l;
            push(&head, l);
        }
        reverses(&head);
        TreeNode *root = NULL;
        convert(head, root);
        if (root == NULL) cout << "-1
";
        lvl(root);
        cout << endl;
        // inorder(root);
        getchar();
    }
    return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
/*
The structure of Link list Node is as follows
struct Node
{
    int data;
    struct node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};
The structure of TreeNode is as follows
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};
*/
void convert(Node *head, TreeNode *&root) {
   TreeNode *newnode=new TreeNode(head->data);
  
   root=newnode;
   queue<TreeNode*>q;
   q.push(root);
   Node *temp=head->next;
    TreeNode *new1;
     TreeNode *new2;
   while(temp!=NULL)
   {  
     new1=new  TreeNode(temp->data);
     TreeNode *t=q.front();
        q.pop();
        t->left=new1;
        q.push(t->left);
       temp=temp->next;
       if(temp!=NULL)
     { new2=new  TreeNode(temp->data);
  t->right=new2;
        q.push(t->right);}
       
       
        if(temp!=NULL)
        temp=temp->next;
       
   }
    // Your code here
}
