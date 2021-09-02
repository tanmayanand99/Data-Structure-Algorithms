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
int leavesno(node *root)
{
    if(!root)
        return 0;
    
    if(root->left==NULL && root->right==NULL)
    {
        return 1;
    }
    else
    {
        int l = leavesno(root->left);
        int r = leavesno(root->right);
        int total = l + r;
        return total;
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
    cout << "No. of Leaf Nodes : " << leavesno(root);
}
