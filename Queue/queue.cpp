#include<iostream>
using namespace std;
typedef struct queue
{
    int size,capacity,front,rear;
    int *ar;
}que;
bool isFull(que *t)
{
    if(t->size==t->capacity)
    {
        return true;
    }
    else
    {
        return false;
    }
}
que *createqueue(int capacity)
{
    que *Queue=(que *)malloc(sizeof(que)*capacity);
    Queue->capacity=capacity;
    Queue->front = Queue->size = 0;
    Queue->rear = capacity-1;
    Queue->ar=(int *)malloc((Queue->capacity)*sizeof(int));
    return Queue;
}
void enqueue(que *t,int data)
{
    if(isFull(t))
    {
        cout << "Overflow" << endl;
        return;
    }
    t->rear=(t->rear+1)%(t->capacity);
    t->ar[t->rear]=data;
    t->size+=1;
}
void dequeue(que *t)
{
    if(t->size==0)
    {
        cout << "Underflow" << endl;
        return;
    }
    t->front = (t->front+1)%(t->capacity);
    t->size -= 1;   
}
void display(que *t)
{
    int temp;
    temp=t->front;
    if(t->size==0)
    {
        cout << "No Element to display" << endl;
        return;
    }
    while(temp!=t->rear+1)
    {
        cout << t->ar[temp] << " --> ";
        temp=(temp+1)%t->capacity;
    }
    cout << "NULL" << endl;
}
int main()
{
    que* queue = createqueue(1000);
    int data,choice;
    char ans;
    do
    {
        cout << "\n\t\tMENU\n\t1.)Enqueue\n\t2.)Dequeue\n\t3.)IsFull\n\t4.)Display" << endl;
        cout << "Enter your choice" << endl;
        cin >> choice;
        switch(choice)
        {
            case 1:cout << "Enter the number you want to enter in queue" << endl;
                   cin >> data;
                   enqueue(queue,data);
                   break; 
            case 2:dequeue(queue);
                   break;
            case 3:isFull(queue);
                   break;
            case 4:display(queue);
                   break;
            default: cout << "Wrong choice" << endl;
        }
        cout << "Do you want to continue?(Y/N)" << endl;
        cin >> ans;
    } while (ans=='Y' || ans=='y');
    return 0;
}