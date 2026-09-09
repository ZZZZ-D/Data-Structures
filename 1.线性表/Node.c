#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct node
{
    ElemType data;
    struct node *next;
} Node;

// 初始化链表
Node *initNode()
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;
}

// 头插法
void HeadAdd(Node *L, ElemType e)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = e;
    p->next = L->next;
    L->next = p;
}

// 遍历
void ListNode(Node *L)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p = L->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 尾插法
// 获取尾节点
Node *get_tail(Node *l)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->next = l->next;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p;
}

Node *EndAdd(Node *l, Node *tail, ElemType e)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = e;
    tail->next = p;
    p->next = NULL;
    return p;
}

// 删除节点
int DeleteNode(Node *l, int pos)
{
    int i = 0;
    Node *q = l;
    while (i < pos - 1)
    {
        q = q->next;
        i++;
        if (q == NULL)
        {
            printf("pos error\n");
            return 0;
        }
    }
    if (q->next == NULL)
    {
        printf("pos error\n");
        return 0;
    }
    Node *p = q->next;
    q->next = p->next;
    free(p);
    return 0;
}

// 获取链表长度
int ListLength(Node *l)
{
    Node *p = l;
    int len = 0;
    while (p->next != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

// 释放链表
int FreeList(Node *l)
{
    Node *p = l->next;
    if (p == NULL)
    {
        printf("ONLY HEAD\n");
        return 0;
    }
    Node *q = p->next;
    while (p->next != NULL)
    {
        free(p);
        p = q;
        q = p->next;
    }
    l->next = NULL;
    return 0;
}

int main()
{
    Node *l = initNode();
    HeadAdd(l, 1);
    HeadAdd(l, 2);
    HeadAdd(l, 3);
    HeadAdd(l, 4);
    ListNode(l);
    Node *tail = get_tail(l);
    tail = EndAdd(l, tail, 5);
    tail = EndAdd(l, tail, 6);
    tail = EndAdd(l, tail, 7);
    tail = EndAdd(l, tail, 8);
    tail = EndAdd(l, tail, 9);
    ListNode(l);
    DeleteNode(l, 4);
    ListNode(l);
    printf("%d\n", ListLength(l));
    FreeList(l);
    HeadAdd(l, 1);
    ListNode(l);
    return 0;
}