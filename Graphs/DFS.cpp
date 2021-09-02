#include<iostream>
#include<vector>
#include<stack>
#define vi vector<int>
#define vvi vector<vi>
using namespace std;
int main()
{
    int n,m;
    cout << "Enter the number of vertex and the edges" << endl;
    cin >> n >> m;

    vector<vector<int>> adjm(n+1,vector<int> (n+1,0));
    // vvi adjm(n+1,vi(n+1,0));

    for(int i=0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        adjm[x][y]=1;
        adjm[y][x]=1;
    }
    cout << "Adjency Matrix is : " << endl;
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            cout << adjm[i][j] << "\t";
        }
        cout << endl;
    }
    
    vector<int> a(n+1,0);
    stack<int> s;
    int flag=0;
    s.push(1);
    cout << 1 << " ";
    a[1]=1;
    while(!s.empty())
    {
        flag=0;
        int k=s.top();
        for(int i=1;i<n+1;i++)
        {
            if(adjm[k][i]==1 && a[i]==0)
            {
                s.push(i); 
                cout << i << " ";
                a[i]=1;
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            s.pop();
        }
    }
}