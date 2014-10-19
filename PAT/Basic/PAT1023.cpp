#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;
template<class out, class in>
out ConvertDataType(const in& a);
int main()
{
    vector<int> data;
    int number;
    int counter = 10;
    vector<int>::iterator start;
    string figure;
    while(counter--)
    {
        cin>>number;
        data.push_back(number);
    }
    for(start = data.begin(); start != data.end(); start++)
    {
        if (0 != *start && start - data.begin() != 0)
        {
            figure = ConvertDataType<string>(start - data.begin());
            (*start)--;
            break;
        }
    }
    for(start = data.begin(); start != data.end(); start++)
    {
        figure.insert(figure.end(), *start, ConvertDataType<char>(start - data.begin()));
    }
    cout<<figure<<endl;
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