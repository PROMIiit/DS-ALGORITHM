#include<bits/stdc++.h>
using namespace std;
int n=5,m=3;
int a[10][10],mx[10][10],av[10],need[10][10];
bool finish[10];
class Sanjida
{
public:
    Sanjida()
    {
        /// cin>>n>>m;
        cout<<"Enter the value of resource allocation: "<<endl;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin>>a[i][j];
            }
        }
        cout<<"Enter the value of max resource : "<<endl;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin>>mx[i][j];
                need[i][j]=mx[i][j]-a[i][j];
            }
        }


        cout<<"Enter the value of available resource: "<<endl;
        for(int i=0; i<m; i++)
        {
            cin>>av[i];
        }
    }
    void solve()
    {

        int res[10],idx=0;
        memset(finish,false,sizeof(finish));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(finish[j]==false)
                {
                    bool flag = true;

                    for (int k = 0; k< m; k++)
                    {
                        if (need[j][k] > av[k])
                        {
                            flag = false;
                            break;
                        }
                    }
                    if (flag == true)
                    {
                        res[idx++] = j;
                        for ( int x = 0; x< m; x++)
                            av[x] += a[j][x];
                        finish[j] = true;
                        break;
                    }
                }
            }
        }
        bool flag = true;

        for(int i=0; i<n; i++)
        {
            if(finish[i]==false)
            {
                flag=false;
                cout<<"The following system is not safe"<<endl;
                break;
            }
        }

        if(flag==true)
        {
            cout<<"\nFollowing is in safe sequence\n";
            for (int i = 0; i < n - 1; i++)
                cout<<"P"<<res[i]<<"-->";
            cout<<"P"<<res[n-1]<<endl;
        }

    }


};
int main()
{
    Sanjida ob;
    ob.solve();

    return 0;
}
/*

0 1 0
2 0 0
3 0 2
2 1 1
0 0 2

7 5 3
3 2 2
9 0 2
2 2 2
4 3 3

3 3 2

*/
