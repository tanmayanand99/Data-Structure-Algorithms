#include<iostream>
#include<stack>
using namespace std;
typedef struct nodes
{
    int data;
    struct nodes *left;
    struct nodes *right;
    nodes(int value)
    {
        data = value;
        left=NULL;
        right=NULL;
    }
}node;
void preorder(node *root) // RO L R
{
    stack<node*> nodeStack;
    while(1)
    {
        while(root)
        {
            cout << root->data << " ";
            nodeStack.push(root);
            root=root->left;
        }
        if(nodeStack.empty())
            break;
        root = nodeStack.top();
        nodeStack.pop();
        root=root->right;
    } 
}
void inorder(node *root)  // L RO R
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
        {
            break;
        }
        root=s.top();
        s.pop();
        cout << root->data << " ";
        root=root->right;
    }
}
void postorder(node *root)  // L R RO
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
        {
            break;
        }
        root=root->right;
        s.push(root);
        
        
    }
}
int main()
{
    node *root= new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    inorder(root);

    return 0;
}