#include<iostream>
using namespace std;
typedef struct maxheap
{
    int *ar;
    int capacity;
    int count;
}maxh;
maxh *createheap(int capacity)
{
    maxh *h = (maxh *)malloc(sizeof(maxh));
    if(h==NULL)
    {
        cout << "Memory Error" << endl;
    }
    h->count=0;
    h->capacity=capacity;
    h->ar=(int *)malloc(sizeof(int)*h->capacity);
    return h;
}
int parentnode(int i,maxh *h)
{
    if(i<=0 || i>=h->count)
        return -1;
    return (i-1)/2;
}
int leftchildren(int i,maxh *h)
{
    int left = (2*i)+1;
    if(left>=h->count)
        return -1;
    return left;
}
int rightchildren(int i,maxh *h)
{
    int right = (2*i)+2;
    if(right>=h->count)
        return -1;
    return right;
}
int maximum(maxh *h)
{
    if(h->count==0)
        return -1;
    return h->ar[0];
}
void heapify(maxh *h,int i)
{
    int max,temp;
    int l=leftchildren(i,h);
    int r=rightchildren(i,h);
    if(l!=-1 && h->ar[l]>=h->ar[i])
    {
        max=l;
    }
    else
    {
        max=i;
    }
    if(r!=-1 && h->ar[r]>=h->ar[max])
    {
        max=r;
    }
    if(max!=i)
    {
        temp=h->ar[i];
        h->ar[i]=h->ar[max];
        h->ar[max]=temp;
        heapify(h,max);
    }
}
int del(maxh *h)
{
    int data;
    if(h->count==0)
        return -1;
    
    data = h->ar[0];
    h->ar[0]=h->ar[h->count-1];
    h->count--;
    heapify(h,0);
    return data;
}
void resize(maxh *h)
{
    int *arold;
    arold = h->ar;
    h->ar=(int *)malloc(sizeof(int)*h->capacity*2);
    for(int i=0;i<h->capacity;i++)
    {
        h->ar[i]=arold[i];
    }
    h->capacity=h->capacity*2;
    free(arold);
}
void insert(maxh *h,int data)
{
    int i;
    if(h==NULL)
        return;
    if(h->count==h->capacity)
        resize(h);
    h->count++;
    i=h->count-1;
    while(i!=0 && data>h->ar[(i-1)/2])
    {
        h->ar[i]=h->ar[(i-1)/2];
        i=(i-1)/2;
    }
    h->ar[i]=data;
}
void destroyheap(maxh *h)
{
    if(h==NULL)
        return;
    free(h->ar);
    free(h);
    h=NULL;
}
int main()
{
    int size,ele;
    char ans;
    maxh *h;
    cout << "Enter the size of heap you want to create" << endl;
    cin >> size;
    h=createheap(size);
    do
    {
        cout << "Enter the element in the heap" << endl;
        cin >> ele;
        insert(h,ele);
        cout << "DO YOU WANT TO ENTER MORE ELEMENTS" << endl;
        cin >> ans;
    } while (ans=='y' || ans=='Y');
    cout << "ELEMENTS OF HEAP ARE" << endl;
    for(int i=0;i<h->count;i++)
    {
        cout << h->ar[i] << " ";
    }
    cout << "Maximum element in heap is : " <<  maximum(h);

}