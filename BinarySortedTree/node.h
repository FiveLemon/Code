typedef struct BinarySortedTreeNode
{
    int data;
    struct BinarySortedTreeNode *lchild, *rchild;
}BinarySortedTreeNode, *BinarySortedTree;
enum Status
{
    FALSE = 0,
    TRUE = 1
};
/*
* SearchBinarySortedTree��������������������������в���TΪ���ĸ��ڵ㣬keyΪҪ��ѯ���ض�ֵ��fָ���ѯ�ڵ�ĸ��ڵ㣬����ѯ�ɹ�����p;
*/
bool SearchBinarySortedTree(BinarySortedTree T, int key, BinarySortedTree f, BinarySortedTree *p);
/*
* 
*/
bool InsertBinarySortedTree(BinarySortedTree *T, int key);
/*
*�������
*/
void IterBinarySortedTree(BinarySortedTree T);