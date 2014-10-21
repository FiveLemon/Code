#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;
void format(int start, int end);
int main()
{
    int start;
    int end;
    cin>>start>>end;
    format(start, end);
    return 0;
}
void format(int start, int end)
{
    float time = (end - start) * 1.0 / 100;
    int hour = int(time) / 3600;
    int minute = int(time - hour * 3600) / 60;
    time = time - hour * 3600 - minute * 60;
    int second = int(time);
    if (time - int(time) >= 0.5)
        second++;
    cout<<hour/10<<hour%10<<":"<<minute/10<<minute%10<<":"<<second/10<<second%10<<endl;
}