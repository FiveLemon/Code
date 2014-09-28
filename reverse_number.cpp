#include<iostream>
#include<string>
using namespace std;
/*2015 Tencent 软件开发-PC客户端一个题目，求DNA的逆序数*/
int reverse(char *pdna, int length);
int main1()
{
	char temp[]={"AGCTGTGTCATGCATACGTA"};
	cout<<reverse(temp, strlen(temp));
	return 0;
}

int reverse(char* pdna, int length)
{
	int sum = 0;
	int temp[4] = {0};
	for(int i = 0; i < length; i++)
	{
		switch(pdna[i])
		{
		case 'A':
			sum += temp[1];
			sum += temp[2];
			sum += temp[3];

			break;
		case 'C':
			temp[1]++;
			sum += temp[2];
			sum += temp[3];
			break;
		case 'G':
			temp[2]++;
			sum += temp[3];
			break;
		case 'T':
			temp[3]++;
			break;
		default:
			return -1;
		}
	}
	return sum;
}