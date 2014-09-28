#include<iostream>
#include<string.h>
#include<assert.h>
using namespace std;
/*
 * 这是2015年大数据云计算工程师百度校招的题目
 * 题目说不适用任何库函数,实现英语文章的逆序输出,
 * 也就是最后一个单词变成第一个单词,以此类推.
 * 以下为程序实现.
 * */
 /*第一种方法，严格意义上说使用了new操作符*/
char* reverse(char * word);
/*另外一种策略，严格意义上说其调用了求解字符串长度的库函数，需要自行实现这个函数*/
void Reverse(char *pbegin,char *pend);
char *ReverseSentence(char *str);
int main()
{
        char temp[] = {"There are so many sth."};
        cout<<ReverseSentence(temp)<<endl;
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

void Reverse(char *pbegin,char *pend)
{
    if(pbegin==NULL||pend==NULL)
        return;
    while(pbegin<pend)
    {
        char tmp;
        tmp=*pbegin;
        *pbegin=*pend;
        *pend=tmp;
        ++pbegin;
        --pend;
    }
}
char *ReverseSentence(char *str)
{
    assert(str!=NULL);
    Reverse(str,str+strlen(str)-1);
    char *base=str;
    int WordLen=0;
    char *WordBase=str;
    while(*str!='\0')
    {
        if(*str!=' ')
            ++WordLen;
        else
        {
            Reverse(WordBase,WordBase+WordLen-1);
            WordLen=0;
            WordBase=str+1;
        }
        str++;
    }
    Reverse(WordBase,WordBase+WordLen-1);
    return base;
}
