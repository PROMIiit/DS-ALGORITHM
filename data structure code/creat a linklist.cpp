#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *head;

void Insert(int x)
{
        struct node *newnode=new node();
        newnode->data=x;
        newnode->next=head;
        head=newnode;
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

creat()
{
        head=NULL;
        cout<<"How many numbers?"<<endl;
        int n,i,x;
        cin>>n;
        for(i=0;i<n;i++)
        {
                cout<<"Enter the number: ";
                cin>>x;
                Insert(x);
            //    print();
        }
}

int main()
{
        creat();
        print();
    return 0;
}
