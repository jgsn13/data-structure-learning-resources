#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define N 3

struct queue {
    int n;
    int start;
    int v[N];
};

Queue *create_queue() {
    Queue *queue = (Queue *)malloc((sizeof(Queue)));
    if (queue == NULL) {
        printf("Insufficient memory\n");
        exit(1);
    }
    queue->n = 0;
    queue->start = 0;
    return queue;
}

int empty_queue(Queue *queue) { return queue->n == 0; }

void insert_queue(Queue *queue, int value) {
    int end;
    if (queue->n == N) {
        printf("Queue overflow!!!\n");
        exit(1);
    }
    end = (queue->start + queue->n) % N;
    queue->v[end] = value;
    queue->n++;
}

int remove_queue(Queue *queue) {
    int value;
    if (empty_queue(queue)) {
        printf("Empty queue!!!\n");
        exit(1);
    }
    value = queue->v[queue->start];
    queue->start = (queue->start + 1) % N;
    queue->n--;
    return value;
}

void print_queue(Queue *queue) {
    int key;
    for (int i = 0; i < queue->n; i++) {
        key = (queue->start + i) % N;
        printf("%d\n", queue->v[key]);
    }
}

void free_queue(Queue *queue) { free(queue); }

int main() {
    Queue queue;
    queue.n = 0;
    queue.start = 0;

    queue.v[0] = 2;
    queue.n++;
    queue.v[1] = 4;
    queue.n++;
    queue.v[2] = 6;
    queue.n++;

    queue.n--;
    queue.start--;

    queue.v[0] = 7;
    queue.n++;

    return 0;
}
