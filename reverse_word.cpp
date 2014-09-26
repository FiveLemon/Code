#include<iostream>
using namespace std;
/*
 * 这是2015年大数据云计算工程师百度校招的题目
 * 题目说不适用任何库函数,实现英语文章的逆序输出,
 * 也就是最后一个单词变成第一个单词,以此类推.
 * 以下为程序实现.
 * */
char* reverse(char * word);
int main()
{
        char temp[] = {"There are so many sth."};
        cout<<reverse(temp)<<endl;
        return 0;
}
char* reverse(char * word)
{
        int length = -1;
        int count = 0;
        int index=0;
        while(word[++length] != '\0');
        cout<<length<<endl;
        char *temp = new char[length + 1];
        for(int i = length - 1; i >= 0; i --)
        {
                if (word[i] != ' ')
                {
                        count++;
                        continue;
                }
                for(int j = i  + 1; j < count + i  + 1; j++)
                {
                        temp[index++] = word[j];
                }
                count = 0;
                temp[index++] = ' ';
        }
        count = 0;
        while(word[count] != ' ')
        {
            temp[index++] = word[count];
            count++;
            }
        temp[index] = '\0';
        return temp;
        
}
