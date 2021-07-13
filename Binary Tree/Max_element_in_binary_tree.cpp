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
int maxele(node *root)
{
    int left,root_data,right,max = INT32_MIN;
    if(root)
    {
        root_data = root->data;
        left = maxele(root->left);
        right = maxele(root->right);

        if(left>right)
        {
            max = left;
        }
        else
        {
            max = right;
        }
        if(root_data>max)
        {
            max=root_data;
        }
    }
    return max;
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
    cout << "Maximum Element is : " << maxele(root);
}
