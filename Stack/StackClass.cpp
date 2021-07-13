#include<iostream>
#define MAX 1000
using namespace std;
class Stack
{
    public:
        int arr[MAX];
        int top;
        Stack()
        {
            top = -1;
        }
        bool isEmpty();
        void pop();
        bool push(int x);
        void peek();
        void display();
};
bool Stack::isEmpty()
{
    return (top<0);
}
void Stack::pop()
{
    if(isEmpty())
    {
        cout << "Underflow" << endl;
    }
    else
    {        
        int x = arr[top--];
        cout << x << " is popped from stack" << endl;
    }
}
bool Stack::push(int x)
{
    if(top==MAX)
    {
        cout << "Overflow" << endl;
        return 0;
    }
    else
    {
        arr[++top] = x;
        return true;
    }
}
void Stack::peek()
{
    if(isEmpty())
    {
        cout << "No elements in Stack" << endl;
    }
    else
    {
        cout << arr[top] << " is the element at the top" << endl;
    }
}
void Stack::display()
{
    int num = top;
    while(num>=0)
    {
        cout << arr[num] << " ";
        num--;
    }
    cout << endl;
}
int main()
{
    class Stack s;
    int choice,num;
    char ans;
    do
    {
        cout << "\t\tMENU\n\t1.)IsEmpty\n\t2.)Push\n\t3.)Pop\n\t4.)Peek\n\t5.)Display\nENTER YOUR CHOICE!!" << endl;
        cin >> choice;
        switch(choice)
        {
            case 1: if(s.isEmpty()==1)
                        cout << "Empty Stack" << endl;
                    break;
            case 2: cout << "Enter the number that you want to enter in the stack" << endl;
                    cin >> num;
                    s.push(num);
                    break;
            case 3: s.pop();
                    break;
            case 4: s.peek();
                    break;
            case 5: cout << "Elements in Stack are : " << endl;
                    s.display();
        }
        cout << "Do you want to continue?(Y/N)" << endl;
        cin >> ans;
        
    }while (ans=='Y');
}