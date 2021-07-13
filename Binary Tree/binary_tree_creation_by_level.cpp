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
node *insert(node *root,int n)
{
    node *r = new node(n);
    if(!root)
    {
        root=r;
        return root;
    }
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
            return root;
        }
        if(p->right)
        {
            q.push(p->right);
        }
        else
        {
            p->right=r;
            return root;
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
    node *root = NULL;
    int n;
    char ans;
    /*
                1
              /   \
             2     3
            / \   / \
           4   5 6   7
    */
    do
    {
        cout << "Enter the elements you want to enter in binary tree level by level" << endl;
        cin >> n;
        root = insert(root,n);
        cout << "Do you want to enter more nodes" << endl;
        cin >> ans;
    } while (ans=='y');
    
    cout << "\nAFTER INSERTING : " << endl;
    inorder(root);

}

