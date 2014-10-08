#include<iostream>
#include<string>
#include<sstream>
using namespace std;
void format(int data);
template<class in, class out>
out convert(const in& a);
int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        format(a + b);
    }
    return 0;
}
void format(int data)
{
    if (data < 0)
    {
        cout<<"-";
        data = data * (-1);
    }
    string str;
    string colloma(",");
    str = convert<int, string>(data);
    int flag = str.length() % 3;
    for(int i = str.length() - 3; i >= flag; i-=3)
    {
        str.insert(i, colloma);
    }
    if (str[0] == ',')
    {
        str = str.substr(1);
    }
    cout<<str<<endl;
}

template<class in, class out>
out convert(const in& a)
{
    stringstream temp;
    temp<<a;
    out b;
    temp>>b;
    return b;
}