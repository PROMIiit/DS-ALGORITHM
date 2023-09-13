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

void insertion(int item,int pos)
{
    node *newnode=new node;
    newnode->data=item;
    newnode->next=NULL;
    if(pos==1)
    {
        newnode->next=head;
        head=newnode;
        //   return;
    }
    else
    {
        node *temp=new node();
        temp=head;
        for(int i=1; i<pos-1; i++)
        {
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}

void Delete()
{
          int n;
    node *pre=head;
    if(pre==NULL)
    {
            cout<<"The linklist is empty"<<endl;
            return;
    }
    cout<<"which position do you want to delete: ";
            cin>>n;
    if(n==1)
    {
            cout<<"The deleted item is: "<<pre->data<<endl;
            pre=pre->next;
            head=pre;
            return;
    }
    for(int i=1; i<n-1; i++)
        pre=pre->next;
    node *curr=pre->next;
    //   cout<<"Deleted item is "<<curr->data<<endl;
    pre->next=curr->next;
    free(curr);


}

void print()
{
       if(head==NULL){
             cout<<"The list is empty"<<endl;
             return;
       }
    // else{
    node *temp=head;
    cout<<"The list are: ";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    //  }
}

void Maximum()
{
        int m=0;
       if(head==NULL){
             cout<<"The list is empty"<<endl;
             return;
       }
    node *temp=head;
    while(temp!=NULL)
    {
           // m=max(m,temp->data);
           if(temp->data=m)
           {
                   m=temp->data;
           }
        temp=temp->next;
    }
    cout<<"Maximum= "<<m<<endl;
}

void Minimum()
{
        int m=INT_MAX;
       if(head==NULL){
             cout<<"The list is empty"<<endl;
             return;
       }
    node *temp=head;
    while(temp!=NULL)
    {
            if(temp->data<=m)
            {
                    m=temp->data;
            }
           // m=min(m,temp->data);
        temp=temp->next;
    }
    cout<<"Minimum= "<<m<<endl;
}

void Median()
{
         if(head==NULL){
             cout<<"The list is empty"<<endl;
             return;
       }
    // else{
    node *temp=head,*mid=head;
    cout<<"The median is: ";
    while(1)
    {
        temp=temp->next;
        if(temp==NULL)
                break;
        temp=temp->next;
        if(temp==NULL)
                break;
        mid=mid->next;
    }
    cout<<mid->data<<endl;;
}

int main()
{
    cout<<"1-Insertion"<<endl;
    cout<<"2-print"<<endl;
    cout<<"3-delete"<<endl;
    cout<<"4-Creat"<<endl;
    cout<<"5-Maximum"<<endl;
    cout<<"6-Minimum"<<endl;
    cout<<"7-Median"<<endl;
    cout<<"8-exit"<<endl;
    head=NULL;
    while(1)
    {
        int choice;
        cout<<"Choice your option: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
        {
            int item,pos;
            cout<<"Insertion item: ";
            cin>>item;
            cout<<"Insertion position: ";
            cin>>pos;
            insertion(item,pos);
        }
        break;
        case 2:
        {
            print();
        }
        break;
        case 3:
        {
            Delete();
        }
        break;
        case 4:
                {
                        creat();
                }
                break;

        case 5:
                Maximum();
                break;
        case 6:
                Minimum();
                break;
        case 7:
                Median();
                break;
        case 8:
            exit(1);
            break;
        }
    }
    return 0;
}
