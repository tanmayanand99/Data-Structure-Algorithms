#include<iostream>
using namespace std;
typedef struct nodes{
    char data;
    struct nodes *next;
}node;
node *pop(node *head)
{
    head = head->next;
    return head;
}
node *push(node *head,char s)
{
    int n;
    node *p=NULL,*right=NULL;
    p = (node *)malloc(sizeof(node));
    p->data = s;
    
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
int main()
{
    string s;
    int i=0;
    node *head=NULL;
    cout << "Enter the String which you want to check is palindrome or not" << endl;
    cin >> s;
    while(s[i]!='X')
    {
        head=push(head,s[i]);
        i++;
    }
    while(++i!=s.length())
    {
        if(head->data==s[i])
        {
            head=pop(head);
        }
        else
        {
            break;
        }
    }
    if(head==NULL)
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not Palindrome" << endl;
    }
    return 0;
}