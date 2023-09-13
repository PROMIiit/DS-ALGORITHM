#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[10000],n,i,k,j=0;
    cout<<"Array size is: ";
    cin>>n;
    cout<<"The element of array is: "<<endl;
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cout<<"Deletion position is: ";
    cin>>k;
    j=k;
    while(j<n)
    {
            a[j-1]=a[j];
            j++;
    }
    n=n-1;
    cout<<"Array after deletion-->"<<endl;
    for(i=0;i<n;i++)
    {
            cout<<a[i];
            if(i==n-1)
                cout<<endl;
            else
                cout<<" ";
    }
    return 0;
}
