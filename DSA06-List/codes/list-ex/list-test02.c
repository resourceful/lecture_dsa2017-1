#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

void print_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int main(void) {
    node_t *head = NULL;
    head = malloc(sizeof(node_t));
    if (head == NULL) {
        return 1;
    }
    head->data = 10;
    head->next = NULL;

    node_t *second = (node_t*) malloc(sizeof(node_t));
    if (second == NULL)
        return 1;
    second->next = NULL;
    second->data = 20;
    head->next = second; 

    print_list(head);

    return 0;
}
