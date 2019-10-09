Node* addTwoLists(Node* l1, Node* l2)
{
if (l1 == NULL) return l2;
if (l2 == NULL) return l1;
int a = l1->data + l2->data;
Node *p = new Node(a % 10);
p->next = addTwoLists(l1->next,l2->next);
if (a >= 10) p->next = addTwoLists(p->next, new Node(1));
return p;
}
