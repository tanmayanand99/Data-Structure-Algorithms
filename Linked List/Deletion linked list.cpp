#include<iostream>
using namespace  std;
typedef struct node
{
    int data;
    struct node *next;
}nodes;
int main()
{
    int n,ch,num;
    nodes *p=NULL,*left=NULL,*right=NULL;

    do
    {
        p=(nodes *)malloc(sizeof(nodes));

        cout << "Enter Number" << endl;
        cin >> p->data;
        
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

        cout << "Enter choice" << endl;
        cin >> ch;
    }while(ch==1);

    cout << "Printing the Linked List" << endl;
    p=left;
    while(p!=NULL)
    {
        cout << p->data << "\t";
        p=p->next;
    }

    cout << "\nDeletion of element in linked list" << endl;
    do
    {
        cout << "Enter Number that you want to delete" << endl;
        cin >> num;
        p=left;
        node *l1=left,*prev=NULL;
        if(l1!=NULL && l1->data==num)
        {
            left=l1->next;
        }
        else
        {
            while(l1!=NULL && l1->data!=num)
            {
                prev=l1;
                l1=l1->next;
            }
            if(l1==NULL)
            {
                cout << "No element exist" << endl;
            }
            prev->next=l1->next;
        }
        
        cout << "Enter choice" << endl;
        cin >> ch;
    }while(ch==1);
    

    cout << "Printing the Linked List" << endl;
    p=left;
    while(p!=NULL)
    {
        cout << p->data << "\t";
        p=p->next;
    }
}