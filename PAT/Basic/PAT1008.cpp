/*
 * PTA.cpp
 *
 *  Created on: 2014年10月2日
 *      Author: qcq
 */
#include<iostream>
#include<algorithm>
using namespace std;
template<class T>
void reverse(T* begin, T* end);
int main()
{
	int data[100] = {0};
	int N = 0;
	int M = 0;
	while(cin>>N>>M)
	{
		M %= N;
		for (int i = 0; i < N;  i++)
		{
			cin>>data[i];
		}
		//reverse(data, data + N - 1);
		reverse(data + N  - M, data + N - 1);
		reverse(data, data + N - M -1);
		reverse(data, data + N - 1);
		for (int i = 0; i < N - 1; i++)
		{
			cout<<data[i]<<" ";
		}
		cout<<data[N-1]<<endl;
	}

	return 0;
}

template<class T>
void reverse(T* begin, T* end)
{
	while (begin < end)
	{

		swap(*begin, * end);
		begin++;
		end--;
	}
}

