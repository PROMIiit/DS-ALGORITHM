#include<bits/stdc++.h>
using namespace std;
int tree[4*100005],a[100005],mn,n,mx;

void build(int node,int b,int e,int c)
{
    if(b==e)
    {
        tree[node]=a[b];
        mx=max(mx,tree[node]);
        //    cout<<tree[node]<<" "<<node<<endl;
        return ;
    }




    build(node+c,b,e-1,c+1);
    build(node+c+1,b+1,e,c+1);


    tree[node]=min(tree[node+c],tree[node+c+1]);
    mx=max(mx,tree[node]*(e-b+1));


}

main()
{
    int t;
    cin>>t;
    for(int z=1; z<=t; z++)
    {
        cin>>n;
        mn=INT_MAX,mx=0;;
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
        }
        build(1,1,n,1);

        cout<<"Case "<<z<<": "<<mx<<endl;
    }
    return 0;
}
