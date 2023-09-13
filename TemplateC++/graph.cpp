#include<bits/stdc++.h>
using namespace std;
int inf=1e5;

class Promi
{
public:
    vector<int>adj[1000];
    int n;
    int m;
    bool visited[1000];
    int dist[1000];
    int parent[1000];
    queue<int>q;
    void create()
    {
        cout<<"Numbers of nodes: ";
        cin>>n;
        cout<<"Numbers of edges: ";
        cin>>m;
        for(int i=1; i<=m; i++)
        {
            int a,b;
            cout<<"Two adjecent nodes: ";
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
    void adjecencyList()
    {
        for(int i=1; i<=n; i++)
        {
            cout<<i<<": ";
            for(int j=0; j<adj[i].size(); j++)
            {
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void bfs(int src)
    {
        dist[src]=0;
        parent[src]=-1;
        q.push(src);
        while(q.size()!=NULL)
        {
            int x=q.front();
            cout<<x<<" ";
            q.pop();
            for(int i=0; i<adj[x].size(); i++)
            {
                int g=adj[x][i];
                if(dist[g]==inf)
                {
                    q.push(g);
                    dist[g]=dist[x]+1;
                    parent[g]=x;
                }
            }
        }
        cout<<endl;

        /// shortest path from source to some vertex

        long long des;
        cout<<"Enter distance: ";
        cin>>des;
        if(dist[des]==inf)
            cout<<"No path\n";
        else
        {
            vector<long long>path;
            for(int i=des; i!=-1; i=parent[i])
            {
                path.push_back(i);
            }
            reverse(path.begin(),path.end());
            for(int i=0; i<path.size(); i++)
            {
                cout<<path[i]<<" ";
            }
            cout<<endl;

        }

    }

    void dfs(int x)
    {
        if(visited[x]==true)
            return;
        visited[x]=true;
        cout<<x<<" ";
        for(int i=0; i<adj[x].size(); i++)
        {
            dfs(adj[x][i]);
        }
    }
};

int main()
{
    cout<<"1.Graph Create"<<endl<<"2.Print Adjecency List"<<endl<<"3.BFS"<<endl;
    cout<<"4.DFS"<<endl<<endl;
    Promi p;
    while(1)
    {
        int choice;
        cout<<"Enter your choice: ";
        cin>>choice;
        if(choice==1)
        {
            p.create();
        }
        if(choice==2)
        {
            p.adjecencyList();
        }
        if(choice==3)
        {
            int src;
            for(int i=1; i<=p.n; i++)
            {
                p.dist[i]=inf;
            }
            cout<<"Enter starting vertex: ";
            cin>>src;
            p.bfs(src);
            cout<<endl;
            cout<<"Distance from starting vertex: ";
            for(int i=1; i<=p.n; i++)
            {
                cout<<i<<" "<<p.dist[i]<<endl;
            }
            cout<<endl;
        }
        if(choice==4)
        {
            int src;
            memset(p.visited,false,sizeof(p.visited));
            p.dfs(1);
            cout<<endl;
        }
    }
}
