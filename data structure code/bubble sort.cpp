#include<bits/stdc++.h>
using namespace std;

int main()
{
    int item,a[10000],n,i,j,temp=0;
    cout<<"Array size is: ";
    cin>>n;
    cout<<"The element of array is: "<<endl;
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
    for(i=0; i<n; i++)
    {
        cout<<a[i];
        if(i==n-1)
            cout<<endl;
        else
            cout<<" ";
    }
    return 0;
}
