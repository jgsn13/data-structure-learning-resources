#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct linked_list LinkedList;
struct linked_list {
    int value;
    LinkedList *next;
};

struct stack {
    LinkedList *first;
};

Stack *create_stack() {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("Insufficient memory\n");
        exit(1);
    }
    stack->first = NULL;
    return stack;
}

int empty_stack(Stack *stack) { return stack->first == NULL; }

void push_stack(Stack *stack, int value) {
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    if (list == NULL) {
        printf("Insufficient memory\n");
        exit(1);
    }
    list->value = value;
    list->next = stack->first;
    stack->first = list;
}

int pop_stack(Stack *stack) {
    int value;
    LinkedList *list;
    if (empty_stack(stack)) {
        printf("Empty stack!!!\n");
        exit(1);
    }
    list = stack->first;
    value = list->value;
    stack->first = list->next;
    free(list);
    return value;
}

void print_stack(Stack *stack) {
    LinkedList *listAux = stack->first;
    while (listAux != NULL) {
        printf("%d\n", listAux->value);
        listAux = listAux->next;
    }
}

void free_stack(Stack *stack) {
    LinkedList *list = stack->first;
    LinkedList *listAux;
    while (list != NULL) {
        listAux = list->next;
        free(list);
        list = listAux;
    }
    free(stack);
}
