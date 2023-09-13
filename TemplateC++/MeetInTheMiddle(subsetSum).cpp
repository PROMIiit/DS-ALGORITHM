#include<bits/stdc++.h>
using namespace std;
#define hi ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

long long a[1005],x,cnt=0,n,cnt1=0,cnt2=0;
unordered_map<long long,long long>m;

inline void subset(long long sum,long long z)
{
    // cout<<"Promi\n";
    if(sum>0)
        m[sum]++;
    //  cout<<sum<<" ";

    if(sum>x)
        return;
    else if(sum==x)
    {
        cnt1++;
        return;
    }
    else
    {
        //  cout<<"Promi\n";
        //  cout<<z<<" "<<n<<endl;
        for(long long i=z; i<n/2; i++)
        {

            //   cout<<a[i]<<endl;
            subset(sum+a[i],i+1);
        }
    }
}

inline void subset1(long long sum,long long z)
{
    // cout<<"Promi\n";
    //  cout<<sum<<" ";
    if(sum>0)
    {
        if(m[x-sum]>0)
            cnt+=m[x-sum];
    }

    if(sum>x)
        return;
    else if(sum==x)
    {
        cnt2++;
        return;
    }
    else
    {
        //  cout<<"Promi\n";
        //  cout<<z<<" "<<n<<endl;
        for(long long i=z; i<n; i++)
        {
            //   cout<<a[i]<<endl;
            subset1(sum+a[i],i+1);
        }
    }
}


main()
{
    hi;
    long long t,i,j,xx=0;
    // cin>>t;
    t=1;
    while(t--)
    {
        cnt=0;
        xx=0;
        cin>>n>>x;
        for(i=0; i<n; i++)
        {
            cin>>a[i];
        }
        subset(0,0);
        subset1(0,n/2);
       // cout<<cnt1<<" "<<cnt2<<endl;
        cout<<cnt+cnt1+cnt2<<"\n";

    }
    return 0;
}
