#include"node.h"

int main()
{
    int i;
    int a[10] = {62,88,58, 47,35,73,51,99,37,93};
    BinarySortedTree T = BinarySortedTree(0);
    for(int i = 0; i < 10; i++)
    {
        InsertBinarySortedTree(&T,a[i]);
    }
    IterBinarySortedTree(T);
    return 0;
}