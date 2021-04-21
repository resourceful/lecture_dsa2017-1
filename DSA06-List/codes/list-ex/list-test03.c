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
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void insert_tail(node_t *head, int data) {
    node_t *current = head;
    while (current->next != NULL) 
        current = current->next;
    
    current->next = malloc(sizeof(node_t));
    if (current->next != NULL) {
        current->next->data = data;
        current->next->next = NULL;
    }
}

int main(void) {
    node_t *head = NULL;
    head = malloc(sizeof(node_t));
    if (head == NULL)
        return 1;
    head->data = 0;
    head->next = NULL;
    insert_tail(head, 10);
    insert_tail(head, 20);
    insert_tail(head, 30);
    print_list(head);

    return 0;
}
