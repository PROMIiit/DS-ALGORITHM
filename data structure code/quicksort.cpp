#include<bits/stdc++.h>
using namespace std;

int a[10000];

int Partision(int lb,int ub)
{
    int pivot=a[lb];
    int start=lb;
    int End=ub;
    while(start<End)
    {
        while(a[start]<=pivot)
        {
            start++;
        }
        while(a[End]>pivot)
        {
            End--;
        }
        if(start<End)
        {
            swap(a[start],a[End]);
        }
    }
    swap(a[lb],a[End]);
    //cout<<End<<endl;
    return End;
}

void quick_sort(int lb,int ub)
{
        if(lb<ub)
        {
                int d=Partision(lb,ub);
                quick_sort(lb,d-1);
                quick_sort(d+1,ub);

        }
}
int main()
{
    int n;
     cout<<"Array size: ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    quick_sort(0,n-1);

    cout<<"Elements of sorted array: ";
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<endl;;
    }

    return 0;
}
