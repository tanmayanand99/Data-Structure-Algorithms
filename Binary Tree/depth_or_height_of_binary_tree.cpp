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
void levelorder(node *root)
{
    if(!root)
        return;
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node *p=q.front();
        q.pop();
        cout << p->data << " ";
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
void depth(node *root)
{
    int count=0;
    if(!root)
        return;
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node *p=q.front();
        q.pop();
        if(p!=NULL)
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
        else if(p==NULL)
        {
            count++;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
    }
    cout << "Depth of tree is : " << count << endl;
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
    cout << "BEFORE DELETING" << endl;
    levelorder(root);
    cout << endl;
    depth(root);
}