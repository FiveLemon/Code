#include<iostream>
#include<memory.h>
using namespace std;
int main()
{
    int data[10000];
    
    int number;
    while(cin>>number)
    {
        memset(data,0,sizeof(data));
        data[0] = 1;
        data[1] = 1;
        for (int i = 2; i <= number; i++)
        {
            for(int j = 1; j <= data[0]; j++)
            {
                data[j] *= i;
            }
            for (int j = 1; j <= data[0]; j++)
            {
                if (data[j] >= 10)
                {
                    data[j + 1] += data[j] / 10;
                    data[j] %= 10;
                    if (j == data[0])
                    {
                        data[0]++;
                    }
                }
            }
        }
        for(int i = data[0]; i > 0; i--)
        {
            cout<<data[i];
        }
        cout<<endl;
    }
    return 0;
}
