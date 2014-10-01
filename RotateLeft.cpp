#include<iostream>
#include<string.h>
using namespace std;
/*
 *问题描述:将一个n元向量向左旋转i个位置,比如当n=8,且i=3时,向量
 * abcdefgh->defghabc
 * 
 * */
 /*
  *本函数用于交换[a,a+m-1]和[b,b+m-1]对应元素
  * */
 template<class T>
 void swap(T *a,T * b,int m);
 template<class T>
 void RotateLeft(T[], int i);
int main()
{
    char temp[] = {"abcdefgh"};
   int i = 0;
   while (temp[i] != '\0')
   {
       cout<<temp[i]<<" ";
        i++;
       }
   
   RotateLeft(temp, 3);
   cout<<endl;
   i = 0;
   while (temp[i] != '\0')
   {
       cout<<temp[i]<<" ";
        i++;
       }
    return 0;
}

 template<class T>
 void swap(T *a,T * b,int m)
 {
    int i = 0;
    T temp;
    while(i++ < m)
    {
        temp = a[i - 1];
        a[i - 1] = b[i - 1];
        b[i - 1] = temp;
        }
}

 template<class T>
 void RotateLeft(T data[], int distance)
 {
     int n = strlen(data);
    if (0 == distance || n == distance )
    {
        return;
     }
     int i;
     int p;
     int j;
     i = p = distance;
     j = n - p;
     while(i != j)
     {
        if (i > j)
        {
            swap(data + p - i, data + p, j);
            i-=j;
        }
        else
        {
            swap(data + p - i, data + p + j - i, i);
            j -= i;
        }
    }
    swap(data + p - i, data +p, i);
 }
