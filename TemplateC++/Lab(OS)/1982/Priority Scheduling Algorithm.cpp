#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of Processes: ";
    cin>>n;
    int a[10],b[10],x[10],w[10],t[10],c[10],p[10];
    int j,smallest,cnt=0,time;
    double avg=0,tt=0,finish,swt=0,stat=0,awt,atat;
    cout<<"Enter Priority AT  BT  : "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"P"<<i+1<<" : ";
        cin>>p[i]>>a[i]>>b[i];
    }

    for(int i=0; i<n; i++)
        x[i]=b[i];

    p[9]=-1;
    for(time=0; cnt!=n; time++)
    {
        smallest=9;
        for(int i=0; i<n; i++)
        {
            if(a[i]<=time && p[i]>p[smallest] && b[i]>0 )
                smallest=i;
        }
        b[smallest]--;

        if(b[smallest]==0)
        {
            cnt++;
            finish=time+1;
            c[smallest] = finish;
            w[smallest] = finish - a[smallest] - x[smallest];
            t[smallest] = finish- a[smallest];
        }
    }
    cout<<"\nAccording to the priority scheduling algorithm : "<<endl<<endl;
    cout<<"Process"<<"\t\t"<< "BT"<<"\t"<<"AT" <<"\t"<<"Priority"<<"\t"<<"WT" <<"\t"<<"TAT"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"p"<<i+1<<"\t\t"<<x[i]<<"\t"<<a[i]<<"\t"<<p[i]<<"\t\t"<<w[i]<<"\t"<<t[i]<<endl;
        swt+= w[i];
        stat+=t[i];
    }
    awt=swt/n;
    atat=stat/n;
    cout<<"\n\nAverage response time ="<<awt<<endl;
    //cout<<"Average Turnaround time ="<<atat<<endl;
}

/*

2 0 1
6 1 7
3 2 3
5 3 6
4 4 5
10 5 15
9 15 8
*/



