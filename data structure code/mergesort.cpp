#include<bits/stdc++.h>
using namespace std;

int b[10000];

void Merge(int a[],int left,int mid,int right)
{
    int i=left,j=mid+1,k=left;
    while(i<=mid && j<=right)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            // cout<<b[k]<<endl;
            k++;
            i++;
        }
        else
        {
            b[k]=a[j];
            //  cout<<b[k]<<endl;
            k++;
            j++;
        }
    }
    while(j<=right)
    {
        b[k]=a[j];
        k++;
        j++;
    }
    while(i<=mid)
    {
        b[k]=a[i];
        k++;
        i++;
    }
    for(int i=0; i<k; i++)
    {
        a[i]=b[i];
    }
}

void mergesort(int a[],int left,int right)
{
    // cout<<left<<" "<<right<<endl;
    int mid;
    if(left<right)
    {
        mid=(left+right)/2;
        mergesort(a,left,mid);
        mergesort(a,mid+1,right);
        Merge(a,left,mid,right);
    }
}

int main()
{
    int  a[10000],n,left=0,right=0;
    cout<<"Array size: ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    right=n-1;
    mergesort(a,left,right);

    cout<<"Elements of sorted array: ";
    for(int i=0; i<n; i++)
    {
        cout<<a[i];
        if(i==n-1)
            cout<<endl;
        else
            cout<<" ";
    }
    return 0;
}
