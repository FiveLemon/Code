#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int number;
    int temp;
    vector<int> data;
    typedef vector<int>::iterator iterator;
    iterator minium, maxium;
    while(cin>>number)
    {
        data.clear();
        while(number--)
        {
            cin>>temp;
            data.push_back(temp);
        }
        minium = maxium = data.begin();
        for (iterator start = data.begin() + 1; start != data.end(); start ++)
        {
            if (*start > *maxium)
            {
                maxium = start;
                continue;
            }
            if (*start < *minium)
            {
                minium = start;
            }

        }
        swap(*minium, *maxium);
        for (iterator start = data.begin(); start != data.end()-1;start++)
        {
            cout<< *start<<" ";
        }
        cout<<*(data.end() - 1)<<endl;
    }
    return 0;
}