#include<bits/stdc++.h>
using namespace std;

void algorithm1(int n,int a[])
{
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
}
int main()
{
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
    algorithm1(k,a);
    j=k;
    for(int i=k; i<n; i++)
    {
        int item=a[i];
        int j=k-1;
        while(j>=0 && a[j]<item)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=item;
    }

    /// 7 5 4 3        10  1 2 8 9

    cout<<k<<"th largests Elements of the array is: "<<a[k-1]<<endl;
    return 0;
}


/*  for(int i=0;i<n;i++)
  {
          cout<<a[i]<<" ";
  }
  cout<<endl;*/

/* for(i=0;i<n;i++)
     {
             cout<<a[i]<<" ";
     }
     cout<<endl;*/


