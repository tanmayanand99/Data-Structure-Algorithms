#include<iostream>
using namespace std;
typedef struct nodes
{
    int data;
    struct nodes *left;
    struct nodes *right;
}node;
node *create(int n)
{
    node *temp=(node *)malloc(sizeof(node));
    if(temp==NULL)
    {
        cout << "Memory Full" << endl;
    }
    else
    {
        temp->data=n;
        temp->left=NULL;
        temp->right=NULL;
    }
    return temp;
}
void insert(node *root,node *temp)
{
    if(temp->data<root->data)
    {
        if(root->left==NULL)
        {
            root->left=temp;
        }
        else
        {
            insert(root->left,temp);
        }
    }
    else
    {
        if(root->right==NULL)
        {
            root->right=temp;
        }
        else
        {
            insert(root->right,temp);
        }
    }
}
void displaypreorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        cout << root->data << " ";
        displaypreorder(root->left);
        displaypreorder(root->right);
    }
}
void displayinorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        displayinorder(root->left);
        cout << root->data << " ";
        displayinorder(root->right);
    }
}
void displaypostorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        displaypostorder(root->left);
        displaypostorder(root->right);
        cout << root->data << " ";
    }
}
int main()
{
    node *temp=NULL,*root=NULL;
    int n,ans;
    char choice;

    do
    {
        cout << "\t\tMenu\n\t1.)Insert Node in Tree\n\t2.)Preorder Traversal\n\t3.)Inorder Traversal\n\t4.)Postorder Traversal" << endl;
        cin >> ans;
        switch(ans)
        {
            case 1: cout << "Enter the number that you want to enter in the tree" << endl;
                    cin >> n;
                    temp=create(n);
                    if(root==NULL)
                    {
                        root=temp;
                    }
                    else
                    {
                        insert(root,temp);
                    }
                    break;
            case 2: displaypreorder(root);
                    break;
            case 3: displayinorder(root);
                    break;
            case 4: displaypostorder(root);
                    break;
            default:cout << "Worng Choice" << endl;
        }
        cout << "\nDo you want to continue" << endl;
        cin >> choice;
    } while (choice=='Y' || choice=='y');
}