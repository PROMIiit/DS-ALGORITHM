#include <bits/stdc++.h>
using namespace std;
int n;
int board[40][40];
int col[200] = {0}, dig1[400] = {0}, dig2[400] = {0};
bool check(int at)
{
    if (at >= n )
    {
        return true;
    }
    for (int i = 0; i < n; i++)
    {
        if (col[i] != 1 && dig1[i + at] != 1 && dig2[n - 1 + i - at] != 1)
        {
            board[i][at] = 1;
            col[i] = dig1[i + at] = dig2[n - 1 + i - at] = 1;
            if (check(at + 1))
                return true;
            board[i][at] = 0;
            col[i] = dig1[i + at] = dig2[n - 1 + i - at] = 0;
        }
    }
    return false;
}

void solve()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = 0;
    if (check(0) == false)
    {
        cout << "There is no solution" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

main()
{

    cout << "Enter the number of queen: ";
    cin >> n;
    solve();
    return 0;
}