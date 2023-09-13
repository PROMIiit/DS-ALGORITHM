#include<bits/stdc++.h>
#include<time.h>
using namespace std;


int main()
{
        time_t End,Start;
    int n,k,choice;
    cout<<"Array size: ";
    cin>>n;
    int a[n],i,j=0,item=0;
    cout<<"Input array:"<<endl;
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cout<<"Input Kth position: ";
    cin>>k;
    for(int i=1; i<n; i++)
    {
        int item=a[i];
        int j=i-1;
        while(j>=0 && a[j]<item)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=item;
    }
    cout<<k<<"th largests Elements of the array is: "<<a[k-1]<<endl;
    return 0;
}

