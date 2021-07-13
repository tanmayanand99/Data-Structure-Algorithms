#include<iostream>
using namespace std;
typedef struct nodes
{
    int data;
    struct nodes *left;
    struct nodes *right;
    nodes(int value)
    {
        data=value;
        left = NULL;
        right = NULL;
    }
}node;
void preorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}
void inorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    /*
                1
            /       \
           2         3
          / \       / \
         4   5     6   7
    */
    cout << "INORDER" << endl;
    inorder(root);
    cout << "\nPREORDER" << endl;
    preorder(root);
    cout << "\nPOSTORDER" << endl;
    postorder(root);
}