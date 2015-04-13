#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int data[101];
    
    int a, n;
    while(cin>>a>>n)
    {
        
        memset(data, 0, sizeof(data));
        for (int i = 1; i <= n; i++)
        {
            data[0] = max(i, data[0]);
            for (int j = 1; j <= i; j++)
            {
                data[j] += a;
            }
            for (int j = 1; j <= data[0]; j++)
            {
                if (data[j] >= 10)
                {
                    data[j + 1] += data[j] / 10;
                    data[j] %= 10;
                    if (j == data[0])
                        data[0]++;
                }
                
            }
        }
        for(int i = data[0]; i >= 1; i--)
        {
            cout<<data[i];
        }
        cout<<endl;
    }
    return 0;

}