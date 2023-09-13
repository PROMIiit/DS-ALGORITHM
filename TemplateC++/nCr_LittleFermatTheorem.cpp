#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
long long mx=1000009;
long long a[1000009],m=1000003;

long long bigmod(long long a,long long b,long long M)
{
    if(b==0)
        return 1%M;
    long long x=bigmod(a,b/2,M);
    x=(x*x)%M;
    if(b%2!=0)
        x=(x*a)%M;
    return x;
}


int main()
{
    long long t,i,j=1;
    cin>>t;
//    t=1;
    for(i=0; i<=mx; i++)
        a[i]=1;

    for(i=2; i<=mx+7; i++)
    {
        a[i]=(a[i-1]*i)%m;
    }
    while(t--)
    {
        long long n,r,ans,x=1,y=1,z=1,yy=0,zz=0;
        cin>>n>>r;


        /// nCr = ( n!%mod * (r!)^mod-2 %mod * ((n-r)!)^mod-2 %m )%mod
        /// Complexity O(n)
        /// n<=10^7




        y=bigmod(a[r],m-2,m);
        z=bigmod(a[n-r],m-2,m);

         cout<<a[n]<<" "<<y<<" "<<z<<endl;
        cout<<"Case "<<j<<": ";
        cout<<(a[n]*y*z)%m<<endl;
        j++;
    }
    return 0;
}

