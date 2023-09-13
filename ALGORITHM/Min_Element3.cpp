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
    bool flag=true;
    i=0;
    while(flag)
    {
           i=i+1;
           Min=a[i];
           flag=false;
           for(j=1;j<=n;j++)
           {
                   if(Min>a[j])
                   {
                           flag=true;
                   }
           }
    }
    cout<<Min<<endl;
    return 0;
}


