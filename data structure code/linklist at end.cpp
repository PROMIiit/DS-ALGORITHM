#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *head;

void Insert(int x)
{
    node *newnode=new node();
    newnode->data=x;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }

}

void creat()
{
    int n;
    cout<<"How many element: ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        Insert(x);
    }
}
void print()
{
        node *temp=head;
        cout<<"The list is: ";
        while(temp!=NULL)
        {
                cout<<temp->data<<" ";
                temp=temp->next;
        }
        cout<<endl;
}
int main()
{
    creat();
    print();
    return 0;
}
