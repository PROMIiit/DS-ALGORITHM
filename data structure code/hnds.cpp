#includeM<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,k,i,p,j;
    cin>>t;
    while(t--)
    {
        p=0;
        map<int,int>m;
        map<int,int>mp;
        vector<int>v;
        vector<int>vp;
        string s,a;
        cin>>n>>k;
        cin>>s>>a;
        for(i=0; i<s.size(); i++)
        {
            m[s[i]]++;
            if(m[s[i]]==1)
                v.push_back(s[i]);
        }
        for(i=0; i<a.size(); i++)
        {
            mp[a[i]]++;
            if(mp[a[i]]==1)
                vp.push_back(a[i]);
        }
        sort(v.begin(),v.end());
        sort(vp.begin(),vp.end());
        for(i=0; i<v.size(); i++)
        {

        }
        if(p==1)
            cout<<"No"<<endl;
        else
        {
            for(i=0; i<n; i++)
            {
                if(m[s[i]]>=mp[s[i]])
                {
                    m[s[i]]=m[s[i]]-m[s[i]];
                }

            }
        }
    }
}
return 0;
}
