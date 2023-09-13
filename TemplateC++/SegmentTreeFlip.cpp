#include<bits/stdc++.h>
using namespace std;
#define Mx 100009
int treeOn[4*Mx],treeOff[4*Mx],Prop[4*Mx],a[Mx];

//void build(int node,int b,int e)
//{
//    if(b==e)
//    {
//        treeOn[node]=0;
//        treeOff[node]=1;
//        // cout<<node<<" "<<treeOn[node]<<" "<<treeOff[node]<<endl;
//        return;
//    }
//    int mid=(b+e)/2;
//    int left=2*node;
//    int right=(2*node)+1;
//    build(left,b,mid);
//    build(right,mid+1,e);
//    treeOn[node]=treeOn[left]+treeOn[left];
//    treeOff[node]=treeOff[left]+treeOff[right];
//    //  cout<<node<<" "<<treeOn[node]<<" "<<treeOff[node]<<endl;
//}

void update(int node,int b,int e,int l,int r)
{
    if(Prop[node]!=0)
    {
        treeOn[node]=(e-b+1)-treeOn[node];
        if(b!=e)
        {
            Prop[node*2]^=1;
            Prop[(node*2)+1]^=1;
        }
        Prop[node]=0;
    }
    if(l>e || r<b)
        return;
    if(b>=l && e<=r)
    {

        treeOn[node]=(e-b+1)-treeOn[node];
        if(b!=e)
        {
            Prop[node*2]^=1;
            Prop[(node*2)+1]^=1;
        }
        return;

    }
    int mid=(b+e)/2;
    int left=2*node;
    int right=(2*node)+1;

    update(left,b,mid,l,r);
    update(right,mid+1,e,l,r);
    treeOn[node]=treeOn[left]+treeOn[right];
}

int query(int node,int b,int e,int l,int r)
{
     if(Prop[node]!=0)
    {
        treeOn[node]=(e-b+1)-treeOn[node];
        if(b!=e)
        {
            Prop[node*2]^=1;
            Prop[(node*2)+1]^=1;
        }
        Prop[node]=0;
    }
     if(l>e || r<b)
        return 0;
    if(b>=l && e<=r)
    {
        return treeOn[node];
    }
      int mid=(b+e)/2;
    int left=2*node;
    int right=(2*node)+1;
    return query(left,b,mid,l,r)+query(right,mid+1,e,l,r);
}

main()
{
    int n,m,i;
    cin>>n>>m;
   // build(1,1,n);
    while(m--)
    {
        int q,l,r;
        cin>>q>>l>>r;
        if(q==0)
        {
            update(1,1,n,l,r);
        }
        else
        {
              cout<<query(1,1,n,l,r)<<endl;;
        }
    }
    return 0;
}

