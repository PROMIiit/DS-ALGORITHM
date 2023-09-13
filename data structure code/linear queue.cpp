#include <bits/stdc++.h>
using namespace std;

int Queue[100], n = 100, Front = - 1, rear = - 1;

void Insert()
{
    int val;
    if (rear == n - 1)
        cout<<"Queue Overflow"<<endl;
    else
    {
        if (Front == - 1)
            Front = 0;
        cout<<"Insert the element in queue : "<<endl;
        cin>>val;
        rear++;
        Queue[rear] = val;
    }
}
void Delete()
{
    if (Front == - 1 || Front > rear)
    {
        cout<<"Queue Underflow ";
        return ;
    }
    else
    {
        cout<<"Element deleted from queue is : "<< Queue[Front] <<endl;
        Front++;
    }
}
void Display()
{
    if (Front == - 1 || Front>rear)
    {
        cout<<"Queue is empty"<<endl;
        ]
        else
        {
            cout<<"Queue elements are : ";
            for (int i = Front; i <= rear; i++)
                cout<<Queue[i]<<" ";
            cout<<endl;
        }
    }
    int main()
    {
        int ch;
        cout<<"1.Equeue"<<endl;
        cout<<"2.Dequeue"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"4. Exit"<<endl;
        while(1)
        {
            cout<<"Enter your choice : "<<endl;
            cin>>ch;
            switch (ch)
            {
            case 1:
                Insert();
                break;
            case 2:
                Delete();
                break;
            case 3:
                Display();
                break;
            case 4:
                cout<<"Exit"<<endl;
                break;
            default:
                cout<<"Invalid choice"<<endl;
            }
        }
        return 0;
    }
