#include<iostream>
#include<queue>
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
void levelorder(node *root)
{
    queue<node*> q;
    stack<node*> s;
    q.push(root);
    int level=1;
    while(!q.empty())
    {
        node *p=q.front();
        q.pop();
        cout << p->data << " ";
        if(level%2!=0)
        {
            if(p->right)
            {
                q.push(p->right);
            }
            if(p->left)
            {
                q.push(p->left);
            }
        }
        else
        {
            if(p->left)
            {
                q.push(p->left);
            }
            if(p->right)
            {
                q.push(p->right);
            }
        }
        
    }
    while(!s.empty())
    {
        node *p = s.top();
        cout << p->data << " ";
        s.pop();
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
    cout << "LEVEL ORDER ITERATIVE" << endl;
    levelorder(root);
}
