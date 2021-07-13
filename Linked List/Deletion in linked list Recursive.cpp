#include<iostream>
using namespace  std;
typedef struct node
{
    int data;
    struct node *next;
}nodes;
node *deletion(node *head,int key)
{
    if(head->data==key)
    {
        head=head->next;
        return;
    }
    return deletion(head->next,key);
}
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
        
        left = deletion(p,num);
        
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