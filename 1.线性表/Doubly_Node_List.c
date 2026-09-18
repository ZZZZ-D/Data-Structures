#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct node
{
    ElemType data;
    struct node *prev;
    struct node *next;
} Node;

// 初始化双向链表
Node *InitList()
{
    Node *Head = (Node *)malloc(sizeof(Node));
    Head->data = 0;
    Head->next = NULL;
    Head->prev = NULL;
    return Head;
}

// 头插法
void HeadAdd(Node *L, ElemType e)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = e;
    p->prev = L;
    p->next = L->next;
    L->next = p;
    L->next->prev = p;
}

// 遍历
void NodeList(Node *L)
{
    Node *p = L->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 获取尾节点
Node *GetTail(Node *L)
{
    Node *p = L;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p;
}

// 尾插法
void TailAdd(Node *L, ElemType e)
{
    Node *p = (Node *)malloc(sizeof(Node));
    Node *tail = GetTail(L);
    p->data = e;
    p->prev = tail;
    p->next = NULL;
    tail->next = p;
}

int main()
{
    Node *L = InitList();
    HeadAdd(L, 1);
    HeadAdd(L, 2);
    HeadAdd(L, 3);
    HeadAdd(L, 4);
    TailAdd(L, 5);
    NodeList(L);
    return 0;
}