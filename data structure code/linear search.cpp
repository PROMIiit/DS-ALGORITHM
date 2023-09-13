#include<bits/stdc++.h>
using namespace std;

int main()
{
    int item,a[10000],n,i;
    cout<<"Array size is: ";
    cin>>n;
    cout<<"The element of array is: "<<endl;
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cout<<"Search item is: ";
    cin>>item;
    for(i=0; i<n; i++)
    {
        if(item==a[i])
        {
            cout<<"Item is found in position "<<i+1<<endl;
            return 0;
        }
    }
    cout<<"Item is not found in this array"<<endl;
    return 0;
}
