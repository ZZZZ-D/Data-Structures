#include <stdio.h>
#include <stdlib.h>
typedef int Elemtype;
// 链式结构
typedef struct stack
{
    Elemtype data;
    Stack *next;
} Stack;

// 初始化
Stack *initStack()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = 0;
    s->next = NULL;
    return s;
}

// 判断是否为空
int IsNull(Stack *s)
{
    if (s->next == NULL)
    {
        printf("空的\n");
        return 1;
    }
    else
    {
        return 1;
    }
}

// 进栈
int Push(Stack *s, Elemtype e)
{
    Stack *p = (Stack *)malloc(sizeof(Stack));
    p->data = e;
    p->next = s->next;
    s->next = p;
    return 1;
}

// 出栈
int Pop(Stack *s, Elemtype *e)
{
    if (s->next == NULL)
    {
        printf("空的\n");
        return 0;
    }
    Stack *q = (Stack *)malloc(sizeof(Stack));
    q = s->next;
    *e = q->data;
    s->next = q->next;
    free(q);
    return 1;
}

// 获取栈顶元素
int GetTop(Stack *s, Elemtype *e)
{
    if (s->next = NULL)
    {
        printf("空的\n");
        return 0;
    }
    *e = s->next->data;
    return 1;
}