/*
*ConvertDataType����ʹ��sstreamͷ�ļ�stringstream�࣬ʵ��������������֮���ת��
*/
#include<sstream>
template<class out, class in>
out ConvertDataType(const in& a);
/*sumdigits��������������ָ�λ���ֵĺͣ�����Ϊstring���͵Ŀ������������*/
int sumdigits(int data);
int sumdigits(string data);
/*
*MaxSubArray���������������������ĸ��ֺ���
*MaxSubArrayRecursive���õݹ����ʵ��������������[start, end],�㷨���Ӷ���nlogn
*MaxSubArrayScan����ɨ���㷨ʵ��������������[0, length),�㷨���Ӷ���n
*/
template<class T>
T MaxSubArrayRecursive(T * data,  int start, int end);
template<class T>
T MaxSubArrayScan(T * data,  int start, int end);
void MaxSubArray(int data[], int length)��
