#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>
/*
*问题背景:有一个有n个元素的数组,从数组取k个元素1<=k<=n,问取得看k个元素的和能组成多少个具有不同和的元素.
*/
/*a数组用于存储从n个整型数
 * 据中取k个数字的数组下标值
 * */
int a[100]={0};
/*data数组用于存储实际的数据,也就是所有砝码的
 * 重量
 * */
 int data[4]={2,2,3,3};
 /*sum数组用于保存再data中取k个树的和,注意
  * 没有唯一化处理,也就是说可能里面存在重复
  * 唯一化处理使用函数unique;
  * */
 int sum[100] = {0};
 /*index_sum用于记录sum中最后一个数据的索引值
  * */
 int index_sum = 0;
 /*这是一个递归实现,用于获取从[start,length-num]的
  * 某一位数,这个位数对应了data数组的下标,num是从
  * data中取几位数的,fujia是一个附加参数,用于记录当
  * 前获取了几位树,从而方便操作数组a
  * */
void GetNumberNew(int start, int length, int num, int fujia);
/*统计长度为length的sum数组中不重复元素的个数
 * */
int unique(int[], int length);
int main()
{
   //data数组长度
    int length = 4;
    
    for(int y = 1; y <= length; y++)
    {
        /*从[0,num]中获取y个数*/
        GetNumberNew(0, length, y, y);
    }
   
    printf("%d",unique(sum, index_sum));
   
    return 0;

}


void GetNumberNew(int start, int length, int num, int fujia)
{
        for(int i = start; i <= length - num; i++)
        {
            if (num > 0)
            {
            a[num - 1] = i;
            /*从[i+1,length]中获取num-1数
             * */
            GetNumberNew(i +1, length, num-1, fujia);
            }
            else
            {
               for(int x = 0; x < fujia; x++)
               {
                    sum[index_sum] += data[a[x]]; 
                }
                index_sum++;
                return;
                }
            }
}
int unique(int sum[], int length)
{
    int temp = index_sum;
   // printf("temp:%d ",temp);
        for(int i = 0 ; i < length - 1; i++)
        {
                for(int j = i + 1; j < length; j++)
                {
                        if(sum[i] == sum[j])
                        {
                            /*若有相同的数字则减1,并退出此次循环*/
                            temp--;
                            break;
                            }
                }
        }
        return temp;
}
