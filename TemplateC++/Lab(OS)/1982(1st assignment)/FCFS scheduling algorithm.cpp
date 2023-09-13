#include<bits/stdc++.h>
using namespace std;

int n,temp,tt=0,min,d,i,j;
int a[1000],b[1000],e[1000],tat[1000],wt[1000],f[10000],p[1000],rt[1000];
float atat=0,awt=0,stat=0,swt=0,srt=0;

class Sanjida
{
public:

    void FCFS()
    {
        for(int i=0; i<n; i++)
        {
            f[i] = f[i-1] + b[i];
            wt[i]=f[i-1]-a[i];
            rt[i]=wt[i];
            tat[i]=b[i]+wt[i];

            swt += wt[i];
            srt+=rt[i];
            stat+= tat[i];
        }
        cout<<"According to the FCFC scheduling algorithm : "<<endl<<endl;
        cout<<"\nProcess \t Arrival-time(s) \t Burst-time(s)  \t Waiting-time(s)  \t Response-time  \t Turnaround-time(s)\n";

        for(i=0; i<n; i++)
        {
            cout<<"P"<<i+1<<"     \t\t       "<<a[i]<<"      \t\t      "<<b[i]<<"    \t\t       "<<rt[i]<<"   \t\t        "<<wt[i]<<"   \t\t        "<<tat[i]<<endl;
        }
        cout<<fixed<<setprecision(2);
        cout<<"\nAverage Waiting Time: "<<(swt/n)<<endl;
        cout<<"Average Response Time: "<<(srt/n)<<endl;
        cout<<"Average Turn Around Time: "<<(stat/n)<<endl;

        return;
    }
};

int main()
{
    Sanjida ob;
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

    ob.FCFS();
    return 0;
}
