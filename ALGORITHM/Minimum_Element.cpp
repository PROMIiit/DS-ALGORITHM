#include<bits/stdc++.h>
using namespace std;
#define Size 100005

class Promi
{
public:
    int n;
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
    }
    void min_Algo1()
    {
        int Min=0;
        Min=a[0];
        for(int i=1; i<n; i++)
        {
            if(Min>a[i])
                Min=a[i];
        }
        cout<<Min<<endl;
    }

    void min_Algo2()
    {
        int k=n;
        int t1[k]= {0},t2[k]= {0},i;
        for(int i=0; i<k; i++)
        {
            t1[i]=a[i];
        }
        while(k>0)
        {
            for(i=0; i<=k/2; i++)
            {
                t2[i]=min(t1[i*2],t1[(i*2)+1]);
            }
            for(i=0; i<=k/2; i++)
            {
                //    cout<<t2[i]<<" ";
                t1[i]=t2[i];
            }
            // cout<<endl;
            k=k/2;
        }
        cout<<t1[0]<<endl;
    }
    void min_Algo3()
    {
        int i,j,temp=0;;
        for(i=0; i<n; i++)
        {
            for(j=0; j<n-i-1; j++)
            {
                if(a[j]>a[j+1])
                {
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
        }
        cout<<a[0]<<endl;
    }

    void min_Algo4()
    {
        int i,j,Min;
        bool flag=true;
        i=-1;
        while(flag)
        {
            i=i+1;
            Min=a[i];
            flag=false;
            for(j=0; j<n; j++)
            {
                if(Min>a[j])
                {
                    flag=true;
                }
            }
        }
        cout<<Min<<endl;
    }
};

main()
{
    Promi p;
    cout<<"1.Algorithm 1"<<endl<<"2.Algorithm 2"<<endl<<"3.Algorithm 3"<<endl<<"4.Algorithm 4"<<endl;
    while(1)
    {
        int choice;
        cout<<"Enter your choice: ";
        cin>>choice;
        if(choice==1)
        {
            p.min_Algo1();
        }
        if(choice==2)
        {
            p.min_Algo2();
        }
        if(choice==3)
        {
            p.min_Algo3();
        }
        if(choice==4)
        {
            p.min_Algo4();
        }
    }
    return 0;
}
