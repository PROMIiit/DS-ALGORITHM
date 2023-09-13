#include<bits/stdc++.h>
using namespace std;

#define Mx 100005
long long tree[4*Mx],Prop[4*Mx],a[Mx];

void build(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=a[b];
        return;
    }
    int left=2*node;
    int right=(2*node)+1;
    int mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}

void update(int node,int b,int e,int l,int r,int Value)
{
    if(l>e || r<b)
        return;
    if(b>=l && e<=r)
    {
        tree[node]+=(e-b+1)*Value;
        Prop[node]+=Value;
        return;
    }
    int left=node*2;
    int right=(node*2)+1;
    int mid=(b+e)/2;
    update(left,b,mid,l,r,Value);
    update(right,mid+1,e,l,r,Value);
    tree[node]=tree[left]+tree[right]+(e-b+1)*Prop[node];
}

long long query(int node,int b,int e,int l,int r,long long carry)
{
    if(l>e || r<b)
        return 0;
    if(b>=l && e<=r)
    {
        return tree[node]+(e-b+1)*carry;
    }
    int left=node*2;
    int right=(node*2)+1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,l,r,carry+Prop[node]);
    int p2=query(right,mid+1,e,l,r,carry+Prop[node]);
    return p1+p2;
}

main()
{
    int n,q,i;
    cin>>n>>q;
    for(i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    build(1,1,n);

    while(q--)
    {
        int x,l,r,Value;
        cin>>x;
        if(x==1) //update range
        {
            cin>>l>>r>>Value;
            update(1,1,n,l,r,Value);
        }
        else  //query
        {
            cin>>l>>r;
            cout<<query(1,1,n,l,r,0)<<endl;
        }
    }
    return 0;
}
