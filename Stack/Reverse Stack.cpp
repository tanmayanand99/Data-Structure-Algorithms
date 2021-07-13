#include<iostream>
using namespace std;
typedef struct nodes{
    int data;
    struct nodes *next;
}node;
node *pop(node *head)
{
    node *p;
    head = head->next;
    cout << "Popping Opeeration has been done" << endl;
    return head;
}
node *push(node *head)
{
    int n;
    node *p=NULL,*right=NULL;
    cout << "Enter the number you want to enter in the stack" << endl;
    cin >> n;
    p = (node *)malloc(sizeof(node));
    p->data = n;
    
    if(head==NULL)
    {
        right=head=p;
        right->next = NULL;
    }
    else
    {
        p->next=head;
        head=p;
    }
    return head;
}
void display(node *head)
{
    node *p;
    cout << "The stack is:" << endl;
    p=head;
    while(p!=NULL)
    {
        cout << p->data << " -> ";
        p=p->next;
    }
    cout << "NULL" << endl;
}
void peek(node *head)
{
    cout << "Toppest Element is " << head->data << endl;
}
int main()
{
    node *head=NULL;
    int choice,answer;

    do
    {    
        cout << "\t\tMENU\n\tPOP\n\tPUSH\n\tPEEK\n\tDISPLAY\nEnter the operation you want to perform" << endl;
        cin >> choice;
        switch(choice)
        {
            case 1:head=pop(head);
                    break;
            case 2:head=push(head);
                    break;
            case 3:peek(head);n
                  break;
            case 4:display(head);
        }
        cout << "Do you want to continue" << endl;
        cin >> answer;
    }while(answer==1);


    return 0;
}