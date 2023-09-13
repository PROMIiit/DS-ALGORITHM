#include<bits/stdc++.h>
using namespace std;

#define q_max 10
int Queue[q_max];
int Front=-1;
int rear=-1;
int Count=0;

bool IsFull()
{
    if(Count==q_max)
        return true;
    else
        return false;
}

bool IsEmpty()
{
    if(Count==0)
        return true;
    else
        return false;
}

void enqueue(int item)
{
    if(IsFull())
    {
        cout<<"The queue is full"<<endl;
    }
    if(Count==0)
        Front=0,rear=0;
    else if(rear==q_max-1)
        rear=0;
    else
        rear=rear+1;
    Queue[rear]=item;
    Count++;
}

int dequeue()
{
    if(IsEmpty())
    {
        cout<<"The queue is empty"<<endl;
        return -1;
    }
    int item=Queue[Front];
    Count--;
    if(Count==0)
        Front=-1,rear=-1;
    else if(Front==q_max-1)
        Front=0;
    else
        Front=Front+1;
    return item;
}

void traverse()
{
    int i=Front,x=Count,x1=0,y=0;
    while(1)
    {
        if(x==0)
        {
            cout<<"Queue is empty"<<endl;
            cout<<"rear is -1"<<endl;
            cout<<"Front is -1"<<endl;
            return;
        }
        if(i==Front)
            y=Queue[i];
        if(i==rear)
            x1=Queue[i];

        cout<<Queue[i]<<endl;
        if(i==rear)
            break;
        else if(Front==q_max-1)
            i=0;
        else
            i++;
        x--;
    }
    cout<<"rear is "<<x1<<endl;
    cout<<"Front is "<<y<<endl;
}


int main()
{
    cout<<"1.Equeue"<<endl;
    cout<<"2.Dequeue"<<endl;
    cout<<"3. Display"<<endl;
    cout<<"4. Exit"<<endl;
    int choice,item;
    while(1)
    {
        cout<<"Choice:";
        cin>>choice;
        switch(choice)
        {
        case 1:
        {
            cout<<"Put an item: ";
            cin>>item;
            enqueue(item);
        }
        break;
        case 2:
        {
            int t=dequeue();
            cout<<"The deleted items are: "<<t<<endl;
        }
        break;
        case 3:
            cout<<"Traverse: "<<endl;
            traverse();
            break;
        case 4:
            exit(0);
            break;
        }
    }
    return 0;
}


