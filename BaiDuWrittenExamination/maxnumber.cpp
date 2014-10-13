#include<iostream>
#include<memory>
using namespace std;
/*
 *最大数
 *描述: 随机给定10个小于10的数字(出现的数字可能重复)，从其中取出3个各不相同的数字可组合出多个不同的3  *位数，请输出这些3位数中最大的那个3位数

 *运行时间限制: 无限制
 *内存限制: 无限制
 *输入: 10个小于10的数字：

 *   1 2 3 4 5 6 7 8 9 0

 *输出: 输出最大的3位数

 *  987

 * 样例输入: 1 2 3 4 5 6 7 8 9 0
 *样例输出: 987
 */
int MaxNumber(bool data[], int bits, int length);
int main()
{
    int temp = 0;
    int i = 0;
    bool data[10];
    int bit = 3;
    memset(data, false, sizeof(bool) * 10);
    for (i = 0; i < 10; i++)
    {
        cin>>temp;
        data[temp] = true;
    }
    cout<<MaxNumber(data, bit, 10)<<endl;;
    return 0;
}
int MaxNumber(bool data[], int bits, int length)
{
    int counter = 0;
    int temp = 0;
    for(int i = length - 1; i >= 0 && counter < bits; i--)
    {
        if (true == data[i])
        {
            counter++;
            temp += i;
            temp *= 10;
        }
    }
    return temp / 10;
}
