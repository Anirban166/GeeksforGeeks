//Inorder:
void inOrder(Node *root)
{
if(root==NULL)
return;
inOrder(root->left);
cout<<root->data<<" ";
inOrder(root->right);
}

//Level Order:
void levelOrder(Node *root)
{
if(root==NULL)
return;
queue<Node*> q;
q.push(root);
while(!q.empty())
{
Node* temp=q.front();
cout<<temp->data<<" ";
q.pop();
if(temp->left!=NULL)
q.push(temp->left);
if(temp->right!=NULL)
q.push(temp->right);
}
//Your code here
//Level order traversal is traversing level by level, left to right
}
