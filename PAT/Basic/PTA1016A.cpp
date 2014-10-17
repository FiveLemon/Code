#include<iostream>
#include<memory>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
using namespace std;
template<class out, class in>
out ConvertDataType(const in& a);
int Countfig(long long A, int DA)
{
    int counter = 0;
    if (0 == A)
    {
        return 0;
    }
    else
    {
        if (DA == A % 10)
        {
            counter++;
        }
        counter += Countfig(A / 10, DA);
    }
    return counter;
}
long long Number(int DA, int counter)
{
    long long data = 0;
    for(int i = 0; i< counter; i++)
    {
        data += DA;
        data *=10;
    }
    return data/10;
}
int main()
{
    long long A;
    int DA;
    long long B;
    int DB;
    while(cin>>A>>DA>>B>>DB)
    {
        //cout<<Countfig(A, DA)<<endl;
        //cout<<Number(DA, Countfig(A, DA))<<endl;
        cout<<Number(DA, Countfig(A, DA))  + Number(DB, Countfig(B, DB))<<endl;
       
    }
    return 0;
}

