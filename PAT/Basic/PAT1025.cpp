#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>
#include<iomanip>
using namespace std;
typedef struct Data
{
    int data;
    int local_address;
    int next_address;
}Data;
int main()
{
    int address_head;
    int number, counter;
    int local_address;
    int k;
    Data data[100002];
    vector<Data> temp;
    cin>>address_head>>number>>k;
    counter = number;
    data[100001].next_address = address_head;
    while(counter--)
    {
        cin>>local_address;
        data[local_address].local_address = local_address;
        cin>>data[local_address].data;
        cin>>data[local_address].next_address;
    }
    local_address = data[100001].next_address;
    while(true)
    {
        temp.push_back(data[local_address]);
        local_address = data[local_address].next_address;
        if(local_address == -1)
            break;
    }
    for (vector<Data>::iterator start = temp.begin(); start + k <= temp.end(); start+=k)
    {
        reverse(start, start + k);
    }
    vector<Data>::iterator start = temp.begin();
    for (; start + 1 != temp.end(); start++)
    {
        start->next_address = (start + 1)->local_address;
        printf("%05d %d %05d\n",start->local_address,start->data,start->next_address);
    }
    printf("%05d %d -1\n",start->local_address,start->data);
    return 0;
}
