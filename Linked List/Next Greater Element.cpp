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
    int n;
    cout << "Enter the number of elements" << endl;
    cin >> n;
    int a[n];
    cout << "Enter the elements of the array" << endl;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if()
        }
    }
    return 0;
}