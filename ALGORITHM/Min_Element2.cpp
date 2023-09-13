#include<bits/stdc++.h>
using namespace std;

main()
{
    int n,i,j,temp=0;;
     cout<<"Size:"<<endl;
    cin>>n;
    int a[n+1];
    cout<<"Input array: ";
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    cout<<a[0]<<endl;
    return 0;
}

