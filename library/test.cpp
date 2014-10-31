#include"library.h"
using namespace std;

using namespace QCQ;
int main()
{
    int data[10] ={2,3,5,1,6,7,9,10,29,20};
    for (int i = 0; i < 10; i++)
    {
        cout<<data[i]<<" ";
    }
    cout<<endl;
    ShellSort(data, 10);
    for (int i = 0; i < 10; i++)
    {
        cout<<data[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < 10; i++)
    {
        cout<<Random(1.0, 100.0)<<" ";
    }
    return 0;
}
