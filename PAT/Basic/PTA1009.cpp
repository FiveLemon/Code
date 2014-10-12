/*
 * PTA.cpp
 *
 *  Created on: 2014年10月9日
 *      Author: qcq
 */
/*
 * PTA.cpp
 *
 *  Created on: 2014年10月2日
 *      Author: qcq
 */
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
template<class T>
void Reverse(T begin, T end);
int main()
{
    string temp;
    getline(cin, temp);
    string::iterator start = temp.begin();
    string::iterator end = temp.end();
    string::iterator temporary = start;
    Reverse(start, end -1);
    for (string::iterator i = start; i < end; i++)
    {

        if (' ' == *i)
        {
            Reverse(temporary, i - 1);
            temporary = i + 1;
        }
    }
    Reverse(temporary, end - 1);
    for (string::iterator i = start; i < end; i++)
    {
        cout<<*i;
    }
    return 0;
}

template<class T>
void Reverse(T begin, T end)
{
    while (begin < end)
    {
        swap(*begin, * end);
        begin++;
        end--;
    }
}
