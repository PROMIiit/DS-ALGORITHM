#include<bits/stdc++.h>
using namespace std;
#define mimi(a) memset(a,0,sizeof(a))
#define ll long long
#define pb push_back
#define fy first
#define ly second
#define lb "\n"
vector<long long>adj[10005];
vector<long long>adjj[10005];
bool visited[10005];
long long ans=0,mod=(1e9)+7;

void dfs(long long x,long long y)
{

    if(x==y)
    {
        ans++;
        ans=ans%mod;
        visited[x]=false;
        return;

    }
    for(int i=0; i<adj[x].size(); i++)
    {

        if(visited[adj[x][i]]==false)
        {
            visited[adj[x][i]]=true;
            dfs(adj[x][i],y);
        }
    }


}

main()
{
    long long n,m,i,j,a,b,u,v;
    cin>>n>>m;
    for(i=0; i<m; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        //  adj[v].push_back(u);
    }


    for(i=0; i<=n; i++)
        visited[i]=false;

    visited[1]=true;
    dfs(1,n);

    cout<<ans%mod<<endl;

    return 0;
}
