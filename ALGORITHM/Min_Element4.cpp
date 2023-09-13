#include<bits/stdc++.h>
using namespace std;

main()
{
    int n,i,j,temp=0,Min=0;
    cin>>n;
    int a[n+1];
    for(i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    Min=a[1];
    for(i=2; i<=n; i++)
    {
        if(Min>a[i])
                Min=a[i];
    }
    cout<<Min<<endl;
    return 0;
}



