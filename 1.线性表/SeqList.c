#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct
{
    ElemType data[MAXSIZE];
    int length; // 当前数组元素的个数
} SeqList;

void initList(SeqList *L) // 初始化列表
{
    L->length = 0;
}

// 末尾增加元素
int EndAdd(SeqList *L, ElemType e)
{
    if (L->length >= MAXSIZE)
    {
        printf("顺序表已满\n");
        return 0;
    }
    L->data[L->length] = e;
    L->length++;
    return 1;
}

// 遍历元素
void ListElem(SeqList *L)
{
    for (int i = 0; i < L->length; i++)
    {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

// 插入元素
int InsertElem(SeqList *L, int pos, ElemType e)
{
    if (L->length >= MAXSIZE)
    {
        printf("列表已满\n");
        return 0;
    }
    if (pos < 1 || pos > L->length)
    {
        printf("位置错误\n");
        return 0;
    }
    if (pos <= L->length)
    {
        for (int i = L->length - 1; i >= pos - 1; i--)
        {
            L->data[i + 1] = L->data[i];
        }
        L->data[pos - 1] = e;
        L->length++;
    }
    return 1;
}

// 删除元素
int DeleteElem(SeqList *L, int pos, ElemType *e)
{
    if (L->length == 0)
    {
        printf("空表\n");
        return 0;
    }
    if (pos < 1 || pos > L->length)
    {
        printf("位置错误\n");
        return 0;
    }
    if (pos <= L->length)
    {
        *e = L->data[pos - 1];
        for (int i = pos; i < L->length; i++)
        {
            L->data[i - 1] = L->data[i];
        }
        L->length--;
        return 1;
    }
}

// 查找元素
int FindElem(SeqList *L, ElemType e)
{
    for (int i = 0; i < L->length; i++)
    {
        if (L->data[i] == e)
        {
            return i + 1;
        }
    }
    return 0;
}
int main()
{
    // 声明一个顺序表并初始化
    SeqList l;
    initList(&l);
    printf("初始化成功,目前长度为%d\n", l.length);
    printf("目前占用字节数%zu字节\n", sizeof(l.data));
    EndAdd(&l, 3);
    EndAdd(&l, 6);
    EndAdd(&l, 5);
    EndAdd(&l, 4);
    ListElem(&l);
    InsertElem(&l, 2, 9);
    ListElem(&l);
    ElemType deleteelem;
    DeleteElem(&l, 2, &deleteelem);
    ListElem(&l);
    printf("%d\n", FindElem(&l, 5));
    return 0;
}