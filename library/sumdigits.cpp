#include"library.h"
namespace QCQ
{
    int Sumdigits(int data)
    {
        if (0 == data)
            return 0;
        int sum = 0;
        sum += data % 10;
        sum += Sumdigits(data / 10);
        return sum;
    }
    int Sumdigits(std::string data)
    {
        if ("" == data)
            return 0;
        int sum = 0;
        sum += ConvertDataType<int>(data[data.length()-1]);
        sum += Sumdigits(data.substr(0, data.length() - 1));
        return sum;
    }
  
}
