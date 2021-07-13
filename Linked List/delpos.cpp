#include<iostream>
using namespace std;
typedef struct nodes
{
    int data;
    struct nodes *next;
}node;
node delpos(node *head)
{
    int n,k=1;
    node *p=NULL,*l=NULL;
    cout << "Enter the postion where you want to delete the element" << endl;
    cin >> n;

    if(n<=1)
    {
        head=head->next;
    }
    else
    {
        p=head;
        while(k!=n-1)
        {
            p=p->next;
            k++;
        }
        l=p->next;
        p->next=l->next;
    }
    return *head;
}
int main()
{
    int n;
    node *p=NULL,*left=NULL,*right=NULL;
    char ans;
    do
    {
        p=(node *)malloc(sizeof(node));
        cout << "Enter the element you want to enter in the linked list" << endl;
        cin >> n;
        p->data=n;
        if(p!=NULL)
        {
            if(left==NULL)
            {
                left=right=p;
            }
            else
            {
                right->next=p;
                right=p;
            }
            right->next=NULL;
        }
        cout << "Do you want to continue(Y/N)?" << endl;
        cin >> ans;
    } while (ans=='Y');
    
    p=left;
    while(p!=NULL)
    {
        cout << p->data << " -> ";
        p=p->next;
    }
    cout << "NULL" << endl;

    delpos(left);

    p=left;
    while(p!=NULL)
    {
        cout << p->data << " -> ";
        p=p->next;
    }
    cout << "NULL" << endl;
}