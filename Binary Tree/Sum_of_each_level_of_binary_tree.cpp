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
void sumeachlevel(node *root)
{
    int sum=0,i=1;
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node *p=q.front();
        q.pop();
        if(p!=NULL)
        {
            sum=sum+p->data;
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
            cout << "Level #" << i << " : " << sum << endl;
            sum=0;
            i++;
            if(!q.empty())
            {
                q.push(NULL);
            }
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
    cout << "Sum of Each Level is : " << endl;
    sumeachlevel(root);
}
