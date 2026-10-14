#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
// 链式结构
// 节点
typedef struct queuenode
{
    ElemType data;
    QueueNode *next;
} QueueNode;

// 队列链
typedef struct queue
{
    QueueNode *front;
    QueueNode *rear;
} Queue;

// 初始化
Queue *initQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    QueueNode *node = (QueueNode *)malloc(sizeof(QueueNode));
    node->data = 0;
    node->next = NULL;
    q->front = node;
    q->rear = node;
    return q;
}

// 判断是否为空
int IsNull(Queue *q)
{
    if (q->front == q->rear)
    {
        printf("空的\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

// 入队
int equeue(Queue *q, ElemType e)
{
    QueueNode *p = (QueueNode *)malloc(sizeof(QueueNode));
    p->data = e;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
    return 1;
}

// 出队
int dequeue(Queue *q, ElemType *e)
{
    if (q->front == q->rear)
    {
        printf("空的\n");
        return 0;
    }
    *e = q->front->next->data;
    QueueNode *p = q->front->next;
    q->front->next = p->next;
    if (q->rear == p)
    {
        q->rear = q->front;
    }
    free(p);
    return 1;
}