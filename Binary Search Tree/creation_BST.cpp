#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct nodes{
    int data;
    struct nodes *left;
    struct nodes *right;
    nodes(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
}node;
void insertion(node *root,node *temp)
{
    if(temp->data<root->data)
    {
        if(root->left==NULL)
        {
            root->left=temp;
        }
        else
        {
            insertion(root->left,temp);
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
            insertion(root->right,temp);
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
int main()
{
    node *root=NULL;
    int n,c=0;
    int ans;
    do
    {
        cout << "Enter the data";
        cin >> n;
        node *temp=NULL;
        temp=new node(n);
        if(root==NULL)
        {
            root=temp;
        }
        else
        {
            insertion(root,temp);
        }
        cout << "Enter your choice" << endl;
        cin >> ans;
    } while (ans==1);
    
    cout << "Do you want to display the binary search tree" << endl;
    cin >> ans;
    if(ans==1)
    {
        displaypreorder(root);
    }   

}
