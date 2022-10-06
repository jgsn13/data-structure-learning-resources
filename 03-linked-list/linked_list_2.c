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

LinkedList *insert_sorted_linked_list(LinkedList *list, int value) {
    LinkedList *listNew = (LinkedList *)malloc(sizeof(LinkedList));
    listNew->value = value;
    if (list == NULL) {
        listNew->next = NULL;
        return listNew;
    } else if (list->value == value) {
        listNew->next = list;
        return listNew;
    } else {
        LinkedList *listPrev = list;
        LinkedList *listNext = list->next;
        while (listNext != NULL && listNext->value < value) {
            listPrev = listNext;
            listNext = listNext->next;
        }
        listPrev->next = listNew;
        listNew->next = listNext;
        return list;
    }
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

void print_linked_list_recursively(LinkedList *list) {
    if (empty_linked_list(list)) {
        return;
    } else {
        printf("Info = %d\n", list->value);
        print_linked_list_recursively(list->next);

        // NOTE: the following code should prints the list in reverse order
        // print_linked_list_recursively(list->next);
        // printf("Info = %d\n", list->value);
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

LinkedList *remove_linked_list_recursively(LinkedList *list, int value) {
    if (!empty_linked_list(list)) {
        if (list->value == value) {
            LinkedList *listAux = list;
            list = list->next;
            free(listAux);
        } else {
            // NOTE: list->next because of the link
            list->next = remove_linked_list_recursively(list->next, value);
        }
    }
    return list;
}

int equal_linked_lists_recursively(LinkedList *list1, LinkedList *list2) {
    if (empty_linked_list(list1) && empty_linked_list(list2)) {
        return 1;
    } else if (empty_linked_list(list1) || empty_linked_list(list2)) {
        return 0;
    } else {
        return (list1->value == list2->value &&
                equal_linked_lists_recursively(list1->next, list2->next));
    }
}

void free_linked_list(LinkedList *list) {
    LinkedList *listNext;
    while (list != NULL) {
        listNext = list->next;
        free(list);
        list = listNext;
    }
}

void free_linked_list_recursively(LinkedList *list) {
    if (!empty_linked_list(list)) {
        free_linked_list_recursively(list->next);
        free(list);
    }
}

int main() {
    LinkedList *linkedList = create_linked_list();
    linkedList = insert_linked_list(linkedList, 10);
    linkedList = insert_linked_list(linkedList, 20);
    linkedList = insert_linked_list(linkedList, 25);
    linkedList = insert_linked_list(linkedList, 30);
    linkedList = insert_linked_list(linkedList, 10);
    print_linked_list(linkedList);

    return 0;
}
