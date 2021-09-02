#include<iostream>
using namespace std;
typedef struct minheap
{
    int *ar;
    int capacity;
    int count;
}minh;
minh *createheap(int capacity)
{
    minh *h=(minh *)malloc(sizeof(minh));
    h->capacity=capacity;
    h->count=0;
    h->ar =(int *)malloc(sizeof(int)*capacity);
    return h;
}
void resize(minh *h)
{
    int *oldar=NULL;
    oldar=h->ar;
    h->ar = (int *)malloc(sizeof(int)*h->capacity*2);
    for(int i=0;i<h->capacity;i++)
    {
        h->ar[i]=oldar[i];
    }
    h->capacity=h->capacity*2;
    free(oldar);
}
void insert(minh *h,int ele)
{
    int i;
    if(h==NULL)
        return;
    if(h->capacity==h->count)
        resize(h);
    h->count++;
    i=h->count-1;
    while(i!=0 && ele<h->ar[(i-1)/2])
    {
        h->ar[i]=h->ar[(i-1)/2];
        i=(i-1)/2;
    }
    h->ar[i]=ele;
}
int leftchildren(minh *h,int i)
{
    int l=(2*i)+1;
    if(l>=h->count)
        return -1;
    return l;
}
int rightchildren(minh *h,int i)
{
    int r=(2*i)+2;
    if(r>=h->count)
        return -1;
    return r;
}
void heapify(minh *h,int i)
{
    int min,temp;
    int l=leftchildren(h,i);
    int r=rightchildren(h,i);
    if(l!=-1 && h->ar[l]<=h->ar[i])
    {
        min = l;
    }
    else
    {
        min = i;
    }
    if(r!=-1 && h->ar[r]<=h->ar[min])
    {
        min=r;
    }
    if(min!=i)
    {
        temp=h->ar[min];
        h->ar[min]=h->ar[i];
        h->ar[i]=temp;
        heapify(h,min);
    }
}
int del(minh *h)
{
    if(h->count==0)
        return -1;
    int data=h->ar[0];
    h->ar[0]=h->ar[h->count-1];
    h->count--;
    heapify(h,0);
    return data;
}
int main()
{
    int size,ele;
    char ans;
    minh *h;
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
    //cout << "Maximum element in heap is : " <<  maximum(h);
}