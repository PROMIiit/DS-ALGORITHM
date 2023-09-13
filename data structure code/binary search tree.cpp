#include<bits/stdc++.h>
using namespace  std;

int p=0;

struct node
{
    int data;
    node *left;
    node *right;
};

node *root=NULL;

void create(int item)
{
    node *newnode=new node();
    newnode->data=item;
    newnode->left=NULL;
    newnode->right=NULL;
    if(root==NULL)
    {
        root=newnode;
        return;
    }
    node *temp=root;
    while(1)
    {
        if(item==temp->data)
        {
            cout<<item<<" is already in bst.So it is not inserted again."<<endl;
            return;
        }
        else if(item>temp->data)
        {
            if(temp->right==NULL)
            {
                temp->right=newnode;
                return;
            }
            else
                temp=temp->right;
        }
        else
        {
            if(temp->left==NULL)
            {
                temp->left=newnode;
                return;
            }
            else
                temp=temp->left;
        }
    }
}

void insertion(int item)
{
    node *newnode=new node();
    newnode->data=item;
    newnode->left=NULL;
    newnode->right=NULL;
    if(root==NULL)
    {
        root=newnode;
        cout<<"The node is successfully inserted in the root."<<endl;
        return;
    }
    node *temp=root;
    while(1)
    {
        if(item==temp->data)
        {
            cout<<item<<" is already in bst."<<endl;
            return;
        }
        else if(item>temp->data)
        {
            if(temp->right==NULL)
            {
                temp->right=newnode;
                cout<<"The node is successfully inserted."<<endl;
                return;
            }
            else
                temp=temp->right;
        }
        else
        {
            if(temp->left==NULL)
            {
                temp->left=newnode;
                cout<<"The node is successfully inserted."<<endl;
                return;
            }
            else
                temp=temp->left;
        }
    }
}

void inorder(node *temp)
{
    if(root==NULL)
    {
        cout<<"bst is empty"<<endl;
        return;
    }
    if(temp==NULL)
        return;
    inorder(temp->left);
    cout<<temp->data<<" ";
    inorder(temp->right);
}

void display(node *temp,int level)
{
    if(temp==NULL)
        return;
    display(temp->right,level+1);
    cout<<endl;
    if(temp==root)
    {
        cout<<"Root-->  ";
    }
    else
    {
        for(int i=0; i<level; i++)
        {
            cout<<"       ";
        }
    }
    cout<<temp->data;
    display(temp->left,level+1);
    return;
}

void predecessor(node *temp,int item)
{
    int k=0;
    if(root==NULL)
    {
        cout<<"Invalid Predecessor"<<endl;
    }
    while(temp!=NULL)
    {
        if(temp->data==item)
        {
            p=1;
            if(temp->left!=NULL)
            {
                temp=temp->left;
                while(temp->right!=NULL)
                    temp=temp->right;
                cout<<temp->data<<endl;
                return;
            }
            else if(k>0)
            {
                cout<<k<<endl;
                return;
            }
            else
            {
                cout<<"Invalid Predecessor"<<endl;
                return;
            }
        }
        else if(item>temp->data)
        {
            k=temp->data;
            temp=temp->right;
        }
        else
        {
            temp=temp->left;
        }
    }
}

void successor(node *temp,int item)
{
    int k=0;
    if(root==NULL)
    {
        cout<<"Invalid successor"<<endl;
        return;
    }
    while(temp!=NULL)
    {
        if(item==temp->data)
        {
            p=1;
            if(temp->right!=NULL)
            {
                temp=temp->right;
                while(temp->left!=NULL)
                {
                    temp=temp->left;
                }
                cout<<temp->data<<endl;
                return;
            }
            else if(k>0)
            {
                cout<<k<<endl;
                return;
            }
            else
            {
                cout<<"Invalid successor"<<endl;
                return;
            }
        }
        else if(item<temp->data)
        {
            k=temp->data;
            temp=temp->left;
        }
        else
            temp=temp->right;
    }
}

node *min_data(node* curr)
{
    while(curr->left!=NULL)
    {
        curr=curr->left;
    }
    return curr;
}

void Delete(int item)
{
    if(root==NULL)
        return;
    node *temp=root;
    node *parent=NULL;
    while(temp!=NULL && temp->data!=item)
    {
        parent=temp;
        if(item>temp->data)
            temp=temp->right;
        else
            temp=temp->left;
    }
    if(temp->left==NULL && temp->right==NULL)
    {
        if(temp==root)
        {
            root=NULL;
        }
        else
        {
            if(parent->left==temp)
            {
                parent->left=NULL;
            }
            else
                parent->right=NULL;
        }
    }
    else if(temp->left!=NULL && temp->right==NULL)
    {
        if(temp==root)
        {
            node *leftchild=temp->left;
            root=leftchild;
            leftchild=NULL;
            return;
        }
        if(parent->left==temp)
        {
            node *leftchild=temp->left;
            parent->left=leftchild;
            leftchild=NULL;
            return;
        }
        else
        {
            node *leftchild=temp->left;
            parent->right=leftchild;
            leftchild=NULL;
            return;
        }
    }
    else if(temp->left==NULL && temp->right!=NULL)
    {
        if(temp==root)
        {
            node *rightchild=temp->right;
            root=rightchild;
            rightchild=NULL;
            return;
        }
        if(parent->left==temp)
        {
            node *rightchild=temp->right;
            parent->left=rightchild;
            rightchild=NULL;
            return;
        }
        else
        {
            node *rightchild=temp->right;
            parent->right=rightchild;
            rightchild=NULL;
            return;
        }
    }
    else if(temp->left!=NULL && temp->right!=NULL)
    {
        node *search_min=min_data(temp->right);
        int value=search_min->data;
        Delete(search_min->data);
        temp->data=value;
    }
    return;
}

int main()
{
    cout<<"1.Create"<<endl<<"2.Inorder Traversal"<<endl<<"3.Insertion"<<endl
        <<"4.Display"<<endl<<"5.Predecessor"<<endl<<"6.Successor"<<endl<<"7.Delete"<<endl<<endl;
    while(1)
    {
        int choice;
        cout<<"Choice your option: ";
        cin>>choice;
        if(choice==1)
        {
            int n,x,i;
            cout<<"Element number: ";
            cin>>n;
            for(i=0; i<n; i++)
            {
                cin>>x;
                create(x);
            }
        }

        if(choice==2)
        {
            inorder(root);
            cout<<endl;
        }
        if(choice==3)
        {
            int x;
            cout<<"inserted element: ";
            cin>>x;
            insertion(x);
        }
        if(choice==4)
        {
            display(root,1);
        }
        if(choice==5)
        {
            p=0;
            int item;
            cout<<"Enter the value: ";
            cin>>item;
            predecessor(root,item);
            if(p==0)
                cout<<"Invalid predecessor"<<endl;
        }
        if(choice==6)
        {
            p=0;
            int item;
            cout<<"Enter the value: ";
            cin>>item;
            successor(root,item);
            if(p==0)
                cout<<"Invalid successor"<<endl;
        }
        if(choice==7)
        {
            int item;
            cout<<"Enter the value to delete: ";
            cin>>item;
            Delete(item);
        }
        cout<<endl;
    }
    return 0;
}
