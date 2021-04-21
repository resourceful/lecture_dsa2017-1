#include <stdio.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

int main(void) {
    node_t x;
    node_t y;
    x.data = 10;
    y.data = 20;
    x.next = &y;
    printf("%d\n", x.next->data);
    node_t z;
    z.data = 30;

    y.next = &z;

    printf("%d\n", x.next->next->data);
    printf("%d\n", y.next->data);
    printf("%d\n", z.data);
    return 0;
}
