#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>
#include<cmath>
using namespace std;
void format(int number, char symbol);
int main()
{
    int number;
    char symbol;
    cin>>number>>symbol;
    format(number, symbol);
    return 0;
}
void format(int number, char symbol)
{
    int line = sqrt((number + 1) / 2);
    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout<<' ';
        }
        for (int j = 2 * (line - i) - 1; j > 0; j--)
        {
            cout<<symbol;
        }
        cout<<endl;
    }
    for (int i = 2; i <= line; i++)
    {
        for (int j = 0; j < line - i; j++)
        {
            cout<<' ';
        }
        for (int j = 2 * i - 1; j > 0; j--)
        {
            cout<<symbol;
        }
        cout<<endl;
    }
    cout<<number - 2 * pow(line, 2) + 1<<endl;
}