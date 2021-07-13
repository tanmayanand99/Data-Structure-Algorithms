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
void postorder(node *root) // L R D
{
    stack<node*> s;
    while(1)
    {
        while(root)
        {
            s.push(root);
            root=root->left;
        }
        root=s.top();
        s.pop();
        cout 
        root=root->right;

    }
}
void recurpostorder(node *root)
{
    
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
    cout << "POSTORDER ITERATIVE" << endl;
    inorder(root);
    cout << "\nPOSTORDER RECURSIVE" << endl;
    recurinorder(root);
}
