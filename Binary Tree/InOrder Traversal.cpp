#include<iostream>
#include<stack>
using namespace std;
typedef struct nodes
{
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
void inorder(node *root) // L D R
{
    stack<node*> s;
    while(1)
    {
        while(root)
        {
            s.push(root);
            root=root->left;
        }
        if(s.empty())
            break;
        root=s.top();
        s.pop();
        cout << root->data << " ";
        root=root->right;
    }
}
void recurinorder(node *root)
{
    if(root)
    {
        recurinorder(root->left);
        cout << root->data << " ";
        recurinorder(root->right);
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
    cout << "INORDER ITERATIVE" << endl;
    inorder(root);
    cout << "\nINORDER RECURSIVE" << endl;
    recurinorder(root);
}
