#include"library.h"
namespace QCQ
{
    string Add(string op1, string op2)
    {
        string long_string, short_string;
        int temp;
        int index_long, index_short;
        int carry = 0;
        if (op1.length() > op2.length())
        {
            long_string = op1;
            short_string = op2;
        }
        else
        {
            long_string = op2;
            short_string = op1;

        }
        for (index_long = long_string.length() - 1, index_short = short_string.length() - 1; index_short >= 0; index_long--, index_short--)
        {
            temp = ConvertDataType<int>(long_string[index_long]) + ConvertDataType<int>(short_string[index_short]) + carry;
            long_string[index_long] = ConvertDataType<char>(temp % 10);
            carry = temp / 10;
        }
        for (; index_long >= 0; index_long--)
        {
            if (0 == carry)
            {
                break;
            }
            temp = carry + ConvertDataType<int>(long_string[index_long]);
            long_string[index_long] = ConvertDataType<char>(temp % 10);
            carry = temp /10;
        }
        if (0 != carry)
        {
            long_string.insert(long_string.begin(), ConvertDataType<char>(carry));
        }
        return long_string;
    }
}
