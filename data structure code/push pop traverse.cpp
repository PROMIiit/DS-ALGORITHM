#include<bits/stdc++.h>
using namespace std;

#define size 100
int data[size];
int top=-1;

bool isFull()
{
    if(top==size-1)
        return true;
    else
        return false;
}

bool isEmpty()
{
    if(top==-1)
        return true;
    else
        return false;
}

int push(int item)
{
    top++;
    data[top]=item;
}

int pop()
{
    return data[top--];
}

void traverse()
{
    int x=0;
    x=top;
    while(x>=0)

    {
        cout<<data[x]<<endl;
        x--;
    }
    //while(x>=0);
}

int main()
{
    cout<<"1.Push"<<endl;
    cout<<"2.Pop"<<endl;
    cout<<"3.Traverse"<<endl;
    cout<<"4.Exit"<<endl;
    int number;
    while(1)
    {
        cout<<"Select the case number: ";
        cin>>number;
        switch(number)
        {
        case 1:
            if(isFull()==true)
                cout<<"The stack is Full."<<endl;
            else
            {
                int item;
                cout<<"Push the item: ";
                cin>>item;
                push(item);
            }
            break;
        case 2:
            if(isEmpty()==true)
            {
                cout<<"The stack is empty."<<endl;
            }
            else
            {
                cout<<"Pop item is: "<<pop()<<endl;
            }
            break;
        case 3:
            if(isEmpty()==true)
                cout<<"The stack is empty."<<endl;
            else
            {
                cout<<"Teverse the stack item:"<<endl;
                traverse();
            }
            break;
        case 4:
            exit(0);
            break;
        default :
            cout<<"Invalid"<<endl;

        }
    }
    return 0;
}
