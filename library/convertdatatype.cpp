/*
*ConvertDataType函数使用sstream头文件stringstream类，实现任意数据类型之间的转换
*/
namespace QCQ
{
    template<class out, class in>
    out ConvertDataType(const in& a)
    {
        std::stringstream temp;
        temp<<a;
        out b;
        temp>>b;
        return b;
    }
}
