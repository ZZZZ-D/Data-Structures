#include <stdio.h>
int fun(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return fun(n - 1) + n;
    }
}

// 递归求斐波那契数列
int fibonacci(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
int main()
{
    // 非递归
    int sum = 0;
    for (int i = 1; i <= 100; i++)
    {
        sum += i;
    }
    printf("%d\n", sum);

    // 递归
    int s = 0;
    s = fun(100);
    printf("%d\n", s);
    //
    int f = 0;
    f = fibonacci(9);
    printf("%d\n", f);
    return 0;
}