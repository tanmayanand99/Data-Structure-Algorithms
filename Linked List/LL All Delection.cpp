#include<iostream>
using namespace std;
typedef struct nodes
{
    int data;
    struct nodes *next;
}node;
node *delbeg(node *head)
{
    head=head->next;
    return head;
}
int main()
{
    char ans;
    int choice;
    node *head=NULL;

    do
    {
        cout << "\n\t\tMENU\n\t1.)Insert In Linked List at Beginning\n\t2.)Insert In Linked List at end\n\t3.)Insert In Linked List At A Position\n\t4.)Display Linked List" << endl;
        cout << "Enter your choice" << endl;
        cin >> choice;
        switch(choice)
        {
            case 1:head = delbeg(head);
                    break;
            case 2:head = delend(head);
                    break;
            case 3:head = delpos(head);
                    break;
            case 4:display(head);
                    break;
            default:cout << "WRONG CHOICE!!" << endl;
        }
        cout << "Do You Want To Continue??" << endl;
        cin >> ans;
    } while (ans=='Y' || ans=='y');
}