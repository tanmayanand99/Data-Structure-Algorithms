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
int search(node *root,int n)
{
    if(!root)
        return 0;
    else
    {
        if(root->data==n)
        {
            return 1;
        }
        int l = search(root->left,n);
        if(l!=0)
            return 1;
        else
            return search(root->right,n);
    }
    return 0;
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
    cout << search(root,n);
}

