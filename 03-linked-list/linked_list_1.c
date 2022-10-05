#include <stdio.h>

typedef struct linked_list LinkedList;
struct linked_list {
    int value;
    LinkedList *next;
};

int main() {
    LinkedList x1, x2;
    x1.value = 4;
    x1.next = &x2;
    x2.value = 3;
    x2.next = NULL;
    return 0;
}
