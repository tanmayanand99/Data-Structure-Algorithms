#include<iostream>
#include<vector>
#define vi vector<int>
#define vvi vector<vi>
const int N=1e5+2;
using namespace std;
int main()
{
    int n,m;
    cout << "Enter the number of vertex and the edges" << endl;
    cin >> n >> m;

    vector<int> adjm[N];

    for(int i=0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        adjm[x].push_back(y);
        adjm[y].push_back(x);
    }
    cout << "Adjency List is : " << endl;
    for(int i=1;i<n+1;i++)
    {
        cout << i << "->";
        vector<int> ::iterator it;
        for(it=adjm[i].begin();it!=adjm[i].end();it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    int x,y;
    cout << "Check if two vertex is connected or not" << endl;
    cin >> x >> y;
    cout << "Checking if " << x << " and " << y << " are connected or not....." << endl;
    vector<int> ::iterator it;
    for(it=adjm[x].begin();it!=adjm[x].end();it++)
    {
        if(*it==y)
        {
            cout << "Elements found" << endl;
        }
    }
}