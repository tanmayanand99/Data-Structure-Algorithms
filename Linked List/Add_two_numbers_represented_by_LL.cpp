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
void insertbeg(node **head,int n)
{
    node *p=(node *)malloc(sizeof(node));
    p->data=n;
    if(*head==NULL)
    {
        *head=p;
        p->next=NULL;
    }
    else
    {
        p->next=*head;
        *head=p;
    }
}
node* rev(node* head)
{
    node *temp=NULL,*nex=NULL,*p=NULL;
    p=head;
    while(p!=NULL)
    {
        nex=p->next;
        p->next=temp;
        temp=p;
        p=nex;
    }
    head=temp;
    cout << endl;
    while(p)
    {
        cout << p->data << " ";
        p=p->next;
    }
    return temp;
}
node* insert(int val,node* head)
{
    node *p=(node *)malloc(sizeof(node));
    node* end=NULL;
    if(head==NULL)
    {
        head=end=p;
    }
    else
    {
        end->next=p;
        end=p;
    }
    return head;
}
    //Function to add two numbers represented by linked list.
node* addTwoLists(node* first, node* second)
{
    int num;
    node* head = NULL;
    int carry=0;
    first = rev(first);
    second = rev(second);
    while(first && second)
    {
        num=carry+first->data+second->data;
        if(num>9)
        {
            carry=1;
            num=num%10;
            head = insert(num,head);
        }
        else
        {
            carry=0;
            head = insert(num,head);
        }
        first=first->next;
        second=second->next;
    }
    if(first)
    {
        while(first)
        {
            num=carry+first->data;
            head=insert(num,head);
            carry=0;
            first=first->next;
        }
    }
    else if(second)
    {
        while(second)
        {
            num=carry+second->data;
            head=insert(num,head);
            carry=0;
            second=second->next;
        }
    }
        
    while(head)
    {
        cout << head->data << " ";
    }
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
    node *head1=NULL,*head2=NULL;

    do
    {
        cout << "\n\t\tMENU\n\t1.)Insert elements In two Linked List at end\n\t2.)Add Two Numbers Represented By two Linked List\n\t3.)Display Both Linked List" << endl;
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
            case 2:addTwoLists(head1,head2);
                    break;
            case 3:display(head1,head2);
                    break;
            default:cout << "WRONG CHOICE!!" << endl;
        }
        cout << "Do You Want To Continue??" << endl;
        cin >> ans;
    } while (ans=='Y' || ans=='y');
    
}