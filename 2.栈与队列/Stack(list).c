#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int ElemType;
// 顺式结构
//  typedef struct
//  {
//      ElemType data[MAXSIZE];
//      int top;//栈顶元素下标值
//  } Stack;
typedef struct
{
    ElemType *data;
    int top;
} Stack; // 动态分配

// 初始化栈
// void initStack(Stack *s)
// {
//     s->top = -1;
// }
Stack *initStack()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (ElemType *)malloc(sizeof(ElemType) * MAXSIZE);
    s->top = -1;
    return s;
}

// 判断栈是否为空
int IsNull(Stack *s)
{
    if (s->top == -1)
    {
        printf("空的\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

// 进栈
int Push(Stack *s, ElemType e)
{
    if (s->top == MAXSIZE - 1)
    {
        printf("满了\n");
        return 0;
    }
    else
    {
        s->top++;
        s->data[s->top] = e;
        return 1;
    }
}

// 出栈
int Pop(Stack *s, ElemType *e)
{
    if (s->top == -1)
    {
        printf("空的\n");
        return 0;
    }
    *e = s->data[s->top];
    s->top--;
    return 1;
}

// 获取栈顶元素
int GetTop(Stack *s, ElemType *e)
{
    if (s->top == -1)
    {
        printf("空的\n");
        return 0;
    }
    *e = s->data[s->top];
    return 1;
}