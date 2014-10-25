#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>
#include<cmath>
#include<set>
using namespace std;
int main()
{
    string whole;
    string defective;
    set<char> data;
    string::size_type i = 0; 
    int    j = 0;
    cin>>whole>>defective;
    for (; i < defective.length(); i++)
    {
        while (defective[i] != whole[j])
        {
            if (isalpha(whole[j]))
            {
                whole[j] = toupper(whole[j]);
            }
            if (!data.count(toupper(whole[j])))
            {
                cout<<whole[j];
            }
            data.insert(whole[j]);
            j++;
        }
        j++;
    }
    for(i = j; i < whole.length(); i++)
    {
        if (isalpha(whole[i]))
            {
                whole[i] = toupper(whole[i]);
            }
            if (!data.count(toupper(whole[i])))
            {
                cout<<whole[i];
            }
            data.insert(whole[i]);
    }
    cout<<endl;
    return 0;
}