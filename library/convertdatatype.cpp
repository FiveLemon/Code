/*
*ConvertDataType����ʹ��sstreamͷ�ļ�stringstream�࣬ʵ��������������֮���ת��
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
