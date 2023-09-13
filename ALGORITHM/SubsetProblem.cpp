#include <bits/stdc++.h>
using namespace std;
int n, a[100005], TargetSum;

void print(int Subset[], int idx)
{
    for (int i = 0; i < idx; i++)
    {
        cout << Subset[i] << " ";
    }
    cout << endl;
}

void solve(int Subset[], int idx, int Sum, int z)
{
    cout<<Sum<<"\n";
    if (Sum > TargetSum)
        return;
    else if (Sum == TargetSum)
    {
        print(Subset, idx);
        return;
    }
    else
    {
        for (int i = z; i < n; i++)
        {
            Subset[idx] = a[i];
            solve(Subset, idx + 1, Sum + a[i], i + 1);
        }
    }
}

main()
{
    cout << "Enter Set Size: ";
    cin >> n;
    cout << "Enter set element: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter sum: ";
    cin >> TargetSum;
    int Subset[100007];
    solve(Subset, 0, 0, 0);
    return 0;
}
