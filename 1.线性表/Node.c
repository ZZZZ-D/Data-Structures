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
    return 0;
}