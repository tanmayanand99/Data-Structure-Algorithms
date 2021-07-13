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
node *intersection(node *head1,node *head2)
{
    node *p=head1,*q=NULL;
    int temp;
    node *root=NULL;
    while(p!=NULL)
    {
        temp=p->data;
        q=head2;
        while(q!=NULL)
        {
            if(temp==q->data)
            {
                insert(&root,temp);
            }
            q=q->next;
        }
        p=p->next;
    }
    return root;
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
void display(node *root)
{
    node *p=NULL;
    p=root;
    while(p!=NULL)
    {
        cout << p->data << " --> ";
        p=p->next;
    }
    cout << "NULL" << endl;
}
int main()
{
    char ans;
    int choice,n,n1,n2;
    node *head1=NULL,*head2=NULL,*root=NULL;

    do
    {
        cout << "\n\t\tMENU\n\t1.)Insert elements In two Linked List at end\n\t2.)Intersection of two Linked List\n\t3.)Display Linked List\n\t4.)Print Root List" << endl;
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
                    break;
            case 2:root = intersection(head1,head2);
                    break;
            case 3:display(head1,head2);
                    break;
            case 4:display(root);
                    break;
            default:cout << "WRONG CHOICE!!" << endl;
        }
        cout << "Do You Want To Continue??" << endl;
        cin >> ans;
    } while (ans=='Y' || ans=='y');
    
}