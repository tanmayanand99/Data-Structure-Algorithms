#include<iostream>
using namespace std;
typedef struct nodes
{
    int data;
    struct nodes *next;
}node;
node *insertnode(node *temp)
{
    node *head=NULL;
    int data;
    node *p=(node *)malloc(sizeof(node));
    cin >> data;
    p->data=data;
    if(temp==NULL)
    {
        head=temp=p;
    }
    else
    {
        temp->next=p;
    }
    p->next=NULL;
    return head;
}
void display(node *head)
{
    node *p=NULL;
    p=head;
    while(p!=NULL)
    {
        cout << p->data << " --> ";
        p=p->next;
    }
    cout << "NULL" << endl;
}
int main()
{
    node *head=NULL;
    head=insertnode(head);
    head=insertnode(head);
    head=insertnode(head);
    head=insertnode(head);
    display(head);
}