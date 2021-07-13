#include<iostream>
using namespace std;
typedef struct nodes
{
    int data;
    struct nodes *next;
}node;
int main()
{
    node *left=NULL,*right=NULL,*p=NULL,*l=NULL;
    int n;
    char ch;
    do
    {
        cout << "Enter the element you want to add in the linked list" << endl;
        cin >> n;
        p=(node *)malloc(sizeof(node));
        if(p!=NULL)
        {
            p->data=n;
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
        
        cout << "Do you want to continue (Y/N)" << endl;
        cin >> ch;
    }while(ch=='Y');

    cout << "-------------------->>>>>>>>>>>Do you want to print the linked list(Y/N)";
    cin >> ch;
    if(ch=='Y')
    {
        p=left;
        while(p!=NULL)
        {
            cout << p->data << " -> ";
            p=p->next;
        }
        cout << "NULL" << endl;
    }

    do
    {
        cout << "Enter the element Which you want to delete from the linked list" << endl;
        cin >> n;

        p=left;

        while(p!=NULL)
        {
            if(p->data==n)
            {
                l->next=p->next;
                break;
            }
            else
            {
                l=p;  
                p=p->next;
            }
        }        
        cout << "Do you want to continue (Y/N)" << endl;
        cin >> ch;
    }while(ch=='Y');

    cout << "-------------------->>>>>>>>>>>Do you want to print the linked list(Y/N)";
    cin >> ch;
    if(ch=='Y')
    {
        p=left;
        while(p!=NULL)
        {
            cout << p->data << " -> ";
            p=p->next;
        }
        cout << "NULL" << endl;
    }
}