#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
using namespace std;
template<class out, class in>
out ConvertDataType(const in& a);
string divide(string dividend, int divisor);
int main()
{
    string dividend;
    int divisor;
    while(cin>>dividend)
    {
        cin>>divisor;
        divide(dividend, divisor);
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
string divide(string dividend, int divisor)
{
    string result;
    int a = 0,b = 0;
    for(int i = 0; i < dividend.length(); i++)
    {
        a = b * 10 + ConvertDataType<int>(dividend[i]);
        result += ConvertDataType<string>(a / divisor);
        b = a % divisor;
    }
    if ('0' == result[0] && result.length() != 1)
        result = result.substr(1);
    
    cout<<result<<" "<<b<<endl;
    return result;
}