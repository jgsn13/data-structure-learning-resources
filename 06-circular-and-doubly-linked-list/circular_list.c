#include "circular_list.h"
#include <stdio.h>
#include <stdlib.h>

struct circularList {
    int info;
    CircularList *next;
};

CircularList *insert_circular_list(CircularList *list, int info) {
    CircularList *ln = (CircularList *)malloc(sizeof(CircularList));
    ln->info = info;
    if (list == NULL) {
        ln->next = ln;
    } else {
        ln->next = list->next;
        list->next = ln;
    }
    return ln;
}

void print_circular_list(CircularList *list) {
    if (list != NULL) {
        CircularList *auxList = list;
        printf("Element list \n");
        do {
            printf("Info = %d\n", auxList->info);
            auxList = auxList->next;
        } while (list != auxList);
    }
}
