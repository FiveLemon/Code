#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<map>
using namespace std;

int main()
{
    float data[1200] = {0};
    int k;
    int max_jieci = 0;
    int num;
    float temp;
    cin>>k;
    while(k--)
    {
        cin>>num;
        cin>>temp;
        max_jieci = max(num, max_jieci);
        data[num]+=temp;
    }
    cin>>k;
    while(k--)
    {
        cin>>num;
        cin>>temp;
        max_jieci = max(num, max_jieci);
        data[num]+=temp;

    }
  
    int counter = 0;
    for(int i = 0; i <= max_jieci; i++)
    {
      
        if(0 != data[i])
        {
            counter++;
        }
    }
    cout<<counter;
    for(int i = max_jieci; i >= 0; i--)
    {
        if (0 != data[i])
            printf(" %d %.1f",i,data[i]);
        
    }
    return 0;
}
