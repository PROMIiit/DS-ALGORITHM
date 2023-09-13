#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define hi ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mimi(a) memset(a,0,sizeof(a))
#define ll long long
#define pb push_back
#define fy first
#define ly second
#define lb "\n"
long long mod=1000000007;
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
    long long x=0,y=0,n,m,z=0,zz=0;
    cin>>n>>m;
    x=bigmod(n,m,mod);   ///x=n^m;

    y=(n-5+mod)%mod; /// y=n-5;
    z=bigmod(y,mod-2,mod);
    zz=x*z;/// zz=x/y;
    cout<<x<<endl;
    return 0;
}
