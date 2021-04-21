#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data[4];
    struct node *next;
} node_t;

int main(void) {
    node_t *head = NULL;
    head = malloc(sizeof(node_t));
    if (head == NULL) {
        return 1;
    }
    strcpy(head->data, "bat");
    head->next = NULL;

    printf("%s\n", head->data);

    node_t *second = (node_t*) malloc(sizeof(node_t));
    if (second == NULL)
        return 1;
    second->next = NULL;
    strcpy(second->data, "cat");
    head->next = second; 
    printf("%s\n", head->next->data);
    return 0;
}
