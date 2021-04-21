#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct _node {
    int data;
    struct _node *next;
} node;


typedef struct _list {
     node *head;
     node *pos;
     int count;
} list;

list* InitList() {
    list *l = (list *)malloc(sizeof(list));
    l->head = (node *)malloc(sizeof(node));
    l->head = NULL;
    l->pos = NULL;
    l->count = 0;
    return l;
}

int ListLen(list *l) {
    return l->count;
}

void PrintList(list *l) {
    l->pos = l->head;
    while (l && (l->pos != NULL)) {
        printf("%d -> ", l->pos->data);
        l->pos = l->pos->next;
    }
    printf("NULL\n");
}

void InsertListHead(list *l, int data) {
    node *new = (node *)malloc(sizeof(node));
    if (!new) {
        printf("Failed to create node\n");
        return;
    }

    new->data = data;
    new->next = l->head;
    l->head = new;
    ++(l->count);
}

void InsertListTail(list *l, int data) {
    node *prev = NULL;
    node *new = (node *) malloc(sizeof(node));
    if (!new) {
        printf("Failed to Create node\n");
        return;
    }
    new->data = data;
    new->next = NULL;
    l->pos = l->head;

    while (l->pos != NULL) {
        prev = l->pos; 
        l->pos = l->pos->next;
    }
    ++(l->count);
    prev->next = new;
}

int DeleteListHead(list *l) {
    int data = l->head->data;
     
    l->pos = l->head;
    if (l->pos != NULL) {
        l->pos = l->pos->next;
        --(l->count);
        free(l->pos);
    }
    printf("%d deleted\n", data);
    return data;
}

int DeleteListTail(list *l) {
    int data;
    node *prev;

    if (l && (l->head != NULL)) {
        if (l->head->next == NULL){
            return DeleteListHead(l);
        }
        prev = l->head;
        l->pos = l->head->next;
        while (l->pos->next != NULL) {
           prev = prev->next; 
           l->pos = l->pos->next;
        }
        prev->next = NULL;
        data = l->pos->data;
        --(l->count);
        printf("%d deleted\n", data);
        free(l->pos);
    }
    return data;
}

void InsertListPos(list *l, int data, int position) {
    if (position > l->count) {
        InsertListTail(l, data);
        return;
    }
    int cnt = 1;
    node *prev;
    l->pos = l->head;
    node *new = (node *)malloc(sizeof(node));
    if (!new) {
        printf("Failed to create node\n");
        return ;
    }
    new->data = data;

    if (position == 1)
        InsertListHead(l, data);
    else {
        while ((l->pos != NULL) && (cnt < position)) {
            cnt ++;
            prev = l->pos;
            l->pos = l->pos->next;
        }
        prev->next = new;
        new->next = l->pos;
    }
}

int SearchList(list *l, int value) {
    l->pos = l->head;
    while ((l != NULL) && (l->pos->next != NULL)) {
        if (l->pos->data == value)
            return l->pos->data;
        l->pos = l->pos->next;
    }
    printf("%d not found\n", value);
    return INT_MIN;
}

int DeleteListNum(list *l, int value) {
    node *temp = l->head;
    int ret = SearchList(l, value);
    if (ret == INT_MIN)
        return ret;
    else {
        while (temp->next != NULL) {
            if (temp->next == l->pos)
                temp->next = l->pos->next;
            temp = temp->next;
        }
        free(l->pos); 
        l->pos = NULL;
        printf("%d deleted\n", ret);
        return ret;
    }
}

list* ConcatList(list *front, list *back) {
    if (front && (front->head == NULL))
        return back;
    else if (back && (back->head == NULL)) 
        return front; 
    else {
        front->pos = front->head;
        while(front->pos->next != NULL) {
            front->pos = front->pos->next;
        }
        front->pos->next = back->head;
        return front;
    }   
}

void ReverseList(list *l) {
    node *prev = NULL;
    node *next = NULL;
    if (l && (l->head != NULL)) {
        l->pos = l->head;
        while (l->pos != NULL) {
            next = l->pos->next;
            l->pos->next = prev;
            prev = l->pos;
            l->pos = next;
        }
        l->head = prev;
    }
}


void DelList(list *l) {
    while (l && (l->head != NULL)) {
        l->pos = l->head;
        l->head = l->head->next;
        free(l->pos);
    }
    free(l);
}

int main(void) {/*
    list *l = InitList();
    for (int i = 0; i < 8; i++) {
        InsertListHead(l, i);
    }
    PrintList(l);
    printf("Len of List: %d\n", ListLen(l));

    printf("Found %d\n", SearchList(l, 3));

    DeleteListHead(l);
    DeleteListNum(l,3);
    DeleteListNum(l,3);
    DeleteListNum(l,101);
    DeleteListTail(l);
    PrintList(l);

    InsertListPos(l, 100, 2);
    InsertListTail(l, 500);

    PrintList(l);

    DelList(l);

    list *first = InitList();
    list *second = InitList();
    
    for (int i = 0; i< 3; i++){
        InsertListHead(first, i+3);
        InsertListHead(second, i);
    }
    PrintList(first);
    PrintList(second);

    first = ConcatList(first, second);
    PrintList(first);
    DelList(first);*/
    
    list *rev = InitList();
    for (int i = 0; i< 5; i++){
        InsertListHead(rev, i);
    }
    PrintList(rev);
    ReverseList(rev);
    PrintList(rev);
    return 0;
}
