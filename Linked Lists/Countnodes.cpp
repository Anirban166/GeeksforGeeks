
int getCount(struct Node* head)
{

if(head == NULL)
return 0;

return 1 + getCount(head->next);
}
