#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
node *Front=NULL,*Rear=NULL;

bool IsEmpty()
{
    if(Front==NULL && Rear==NULL)
        return true;
    else
        return false;
}

void enqueue(int item)
{
    node *temp=new node();
    temp->data=item;
    temp->next=NULL;
    if(Front==NULL)
    {
        Front=temp;
        Rear=temp;
    }
    else
    {
        Rear->next=temp;
        Rear=temp;
    }
}

void dequeue()
{
    if(IsEmpty())
    {
        cout<<"The queue is empty"<<endl;
    }
    else
    {
        if(Front==Rear)
        {
            cout<<"The dequeue item is "<<Front->data<<endl;
            free(Front);
            Front=NULL;
            Rear=NULL;
        }
        else
        {
            node *temp=Front;
            cout<<"The dequeue item is: "<<Front->data<<endl;
            Front=Front->next;
            free(temp);
        }
    }
}

void display()
{
    if(IsEmpty())
    {
        cout<<"The queue is empty"<<endl;
    }
    else
    {
        node *temp;
        temp=Front;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
}

int main()
{
    cout<<"1.Enqueue"<<endl;
    cout<<"2.Dequeue"<<endl;
    cout<<"3.Display"<<endl;
    cout<<"4.Display Front"<<endl;
    cout<<"5.Display Rear"<<endl;
    cout<<"6.Exit"<<endl;
    int choice,item;
    while(1)
    {
        cout<<"Choice:";
        cin>>choice;
        switch(choice)
        {
        case 1:
        {
            int n;
            cout<<"How many element you want to enqueue: ";
            cin>>n;
            while(n--)
            {
              //  cout<<"Put an item: ";
                cin>>item;
                enqueue(item);
            }
        }
        break;
        case 2:
        {
            dequeue();
        }
        break;
        case 3:
        {
            cout<<"Display: "<<endl;
            display();
            cout<<endl;
        }
        break;
        case 4:{
                if(Front==NULL)
                        cout<<"Front is Null"<<endl;
                else
                cout<<"Front is: "<<Front->data<<endl;
        }
                break;
        case 5:{
                if(Rear==NULL)
                        cout<<"Rear is Null"<<endl;
                else
                cout<<"Rear is: "<<Rear->data<<endl;
        }
        break;
        case 6:
            exit(0);
            break;
        }
    }
    return 0;
}
