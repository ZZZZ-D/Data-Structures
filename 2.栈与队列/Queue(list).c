#include <stdio.h>
#include <stdlib.h>
typedef int Elemtype;
#define MAXSIZE 100
// 队列的顺式结构
//  typedef struct
//  {
//      Elemtype data [MAXSIZE];
//      int front;
//      int rear;
//  }Queue;

// 动态分配
typedef struct
{
    Elemtype *data;
    int front;
    int rear;
} Queue;

// 初始化队列
//  void initQueue(Queue *q)
//  {
//      q->front = 0;
//      q->rear = 0;
//  }
Queue *initQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (Elemtype *)malloc(sizeof(Elemtype) * MAXSIZE);
    q->front = 0;
    q->rear = 0;
    return q;
}

// 判断是否为空
int isNull(Queue *q)
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

// 出队
int dequeue(Queue *q, Elemtype *e)
{
    if (q->front == q->rear)
    {
        printf("空的\n");
        return 0;
    }
    *e = q->data[q->front];
    q->front++;
    return 1;
}

// 判断满没满
int queueFull(Queue *q)
{
    if (q->front == 0)
    {
        printf("满了\n");
        return 1;
    }
    else
    {
        int step = q->front;
        for (int i = q->front; i < q->rear; i++)
        {
            q->data[i - step] = q->data[i];
        }
        q->rear = q->rear - q->front;
        return 0;
    }
}

// 入队
int equeue(Queue *q, Elemtype e)
{
    if (q->rear >= MAXSIZE)
    {
        if (queueFull(q))
        {
            return 0;
        }
    }
    q->data[q->rear] = e;
    q->rear++;
    return 1;
}

// 获取队头元素
int GetFront(Queue *q, Elemtype *e)
{
    if (q->front == q->rear)
    {
        printf("空的\n");
        return 0;
    }
    *e = q->data[q->front];
    return 1;
}
