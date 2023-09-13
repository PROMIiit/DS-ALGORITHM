#include<bits/stdc++.h>
using namespace std;

main()
{
    priority_queue<long long>Q;
    long long x,i;
    for(i=1; i<=5; i++)
    {
        cin>>x;
        Q.push(x);
    }
    while(!Q.empty())
    {
        cout<<Q.top()<<" ";
        Q.pop();
    }
//    cout<<endl;



    /// Greater Or Decreasng
//    priority_queue<long long,vector<long long>,std::greater<int>>Q;
//    long long x,i;
//    for(i=1; i<=5; i++)
//    {
//        cin>>x;
//        Q.push(x);
//    }
//    while(!Q.empty())
//    {
//        cout<<Q.top()<<" ";
//        Q.pop();
//    }
    return 0;
}
