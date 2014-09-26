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
void InsertionSort(T data[], int length);
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
    InsertionSort(data,10);
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
void InsertionSort(T data[], int length)
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
