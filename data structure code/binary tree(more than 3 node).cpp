#include<bits/stdc++.h>
using namespace std;
int p=0,k=0,call=0,a[10000]= {0},kk=0;


struct node
{
    int data;
    node *left;
    node *right;
};

node *create()
{
    int x;
    node *newnode= new node();
    cout<<"Enter node: (Enter -1 for no node: )"<<endl;;
    cin>>x;
    if(x==-1)
        return 0;
    newnode->data=x;
    cout<<"Enter left child of "<<x<<" : ";
    newnode->left=create();
    cout<<"Enter right child of "<<x<<" : ";
    newnode->right=create();
    return newnode;
}


void left(node *temp)
{
    if(temp->left==NULL && temp->right==NULL)
    {
        a[k]=-1;
        k++;
        a[k]=-1;
        k++;
        return;
    }
    if(temp->left!=NULL && temp->right!=NULL)
    {
        a[k]=temp->left->data;
        k++;
        a[k]=temp->right->data;
        k++;
        //  cout<<"     "<<temp->data<<"     "<<endl;
        // cout<<temp->left->data<<"          "<<temp->right->data<<"     ";
    }
    if(temp->right==NULL && temp->left!=NULL)
    {
        a[k]=temp->left->data;
        k++;
        a[k]=-1;
        k++;
        //  cout<<"     "<<temp->data<<"     "<<endl;
        //    cout<<"          "<<temp->left->data<<"     ";
    }
    if(temp->right!=NULL && temp->left==NULL)
    {
        a[k]=-1;
        k++;
        a[k]=temp->right->data;
        k++;
        //  cout<<"     "<<temp->data<<"     "<<endl;
        //   cout<<temp->right->data<<"     ";
    }
}


void display(node *temp)
{
    if(temp==NULL)
    {
        a[k]=-1;
        k++;
        a[k]=-1;
        k++;
        return;
    }
    left(temp);
    if(kk==1)
    {
        kk=0;
        return;
    }
    kk++;
    display(temp->left);
    display(temp->right);
    cout<<endl;
    return;
}

void inorder(node *r)
{
    node *temp=r;
    if(temp==NULL)
    {
        return;
    }
    inorder(temp->left);
    cout<<temp->data<<" ";
    inorder(temp->right);
    return;
}

void display1(node *r)
{
    node *temp=r;
    if(temp==NULL)
        return ;
    if(temp->left==NULL && temp->right==NULL)
        return;
    if(temp->left!=NULL && temp->right!=NULL)
    {
        cout<<"     "<<temp->data<<"     "<<endl;
        cout<<temp->left->data<<"          "<<temp->right->data<<endl;
    }
    if(temp->right!=NULL && temp->left==NULL)
    {
        cout<<"     "<<temp->data<<"     "<<endl;
        cout<<"          "<<temp->right->data<<endl;
    }
    if(temp->right!=NULL && temp->left==NULL)
    {
        cout<<"     "<<temp->data<<"     "<<endl;
        cout<<temp->left->data<<endl;
    }
    cout<<endl;
    display1(temp->left);
    display1(temp->right);

    return;
}


int in(node *r,int item)
{
    node *temp=r;
    if(temp==NULL)
    {
        return 0;
    }
    in(temp->left,item);
    if(temp->data==item && p==0)
    {
        int l;
        // cout<<item<<endl;
        cout<<"Enter 1 if you want to insert left child"<<endl;
        cout<<"Enter 2 if you want to insert right child"<<endl;
        cin>>l;
        if(l==1)
        {
            if(temp->left==NULL)
            {
                p=1;
                int x;
                cout<<"Inserted item is: ";
                cin>>x;
                node *newnode=new node();
                temp->left=newnode;
                newnode->data=x;
                newnode->left=NULL;
                newnode->right=NULL;
            }
            else
            {
                p=1;
                cout<<"This node isnot empty"<<endl;
            }
        }
        if(l==2)
        {
            if(temp->right==NULL)
            {
                p=1;
                int x;
                cout<<"Inserted item is: ";
                cin>>x;
                node *newnode=new node();
                temp->right=newnode;
                newnode->data=x;
                newnode->left=NULL;
                newnode->right=NULL;
            }
            else
            {
                p=1;
                cout<<"This node isnot empty"<<endl;
            }
        }
    }
//        cout<<temp->data<<" ";
    in(temp->right,item);
    return 0;
}



main()
{
    node *root=NULL;
    cout<<"1.Creat"<<endl;
    cout<<"2.Inorder"<<endl;
    cout<<"3.Insert"<<endl;
    cout<<"4.Display 1"<<endl;
    cout<<"5.Display 2"<<endl<<endl;
    while(1)
    {
        int choice;
        cout<<"Choice your option: ";
        cin>>choice;
        if(choice==1)
            root=create();
        if(choice==2)
        {
            if(root==NULL)
                cout<<"Empty tree"<<endl;
            else
            {
                inorder(root);
                cout<<endl;
            }
        }
        if(choice==3)
        {
            p=0;
            int item;
            cout<<"Select parent node for insertion: "<<endl;
            cin>>item;
            in(root,item);
            //  cout<<p<<endl;
            if(p==0)
                cout<<"Invalid parent"<<endl;
        }
        if(choice==4)
        {
            display1(root);
        }
        if(choice==5)
        {
            int q=0,c=0,cc=0;
            a[k]=root->data;
            k++;
            display(root);
            for(int i=0; i<k; i++)
            {

                //  cout<<a[i]<<" ";
                q++;
                if(q==pow(2,c))
                {
                    // cout<<endl;
                    q=0;
                    c++;
                }
            }
            q=0;
            c=c;
            // cout<<c<<endl;
            for(int g=pow(2,c); g>=0; g--)
                cout<<" ";
            c--;
            for(int i=0; i<k; i++)
            {
                if(a[i]!=-1)
                    cout<<a[i];

                for(int g=pow(2,c+2)-1; g>=0; g--)
                    cout<<" ";
                q++;
                if(q==pow(2,cc))
                {
                    cout<<endl;
                    for(int g=pow(2,c); g>=0; g--)
                        cout<<" ";
                    q=0;
                    cc++;
                    c--;
                }
            }
            cout<<endl;
        }
    }
    return 0;
}
