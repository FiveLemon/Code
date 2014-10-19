#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;
typedef struct MoonCake
{
    float storage;
    float totalprice;
    float singleprice;
    
}MoonCake;
bool compare(MoonCake cake1, MoonCake cake2)
{
    return cake1.singleprice > cake2.singleprice;
}
int main()
{
    int kind;
    float market;
    float sum = 0.0;
    float money = 0.0;
    cin>>kind>>market;
    MoonCake *cake = new MoonCake[kind];
    for(int  i = 0; i < kind; i++)
    {
        cin>>cake[i].storage;
    }
    for(int i = 0; i < kind; i++)
    {
        cin>>cake[i].totalprice;
        cake[i].singleprice = cake[i].totalprice / cake[i].storage;
    }
    sort(cake, cake + kind, compare);
    for(int i = 0; i < kind; i++)
    {
        sum += cake[i].storage;
        money += cake[i].totalprice;
        if (sum >= market)
        {
            sum -= cake[i].storage;
            money -= cake[i].totalprice;
            money += cake[i].singleprice * (market - sum);
            break;
        }
    }
    printf("%.2f",money);
    return 0;
}
