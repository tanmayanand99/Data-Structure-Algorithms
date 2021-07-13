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
    if(root==NULL)
    {
        return;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node *p=q.front();
        q.pop();
        if(p!=NULL)
        {
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
        else if(!q.empty())
        {
            q.push(NULL);
        }
    }
}
void levelsum(node *root)
{
    int sum=0;
    if(root==NULL)
    {
        return;
    }
    int res=root->data;
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        sum=0;
        int size=q.size();
        while(size)
        {
            node *p=q.front();
            sum=sum+p->data;
            q.pop();
            if(p->left)
            {
                q.push(p->left);
            }
            if(p->right)
            {
                q.push(p->right);
            }
            size--;
        }
        if(sum>res)
        {
            res=sum;
        }
    }
    cout << "Sum : " << sum << endl;
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
    cout << "Level Order" << endl;
    levelorder(root);
    cout << endl;
    levelsum(root);
}