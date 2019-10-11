//Recursive:
void inOrder(Node* root)
{
    if(root == NULL)
        return;
        
    inOrder(root->left);
    
    cout << root->data << " ";
    
    inOrder(root->right);
}

//Non-Recursive:
void inOrder(Node* root)
{
    stack<Node*> s;
    auto curr = root;
    
    while(!s.empty() || curr)
    {
      if(curr)  
      {
          s.push(curr);
          
          // Going left.
          curr = curr->left;
      }
      else
      {
          // Going up
          curr = s.top();
          s.pop();
          
          cout << curr->data << " ";
          
          // Going right
          curr = curr->right;
      }
    }
}

