#include <stdio.h>
#include <stdlib.h>

struct _node {
    int data;
    struct _node *next;
}

typedef struct _node node;

int ListLen(node *head)
{
    node *current = head;
    int count = 0;

    while (current != NULL)
    {
        count++;    
        current = current->next;
    }
    return count;
}

void InsertListNode(node *head, int data, int position){
    int k = 1;
    node *p, *q;
    node *newNode = (node *)malloc(sizeof(node));

    if(!newNode){
        printf("Failed to create node\n");
        return;
    }

    newNode->data = data;
    p = *head;

    // Insert at the beginning of the list
    if(position == 1){
        newNode->next = p;
        *head = newNode;
    }
    else{
        // Traverse the list until the position is reached
        while((p != NULL) && (k < position)){
            k++;
            q = p;
            p = p->next;
        }
        q->next = newNode;
        newNode->next = p;
    }
}

void DeleteListNode(node *head, int position){
    int k = 1;
    node *p, *q;
    if(*head == NULL){
        printf("List is Empty\n");
        return;
    }

    p = *head;

    if(position == 1){
        *head = (*head)->next;
        free(p);
        return;
    }
    else{
        // Traverse the list until the position is reached
        while((p != NULL) && (k < position)) {
            k++;
            q = p;
            p = p->next;
        }
        if(p == NULL)
            printf("Out of bound\n");
        else {
            q->next = p->next;
            free(p);
        }
    }
}

void DeleteList(node *head){
    node *auxNode, *iterator;
    *iterator = *head;

    while(iterator) {
        auxNode = iterator->next;
        free(iterator);
        iterator = auxNode;
    }
    *head = NULL;
}


int main(void)
{
    node *head = NULL;
    InsertListNode(head, 10, 1);
    InsertListNode(head, 20, 2);
    InsertListNode(head, 30, 3);
    printf("len: %d\n", ListLen(head));
    DeleteListNode(head, 1);
    printf("len: %d\n", ListLen(head));
    return 0;
}

