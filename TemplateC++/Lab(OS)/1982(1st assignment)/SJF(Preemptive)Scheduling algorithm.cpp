#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int pid;
    int bt;
    int art;
};

Process p[1000000];

void find_TAT(Process proc[], int n, int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
        tat[i] = p[i].bt + wt[i];
}

void find_WT(Process p[], int n, int wt[])
{
    int rt[n];
    for (int i = 0; i < n; i++)
        rt[i] = p[i].bt;
    int c = 0, t = 0, mn = INT_MAX;
    int s = 0, ft;
    bool flag = false;
    while (c != n)
    {
        for (int j = 0; j < n; j++)
        {
            if ((p[j].art <= t) && (rt[j] < mn) && rt[j] > 0)
            {
                mn = rt[j];
                s = j;
                flag = true;
            }
        }
        if (flag == false)
        {
            t++;
            continue;
        }
        rt[s]--;
        mn = rt[s];
        if (mn == 0)
            mn = INT_MAX;

        if (rt[s] == 0)
        {
            c++;
            flag = false;
            ft = t + 1;

            wt[s] = ft -
                    p[s].bt -
                    p[s].art;
            if (wt[s] < 0)
                wt[s] = 0;
        }
        t++;
    }
}
void avg_Time(Process p[], int n)
{
    int wt[n], tat[n], total_wt = 0,
                       total_tat = 0;

    find_WT(p, n, wt);

    find_TAT(p, n, wt, tat);
    cout<<"According to the Preemptive SJF scheduling algorithm : "<<endl<<endl;
    cout << "Processes \t" << "Burst time \t" << " Arrival time \t"<< " Waiting time \t" << "Turn around time\n";
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << p[i].pid << "\t\t" << p[i].bt << "\t\t " << p[i].art << "\t\t " << wt[i] << "\t\t " << tat[i] << endl;
    }
    cout << "\nAverage waiting time = " << (float)total_wt/(float)n;
    cout << "\nAverage turn around time = " << (float)total_tat/(float)n<<endl;
}

int main()
{
    int n;
    cout<<"Number of Processes: ";
    cin>>n;
    for(int i=0; i<n; i++)
        p[i].pid=i+1;

    cout<<"\nProcess Burst Times:\n";
    for(int i=0; i<n; i++)
    {
        cout<<"P"<<p[i].pid<<" : ";
        cin>>p[i].bt;
    }

    cout<<"\nProcess Arrival Times:\n";
    for(int i=0; i<n; i++)
    {
        cout<<"P"<<p[i].pid<<" : ";
        cin>>p[i].art;
    }
    avg_Time(p, n);
    return 0;
}
