#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define MAX 3

typedef struct stack {
    int n;
    int v[MAX];
} Stack;

Stack *create_stack() {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("Insufficient memory");
        exit(1);
    }
    stack->n = 0;
    return stack;
}

int empty_stack(Stack *stack) { return stack->n == 0; }

void push_stack(Stack *stack, int value) {
    if (stack->n == MAX) {
        printf("Stack overflow!!!\n");
        exit(1);
    }
    stack->v[stack->n] = value;
    stack->n++;
}

int pop_stack(Stack *stack) {
    int value;
    if (empty_stack(stack)) {
        printf("Empty stack!!!\n");
        exit(1);
    }
    value = stack->v[stack->n - 1];
    stack->n--;
    return value;
}

void print_stack(Stack *stack) {
    for (int i = stack->n - 1; i >= 0; i--) {
        printf("%d\n", stack->v[i]);
    }
}

void free_stack(Stack *stack) { free(stack); }

int main() {
    Stack stack1;
    stack1.n = 0;
    stack1.v[0] = 2;
    stack1.n++;
    stack1.v[1] = 4;
    stack1.n++;
    stack1.v[2] = 3;
    stack1.n++;

    return 0;
}
