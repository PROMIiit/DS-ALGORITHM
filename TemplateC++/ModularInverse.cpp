#include<bits/stdc++.h>
using namespace std;
#define mimi(a) memset(a,0,sizeof(a))
#define ll long long
#define pb push_back
#define fy first
#define ly second
#define lb "\n"
long long bigmod(long long a,long long b,long long M)
{
    if(b==0)
        return 1%M;
    long long x=bigmod(a,b/2,M);
    x=(x*x)%M;
    if(b%2==1)
        x=(x*a)%M;
    return x;
}

main()
{
    long long t,i,j,n;
    cin>>t;
    while(t--)
    {
        long long x=0,y=0,xx=0,xy,ans=0,mod=(1e9)+7;
        cin>>n;

        /// sum=((n*(n+1)*(2n+1))/6;

        x=(n%mod)*((n+1)%mod);
        xx=(x%mod)*(((2*n)+1)%mod);
        xy=(xx%mod)*bigmod(6,mod-2,mod);
        cout<<xy%mod<<endl;


    }
    return 0;
}

