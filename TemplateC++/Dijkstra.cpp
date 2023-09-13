#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define xx first
#define yy second
int tc=0;
void solve()
{
    tc++;
    long long i, j, k, l, m,  p, q,n;
    cin>>n>>m;
    long long dis[n+6];
    for(i=0; i<=n; i++)dis[i]=100000000000000;
    bool f[n+6];
    vector<pair<long long,long long>>v[n+5];
    for(i=0; i<m; i++)
    {
        cin>>j>>k>>l;
        v[j].pb({l,k});
        v[k].pb({l,j});
    }
  priority_queue < pair<long long, long long>, vector < pair < long long, long long >> , greater<pair<long long, long long>> > qq;
    qq.push({0,1});
    dis[1]=0;
   long long path[n+5];
    for(i=1; i<=n; i++)path[i]=-1;
    while(!qq.empty())
    {
        pair<long long,long long>a=qq.top();
        qq.pop();
        for(i=0; i<v[a.yy].size(); i++)
        {
            pair<long long,long long>b=v[a.yy][i];
            if(dis[b.yy]>dis[a.yy]+b.xx)
            {
                dis[b.yy]=dis[a.yy]+b.xx;
                path[b.yy]=a.yy;
                qq.push({(dis[a.yy]+b.yy),b.yy});
            }
        }
    }

    if(dis[n]>=100000000000000)cout<<"-1"<<endl;
    else
    {
        vector<int>v;
        v.pb(n);
        for(i=n; i>=1; i=path[i])
        {
            v.pb(path[i]);
        }
        reverse(v.begin(),v.end());
        for(i=1; i<v.size(); i++)cout<<v[i]<<" ";
        cout<<endl;
    }
}


main()
{
  solve();
    return 0;
}

/*
*/
