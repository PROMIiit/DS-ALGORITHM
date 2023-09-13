#include<bits/stdc++.h>
using namespace std;
#define Size 100005

class Promi
{
public:
    int n,k;
    int a[Size];
    Promi()
    {
        cout<<"Size of array: ";
        cin>>n;
        cout<<"Input Array: ";
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        cout<<"Input Kth position: ";
        cin>>k;
    }

    void sort_algorithm(int Sz)
    {
        for(int i=1; i<Sz; i++)
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
};

main()
{
    Promi p;

    return 0;
}
