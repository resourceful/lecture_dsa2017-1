#include <stdio.h>
#include <stdlib.h>

typedef struct _stack_node {
    int data;
    struct _stack_node *next;
} stacknode;

typedef struct _stack_list {
    stacknode *top;
} lstack;

void INIT(lstack *s) {
    s->top = NULL;
}

int IS_FULL(lstack *s) {
    // test code needed
    return 0;
}

int IS_EMPTY(lstack *s) {
    return (s->top == NULL);
}

void TOP(lstack *s) {
    if (!IS_EMPTY(s))
        printf("%d\n", s->top->data);
}

void PUSH(lstack *s, int data) {
    // IS_FULL(s) testing required 
    stacknode *t = (stacknode*)malloc(sizeof(stacknode));
    if (t == NULL) {
        printf("Failed to allocate\n");
        return ;
    }
    t->data = data;
    t->next = s->top;
    s->top = t;
}

int POP(lstack *s) {
    int data;
    if(IS_EMPTY(s)) {
        printf("Stack Empty\n");
        return -1;
    }
    else {
        stacknode *t = s->top;
        data = t->data;
        s->top = s->top->next;
        free(t);
        return data;
    }
}

int main(void) {
    lstack *s = (lstack*)malloc(sizeof(lstack)); 
    INIT(s);
    PUSH(s, 10);
    TOP(s);
    PUSH(s, 20);
    TOP(s);
    PUSH(s, 30);
    TOP(s);
    printf("%d\n", POP(s));
    printf("%d\n", POP(s));
    printf("%d\n", POP(s));
    
    return 0;
}
