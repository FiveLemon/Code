/*
* This C++ program implement many sort algorithm
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
//Quick Sort algorithm.
/*
* data是需要排序的数组，start和end是需要排序的范围。
*/
template <class T>
void QuickSort(T data[], int start, int end);
template <class T>
int Partion(T data[], int start, int end);
template<class T>
void Exchange(T &data1, T &data2);

/*
插入排序
* data是需要排序的数组,length是数组的长度
*/
template<class T>
void InsertSort(T data[], int length);
/*
*冒泡排序
* data是需要排序的数组,length是数组的长度
*/
template<class T>
void BubbleSort(T data[], int length);
/*
*选择排序
* data是需要排序的数组,length是数组的长度
*/
template<class T>
void SelectSort(T data[], int length);
/*
*希尔排序  not-stable
* data是需要排序的数组,length是数组的长度
*/
template<class T>
void ShellSort(T data[], int length);
int main()
{
    double random(double,double);
    srand(unsigned(time(0)));
    double data[10];
    for(int i = 0; i < 10; i++)
    {
        data[i] = random(0,100);
       cout<<data[i]<<" ";
    }
    cout<<endl;
    ShellSort(data,10);
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
