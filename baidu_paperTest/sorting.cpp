#include<iostream>
#include<memory>
#include<vector>
#include<algorithm>
using namespace std;
/*
 *��ż���� 
 *����: �������ɣ�������1000�����Ǹ��������֣�����ȡ��Ϊ���������ְ��Ӵ�С������ȡ��ż����С����  *��������
 
 *����ʱ������: 10 Sec 
 *�ڴ�����: 128 MByte 
 *����: ����һ�����������
 
 *���: �������������
 
 *��������: 12 34 5 7 92 3 8 
 *�������: 7 5 3 8 12 34 92 
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
