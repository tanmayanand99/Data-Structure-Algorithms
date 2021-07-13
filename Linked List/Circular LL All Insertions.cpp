#include<iostream>
using namespace std;
typedef struct nodes
{
    int data;
    struct nodes *next;
}node;
node *insertbeg(node *head)
{
    int n;
    node *temp=NULL;
    node *p=(node *)malloc(sizeof(node));
    cout << "Enter Number You want to enter in the linked list" << endl;
    cin >> n;
    p->data=n;
    if(head==NULL)
    {
        head=p;
        p->next=head;
    }
    else
    {
        temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        p->next=head;
        temp->next=p;
        head=p;
    }
    return head;
}
node *insertend(node *head)
{
    int n;
    node *end=head;
    node *p=(node *)malloc(sizeof(node));
    cout << "Enter Number You want to enter in the linked list" << endl;
    cin >> n;
    p->data=n;
    if(head==NULL)
    {
        head=p;
        p->next=head;
    }
    else
    {
        while(end->next!=head)
        {
            end=end->next;
        }
        end->next=p;
        p->next=head;
    }
    return head;
}
node *insertpos(node *head)
{
    int n,pos,c=1;
    node *temp=head,*k=NULL,*end=head;
    node *p=(node *)malloc(sizeof(node));
    cout << "Enter Number You want to enter in the linked list" << endl;
    cin >> n;
    cout << "Enter position where you want to enter the element" << endl;
    cin >> pos;
    p->data=n;
    if(head==NULL)
    {
        cout <<"No element was present so inserted at first position" << endl;
        head=p;
        p->next=head;
    }
    else
    {
        while(end->next!=head)
        {
            end=end->next;
        }
        
        if(pos<=1)
        {
            p->next=head;
            end->next=p;
        }
        else
        {
            while(c!=pos-1)
            {
                temp=temp->next;
                c++;
            }
            k=temp->next;
            temp->next=p;
            p->next=k;
        }
    }
    return head;
}
void display(node *head)
{
    node *p=NULL;
    p=head;
    do
    {
        cout << p->data << " --> ";
        p=p->next;
    }
    while(p!=head);
    cout << "NULL" << endl;
}
int main()
{
    char ans;
    int choice;
    node *head=NULL;

    do
    {
        cout << "\n\t\tMENU\n\t1.)Insert In Linked List at Beginning\n\t2.)Insert In Linked List at end\n\t3.)Insert In Linked List At A Position\n\t4.)Display Linked List" << endl;
        cout << "Enter your choice" << endl;
        cin >> choice;
        switch(choice)
        {
            case 1:head = insertbeg(head);
                    break;
            case 2:head = insertend(head);
                    break;
            case 3:head = insertpos(head);
                    break;
            case 4:display(head);
                    break;
            default:cout << "WRONG CHOICE!!" << endl;
        }
        cout << "Do You Want To Continue??" << endl;
        cin >> ans;
    } while (ans=='Y' || ans=='y');
    
}