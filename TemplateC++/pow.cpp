#include<bits/stdc++.h>
using namespace std;
#define mimi(a) memset(a,0,sizeof(a))
#define ll long long
#define pb push_back
#define fy first
#define ly second
#define lb "\n"

main()
{

    /// (x<<b) means x*2^b;for example (13<<2)=13*(2^2)=4  , (1<<x)=1*(2^x)
    long long x,p=0;
    cin>>x;
    p=(1LL<<x);
    cout<<p<<endl;
    /// (1<<x) works like pow(2,x) .SO 2^x is just like (1<<x) or (1LL<<x)


    ///  (x>>b) = floor value of(x/2^b)

    p=(x>>2);
    cout<<p<<endl;


    for(int i = 0; i < 30; i++) if((x & (1 << i)) != 0) cout << i << " "; ///in binary reprentation which bit is 1 .this will check for range 2^29
    cout<<endl;

    return 0;
}
