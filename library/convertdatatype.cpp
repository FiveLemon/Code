/*
*ConvertDataType����ʹ��sstreamͷ�ļ�stringstream�࣬ʵ��������������֮���ת��
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
