#include<iostream>
#include<queue>
using namespace std;
typedef struct nodes 
{
    int data;
    struct nodes *left;
    struct nodes *right;
    nodes(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
}node;
void spiral(node *root)
{
    int level=1;
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node *p=NULL;
        p=q.front();
        q.pop();
        if(p!=NULL)
        {
            cout << p->data << " ";
            if(==1)
            {
                q.push(p->left);
                q.push(p->right);
            }
            else
            {
                q.push(p->right);
                q.push(p->left);
            }
        }
        else if(!q.empty())
        {
            q.push(NULL);
        }
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
    
}