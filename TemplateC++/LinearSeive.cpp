#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
vector<int>prime;
int mark[10000006];
int cnt[10000006],q=0;
void sieve()
{
    for(int i = 2; i <= 10000006; i++)
    {
        if(!mark[i])
        {
            mark[i] = i;
            prime.push_back(i);
        }
        for(auto it : prime)
        {
            if(i * it > 10000006)
            {
                break;
            }
            mark[i * it] = it;
            if(i % it == 0)
            {
                break;
            }
        }
    }
}
main()
{
    sieve();
    int q=0;
    int m=100;
    while(m>1)
    {
        int k=mark[m];
        while(m%k==0)
        {
            m/=k;
            cout<<k<<endl;
        }
    }
}
