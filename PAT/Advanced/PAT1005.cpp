#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
int sumdigits(string data);
template<class out, class in>
out convert(in a);
int main()
{
    string data;
    string digit[] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    string temp;
    while(cin>>data)
    {
        temp = convert<string>(sumdigits(data));
        for(int i = 0; i < temp.length(); i++)
        {
            cout<<digit[convert<int>(temp[i])];
            if (i != temp.length() - 1)
                cout<<" ";
        }

        cout<<endl;
    }
    return 0;
}

int sumdigits(string data)
{
    if ("" == data)
        return 0;
    int sum = 0;
    sum += convert<int>(data[data.length()-1]);
    sum += sumdigits(data.substr(0, data.length() - 1));
    return sum;
    
}
template<class out, class in>
out convert(in a)
{
    stringstream temp;
    temp<<a;
    out b;
    temp>>b;
    return b;
}