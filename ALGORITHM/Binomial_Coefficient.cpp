#include <bits/stdc++.h>
using namespace std;

main()
{
    int n, k;
    cout << "Enter values: ";
    cin >> n >> k;
   int  C[n + 1][k + 1] = {0};
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= min(i, k); j++)
        {
            if (i == j || j == 0)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    cout << "The value of C(n,k) is: " << C[n][k] << endl;
    return 0;
}