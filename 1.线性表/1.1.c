#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char ISBN[10];
    char BookName[20];
    double price;
} book;
int main()
{
    book b1;
    strcpy(b1.ISBN, "1234556");
    strcpy(b1.BookName, "java");
    strcpy(b1.price, 100.0);
    book bs[] = {b1};
    return 0;
}