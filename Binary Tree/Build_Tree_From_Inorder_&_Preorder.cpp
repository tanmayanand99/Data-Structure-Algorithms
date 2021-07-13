#include<iostream>
using namespace std;
typedef struct nodes
{
    int data;
    struct nodes *left;
    struct nodes* right;
    nodes(int value)
    {
        data=value;
        left=NULL;
        right=NULL;
    }
}node;
void display(node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        display(root->left);
        cout << root->data << " ";
        display(root->right);
    }
}
int main()
{
    int inorder[50],preorder[50];
    int n,pos;
    cout << "Number of Elements" << endl;
    cin  >> n;
    cout << "Enter the Elements in inorder tree" << endl;
    for(int i=0;i<n;i++)
    {
        cin >> inorder[i];
    }
    cout << "Enter the Elements in preorder tree" << endl;
    for(int i=0;i<n;i++)
    {
        cin >> preorder[i];
    }
    node *root = new node(preorder[0]);
    for(int i=0;i<n;i++)
    {
        if(preorder[0]==inorder[i])
        {
            pos=i;
            break;
        }
    }
    node *p=root;
    for(int i=0;i<pos;i++)
    {
        p=p->left;
        p=new node(inorder[i]);
    }
    p=root;
    for(int i=pos+1;i<n;i++)
    {
        p=p->right;
        p=new node(inorder[i]);
    }
    cout << "INORDER" << endl;
    display(root);
}