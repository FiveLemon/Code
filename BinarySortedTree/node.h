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
* SearchBinarySortedTree函数用来搜索排序二叉树，其中参数T为树的根节点，key为要查询的特定值，f指向查询节点的父节点，若查询成功返回p;
*/
bool SearchBinarySortedTree(BinarySortedTree T, int key, BinarySortedTree f, BinarySortedTree *p);
/*
* 向T指向的二叉排序树中插入值
*/
bool InsertBinarySortedTree(BinarySortedTree *T, int key);
/*
*中序遍历二叉排序树，输出其中的元素
*/
void IterBinarySortedTree(BinarySortedTree T);
/*
* 删除排序二叉树中的某一个元素所在的节点
*/
bool DeleteBinarySortedTree(BinarySortedTree *T, int key);
bool Delete(BinarySortedTree* T);