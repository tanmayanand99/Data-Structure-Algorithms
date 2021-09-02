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
int heightoftree(node *root)
{
    if(!root)
        return 0;

    if(!root->left && !root->right)
    {
        return 0;
    }
    else
    {
        int l = heightoftree(root->left);
        int r = heightoftree(root->right);
        int m = max(l,r)+1;
        return m;
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
    cout << heightoftree(root);
}

