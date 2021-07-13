#include<iostream>
using namespace std;
typedef struct nodes
{
    int data;
    struct nodes *next;
}node;
int main()
{
    node *left=NULL,*right=NULL,*p=NULL,*prev=NULL,*add=NULL;
    int n,pos,k=1;
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
        cout << "Enter the position where you want to enter the element" << endl;
        cin >> pos;

        cout << "Enter the element which you want to enter at that position" << endl;
        cin >> n;
        p=prev=left;
        p=(node *)malloc(sizeof(node));

        if(p!=NULL)
        {
            p->data=n;
            while(k!=pos-1)
            {
                prev=prev->next;
                k++;
            }
            add=prev->next;
            prev->next=p;
            p->next=add;
        }  
        cout << "Do you want to continue to enter element at a position(Y/N)" << endl;
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