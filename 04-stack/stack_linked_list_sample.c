#include <stdio.h>
#include <stdlib.h>
#include "../03-linked-list/linked_list_2.h"
#include "stack.h"

struct linked_list {
    int value;
    LinkedList *next;
};

struct stack {
    LinkedList *first;
};

int main() {
    Stack stack1;

    LinkedList list1;
    list1.value = 2;
    list1.next = NULL;
    stack1.first = &list1;

    LinkedList list2;
    list2.value = 4;
    list2.next = &list1;
    stack1.first = &list2;

    return 0;
}
