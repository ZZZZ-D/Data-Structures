#include <stdio.h>
#include <string.h>
void simplicityMatch(char *q, char *p)
{
    for (int i = 0; i <= strlen(q) - strlen(p); i++)
    {
        int j = 0;
        int flag = 1;
        while (j < strlen(p))
        {
            if (p[j] == q[i + j])
            {
                j++;
            }
            else
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            printf("%d\n", i + 1);
            break;
        }
    }
}
int main()
{
    char q[] = "abcdefghabcz";
    char p[] = "abcz";
    simplicityMatch(q, p);
    return 0;
}