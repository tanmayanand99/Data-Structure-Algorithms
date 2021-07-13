#include<iostream>
using namespace std;
typedef struct nodes
{
    int data;
    struct nodes *next;
}node;
int main()
{
    node *head=NULL,*p=NULL,*end=NULL,*t=NULL;
    int data,c=0,n;
    cout << "Enter No of elements you want to enter in Linked List" << endl;
    cin >> n;

    while(c!=n)
    {
        cout << "Enter the element you want to enter in lnked list" << endl;
        cin >> data;
        p=(node *)malloc(sizeof(node));
        p->data=data;
        if(head==NULL)
        {
            head=end=p;
        }
        else
        {
            end->next=p;
            end=p;
        }
        p->next=NULL;
        c++;
    }
    end->next=head;
    p=t=head;
    while(t!=NULL && t->next!=NULL)
    {
        t=t->next->next;
        p=p->next;
        if(t==p)
        {
            cout << "Cycle Exists" << endl;
            break;
        }
    }
}