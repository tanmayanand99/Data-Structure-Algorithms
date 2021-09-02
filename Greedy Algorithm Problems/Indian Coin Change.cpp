#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    int am;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    cout << "Enter the amount you want with minimum number of notes" << endl;
    cin >> am;

    for(int i=n-1;i>=0;)
    {
        if(a[i]<=am)
        {
            am=am-a[i];
            cout << a[i] << " + ";
        }
        else
        {
            i--;
        }
    }

    return 0;
}