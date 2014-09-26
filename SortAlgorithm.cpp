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
    QuickSort(data, 0, 10);
    for(int i = 0; i < 10; i++)
    {
        cout<<data[i]<<" ";
    }

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
