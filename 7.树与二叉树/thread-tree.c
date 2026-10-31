#include <stdio.h>
typedef char Elemtype;
typedef struct threadNode
{
    Elemtype data;
    struct threadNode *lchild;
    struct threadNode *rchild;
    int ltag;
    int rtag;
} threadNode;
typedef threadNode *threadTree;
