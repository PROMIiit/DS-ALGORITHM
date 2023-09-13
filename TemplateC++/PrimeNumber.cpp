#include<bits/stdc++.h>
using namespace std;
#define hi ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mimi(a) memset(a,0,sizeof(a))
#define ll long long
#define pb push_back
#define fy first
#define ly second
#define lb "\n"
long long mx=(9e7)+3;
bool prime[90000005];
long long m[90000005];
vector<long long>v;


void p()
{
    memset(prime,true,sizeof(prime));
    memset(m,0,sizeof(m));
    for(int i=3; i*i<=mx; i+=2)
    {
        if(prime[i]==true)
        {
            for(int j=i*i; j<=mx; j+=i)
            {
                prime[j]=false;
            }
        }
    }
    v.push_back(2);
    m[2]++;
    for(int i=3; i<=mx; i+=2)
    {
        if(prime[i])
        {
          //  cout<<i<<endl;
            m[i]++;
            v.push_back(i);
        }
    }
}




main()
{
    hi;
    p();


    return 0;
}


