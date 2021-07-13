#include<iostream>
using namespace std;
typedef struct nodes
{
    int data;
    struct nodes *prev;
    struct nodes *next;
}node;
node *insertbegin(node *head)
{
    int n;
    node *p=(node *)malloc(sizeof(node));
    cout << "Enter element that you want to enter" << endl;
    cin >> n;
    p->data=n;
    if(head==NULL)
    {
        head=p;
        head->prev=NULL;
        head->next=NULL;
    }
    else
    {
        p->next=head;
        head->prev=p;
        p->prev=NULL;
        head=p;
    }
    return head;
}
node *insertend(node *head)
{
    int n;
    node *end=NULL;
    end=head;
    node *p=(node *)malloc(sizeof(node));
    cout << "Enter element that you want to enter" << endl;
    cin >> n;
    p->data=n;
    if(head==NULL)
    {
        head=end=p;
        head->prev=NULL;
        head->next=NULL;
    }
    else
    {
        while(end->next!=NULL)
        {
            end=end->next;
        }
        end->next=p;
        p->next=NULL;
        p->prev=end;
        end=p;
    }
    return head;
}
node *insertpos(node *head)
{
    node *k=NULL,*p=NULL;
    k=head;
    p=head;
    int n,pos;
    cout << "Enter the position whee you want to insert a Node" << endl;
    cin >> pos;
    cout << "Enter the element you want to enter at that position" << endl;
    cin >> n;
    p=(node *)malloc(sizeof(node));
    p->data=n;
    int c=1;
    while(c!=pos-1)
    {
        k=k->next;
        c++;
    }
    p->next=k->next;
    k->next=p;
    p->prev=k;
    p->next->prev=p;
    return head;
}
node *reverse(node *head)
{
    node *temp=NULL;
    node *k=head;
    while(k!=NULL)
    {
        cout << k->data << endl;
        temp=k->prev;
        k->prev=k->next;
        k->next=temp;
        k=k->prev;
    }
    head=k->prev;
    return head;
}
void display(node *head)
{
    node *p=NULL;
    p=head;
    while(p->next!=NULL)
    {   
        cout << p->data << " --> ";
        p=p->next;
    }
    while(p!=NULL)
    {
        cout << p->data << " --> ";
        p=p->prev;
    }
    cout << "NULL" << endl;

}
int main()
{
    char ans;
    int choice;
    node *head=NULL;

    do
    {
        cout << "\n\t\tMENU\n\t1.)Insertion At Beginning\n\t2.Insertion At Ending\n\t3.)Insertion At A Position\n\t4.)Reverse Linked List\n\t5.)Display Linked List" << endl;
        cout << "Enter your choice" << endl;
        cin >> choice;
        switch(choice)
        {
            case 1 : head=insertbegin(head);
                    break;
            case 2 : head=insertend(head);
                    break;
            case 3 : head=insertpos(head);
                    break;
            case 4 : head=reverse(head);
                    break;
            case 5: display(head);
                    break;
            default:cout << "Wrong Choice!!" << endl;
        }    
        cout << "Do You Want To Continue?(Y/N)" << endl;
        cin >> ans; 
    } while (ans=='Y' || ans=='y');
    
}