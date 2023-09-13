#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int main()
{
    long long t,n,i,j,k;
    cin>>t;
    while(t--)
    {
        long long mx=0;
        cin>>n>>k;
        string a,b;
        map<long long,long long>m;
        vector<long long>v;
        cin>>a>>b;
        for(i=0; i<n; i++)
        {
            long long c=a[i]-'a';
            m[c]++;
            if(m[c]==1)
                v.push_back(c);
        }
        long long h=v.size();
        long long p=(1<<h);
        long long me[27];

        for(i=0; i<p; i++)
        {
            memset(me,0,sizeof(me));
            long long  x=0,y=0,ans=0;
            for(j=0; j<v.size(); j++)
            {

                if(i&(1<<j))
                {
                    me[v[j]]++;
                    x++;
                }
                if(x>k)
                    break;
            }
            if(x<=k)
            {
                for(j=0; j<n; j++)
                {
                    if(a[j]==b[j])
                        y++;
                    else if(me[a[j]-'a']>=1)
                    {
                        y++;
                    }
                    else
                    {
                        ans+=((y*(y+1))/2);
                        y=0;
                    }
                }
                ans+=((y*(y+1))/2);
            }

            mx=max(mx,ans);
        }
        cout<<mx<<endl;
    }
    return 0;
}

