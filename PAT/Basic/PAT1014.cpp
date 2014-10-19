#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cctype>
using namespace std;
int main()
{
    string data[4];
    int number;
    for(int i = 0; i < 4; i++)
    {
        cin>>data[i];
    }
    vector<string> week;
    week.push_back("MON");
    week.push_back("TUE");
    week.push_back("WED");
    week.push_back("THU");
    week.push_back("FRI");
    week.push_back("SAT");
    week.push_back("SUN");

    int length1 = min(data[0].length(), data[1].length());
    int length2 = min(data[2].length(), data[3].length());
    for(int i = 0; i < length1; i++)
    {
        if (data[0][i] == data[1][i] && data[0][i] >= 'A' && data[0][i] <= 'G')
        {
            cout<<week[data[0][i] - 'A']<<" ";
            for(int j = i + 1; j < length1; j++)
            {
                if (data[0][j] == data[1][j] && ((data[0][j] >= 'A' && data[0][j] <= 'N') || isdigit(data[0][j])))
                {
                    if (isdigit(data[0][j]))
                    {
                        number = data[0][j] - '0';
                    }
                    else
                    {
                        number = data[0][j] - 'A' + 10;
                    }
                    cout<<number/10<<number%10<<":";
                    break;
                }
            }
            break;
        }
    }
    for (int i = 0; i < length2; i++)
    {
        if(data[2][i] == data[3][i] && isalpha(data[2][i]))
        {
            cout<<i/10<<i%10<<endl;
            break;
        }
    }
    return 0;
}