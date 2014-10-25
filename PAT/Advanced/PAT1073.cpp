#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>
#include<cmath>
using namespace std;
template<class out, class in>
out ConvertDataType(const in& a);
int main()
{
    string data;
    string integer;
    string index;
    int bits;
    while(cin>>data)
    {
        integer = data.substr(0, data.find_first_of('E') - 0);
        //cout<<temp<<endl;
        index = data.substr(data.find_first_of('E') + 1);
        int index_int = ConvertDataType<int>(index);
        int dot_place = integer.find_first_of('.');
        if (index_int > 0)
        {
            bits = integer.length() - dot_place - 1;
            if (index_int < bits)
            {
                integer.insert(dot_place + index_int + 1, 1, '.');
                integer.erase(dot_place, 1);
            }
            else
            {
                integer.insert(integer.end(), index_int - bits, '0');
                integer.erase(dot_place, 1);
            }
            if ('+' == integer[0])
                integer.erase(0, 1);
        }
        else if(index_int <= 0)
        { 
            bits = ConvertDataType<int>(integer);
            integer.erase(dot_place, 1);
            
            integer.erase(0, 1);
            integer.insert(integer.begin(), -1 * index_int, '0');
            integer.insert(1, 1, '.');
            if(bits < 0)
            {
                integer.insert(0, 1, '-');
            }
        }
        cout<<integer<<endl;
    }
    return 0;
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