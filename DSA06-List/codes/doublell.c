#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node *next;
    struct _node *prev;
} dlnode;

typedef struct _double_linked_list {
    dlnode *head;
} dlist;

dlnode* NewNode(int data) {
    dlnode *new = (dlnode *)malloc(sizeof(dlnode));
    if (new == NULL) {
        printf("Creating node failed\n");
        return NULL;
    }

    new->data = data;
    new->next = NULL;
    new->prev = NULL;

    return new;
}

dlist* InitDList(int data) {
    dlnode *new = NewNode(data);
    if (new == NULL) {
        printf("Creating node failed\n");
        return NULL;
    }
    dlist *l = (dlist *)malloc(sizeof(dlist)); 
    if (l == NULL) {
        printf("Creating list failed\n");
        return NULL;
    }
    l->head = new;

    return l;
}

void TraverseDlist(dlist *l) {
    dlnode *temp = l->head; 

    while(temp != NULL) { 
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("Null\n");
}

void InsertDlistHead(dlist *l, dlnode *n) {
    n->next = l->head;
    l->head->prev = n;
    l->head = n;
}

void InsertDlistTail(dlist *l, dlnode *n) {
    dlnode *t = l->head;

    while(t->next != NULL)
        t = t->next;
    
    t->next = n;
    n->prev = t;
}

void InsertDlistAfter(dlnode *n, dlnode *t) {
    n->next = t->next;
    t->next->prev = n;
    t->next = n;
    n->prev = t;
}

void DeleteDlistNode(dlist *l, dlnode *t) {
    if (l && (l->head != NULL)){
        if(t->prev != NULL) // not head
            t->prev->next = t->next;
        else // head
            l->head = t->next;
        
        if(t->next != NULL)
            t->next->prev = t->prev;
        
        free(t);
    }
}


int main(void) {
    dlist *l = InitDList(0);
    for (int i = 1; i < 3; i++) {
        InsertDlistHead(l, NewNode(i));
    }
    TraverseDlist(l);
    for (int i = 1; i < 4; i++) {
        InsertDlistTail(l, NewNode(i+10));
    }
    TraverseDlist(l);

    for (int i = 1; i < 10; i++) {
        DeleteDlistNode(l, l->head);
        TraverseDlist(l);
    }
    free(l);

    return 0;
}
