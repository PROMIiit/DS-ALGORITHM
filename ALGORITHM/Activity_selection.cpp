#include <bits/stdc++.h>
using namespace std;

int n;

void maxActivities(int start[], int End[])
{
    int i, j;
    j = 0;
    cout << "Selected activities are: " << endl;
    cout << start[0] << " " << End[0] << endl;
    for (i = 1; i < n; i++)
    {
        if (start[i] >= End[j])
        {
            cout << start[i] << " " << End[i] << endl;
            j = i;
        }
    }
}

main()
{
    cout << "Activity numbers: ";
    cin >> n;
    int start[n], End[n];
    cout << "Enter Start time & End time: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> start[i] >> End[i];
    }
    maxActivities(start, End);
    return 0;
}

/*
3
10 20
12 25
20 30

*/