#include<iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of elements" << endl;
    cin >> n;
    int a[n];
    cout << "Enter the elements of the array" << endl;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    
    for(int i=0;i<n;i++)
    {
        int max=-1;
        for(int j=i+1;j<n;j++)
        {
            if(a[i]<a[j])
            {
                max=a[j];
                break;
            }
        }
        cout << a[i] << " --> " << max << endl;
    }
    return 0;
}