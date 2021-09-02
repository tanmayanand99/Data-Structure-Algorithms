#include<iostream>
#include<vector>
#include<queue>
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
    queue<int> q;
    q.push(1);
    a[1]=1;
    while(!q.empty())
    {
        int k=q.front();
        for(int i=1;i<n+1;i++)
        {
            if(adjm[k][i]==1 && a[i]==0)
            {
                q.push(i);
                a[i]=1;
            }
        }
        cout << k << " ";
        q.pop();
    }
}