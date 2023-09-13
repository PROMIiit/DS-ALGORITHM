#include<bits/stdc++.h>
using namespace std;

int main()
{
    int first,last,mid,i,n,item,a[10000];
    cout<<"Array size is: ";
    cin>>n;
    cout<<"The element of array is: "<<endl;
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cout<<"Search item is: ";
    cin>>item;
    first=0;
    last=n-1;
    while(first<=last)
    {
        mid=(first+last)/2;
        if(a[mid]==item)
        {
            cout<<"Item is found in position "<<mid+1<<endl;
            return 0;
        }
        if(a[mid]<item)
            first=mid+1;
        else
            last=mid-1;
    }
    cout<<"Item is not found in this array"<<endl;
    return 0;
}
