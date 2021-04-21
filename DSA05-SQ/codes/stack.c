#include <stdio.h>
#include <stdlib.h>

typedef struct stack_elm {
    int top;
    int capacity;
    int *array;
} dstack;

dstack *CreateStack()
{
    dstack *s = malloc(sizeof(dstack));
    if (!s)
        return NULL;
    s->capacity = 1;
    s->top = -1;
    s->array = malloc(s->capacity * sizeof(int));
    if(!s->array)
        return NULL;
    return s;
}


int IsEmpty(dstack *s)
{
    return s->top == -1;
}

int IsFull(dstack *s)
{
    return(s->top == s->capacity-1);
}

void DoubleStack(dstack *s)
{
    s->capacity *= 2;
    s->array = realloc(s->array, s->capacity*sizeof(int));
}

int Top(dstack *s)
{
    if(IsEmpty(s))
        return -1;
    return s->array[s->top];
}


void Push(dstack *s, int x)
{
    if(IsFull(s))
    {
        printf("Is full, doubling the stack\n");
	DoubleStack(s);
    }
    s->array[++s->top] = x;
    printf("Pushing %d\n", Top(s));
}

int Pop(dstack *s)
{
    if(IsEmpty(s))
    {
	printf("empty\n");
        return -1;
    }

    printf("Popping %d\n", Top(s));
    return s->array[s->top--];
}

void DeleteStack(dstack *s)
{
    if(s)
    {
        if(s->array)
            free(s->array);
        free(s);
    }
}

int main(void)
{
    dstack *stack = CreateStack();
    Push(stack, 10);
    Push(stack, 20);
    Push(stack, 30);
    Push(stack, 40);
    Push(stack, 50);
    Push(stack, 60);
    Push(stack, 70);
    Push(stack, 80);
    Push(stack, 90);
    printf("\n");
    Pop(stack);
    Pop(stack);
    Pop(stack);
    Pop(stack);
    Pop(stack);
    Pop(stack);
    Pop(stack);
    Pop(stack);
    Pop(stack);
    Pop(stack);
    Pop(stack);
    Pop(stack);
    DeleteStack(stack);
    return 0;
}
