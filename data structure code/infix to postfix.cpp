#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,p=0,k=0,j=0;
    stack<char>sk;
    char ch[1000];
    string s;
    cin>>s;
    sk.push('(');
    for(i=0; i<s.size(); i++)
    {
        k=0,p=0;
        if(isalpha(s[i]) || isdigit(s[i]))
        {
            ch[j]=s[i];
            // cout<<ch[j]<<endl;
            j++;
        }
        else if(s[i]=='(')
            sk.push(s[i]);
        else if(s[i]==')')
        {
            while(sk.top()!='(')
            {
                ch[j]=sk.top();
                j++;
                sk.pop();
            }
            sk.pop();
        }
        else
        {
            if(s[i]=='^')
                p=5;
            else if(s[i]=='/')
                p=4;
            else if(s[i]=='*')
                p=4;
            else if(s[i]=='+')
                p=3;
            else if(s[i]=='-')
                p=3;
            while(1)
            {
                if(sk.top()=='^')
                    k=5;
                else if(sk.top()=='/')
                    k=4;
                else if(sk.top()=='*')
                    k=4;
                else if(sk.top()=='+')
                    k=3;
                else if(sk.top()=='-')
                    k=3;
                else
                    k=2;
                if(k>=p)
                {
                    ch[j]=sk.top();
                    j++;
                    sk.pop();
                }
                else
                    break;
            }
            sk.push(s[i]);
        }
    }
    while(sk.top()!='(')
    {
        ch[j]=sk.top();
        j++;
        sk.pop();
    }
    for(i=0; i<j; i++)
    {
        cout<<ch[i];
    }
    cout<<endl;
    return 0;
}
