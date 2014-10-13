#include"library.h"
/*
 *本文件相较于maxsubarray.cpp的区别在于，maxsubarray.cpp是一个泛型实现，
 *本源文件中的实现是普通实现。
 */
namespace QCQ
{
    void MaxSubArray(int data[], int length)
    {
        int max_sum = -1;
        int sum = 0;
        int temp = 0;
        int first = 0;
        int second = length - 1;
        for(int i = 0; i < length; i++)
        {
            sum += data[i];
            if (sum < 0)
            {
                sum = 0;
                temp = i + 1;
                continue;
            }
            if (sum > max_sum)
            {
                max_sum = sum;
                first = temp;
                second = i;
            }
        }
        std::cout<<std::max(max_sum,0)<<" "<<data[first]<<" "<<data[second]<<std::endl;
    }
}