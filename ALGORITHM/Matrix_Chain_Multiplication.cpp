#include<bits/stdc++.h>
using namespace std;

main()
{
    cout<<"Enter the number of matrix: ";
    int n;
    cin>>n;
    int p[n];
    cout<<"Enter dimensions: "<<endl;
    for(int i=0;i<=n;i++)
    {
        cin>>p[i];
    }

    int i,j=0,d,k,x=0;
    n=n+1;
    int m[n][n]={0};
    for(d=1;d<n-1;d++)
    {
        for(i=1;i<n-d;i++)
        {
            j=i+d;
            int mn=INT_MAX;
            for(k=i;k<=j-1;k++)
            {
                x=m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]);
                if(x<mn)
                {
                    mn=x;
                }
            }
            m[i][j]=mn;
        }
    }
    cout<<"Total cost: "<<m[1][n-1]<<endl;

    return 0;
}