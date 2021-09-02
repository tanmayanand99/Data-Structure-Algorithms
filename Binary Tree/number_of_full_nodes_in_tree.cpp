#include<iostream>
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
int fullnodes(node *root)
{
    int total=0;
    if(!root)
        return 0;
    
    if(root->left==NULL && root->right==NULL)
    {
        return 0;
    }
    else
    {
        int l = fullnodes(root->left);
        int r = fullnodes(root->right);
        total = l+r+1;
    }
    return total;
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
    root->right->right->right = new node(8);
    root->right->right->left = new node(9);
    /*
                1
              /   \
             2     3
            / \   / \
           4   5 6   7
                    / \
                   9   8
    */
    cout << "No. of Full Nodes : " << fullnodes(root);
}
