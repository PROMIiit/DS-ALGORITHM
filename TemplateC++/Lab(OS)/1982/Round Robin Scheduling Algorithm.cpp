#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    vector<pair<int,pair<int,int>>>v;
    cout<<"Enter the number of process : ";
    cin>>n;
    int ct[n],tat[n],wat[n];
    int AT,BT,l,m;
    cout<<"\nEnter Arriving time & burst time"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"P"<<i+1<<" : ";
        cin>>AT>>BT;
        v.push_back({AT,{i,BT}});
    }
    sort(v.begin(),v.end());
    int quan;
    cout<<"Enter the value of time quanta: ";
    cin>>quan;
    queue<pair<int,pair<int,int>>>qq;
    qq.push(v[0]);
    memset(ct,0,sizeof(ct));
    int time=v[0].first;
    int j=1;
    while(!qq.empty())
    {
        pair<int,pair<int,int>>a=qq.front();
        qq.pop();
        if(a.second.second>quan)
        {
            a.second.second-=quan;
            while(j<n&&v[j].first<=time+quan){
                qq.push(v[j]);
                j++;
            }
            time+=quan;
            qq.push(a);
        }
        else
        {
            while(j<n&&v[j].first<=time+a.second.second){
                qq.push(v[j]);
                j++;
            }
            time+=a.second.second;
            a.second.second=0;
            ct[a.second.first]=time;
        }
    }
    float awt=0.0,atat=0.0;
    int swt=0,stat=0;
    for(int i=0; i<n; i++)
    {
        tat[i]=ct[i]-v[i].first;
        stat+=tat[i];
    }
    for(int i=0; i<n; i++)
    {
        wat[i]=tat[i]-v[i].second.second;
        swt+=wat[i];
    }
    cout<<"\nAccording to the Round Robin Scheduling Process: "<<endl<<endl;
    cout<<"Process\tAT\tBT\tCT\tTAT\tWT"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"P"<<i+1<<"\t"<<v[i].first<<"\t"<<v[i].second.second<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wat[i]<<endl;

    }
    awt=(float)swt/(float)n;
    atat=(float)stat/(float)n;
    cout<<fixed<<setprecision(2);
    cout<<"\nAverage Waiting Time: "<<awt<<endl;
    cout<<"Average Turn Around Time: "<<atat<<endl;

    return 0;
}


