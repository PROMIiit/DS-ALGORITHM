#include<bits/stdc++.h>
using namespace std;
#define hi ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mimi(a) memset(a,0,sizeof(a))
#define ll long long
#define pb push_back
#define fy first
#define ly second
#define lb "\n"

bool cmp(const pair<long long,long long>i,const pair<long long,long long>j)
{
    if(i.first==j.first)
        return i.second>j.second;
    return i.first<j.first;
}



main()
{

    long long t,i,j,x=1,y,n,k;
    cin>>t;

    while(t--)
    {
        cin>>n;
        long long a[n+1],b[n+1],mx=0,p=0;
        map<long long,long long>m;
        vector<pair<long long,long long>>v;
        for(i=0; i<n; i++)
        {
            cin>>a[i]>>b[i];
            v.push_back({a[i],1});
            v.push_back({b[i],-1});
        }
        sort(v.begin(),v.end(),cmp);
        for(i=0;i<v.size();i++)
        {
            cout<<v[i].fy<<" "<<v[i].ly<<"\n";
        }
        for(i=0; i<v.size(); i++)
        {
            //cout<<v[i].fy<<" "<<v[i].ly<<endl;
            p+=v[i].second;
            mx=max(mx,p);

        }


        cout<<"Case "<<x<<": "<<mx<<endl;

        x++;
    }
    return 0;
}

