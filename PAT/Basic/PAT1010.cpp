#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> data;
    int temp;
    while(cin>>temp)
    {
        data.push_back(temp);
    }
    int length = data.size();
    if ((length == 2) && (data[length - 1]==0))
    {
        cout<<"0"<<" "<<"0"<<endl;
        return 0;
    }
    if (length == 0)
    {
        cout<<"0"<<" "<<"0"<<endl;
        return 0;
    }
    if (data[length - 1] == 0)
    {
        data.erase(data.end() - 2, data.end());
    }
    length = data.size();
    if (length >= 2)
    {
        for (vector<int>::iterator start = data.begin(); start != data.end() - 2; start += 2)
        {
            cout<<*start * *(start + 1)<<" "<<*(start + 1) - 1<<" ";
        }
        cout<<data[length - 2] * data[length - 1]<<" "<<data[length - 1] - 1<<endl;
    } 
    return 0;
}