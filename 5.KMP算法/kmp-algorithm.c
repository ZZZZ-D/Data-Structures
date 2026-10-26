#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *getNext(char *p)
{
    int len = strlen(p);

    int *next = malloc(len * sizeof(int));
    if (next == NULL)
    {
        return NULL;
    }

    if (len == 0)
    {
        return next;
    }

    int i = 0;
    int j = -1;
    next[0] = -1;

    while (i < len - 1)
    {
        if (j == -1 || p[i] == p[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }

    return next;
}
int kmp(char *q, char *p)
{
    int q_len = strlen(q);
    int p_len = strlen(p);

    if (p_len == 0)
    {
        return 0;
    }

    int *next = getNext(p);
    if (next == NULL)
    {
        return -1;
    }

    int i = 0;
    int j = 0;

    while (i < q_len && j < p_len)
    {
        if (j == -1 || q[i] == p[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }

    int result = (j == p_len) ? i - j : -1;

    free(next);
    return result;
}