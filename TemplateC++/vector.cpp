#include<bits/stdc++.h>
using namespace std;
#define mimi(a) memset(a,0,sizeof(a))
#define ll long long
#define pb push_back
#define fy first
#define ly second
#define lb "\n"

main()
{
    vector<int>v;
    for(int i=0; i<5; i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<v[2]<<endl;
    cout<<v.at(2)<<endl;/// 2 num index er value print && out of range a gele warning dbe
    cout<<v.front()<<endl;
    cout<<v.back()<<endl;
    cout<<v.empty()<<endl;/// output:0 means vector isnot empty
///   v.clear();
///    cout<<v.empty()<<endl;/// output:1 means vector is empty
    v.pop_back();/// will delete last value
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    int idx=2;
    //  v.erase(v.begin()+idx);
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;

///    v.erase(v.begin()+3,v.end());
///     for(int i=0;i<v.size();i++)
///    {
///      cout<<v[i]<<" ";
///    }
///    cout<<endl;
    // v.erase(v.begin()+1,v.begin()+3);


    v.insert(v.begin(),100);
    v.insert(v.begin()+2,200);
    v.insert(v.begin(),2,100);
    v.insert(v.begin()+2,5,200);///v.insert(position,frequency,value)
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<endl;



    vector<int>one;
    vector<int>two;
    one.push_back(1);
    two.push_back(2);
    swap(one,two);
    for(int i=0; i<1; i++)
        cout<<one[i]<<endl;
    for(int i=0; i<1; i++)
        cout<<two[i]<<endl;


    reverse(v.begin(),v.end());
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<endl;



    vector<int>::iterator it;
    it=v.begin();
    cout<<*it<<endl;

    it=v.begin()+3;
    cout<<*it<<endl;

    for(it=v.begin(); it!=v.end(); it++)
        cout<<*it<<endl;
    return 0;
}
