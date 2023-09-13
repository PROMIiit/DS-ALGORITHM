#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
node *top;

void push()
{

    int x;
    cin>>x;

    node *temp=new node();

        temp->data=x;
        temp->next=top;
        top=temp;
}

void pop()
{
    if(top==NULL)
    {
        cout<<"The stack is empty"<<endl;
        return;
    }
    node *temp;
    temp=top;
    cout<<"Deleted item is: "<<temp->data<<endl;
    top=top->next;
    free(temp);

}

void display()
{
    if(top==NULL)
    {
        cout<<"The stack is empty"<<endl;
        return ;
    }
    else
    {
        node *temp=top;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;

    }

}

void add()
{
    int n,x;
    cout<<"Number of elements : "<<endl;
    cin>>n;
    cout<<"Push element : "<<endl;

    for(int i=0; i<n; i++)
    {
        push();
    }

}

main()
{

    top=NULL;
    cout<<"1.Push"<<endl;
    cout<<"2.Pop"<<endl;
    cout<<"3.Display Top"<<endl;
    cout<<"4.Display"<<endl;
    cout<<"5.Exit"<<endl;

    while(1)
    {

         int choice;
        cout<<"Choice your option: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            add();
            break;
        case 2:
            pop();
            break;
        case 3:{
                if(top==NULL)
                        cout<<"The top is null"<<endl;
                else
                 cout<<top->data<<endl;
        }
            break;
        case 4:
                display();
                break;
        break;
        case 5:
            exit(1);
            break;
        }

    }

    return 0;
}
