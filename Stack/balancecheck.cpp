#include<iostream>
using namespace std;
typedef struct nodes{
    char data;
    struct nodes *next;
}node;
node *pop(node *head,char s)
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
    node *head=NULL;
    int choice,answer;
    string s;
    int i=0;
    cout << "Enter the Expression that you want to check have brackets or not" << endl;
    cin >> s;

    while(i!=s.length())
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
        {
            head = push(head,s[i]);
        }
        else if(s[i]==')' || s[i]=='}' || s[i]==']')
        {
            if(s[i]==')')
            {
                if(head->data=='(')
                {
                    head = pop(head,s[i]);
                }
            }
            else if(s[i]=='}')
            {
                if(head->data=='{')
                {
                    head = pop(head,s[i]);
                }
            }
            else if(s[i]==']')
            {
                if(head->data=='[')
                {
                    head = pop(head,s[i]);
                }
            } 
        }
        i++;
    }
    if(head==NULL)
    {
        cout << "Balanced Expression" << endl;
    }
    else
    {
        cout << "Not a Balanced Expression" << endl;
    }
    return 0;
}