#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;
void BlackHole(string data);
template<class out, class in>
out ConvertDataType(in data);
int main()
{
    string data;
    while(cin>>data)
    {
        if (data[0] == data[1] && data[1] == data[2] && data[2] == data[3])
        {
            cout<<data<<" - "<<data<<" = "<<"0000"<<endl;
        }
        else
        {
            data.insert(data.begin(), 4 - data.length(), '0');
            if ("6174" == data)
                cout<<"7641"<<" - "<<"1467"<<" = "<<"6174"<<endl;
            else
                BlackHole(data);
        }
    }
    return 0;
}
void BlackHole(string data)
{
    if (data == "6174")
    {
        return;
    }
    else
    {
        sort(data.begin(), data.end());
        int data2 = ConvertDataType<int>(data);
        reverse(data.begin(), data.end());
        int data1 = ConvertDataType<int>(data);
        data = ConvertDataType<string>(data1 - data2);
        string data2_str = ConvertDataType<string>(data2);
        data2_str.insert(data2_str.begin(), 4 - data2_str.length(), '0');
        data.insert(data.begin(),4 - data.length(),'0');
        cout<<data1<<" - "<<data2_str<<" = "<<data<<endl;
        BlackHole(data);
    }
}
template<class out, class in>
out ConvertDataType(in data)
{
    stringstream temp;
    out b;
    temp<<data;
    temp>>b;
    return b;
}