#include<bits/stdc++.h>
using namespace std;

int n,a[1000];

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

int test_max_heap()
{
    for(int i=n; i>1; i--)
    {
        int p=i/2;
        if(a[i]>a[p])
            return 0;
    }
    return 1;
}

void display()
{
    for(int i=1; i<=n; i++)
    {
        cout<<a[i];
        if(i==n)
            cout<<endl;
        else
            cout<<" ";
    }
}

int main()
{
    cout<<"1.Input complete binary tree"<<endl;
    cout<<"2.Creat Max heap"<<endl;
    cout<<"3.Display"<<endl;
    cout<<"4.Test Max heap property"<<endl<<endl;
    while(1)
    {
        int choice;
        cout<<"Choice your option: ";
        cin>>choice;
        if(choice==1)
        {
            int i;
            cout<<"Size of complete binary tree: ";
            cin>>n;
            for(i=1; i<=n; i++)
            {
                cin>>a[i];
            }
        }
        if(choice==2)
        {
            cout<<"Tree before max heapify: "<<endl;
            display();
            build_max_heap();
            cout<<"Tree after max heapify: "<<endl;
            display();
        }
        if(choice==3)
        {
            display();
        }
        if(choice==4)
        {

            if(test_max_heap()==1)
                cout<<"Yes!! It follows max_heap property"<<endl;
            else
                cout<<"No,It doesn't follow max_heap property"<<endl;
        }
        cout<<endl;
    }

    return 0;
}
