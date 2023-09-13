#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *head=NULL,*p;

void creat()
{
    int n,i,x;
    cout<<"Size of circular linklist: ";
    cin>>n;
    cin>>x;
    node *newnode=new node();
    newnode->data=x;
    newnode->next=NULL;
    head=newnode;
    p=newnode;
    for(i=1; i<n; i++)
    {
        cin>>x;
        node *newnode=new node();
        newnode->data=x;
        newnode->next=NULL;
        p->next=newnode;
        p=p->next;
    }
    p->next=head;

}

void insert_begin(int item)
{
    cout<<"Inserted element is: "<<item<<endl;;
    //  int item;
    // cin>>item;
    node *newnode=new node();
    newnode->data=item;
    newnode->next=newnode;
    if(head==NULL)
    {
        head=newnode;
        p=newnode;
        return;
    }
    newnode->next=head;
    p->next=newnode;
    head=newnode;
}

void insert_at_any_pos(int item,int n)
{
    if(n==1)
    {
        insert_begin(item);
    }
    else
    {
        node *newnode=new node();
        node *temp=head;
        for(int i=1; i<n-1; i++)
        {
            temp=temp->next;
        }
        newnode->data=item;
        newnode->next=temp->next;
        temp->next=newnode;
    }
}

/*void insert_end()
{
    int item;
    cout<<"Inserted item is: ";
    cin>>item;
    node  *newnode=new node();
    newnode->data=item;
    p->next=newnode;
    newnode->next=head;
    p=newnode;
}
*/
void delete_begin()
{
    if(head==NULL)
    {
        cout<<"The list is empty"<<endl;
        return;
    }
    node *temp=head;
    cout<<"The deleted element is: "<<head->data<<endl;
    if(head->next==head)
        head=NULL;
    else
    {
        head=head->next;
        p->next=head;
        temp=NULL;
        free(temp);
    }
}

/*void delete_end()
{
    /* if(head->next==p){
    head=NULL;
    return;
     }*/
/*  node *temp=head;
  while(temp->next!=p)
  {
      temp=temp->next;
  }
  temp->next=head;
  cout<<"The deleted element is: "<<p->data<<endl;
  p->next=NULL;
  p=temp;
}*/

void delete_any_position(int n)
{
    if(n==1)
    {
        delete_begin();
        return;
    }
    if(head->next==head)
    {
        head=NULL;
        // return;
    }
    else
    {
        node *temp=head;
        for(int i=1; i<n-1; i++)
            temp=temp->next;
        if(temp->next==p)
        {
            temp->next=head;
            cout<<"The deleted element is: "<<p->data<<endl;
            p->next=NULL;
            p=temp;
        }
        else
        {
            node *curr=temp->next;
            cout<<"The deleted item is: "<<curr->data<<endl;
            temp->next=curr->next;
        }
    }
}

void display()
{
    node *temp=head;
    if(head==NULL)
    {
        cout<<"The list is empty"<<endl;
        return;
    }
    while(temp->next!=head)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    cout<<temp->data<<endl;
}


void Median()
{
    node *temp=head,*mid=head;
    if(head==NULL)
    {
        cout<<"The list is empty"<<endl;
        return;
    }
    cout<<"Median: ";
    while(1)
    {
        temp=temp->next;
        if(temp==head)
            break;
        temp=temp->next;
        if(temp==head)
            break;
        mid=mid->next;
    }

    cout<<mid->data<<endl;
}

void Maximum()
{
    int m=0;
    node *temp=head,*mid=head;
    if(head==NULL)
    {
        cout<<"The list is empty"<<endl;
        return;
    }
    while(1)
    {
        m=max(m,temp->data);
        temp=temp->next;
        if(temp==head)
        {
            //  m=max(m,temp->data);
            break;
        }
    }

    cout<<"Maximum: "<<m<<endl;
}

void Minimum()
{
    int m=INT_MAX;
    node *temp=head,*mid=head;
    if(head==NULL)
    {
        cout<<"The list is empty"<<endl;
        return;
    }
    while(1)
    {
        m=min(m,temp->data);
        temp=temp->next;
        if(temp==head)
        {
            //  m=min(m,temp->data);
            break;
        }
    }

    cout<<"Minimum: "<<m<<endl;
}

void Check_Circulation()
{
    int i=1;
    node *temp=head,*mid=head;
    if(head==NULL)
    {
        cout<<"The list is empty"<<endl;
        return;
    }
    cout<<"For nth node: "<<"Data of current node  Address of current node  Address of next node"<<endl;

    while(1)
    {
        cout<<"For "<<i;
        if(i==1)
            cout<<"st ";
        else if(i==2)
            cout<<"nd ";
        else if(i==3)
            cout<<"rd ";
        else
            cout<<"nd ";
        cout<<"node: ";
        cout<<"          "<<temp->data<<"                  "
            <<temp<<"               "<<temp->next<<endl;

        temp=temp->next;
        if(temp==head)
        {
            break;
        }
        i++;
    }

}


int main()
{
    cout<<"1-Creat circular linklist"<<endl;
    cout<<"2-Display"<<endl;
    // cout<<"3-Insert at the beginning"<<endl;
    cout<<"3-Insert at any position"<<endl;
    // cout<<"5-Insert at end"<<endl;
    //  cout<<"4-Delete from begin"<<endl;
    // cout<<"5-Delete from end"<<endl;
    cout<<"4-Delete at any position"<<endl;
    cout<<"5-Median"<<endl;
    cout<<"6-Maximum"<<endl;
    cout<<"7-Minimum"<<endl;
    cout<<"8-Check Circulation"<<endl;
    cout<<"9-Exit"<<endl;
    while(1)
    {
        int choice;
        cout<<"Choice your option: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            creat();
            break;
        case 2:
            display();
            break;
        /* case 3:
             insert_begin();
             break;*/
        case 3:
        {

            int n,item;
            cout<<"Which position you want to insert: ";
            cin>>n;
            cout<<"Which item you want to insert: ";
            cin>>item;
            insert_at_any_pos(item,n);
        }
        break;
        /* case 5:
             insert_end();
             break;*/
        /* case 4:
             delete_begin();
             break;
        /* case 5:
             delete_end();
             break;*/
        case 4:
        {
            int n;
            cout<<"Which position do you want to delete: "<<endl;
            cin>>n;
            delete_any_position(n);
        }
        break;
        case 5:
            Median();
            break;
        case 6:
            Maximum();
            break;
        case 7:
            Minimum();
            break;
        case 8:
            Check_Circulation();
            break;
        case 9:
            exit(1);
            break;
        }
    }
    return 0;
}
