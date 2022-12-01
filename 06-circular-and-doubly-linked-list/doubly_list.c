#include "doubly_list.h"
#include <stdio.h>
#include <stdlib.h>

struct doublyList {
    int info;
    DoublyList *next;
    DoublyList *prev;
};

DoublyList *insert_doubly_list(DoublyList *list, int info) {
    DoublyList *ln = (DoublyList *)malloc(sizeof(DoublyList));
    ln->info = info;
    ln->next = list;
    ln->prev = NULL;
    if (list != NULL) {
        list->prev = ln;
    }

    return ln;
}

DoublyList *search_doubly_list(DoublyList *list, int info) {
    DoublyList *auxList = list;
    while (auxList != NULL) {
        if (auxList->info == info) {
            return auxList;
        }
        auxList = auxList->next;
    }
    return NULL;
}

DoublyList *remove_doubly_list(DoublyList *list, int info) {
    DoublyList *auxList = search_doubly_list(list, info);
    if (auxList == NULL) {
        return list;
    }

    if (auxList == list) {
        // if is the first
        list = auxList->next;
    } else {
        auxList->prev->next = auxList->next;
    }

    if (auxList->next != NULL) {
        // if the next is not null
        auxList->next->prev = auxList->prev;
    }

    free(auxList);

    return list;
}
