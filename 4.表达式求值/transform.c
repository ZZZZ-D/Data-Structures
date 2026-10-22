#include <stdlib.h>
#include <stdio.h>
#define MAXSIZE 100
typedef int Elemtype;
typedef struct
{
    Elemtype *data;
    int top;
} Stack;

// 初始化
Stack *initStack()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (Elemtype *)malloc(sizeof(Elemtype) * MAXSIZE);
    s->top = -1;
    return s;
}

// 压栈
int push(Stack *s, Elemtype e)
{
    if (s->top >= MAXSIZE)
    {
        printf("满了\n");
        return 0;
    }
    s->top++;
    s->data[s->top] = e;
    return 1;
}

// 弹栈
int pop(Stack *s, Elemtype *e)
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

typedef enum
{
    left_part,
    right_part,
    add,
    sub,
    mult,
    division,
    mod,
    eos,
    num,
} character;

char fore[MAXSIZE] = "x/(i-j)*y";
character getToken(char *symbol, int *index)
{
    *symbol = fore[*index];
    *index = *index + 1;
    switch (*symbol)
    {
    case '(':
        return left_part;
    case ')':
        return right_part;
    case '+':
        return add;
    case '-':
        return sub;
    case '*':
        return mult;
    case '/':
        return division;
    case '%':
        return mod;
    case '\0':
        return eos;
    default:
        return num;
    }
}

void printfToken(Elemtype e)
{
    switch (e)
    {
    case left_part:
        break;
    case right_part:
        break;
    case add:
        printf("+");
        break;
    case sub:
        printf("-");
        break;
    case mult:
        printf("*");
        break;
    case division:
        printf("/");
        break;
    case mod:
        printf("%%");
        break;
    case eos:
        break;
    default:
        break;
    }
}

void transform(Stack *s)
{
    int in_stack[] = {0, 19, 12, 12, 13, 13, 13, 0};
    int out_stack[] = {20, 19, 12, 12, 13, 13, 13, 0};
    character token;
    int index = 0;
    char symbol;
    s->top = 0;
    s->data[s->top] = eos;
    Elemtype e;
    token = getToken(&symbol, &index);
    while (token != eos)
    {
        if (token == num)
        {
            printf("%c", symbol);
        }
        else if (token == right_part)
        {
            while (s->data[s->top] != left_part)
            {
                pop(s, &e);
                printfToken(e);
            }
            pop(s, &e);
        }
        else
        {
            while (out_stack[token] <= in_stack[s->data[s->top]])
            {
                pop(s, &e);
                printfToken(e);
            }
            push(s, token);
        }
        token = getToken(&symbol, &index);
    }
    pop(s, &e);
    token = e;
    while (token != eos)
    {
        printfToken(token);
        pop(s, &e);
        token = e;
    }
    printf("\n");
}
int main()
{
    Stack *s = initStack();
    printf("%s\n", fore);
    transform(s);
    return 0;
}