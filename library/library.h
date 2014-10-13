/*
 * 文档说明:this head file contains the function which common used. 实现在对应的源文件内.
 */
#include<iostream>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<string>
/*
 *ConvertDataType函数使用sstream头文件stringstream类，实现任意数据类型之间的转换
 */
namespace QCQ
{
    template<class out, class in>
    out ConvertDataType(const in& a);

    /*
     *sumdigits用于求解整型数字各位数字的和，参数为string类型的可以求解更大的数
     */
    int Sumdigits(int data);
    int Sumdigits(std::string data);
    /*
     *MaxSubArray用于求解最大字数组和问题的各种函数
     *MaxSubArrayRecursive采用递归策略实现求解最大子数组[start, end],算法复杂度是nlogn
     *MaxSubArrayScan采用扫描算法实现求解最大字数组[0, length),算法复杂度是n
     */
    template<class T>
    T MaxSubArrayRecursive(T * data,  int start, int end);
    template<class T>
    T MaxSubArrayScan(T * data,  int start, int end);
    void MaxSubArray(int data[], int length);
    /*
     *isPrime函数用于判断是不是素数
     *nthPrime函数用于产生第形参个素数
     */
    bool IsPrime(int data);
    int NthPrime(int no);
    /*
     *将[begin,end]指向的内容进行颠倒(原址),第一个指针版本,第二个迭代器重载
     */
    template<class T>
    void Reverse(T* begin, T* end);
    template<class T>
    void Reverse(T begin, T end);
}
#include "convertdatatype.cpp"
#include "reverse.cpp"
#include "maxsubarray.cpp"
