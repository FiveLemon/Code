#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>
#include<ctype.h>
#include<math.h>
/**
@Author：qcq
2014.9.25
qinchuanqing918@163.com

*程序说明，Nokia浙江工业大学校招软件开发中的关于保龄球计分实现程序，
*本程序没有写完，其主要思路如下：
*首先将字符串按照|字符串进行切割并存储，之后做相应的转换，如果字符个数为2
*则将对应的整型数组赋值为相应的数字（如果字符串全是数字的话），如果其中一个字符
*是‘-’，则相应的赋值为-1，如果是‘\’则赋值为-2，如果字符串个数是1这意味着是、x、，则
*将第一维赋值10，第二位赋值-1，
*进行一次遍历将掐中是-1的位剔除，并将整个二维整型转换成一维整型，然后按照相应的规则
*处理即可。
*/
int dealBits(const char* temp);
int deal(const char a);
double fun(double a);
int main()
{
	char a[]= "X|23|4-|5\\|23|X|X|X|32|44";
	
	printf("%d\n",dealBits(a));
	printf("%lf\n",fun(2.3));
	return 0;
}
double fun(double a)
{
	return 2 * pow(a, -1.63);
}
int dealBits(const char* temp)
{
	char str[30];
	char data[10][3];
	int i = 0;
	int score[10][2];
	char *pch;
	char  delime[] = "|";
	int length = 0;
	int k = 0;
	strcpy(str,temp);
	pch = strtok(str, delime);
	
	while(pch != NULL)
	{
		strcpy(data[i++],pch);
		pch = strtok(NULL,delime);
	}
	for(i = 0; i < 10; i++)
	{
	printf("%s\n",data[i]);
	}
	printf("--------------------\n");
	for(i = 0; i < 10; i++)
	{
		length = strlen(data[i]);
		if(2 == length)
		{
			score[i][0] = deal(data[i][0]);
			score[i][1] = deal(data[i][1]);
			
		}
		if(1 == length)
		{
			score[i][0] = 10;
			score[i][1] = -1;
		}
	}
	for(int x = 0; x < 10; x++)
	{
		for(int y = 0; y < 2; y++)
		{
			printf("%d ",score[x][y]);
		}
		printf("\n");
	}
	return 0;
}

int deal(const char a)
{
	if (isalnum(a))
	{
		return a - '0';
	}
	else
	{
		if ('\\' == a)
		{
			return -2;
		}
		else
		{
			return -1;
		}
	}
	
}
