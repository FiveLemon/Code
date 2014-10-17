#include<iostream>
#include<memory>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
using namespace std;
string GetNumber(string data, char bit);
string Add(string op1, string op2);
template<class out, class in>
out ConvertDataType(const in& a);
/*
 *�����������PTA1016.cpp����ķ���������һ���ԣ�PTA1016A��ʹ����long long��������ʵ�ּӷ�
 *PTA1016Bʹ���ַ�����ʾ��������ӣ���ˣ�������һ���ԣ�����Ҫλ�������ơ�
 */
int main()
{
    string A;
    char DA;
    string B;
    char DB;
    while(cin>>A>>DA>>B>>DB)
    {
        cout<<Add(GetNumber(A, DA), GetNumber(B, DB))<<endl;

    }
    return 0;
}
string GetNumber(string data, char bit)
{
    int counter = 0;
    for (int i = 0; i < data.length(); i++)
    {
        if (bit == data[i])
        {
            counter++;
        }
    }
    string temp(counter, bit);
    /*
     *��ֹ���ֿ��ַ���
     */
    if (temp.empty())
    {
        temp = "0";
    }
    /*
     * ��ֹ����0000�������
     */
    string last = ConvertDataType<string>(ConvertDataType<int>(temp));
    return last;
}
string Add(string op1, string op2)
{
    string long_string, short_string;
    int temp;
    int index_long, index_short;
    int carry = 0;
    if (op1.length() > op2.length())
    {
        long_string = op1;
        short_string = op2;
    }
    else
    {
        long_string = op2;
        short_string = op1;

    }
    for (index_long = long_string.length() - 1, index_short = short_string.length() - 1; index_short >= 0; index_long--, index_short--)
    {
        temp = ConvertDataType<int>(long_string[index_long]) + ConvertDataType<int>(short_string[index_short]) + carry;
        long_string[index_long] = ConvertDataType<char>(temp % 10);
        carry = temp / 10;
    }
    for (; index_long >= 0; index_long--)
    {
        if (0 == carry)
        {
            break;
        }
        temp = carry + ConvertDataType<int>(long_string[index_long]);
        long_string[index_long] = ConvertDataType<char>(temp % 10);
        carry = temp /10;
    }
    if (0 != carry)
    {
        long_string.insert(long_string.begin(), ConvertDataType<char>(carry));
    }
    return long_string;
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
