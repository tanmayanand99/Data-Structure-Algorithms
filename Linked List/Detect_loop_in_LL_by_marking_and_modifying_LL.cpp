#include<iostream>
using namespace std;
typedef struct nodes
{
    int data;
    struct nodes *next;
    int flag;
}node;
int main()
{
    node *head=NULL,*p=NULL,*end=NULL;
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
    p=head;
    while(p!=NULL)
    {
        if(p->flag==1)
        {
            cout << "Loop is present in the linked list" << endl;
            break;
        }
        else
        {
            p->flag=1;
            p=p->next;
        }
    }
}