#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
bool prime(int i);
int main()
{
    int number;
    cin>>number;
    int counter;
    vector<int> data;
    data.push_back(2);
    typedef vector<int>::iterator iter;
    for (int i = 3;i <= number; i++)
    {
        if (prime(i))
        {
            //cout<<i<<" ";
            data.push_back(i); 
        }
    }
    counter = 0;
    for(iter start = data.begin(); start != data.end() - 1; start++)
    {
        if(2 == *(start + 1) - *(start))
        {
            counter++;
        }
    }
    cout<<counter<<endl;
    return 0;
}
bool prime(int n)
{
    int i, bound;
    if ( 0 == n % 2)
        return 2 == n;
    if (0 == n % 3)
        return 3 == n;
    if (0 == n % 5)
        return 5 == n;
    bound = sqrt(n);
    for (i = 7; i <= bound; i+=2)
    {
        if (0 == n % i)
        {
            return false;
        }
    }
    
    return true;
}