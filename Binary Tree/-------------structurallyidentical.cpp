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
int check(node *root1,node *root2)
{
    if(root1==NULL && root2==NULL)
    {
        return 1;
    }
    if(root1->data!=root2->data)
    {
        return 0;
    }
    check(root1->left,root2->left);
    check(root1->right,root2->right);
    return 0;
}
int main()
{
    node *root1 = new node(1);
    root1->left = new node(2);
    root1->right = new node(3);
    root1->left->left = new node(4);
    root1->left->right = new node(5);
    root1->right->left = new node(6);
    root1->right->right = new node(7);

    node *root2 = new node(1);
    root2->left = new node(2);
    root2->right = new node(3);
    root2->left->left = new node(4);
    root2->left->right = new node(5);
    root2->right->left = new node(7);
    root2->right->right = new node(7);
    /*
                1
            /       \
           2         3
          / \       / \
         4   5     6   7
    */
    cout << check(root1,root2);
}