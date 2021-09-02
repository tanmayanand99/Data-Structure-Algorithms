#include<iostream>
#include<queue>
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
void deepestnode(node *root)
{
    queue<node*> q;
    node *p=NULL;
    q.push(root);
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        if(p->left)
        {
            q.push(p->left);
        }
        if(p->right)
        {
            q.push(p->right);
        }
    }
    cout << "The Deepest Node in Binary Tree is " << p->data << endl;
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
    root->right->left->right = new node(8);
    /*
                1
            /       \
           2         3
          / \       / \
         4   5     6   7
                    \
                     8
    */
    deepestnode(root);
}