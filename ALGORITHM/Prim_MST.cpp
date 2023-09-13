#include <bits/stdc++.h>
using namespace std;
int n;
int G[200][200];

void print(int parent[])
{
    int x = 0;
    cout << "Edges\tWeight\n";

    for (int i = 1; i < n; i++)
    {
        cout << parent[i] << " - " << i << "\t" << G[i][parent[i]] << endl;
        x += G[i][parent[i]];
    }
    cout << "Total Cost: " << x << endl;
}

int minKey(int key[], bool check[])
{
    int mn = INT_MAX;
    int mn_idx;

    for (int i = 0; i < n; i++)
    {
        if (check[i] == false && key[i] < mn)
        {
            mn = key[i];
            mn_idx = i;
        }
    }
    return mn_idx;
}

void prim()
{
    int parent[n];
    int key[n];
    bool check[n];
    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int i = 0; i < n - 1; i++)
    {
        int u = minKey(key, check);
        check[u] = true;
        for (int j = 0; j < n; j++)
        {
            if (G[u][j] && check[j] == false && G[u][j] < key[j])
            {
                parent[j] = u;
                key[j] = G[u][j];
            }
        }
    }
    print(parent);
}

main()
{
    int m, u, v, w;
    cout << "Numbers of nodes: ";
    cin >> n;
    cout << "Numbers of edges: ";
    cin >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            G[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++)
    {
        cout << "Two adjecent nodes & thier weights: ";
        cin >> u >> v >> w;
       // u--,v--;
        G[u][v] = w;
        G[v][u] = w;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
    prim();
    return 0;
}

/*
5 7
0 1 2
0 3 6
1 2 3
1 3 8
1 4 5
2 4 7
3 4 9

*/
