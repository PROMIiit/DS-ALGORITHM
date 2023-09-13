#include<bits/stdc++.h>
using namespace std;
long long base=31,mod=(1e9)+41,p[1000009];

main()
{
    int t,n,i,x=1;
    cin>>t;

    memset(p,0,sizeof(p));

    p[0]=1;
    for(i=1; i<=(1e6)+7; i++)
    {
        p[i]=(p[i-1]*base)%mod;
    }

    while(t--)
    {
        string s,a;
        cin>>s;
        cin>>a;
        n=s.size();
        long long Hash[n+5],h=0,H=0,ans=0;
        memset(Hash,0,sizeof(Hash));
        for(i=0; i<n; i++)
        {
            h=(h*base)+(s[i]-'a'+1);
            h=h%mod;
            Hash[i]=h;
            //cout<<s[i]<<" "<<Hash[i]<<endl;
        }
        for(i=0; i<a.size(); i++)
        {
            H=(H*base)+(a[i]-'a'+1);
            H=H%mod;
        }
        //  cout<<H<<endl;
        if(H==Hash[a.size()-1])
            ans++;
        int j=0;
        for(i=a.size(); i<n; i++)
        {
            if(i-j<a.size())
                break;
            int dif=i-j;
            long long value=(Hash[j]*p[dif])%mod;
            long long k=(Hash[i]-value+mod)%mod;
            j++;
            if(k==H)
                ans++;
        }
        cout<<"Case "<<x<<": "<<ans<<endl;
        x++;

    }
    return 0;
}
