#include<iostream>
using namespace std;
void push(int *, int [], int);
void pop(int *, int []);
void display(int , int []);
void peek(int , int []);
int main()
{
    int top=-1,n,ch,i;
    char ans;

    cout << "Enter the number of elements in stack" << endl;
    cin >> n;
    int ar[n];
    do
    {
        cout << "\t\tMENU" << "\n" << "\t1. PUSH\n" << "\t2. POP\n" << "\t3. DISPLAY\n" << "\t4. PEEK" << endl;
        cout << "Enter your choice = " << endl;
        cin >> ch;

        switch(ch)
        {
            case 1: push(&top,ar,n);
                    break;
            case 2: pop(&top,ar);
                    break;
            case 3: display(top,ar);
                    break;
            case 4: peek(top,ar);
                    break;
            default: cout << "Wrong Input" << endl;
        }

        cout << "Do you want to continue(Y/N)" << endl;
        cin >> ans;
    }while(ans=='Y');
}
void push(int *top,int ar[],int max)
{
    if(*top!=max-1)
    {
        (*top)++;
        cout << "Enter the element" << endl;
        cin >> ar[*top];
    }
    else
    {
        cout << "Stack is full" << endl;
    }    
}
void pop(int *top,int ar[])
{
    if(*top==-1)
    {
        cout << "No elements in stack" << endl;
    }
    else
    {
        (*top)--;
    }  
}
void display(int top,int ar[])
{
    int temp;
    temp=top;
    cout << "Stack is" << endl;
    while(temp!=-1)
    {
        cout << ar[temp] << "\n";
        temp--;        
    }
}
void peek(int top,int ar[])
{
    if(top==-1)
    {
        cout << "No element to peek" << endl;
    }
    else
    {
        cout << ar[top];
    }
}
