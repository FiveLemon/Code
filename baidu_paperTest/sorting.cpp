#include<iostream>
#include<memory>
#include<vector>
#include<algorithm>
using namespace std;
/*
 *奇偶排序 
 *描述: 输入若干（不超过1000个）非负整数数字，请先取出为奇数的数字按从大到小排序，再取出偶数从小到大  *进行排序。
 
 *运行时间限制: 10 Sec 
 *内存限制: 128 MByte 
 *输入: 输入一串乱序的数字
 
 *输出: 输出排序后的数字
 
 *样例输入: 12 34 5 7 92 3 8 
 *样例输出: 7 5 3 8 12 34 92 
 */
bool IsOdd (int i) { return (i%2)==1; }
bool compare(int i, int j)
{
    return i > j;
}
int main()
{
    int temp;
    vector<int> data;
    while(cin>>temp)
    {
        data.push_back(temp);
    }
    vector<int>::iterator middle = stable_partition(data.begin(),data.end(),IsOdd);
    sort(data.begin(), middle, compare);
    sort(middle, data.end());
    for(vector<int>::iterator temp = data.begin(); temp != data.end(); temp++)
    {
        cout<<*temp<<" ";
    }
}
