/*
 * �ĵ�˵��:this head file contains the function which common used. ʵ���ڶ�Ӧ��Դ�ļ���.
 */
#include<iostream>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<string>
/*
 *ConvertDataType����ʹ��sstreamͷ�ļ�stringstream�࣬ʵ��������������֮���ת��
 */
namespace QCQ
{
    template<class out, class in>
    out ConvertDataType(const in& a);

    /*
     *sumdigits��������������ָ�λ���ֵĺͣ�����Ϊstring���͵Ŀ������������
     */
    int Sumdigits(int data);
    int Sumdigits(std::string data);
    /*
     *MaxSubArray���������������������ĸ��ֺ���
     *MaxSubArrayRecursive���õݹ����ʵ��������������[start, end],�㷨���Ӷ���nlogn
     *MaxSubArrayScan����ɨ���㷨ʵ��������������[0, length),�㷨���Ӷ���n
     */
    template<class T>
    T MaxSubArrayRecursive(T * data,  int start, int end);
    template<class T>
    T MaxSubArrayScan(T * data,  int start, int end);
    void MaxSubArray(int data[], int length);
    /*
     *isPrime���������ж��ǲ�������
     *nthPrime�������ڲ������βθ�����
     */
    bool IsPrime(int data);
    int NthPrime(int no);
    /*
     *��[begin,end]ָ������ݽ��еߵ�(ԭַ),��һ��ָ��汾,�ڶ�������������
     */
    template<class T>
    void Reverse(T* begin, T* end);
    template<class T>
    void Reverse(T begin, T end);
}
#include "convertdatatype.cpp"
#include "reverse.cpp"
#include "maxsubarray.cpp"
