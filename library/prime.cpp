#include"library.h"
namespace QCQ
{
    bool IsPrime(int data)
    {
        if (data < 2)
        {
            return false;
        }
        bool flag = true;
        for (int i = 2; i <= sqrt(data); i++)
        {
            if (0 == data % i)
            {
                flag = false;
            }
        }
        return flag;
    }
    int NthPrime(int no)
    {
        if (no > 0)
        {
            int x = NthPrime(no - 1) + 1;
            while(!IsPrime(x))
            {
                x++;
            }
            return x;
        }
        else
        {
            return 1;
        }
    }
}