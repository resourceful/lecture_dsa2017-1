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

void insert_head(node_t **head, int data) {
    node_t *new_node;
    new_node = malloc(sizeof(node_t));
    
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

int remove_head(node_t **head) {
    int retval = -1;
    node_t *new_head = NULL;
    if (*head == NULL) {
        return -1;
    }

    new_head = (*head)->next;
    retval = (*head)->data;
    free(*head);
    *head = new_head;
    return retval;
}

int remove_tail(node_t *head) {
    int retval = 0;
    if (head->next == NULL) { 
       retval = head->data;
       free(head);
       return retval;
    }

    node_t *current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    retval = current->next->data;
    free(current->next);
    current->next = NULL;
    return retval;
}

int remove_value(node_t **head, int data) {
    node_t *previous, *current;
    if (*head == NULL)
        return -1;

    if ((*head)->data == data)
        return remove_head(head);

    previous = current = (*head)->next;
    while (current != NULL) {
        if (current->data == data) {
            previous->next = current->next;
            free(current);
            return data;
        } 
        previous = current;
        current = current->next;
    }
    return -1;
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
    insert_head(&head, 10);
    insert_head(&head, 20);
    insert_head(&head, 30);
    print_list(head);
    printf("%d\n", remove_head(&head));
    printf("%d\n", remove_tail(head));
    remove_value(&head, 0);
    print_list(head);

    return 0;
}
