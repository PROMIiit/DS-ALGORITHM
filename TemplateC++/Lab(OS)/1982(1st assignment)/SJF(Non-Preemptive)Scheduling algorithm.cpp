#include<bits/stdc++.h>
using namespace std;

class Non_Preemptive
{
public:
    int n,temp,tt=0,min,d,i,j;
    int a[1000],b[1000],e[1000],tat[1000],wt[1000],f[10000],p[1000];
    float atat=0,awt=0,stat=0,swt=0;
    Non_Preemptive()
    {
        cout<<"Enter the total number of processes: ";
        cin>>n;
        cout<<"\nEnter arrival time: "<<endl;
        for(i=0; i<n; i++)
        {
            cout<<"P"<<i+1<<" : ";
            cin>>a[i];
            p[i]=i+1;
        }
        cout<<"\nEnter burst time: "<<endl;
        for(i=0; i<n; i++)
        {
            cout<<"P"<<i+1<<" : ";
            cin>>b[i];
        }
    }

    void SJF()
    {
        swt=0,stat=0;
        for(i=0; i<n; i++)
        {
            for(j=i+1; j<n; j++)
            {
                if(b[i]>b[j])
                {
                    temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;

                    temp=b[i];
                    b[i]=b[j];
                    b[j]=temp;

                    temp=p[i];
                    p[i]=p[j];
                    p[j]=temp;
                }
            }
        }
        min=a[0];
        for(i=0; i<n; i++)
        {
            if(min>a[i])
            {
                min=a[i];
                d=i;
            }
        }
        tt=min;
        e[d]=tt+b[d]; ///for initial process
        tt=e[d];

        for(i=0; i<n; i++)
        {
            if(a[i]!=min)
            {
                e[i]=b[i]+tt;
                tt=e[i];
            }
        }
        for(i=0; i<n; i++)
        {

            tat[i]=e[i]-a[i];
            stat=stat+tat[i];
            wt[i]=tat[i]-b[i];
            swt=swt+wt[i];
        }
        atat=stat/n;
        awt=swt/n;
        cout<<"According to the non-preemptive SJF scheduling algorithm : "<<endl;
        cout<<"\nProcess \t Arrival-time(s) \t Burst-time(s)  \t Waiting-time(s) \t Turnaround-time(s)\n";

        for(i=0; i<n; i++)
        {
            cout<<"P"<<p[i]<<"     \t\t       "<<a[i]<<"      \t\t      "<<b[i]<<"    \t\t       "<<wt[i]<<"   \t\t        "<<tat[i]<<endl;
        }
        cout<<fixed<<setprecision(2);
        cout<<"\nAverage waiting time = "<<awt<<"\nAverage turnaround time = "<<atat<<endl;
    }

};
int main()
{
    Non_Preemptive ob;
   ob.SJF();
    return 0;
}

