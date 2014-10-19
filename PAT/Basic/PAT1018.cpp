#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cctype>
#include<map>
using namespace std;
bool IsJiaWin(char a[]);
int main()
{
    int number;
    cin>>number;
    char data[2];
    int count[3] = {0,0,0};
    map<char,int> jia,yi;
    jia['J'] = 0;
    jia['B'] = 0;
    jia['C'] = 0;
    yi['J'] = 0;
    yi['B'] = 0;
    yi['C'] = 0;
    while(number--)
    {
        cin>>data[0]>>data[1];
        if (IsJiaWin(data))
        {
            count[0]++;
            jia[data[0]]++;
        }
        else if(data[0] == data[1])
        {
            count[1]++;
        }
        else
        {
            count[2]++;
            yi[data[1]]++;
        }

    }
    cout<<count[0]<<" "<<count[1]<<" "<<count[2]<<endl;
    cout<<count[2]<<" "<<count[1]<<" "<<count[0]<<endl;
    data[0] = 'J';
    data[1] = 'J';
    for(map<char,int>::reverse_iterator start = jia.rbegin(); start != jia.rend(); start++)
    {
        if(start->second >= jia[data[0]])
        {
            data[0] = start->first;
        }
    }
    for(map<char,int>::reverse_iterator start = yi.rbegin(); start != yi.rend(); start++)
    {
        if(start->second >= yi[data[1]])
        {
            data[1] = start->first;
        }
    }
    cout<<data[0]<<" "<<data[1]<<endl;
    return 0;
}
bool IsJiaWin(char a[])
{
    return ('C' == a[0] && 'J' == a[1])|| ('J' == a[0] && 'B' == a[1])|| ('B' == a[0] && 'C' == a[1]);
}