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
* ��Tָ��Ķ����������в���ֵ
*/
bool InsertBinarySortedTree(BinarySortedTree *T, int key);
/*
*�������������������������е�Ԫ��
*/
void IterBinarySortedTree(BinarySortedTree T);
/*
* ɾ������������е�ĳһ��Ԫ�����ڵĽڵ�
*/
bool DeleteBinarySortedTree(BinarySortedTree *T, int key);
bool Delete(BinarySortedTree* T);