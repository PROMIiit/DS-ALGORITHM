#include<bits/stdc++.h>
using namespace std;

struct student
{
    char name[50];
    int roll;
    float marks;
};

int main()
{
    struct student s[3];
    int i;
    cout<<"Enter information of students:"<<endl;
    for(i=0; i<3 ; i++)
    {
        s[i].roll=i+1;
        cout<<"For roll number "<<s[i].roll<<endl;
        cout<<"Enter name: ";
        cin>>s[i].name;
        cout<<"Enter marks: ";
        cin>>s[i].marks;
        cout<<endl;
    }
    cout<<"Displaying information of students:"<<endl;
    for(i=0; i<3; i++)
    {
        cout<<endl;

        cout<<"Information for the roll number "<<i+1<<endl;
        cout<<"Name: "<<s[i].name<<endl;
        cout<<"Marks: "<<s[i].marks<<endl;
    }
    return 0;
}
