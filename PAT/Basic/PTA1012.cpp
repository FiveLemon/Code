#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
#include<cmath>
using namespace std;
typedef struct Data
{
    int data[1000];
    int range;
}Data;
void Classify(Data datatemp[], int data[], int length);
float Deal(Data datatemp[], int data[]);

int main()
{
    int number;
    int data[1000];
    float data3 = 0;
    cin>>number;
    for(int i = 0; i < number; i++)
    {
        cin>>data[i];
    }
    Data datatemp[5];
    Classify(datatemp, data, number);
    data3 = Deal(datatemp, data);
    if (data[0] == 0)
        {
            cout<<"N"<<" ";
        }
        else
        {
            cout<<data[0]<<" ";
        }
    for(int i = 1; i < 3;i++)
    {
        if (datatemp[i].range == 0)
        {
            cout<<"N"<<" ";
        }
        else
        {
            cout<<data[i]<<" ";
        }
    }
    if (datatemp[3].range  == 0)
    {
        cout<<"N"<<" ";
    }
    else
    {
        printf("%.1f ",data3);
    }
    if (0 == datatemp[4].range )
    {
        cout<<"N";
    }
    else
    {
        cout<<data[4]<<endl;
    }
    return 0;
}
void Classify(Data datatemp[], int data[], int length)
{
    int k = 0;
    int j = 0;
    int x = 0;
    int y = 0;
    int z = 0;
    for(int i = 0; i < 5; i ++)
    {
        datatemp[i].range = 0;
    }
    for (int i = 0; i < length; i++)
    {
        if (0 == data[i] % 5)
        {
            datatemp[0].data[k++] = data[i];
            datatemp[0].range = k;
        }
        else if (1 == data[i] % 5)
        {
            datatemp[1].data[j++] = data[i];
            datatemp[1].range = j;
        }
        else if (2 == data[i] % 5)
        {
            datatemp[2].data[x++] = data[i];
            datatemp[2].range = x;
        }
        else if (3 == data[i] % 5)
        {
            datatemp[3].data[y++] = data[i];
            datatemp[3].range = y;
        }
        else
        {
            datatemp[4].data[z++] = data[i];
            datatemp[4].range = z;
        }
    }
}

float Deal(Data datatemp[], int data[])
{
    float data3 = 0;
    for(int i = 0; i < 5; i++)
    {
        data[i] = 0;
    }
    for (int i = 0; i < 5; i++)
    {
        if (0 == i)
        {
            for(int j = 0; j < datatemp[i].range; j++)
            {
                if (0 == datatemp[i].data[j] % 2)
                {
                    data[i] += datatemp[i].data[j];
                }
            }
        }
        else if (1 == i)
        {
            for(int j = 0; j < datatemp[i].range; j++)
            {
                 data[i] += datatemp[i].data[j] * pow(-1, j + 2);
            }
        }
        else if (2 == i)
        {
            data[i] = datatemp[i].range;
        }
        else if (3 == i)
        {
            for(int j = 0; j < datatemp[i].range; j++)
            {
                 data[i] += datatemp[i].data[j];
            }
            if(datatemp[i].range != 0)
                data3 = data[i] * 1.0 / datatemp[i].range;
        }
        else
        {
            for(int j = 0; j < datatemp[i].range; j++)
            {
                 data[i] = max(data[i], datatemp[i].data[j]);
            }
        }
    }
    return data3;
}