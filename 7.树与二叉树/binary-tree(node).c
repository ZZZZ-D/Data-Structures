#include <stdio.h>
typedef char Elemtype;
// 定义二叉树
typedef struct treenode
{
    Elemtype data;
    treeNode *lchild;
    treeNode *rchild;
} treeNode;
typedef treeNode *biTree;
// 前序遍历
void preOrder(biTree T)
{
    if (T == NULL)
    {
        return 0;
    }
    printf("%c\t", T->data);
    preOrder(T->lchild);
    preOrder(T->rchild);
}
// 中序遍历
void midOrder(biTree T)
{
    if (T == NULL)
    {
        return 0;
    }
    midOrder(T->lchild);
    printf("%c\t", T->data);
    midOrder(T->rchild);
}
// 后序遍历
void finaOrder(biTree T)
{
    if (T == NULL)
    {
        return 0;
    }
    finaOrder(T->lchild);
    finaOrder(T->rchild);
    printf("%c\t", T->data);
}
char str[] = "ABDH#K###E##CFI###G#J##";
int idx = 0;
// 创造二叉树
void createTree(biTree *T)
{
    Elemtype ch;
    ch = str[idx++];
    if (ch == '#')
    {
        *T = NULL;
        return;
    }
    *T = (biTree)malloc(sizeof(treeNode));
    (*T)->data = ch;
    createTree(&(*T)->lchild);
    createTree(&(*T)->rchild);
}