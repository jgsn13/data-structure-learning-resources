#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct linked_list LinkedList;
struct linked_list {
    int value;
    LinkedList *next;
};

struct queue {
    LinkedList *start;
    LinkedList *end;
};

Queue *create_queue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Insufficient memory\n");
        exit(1);
    }
    queue->start = NULL;
    queue->end = NULL;
    return queue;
}

int empty_queue(Queue *queue) { return queue->start == NULL; }

void insert_queue(Queue *queue, int value) {
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    if (list == NULL) {
        printf("Insufficient memory\n");
        exit(1);
    }
    list->value = value;
    list->next = NULL;
    if (!empty_queue(queue)) {
        queue->end->next = list;
    } else {
        queue->start = list;
    }
    queue->end = list;
}

int remove_queue(Queue *queue) {
    LinkedList *list;
    int value;
    if (empty_queue(queue)) {
        printf("Empty queue!!!\n");
        exit(1);
    }
    value = queue->start->value;
    list = queue->start;
    queue->start = queue->start->next;
    free(list);
    if (empty_queue(queue)) {
        queue->end = NULL;
    }
    return value;
}

void print_queue(Queue *queue) {
    LinkedList *listAux = queue->start;
    while (listAux != NULL) {
        printf("%d\n", listAux->value);
        listAux = listAux->next;
    }
}

void free_queue(Queue *queue) {
    LinkedList *list = queue->start;
    LinkedList *listAux;
    while (list != NULL) {
        listAux = list->next;
        free(list);
        list = listAux;
    }
    free(queue);
}

int main() {
    Queue queue;

    LinkedList list1;
    list1.value = 2;
    list1.next = NULL;
    queue.start = &list1;
    queue.end = &list1;

    LinkedList list2;
    list2.value = 4;
    list2.next = NULL;
    queue.end->next = &list2;
    queue.end = &list2;

    return 0;
}
