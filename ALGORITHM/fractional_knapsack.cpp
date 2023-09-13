#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
vector<PII> v;

bool cmp(PII a, PII b)
{
    return a.second * b.first > b.second * a.first;
}

main()
{
    int n, w, weight, price;
    double ans = 0.0;
    cout << "Total num of item: ";
    cin >> n;
    cout << "Enter weight & price: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> weight >> price;
        v.push_back(PII(weight, price));
    }
    cout << "Weight of knapsack: ";
    cin >> w;
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }

    for (int i = 0; i < n; i++)
    {
        int z = min(w, v[i].first);
        w = w - z;
        ans += z * ((double)v[i].second / (double)v[i].first);
        cout << z << " kg from " << v[i].first << " kg && required cost is " << z * ((double)v[i].second / (double)v[i].first) << " for this." << endl;
    }
    cout << endl
         << "Maximum cost: " << ans << endl;
    return 0;
}

/*
3
10 60
20 100
30 120

50
*/
