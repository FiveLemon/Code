#include<iostream>
#include<memory>
using namespace std;
/*
 *�����
 *����: �������10��С��10������(���ֵ����ֿ����ظ�)��������ȡ��3��������ͬ�����ֿ���ϳ������ͬ��3  *λ�����������Щ3λ���������Ǹ�3λ��

 *����ʱ������: ������
 *�ڴ�����: ������
 *����: 10��С��10�����֣�

 *   1 2 3 4 5 6 7 8 9 0

 *���: �������3λ��

 *  987

 * ��������: 1 2 3 4 5 6 7 8 9 0
 *�������: 987
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
