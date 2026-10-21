#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

// 字符
typedef enum
{
    left_paren,
    right_paren,
    add,
    sub,
    mult,
    division,
    num,
    eos,
    mod
} character;
character getToken(char *symbol, char expr[MAXSIZE], int *index)
{
    *symbol = expr[*index];
    *index = *index + 1;
    switch (*symbol)
    {
    case '(':
        return left_paren;
    case ')':
        return right_paren;
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

Elemtype evals(Stack *s, char expr[MAXSIZE])
{
    Elemtype op1, op2;
    char symbol;
    int index = 0;
    character token;
    token = getToken(&symbol, expr, &index);
    while (token != eos)
    {
        if (token == num)
        {
            push(s, symbol - '0');
        }
        else
        {
            pop(s, &op2);
            pop(s, &op1);
            switch (token)
            {
            case add:
                push(s, op1 + op2);
                break;
            case sub:
                push(s, op1 - op2);
                break;
            case mult:
                push(s, op1 * op2);
                break;
            case division:
                push(s, op1 / op2);
                break;
            case mod:
                push(s, op1 % op2);
            default:
                break;
            }
        }
        token = getToken(&symbol, expr, &index);
    }
    Elemtype result;
    pop(s, &result);
    return result;
}
int main()
{
    Stack *s = initStack();
    char expr[MAXSIZE];
    fgets(expr, MAXSIZE, stdin);
    expr[strcspn(expr, "\n")] = '\0';
    Elemtype re = evals(s, expr);
    printf("%d\n", re);
    return 0;
}