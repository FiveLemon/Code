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
void Judge(int A, int B, int C);
int main()
{
    int number;
    cin>>number;
    int A[10] = {0},B[10]={0},C[10]={0};
    for (int i = 0; i < number; i++)
    {
        cin>>A[i]>>B[i]>>C[i];
    }
    for (int i = 0; i < number; i++)
        {
            cout<<"Case #"<<i + 1<<": ";
            Judge(A[i], B[i], C[i]);
        }
    return 0;
}
void Judge(int A, int B, int C)
{
    if ((A >= 0 && B >= 0 && C >= 0)||
            (A < 0 && B < 0 && C < 0))
    {
        if (A > C - B)
        {
            cout<<"true"<<endl;
        }
        else
        {
            cout<<"false"<<endl;
        }
    }
    else if ((A < 0 && B >= 0 && C >= 0)||
            (A >= 0 && B < 0 && C >= 0)||
            (A < 0 && B >= 0 && C < 0)||
            (A >= 0 && B < 0 && C < 0)
            )
    {
        if (A + B > C)
        {
            cout<<"true"<<endl;
        }
        else
        {
            cout<<"false"<<endl;
        }
    }
    else if ((A < 0 && B < 0 && C >= 0))
    {
        cout<<"false"<<endl;
    }
    else
    {
        cout<<"true"<<endl;
    }
}


