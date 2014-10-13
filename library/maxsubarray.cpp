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

    
}
