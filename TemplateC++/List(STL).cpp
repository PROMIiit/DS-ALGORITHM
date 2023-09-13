#include <iostream>
#include <iterator>
#include <list>
using namespace std;

void showlist(list<int> g)
{

    for (auto it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}

int main()
{

    list<int> L1,L2;

    for (int i = 0; i < 10; ++i)
    {
        L1.push_back(i * 2);
        L2.push_front(i * 3);
    }
    cout << "L1 : ";
    showlist(L1);

    cout << "L2 : ";
    showlist(L2);

    cout << "L1.front() : " << L1.front()<<endl;
    cout << "L1.back() : " << L1.back()<<endl;;

    cout << "L1.pop_front() : ";
    L1.pop_front();
    showlist(L1);

    cout << "L2.pop_back() : ";
    L2.pop_back();
    showlist(L2);

    cout << "L1.reverse() : ";
    L1.reverse();
    showlist(L1);

    cout << "L2.sort(): ";
    L2.sort();
    showlist(L2);

    return 0;
}

