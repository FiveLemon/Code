#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
using namespace std;
template<class out, class in>
out ConvertDataType(const in& a);
int main()
{
    string data;
    int num[10]={0};
    cin>>data;
    for(int i = 0; i < data.length(); i++)
    {
        num[ConvertDataType<int>(data[i])]++;
    }
    for(int i = 0; i < 10; i++)
    {
        if (0 != num[i])
        cout<<i<<":"<<num[i]<<endl;
    }
    return 0;
}
template<class out, class in>
out ConvertDataType(const in& a)
{
    stringstream temp;
    temp<<a;
    out b;
    temp>>b;
    return b;
}