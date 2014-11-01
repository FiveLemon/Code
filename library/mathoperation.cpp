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
        /*
         *next section deal with the common section(tail section) of the long_string and short_string
         */
        for (index_long = long_string.length() - 1, index_short = short_string.length() - 1; index_short >= 0; index_long--, index_short--)
        {
            temp = ConvertDataType<int>(long_string[index_long]) + ConvertDataType<int>(short_string[index_short]) + carry;
            long_string[index_long] = ConvertDataType<char>(temp % 10);
            carry = temp / 10;
        }
        /*
         * next segment deal with the long_string's long section than short_string.
         */
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
        /*
         * deal with the last carray bit of two string.
         */
        if (0 != carry)
        {
            long_string.insert(long_string.begin(), ConvertDataType<char>(carry));
        }
        return long_string;
    }
    string Multiply(string op1, char b, int bit)
    {
        int carry = 0;
        int temp = 0;
        if ('0' == b)
        {
            return "0";
        }
        for (int i = op1.size() - 1; i >= 0; i--)
        {
            temp = ConvertDataType<int>(op1[i]) * ConvertDataType<int>(b) + carry;
            op1[i] = ConvertDataType<char>(temp % 10);
            carry = temp / 10;
        }
        if (0 != carry)
        {
            op1.insert(op1.begin(), ConvertDataType<char>(carry));
        }
        while(bit--)
        {
            op1.insert(op1.end(),'0');
        }
        return op1;
    }
    string Multiply(string op1, string op2)
    {
        string sum = "0";
        for (int i = op2.length() - 1, j = 0; i >= 0; i--, j++)
        {
            sum = Add(sum, Multiply(op1, op2[j], i));
        }
        return sum;
    }
}
