#include <bits/stdc++.h>
using namespace std;

int queen[100] = {0}, col[200] = {0}, dig1[400] = {0}, dig2[400] = {0};

void nqueen(int at, int n)
{
    if (at == n + 1)
    {
        printf("(row,column)= ");
        for (int i = 1; i <= n; i++)
            printf("(%d,%d)", i, queen[i]);
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (col[i] || dig1[i + at] || dig2[n + i - at])
        {
            continue;
        }
        queen[at] = i;
        col[i] = dig1[i + at] = dig2[n + i - at] = 1;
        nqueen(at + 1, n);
        col[i] = dig1[i + at] = dig2[n + i - at] = 0;
    }
}

main()
{
    nqueen(1, 4);
    return 0;
}