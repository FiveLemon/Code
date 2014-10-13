#include"library.h"
namespace QCQ
{
    template<class T>
    T MaxSubArrayRecursive(T * data,  int start, int end)
    {
        if (start > end)
        {
            return 0;
        }
        else if ( start == end)
        {
            return max(0, data[start]);
        }
        else
        {
            int mid = (start + end) / 2;
            T sum_left = 0;
            T sum = 0;
            for(int i = mid; i >= start; i--)
            {
                sum += data[i];
                sum_left = max(sum, sum_left);
            }
            T sum_right = 0;
            sum = 0;
            for(int i = mid + 1; i <= end; i++)
            {
                sum += data[i];
                sum_right = max(sum_right, sum);
            }
            return max(sum_right+sum_left, max(MaxSubArray(data, start, mid, first, second), MaxSubArray(data, mid + 1, end, first, second)));
        }

    }
    template<class T>
    T MaxSubArrayScan(T * data,  int start, int end)
    {
        T maxsofar = 0;
        T maxendinghere = 0;
        for(int i = 0; i < length; i++)
        {

            maxendinghere = max(maxendinghere + data[i], 0);
            maxsofar = max(maxsofar, maxendinghere);
        }
        return maxsofar;
    }

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