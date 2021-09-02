#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,m,x;
    cout << "Enter the number of vertex and edges" << endl;
    cin >> n >> m;
    vector<vector<int>> adjm(n+1,vector<int>(n+1,0));
    cout << "Enter the connected vertexes of the directed graph" << endl;
    for(int i=0;i<m;i++)
    {
        int y;
        cin >> x >> y;
        adjm[x][y]=1;
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            cout << adjm[i][j] << "\t";
        }
        cout << endl;
    }
}