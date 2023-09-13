
#include<bits/stdc++.h>
using namespace std;
#define hi ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mimi(a) memset(a,0,sizeof(a))
#define ll long long
#define pb push_back
#define fy first
#define ly second
#define lb "\n"

struct cmp
{
    bool operator()(const pair<int, int>& a,
                    const pair<int, int>& b)
    {
        if (a.first != b.first)
            return (a.first < b.first);
        else
            return (a.second > b.second);
    }
};

main()
{
    hi;
    long long t,n,i,j,x,y,k;
    cin>>t;
    while(t--)
    {
        cin>>n;
        multiset<pair<long long,long long>,cmp>v;
        long long a[n+9],b[n+9],ans=0,f=0;
        for(i=0; i<n; i++)
        {
            cin>>a[i]>>b[i];
            v.insert({a[i],b[i]});
        }
        x=0;
        for(auto it=v.begin(); it!=v.end(); it++)
        {
            cout<<(it->fy)<<" "<<(it->ly)<<"\n";

        }


    }
    return 0;
}
