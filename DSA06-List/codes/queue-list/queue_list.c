#include <stdio.h>
#include <stdlib.h>

struct _node {
    int data;
    struct _node *next;
} ;

typedef struct _node listnode;

struct _queue {
    listnode *front;
    listnode *rear;
} ;

typedef struct _queue queue;

queue* CreateQueue(){
    queue *q = malloc(sizeof(queue));
    if(!q)
    {
        printf("failed to create queue\n");
        exit(-1);
    }
    q->front = q->rear = NULL;
    //printf("creating queue\n");
    return q;
}

int IsEmptyQueue(queue *q)
{
    // if condition is true then 1
    // else 0 is returned;
    return(q->front == NULL);
}

void enqueue(queue *q, int data)
{
    listnode *newnode;
    newnode = malloc(sizeof(listnode));
    if(!newnode)
    {
        printf("failed to create node\n");
        exit(-1);
    }
    newnode->data = data;
    newnode->next = NULL;
    if(q->rear)
        q->rear->next = newnode;
    q->rear = newnode;
    if(q->front == NULL)
        q->front = q->rear;
    printf("enqueue %d\n", q->rear->data);
}

int dequeue(queue *q)
{
    int data = 0;
    listnode *temp;
    if(IsEmptyQueue(q))
    {
        printf("queue is empty\n");
	return 0;
    }
    else
    {
        temp = q->front;
	data = q->front->data;
	q->front = q->front->next;
	free(temp);
    }
    printf("dequeue %d\n", data);
    return data;
}

void DeleteQueue(queue *q)
{
    listnode *temp;
    while(q && (q->front!=NULL))
    {
        temp = q->front;
	q->front = q->front->next;
	free(temp);
    }
    free(q);
    printf("delete queue");
}

int main(void)
{
    queue *Q = CreateQueue();
    enqueue(Q, 10);
    enqueue(Q, 20);
    enqueue(Q, 30);
    enqueue(Q, 40);
    enqueue(Q, 50);
    printf("\n");
    
    dequeue(Q);
    dequeue(Q);
    dequeue(Q);
    dequeue(Q);
    dequeue(Q);
    dequeue(Q);
    dequeue(Q);
    dequeue(Q);
    dequeue(Q);
    DeleteQueue(Q);
    return 0;
}
