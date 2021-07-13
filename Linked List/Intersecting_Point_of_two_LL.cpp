#include<iostream>
using namespace std;
typedef struct nodes
{
    int data;
    struct nodes *next;
}node;
void insertend(node **head)
{
    int n;
    node *end=*head;
    node *p=(node *)malloc(sizeof(node));
    cout << "Enter Number You want to enter in the linked list" << endl;
    cin >> n;
    p->data=n;
    if(*head==NULL)
    {
        *head=p;
    }
    else
    {
        while(end->next!=NULL)
        {
            end=end->next;
        }
        end->next=p;
    }
    p->next=NULL;
}
void insert(node **head,int n)
{
    node *end=*head;
    node *p=(node *)malloc(sizeof(node));
    p->data=n;
    if(*head==NULL)
    {
        *head=p;
    }
    else
    {
        while(end->next!=NULL)
        {
            end=end->next;
        }
        end->next=p;
    }
    p->next=NULL;
}
void merge(node **head1,node **head2,node **head3)
{
    node *p=*head1,*q=*head2;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    while(q->next!=NULL)
    {
        q=q->next;
    }
    node *k=*head3;
    p->next=k;
    q->next=k;
}
void display(node *head1,node *head2)
{
    node *p=head1;
    cout << "First Linked List is :" << endl;
    while(p!=NULL)
    {
        cout << p->data << " --> ";
        p=p->next;
    }
    cout << "NULL" << endl;
    cout << "Second Linked List is :" << endl;
    p=head2;
    while(p!=NULL)
    {
        cout << p->data << " --> ";
        p=p->next;
    }
    cout << "NULL" << endl;
}
void mergingpointfind(node *head1,node *head2)
{
    node *p=head1,*t=NULL;
    while(p!=NULL)
    {
        t=head2;
        while(t!=NULL)
        {
            if(t==p)
            {
                cout << "Merge Point is : " << t << " and data is : " << t->data << endl;
            }
            t=t->next;
        }
        p=p->next;
    }
}
int main()
{
    char ans;
    int choice,n,n1,n2,n3;
    node *head1=NULL,*head2=NULL,*root=NULL,*head3=NULL;

    do
    {
        cout << "\n\t\tMENU\n\t1.)Insert elements In two Linked List at end\n\t2.)Merge First two Linked list with third\n\t3.)Display Both Linked List\n\t4.)Find Merging Point of the Linked List" << endl;
        cout << "Enter your choice" << endl;
        cin >> choice;
        switch(choice)
        {
            case 1: cout << "Enter the number of elements you want to enter in first linked list" << endl;
                    cin >> n1;
                    cout << "Enter the elements of first linked list" << endl;
                    while(n1--)
                    {
                        insertend(&head1);
                    }
                    cout << "Enter the number of elements you want to enter in second linked list" << endl;
                    cin >> n2;
                    cout << "Enter the elements of second linked list" << endl;
                    while(n2--)
                    {
                        insertend(&head2);
                    }
                    cout << "Enter the number of elements you want to enter in merged linked list" << endl;
                    cin >> n3;
                    cout << "Enter the elements of merged linked list" << endl;
                    while(n3--)
                    {
                        insertend(&head3);
                    }
                    break;
            case 2:merge(&head1,&head2,&head3);
                    break;
            case 3:display(head1,head2);
                    break;
            case 4:mergingpointfind(head1,head2);
                    break;
            default:cout << "WRONG CHOICE!!" << endl;
        }
        cout << "Do You Want To Continue??" << endl;
        cin >> ans;
    } while (ans=='Y' || ans=='y');
    
}