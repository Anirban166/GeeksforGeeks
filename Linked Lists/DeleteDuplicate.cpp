Node *removeDuplicates(Node *start)
{
Node *curr = start, *temp = NULL;
while(curr != NULL)
{
temp = curr;
while(temp->next != NULL)
{
if(temp->next->data == curr->data)
temp->next = temp->next->next;
else
temp = temp->next;
}
curr = curr->next;
}
return start;
}
