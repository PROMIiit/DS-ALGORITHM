#include<bits/stdc++.h>
using namespace std;
#define Mx 100009
#define hi ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
long long tree[4*Mx],a[Mx];

void build(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=a[b];
        cout<<node<<" "<<tree[node]<<endl;
        return;
    }
    int mid=(b+e)/2;
    int left=node*2;
    int right=(node*2)+1;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}

void update(int node,int b,int e,int l,long long value)
{
    if(l>e || l<b)
        return;
    if(b>=l && e<=l)
    {
        tree[node]=value;
        return;
    }
    int mid=(b+e)/2;
    int left=node*2;
    int right=(node*2)+1;
    update(left,b,mid,l,value);
    update(right,mid+1,e,l,value);
    tree[node]=tree[left]+tree[right];
}

long long query(int node,int b,int e,int l,int r)
{
    if(l>e || r<b)
        return 0;

    if(b>=l && e<=r)
    {
        return tree[node];
    }
    int mid=(b+e)/2;
    int left=node*2;
    int right=(node*2)+1;;
    return query(left,b,mid,l,r)+query(right,mid+1,e,l,r);
}

main()
{
    hi;
    int n,q,i,l,r;
    cin>>n>>q;

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    build(1,0,n-1);
    for(int i=1; i<=4*n; i++)
    {
        cout<<tree[i]<<endl;
    }
    cout<<endl;
    while(q--)
    {
        int ll;
        cin>>ll;
        if(ll==1)
        {
            long long value;
            cin>>l>>value;
            a[l]=value;
            update(1,0,n-1,l,value);
        }
        else
        {
            cin>>l>>r;
            r-=1;
            long long ans=query(1,0,n-1,l,r);
            cout<<ans<<"\n";

        }
    }
    return 0;
}
