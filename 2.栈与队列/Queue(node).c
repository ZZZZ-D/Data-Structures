#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
// 链式结构
typedef struct queue
{
    ElemType data;
    Queue *front;
    Queue *rear;
} Queue;

// 初始化
Queue *initQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    q->data = 0;
}