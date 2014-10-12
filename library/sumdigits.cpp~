#include"library"
int sumdigits(int data)
{
    if (0 == data)
        return 0;
    int sum = 0;
    sum += data % 10;
    sum += sumdigits(data / 10);
    return sum;
}
int sumdigits(string data)
{
    if ("" == data)
        return 0;
    int sum = 0;
    sum += ConvertDataType<int>(data[data.length()-1]);
    sum += sumdigits(data.substr(0, data.length() - 1));
    return sum;
}
