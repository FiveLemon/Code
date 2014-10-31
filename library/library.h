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
using std::string;
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
    /*
     *Add����ʵ������������ת�����ַ���֮�����Ӳ�����������λ�������ơ�
     */
    string Add(string op1, string op2);
    /*
     *��ʮ���Ƶ�����dataת����adix���ƣ����ַ�����ʽ����
     */
    string RadixConvert(int data, int radix);
    double Random(double start, double end);

    /*
     *�������
     */
    /*1
     * data����Ҫ��������飬start��end����Ҫ����ķ�Χ��[start, end)
     */
    template <class T>
    void QuickSort(T data[], int start, int end);
    template <class T>
    int Partion(T data[], int start, int end);
    template <class T>
    void Exchange(T &data1, T &data2);
    /*2
    ��������
    * data����Ҫ���������,length������ĳ���
    */
    template<class T>
    void InsertSort(T data[], int length);
    /*3
    *ð������
    * data����Ҫ���������,length������ĳ���
    */
    template<class T>
    void BubbleSort(T data[], int length);
    /*4
    *ѡ������
    * data����Ҫ���������,length������ĳ���
    */
    template<class T>
    void SelectSort(T data[], int length);
    /*5
    *ϣ������  not-stable
    * data����Ҫ���������,length������ĳ���
    */
    template<class T>
    void ShellSort(T data[], int length);
    /*6
    *������  not-stable
    * data����Ҫ���������,length������ĳ���
    */
    template<class T>
    void HeapSort(T data[], int length);
    //ʵ�����ѽṹ,����start��end����Ҫά�������ѵķ�Χ[start, end)
    template<class T>
    void MaxHeap(T data[], int start, int length);
    //ά����ͷ�����ʺ����ĵݹ�汾
    template<class T>
    void MaxHeapRecursive(T data[], int start, int length);
    /*7.1
    *�鲢����֮һ
    * data����Ҫ���������,length������� ���һ��Ԫ���±�[start,end]
    */
    template<class T>
    void MergeSort(T data[], int start, int end);
    template<class T>
    void Merge(T data[], int start, int mid, int end);
    /*7.2
    *�鲢����֮������bug
    * data����Ҫ���������,length������� ���һ��Ԫ���±�[start,end]
    */
    template<class T>
    void MergeSort2(T temp[], T data[], int start, int end);
    template<class T>
    void Merge2(T temp[], T data[], int start, int mid, int end);
    /*7.3
    *�鲢����֮��
    * data����Ҫ���������,length������ĳ���
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
