#include<iostream>
#include<vector>
using namespace std;
typedef struct nodes
{
    char data;
    struct nodes *next;
}node;
node *insertbeg(node *head)
{
    char n;
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
    char n;
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
    char n;
    int pos,c=1;
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
void palin(node *head)
{
    vector<int> a,ar;
    node *p=head;
    while(p!=NULL)
    {
        a.push_back(p->data);
    }
    node *temp=NULL,*nex=NULL;
    p=head;
    
    
}

int main()
{
    char ans;
    int choice,answer;
    node *head=NULL;

    do
    {
        cout << "\n\t\tMENU\n\t1.)Insert In Linked List at Beginning\n\t2.)Insert In Linked List at end\n\t3.)Insert In Linked List At A Position\n\t4.)Check Palindrome or not\n\t5.)Display Linked List" << endl;
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
            case 4:palin(head);
                    break;
            case 5:display(head);
                    break;
            default:cout << "WRONG CHOICE!!" << endl;
        }
        cout << "Do You Want To Continue??" << endl;
        cin >> ans;
    } while (ans=='Y' || ans=='y');
    
}