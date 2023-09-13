#include<bits/stdc++.h>
using namespace std;

struct node
{
    int x;
    node *y;
};
struct node *head=NULL,*tail;
void creatnode(int item)
{
    struct node *p;
    p=new node;
    // node *p=(node *)malloc(sizeof(node));
    p->x=item;
    p->y=NULL;
    if(head==NULL)
    {
        head=p;
        tail=p;
        p=NULL;
    }
    else
    {
        tail->y=p;
        tail=p;
    }
}
void traverse()
{
    struct node *t;
    t=head;
    while(t!=NULL)
    {
        cout<<t->x<<" ";
        t=t->y;
    }
}

void insertnode(int item)
{

}

int main()
{
    cout<<"1-Creat link list"<<endl;
    cout<<"2-Insert Node"<<endl;
    cout<<"3-Delete Node"<<endl;
    cout<<"4-Traverse Linklist"<<endl;
    cout<<"5-Exit"<<endl;
    while(1)
    {
        int n;
        cout<<"Choice your option: ";
        cin>>n;
        switch(n)
        {
        case 1:
        {
            int a,i,item;
            cout<<"Choose your linklist size: ";
            cin>>a;
            for(i=1; i<=a; i++)
            {
                cout<<i;
                if(i==1)
                    cout<<"st ";
                else if(i==2)
                    cout<<"nd ";
                else if(i==3)
                    cout<<"rd ";
                else
                    cout<<"th ";
                cout<<"item is: ";
                cin>>item;
                creatnode(item);
            }
        }
        break;
        case 2:
        {
            cout<<"Traverse the linklist:"<<endl;
            traverse();
            cout<<endl;
        }
        break;

        }
    }
    return 0;
}
