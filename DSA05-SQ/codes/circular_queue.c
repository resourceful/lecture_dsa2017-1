#include <stdio.h>
#include <stdlib.h>

typedef struct _queue{
    int front;
    int rear;
    int capacity;
    int *array;
} queue;

queue* CreateCQueue(){
    queue *q = malloc(sizeof(queue));
    if(!q)
        return NULL;
    q->capacity = 1;
    q->front = q->rear = -1;
    q->array = malloc(q->capacity *sizeof(int));
    if(!q->array)
        return NULL;
    return q;
}

int IsEmptyCQ(queue *q)
{
    return (q->front == -1);
}

int IsFullCQ(queue *q)
{
    return ((q->rear + 1) % q->capacity == q->front);
}

int CQsize(queue *q)
{
    return (q->capacity - q->front + q->rear +1) % q->capacity;
}

void ResizeCQ(queue *q)
{
    int size = q->capacity;
    q->capacity = q->capacity * 2;
    q->array = realloc(q->array, q->capacity);
    if(!q->array)
    {
        printf("failed to resize\n");
        return;
    }
    if(q->front > q->rear)
    {
        for (int i = 0; i < q->front; i++)
        {
            q->array[i+size] = q->array[i];
        }
        q->rear = q->rear + size;
    }
    printf("Size of Q doubled\n");
}

void EnCQ(queue *q, int data)
{
    if(IsFullCQ(q))
        ResizeCQ(q);
    q->rear = (q->rear + 1) % q->capacity;
    q->array[q->rear] = data;
    if(q->front == -1)
        q->front = q->rear;
    
    printf("EnCQueue %d\n", q->array[q->rear]);
}

int DeCQ(queue *q)
{
    int data = 0;
    if(IsEmptyCQ(q))
    {
        printf("CQueue is Empty\n");
        return 0;
    }
    else
    {
        data = q->array[q->front];
        if(q->front == q->rear)
            q->front = q->rear = -1;
        else
            q->front = (q->front+1) % q->capacity;
    }
    printf("DeCQueue %d\n", data);
    return data;
}

void DelCQ(queue *q)
{
    if(q)
    {
        if(q->array)
            free(q->array);
        free(q);
    }
    printf("Queue Deleted\n");
}


int main(void)
{
    queue *Q = CreateCQueue();
    EnCQ(Q, 10);
    EnCQ(Q, 20);
    EnCQ(Q, 30);
    EnCQ(Q, 40);
    EnCQ(Q, 50);
    EnCQ(Q, 60);
    EnCQ(Q, 70);
    EnCQ(Q, 80);
    printf("\n");
    DeCQ(Q);
    DeCQ(Q);
    DeCQ(Q);
    DeCQ(Q);
    DeCQ(Q);
    DeCQ(Q);
    DeCQ(Q);
    DeCQ(Q);
    DeCQ(Q);
    DeCQ(Q);
    DeCQ(Q);
    DelCQ(Q);
    return 0;
}