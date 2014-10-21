#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>
#include<cmath>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
typedef struct People
{
    string name;
    int born[3];
}People;
int Compare(People p1, People p2);
int Compare(People p1, int a[]);
template<class out, class in>
out ConvertDataType(const in& a);
int main()
{
    People  old, young, current;
    int number;
    int counter = 0;
    int old_limit[3] = {1814,9,6};
    int young_limit[3] = {2014,9,6};
    old.born[0] = 2014;
    old.born[1] = 9;
    old.born[2] = 7;
    young.born[0] = 1814;
    young.born[1] = 9;
    young.born[2] = 5;
    scanf("%d",&number);
    while(number--)
    {
        cin>>current.name;
        scanf("%d/%d/%d", &current.born[0], &current.born[1],&current.born[2]);
        if (Compare(current, old_limit) > 0 || Compare(current, young_limit) < 0)
        {
            continue;
        }
        if (Compare(current, old) > 0)
        {
            old.name = current.name;
            old.born[0] = current.born[0];
            old.born[1] = current.born[1];
            old.born[2] = current.born[2];
        }
        if (Compare(current, young) < 0)
        {
            young.name = current.name;
            young.born[0] = current.born[0];
            young.born[1] = current.born[1];
            young.born[2] = current.born[2];
        }
        counter++;
    }
    if (counter)
    {
        cout<<counter<<" "<<old.name<<" "<<young.name<<endl;
    }
    else
        cout<<counter<<endl;
    return 0;
}
int Compare(People p1, People p2)
{
    if ( (p1.born[0] < p2.born[0]) ||(p1.born[0] == p2.born[0] && p1.born[1] < p2.born[1])||
        (p1.born[0] == p2.born[0] && p1.born[1] == p2.born[1] && p1.born[2] < p2.born[2]))
    {
        return 1;
    }
    else if (p1.born[0] == p2.born[0] && p1.born[1] == p2.born[1] && p1.born[2] == p2.born[2])
    {
        return 0;
    }
    else
    {
        return -1;
    }
}
template<class out, class in>
out ConvertDataType(const in& a)
{
    std::stringstream temp;
    temp<<a;
    out b;
    temp>>b;
    return b;
}

int Compare(People p1, int a[])
{
    People temp;
    temp.born[0] = a[0];
    temp.born[1] = a[1];
    temp.born[2] = a[2];
    return Compare(p1, temp);
}