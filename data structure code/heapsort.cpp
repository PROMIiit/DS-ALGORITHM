#include<bits/stdc++.h>
using namespace std;

int n,a[1000],k=0;

void max_heapify(int i)
{
    int largest=i;
    int l=(2*i);
    int r=(2*i)+1;
  //  int p=i/2;
    if(l<=n && a[l]>a[largest])
    {
        largest=l;
    }
    if(r<=n && a[r]>a[largest])
    {
        largest=r;
    }
    if(i!=largest)
    {
        swap(a[i],a[largest]);
        max_heapify(largest);
    }
    return;
}

void build_max_heap()
{
    for(int i=n/2; i>=1; i--)
    {
        max_heapify(i);
    }
}

void heap_sort()
{
        build_max_heap();
        for(int i=n;i>1;i--)
        {
                swap(a[1],a[i]);
                n=n-1;
                max_heapify(1);
        }
}
void display()
{
    for(int i=1; i<=k; i++)
    {
        cout<<a[i];
        if(i==k)
            cout<<endl;
        else
            cout<<" ";
    }
}

int main()
{
        int i;
            cout<<"Size of complete binary tree: ";
            cin>>n;
            k=n;
            for(i=1; i<=n; i++)
            {
                cin>>a[i];
            }
            heap_sort();
            display();
    return 0;
}
