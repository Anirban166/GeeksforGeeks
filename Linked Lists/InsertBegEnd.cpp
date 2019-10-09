Node *insertAtBegining(Node *head, int newData) {
// Your code here
struct Node *temp=new Node(newData);

if(head==NULL)
{
head=temp;
return head;
}

else
{
temp->next=head;
head=temp;

return head;
}
}
// function appends the data at the end of the list
Node *insertAtEnd(Node *head, int newData) {
//Your code here
struct Node *temp=head;
struct Node *temp2=new Node(newData);

if(head==NULL)
{
head=temp2;
return head;
}
else
{
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=temp2;
return head;
}

}
