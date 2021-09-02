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
        data=val;
        left=NULL;
        right=NULL;
    }
}node;
void del(node *root,int data)
{
    queue<node*> q;
    node *p=NULL,*f=NULL;
    q.push(root);
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        if(p->data==data)
        {
            f = p;
        }
        if(p->left)
        {
            q.push(p->left);
        }
        if(p->right)
        {
            q.push(p->right);
        }
    }
    int temp = p->data;
    p->data = f->data;
    f->data = temp;
    free(p);
}
void levelorder(node *root)
{
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
              /   \
             2     3
            / \   / \
           4   5 6   7
    */
    int n;
    cout << "Enter the element you want to delete" << endl;
    cin >> n;
    levelorder(root);
    del(root,n);
    cout << endl;
    levelorder(root);
}

