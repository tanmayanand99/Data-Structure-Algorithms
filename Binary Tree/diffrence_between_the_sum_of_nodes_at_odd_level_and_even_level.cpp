#include<iostream>
#include<queue>
#define ABS(A) ((A>0)?(A):(A*-1))
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
void sumdifference(node *root)
{
    int level=0,odd=0,even=0;
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node *p=q.front();
        q.pop();
        if(p!=NULL)
        {
            if(level%2==0)
            {
                even=even + p->data;
            }
            else
            {
                odd = odd + p->data;
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
        else if(p==NULL)
        {
            if(!q.empty())
            {
                q.push(NULL);
            }
            level++;
        }
    }
    int diff = even-odd;
    cout << "Difference between the sum of nodes at even and odd level is : " << ABS(diff);
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
                1           -> level 0
            /       \
           2         3      -> level 1
          / \       / \
         4   5     6   7    -> level 2
    */
    sumdifference(root);
}