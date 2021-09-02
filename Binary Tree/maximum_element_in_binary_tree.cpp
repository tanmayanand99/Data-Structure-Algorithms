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
int max(node *root)
{
    int ma=INT32_MIN;
    if(root!=NULL)
    {
        int root_data = root->data;
        int left = max(root->left);
        int right = max(root->right);
        if(left>right)
        {
            ma=left;
        }
        else
        {
            ma=right;
        }
        if(root_data>ma)
        {
            ma=root_data;
        }
    }
    return ma;
}
int iterativemax(node *root)
{
    int ma = INT32_MIN;
    if(root)
    {
        queue<node*> q;
        q.push(root);
        while(!q.empty())
        {
            node *p=q.front();
            q.pop();
            if(p->data>ma)
            {
                ma = p->data;
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
    }
    return ma;
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
    cout << "Maximum element in binary tree : " << iterativemax(root) << endl;
    cout << "Maximum element in binary tree : " << max(root);
}