#include <bits/stdc++.h>
using namespace std;
int direction[200][200];
string s1, s2;

void path(int i, int j)
{
    if (i == 0 || j == 0)
        return;
    if (direction[i][j] == 1)
    {
        path(i - 1, j - 1);
        cout << s1[i - 1];
        return;
    }
    if (direction[i][j] == 2)
    {
        path(i - 1, j);
        return;
    }
    // if(direction[i][j]==3)
    {
        path(i, j - 1);
    }
}

main()
{
    cin >> s1 >> s2;

    int l = s1.size(), m = s2.size(), i, j;
    int d[l + 1][m + 1];
    for (i = 0; i <= l; i++)
    {
        d[i][0] = 0;
    }
    for (i = 0; i <= m; i++)
    {
        d[0][i] = 0;
    }
    for (i = 1; i <= l; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                d[i][j] = 1 + d[i - 1][j - 1];
                direction[i][j] = 1;
            }
            else if (d[i - 1][j] >= d[i][j - 1])
            {
                d[i][j] = d[i - 1][j];
                direction[i][j] = 2;
            }
            else
            {
                d[i][j] = d[i][j - 1];
                direction[i][j] = 3;
            }
        }
    }

    for (i = 0; i <= l; i++)
    {
        for (j = 0; j <= m; j++)
        {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Longest Sequence lenghth is: " << d[l][m] << endl;
    cout << "Path is: ";
    path(l, m);
    cout << endl;
    return 0;
}
