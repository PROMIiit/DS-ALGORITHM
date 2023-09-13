#include <bits/stdc++.h>
using namespace std;

class Promi
{
public:
    int n;
    int queen[100] = {0}, col[400] = {0}, dig1[800] = {0}, dig2[800] = {0};
    Promi()
    {
        cout << "Enter the number of queen: ";
        cin >> n;
    }
    void nqueen(int at, int n)
    {
        if (at == n + 1)
        {
            printf("(row,col) = ");
            for (int i = 1; i <= n; i++)
            {
                printf("(%d,%d) ", i, queen[i]);
            }
            printf("\n");
            return;
        }
        for (int i = 1; i <= n; i++)
        {
            if (col[i] || dig1[i + at] || dig2[n + i - at])
                continue;
            queen[at] = i;
            col[i] = dig1[i + at] = dig2[n + i - at] = 1;
            nqueen(at + 1, n);
            col[i] = dig1[i + at] = dig2[n + i - at] = 0;
        }
    }
};

main()
{

    Promi p;
    p.nqueen(1, p.n);
    return 0;
}