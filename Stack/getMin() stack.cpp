#include<iostream>
using namespace std;
typedef struct nodes
{
    int data;
    struct nodes *next; 
}node;
void display(node *head)
{
    if(head==NULL)
    {
        cout << "No element to display" << endl;
    }
    else
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
}
node *push(node *head)
{
    int n,minele;
    node *right=NULL,*p=NULL,*temp=NULL,*q=NULL;
    cout << "Enter the element you want to enter in the stack" << endl;
    cin >> n;
    p=(node *)malloc(sizeof(node));
    q=(node *)malloc(sizeof(node));
    p->data=n;
    if(head==NULL)
    {
        right=head=p;
        right->next=NULL;
        minele = p->data;
        temp=q;
        q->data=minele;
        q->next=NULL;
    }
    else
    {
        p->next=head;
        head=p;
        if(minele>=head->data)
        {
            minele=head->data;
            q->data=minele;
            temp=q;
        }
    }
    display(temp);
    return head;
}
node *pop(node *head)
{
    if(head==NULL)
    {
        cout << "Underflow" << endl;
    }
    else
    {
        head=head->next;
        cout << "Popping has been done" << endl;
    }
    return head;
}
void peek(node *head)
{
    if(head==NULL)
    {
        cout << "Empty Stack" << endl;
    }
    else
    {
        cout << "Peeked element is " << head->data << endl;
    }
}
int main()
{
    node *head=NULL;
    head=push(head);
    head=push(head);
    head=push(head);
    head=push(head);
    head=push(head);
    display(head);
}