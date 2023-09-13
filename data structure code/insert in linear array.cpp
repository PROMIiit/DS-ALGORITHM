#include<bits/stdc++.h>
using namespace std;

int main()
{
    int item,a[10000],n,i,k,j=0;
    cout<<"Array size is: ";
    cin>>n;
    cout<<"The element of array is: "<<endl;
    for(i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    cout<<"Insert item is: ";
    cin>>item;
    cout<<"Insertion position is: ";
    cin>>k;
    j=n;
    n=n+1;
    while(j>=k)
    {
            a[j+1]=a[j];
            j--;
    }
    a[k]=item;
    cout<<"Array after insertion-->"<<endl;
    for(i=1;i<=n;i++)
    {
            cout<<a[i];
            if(i==n)
                cout<<endl;
            else
                cout<<" ";
    }
    return 0;
}
