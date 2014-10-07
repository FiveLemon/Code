#include"node.h"
#include <malloc.h>
#include<stdio.h>
#include<stdlib.h>
bool SearchBinarySortedTree(BinarySortedTree T, int key, BinarySortedTree f, BinarySortedTree *p)
{
    if (!T)
    {
        *p = f;
        return false;
    }
    else if(key == T->data)
    {
        *p = T;
        return true;
    }
    else if(key < T->data)
        return SearchBinarySortedTree(T->lchild, key, T, p);
    else
        return SearchBinarySortedTree(T->rchild, key, T, p);
}

bool InsertBinarySortedTree(BinarySortedTree *T, int key)
{
    BinarySortedTree p, s;
    if(!SearchBinarySortedTree(*T, key, BinarySortedTree(0), &p))
    {
        s = (BinarySortedTree)malloc(sizeof(BinarySortedTreeNode));
        s->data = key;
        s->lchild = s->rchild = BinarySortedTree(0);
        if(!p)
            *T = s;
        else if (key < p->data)
            p->lchild = s;
        else
            p->rchild = s;
        return true;
    }
    else
        return false;
}
void IterBinarySortedTree(BinarySortedTree T)
{
    if (!T)
        return;
    IterBinarySortedTree(T->lchild);
    printf("%d ", T->data);
    IterBinarySortedTree(T->rchild);

}

bool DeleteBinarySortedTree(BinarySortedTree *T, int key)
{
    if(!*T)
        return false;
    else
    {
        if (key == (*T)->data)
           return Delete(T);
        else if (key < (*T)->data)
            return DeleteBinarySortedTree(&(*T)->lchild, key);
        else
            return DeleteBinarySortedTree(&(*T)->rchild, key);
    }
}
bool Delete(BinarySortedTree *T)
{
    BinarySortedTree q,s;
    if(NULL==(*T)->rchild)
    {
        q = *T;
        *T = (*T)->lchild;
        free(q);
    }
    else if ((*T)->lchild == NULL)
    {
       q = *T;
        *T = (*T)->rchild;
        free(q); 
    }
    else
    {
        q = *T;
        s = (*T)->lchild;
        while(s->rchild)
        {
            q = s;
            s = s->rchild;
        }
        (*T)->data = s->data;
        if(q != *T)
        {
            q->rchild = s->lchild;
        }
        else
            q->lchild = s->lchild;
        free(s);

    }
    return true;
}