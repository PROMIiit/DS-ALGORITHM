#include<bits/stdc++.h>
using namespace std;

main()
{
    int n,i;
    cout<<"Array size: ";
    cin>>n;
    int a[n+1],t1[n]= {0},t2[n]= {0};
    cout<<"Input array: ";
    for(i=0; i<n; i++)
    {
        cin>>a[i];
        t1[i]=a[i];
    }
    while(n>0)
    {
        for(i=0; i<=n/2; i++)
        {
            t2[i]=min(t1[i*2],t1[(i*2)+1]);
        }
        for(i=0; i<=n/2; i++)
        {
            //    cout<<t2[i]<<" ";
            t1[i]=t2[i];
        }
        // cout<<endl;
        n=n/2;
    }
    cout<<t1[0]<<endl;
    return 0;
}
