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
using std::string;
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
    /*
     *Add函数实现了整型数据转换成字符串之后的相加操作，不具有位数的限制。
     */
    string Add(string op1, string op2);
    /*
     *将十进制的整型data转换成adix进制，以字符串形式返回
     */
    string RadixConvert(int data, int radix);
    double Random(double start, double end);

    /*
     *排序程序
     */
    /*1
     * data是需要排序的数组，start和end是需要排序的范围。[start, end)
     */
    template <class T>
    void QuickSort(T data[], int start, int end);
    template <class T>
    int Partion(T data[], int start, int end);
    template <class T>
    void Exchange(T &data1, T &data2);
    /*2
    插入排序
    * data是需要排序的数组,length是数组的长度
    */
    template<class T>
    void InsertSort(T data[], int length);
    /*3
    *冒泡排序
    * data是需要排序的数组,length是数组的长度
    */
    template<class T>
    void BubbleSort(T data[], int length);
    /*4
    *选择排序
    * data是需要排序的数组,length是数组的长度
    */
    template<class T>
    void SelectSort(T data[], int length);
    /*5
    *希尔排序  not-stable
    * data是需要排序的数组,length是数组的长度
    */
    template<class T>
    void ShellSort(T data[], int length);
    /*6
    *堆排序  not-stable
    * data是需要排序的数组,length是数组的长度
    */
    template<class T>
    void HeapSort(T data[], int length);
    //实现最大堆结构,其中start和end是需要维护成最大堆的范围[start, end)
    template<class T>
    void MaxHeap(T data[], int start, int length);
    //维护大头堆性质函数的递归版本
    template<class T>
    void MaxHeapRecursive(T data[], int start, int length);
    /*7.1
    *归并排序之一
    * data是需要排序的数组,length是数组的 最后一个元素下表[start,end]
    */
    template<class T>
    void MergeSort(T data[], int start, int end);
    template<class T>
    void Merge(T data[], int start, int mid, int end);
    /*7.2
    *归并排序之二，有bug
    * data是需要排序的数组,length是数组的 最后一个元素下表[start,end]
    */
    template<class T>
    void MergeSort2(T temp[], T data[], int start, int end);
    template<class T>
    void Merge2(T temp[], T data[], int start, int mid, int end);
    /*7.3
    *归并排序之三
    * data是需要排序的数组,length是数组的长度
    */
    template<class T>
    void MergeSort3(T data[], int length);
    template<class T>
    void MergePass(T temp[], T data[], int start,int end);
}
#include "convertdatatype.cpp"
#include "reverse.cpp"
#include "maxsubarray.cpp"
#include "sortalgorithm.cpp"
