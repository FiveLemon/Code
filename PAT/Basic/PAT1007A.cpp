#include<iostream>
#include<vector>
using namespace std;
bool prime(vector<int> data,int i);
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
        if (prime(data, i))
        {
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
bool prime(vector<int> data, int n)
{
    for (int i = 0; data[i] * data[i] <= n; i++)
    {
        if (0 == n % data[i])
        {
            return false;
        }
    }
    
    return true;
}