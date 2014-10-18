#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;
template<class out, class in>
out ConvertDataType(const in& a);
string RadixConvert(int data, int radix);

string Reverse(string a);
int main()
{
    int a,b,c;
    string temp;
    while(cin>>a>>b>>c)
    {
        cout<<Reverse(RadixConvert(a + b, c))<<endl;
    }
   /* while(cin>>temp)
    {
        cout<<Reverse(temp);
    }*/
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
string RadixConvert(int data, int radix)
{
    string intermidia;
    if (data < radix)
    {
        return ConvertDataType<string>(data);
    }
    else
    {
        intermidia += ConvertDataType<string>(data % radix);
        intermidia += RadixConvert(data / radix, radix);
        
    }
    return intermidia;
}


string Reverse(string a)
{
    int start = 0;
    int end = a.length() - 1;
    while(start < end)
    {
        swap(a[start], a[end]);
        start++;
        end--;
    }
    return a;
}