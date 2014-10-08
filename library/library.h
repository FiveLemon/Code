/*
*ConvertDataType函数使用sstream头文件stringstream类，实现任意数据类型之间的转换
*/
#include<sstream>
template<class out, class in>
out ConvertDataType(const in& a);
/*sumdigits用于求解整型数字各位数字的和，参数为string类型的可以求解更大的数*/
int sumdigits(int data);
int sumdigits(string data);
/*
*MaxSubArray用于求解最大字数组和问题的各种函数
*MaxSubArrayRecursive采用递归策略实现求解最大子数组[start, end],算法复杂度是nlogn
*MaxSubArrayScan采用扫描算法实现求解最大字数组[0, length),算法复杂度是n
*/
template<class T>
T MaxSubArrayRecursive(T * data,  int start, int end);
template<class T>
T MaxSubArrayScan(T * data,  int start, int end);
void MaxSubArray(int data[], int length)；
