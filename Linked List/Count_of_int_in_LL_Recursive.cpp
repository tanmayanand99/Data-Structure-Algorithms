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
    node *p=(node *)malloc(sizeof(node));
    cout << "Enter Number You want to enter in the linked list" << endl;
    cin >> n;
    p->data=n;
    if(head==NULL)
    {
        head=p;
        head->next=NULL;
    }
    else
    {
        p->next=head;
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
    }
    else
    {
        if(pos<=1)
        {
            p->next=head;
            head=p;
        }
        else
        {
            while(c!=pos-1)
            {
                temp=temp->next;
                c++;
                if(temp->next==NULL)
                {
                    temp->next=p;
                    p->next=NULL;
                }
            }
            k=temp->next;
            temp->next=p;
            p->next=k;
        }
    }
    return head;
}
int count(node *p,int n)
{
    if(p==NULL)
    {
        return 0;
    }
    else
    {
        if(p->data==n)
        {
            return 1+count(p->next,n);
        }
        else
        {
            return 0+count(p->next,n);
        }
    }
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
    char ans;
    node *p=NULL;
    int choice,n;
    node *head=NULL;

    do
    {
        cout << "\n\t\tMENU\n\t1.)Insert In Linked List at Beginning\n\t2.)Insert In Linked List at end\n\t3.)Insert In Linked List At A Position\n\t4.)Count the frequency of element in Linked List\n\t5.)Display Linked List" << endl;
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
            case 4: cout << "Enter the element of which you want to count the frequency" << endl;
                    cin >> n;
                    p=head;
                    cout << "Frequency of " << n << " is " << count(p,n) << endl;
                    break;
            case 5:display(head);
                    break;
            default:cout << "WRONG CHOICE!!" << endl;
        }
        cout << "Do You Want To Continue??" << endl;
        cin >> ans;
    } while (ans=='Y' || ans=='y');
    
}