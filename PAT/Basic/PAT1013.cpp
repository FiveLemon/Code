#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool IsPrime(int data);
int NthPrime(int no);
int main()
{
    int min_value, max_value;
    int number = 0;
    cin>>min_value>>max_value;
    int value = NthPrime(min_value);
    for(int i = min_value; i < max_value; i++)
    {
        while(!IsPrime(value))
        {
            value ++;
        } 
        if ((0 == number % 10) && (0 != number))
        {
            cout<<endl;
        }
        if ((9 == number % 10) && (0 != number))
            cout<<value;
        else
            cout<<value<<" ";
        number++;
        value++;
    }
    if ((0 == number % 10)  && (0 != number))
        cout<<endl;
    while(!IsPrime(value))
        value++;
    cout<<value;
    return 0;
}
bool IsPrime(int data)
{
    if (data < 2)
    {
        return false;
    }
    bool flag = true;
    for (int i = 2; i <= sqrt(data); i++)
    {
        if (0 == data % i)
        {
            flag = false;
            break;
        }
    }
    return flag;
}
int NthPrime(int no)
{
    if (no > 0)
    {
        int x = NthPrime(no - 1) + 1;
        while(!IsPrime(x))
        {
            x++;
        }
        return x;
    }
    else
    {
        return 1;
    }
}