/*
*ConvertDataType函数使用sstream头文件stringstream类，实现任意数据类型之间的转换
*/
#include"library.h"
template<class out, class in>
out ConvertDataType(const in& a)
{
    stringstream temp;
    temp<<a;
    out b;
    temp>>b;
    return b;
}
