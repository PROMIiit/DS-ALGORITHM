#include<bits/stdc++.h>
using namespace std;

class BinaryTree
{
public:
    int a,b,c;
    struct node
    {
        int data;
        node *left;
        node *right;
    };
    void d()
    {
        cout<<"Input root node: ";
        cin>>a;
        cout<<"Input left child: ";
        cin>>b;
        cout<<"Input right child: ";
        cin>>c;
        node *p=new node();
        node *l=new node();
        node *r=new node();
        p->data=a;
        l->data=b;
        r->data=c;
        p->left=l;
        p->right=r;
        l->left=NULL;
        l->right=NULL;
        r->left=NULL;
        r->right=NULL;

        cout<<"Parent "<<p->data<<endl;
        cout<<"Left Child "<<l->data<<endl;
        cout<<"Right Child "<<r->data<<endl;
    }
};

int main()
{
    BinaryTree A;
    A.d();
    return 0;
}
