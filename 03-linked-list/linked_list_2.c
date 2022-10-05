#include <stdio.h>
#include <stdlib.h>
#include "linked_list_2.h"

struct linked_list {
    int value;
    LinkedList *next;
};

LinkedList *create_linked_list() { return NULL; }

int empty_linked_list(LinkedList *list) { return (list == NULL); }

LinkedList *insert_linked_list(LinkedList *list, int value) {
    LinkedList *linkedList = (LinkedList *)malloc(sizeof(LinkedList));
    linkedList->value = value;
    linkedList->next = list;
    return linkedList;
}

LinkedList *search_linked_list(LinkedList *list, int value) {
    LinkedList *listAux = list;
    while (listAux != NULL) {
        if (listAux->value == value) {
            return listAux;
        }
        listAux = listAux->next;
    }
    return NULL;
}

void print_linked_list(LinkedList *list) {
    LinkedList *listAux = list;
    while (listAux != NULL) {
        printf("Info = %d\n", listAux->value);
        listAux = listAux->next;
    }
}

LinkedList *remove_linked_list(LinkedList *list, int value) {
    if (list != NULL) {
        LinkedList *listAux = list->next;
        // if the searched value is the first element of the list
        if (list->value == value) {
            free(list);
            return listAux; // returns the rest of the list
        } else {
            LinkedList *listPrev = list;
            while (listAux != NULL) {
                if (listAux->value == value) {
                    // ensure the link when an element in the middle of the list
                    // is removed
                    listPrev->next = listAux->next;
                    free(listAux);
                    break;
                } else {
                    listPrev = listAux;
                    listAux = listAux->next;
                }
            }
        }
    }
    return list;
}

void free_linked_list(LinkedList *list) {
    LinkedList *listNext;
    while (list != NULL) {
        listNext = list->next;
        free(list);
        list = listNext;
    }
}

int main() {
    LinkedList * linkedList = create_linked_list();
    linkedList = insert_linked_list(linkedList, 10);
    linkedList = insert_linked_list(linkedList, 20);
    linkedList = insert_linked_list(linkedList, 25);
    linkedList = insert_linked_list(linkedList, 30);
    linkedList = insert_linked_list(linkedList, 10);
    print_linked_list(linkedList);

    return 0;
}
