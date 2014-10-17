#include "library.h"
namespace QCQ
{
    string RadixConvert(int data, int radix)
    {
        string intermidia;
        if (data < radix)
        {
            return ConvertDataType<string>(data);
        }
        else
        {
            intermidia += ConvertDataType<string>(data % radix);
            intermidia += RadixConvert(data / radix, radix);

        }
        return intermidia;
    }
}
