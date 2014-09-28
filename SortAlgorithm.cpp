/*
* This C++ program implement many sort algorithm
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
//Quick Sort algorithm. not-stable
/*1
* data是需要排序的数组，start和end是需要排序的范围。
*/
template <class T>
void QuickSort(T data[], int start, int end);
template <class T>
int Partion(T data[], int start, int end);
template<class T>
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
int main()
{
    double random(double,double);
    srand(unsigned(time(0)));
    double data[10],temp[10];
    for(int i = 0; i < 10; i++)
    {
        data[i] = random(0,100);
        temp[i] = data[i];
       cout<<data[i]<<" ";
    }
    cout<<endl;
    MergeSort2(temp,data, 0,9);
    for(int i = 0; i < 10; i++)
    {
        cout<<data[i]<<" ";
    }
    return 0;

}

double random(double start, double end)
{
    return start+(end-start)*rand()/(RAND_MAX + 1.0);
}
template <class T>
void QuickSort(T data[], int start, int end)
{
    if (start < end - 1)
    {
        int q = Partion(data, start, end);
        QuickSort(data, start, q );
        QuickSort(data, q + 1, end);
    }
}
template <class T>
int Partion(T data[], int start, int end)
{
    T x = data[end - 1];
    int i = start - 1;
    for(int j = start; j < end - 1; j++)
    {
        if (data[j] <= x)
        {
            i++;
            Exchange(data[j], data[i]);

        }
    }
    Exchange(data[i + 1], data[end - 1]);
    return i + 1;
}
template <class T>
void Exchange(T &data1, T &data2)
{
    T temp;
    temp = data1;
    data1 = data2;
    data2 = temp;
}

template<class T>
void InsertSort(T data[], int length)
{
    int j = 0;
    T key;
    for(int i = 1; i < length; i++)
    {
        j = i - 1;
        key = data[i];
        while(j > -1 && data[j] > key)
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;

    }
}
template<class T>
void BubbleSort(T data[], int length)
{
    bool flag = true;
    for(int i = 0; i < length -1 && flag; i++)
    {
        flag = false;
        for(int j = i; j < length - 1; j++)
        {
            if (data[j] > data[j + 1])
            {
                Exchange(data[j], data[j + 1]);
                flag = true;
            }
        }
    }
}

template<class T>
void SelectSort(T data[], int length)
{
    int min_value;
    for(int i = 0; i < length - 1; i ++)
    {
        min_value = i;
        for(int j = i + 1; j < length; j++)
        {
            if(data[min_value] > data[j])
            {
                min_value = j;
            }
        }
        if(min_value != i)
        {
            Exchange(data[min_value], data[i]);
        }

    }
}

template<class T>
void ShellSort(T data[], int length)
{
    int i,j;
    T key;
    int increment = length;
    do
    {
        increment = increment / 3 + 1;
        for(i = increment + 1; i < length; i++)
        {
            if(data[i] < data[i - increment])
            {
                key = data[i];
                for(j = i - increment; j > -1 && key < data[j]; j -= increment)
                {
                    data[j + increment] = data[j];
                }
                data[j + increment] = key;
            }
        }
    }while(increment > 1);

}

template<class T>
void HeapSort(T data[], int length)
{
	int i;
    for(i = length / 2 - 1; i > -1; i --)
    {
        //MaxHeap(data, i, length);
        MaxHeapRecursive(data, i, length);
    }
    for(i = length - 1; i > 0; i--)
    {
        Exchange(data[0], data[i]);
        MaxHeap(data, 0, i);
    }
}
template<class T>
void MaxHeap(T data[], int start, int end)
{
	int j;
    T key;
    key = data[start];
    for(j = 2 * start + 1; j < end; j = 2 * j + 1)
    {
        if(j < end - 1 && data[j] < data[j + 1])
        {
            j++;
        }
        if(key > data[j])
            break;
        data[start] = data[j];
        start = j;
    }
    data[start] = key;              

}
template<class T>
void MaxHeapRecursive(T data[], int start, int end)
{
    int left = 2 * start + 1;
    int right = left + 1;
    int largest = start;
    if (left < end && data[left] > data[start])
    {
        largest = left;
    }
    if (right < end && data[right] > data[largest])
    {
        largest = right;
    }
    if(largest != start)
    {
        Exchange(data[largest], data[start]);
        MaxHeapRecursive(data, largest, end);
    }
}
template<class T>
void MergeSort(T data[], int start, int end)
{
    if (start < end)
    {
        int mid;
        mid = (start + end) / 2;
        MergeSort(data, start, mid);
        MergeSort(data, mid + 1, end);
        Merge(data, start, mid, end);
    }
}
template<class T>
void Merge(T data[], int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;
    T *left = new T[n1 + 1];
    T *right = new T[n2 + 1];
    int i = 0;
    for(i = 0; i < n1; i++)
    {
        left[i] = data[start + i];
    }
    for(i = 0; i < n2; i++)
    {
        right[i] = data[mid + i + 1];
    }
    left[n1] = INT_MAX;
    right[n2] = INT_MAX;
    i = 0;
    int j = 0;
    for(int k = start; k < end + 1; k++)
    {
        if(left[i] <= right[j])
        {
            data[k] = left[i];
            i++;
        }
        else
        {
            data[k] = right[j];
            j++;
        }
    }
    delete[] right;
    delete[] left;
}

template<class T>
void MergeSort2(T temp[], T data[], int start, int end)
{
    int m;
    T * p =  new T[end - start + 1];
    if(start == end)
    {
        data[start] = temp[start];
    }
    else

    {
        m = (start + end) / 2;
        MergeSort2(temp, p, start, m);
        MergeSort2(temp, p, m + 1, end);
        Merge2(p, data, start, m, end);
        
    }
    delete [] p;
}
template<class T>
void Merge2(T SR[], T TR[], int i, int m, int n)
{
    int j,k,l;
    for(j = m + 1, k = i; i <= m && j <= n; k++)
    {
        if(SR[i] < SR[j])
        {
            TR[k] = SR[i++];
        }
        else
        {
            TR[k] = SR[j++];
        
        }
    }
        if(i <= m)
        {
            for(l = 0; l <= m - i; l++)
            {
                TR[k + l] = SR[i + l];
            }
        }
        if(j <= n)
        {
            for(l = 0; l <= n - j; l ++)
            {
                TR[k + l] =SR[j + l];
            }
        }
}
template<class T>
void MergeSort3(T data[], int length)
{
    T * TR = new T[length];
    int k = 1;
    while(k < length)
    {
        MergePass(data, TR, k, length);
        k *= 2;
        MergePass(TR, data, k, length);
        k *= 2;
    }
}
template<class T>
void MergePass(T SR[], T TR[], int s,int n)
{
    int i = 1;
    int j;
    while(i <= n - 2 * s + 1)
    {
        Merge2(SR, TR, i, i + s -1, i + 2 * s - 1);
        i = i + 2 * s;
    }
    if(i < n - s + 1)
    {
        Merge2(SR, TR, i, i + s -1, n);

    }
    else
    {
        for(j = i; j <= n; j++)
        {
        
            TR[j] = SR[j];
        }
    }
}