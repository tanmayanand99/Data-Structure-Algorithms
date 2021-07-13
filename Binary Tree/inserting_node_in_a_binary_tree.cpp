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
void insert(node *root,int n)
{
    node *r = new node(n);
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node *p = q.front();
        q.pop();
        if(p->left)
        {
            q.push(p->left);
        }
        else
        {
            p->left=r;
            return;
        }
        if(p->right)
        {
            q.push(p->right);
        }
        else
        {
            p->right=r;
            return;
        }
    }
}
void inorder(node *root)
{
    if(root)
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
              /   \
             2     3
            / \   / \
           4   5 6   7
    */
    int n;
    cin >> n;
    cout << "BEFORE INSERTING : " << endl; 
    inorder(root);
    insert(root,n);
    cout << "\nAFTER INSERTING : " << endl;
    inorder(root);

}

