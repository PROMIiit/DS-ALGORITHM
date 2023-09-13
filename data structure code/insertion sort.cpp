#include<bits/stdc++.h>
using namespace std;

int main()
{
        int n;
        cout<<"Array size: ";
        cin>>n;
        int a[n],i,j=0,item=0;
        for(i=0;i<n;i++)
        {
                cin>>a[i];
        }
        /// 8   10    5   7  3   2
        /// 0    1    2   3  4   5
        for(i=1;i<n;i++)
        {
                item=a[i];
                j=i-1;
                while(j>=0 && a[j]>item)
                {
                        a[j+1]=a[j];
                        j=j-1;
                }
                  a[j+1]=item;
        }
        cout<<"Elements of sorted array: ";
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
